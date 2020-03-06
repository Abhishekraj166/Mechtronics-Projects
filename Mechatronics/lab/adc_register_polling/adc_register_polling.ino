const byte adcPin = 0;  // A0
const byte adcOutput = 1;  
bool working;
  
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
void loop () 
  { 
  if (!working)
    {
    bitSet (ADCSRA, ADSC);  // start a conversion
    working = true;
    }
    
  // the ADC clears the bit when done
  if (bit_is_clear(ADCSRA, ADSC))
    {
    int value = ADC;  // read result
    working = false;
    Serial.println (value);
    delay (500);  
    }
    
  }  // end of loop  
