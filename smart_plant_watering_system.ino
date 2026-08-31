#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Soil moisture sensor analog input
const int nemPin = A0;

// L298N motor driver control pins
const int IN1 = 7;
const int IN2 = 8;

// Stores the current state of the water pump
bool pompaAcik = false;

void setup() {
  // Initialize the 16x2 LCD
  lcd.begin(16, 2);

  // Configure motor driver pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Make sure the pump is OFF when the system starts
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  // Read the soil moisture sensor (0-1023)
  int nem = analogRead(nemPin);

  // Dry soil: turn the pump ON
  if (nem >= 600) {
    pompaAcik = true;
  }

  // Wet enough: turn the pump OFF
  if (nem <= 450) {
    pompaAcik = false;
  }

  // Between 450 and 600, the previous pump state is preserved.
  // This hysteresis prevents frequent ON/OFF switching.

  // Control the pump through the L298N motor driver
  if (pompaAcik) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  // Display the current sensor value
  lcd.setCursor(0, 0);
  lcd.print("Nem: ");
  lcd.print(nem);
  lcd.print("    ");

  // Display the current pump status
  lcd.setCursor(0, 1);

  if (pompaAcik) {
    lcd.print("Pompa: ACIK   ");
  }
  else {
    lcd.print("Pompa: KAPALI ");
  }

  // Update the system every 500 ms
  delay(500);
}
