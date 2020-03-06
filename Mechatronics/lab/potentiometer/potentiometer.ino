int SI = A1;
int value;
void setup() 
{
  pinMode(SI,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  value = analogRead(SI);
  Serial.print("The output is: ");
  Serial.println(value);
  delay(500);
}
