#include <avr/io.h>// AVR microcontrollers library
const int ledPin = 13;
volatile int seconds=0;
void setup() {
	pinMode(ledPin,OUTPUT);
	// Timer1 initialization
	noInterrupts();//disable interrupts. Also with cli().
	// iniialize TCCR1A and TCCR1B
	TCCR1A = 0;
	TCCR1B = 0;
	// set compare match register to desired value for 1 s delay
	OCR1A = 62499;
	// CTC mode
	bitSet(TCCR1B,WGM12);// or TCCR1B |= (1<<WGM12);
	// set CS12 bit of TCCR1B (prescaler=256)
	bitSet(TCCR1B,CS12);
	//TCCR1B |= (1 << CS12);        // shift 00000001 to CS12 position
	// or TCCR1B = _BV(CS12) --> 1<<CS12
 	// enable OCIE1A of TIMSK1
	bitSet(TIMSK1,OCIE1A);
	interrupts();//enable interrupts. Also with sei().
}

void loop(){
}

ISR(TIMER1_COMPA_vect){
	seconds++;
	if(seconds==10){
		seconds = 0;
		digitalWrite(ledPin,!digitalRead(ledPin));
	}
}