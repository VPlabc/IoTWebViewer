from application import db
from datetime import datetime
import enum


class IncomeExpenses(db.Model):
    
    id = db.Column(db.Integer, primary_key=True)
    type = db.Column(db.String(30), default = 'income', nullable=False)
    category = db.Column(db.String(30), nullable=False, default='rent')
    date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
    amount = db.Column(db.Integer, nullable=False)
    

def __init__(self, id, type, category,date, amount):
   self.id = id
   self.type = type
   self.category = category
   self.date = date
   self.amount = amount

class DeviceAdd(db.Model):
    
    id = db.Column(db.Integer, primary_key=True)    
    network_id = db.Column(db.Integer, nullable=True)
    device_id = db.Column(db.Integer, nullable=True)
    category = db.Column(db.Integer, nullable=False, default='1')
    

def __init__(self, id, network_id, device_id, category ):
   self.id = id
   self.network_id = network_id
   self.device_id = device_id
   self.category = category

class DeviceLog(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    date = db.Column(db.Integer,unique = True, default=datetime.utcnow)
    network_id = db.Column(db.Integer, nullable=True)
    device_id = db.Column(db.Integer, nullable=True)
    category = db.Column(db.Integer, nullable=False, default='1')
    status = db.Column(db.Integer, nullable=False)
    temperature = db.Column(db.Float, nullable=False)
    humidity = db.Column(db.Float, nullable=False)
    battery = db.Column(db.Float, nullable=False)
    mbattery = db.Column(db.Float, nullable=False)
    rssi = db.Column(db.Float, nullable=False)
    

def __init__(self,network_id, id, date, device_id,category, status, temperature, humidity, mbattery, battery, rssi):
   self.id = id
   self.date = date
   self.network_id = network_id
   self.device_id = device_id
   self.category = category
   self.status = status
   self.temperature = temperature
   self.humidity = humidity
   self.battery = mbattery
   self.mbattery = battery
   self.rssi = rssi

class Parameters(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    devices = db.Column(db.Integer, nullable=False)

def __init__(self, id, devices):
   self.id = id
   self.devices = devices

class device_list(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    device = db.Column(db.Integer, nullable=False)

def __init__(self, id, devices):
   self.id = id
   self.device = devices

class MQTT_Parameter(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    mqtt_netid = db.Column(db.Integer, nullable=True)
    mqtt_host = db.Column(db.String, nullable= True)
    mqtt_port = db.Column(db.Integer, nullable= True)
    mqtt_user = db.Column(db.String, nullable= True)
    mqtt_pass = db.Column(db.String, nullable= True)
    mqtt_keepalive = db.Column(db.Integer, nullable= True)
    mqtt_tls_enable = db.Column(db.Integer, nullable= True)

def __init__(self, id, mqtt_netid, mqtt_host, mqtt_port, mqtt_user, mqtt_pass, mqtt_keepalive, mqtt_tls_enable):
   self.id = id
   self.mqtt_netid = mqtt_netid
   self.mqtt_host = mqtt_host
   self.mqtt_port = mqtt_port
   self.mqtt_user = mqtt_user
   self.mqtt_pass = mqtt_pass
   self.mqtt_keepalive = mqtt_keepalive
   self.mqtt_tls_enable = mqtt_tls_enable

db.create_all()

