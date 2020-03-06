double count = 0; //set the counts of the encoder
double angle = 0;//set the angles
boolean A,B;
byte state, statep;


const int dir1 = 10;//these pins are to control the direction of the motor (clockwise/counter-clockwise)
const int dir2 = 9;


double Kp = 1;// you can set these constants however you like depending on trial & error
double Ki = 0.01;
double Kd = 0.01;

float last_error = 0;
float error = 0;
float changeError = 0;
float totalError = 0;
float pidTerm = 0;
float pidTerm_scaled = 0;// if the total gain we get is not in the PWM range we scale it down so that it's not bigger than |255|
double timer1_counter;
double pv_speed;
double e_speed;
double set_speed =20;
double pwm_pulse;
double e_speed_sum;
double e_speed_pre;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);//encoder pins
  pinMode(3, INPUT);
  attachInterrupt(0,Achange,CHANGE);//interrupt pins for encoder
  attachInterrupt(1,Bchange,CHANGE); 
  
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

}

void loop(){
  pid();
  if (pv_speed>0) {
    digitalWrite(dir1, LOW);// Forward motion
    analogWrite(dir2, pwm_pulse);
  } else {
    analogWrite(dir1, pwm_pulse);//Reverse motion
    digitalWrite(dir2, LOW);
  }


  Serial.print("WHEEL ANGLE:");
  Serial.print(angle);
  //Serial.print("\t");
   //Serial.println(pidTerm_scaled);
  Serial.print("speed");
  Serial.println(pwm_pulse);
  delay(100);
}
ISR(TIMER1_OVF_vect)        // interrupt service routine - tick every 0.1sec
 {
   TCNT1 = timer1_counter;   // set timer
   pv_speed = 60.0*(pwm_pulse/200.0)/0.1;  //calculate motor speed, unit is rpm
   count=0;
   //print out speed
   if (Serial.available() <= 0) {
     Serial.print("speed");
     Serial.println(pv_speed);         //Print speed (rpm) value to Visual Studio
     }}
void pid(){
     e_speed = set_speed - pv_speed;
     pwm_pulse = e_speed*Kp + e_speed_sum*Ki + (e_speed - e_speed_pre)*Kd;
     e_speed_pre = e_speed;  //save last (previous) error
     e_speed_sum += e_speed; //sum of error
     if (e_speed_sum >4000) e_speed_sum = 4000;
     if (e_speed_sum <-4000) e_speed_sum = -4000;
  
  //update new speed
   if (pwm_pulse <255 & pwm_pulse >0){
     analogWrite(9,pv_speed);  //set motor speed 
   }
   else{
     if (pwm_pulse>255){
       analogWrite(9,255);
     }
     else{
       analogWrite(9,0);
     }
   }
 }

  
void Achange() //these functions are for finding the encoder counts
{
  A = digitalRead(2);
  B = digitalRead(3);

  if ((A==HIGH)&&(B==HIGH)) state = 1;
  if ((A==HIGH)&&(B==LOW)) state = 2;
  if ((A==LOW)&&(B==LOW)) state = 3;
  if((A==LOW)&&(B==HIGH)) state = 4;
  switch (state)
  {
    case 1:
    {
      if (statep == 2) count++;
      if (statep == 4) count--;
      break;
    }
    case 2:
    {
      if (statep == 1) count--;
      if (statep == 3) count++;
      break;
    }
    case 3:
    {
      if (statep == 2) count --;
      if (statep == 4) count ++;
      break;
    }
    default:
    {
      if (statep == 1) count++;
      if (statep == 3) count--;
    }
  }
  statep = state;

}

void Bchange()
{
  A = digitalRead(2);
  B = digitalRead(3);

  if ((A==HIGH)&&(B==HIGH)) state = 1;
  if ((A==HIGH)&&(B==LOW)) state = 2;
  if ((A==LOW)&&(B==LOW)) state = 3;
  if((A==LOW)&&(B==HIGH)) state = 4;
  switch (state)
  {
    case 1:
    {
      if (statep == 2) count++;
      if (statep == 4) count--;
      break;
    }
    case 2:
    {
      if (statep == 1) count--;
      if (statep == 3) count++;
      break;
    }
    case 3:
    {
      if (statep == 2) count --;
      if (statep == 4) count ++;
      break;
    }
    default:
    {
      if (statep == 1) count++;
      if (statep == 3) count--;
    }
  }
  statep = state;
  
}
