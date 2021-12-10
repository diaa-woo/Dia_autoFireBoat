#include <SoftwareSerial.h>

int RX = 9;
int TX = 10;
const int power1 = A1;
const int EnableMotor1 = 2;
const int EnableMotor2 = 7;
const int motorPin11 = 3;
const int motorPin12 = 4;
const int motorPin21 = 5;
const int motorPin22 = 6;
const int water = 8;
const int fireSensor = 12;
enum MOTOR_DIRECTION{FOWARD=0, BACKWARD=1};
int state = 0;

enum MOTOR_DIRECTION Direction;

SoftwareSerial bluetooth(TX, RX);

void setup() {
  pinMode(power1, OUTPUT);
  pinMode(motorPin11, OUTPUT);
  pinMode(motorPin12, OUTPUT);
  pinMode(motorPin21, OUTPUT);
  pinMode(motorPin22, OUTPUT);
  pinMode(EnableMotor1, OUTPUT);
  pinMode(EnableMotor2, OUTPUT);
  pinMode(fireSensor, INPUT);
  pinMode(water, OUTPUT);
  digitalWrite(EnableMotor1, LOW);
  digitalWrite(EnableMotor2, LOW);
  analogWrite(power1, 255);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()) {

    char message = (char)bluetooth.read();
    switch(message){
      case '1':  //motor control
        while(message == 'x') {
          char message = (char)bluetooth.read();
          analogWrite(EnableMotor1, 125);
          analogWrite(EnableMotor2, 125);
          digitalWrite(motorPin11, HIGH);
          digitalWrite(motorPin12, LOW);
          digitalWrite(motorPin21, HIGH);
          digitalWrite(motorPin22, LOW);
          delay(50);
        }
        digitalWrite(motorPin11, LOW);
        digitalWrite(motorPin12, LOW);
        digitalWrite(motorPin21, LOW);
        digitalWrite(motorPin22, LOW);
        break;
      case '2': //water control
        delay(3000);
        digitalWrite(water, HIGH);
        delay(1000);
        digitalWrite(water, LOW);
        break;
      
    }
    Serial.write(bluetooth.read());
  }
  if(Serial.available()) {
    bluetooth.write(Serial.read());
  }
}
