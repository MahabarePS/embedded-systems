"""
 * author Prasad Mahabare
 * created on 29-12-2025-10h-20m
 * github: https://github.com/MahabarePS
 * copyright 2025
"""
"""
simple-web-server.txt
"""
import network
import socket
import machine
import time

# WiFi credentials
SSID = 'dlink-EB94-BICARD'
PASSWORD = 'ASD12345'

# Connect to WiFi
def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('Connecting to WiFi...')
        wlan.connect(SSID, PASSWORD)
        while not wlan.isconnected():
            time.sleep(1)
    print('Connected!')
    print('IP address:', wlan.ifconfig()[0])
    return wlan.ifconfig()[0]

# HTML page
def web_page():
    html = """<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body { font-family: Arial; text-align: center; margin: 20px; }
        h1 { color: #333; }
        .button { 
            padding: 15px 30px; 
            font-size: 18px; 
            margin: 10px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        .on { background-color: #4CAF50; color: white; }
        .off { background-color: #f44336; color: white; }
    </style>
</head>
<body>
    <h1>Bicards Micropython Exercise</h1>
    <h2>Simple Webserver App</h2>
    <p>Control your ESP32</p>
    <a href="/?led=on"><button class="button on">LED ON</button></a>
    <a href="/?led=off"><button class="button off">LED OFF</button></a>
</body>
</html>"""
    return html

# Setup LED (usually GPIO 2 for onboard LED)
led = machine.Pin(2, machine.Pin.OUT)

# Start server
def start_server():
    ip = connect_wifi()
    
    # Create socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 80))
    s.listen(5)
    
    print('Web server running on http://' + ip)
    
    while True:
        try:
            conn, addr = s.accept()
            print('Connection from:', addr)
            
            request = conn.recv(1024)
            request = str(request)
            
            # Parse request
            led_on = request.find('/?led=on')
            led_off = request.find('/?led=off')
            
            if led_on > -1:
                print('LED ON')
                led.value(1)
            elif led_off > -1:
                print('LED OFF')
                led.value(0)
            
            # Send response
            response = web_page()
            conn.send('HTTP/1.1 200 OK\n')
            conn.send('Content-Type: text/html\n')
            conn.send('Connection: close\n\n')
            conn.sendall(response)
            conn.close()
            
        except Exception as e:
            print('Error:', e)
            conn.close()

# Run the server
start_server()