#include <SoftwareSerial.h>

SoftwareSerial serialSIM(10, 11); // RX, TX

void setup() {
  serialSIM.begin(9600);
  Serial.begin(9600);
}

void loop() {

if (Serial.available() > 0)
switch (Serial.read())
{
  case 'c':
  call();
  break;

  case 's':
    Hcall();
  break;
  }

}

void call()
{
  serialSIM.println("ATD+94000000000;");//enter mobile number here
  Serial.println("Callin");
  delay(1000);
}

void Hcall()
{
  serialSIM.println("ATH");
  Serial.println("Cut call");
  delay(1000);
}
