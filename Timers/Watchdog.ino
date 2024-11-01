#include <avr/wdt.h>   // Include Watchdog library

int loop_count = 0;    // Global counter for loop iterations

void setup() {
    Serial.begin(9600);                         // Start serial communication
    Serial.println("Starting up...");           // Initial message
    pinMode(13, OUTPUT);                        // Set pin 13 as output
    digitalWrite(13, HIGH);                     // Turn LED on
    delay(500);                                 // Wait for half a second
    watchdogSetup();                            // Configure Watchdog Timer
}

void watchdogSetup() {
    cli();                                      // Disable all interrupts
    wdt_reset();                                // Reset the WDT timer
    WDTCSR |= (1 << WDCE) | (1 << WDE);         // Enable Watchdog configuration
    WDTCSR = (1 << WDIE) | (1 << WDE) |         // Set WDT to interrupt & reset mode
             (0 << WDP3) | (1 << WDP2) | 
             (1 << WDP1) | (1 << WDP0);         // Set timeout period
    sei();                                      // Re-enable interrupts
}

void loop() {
    for (int i = 0; i <= loop_count; i++) {     // Loop for `loop_count` times
        digitalWrite(13, HIGH);                 // Turn LED on
        delay(100);                             // Wait 100 ms
        digitalWrite(13, LOW);                  // Turn LED off
        delay(100);                             // Wait 100 ms
    }
    loop_count++;                               // Increment loop counter
    wdt_reset();                                // Feed the Watchdog

    Serial.print(loop_count);                   // Output current loop count
    Serial.print(". Watchdog fed in approx. ");
    Serial.print(loop_count * 200);             // Calculate time in ms
    Serial.println(" milliseconds.");
}

ISR(WDT_vect) {                                 // Watchdog Timer Interrupt Service Routine
    // Code here must be minimal to avoid hanging the WDT interrupt.
}
