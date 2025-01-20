import time
import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

COM_PORT = "COM4"
BAUD_RATE = 9600


def animate(i, dataList, ser):
    ser.write(b'g')
    arduinoData_string = ser.readline().decode('ascii')


    try:
        arduinoData_float = float(arduinoData_string)
        
        dataList.append(arduinoData_float)

    except:

        pass

    dataList = dataList[-100:]

    ax.clear()
    ax.plot(dataList)

    ax.set_ylim([700, 0])
    ax.set_title("samples")
    ax.set_ylabel("distance")

dataList = []

fig = plt.figure()

ax = fig.add_subplot(111)

ser = serial.Serial(COM_PORT, BAUD_RATE)
time.sleep(2)

ani = animation.FuncAnimation(fig, animate, frames = 100, fargs=(dataList, ser), interval = 25)



plt.show()
ser.close()