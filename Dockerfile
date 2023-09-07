FROM python:3


WORKDIR /Mac/Users/mac/Work/Win/Project/Web/demo/IoTWebViewer/
COPY . .
# RUN pip3 install -r requirements.txt
# COPY . /app
# COPY ./config.ini /app/config.ini
# COPY ./requirements.txt /app/requirements.txt
# install the dependencies and packages in the requirements file


RUN pip3 install -r requirements.txt

CMD ["python3", "run.py"]