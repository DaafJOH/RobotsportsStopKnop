#include <SoftwareSerial.h>
SoftwareSerial Soft_Serial(2,3);
int MissedCount = 0;
int pinLED = 9;
int pinKillSign = 7;
int pinLifeSign = 8;
int LifeSign = false;
int LED = false;
uint32_t tMain;
uint32_t tLife;
uint32_t tLED;
void setup() {
  Soft_Serial.begin(19200);
  pinMode(pinLED, OUTPUT);
  pinMode(pinKillSign, OUTPUT);
  pinMode(pinLifeSign, OUTPUT);
  digitalWrite(pinKillSign, LOW);
} void loop() {
  if (millis() >= tMain + 51) {
    MissedCount += 1;
    tMain = millis();
  } if (MissedCount >= 3) {
    digitalWrite(pinKillSign, LOW);
  } if (Soft_Serial.available()) {
    digitalWrite(pinKillSign, HIGH);
    tMain = millis();
    MissedCount = 0;
  } if (millis() >= tLife + 50) {
    LifeSign = !LifeSign;
    digitalWrite(pinLifeSign, LifeSign);
    tLife = millis();
  } if (millis() >= tLED + 100) {
    LED = !LED;
    digitalWrite(pinLED, LED);
    tLED = millis();
  }
}
