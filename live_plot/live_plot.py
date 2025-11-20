# generated with CHAT GPT because I thought it would be quicker than 
# installing a new terminal or whatever


import serial
import matplotlib.pyplot as plt
from collections import deque

# Configure
PORT = "/dev/tty.usbmodem1103"  # or /dev/tty.usbmodem11103 on Mac/Linux
BAUD = 115200

ser = serial.Serial(PORT, BAUD)

# Create fixed-length deques for rolling plot
window_size = 200
x_data = deque([0]*window_size, maxlen=window_size)
y_data = deque([0]*window_size, maxlen=window_size)
z_data = deque([0]*window_size, maxlen=window_size)

plt.ion()  # interactive mode
fig, ax = plt.subplots()
line_x, = ax.plot(x_data, label='X')
line_y, = ax.plot(y_data, label='Y')
line_z, = ax.plot(z_data, label='Z')
ax.legend()
ax.set_ylim(-4, 4)  # G range

while True:
    try:
        line = ser.readline().decode('utf-8').strip()
        # Example input: x: 0.007812, y: 0.011719, z: 1.027344
        if line.startswith("x:"):
            parts = line.replace("x:", "").replace("y:", "").replace("z:", "").split(",")
            x_val = float(parts[0])
            y_val = float(parts[1])
            z_val = float(parts[2])
            x_data.append(x_val)
            y_data.append(y_val)
            z_data.append(z_val)

            # Update plot
            line_x.set_ydata(x_data)
            line_y.set_ydata(y_data)
            line_z.set_ydata(z_data)
            line_x.set_xdata(range(len(x_data)))
            line_y.set_xdata(range(len(y_data)))
            line_z.set_xdata(range(len(z_data)))

            plt.pause(0.001)
    except KeyboardInterrupt:
        break