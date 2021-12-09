#include <SoftwareSerial.h>

int RX = 9;
int TX = 10;
SoftwareSerial bluetooth(TX, RX);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()) {

    char message = (char)bluetooth.read();
    switch(message){
      case '1':  //motor control
        break;
      case '2':  //water control
        break;
    }
    Serial.write(bluetooth.read());
  }
  if(Serial.available()) {
    bluetooth.write(Serial.read());
  }
}
