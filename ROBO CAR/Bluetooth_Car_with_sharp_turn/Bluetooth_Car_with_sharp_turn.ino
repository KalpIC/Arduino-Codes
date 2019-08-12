const int mot1_1 = 8;
const int mot1_2 = 9;
const int mot2_1 = 10;
const int mot2_2 = 11;
const int Speed = 6;
int b = 255;
 bool c=false;

void forward();
void reverse();
void left();
void right();
void Stop();
void sharp_left();
void sharp_right();

void setup() {
  // put your setup code here, to run once:

  pinMode(mot1_1, OUTPUT);
  pinMode(mot1_2, OUTPUT);
  pinMode(mot2_1, OUTPUT);
  pinMode(mot2_2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int a;
  
  if (Serial.available() > 0)
  {
    a = Serial.read();
//    Serial.println(a);
  }

  if (a == 'X')
  {
    c = true;
  }
  else if (a == 'x')
  {
    c = false;
  }
  else if (a == 'F')
  {
    forward();
    delay(20);
//    Serial.println("forward");
  }

  else if (a == 'B')
  {
    reverse();
    delay(20);
  }
  else if (a == 'L')
  {
    if (c == true)
    {
      sharp_left();
      delay(20);
    }
    else
    {
      left();
      delay(20);
    }
  }

  else if (a == 'R')
  {
    if (c == true)
    {
      sharp_right();
      delay(20);
    }
    else
    {
      right();
      delay(20);
    }
  }

  else if (a == 'S')
  {
    Stop();
    delay(20);
  }
  else if (a == '1')
  {
    b = 100;
    //  analogWrite(Speed,100);
  }
  else if (a == '2')
  {
    b = 120;
    // analogWrite(Speed,120);
  }
  else if (a == '3')
  {
    b = 140;
    //  analogWrite(Speed,140);
  }
  else if (a == '4')
  {
    b = 160;
    //analogWrite(Speed,160);
  }
  else if (a == '5')
  {
    b = 180;
    //analogWrite(Speed,180);
  }
  else if (a == '6')
  {
    b = 200;
    //analogWrite(Speed,200);
  }
  else if (a == '7')
  {
    //analogWrite(Speed,210);
  }
  else if (a == '8')
  {
    b = 220;
    //analogWrite(Speed,220);
  }
  else if (a == '9')
  {
    b = 230;
    //analogWrite(Speed,230);
  }
  else if (a == 'q')
  {
    b = 255;
    //analogWrite(Speed,255);
  }
  else
  {
    Stop();
  }

  // put your main code here, to run repeatedly:

}
void forward()
{
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 1);
  digitalWrite(mot1_2, 0);
  digitalWrite(mot2_1, 1);
  digitalWrite(mot2_2, 0);
}
void reverse()
{
  //digitalWrite(Speed,HIGH);
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 0);
  digitalWrite(mot1_2, 1);
  digitalWrite(mot2_1, 0);
  digitalWrite(mot2_2, 1);
}

void sharp_right()
{
  // digitalWrite(Speed,HIGH);
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 0);
  digitalWrite(mot1_2, 1);
  digitalWrite(mot2_1, 1);
  digitalWrite(mot2_2, 0);
//  Serial.println("sharp_left");

}


void sharp_left()
{
  //digitalWrite(Speed,HIGH);
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 1);
  digitalWrite(mot1_2, 0);
  digitalWrite(mot2_1, 0);
  digitalWrite(mot2_2, 1);
 // Serial.println("sharp_right");
}

void right()
{
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 0);
  digitalWrite(mot1_2, 0);
  digitalWrite(mot2_1, 1);
  digitalWrite(mot2_2, 0);
  //Serial.println("left");
}

void left()
{
  analogWrite(Speed, b);
  digitalWrite(mot1_1, 1);
  digitalWrite(mot1_2, 0);
  digitalWrite(mot2_1, 0);
  digitalWrite(mot2_2, 0);
 // Serial.println("right");

}
void Stop()
{
  //analogWrite(Speed,b);
  digitalWrite(mot1_1, 0);
  digitalWrite(mot1_2, 0);
  digitalWrite(mot2_1, 0);
  digitalWrite(mot2_2, 0);
}

