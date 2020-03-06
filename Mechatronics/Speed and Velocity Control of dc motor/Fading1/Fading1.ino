/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fading
*/
int ruptPin = 2;
int ruptpin2 = 3;// select the input pin for the interrupter
int val = 0;
int val2 = 0;
int ledPin1 = 9; // LED connected to digital pin 9
int ledPin2 = 10;// LED connected to digital pin 10

void setup() {
  Serial.begin(9600); 
}

void loop() {
 
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin1, fadeValue);
    analogWrite(ledPin2, 0);
      val = digitalRead(ruptPin);
    val2 = digitalRead(ruptpin2);
    // wait for 30 milliseconds to see the dimming effect
    Serial.println(val);
    delay(30);
     
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
  analogWrite(ledPin1, fadeValue);
    analogWrite(ledPin2, 0);
      val = digitalRead(ruptPin);
    val2 = digitalRead(ruptpin2);
    Serial.println(val);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
 for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin2, fadeValue);
    analogWrite(ledPin1, 0);
      val = digitalRead(ruptPin);
    val2 = digitalRead(ruptpin2);
    Serial.println(val);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
  analogWrite(ledPin2, fadeValue);
    analogWrite(ledPin1, 0);
      val = digitalRead(ruptPin);
    val2 = digitalRead(ruptpin2);
    Serial.println(val);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }   
}
