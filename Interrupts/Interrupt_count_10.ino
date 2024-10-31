const byte LED=13,SW=2;
unsigned char lastCount=-1;
volatile unsigned char count = 0;
volatile int ledStatus = HIGH;
void handleSw()
{
	count++;
}

void handleOtherStuff()
{
	Serial.print("Count ");
  	Serial.println(count);
  	if(count==10)
    {
		digitalWrite(LED,ledStatus);
      	ledStatus = (ledStatus ==LOW)? HIGH : LOW;
      	count=0;
     	 
    }
}

void setup()
{
	Serial.begin(9600);
  	pinMode(LED,OUTPUT);
  	pinMode(SW,INPUT_PULLUP);
  	attachInterrupt(INT0,handleSw,FALLING);
  	//attachInterrupt(digitalPinToInterrupt(SW),handleSw,FALLING);
}

void loop()
{
	handleOtherStuff();
}