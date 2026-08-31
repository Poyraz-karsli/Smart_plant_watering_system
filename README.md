# Smart_plant_watering_system

## About the Project
I developed an Arduino-based automatic plant watering system that monitors soil moisture and automatically waters the soil when it becomes dry.

## Components
- Arduino Uno
- Soil Moisture Sensor
- 16x2 LCD Display
- L298N Motor Driver
- Mini DC Water Pump
- 4xAA Battery Holder
- Breadboard
- Jumper Wires
- Water Tube

## Hardware Overview

- **Arduino Uno:** Reads the soil moisture sensor data and controls the overall system.
- **Soil Moisture Sensor:** Measures the moisture level of the soil and provides an analog signal to the Arduino.
- **16x2 LCD Display:** Displays the current soil moisture value and the pump status.
- **L298N Motor Driver:** Acts as an interface between the Arduino and the water pump. Since the Arduino cannot safely supply the current required by the pump directly, the L298N controls the pump using signals from the Arduino while the pump is powered from an external power source.
- **Mini DC Water Pump:** Pumps water from the reservoir to the soil when watering is required.
- **4xAA Battery Pack:** Provides an external power supply for the pump through the L298N motor driver.

## Circuit Connections
### Soil Moisture Sensor
| Sensor | Arduino Uno |
|---|---|
| Analog Output | A0 |
| VCC | 5V |
| GND | GND |
### 16x2 LCD
| LCD | Arduino Uno |
|---|---|
| RS | 12 |
| Enable | 11 |
| D4 | 5 |
| D5 | 4 |
| D6 | 3 |
| D7 | 2 |
### L298N Motor Driver
| L298N | Arduino Uno |
|---|---|
| IN1 | 7 |
| IN2 | 8 |
| GND | GND |
The water pump is connected to the L298N output terminals. The pump is powered using an external 4xAA battery pack through the motor driver
The Arduino and L298N share a common ground.

## How it Works
-The soil moisture sensor continuously measures the moisture level of the soil and sends an analog value to the Arduino.
-If the sensor value is higher than 600, the soil is considered dry and water pump is turned ON.
-If the sensor value falls below 450, the soil is considered wet and water pump is turned OFF.
-Between 450 and 600 pump keeps its previous state to prevent frequent ON/OFF switching.
-The current sensor value and pump status are displayed on 16x2 LCD screen.

## Sensor Calibration
The soil moisture sensor was calibrated experimentally using dry and wet soil.
- Dry soil: approximately 935
- Wet soil: approximately 273
Based on these measurements, 600 and 450 were selected as the control thresholds for the automatic watering system.

## Project Setup
The completed prototype of teh smart plant watering system is shown below.
(project-setup.jpg)
