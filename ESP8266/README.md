# ESP8266 WiFi Module IoT Temperature Monitoring

Welcome to my IoT temperature monitoring project using ESP8266 WiFi module and Arduino Uno R3!

This project demonstrates how to build a temperature monitoring system using an ESP8266 WiFi module, Arduino Uno R3, and a temperature sensor. The temperature readings are sent to ThingSpeak, an IoT platform, where they can be visualized and analyzed in real-time.

## Components Used

- Arduino Uno R3
- ESP8266 WiFi module
- Temperature sensor (e.g., LM35)
- Resistors: 10kΩ and 20kΩ
- Breadboard and jumper wires

## Setup

1. **Hardware Connection:**
   - Connect the temperature sensor to the Arduino Uno R3 as follows:
     - Connect the sensor's VCC pin to Arduino's 5V pin.
     - Connect the sensor's GND pin to Arduino's GND pin.
     - Connect the sensor's output pin to Arduino's analog pin (e.g., A0).
   - Use a voltage divider circuit with a 10kΩ resistor between the sensor output and Arduino's analog pin. Connect a 20kΩ resistor between the Arduino's analog pin and GND.

2. **ThingSpeak Setup:**
   - Sign up for an account on ThingSpeak (https://thingspeak.com/) if you haven't already.
   - Create a new channel and note down the channel ID and API key.

3. **Update the Code:**
   - Open the Arduino IDE and create a new sketch.
   - Copy and paste the code provided in the `ESP8266.ino` file into your sketch.
   - Update the WiFi SSID and password variables with your network credentials.
   - Update the ThingSpeak channel ID and API key variables with your specific values.

4. **Upload and Monitor:**
   - Connect your Arduino Uno R3 to your computer via USB.
   - Select the appropriate board and port from the Arduino IDE (`Tools > Board` and `Tools > Port`).
   - Upload the sketch to your Arduino board.
   - Open the serial monitor to view the temperature readings being sent to ThingSpeak.

## Usage

Once the setup is complete and the sketch is uploaded to your Arduino Uno R3, the temperature readings will be continuously sent to your ThingSpeak channel. You can log in to your ThingSpeak account to visualize the data, create charts, and set up alerts based on temperature thresholds.

## Resources

- [Arduino IDE](https://www.arduino.cc/en/software)
- [ESP8266 Arduino Core Documentation](https://arduino-esp8266.readthedocs.io/en/latest/)
- [ThingSpeak IoT Platform](https://thingspeak.com/)
- [Youtube Video](https://www.youtube.com/watch?v=sM5_6e95t2A&ab_channel=UNIQUE)

Feel free to reach out if you have any questions or need further assistance!

![image](https://github.com/filegeiasou/Basics_Arduino/assets/49124547/ac2a6edb-beca-4ce8-8666-62136880dff1)
![image](https://github.com/filegeiasou/Basics_Arduino/assets/49124547/a3abe02b-b626-4ba6-a9e6-1172d485ffd1)


