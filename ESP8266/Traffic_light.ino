String ssid = "Simulator Wifi";
String password = "";
String host = "api.thingspeak.com";
const int httpPort = 80;

// ThingSpeak API URIs
String greenUri = "/update?api_key=RVYMKEOS5DUCTSNQ&field1=";
String orangeUri = "/update?api_key=RVYMKEOS5DUCTSNQ&field2=";
String redUri = "/update?api_key=RVYMKEOS5DUCTSNQ&field3=";

// LED pin setup (adjust according to your pinout)
int greenLED = 10; // Pin for green LED
int orangeLED = 9; // Pin for orange LED
int redLED = 8; // Pin for red LED

int setupESP8266(void){
  Serial.begin(115200);
  Serial.println("AT");
  delay(10);
  if(!Serial.find("OK")) return 1;
  
  // Set WiFi mode to station
  Serial.println("AT+CWMODE=1");
  delay(2000);
  if(!Serial.find("OK")) return 2;

  // Connect to WiFi
  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";
  Serial.println(cmd);
  delay(5000); // Wait a bit for the connection to establish
  if(!Serial.find("OK")) return 3;

  // Check IP address (optional, for verification)
  Serial.println("AT+CIFSR");
  delay(2000);
  if(!Serial.find("OK")) return 4;

  // Connect to ThingSpeak
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(5000); // Wait for connection to establish
  if(!Serial.find("OK")) return 5;

  Serial.println("WiFi Connected and ThingSpeak API ready");
  return 0; // Success
}

void sendData(String uri) {

  // Construct and send the HTTP GET request
  String httpPacket = "GET " + uri + " HTTP/1.1\r\nHost: " + String(host) + "\r\nConnection: close\r\n\r\n";
  int lenght = httpPacket.length();
  
   Serial.print("AT+CIPSEND=");
  Serial.println(lenght);
  delay(10);
  
  Serial.print(httpPacket);
  delay(10);
  if(!Serial.find("SEND OK\r\n")) return;
}

void controlTrafficLight(String state) {
  if (state == "green") {
    digitalWrite(greenLED, HIGH);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (state == "orange") {
    digitalWrite(greenLED, LOW);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(redLED, LOW);
  } else if (state == "red") {
    digitalWrite(greenLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, HIGH);
  }
}

void setup() {
  // Setup the ESP8266 and LEDs
  pinMode(greenLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  setupESP8266();
}

void loop() {
  // Simulate traffic light control
  controlTrafficLight("green");
  sendData(greenUri + "1"); // Send green status to ThingSpeak
  sendData(orangeUri + "0");
  sendData(redUri + "0");
  delay(5000);

  controlTrafficLight("orange");
  sendData(orangeUri + "1"); // Send orange status to ThingSpeak
  sendData(greenUri + "0");
  sendData(redUri + "0");
  delay(2000);

  controlTrafficLight("red");
  sendData(redUri + "1"); // Send red status to ThingSpeak
  sendData(orangeUri + "0");
  sendData(greenUri + "0");
  delay(5000);
}
