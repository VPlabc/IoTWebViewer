from application import app, socketio
from flask import render_template, request, url_for, redirect,flash,get_flashed_messages, jsonify,copy_current_request_context
from application.form import UserDataForm, DeviceDataForm, DeviceAddForm
from application.models import IncomeExpenses, DeviceAdd, DeviceLog, Parameters, device_list,MQTT_Parameter
from application import db
from werkzeug.utils import secure_filename
import json
import time    
import os
from flask_mqtt import Mqtt
import threading
from threading import Lock
from flask_socketio import SocketIO, emit, disconnect
async_mode = None
thread = None
thread_lock = Lock()

app.config['MQTT_BROKER_URL'] = "test.mosquitto.org"#'broker.emqx.io'
app.config['MQTT_BROKER_PORT'] = 1883
app.config['MQTT_USERNAME'] = ""  # Set this item when you need to verify username and password
app.config['MQTT_PASSWORD'] = ""  # Set this item when you need to verify username and password
app.config['MQTT_KEEPALIVE'] = 10  # Set KeepAlive time in seconds
app.config['MQTT_TLS_ENABLED'] = False  # If your server supports TLS, set it True


topic = '/stat/vplab/update'
Status_topic = '/stat/vplab/status'
Control_topic = '/stat/vplab/control'
Setting_topic = '/stat/vplab/setting'

mqtt_client = Mqtt(app)

history = 0
mqtt_stt = 1
sd_stt = 0
reciver_stt = 1


mqtt_client.subscribe(topic) # subscribe topic

def save():     
    print(f'{msg.device_id}, {msg.network_id}, {msg.category}, {msg.status}, {msg.temperature}, {msg.humidity}, {msg.mbattery}, {msg.battery}, {msg.rssi}')
    if msg.device_id == None or msg.device_id == None or msg.category == None or msg.status == None or msg.temperature == None or msg.humidity == None or msg.mbattery == None  or msg.battery == None or msg.rssi == None :
        print("data error")
    else:
        epoch_time = int(time.time())
        new_sensor_found = False
        list_lenght = 0
        list_deviceID = device_list.query.filter().all()  
        try:
            for deviceID in list_deviceID:
                list_lenght = list_lenght + 1
                print("- ID" + str(deviceID.device))
                if msg.device_id == deviceID.device:
                    new_sensor_found = True
        except:
            print("error device list")
        if new_sensor_found == False and msg.rssi < 100:
            print(f'New Device')
            try:
                deviceID = device_list(id=list_lenght+1,device=msg.device_id)
                db.session.add(deviceID)
                db.session.commit()   
                updateparameter = Parameters.query.get_or_404(1)
                updateparameter.devices = list_lenght + 1
                print("update parameters "+ str(updateparameter.devices))
                db.session.add(updateparameter)
                db.session.commit()
                print("parameters readding")
                updateparameter = db.session.query(Parameters).filter(Parameters.id==1)
                for getlogdata in updateparameter:
                    print("parameters read "+ str(getlogdata.devices))
                db.session.commit() 
                flash(f"{msg.device_id} has been added to {msg.device_id}", "success")
            except:
                # updatePara = Parameters(devices=1)
                # db.session.add(updatePara)
                print("creat parameters error")
            print("_________________________________________________________________\n\n\n")

            # try:
            #     print("device list lenght :" + str(list_lenght))
            #     deviceID = device_list(id=list_lenght+1 ,device=msg.device_id)
            #     db.session.add(deviceID)
            #     db.session.commit()    
            # except Exception as e:
            #     print(e)
            #     print("_________________________________________________________________\n\n\n")
            flash(f'New Device {msg.device_id}','success')
        # epoch_time = epoch_time + 1
        time.sleep(2)
        try:
            # socketio.emit('mqtt_feedback', data="OK")
            entrys = DeviceLog(
                date=epoch_time, 
                network_id=msg.network_id,
                device_id=msg.device_id, 
                category=msg.category, 
                status=msg.status, 
                temperature=msg.temperature, 
                humidity=msg.humidity, 
                mbattery=msg.mbattery, 
                battery=msg.battery, 
                rssi=msg.rssi)
            db.session.add(entrys)
            print("data logging")
        except:
            print("save error")
        db.session.commit()

#__________ Socket
@socketio.on('NodeSetting')
def handle_publish(json_str):
    data = json.loads(json_str)
    print(data)
    # socketio.emit('mqtt_feedback', data="OK")
    mqtt_client.publish(Setting_topic,str(data))


# @socketio.on('subscribe')
# def handle_subscribe(json_str):
#     data = json.loads(json_str)
#     mqtt_client.subscribe(data['topic'])
#__________ MQTT 
@mqtt_client.on_connect()
def handle_connect(client, userdata, flags, rc):
   if rc == 0:
       print('Connected successfully')
       mqtt_stt = 1
       mqtt_client.publish(Status_topic, "Server Online")
   else:
       print('Bad connection. Code:', rc)
       mqtt_stt = 0
       
@mqtt_client.on_log()
def handle_logging(client, userdata, level, buf):
    # print(level, buf)
    pass


@mqtt_client.on_message()
def handle_mqtt_message(client, userdata, message):
    payload = ""
    data = dict(
        topic=message.topic,
        payload=message.payload.decode()
    )
    # socketio.emit('mqtt_message', data=data)
    # socketio.emit('Messenger',data)

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

@mqtt_client.on_disconnect()
def handle_disconnect():
    print("CLIENT DISCONNECTED")
    mqtt_stt = 0

@app.route('/publish', methods=['POST'])
def publish_message():
    @copy_current_request_context
    def foo_main():
        # insert your code here
        print(request.url)
    threading.Thread(target=foo_main).start()
    request_data = request.get_json()
    publish_result = mqtt_client.publish(request_data['topic'], request_data['msg'])
    return jsonify({'code': publish_result[0]})  
#----------------------------------------------------------------


@app.route('/')
def index():
    mqtt_client._connect()

    return redirect(url_for('sen'))

@app.route('/statup')
def statup():
    try:    
        entrys = Parameters(id=1, devices=1)
        db.session.add(entrys)
        entrys = DeviceLog(date=epoch_time, device_id=0, category=0 , status=0 , temperature=1 , humidity=1, mbattery=1, battery=1, rssi=100)
        updatePara = Parameters(devices=1)
        db.session.add(updatePara)
        print("creat parameters")
        print("update parameters")
        db.session.add(entrys)
        db.session.commit()
    except Exception as e:
        print(e)
    return redirect(url_for('index'))

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

@app.route('/addDevice', methods = ["POST", "GET"])
def add_device():
    form = DeviceAddForm()
    new_sensor_found = False

    if form.validate_on_submit():
        # entry = DeviceAdd(network_id=form.device_id.data, device_id=form.device_id.data, category=form.category.data)
        # db.session.add(entry)
        # db.session.commit()
        list_lenght = 0
        list_deviceID = device_list.query.filter().all()  
        for deviceID in list_deviceID:
            list_lenght = list_lenght + 1
            print(" ID" + str(deviceID.device))
            if deviceID.device == form.device_id.data:
                print("ID " + str(deviceID.device) + "is found")
                new_sensor_found = True
        if new_sensor_found == True:
            deviceID = device_list(id=list_lenght+1, device=form.device_id.data)
            db.session.add(deviceID)
            updateparameter = db.session.query(Parameters)
            updateparams = updateparameter.filter(Parameters.id==1)
            print("parameters read"+ str(updateparams))


            updateparameter.devices = list_lenght + 1
            print("update parameters :"+ str(updateparameter.devices))
        else:
            print(f'ADD Device {form.device_id.data}')
            # try:
            deviceID = device_list(id=list_lenght+1,device=form.device_id.data)
            db.session.add(deviceID)
            db.session.commit()   
            updateparameter = Parameters.query.get_or_404(1)
            updateparameter.devices = list_lenght + 1
            print("update parameters "+ str(updateparameter.devices))
            db.session.add(updateparameter)
            db.session.commit()
            print("parameters readding")
            updateparameter = db.session.query(Parameters).filter(Parameters.id==1)
            for getlogdata in updateparameter:
                print("parameters read "+ str(getlogdata.devices))
            db.session.commit() 
            flash(f"{form.device_id.data} has been added to {form.device_id.data}", "success")
            # except Exception as e:
            #     print(e)
        # epoch_time = epoch_time + 1
        return redirect(url_for('index'))
    return render_template('addDevice.html', title="Add expenses", form=form)    


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
    def __init__(self, network_id, device_id, category,status,temperature,humidity,mbattery,battery,timestamp,rssi):
        self.network_id = network_id
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
        try:
            data = DeviceLog.query.filter(DeviceLog.device_id == deviceID.device).all()
            for datas in data:
                ids = ids + 1
            list_Device.append(sensors(datas.network_id, datas.device_id,datas.category,datas.status,datas.temperature,datas.humidity,datas.battery,datas.mbattery,datas.date,datas.rssi))
        except:
            print('ID not found')    
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
            netID = list_Device[i].network_id
            raw += str(netID) + ","
            raw += str(ID) + ","
            raw += str(list_Device[i].category) + ","
            raw += str(list_Device[i].status) + ","
            raw += str(list_Device[i].temperature) + ","
            raw += str(list_Device[i].humidity) + ","
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
    global history
    history = 1
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
@app.route("/changestate/<int:netid>/<int:id>/<int:state>")
def changestate(netid,id,state):
    ID = int(id)
    State = int(state)
    payload = "{'netid':" + str(netid) + ",'id':" + str(id) + ",'state': " + str(State) + "}"
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

        # print(data)
        my_file.close()
        return data
    except:
        print("file not found!!!")
        
        out = os.path.dirname(os.path.abspath(__file__))
        print(out)
        return "file not found!!! \n" + out


@app.route('/sen', methods = ["POST", "GET"])
def sen():
    form = DeviceDataForm()
    if form.validate_on_submit():
        network_id = int(form.network_id.data)
        mqtt_broker = form.mqtt_broker.data
        mqtt_port = form.mqtt_port.data
        mqtt_user = form.mqtt_user.data
        mqtt_pass = form.mqtt_pass.data
        print("Networrk ID:" + str(network_id))
        print("MQTT host:" + str(mqtt_broker))
        print("MQTT port:" + str(mqtt_port))
        print("MQTT user:" + str(mqtt_user))
        print("MQTT pass:" + str(mqtt_pass))

        # try:
        db.session.query(MQTT_Parameter).filter(MQTT_Parameter.id== 1).update({
            MQTT_Parameter.mqtt_host:mqtt_broker,
            MQTT_Parameter.mqtt_netid:network_id,
            MQTT_Parameter.mqtt_port:mqtt_port,
            MQTT_Parameter.mqtt_user:mqtt_user,
            MQTT_Parameter.mqtt_pass:mqtt_pass,
            MQTT_Parameter.mqtt_keepalive:5,
            MQTT_Parameter.mqtt_tls_enable:0
            }, synchronize_session = False)
        db.session.commit()
        print("update MQTT parameters")
        # except:
        #     print("update MQTT parameters failed")
        #     c1 = MQTT_Parameter(mqtt_host = mqtt_broker,mqtt_netid = network_id, mqtt_port = mqtt_port,mqtt_user = mqtt_user,mqtt_pass = mqtt_pass, mqtt_keepalive = 5 ,mqtt_tls_enable = 0)
        #     db.session.add(c1)
        #     db.session.commit()
        #     print("add MQTT parameters")
        return render_template('device.html', async_mode=socketio.async_mode)
        # return redirect(url_for('sen'))
    try:
        # mqtt_client._connect()
        return render_template('device.html', async_mode=socketio.async_mode)
    except:
        print("Error")
        return render_template('add.html',title="Add expenses")



@app.route('/config', methods = ["POST", "GET"])
def device_setting():
    form = DeviceDataForm()
    try:
        x = db.session.query(MQTT_Parameter).first() 
        form.network_id.data = 1
        form.mqtt_broker.data = x.mqtt_host
        form.mqtt_port.data = x.mqtt_port
        form.mqtt_user.data = x.mqtt_user
        form.mqtt_pass.data = x.mqtt_pass
    except:
        c1 = MQTT_Parameter(mqtt_host = "test.mosquitto.org",mqtt_port = 1883,mqtt_user = "_",mqtt_pass = "_", mqtt_keepalive = 5)
        db.session.add(c1)
        db.session.commit()
        print("add MQTT parameters")
        return redirect(url_for('sen'))
    return render_template('DeviceSetting.html', title="Device Setting", form=form)
# ///////////////////////////////////////////// Socket //////////////////////////////////////
# 
def background_thread():
    """Example of how to send server generated events to clients."""
    count = 0
    while True:
        socketio.sleep(10)
        count += 1
        socketio.emit('my_response',
                      {'data': 'Server generated event', 'count': count})


# @socketio.event
# def my_event(message):
    # session['receive_count'] = session.get('receive_count', 0) + 1
    # emit('my_response',
        #  {'data': message['data'], 'count': session['receive_count']})



@socketio.event
def disconnect_request():
    @copy_current_request_context
    def can_disconnect():
        disconnect()

    # session['receive_count'] = session.get('receive_count', 0) + 1
    # for this emit we use a callback function
    # when the callback function is invoked we know that the message has been
    # received and it is safe to disconnect
    # emit('my_response',
    #      {'data': 'Disconnected!', 'count': session['receive_count']},
    #      callback=can_disconnect)

@socketio.event
def connect_request():
    @copy_current_request_context
    def can_connect():
        connect()

    # session['receive_count'] = session.get('receive_count', 0) + 1
    # for this emit we use a callback function
    # when the callback function is invoked we know that the message has been
    # received and it is safe to disconnect
    # emit('my_response',
    #      {'data': 'connected!', 'count': session['receive_count']},
    #      callback=connect)
    
@socketio.event
def my_ping():
    emit('my_pong')

@socketio.event
def Getdata():
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
            netID = list_Device[i].network_id
            raw += str(netID) + ","
            raw += str(ID) + ","
            raw += str(list_Device[i].category) + ","
            raw += str(list_Device[i].status) + ","
            raw += str(list_Device[i].temperature) + ","
            raw += str(list_Device[i].humidity) + ","
            raw += str(list_Device[i].battery) + ","
            raw += str(list_Device[i].mbattery) + ","
            raw += str(list_Device[i].timestamp) + ","
            raw += str(list_Device[i].rssi )
            if i < list_lenght - 1:
                raw += "\n"
        except:
            print("list out range")
    emit('data_here',{'data':raw},callback=connect)

@socketio.event
def connect():
    global thread
    with thread_lock:
        if thread is None:
            thread = socketio.start_background_task(background_thread)
    emit('my_response', {'data': 'Connected', 'count': 0})


@socketio.on('disconnect')
def test_disconnect():
    print('Client disconnected', request.sid)


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

