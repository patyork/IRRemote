/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#if defined (PARTICLE)
#include "application.h"
#endif

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("Received: "); Serial.println(results.value, HEX);
        
        irsend.sendNEC(results.value, 32); // send on A5
        Serial.print("Sending: "); Serial.println(results.value, HEX); Serial.println();
        
        
        irrecv.enableIRIn(); // Start the receiver
        irrecv.resume(); // Receive the next value
    }
}
