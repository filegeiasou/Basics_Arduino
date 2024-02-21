
String ssid = "Simulator Wifi";
String password = "";
String host = "api.thingspeak.com";
const int  httpPort = 80;
String uri = "/update?api_key=A9TO2IFI3URG1W67&field1=";

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

void anydata(void){
  int temp=map(analogRead(A0),20,358,-40,125);
   String httpPacket = "GET " + uri + String(temp) + " HTTP/1.1\r\nHost: api.thingspeak.com\r\n";
  int lenght = httpPacket.length();
  
   Serial.print("AT+CIPSEND=");
  Serial.println(lenght);
  delay(10);
  
  Serial.print(httpPacket);
  delay(10);
  if(!Serial.find("SEND OK\r\n")) return;
  
}

void setup(){
 	setupESP8266(); 
}

void loop(){
 anydata();
  delay(10000);
  
}
