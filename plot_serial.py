import time
import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation

COM_PORT = "COM3"
BAUD_RATE = 9600


def animate(i, dataList, ser):
    ser.write(b'g')
    arduinoData_string = ser.readline().decode('ascii')


    try:
        arduinoData_float = float(arduinoData_string)
        if arduinoData_float > 250 :
            arduinoData_float = 0
        dataList.append(arduinoData_float)

    except:

        pass

    dataList = dataList[-100:]

    ax.clear()
    ax.plot(dataList)

    ax.set_ylim([0, 300])
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