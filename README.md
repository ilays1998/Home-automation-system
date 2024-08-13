# Arduino Embedded Systems Projects

## Overview
This repository contains a collection of
Arduino-based projects. These projects integrate multiple sensors, communication modules, and control mechanisms to create real-world applications such as a smart home lighting system, a temperature and humidity monitoring system with data logging, and a home security system with motion detection and GSM alerts.

## Projects

### Smart Home Lighting System with Adaptive Brightness and Remote Control

**Description:** A smart lighting system that automatically adjusts brightness based on ambient light levels and can be controlled remotely via a Bluetooth app.

**Components:**
- Arduino Uno
- LDR (Light Dependent Resistor)
- LED Strip
- Bluetooth Module (HC-05)
- Push Button

**Features:**
- Adaptive brightness control using an LDR.
- Remote on/off control via Bluetooth.
- Manual control using a push button.

### Temperature and Humidity Monitoring with Data Logging and Alert System

**Description:** A system that monitors temperature and humidity, logs data to an SD card, and triggers alerts if conditions exceed predefined thresholds.

**Components:**
- Arduino Uno
- DHT22 Temperature and Humidity Sensor
- SD Card Module
- Buzzer
- LED
- Push Button

**Features:**
- Continuous monitoring of temperature and humidity.
- Data logging to an SD card in CSV format.
- Visual and audible alerts when conditions exceed thresholds.
- Manual reset of the alert system.

### Home Security System with Motion Detection and GSM Alerts

**Description:** A home security system that detects motion using a PIR sensor and sends an SMS alert via a GSM module.

**Components:**
- Arduino Uno
- PIR Motion Sensor
- GSM Module (SIM900)
- Buzzer
- LED

**Features:**
- Motion detection with an automatic alert system.
- SMS notifications sent to a predefined number via a GSM module.
- Visual and audible alarms triggered upon detecting motion.

## Installation and Setup

### Clone the Repository:
```bash
git clone https://github.com/yourusername/Arduino-Embedded-Projects.git
cd Arduino-Embedded-Projects
```
### Hardware Setup:
- Follow the circuit diagrams and wiring instructions provided in each project’s README file in the respective folders.
- Ensure all connections are secure before uploading the code to the Arduino.

### Software Setup:
- **Arduino IDE:** Download and install the Arduino IDE if you haven’t already.
- **Libraries:** Install the following libraries via the Arduino Library Manager:
    - `DHT` for temperature and humidity sensors.
    - `SD` for data logging.
    - `SoftwareSerial` for Bluetooth and GSM communication.

## How to Use

### Upload the Code:
1. Open the respective `.ino` file for the project in the Arduino IDE.
2. Select the appropriate Arduino board (e.g., Arduino Uno).
3. Choose the correct COM port.
4. Upload the code to the Arduino.

### Run the Simulation (if applicable):
- If using SimulIDE or other simulation software, load the project and run the simulation to test the setup virtually.

### Test the System:
- **Smart Lighting System:** Test the LDR’s responsiveness to ambient light and the Bluetooth app for remote control.
- **Temperature and Humidity Monitoring:** Observe the serial monitor for temperature and humidity readings and check the SD card for logged data.
- **Home Security System:** Trigger the PIR sensor and verify that the GSM module sends an SMS alert.

