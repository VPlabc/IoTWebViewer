from flask import Flask
from flask_sqlalchemy import SQLAlchemy


sensors_saved = 7

app = Flask(__name__)

app.config['SECRET_KEY'] = "JLKJJJO3IURYoiouolnojojouuoo=5y9y9youjuy952oohhbafdnoglhoho"
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///expenseDB.db'

db = SQLAlchemy(app)


from application import routes