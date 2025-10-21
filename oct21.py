import serial
import time

PORT = '/dev/cu.usbserial-1420'   # adjust if needed

arduino = serial.Serial(port=PORT, baudrate=9600, timeout=1)
time.sleep(2)

print("Type: OFF, ALLON, PAT1, PAT2, PAT3, PAT4, PAT5 (type 'exit' to quit)")

while True:
    cmd = input("> ").strip()
    if cmd.lower() == "exit":
        arduino.write(("OFF\n").encode())   # turn off LEDs before quitting
        time.sleep(0.1)
        break
    if not cmd:
        continue
    arduino.write((cmd.upper() + "\n").encode())
    time.sleep(0.05)
