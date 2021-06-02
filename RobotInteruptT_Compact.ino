#include <SoftwareSerial.h>
SoftwareSerial Soft_Serial(2,3);
int pinLED = 9;
int pinButton = 7;
int LED = false;
uint32_t tMain;
void setup() {  
  Soft_Serial.begin(19200);
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);
  digitalWrite(pinButton, HIGH);
} void loop() {  
  if (digitalRead(pinButton) == HIGH) {
    digitalWrite(pinLED, LOW);
    if (millis() > tMain + 50) {
      tMain = millis();
      Soft_Serial.print("?");
      LED = !LED;
      digitalWrite(pinLED, LED);
    }
  } else {
    digitalWrite(pinLED, HIGH);
  }
}
