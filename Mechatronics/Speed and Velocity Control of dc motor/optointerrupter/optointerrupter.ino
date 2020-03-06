int ruptPin = 5;
int ruptpin2 = 3;// select the input pin for the interrupter
int val = 0;
int val2 = 0;// variable to store the value coming from the sensor

void setup()
{
    Serial.begin(9600); // set up Serial library at 9600 bps
}

void loop()
{
    val = digitalRead(ruptPin);
    val2 = digitalRead(ruptpin2);// read the value from the sensor
    Serial.println(val);
    //Serial.println(val2);// print the sensor value to the serial monitor
    delay(50);
}
