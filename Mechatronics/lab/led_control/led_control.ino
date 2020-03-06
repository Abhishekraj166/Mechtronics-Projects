
#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

// Arduino pins used for the switches
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3

// State of each switch (0 or 1)
int S1state;
int S2state;
int S3state;
int S4state;

void setup() 
  // pins for LEDs are outputs
  {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // pins for switches are inputs
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
 
  // setup serial port
  Serial.begin(9600);
  Serial.println("Serial port open");
  }

void loop() 
{
  S1state = digitalRead(S1);
  digitalWrite(LED1, S1state);
  S2state = digitalRead(S2);
  digitalWrite(LED2, S2state);
  S3state = digitalRead(S3);
  digitalWrite(LED3, S3state);
  S4state = digitalRead(S4);
  digitalWrite(LED4, S4state);


  Serial.print(S1state);
  Serial.print(S2state);
  Serial.print(S3state);
  Serial.print(S4state);

  Serial.println();
}
