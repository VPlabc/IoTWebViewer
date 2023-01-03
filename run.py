from application import app
from application import socketio

app.app_context().push()
if __name__ == '__main__':
    socketio.run(app, port=5050, use_reloader=False, debug=True)
    # app.run(debug = True, port=5003)