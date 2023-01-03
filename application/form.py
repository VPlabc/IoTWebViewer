from flask_wtf import FlaskForm
from wtforms import StringField, SelectField, SubmitField, IntegerField, FloatField
from wtforms.validators import DataRequired

class UserDataForm(FlaskForm):
    type = SelectField('Type', validators=[DataRequired()],
                                choices=[('income', 'income'),
                                        ('expense', 'expense')])
    category = SelectField("Category", validators=[DataRequired()],
                                            choices =[('rent', 'rent'),
                                            ('salary', 'salary'),
                                            ('investment', 'investment'),
                                            ('side_hustle', 'side_hustle')
                                            ]
                            )
    amount = IntegerField('Amount', validators = [DataRequired()])                                   
    submit = SubmitField('Generate Report')      

class DeviceDataForm(FlaskForm):    
    network_id = IntegerField('Network ID', validators=[DataRequired()])  
    mqtt_broker = StringField('MQTT Broker', validators=[DataRequired()])  
    mqtt_port = StringField('MQTT port', validators=[DataRequired()])   
    mqtt_user = StringField('MQTT user')   
    mqtt_pass = StringField('MQTT pass')  
  

    submit = SubmitField('Update configuration')                         