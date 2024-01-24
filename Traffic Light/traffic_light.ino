
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop()
{
  digitalWrite(8, LOW); //green
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(4000);
  
  
  digitalWrite(8, LOW); //orange
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  delay(2000);
  
  digitalWrite(8, HIGH); //red
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(5000);
}