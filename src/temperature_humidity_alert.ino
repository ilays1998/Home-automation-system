/*
* Components
 * Arduino Uno
 * PIR Motion Sensor
 * GSM Module (SIM900)
 * Buzzer
 * LED
 *
 * Circuit Connections
 * PIR Sensor (Digital Signal):
 * Connect the output to digital pin 4.
 *
 * GSM Module (Digital Signal):
 * Connect TX to pin 7 and RX to pin 8.
 *
 * Buzzer and LED (Digital Signal):
 * Connect the buzzer to digital pin 5.
 * Connect the LED to digital pin 6.
 */
#include <SoftwareSerial.h>

#define PIR_PIN 4
#define BUZZER_PIN 5
#define LED_PIN 6
#define GSM_TX 7
#define GSM_RX 8

SoftwareSerial gsmSerial(GSM_TX, GSM_RX);

bool motionDetected = false;

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    gsmSerial.begin(9600);
    Serial.begin(9600);

    // Initialize GSM Module
    gsmSerial.println("AT");
    delay(1000);
    gsmSerial.println("AT+CMGF=1");  // Set SMS to text mode
    delay(1000);
    gsmSerial.println("AT+CNMI=1,2,0,0,0");  // Configure message indications
    delay(1000);
}

void loop() {
    motionDetected = digitalRead(PIR_PIN);

    if (motionDetected) {
        triggerAlarm();
        sendSMSAlert();
        delay(10000);  // Prevent spamming SMS
    } else {
        resetAlarm();
    }

    delay(1000);
}

void triggerAlarm() {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected! Alarm triggered.");
}

void resetAlarm() {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
}

void sendSMSAlert() {
    gsmSerial.println("AT+CMGS=\"+1234567890\"");  // Replace with your phone number
    delay(1000);
    gsmSerial.println("Motion detected at home! Check immediately.");  // SMS content
    delay(1000);
    gsmSerial.write(26);  // Send the SMS
    delay(1000);
    Serial.println("SMS sent!");
}
