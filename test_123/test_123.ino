//// 11 5 6 3 of l293d


#include <AFMotor.h>

AF_DCMotor motor1(1); //////right Wheels
AF_DCMotor motor2(2);  ////// Left Wheels

int spd = 255;

void setup() {
  Serial.begin(9600);

  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  uint8_t i;
  int state = 0;


  motor1.setSpeed(spd);
  motor2.setSpeed(spd);
  

  if (Serial.available() > 0){
    state = Serial.read();
      }

  if (state == 'F'){             ////////////// forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
      }
  if (state == 'B') {         //////////////////  backward
     motor1.run(BACKWARD);
     motor2.run(BACKWARD);
  }

  if (state == 'S'){         ////////////////stop / release
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }

  if (state == 'L'){        ///////////////   left
    motor1.run(FORWARD);
    motor2.run(RELEASE);
  }

  if (state == 'R'){      ///////////////   right
    motor1.run(RELEASE);
    motor2.run(FORWARD);
  }




                        ////////////// speed
  if (state == 'q'){    
    spd = 255;
  }

  if (state == '9'){
    spd = 240;
  }

  if (state == '8'){
    spd = 225;
  }

  if (state == '7'){
    spd = 205;
  }

  if (state == '6'){
    spd = 190;
  }

  if (state == '5'){
    spd = 175;
  }

  if (state == '4'){
    spd = 155;
  }

  if (state == '3'){
    spd = 135;
  }

  if (state == '2'){
    spd = 115;
  }

  if (state == '1'){
    spd = 100;
  }

  if (state == '0'){
    spd = 00;
  }

 }
