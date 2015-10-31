#define lf_speed 5   //left front chip enable pin                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
#define rf_speed 10  //right front chip enable pin
#define lb_speed 6   //left back chip enable pin
#define rb_speed 11  //right back chip enable pin
#define lmf 4   //left motor forward
#define lmb 7   //left motor back
#define rmf 8   //right motor forward
#define rmb 9   //left motor back

int drive_speed=255; // set drive speed in the range 0 to 255

//turn left
void left ()
{
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}

//turn right
void right ()
{
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
}

//move forward
void fwd ()
{
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}

//move backwards
void rev ()
{
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
}

//stop motion
void stp ()
{
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}

//initialise pins and set initial speeds
void motor_init()
{
  for (int i = 2; i<=12; i++)
    pinMode(i , OUTPUT);
  digitalWrite(12, HIGH);
  analogWrite( lf_speed, 255);
  analogWrite( rf_speed, 255);
  analogWrite( lb_speed, 255);
  analogWrite( rb_speed, 255);
}

//set drive speed
void set_speed(int spd)
{
  if(spd >= 0 && spd <= 255)
  {
    analogWrite( lf_speed, spd);
    analogWrite( rf_speed, spd);
    analogWrite( lb_speed, spd);
    analogWrite( rb_speed, spd);
  }
}
//simple test code to check motors
void test()
{
left();
delay(1000);
right();
delay(1000);
fwd();
delay(1000);
rev();
delay(1000);
stp();
delay(30000);
}

char a;
void setup() {
  motor_init();  //initialize motor driver pins
  Serial.begin(9600); //begin serial communications
  //test();
}

void loop() {
  if(Serial.available())
  {
    a=Serial.read();
    if(a=='F')
      fwd();
    else if(a=='B')
      rev();
    else if(a=='L')
      left();
    else if(a=='R')
      right();
    else if(a=='S')
      stp();
    else if(a=='W')
    {
      analogWrite( lf_speed, 255);
      analogWrite( rf_speed, 255);
    }
    else if(a=='w')
     {
      analogWrite( lf_speed, 0);
      analogWrite( rf_speed, 0);
    }
    else if(a=='U')
     {
      analogWrite( lb_speed, 255);
      analogWrite( rb_speed, 255);
    }
    else if(a=='u')
     {
      analogWrite( lb_speed, 0);
      analogWrite( rb_speed, 0);
    }
    //else if(a > '1' && a < '3')
  }
}
