import serial

ser = serial.Serial('/dev/pts/6', 9600, timeout=1)

while True:
    linha = ser.readline().decode(errors='ignore').strip()
    if linha:
        print("Recebido:", linha)
    else:
      print("nao aconteceu nada")
