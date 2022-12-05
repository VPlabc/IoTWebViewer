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


db.create_all()



