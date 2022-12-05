from application import app
from flask import render_template, url_for, redirect,flash, get_flashed_messages
from application.form import UserDataForm
from application.models import IncomeExpenses
from application import db
import json
import time    
import os

@app.route('/')
def index():
    try:
        entries = IncomeExpenses.query.order_by(IncomeExpenses.date.desc()).all()
        return render_template('index.html', entries = entries)
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
sensors_saved = 7

class sensors:
    def __init__(self, sensor_id, category,status,temperature,humidity,battery,timestamp):
        self.sensor_id = sensor_id
        self.category = category
        self.status = status
        self.temperature = temperature
        self.humidity = humidity
        self.battery = battery
        self.timestamp = timestamp

list_Sensors = []
epoch_time = int(time.time())
list_Sensors.append(sensors(0,1,1,26.5,60.0,3.9,epoch_time + 10))
list_Sensors.append(sensors(1,2,0,25.5,61.0,4.1,epoch_time + 20))
list_Sensors.append(sensors(2,3,1,24.5,62.0,3.6,epoch_time + 15))
list_Sensors.append(sensors(3,3,0,23.5,63.0,3.4,epoch_time + 30))
list_Sensors.append(sensors(4,1,0,23.5,63.0,3.4,epoch_time + 30))

list_Sensors.append(sensors(5,4,1,23.5,63.0,3.4,epoch_time + 30))
list_Sensors.append(sensors(6,4,0,23.5,63.0,3.4,epoch_time + 30))

@app.route("/raw", methods=['GET'])
def get_user():
    raw = ""

    for i in range(sensors_saved):
        ID = list_Sensors[i].sensor_id
        raw += str(ID) + ","
        raw += str(list_Sensors[i].category) + ","
        raw += str(list_Sensors[i].status) + ","
        raw += str(list_Sensors[i].temperature) + ","
        raw += str(list_Sensors[i].humidity) + ","
        raw += "°C,"
        raw += str(list_Sensors[i].battery ) + ","
        raw += str(list_Sensors[i].timestamp)
        raw += '\n'
        if i < sensors_saved - 1:
            raw += "\n"
    
    return raw

mqtt_stt = 1
sd_stt = 0
reciver_stt = 1
epoch_time = int(time.time())

#  server.send(200, "text/plain", String(sd_card_found) + "," + String( mqtt_is_good ) + "," + String(receiver_status) + "," + String( timeClient.getEpochTime() > 1635652800 ));
@app.route("/status", methods=['GET'])
def status():
    return str(sd_stt) + "," + str(mqtt_stt) + "," + str(reciver_stt) + "," + str(epoch_time > 1635652800 )



@app.route("/retry_sd", methods=['GET'])
def retry_sd():
    return "0"

@app.route("/names", methods=['GET'])
def names():
    try:
        out = os.path.dirname(os.path.abspath(__file__))
        # opening the file in read mode
        my_file = open(out + "/static/config.txt", "r")
        
        # reading the file
        data = my_file.read()
        
        # replacing end of line('/n') with ' ' and
        # splitting the text it further when '.' is seen.
        # data_into_list = data.replace('\n', ' ').split(".")
        # data_into_list = data.split("\n")

        # printing the data
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
        return render_template('sensors.html')
    except:
        print("Error")
        return render_template('add.html',title="Add expenses")
