/*
* Components
 * Arduino Uno
 * LDR (Light Dependent Resistor)
 * LED Strip
 * Bluetooth Module (HC-05)
 * PWM Driver (optional for more LEDs)
 * Push Button
 *
 * Circuit Connections
 * LDR (Analog Signal):
 * Connect LDR to A0 and ground with a 10kΩ pull-down resistor.
 * LED Strip (Digital PWM Signal):
 * Connect the LED strip's control pin to PWM pin 9.
 * Bluetooth Module (Digital Signal):
 * Connect TX of HC-05 to RX (pin 0) of Arduino.
 * Connect RX of HC-05 to TX (pin 1) of Arduino.
 * Push Button (Digital Signal):
 * Connect one terminal of the push button to digital pin 2.
 * Connect the other terminal to ground.
 */

#include <SoftwareSerial.h>

#define LDR_PIN A0
#define LED_PIN 9
#define BUTTON_PIN 2

SoftwareSerial BTSerial(10, 11);  // TX, RX

int ldrValue = 0;
int ledBrightness = 0;
bool lightState = false;

void setup() {
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    BTSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    // Read LDR value
    ldrValue = analogRead(LDR_PIN);

    // Map the LDR value to LED brightness
    ledBrightness = map(ldrValue, 0, 1023, 255, 0); // Inverse mapping
    if (lightState) {
        analogWrite(LED_PIN, ledBrightness);
    } else {
        analogWrite(LED_PIN, 0);
    }

    // Check for Bluetooth commands
    if (BTSerial.available()) {
        char command = BTSerial.read();
        if (command == 'O') {
            lightState = !lightState; // Toggle light
        }
    }

    // Check for button press
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(50);  // Debounce
        if (digitalRead(BUTTON_PIN) == LOW) {
            lightState = !lightState;
        }
    }

    delay(100);
}
