#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DIGITAL_PIN 2
#define ANALOG_PIN A0

void setup() {
  pinMode(DIGITAL_PIN, INPUT);
  pinMode(ANALOG_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(" Metal Touch Sensor");

  lcd.setCursor(0, 2);
  lcd.print("Switch: O");

  lcd.setCursor(0, 3);
  lcd.print("Analog:");
}

void loop() {
  lcd.setCursor(9, 2);
  if (digitalRead(DIGITAL_PIN)) {
    lcd.print("n ");
    delay(250);
  } else {
    lcd.print("ff");
  }

  lcd.setCursor(8, 3);
  lcd.print(analogRead(ANALOG_PIN));
}
