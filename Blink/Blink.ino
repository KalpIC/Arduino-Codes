#define switch1 5
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(switch1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(switch1, HIGH);
  delay(10000);// turn the LED on (HIGH is the voltage level)
  digitalWrite(switch1, LOW);
  delay(20000);
                         // wait for a second
                  // wait for a second
}
