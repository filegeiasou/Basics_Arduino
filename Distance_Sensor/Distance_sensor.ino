// C++ code
//
const int trigPin=9;
const int echoPin=8;
const int ledPin=11;
long duration;
int distance;
void setup()
{
	pinMode(trigPin,OUTPUT);
  	pinMode(echoPin,INPUT);
  	pinMode(ledPin,OUTPUT);
  
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.017;
  if(distance < 150)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
}