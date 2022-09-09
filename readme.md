> An IOT project for controlling the house's light and fan `wirelessly`

### Requirements:
- Hardware:
    - An arduino (wemos d1 wifi)
    - Power bank (5V, 1A) for arduino or a normal charger with the same current and voltage
    - A two module relay
    - Jumper wires

- Software:
    - Arduino IDE for uploading sketch
    - Code editor (vs code)
    - nodejs >= version 12
    - npm 
    - java jdk + setting up java environment variables (only for building android app)

### Wiring
- connect pin 6 and 7 of the arduino with signals pins of the relay
- power up the relay from arduino on the pin with 5v along side with any ground pin
- plug-in the 5v 1a power bank to the arduino

### Uploading sketch
- open Arduino IDE 
- go to file > preferences > additional boards manager urls and add this url : http://arduino.esp8266.com/stable/package_esp8266com_index.json
- then go to tools > boards > boards manager and search for esp8266 by community and choose version 2.5.0
- select your board e.g. tools > boards > wemos d1 r1
- select upload speed e.g. tools > upload speed > 115200 
- add your [code](./arduino/smartHouse.ino) and click verify then upload (of course you need to modify the ssid and password to suit you wifi network)
- see if there are any errors in the logs down below and try to solve them

> Pro Tip: try to unplug any wires connected to arduino expect the usb cable while uploading your code to avoid any errors, also some errors maybe related to python symlinks

---

> After uploading sketch to arduino it will connect right away on you wifi network so you can check arduino internal `ip` and modify the [domain variable](./www/js/index.js) with arduino ip

## For controlling the light and fan run below commands:

#### Getting started
```bash
npm i
```

#### Development server 
```bash
npm run serve
```

#### Build android app
```bash
npm run android
```

```bash
npm run build
```
