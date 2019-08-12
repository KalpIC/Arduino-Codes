//// 11 5 6 3 of l293d



#include <AFMotor.h>

AF_DCMotor motor1(1); //////right Wheels
AF_DCMotor motor2(2);  ////// Left Wheels



void setup() {
  Serial.begin(9600);

  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  uint8_t i;
  int state = 0;

  if (Serial.available() > 0){
    state = Serial.read();
      }

  if (state == 'F'){
    forward();
    delay(20);
      }
  if (state == 'B') {
     motor1.run(BACKWARD);
     motor2.run(BACKWARD);
  }

  if (state == 'S'){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
 // motor2.run(FORWARD);  
  //  delay(10);
 }

void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
