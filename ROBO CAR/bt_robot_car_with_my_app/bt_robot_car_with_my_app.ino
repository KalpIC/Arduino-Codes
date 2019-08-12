#define ledPin 7
int state = 0;
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);




void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, LOW);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);

  motor1.setSpeed(255);
  motor2.setSpeed(255);
}



void loop() {

  uint8_t i;

  if (Serial.available() > 0){
    state = Serial.read();
      }

      
///////////////////////////////////motor speed

   if (state == 'H'){
    i = i + 10;
    Serial.println("Increasing Speed");
      motor1.setSpeed(i);
      motor2.setSpeed(i);  
      Serial.println(i);
      delay(150);
    
   }
   if (state == 'L'){
    i = i -10;
    Serial.println("Decreasing Speed");
      motor1.setSpeed(i);
      motor2.setSpeed(i);
      Serial.println(i);
      delay(150);
   
   }

///////////////////////////////motor direction through bluetooth


   if (state == 'F'){
    forward();
    Serial.println("Moving Forward");
    digitalWrite(ledPin, HIGH);
   
   }

   if (state == 'B'){
    Serial.println("Moving Backward");
    digitalWrite(ledPin, HIGH);
    backward();
   
   }

   if (state == 'R'){
    Serial.println("Moving Right");
    digitalWrite(ledPin, HIGH);
    right();
    
   }

   if (state == 'S'){
    Serial.println("Moving Left");
    left();
    digitalWrite(ledPin, HIGH);
    
   }

   if (state == '8'){                //////////square button
    Serial.println("Taking SharpLeft");
    sharpleft();
    digitalWrite(ledPin, HIGH);
    
   }

   if (state == '9'){              ///////////cross button
    Serial.println("Taking SharpRight");
    sharpright();
    digitalWrite(ledPin, HIGH);
   
   }
   
  
   if (state == 'K'){ 
    Serial.println("Making Circle");
    digitalWrite(ledPin, HIGH);
    forward();
    delay(200);
    right();
    delay(100);
   
   }

   if (state == 'P'){
    Serial.println("Moving Zig Zag");
    digitalWrite(ledPin, HIGH);
    forward();
    delay(200);
    right();
    delay(100);
    forward();
    delay(200);
    left();
    delay(100);
    
   }




   
}





////////////////car direction

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
