//
// Created by ilays on 13/08/2024.
//

/*
 * Components
 * Arduino Uno
 * DHT22 Temperature and Humidity Sensor
 * SD Card Module
 * Buzzer
 * LED
 * Push Button
 *
 * Circuit Connections
 * DHT22 Sensor (Digital Signal):
 * Connect the data pin to digital pin 3.
 *
 * SD Card Module (SPI):
 * Connect CS to pin 10, MOSI to pin 11, MISO to pin 12, and SCK to pin 13.
 *
 * Buzzer and LED (Digital Signal):
 * Connect the buzzer to digital pin 6.
 * Connect the LED to digital pin 7.
 *
 * Push Button (Digital Signal):
 * Connect one terminal to digital pin 2 and the other to ground.
 */

#include <SD.h>
#include <SPI.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT22
#define SD_CS_PIN 10
#define BUZZER_PIN 6
#define LED_PIN 7
#define BUTTON_PIN 2

DHT dht(DHTPIN, DHTTYPE);
File dataFile;

float temperature, humidity;
bool alertOn = false;

void setup() {
    Serial.begin(9600);
    dht.begin();

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("SD Card initialization failed!");
        return;
    }

    dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.println("Temperature,Humidity");
        dataFile.close();
    } else {
        Serial.println("Error opening datalog.txt");
    }
}

void loop() {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Log data
    logData(temperature, humidity);

    // Check if conditions exceed thresholds
    if (temperature > 30.0 || humidity > 70.0) {
        triggerAlert();
    } else {
        resetAlert();
    }

    // Check for manual reset
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(50);  // Debounce
        if (digitalRead(BUTTON_PIN) == LOW) {
            resetAlert();
        }
    }

    delay(2000);
}

void logData(float temp, float hum) {
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.print(temp);
        dataFile.print(",");
        dataFile.println(hum);
        dataFile.close();
    }
}

void triggerAlert() {
    if (!alertOn) {
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);
        alertOn = true;
    }
}

void resetAlert() {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    alertOn = false;
}
