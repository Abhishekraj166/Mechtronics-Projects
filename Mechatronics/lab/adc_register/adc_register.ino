int digital;
void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
 ADMUX |= (1 << REFS0); //Ref V
 ADMUX |= (1 << MUX0); //Input Channel ADC1(PortC1)
 ADCSRA |= (1 << ADEN); //Enable the ADC
 ADCSRA |= (1 << ADSC); //Start Conversion
 ADCSRA |= (1 << ADATE); //Enable Auto trigger
 ADCSRA |= (1 << ADIE); //Enable interrupt
 //Prescaler
 ADCSRA |= (1 << ADPS2);
 ADCSRA |= (1 << ADPS1);
}
void loop() {
 // write ’1′ to ADSC to start conversion
 ADCSRA |= (1<<ADSC);
 // wait for conversion to complete
 // ADSC becomes ’0′ again
 // till then, run loop continuously
 while(ADCSRA & (1<<ADSC));
 digital = ADC;
 Serial.println(digital);
}
