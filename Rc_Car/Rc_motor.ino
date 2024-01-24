void setup()
{Serial.begin(9600);
  pinMode(4, OUTPUT);  //motor1
  pinMode(7, OUTPUT);  //motor2
  pinMode(8, OUTPUT);  //motor4
  pinMode(13, OUTPUT); //motor3
  pinMode(9, INPUT);   //SW4
  pinMode(10, INPUT);  //SW3
  pinMode(11, INPUT);  //SW2
  pinMode(12, INPUT);  //SW1
}

void loop()
{if (digitalRead(9) == HIGH)
  {backward(); }
  if (digitalRead(10) == HIGH)
  {right(); }
  if (digitalRead(11) == HIGH)
  {left();}
  if (digitalRead(12) == HIGH)
  {forward();} 
}
void right()//SW4
{ digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(13,HIGH);}

void left()//SW3
{digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(13,LOW);}

void forward()//SW2
{digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(13,LOW);}

void backward()//SW1
{ digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(13,HIGH);}
 