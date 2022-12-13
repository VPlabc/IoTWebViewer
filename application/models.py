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

class DeviceLog(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    date = db.Column(db.Integer, nullable=True , unique= True, default=datetime.utcnow)
    device_id = db.Column(db.Integer, nullable=True)
    category = db.Column(db.Integer, nullable=False, default='1')
    status = db.Column(db.Integer, nullable=False)
    temperature = db.Column(db.Float, nullable=False)
    humidity = db.Column(db.Float, nullable=False)
    battery = db.Column(db.Float, nullable=False)
    mbattery = db.Column(db.Float, nullable=False)
    rssi = db.Column(db.Float, nullable=False)
    

def __init__(self, id, date, device_id,category, status, temperature, humidity, mbattery, battery, rssi):
   self.id = id
   self.date = date
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

db.create_all()

