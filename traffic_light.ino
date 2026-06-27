int green=13;
int yellow=12;
int red=11;
void setup() {
pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT); 
pinMode(red, OUTPUT); // put your setup code here, to run once:

}

void loop() {
  digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  delay(2000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(1000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(2000);
   

}
