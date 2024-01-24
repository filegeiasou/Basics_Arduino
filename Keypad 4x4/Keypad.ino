#include <Keypad.h>

const byte rows =4;
const byte cols =4;

char keys[rows][cols]=
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpins[rows]={3,4,5,6};
byte colspins[cols]={8,9,10,11};

Keypad keypad = Keypad(makeKeymap(keys),rowpins,colspins,rows,cols);

String pass="";

void setup()
{
  Serial.begin(9600);
  //led
  pinMode(12, OUTPUT);
}

void loop()
{
  char key= keypad.getKey();
  if(key !=NO_KEY)
  {
   		pass=pass + key; 
    	if(key=='A')
        {
         	Serial.println("enter Password");
          	pass="";
        }
    	if(key=='D')
        {
         	Serial.println("Validate the password");
          	if(pass=="159D")
            {
              	Serial.println("Access");
				digitalWrite(12,HIGH);
              	delay(2000);
            }
          	else
            {
              	Serial.println("Denied");
             	 digitalWrite(12,LOW);
            }
        }
  }
  
}
