int ledPin = 9;
int inPin = 7;
int val = 0;
int count = 0;


void setup() {
  pinMode (ledPin , OUTPUT);
  pinMode (inPin, INPUT);
  
}

void loop()

 {
   val = digitalRead(inPin);


if (val == HIGH)


{
  count++;
  delay(200);
}

if (count == 1)
 {
  digitalWrite(ledPin, HIGH);
  
 }
else if (count == 2)
{
  digitalWrite (ledPin,LOW);
  count = 0;
}

}
