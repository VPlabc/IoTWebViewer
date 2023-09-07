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

#define GROUP_SWITCH          1
#define GROUP_HT              2
#define GROUP_MOTION          3
#define GROUP_RELAY           4
#define GROUP_MOISTURE        5
#define GROUP_TEMP            6
#define GROUP_VALVE           7
#define GROUP_POSITION        8
#define GROUP_POWER_ENERGY    9
class DeviceAddForm(FlaskForm):
    network_id = IntegerField('Network ID', validators=[DataRequired()])  
    device_id = IntegerField('Node ID', validators=[DataRequired()])  
    category = SelectField("Category", validators=[DataRequired()],
                                            choices =[('0', 'Gateway'),
                                            ('1', 'Switch'),
                                            ('2', 'DHT sensor'),
                                            ('3', 'Motion'),
                                            ('4', 'Relay'),
                                            ('5', 'Moisture sensor'),
                                            ('6', 'Temperature sensor'),
                                            ('7', 'Valve'),
                                            ('8', 'Position sensor'),
                                            ('9', 'Energy sensor')
                                            ]
                            )                                
    submit = SubmitField('Update Device')   

class DeviceDataForm(FlaskForm):    
    network_id = IntegerField('Network ID', validators=[DataRequired()])  
    mqtt_broker = StringField('MQTT Broker', validators=[DataRequired()])  
    mqtt_port = StringField('MQTT port', validators=[DataRequired()])   
    mqtt_user = StringField('MQTT user')   
    mqtt_pass = StringField('MQTT pass')  
  

    submit = SubmitField('Update configuration')                         