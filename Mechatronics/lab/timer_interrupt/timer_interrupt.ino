
#include "TimerOne.h"
#define LED1 PB1
#define LED2 PB4
#define LED3 PB3
#define LED4 PB2
#define S1 PD2
#define S2 PD3
#define S3 PD4
#define S4 PD5


const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;
const uint16_t t2_load = 0;
const uint16_t t2_comp = 31250;
const uint16_t t3_load = 0;
const uint16_t t3_comp = 31250;
const uint16_t t4_load = 0;
const uint16_t t4_comp = 31250;


void setup() 
 
  {
 DDRD = DDRD | B11000011;
 DDRB |= (1<<LED1);
  DDRB |= (1<<LED2);
   DDRB |= (1<<LED3);
    DDRB |= (1<<LED4);

 TCCR1A = 0;
 TCCR1B |= ( 1 << CS12);
 TCCR1B &= ~(1 << CS11);
 TCCR1B &= ~(1 << CS10);

 TCNT1 = t1_load;
 OCR1A = t1_comp;
  TCNT1 = t2_load;
 OCR1A = t2_comp;
  TCNT1 = t3_load;
 OCR1A = t3_comp;
  TCNT1 = t4_load;
 OCR1A = t4_comp;

 TIMSK1 = (1<< OCIE1A);

 sei();
}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
}

ISR(TIMER1_COMPA_vect) {
  int btn1 = (PIND & (1 << S1)) >> S1;
  int btn2 = (PIND & (1 << S2)) >> S2;
  int btn3 = (PIND & (1 << S3)) >> S3;
  int btn4 = (PIND & (1 << S4)) >> S4;
     
  if ( btn1 == LOW){
  TCNT1 = t1_load;
  PORTB ^= (1 << LED1);
  } else
  {
  PORTB = ~(1 << LED1) & PORTB;
  } 
  if ( btn2 == LOW){
  TCNT1 = t2_load;
  PORTB ^= (1 << LED2);
  } else
  {
  PORTB = ~(1 << LED2) & PORTB;
  } 
  if ( btn3 == LOW){
  TCNT1 = t3_load;
  PORTB ^= (1 << LED3);
  } else
  {
  PORTB = ~(1 << LED3) & PORTB;
  } 
  if ( btn4 == LOW){
  TCNT1 = t4_load;
  PORTB ^= (1 << LED4);
  } else
  {
  PORTB = ~(1 << LED4) & PORTB;
  } 
}
