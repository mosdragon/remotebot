import serial
import time
import flask
from flask import render_template

baudrate = 9600
comPort = "/dev/ttyACM0"
ser = None
app = flask.Flask("Brobot")


@app.route("/forward", methods=["POST"])
def forward():
    ser.write("F")
    return render_template("index.html")


@app.route("/reverse", methods=["POST"])
def reverse():
    ser.write("B")
    return render_template("index.html")

@app.route("/left", methods=["POST"])
def left():
    ser.write("L")
    return render_template("index.html")

@app.route("/right", methods=["POST"])
def right():
    ser.write("R")
    return render_template("index.html")

@app.route("/stop", methods=["POST"])
def stop():
    ser.write("S")
    return render_template("index.html")
    

@app.route('/')
def index():
    return render_template("index.html")


if __name__ == '__main__':
    print "Hello"
    ser = serial.Serial(comPort, baudrate)
    app.run(debug=True)
