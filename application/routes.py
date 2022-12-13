from application import app
from flask import render_template, request, url_for, redirect,flash, get_flashed_messages, jsonify
from application.form import UserDataForm, DeviceDataForm
from application.models import IncomeExpenses, DeviceLog, Parameters, device_list
from application import db
from werkzeug.utils import secure_filename
import json
import time    
import os
from flask_mqtt import Mqtt

app.config['MQTT_BROKER_URL'] = 'broker.emqx.io'
app.config['MQTT_BROKER_PORT'] = 1883
app.config['MQTT_USERNAME'] = ''  # Set this item when you need to verify username and password
app.config['MQTT_PASSWORD'] = ''  # Set this item when you need to verify username and password
app.config['MQTT_KEEPALIVE'] = 10  # Set KeepAlive time in seconds
app.config['MQTT_TLS_ENABLED'] = False  # If your server supports TLS, set it True
topic = '/flask/update'
Status_topic = '/flask/status'
Control_topic = '/flask/control'

mqtt_client = Mqtt(app)
mqtt_stt = 1
sd_stt = 0
reciver_stt = 1

#__________ MQTT 
@mqtt_client.on_connect()
def handle_connect(client, userdata, flags, rc):
   if rc == 0:
       print('Connected successfully')
       mqtt_stt = 1
       mqtt_client.subscribe(topic) # subscribe topic
    #    mqtt_client.publish(Status_topic, "Online")
   else:
       print('Bad connection. Code:', rc)
       mqtt_stt = 0

@mqtt_client.on_message()
def handle_mqtt_message(client, userdata, message):
    payload = ""
    data = dict(
        topic=message.topic,
        payload=message.payload.decode()
    )
    # print("payload: " + str(data))
    jsonData = json.dumps(data)
    # print("payload: " + jsonData)
    DataParse = json.loads(str(jsonData))
    payload_ = DataParse["payload"]
    # print("payload: " + payload_)
    # jsonPayload = json.dumps(str(payload_))
    PayloadParse = json.loads(str(payload_))
    # {
    #     "deviceid": ,
    #     "networkid": ,
    #     "category": ,
    #     "status": ,
    #     "temperature": ,
    #     "humidity": ,
    #     "mbattery": ,
    #     "battery": ,
    #     "rssi": 
    # }
    msg.device_id = PayloadParse["deviceid"]
    msg.network_id = PayloadParse["networkid"]
    msg.category = PayloadParse["category"]
    msg.status = PayloadParse["status"]
    msg.temperature = PayloadParse["temperature"]
    msg.humidity = PayloadParse["humidity"]
    msg.mbattery = PayloadParse["mbattery"]
    msg.battery = PayloadParse["battery"]
    msg.rssi = PayloadParse["rssi"]
    # print(PayloadParse["mbattery"])
    # print(PayloadParse["battery"])
    save()
    loadData()

@app.route('/publish', methods=['POST'])
def publish_message():
   request_data = request.get_json()
   publish_result = mqtt_client.publish(request_data['topic'], request_data['msg'])
   return jsonify({'code': publish_result[0]})  
#----------------------------------------------------------------


@app.route('/')
def index():
    return redirect(url_for('sen'))
@app.route('/ExpenseIncome')
def ExpenseIncome():
    try:
        entries = IncomeExpenses.query.order_by(IncomeExpenses.date.desc()).all()
        return render_template('ExpenseIncome.html', entries = entries)
    except:
        print("Error")
        return render_template('add.html',title="Add expenses")


@app.route('/add', methods = ["POST", "GET"])
def add_expense():
    form = UserDataForm()
    if form.validate_on_submit():
        entry = IncomeExpenses(type=form.type.data, category=form.category.data, amount=form.amount.data)
        db.session.add(entry)
        db.session.commit()
        flash(f"{form.type.data} has been added to {form.type.data}s", "success")
        return redirect(url_for('index'))
    return render_template('add.html', title="Add expenses", form=form)
    


@app.route('/delete-post/<int:entry_id>')
def delete(entry_id):
    entry = IncomeExpenses.query.get_or_404(int(entry_id))
    db.session.delete(entry)
    db.session.commit()
    flash("Entry deleted", "success")
    return redirect(url_for("index"))


@app.route('/dashboard')
def dashboard():
    income_vs_expense = db.session.query(db.func.sum(IncomeExpenses.amount), IncomeExpenses.type).group_by(IncomeExpenses.type).order_by(IncomeExpenses.type).all()

    category_comparison = db.session.query(db.func.sum(IncomeExpenses.amount), IncomeExpenses.category).group_by(IncomeExpenses.category).order_by(IncomeExpenses.category).all()

    dates = db.session.query(db.func.sum(IncomeExpenses.amount), IncomeExpenses.date).group_by(IncomeExpenses.date).order_by(IncomeExpenses.date).all()

    income_category = []
    for amounts, _ in category_comparison:
        income_category.append(amounts)

    income_expense = []
    for total_amount, _ in income_vs_expense:
        income_expense.append(total_amount)

    over_time_expenditure = []
    dates_label = []
    for amount, date in dates:
        dates_label.append(date.strftime("%m-%d-%y"))
        over_time_expenditure.append(amount)

    return render_template('dashboard.html',
                            income_vs_expense=json.dumps(income_expense),
                            income_category=json.dumps(income_category),
                            over_time_expenditure=json.dumps(over_time_expenditure),
                            dates_label =json.dumps(dates_label)
                        )



class Message_Frame(object):
    def __init__(self, network_id, device_id, category,status,temperature,humidity,mbattery,battery,rssi):
        self.network_id = network_id
        self.device_id = device_id
        self.category = category
        self.status = status
        self.temperature = temperature
        self.humidity = humidity
        self.battery = mbattery
        self.mbattery = battery
        self.rssi = rssi
msg = Message_Frame

class sensors:
    def __init__(self, device_id, category,status,temperature,humidity,mbattery,battery,timestamp,rssi):
        self.device_id = device_id
        self.category = category
        self.status = status
        self.temperature = temperature
        self.humidity = humidity
        self.mbattery = mbattery
        self.battery = battery
        self.rssi = rssi
        self.timestamp = timestamp


list_Device = []
epoch_time = int(time.time())
def loadData():
    #load data from  database to list_Device 
    list_Device.clear()
    count = Parameters.query.filter(Parameters.id == 1).first() 
    # print ("load data")  
    # print("count device: " + str(count.devices)) 
    list_lenght = 0
    list_deviceID = device_list.query.filter().all()  
    for deviceID in list_deviceID:
        list_lenght = list_lenght + 1
        # print("Device ID:" + str(deviceID.device))
        ids = 0
        # try:
        data = DeviceLog.query.filter(DeviceLog.device_id == deviceID.device).all()
        for datas in data:
            ids = ids + 1
        list_Device.append(sensors(datas.device_id,datas.category,datas.status,datas.temperature,datas.humidity,datas.battery,datas.mbattery,datas.date,datas.rssi))
        # except:
        #     print('ID not found')    
    #end load data
loadData()

@app.route("/raw", methods=['GET'])
def get_user():
    list_lenght = 0
    list_deviceID = device_list.query.filter().all()  
    for deviceID in list_deviceID:
        list_lenght = list_lenght + 1
        # print("Device ID:" + str(deviceID.device))
    count = Parameters.query.filter(Parameters.id == 1).first()  
    loadData()
    # print("count device: " + str(count.devices)) 
    raw = ""
    
    for i in range(list_lenght):
        try:
            ID = list_Device[i].device_id
            raw += str(ID) + ","
            raw += str(list_Device[i].category) + ","
            raw += str(list_Device[i].status) + ","
            raw += str(list_Device[i].temperature) + ","
            raw += str(list_Device[i].humidity) + ","
            raw += "°C,"
            raw += str(list_Device[i].battery) + ","
            raw += str(list_Device[i].mbattery) + ","
            raw += str(list_Device[i].timestamp) + ","
            raw += str(list_Device[i].rssi )
            if i < list_lenght - 1:
                raw += "\n"
        except:
            print("list out range")
    loadData() 
    return raw




#  server.send(200, "text/plain", String(sd_card_found) + "," + String( mqtt_is_good ) + "," + String(receiver_status) + "," + String( timeClient.getEpochTime() > 1635652800 ));
@app.route("/status", methods=['GET'])
def status():
    epoch_time = int(time.time())
    return str(sd_stt) + "," + str(mqtt_stt) + "," + str(reciver_stt) + "," + str(epoch_time > 1635652800 )



@app.route("/retry_sd", methods=['GET'])
def retry_sd():
    return "0"

@app.route("/sensor/<int:id>")
def sensor(id): 
    ids = 0
    dataOut = ""
    data = DeviceLog.query.filter(DeviceLog.device_id == id).all()
    for datas in data:
        ids = ids + 1
        dataOut += str(datas.date)
        dataOut += "," + str(datas.category) 
        dataOut += "," + str(datas.status) 
        dataOut += "," + str(datas.temperature)
        dataOut += "," + str(datas.humidity)
        dataOut += "," + str(datas.battery)
        dataOut += "," + str(datas.mbattery)
        dataOut += "," + str(datas.rssi)
        dataOut += '\n'

    return dataOut
    # {
    #     "id": ,
    #     "state": 
    # }
@app.route("/changestate/<int:id>/<int:state>")
def changestate(id,state):
    ID = int(id)
    State = int(state)
    payload = "{'id':" + str(id) + ",'state': " + str(State) + "}"
    if mqtt_client.publish(Control_topic, payload):
        print("pushed message")
    else:
        print("pushed message failed")
    print(f'state on device {ID} changed state:{State}', "success")
    flash(f'state on device {ID} changed state:{State}', "success")
    return redirect(url_for("sen"))

@app.route('/delete/<int:deviceID>')
def deletelog(deviceID):
    # try:
    entry = DeviceLog.query.get_or_404(int(deviceID))
    db.session.delete(entry)
    db.session.commit()
    flash("Entry deleted", "success")
    return "1"
    # except:
    #     return "0"

@app.route("/names", methods=['GET'])
def names():
    try:
        out = os.path.dirname(os.path.abspath(__file__))
        # opening the file in read mode
        my_file = open(out + "/static/config.txt", "r")
        
        # reading the file
        data = my_file.read()

        print(data)
        my_file.close()
        return data
    except:
        print("file not found!!!")
        
        out = os.path.dirname(os.path.abspath(__file__))
        print(out)
        return "file not found!!! \n" + out


@app.route('/sen')
def sen():
    try:
        return render_template('device.html')
    except:
        print("Error")
        return render_template('add.html',title="Add expenses")



def save():     
    epoch_time = int(time.time())
    new_sensor_found = False
    list_lenght = 0
    list_deviceID = device_list.query.filter().all()  
    for deviceID in list_deviceID:
        list_lenght = list_lenght + 1
        if msg.device_id == deviceID.device:
            new_sensor_found = True
    # print("list lenght: " +str(list_lenght))
    # try:
    # for i in range(list_lenght):
    #     if list_Device[i].device_id == msg.device_id:
    #         list_Device[i].category = msg.category
    #         list_Device[i].status = msg.status
    #         list_Device[i].temperature = msg.temperature
    #         list_Device[i].humidity = msg.humidity
    #         list_Device[i].battery = msg.battery
    #         list_Device[i].timestamp = epoch_time
    #         new_sensor_found = True
    #     # print("device id: " +str(list_Device[i].device_id))


    if new_sensor_found == False:
        # print("New device detected")
        # list_Device.append(sensors(msg.device_id,msg.category,msg.status,msg.temperature,msg.humidity,msg.battery,epoch_time))
        updateparameter = Parameters.query.get_or_404(1)
        updateparameter.devices = list_lenght + 1
        # print("update parameters")
        # db.session.commit()
        deviceID = device_list(device=msg.device_id)
        db.session.add(deviceID)
        # db.session.commit()
        # print("update device list")
        flash(f'New Device {msg.device_id}','success')
        # sensors_saved = sensors_saved + 1

    entrys = DeviceLog(date=epoch_time, device_id=msg.device_id, category=msg.category  , status=msg.status , temperature=msg.temperature , humidity=msg.humidity, mbattery=msg.mbattery, battery=msg.battery, rssi=msg.rssi)
    db.session.add(entrys)
    db.session.commit()

    # print("update device log")
    # flash(f"ID {msg.device_id} has been added", "success")
    # print(f"ID {msg.device_id} has been added")
    # except:
    #     loadData()
    #     print("save error")


@app.route('/config', methods = ["POST", "GET"])
def add_device():
    form = DeviceDataForm()
    if form.validate_on_submit():

        msg.device_id = form.device_id.data
        msg.network_id = form.network_id.data
        msg.category = int(form.category.data)
        msg.status = form.status.data
        msg.temperature = form.temperature.data
        msg.humidity = form.humidity.data
        msg.mbattery = form.mbattery.data
        msg.battery = form.battery.data
        msg.rssi = form.rssi.data
        print("ID:" + str(msg.device_id))
        print("Net:" + str(msg.network_id))
        print("Cat:" + str(msg.category))
        print("Status:" + str(msg.status))
        print("temp:" + str(msg.temperature))
        print("humidity:" + str(msg.humidity))
        print("mBat:" + str(msg.mbattery))
        print("Bat:" + str(msg.battery))
        print("RSSI:" + str(msg.rssi))
        
        save()  
        return redirect(url_for('add_device'))
    return render_template('addDevice.html', title="Add device", form=form)

# out = os.path.dirname(os.path.abspath(__file__))
# UPLOAD_FOLDER = out + '/static/upload'
 
# app.secret_key = "Cairocoders-Ednalan"
# app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
# app.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024
 
# ALLOWED_EXTENSIONS = set(['txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'])
 
# def allowed_file(filename):
#  return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS
  
# @app.route('/upload')
# def upload_form():
#  return render_template('upload.html')
 
# @app.route('/upload', methods=['POST'])
# def upload_file():
#  if request.method == 'POST':
#         # check if the post request has the files part
#   if 'files[]' not in request.files:
#    flash('No file part')
#    return redirect(request.url)
#   files = request.files.getlist('files[]')
#   for file in files:
#    if file and allowed_file(file.filename):
#     filename = secure_filename(file.filename)
#     file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
#   flash('File(s) successfully uploaded')
#   return redirect('/')