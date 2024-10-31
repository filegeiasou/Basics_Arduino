#include <Wire.h>
#define PIR_PIN 8
byte movement;
void setup() {
  Wire.begin();
  pinMode(PIR_PIN, INPUT);

}

void loop() {
  movement = digitalRead(PIR_PIN);
  if(movement)
  {
    Wire.beginTransmission(2);
    Wire.write(1);
    Wire.endTransmission();
  }
  delay(100);
}