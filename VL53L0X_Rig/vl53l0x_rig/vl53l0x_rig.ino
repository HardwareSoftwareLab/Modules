#include "Adafruit_VL53L0X.h"

// address we will assign if dual sensor is present
byte i2c_address[16] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45};

// objects for the vl53l0x
Adafruit_VL53L0X lox[16] = {Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X(), Adafruit_VL53L0X()};

/*
    Reset all sensors by setting all of their XSHUT pins low for delay(10), then set all XSHUT high to bring out of reset
    Keep sensor #1 awake by keeping XSHUT pin high
    Put all other sensors into shutdown by pulling XSHUT pins low
    Initialize sensor #1 with lox.begin(new_i2c_address) Pick any number but 0x29 and it must be under 0x7F. Going with 0x30 to 0x3F is probably OK.
    Keep sensor #1 awake, and now bring sensor #2 out of reset by setting its XSHUT pin high.
    Initialize sensor #2 with lox.begin(new_i2c_address) Pick any number but 0x29 and whatever you set the first sensor to
*/

void setID() {
  // all reset
  for (int i = 0; i < 16; i++) {
    digitalWrite(i, LOW);
  }
  delay(10);
  Serial.println("RESET");

  // all unreset
  for (int i = 0; i < 16; i++) {
    digitalWrite(i, HIGH);
  }
  delay(10);
  Serial.println("UNRESET");

  for (int i = 0; i < 16; i++) {
    digitalWrite(i, LOW);
  }
  delay(10);

  // activating

  Serial.println("ACTIVATING");
  for (int i = 0; i < 16; i++) {
    digitalWrite(i, HIGH);
    delay(10);
  //  Serial.println(i);

    if (!lox[i].begin(i2c_address[i])) {
      Serial.print(F("Failed to boot VL53L0X # "));
      Serial.println(i);
      while (1);
    }
    delay(10);
  }
  for (int i = 0; i < 16; i++) {
    lox[i].setMeasurementTimingBudgetMicroSeconds(200);
    lox[i].startRangeContinuous(10);
  }
}

void read_dual_sensors() {
  uint8_t delta_t = 0;
  uint16_t old_millis = 0;
  uint16_t current_millis = 0;
  for (int i = 0; i < 16; i++) {
   // old_millis = millis();
    Serial.print(lox[i].readRange());
    Serial.print("\t");
  }
  Serial.println();

}

void setup() {
  Serial.begin(115200);
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  for (int i = 0; i < 16; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.println(F("Shutdown pins inited..."));
  for (int i = 0; i < 16; i++) {
    digitalWrite(i, LOW);
  }

  Serial.println(F("All in reset mode...(pins are low)"));
  Serial.println(F("Starting..."));
  setID();

}

void loop() {
  read_dual_sensors();
  delay(1);
}
