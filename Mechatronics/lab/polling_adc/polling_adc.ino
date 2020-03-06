float SF; 

float SJ; 

  

void setup()  

{ 

pinMode(A0,INPUT);  //Input for ADC Voltage 

pinMode(A1,INPUT);  //Input for Deflection  

Serial.begin(9600); 

} 

  

void loop()  

{ 

SJ = analogRead(A1); 

SJ = map(SJ, 0, 1024, 0, 5); 

Serial.print("Measured Deflection = "); 

Serial.print(SJ); 

SF = analogRead(A0); 

SF = map(SF, 0, 1024, 0, 5); 

Serial.print("   Measured ADC Voltage1 = "); 

Serial.println(SF); 

delay(10); 

} 
