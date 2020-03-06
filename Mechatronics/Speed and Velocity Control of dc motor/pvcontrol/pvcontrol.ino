double count = 0; //set the counts of the encoder
double angle = 0;//set the angles
boolean A,B;
byte state, statep;


const int dir1 = 10;//these pins are to control the direction of the motor (clockwise/counter-clockwise)
const int dir2 = 9;

double setpoint = 25;//
double Kp = 1;// you can set these constants however you like depending on trial & error
double Ki = 0.01;
double Kd = 0.01;

float last_error = 0;
float error = 0;
float changeError = 0;
float totalError = 0;
float pidTerm = 0;
float pidTerm_scaled = 0;// if the total gain we get is not in the PWM range we scale it down so that it's not bigger than |255|


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
  
  PIDcalculation();// find PID value
  
  if (angle < setpoint) {
    digitalWrite(dir1, LOW);// Forward motion
    analogWrite(dir2, pidTerm_scaled);
  } else {
    analogWrite(dir1, pidTerm_scaled);//Reverse motion
    digitalWrite(dir2, LOW);
  }


  Serial.print("WHEEL ANGLE:");
  Serial.print(angle);
  Serial.print("\t");
   Serial.println(pidTerm_scaled);

  delay(100);
}

void PIDcalculation(){
  angle = (0.3 * count);//count to angle conversion
  error = setpoint - angle;
  
  changeError = error - last_error; // derivative term
  totalError += error; //accumalate errors to find integral term
  pidTerm = (Kp * error) + (Ki * totalError) + (Kd * changeError);//total gain
  pidTerm = constrain(pidTerm, -255, 255);//constraining to appropriate value
  pidTerm_scaled = abs(pidTerm);//make sure it's a positive value

  last_error = error;
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
