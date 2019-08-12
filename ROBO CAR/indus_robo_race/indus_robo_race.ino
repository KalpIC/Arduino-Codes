//// 11 5 6 3 of l293d



#define ledPin 7
#include <AFMotor.h>

AF_DCMotor motor1(1); //////right Wheels
AF_DCMotor motor2(2);  ////// Left Wheels

int spd = 255;


void forward();
void backward();
void left();
void right();
void Stop();


/////////////////////////////////////////////////////SetUp
void setup() {
  
  Serial.begin(9600);

  motor1.setSpeed(255);
  motor2.setSpeed(255);
}


///////////////////////////////////////////////LOOP
void loop() {

  uint8_t i;
  int state = 0;
  Serial.println(state);

  if (Serial.available() > 0){
    state = Serial.read();
      }

 //   
//
///
/////

////////////////////////////////////////////////motor direction through bluetooth


   if (state == 'F'){
    Serial.println("F");
    forward();
    delay(20);
       
   }

   else if (state == 'B'){
    Serial.println("B");
    backward();
    delay(20);
   
   }

   else if (state == 'R'){
    Serial.println("R");
    right();
    delay(20);
   }

   else if (state == 'L'){
    Serial.println("L");
    left();
    delay(20);
    
   }



// 
//
///
/////
///////////
/////////////////////////////////////////////////////////////car Speed



   else if (state == '1'){
    spd = 135;   
   }

   else if (state == '2'){
    spd = 150;   
   }

   else if (state == '3'){
    spd = 165;   
   }

   else if (state == '4'){
    spd = 180;   
   }

   else if (state == '5'){
    spd = 195;   
   }

   else if (state == '6'){
    spd = 210;   
   }

   else if (state == '7'){
    spd = 225;   
   }

   else if (state == '8'){
    spd = 240;   
   }

   else if (state == '9'){
    spd = 255;   
   }
   
   motor1.setSpeed(spd);
   motor2.setSpeed(spd);

}
///////////////////////////////////////////////////// Main Loop End Here
//   
//
///
/////
///////////
///////////////////////////////////////////////////////////////car direction




void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
   
void backward(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}


void sharpleft(){
  motor1.run(FORWARD);   //right wheels
  motor2.run(BACKWARD);  //left wheels
}

void sharpright(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  
}

void left(){
  motor1.run(FORWARD);   //right wheels
  motor2.run(RELEASE);  //left wheels
}

void right(){
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  
}

void Stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
