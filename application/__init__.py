from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_socketio import SocketIO


app = Flask(__name__)

app.config['SECRET_KEY'] = "JLKJJJO3IURYoiouolnojojouuoo=5y9y9youjuy952oohhbafdnoglhoho"
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///expenseDB.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False


socketio = SocketIO(app)

db = SQLAlchemy(app)
app.app_context().push()


from application import routes