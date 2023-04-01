#include <SoftwareSerial.h>

const int LS = 2; // left sensor
const int RS =  3; // right sensor
const int LM1 = 5; // left motor M1a
const int LM2 =  4; // left motor M2a
const int RM1 = 7; // right motor M2a
const int RM2 = 6; // right motor M2b

// Bluetooth
SoftwareSerial BT1(4, 2);
String command = "";
void setup()
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
  
// Bluetooth
  
Serial.begin(9600);
BT1.begin(9600);
delay(1000);
Serial.println("Configuracion bluetooth");
  
}
void loop()
{ 
  // Bluetooth
  
if (BT1.available()>0){
command = BT1.readString();
Serial.println(command);

}

if (Serial.available()>0){

String S = Serial.readStringUntil('\n');

Serial.println("---> " + S);

BT1.print(S);

BT1.print('\n');

Serial.println("");
}


if(digitalRead(LS)&& digitalRead(RS)) // Finish line, stop both the motors
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
}
if(digitalRead(LS) && !(digitalRead(RS))) // turn left by rotationg left motors in forward and right ones in backward direction
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
}
if(!(digitalRead(LS)) && digitalRead(RS)) // Turn right by rotating right motors in forward and left ones in backward direction
{
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
}




if(!(digitalRead(LS)) && !(digitalRead(RS))) // Move Forward on line
{
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
}
}
