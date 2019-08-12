
///////////       frwd
///////////       B     A
//////////        B     A


//motor A
const int ma1 = 8;        // clock
const int ma2 = 9;       // antti clock

//motor B
const int mb1 = 10;
const int mb2 = 11;



/////////////////////////////// setup/////////////////////////////////



void setup() {
  // put your setup code here, to run once:
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
Serial.begin(9600);
}


/////////////////////////////direction of car//////////////////////


void forward()
{
  digitalWrite(ma2,LOW);
  digitalWrite(mb2,LOW);
  digitalWrite(ma1,HIGH);
  digitalWrite(mb1,HIGH);
 
  
}

void backward()
{
  digitalWrite(ma1,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(ma2,HIGH);
  digitalWrite(mb2,HIGH);
 
  
}

void left()
{
  digitalWrite(ma2,LOW);
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,HIGH);
  digitalWrite(ma1,HIGH);
  
 
  
}

void right()
{
  digitalWrite(ma2,HIGH);
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,LOW);
  digitalWrite(ma1,LOW);
  
 
  
}



/////////////////////////////loop prog////////////////////////




void loop() {
  // put your main code here, to run repeatedly:

forward();
delay(3000);

//backward();
//delay(3000);

//right();
//delay(3000);

//left();
//delay(3000);

}
