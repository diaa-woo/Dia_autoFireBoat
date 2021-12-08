#include <SPI.h>

volatile int motor = 0;
volatile int checkFire = 0;
volatile boolean fireOn = false;

void setup(void) {
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();

  for(int i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(9,INPUT);
  
}

ISR (SPI_STC_vect) {
  byte mode = SPDR;
  if(mode == 'a') {
    fireOn = true; 
  }
  else {
    motor = mode - '0';
  }

  SPCR |= _BV(SPIE);
}

void loop() {
  if(fireOn) {
    
  }
  if(motor) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    delay(motor);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
