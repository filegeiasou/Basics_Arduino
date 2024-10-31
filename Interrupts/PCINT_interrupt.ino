#include <avr/interrupt.h>
volatile int value = 0;
void setup()
{
  cli();//disable interrupts
  pinMode(8,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  PCICR = 0b00000011; //Enables Ports B and C
  PCIFR = 0b00000000; //Clear All interrupt flags
  PCMSK0 = 0b00000001; //PCINT0
  PCMSK1 = 0b00001000; //PCINT11
  sei(); //enable interrupts
  Serial.begin(9600);
}

void loop()
{
  Serial.println(value);
}

ISR(PCINT0_vect)
{
value++;
}

ISR(PCINT1_vect)
{
value--;
}