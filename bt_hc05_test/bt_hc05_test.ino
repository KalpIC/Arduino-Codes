#define ledPin 7
int  state = 0;

void setup() {
  pinMode(ledPin, LOW);
  digitalWrite(ledPin,LOW);
  Serial.begin(9600);
  
}

void loop() {
  if(Serial.available() > 0) {
    state = Serial.read();
      }


  if (state == 'R') {
  digitalWrite(ledPin, LOW);
  Serial.println("LED: OFF");
  state = 0;
}
 else if (state == 'L') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");
  state = 0;
 }

}
