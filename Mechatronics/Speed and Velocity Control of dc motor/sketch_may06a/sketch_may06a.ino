


void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(9, 50);
delay(5000);
analogWrite(9, 0);
delay(1000);
analogWrite(10, 50);
delay(5000);
analogWrite(10,0);
delay(1000);
}
