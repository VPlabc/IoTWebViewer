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
    category = SelectField('Category', validators=[DataRequired()],
                                choices=[('1','Switch'),
                                        ('2', 'HT sensor'),
                                        ('3', 'Motion'),
                                        ('4', 'Relay')])

    network_id = IntegerField('Network ID', validators = [DataRequired()])  
    device_id = IntegerField('Device ID')  
    status = IntegerField('Status')  
    temperature = FloatField('Temperature', validators = [DataRequired()]) 
    humidity = FloatField('Humidity', validators = [DataRequired()])
    battery = FloatField('Battery', validators = [DataRequired()])   

    submit = SubmitField('Update device')                         