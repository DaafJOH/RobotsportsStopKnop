//Initiate and start libraries
#include <SoftwareSerial.h>
SoftwareSerial Soft_Serial(2,3);

//Declare variables
int MissedCount = 0;
int pinLED = 9;
int pinKillSign = 7;
int pinLifeSign = 8;
int LifeSign = false;
int LED = false;

//Declare time variables
uint32_t tMain;
uint32_t tLife;
uint32_t tLED;

void setup()
{
  //Begin SoftwareSerial
  Soft_Serial.begin(19200);
  
  //Begin GPIO pins
  pinMode(pinLED, OUTPUT);
  pinMode(pinKillSign, OUTPUT);
  pinMode(pinLifeSign, OUTPUT);

  //Start on kill
  digitalWrite(pinKillSign, LOW);
}

void loop()
{
  //If we missed a pulse
  if (millis() >= tMain + 51)
  {
    //Add 1 to missed count
    MissedCount += 1;

    //Reset timer
    tMain = millis();
  }
  //If we hit 3 missed counts
  if (MissedCount >= 3)
  {
    //Declare kill event
    digitalWrite(pinKillSign, LOW);
  }
  //If we recieved a pulse
  if (Soft_Serial.available())
  {
    //Lift the kill
    digitalWrite(pinKillSign, HIGH);

    //Reset timer
    tMain = millis();

    //Reset missed counts
    MissedCount = 0;
  }
  //check if lifesign is needed
  if (millis() >= tLife + 50)
  {
    //Give life sign
    LifeSign = !LifeSign;
    digitalWrite(pinLifeSign, LifeSign);

    //Reset timer
    tLife = millis();
  }
  //Check if LED flash is needed
  if (millis() >= tLED + 100)
  {
    //Pulse LED
    LED = !LED;
    digitalWrite(pinLED, LED);

    //Reset timer
    tLED = millis();
  }
}
