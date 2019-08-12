
const int motor = 9;       // primary motor pin
const int smotor = 8;       // secondary motor
const int button = 7;    //start/stop Button
const int reset = 6;     //reset pin
const int sensor = 5;    //sensor pin

int counter = 0;
int turns = 0;

void setup() {
                                                 // put your setup code here, to run once:
  pinMode (motor,OUTPUT);
  pinMode (smotor,OUTPUT);
  pinMode (button, INPUT);
  pinMode (reset, INPUT);
  pinMode (sensor, INPUT);
}

void loop() {
                                                   // put your main code here, to run repeatedly:


                  //define variable
                  
int buttonState;
int resetState;                            
int sensorState;

                                      // read data 

buttonState = digitalRead(button);
resetState = digitalRead (reset);
sensorState = digitalRead(sensor);
                                     //


if (buttonState == HIGH)             //start stop button counter
{
  counter++;
  delay(200);
}                                     //


if (sensorState == HIGH)              // turns counter 
{
  turns++;
}                                   //


if (counter == 1)                     //Motor_ON/_OFF on pushhing start/stop button
{
   digitalWrite (motor,HIGH);
   digitalWrite (smotor,HIGH);        
}
else if (counter == 2) 
{
   digitalWrite (motor,LOW);
   digitalWrite (smotor,LOW);
   counter = 0;
}                                 //


if (turns == 1000)                  //stop on 1000 turns (user definable)
{
   digitalWrite (motor,LOW);
   digitalWrite (smotor,LOW);
}


if (resetState == HIGH)               // RESET Button
{
   digitalWrite (motor,LOW);
   digitalWrite (smotor,LOW);
   turns = 0;
}
}
