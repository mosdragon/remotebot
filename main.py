import serial
import time


baudrate = 9600
comPort = "/dev/ttyACM0"

if __name__ == '__main__':
    print "Hello"
    ser = serial.Serial(comPort, baudrate)
    ser.write("F")
    time.sleep(2)
    ser.write("S")

