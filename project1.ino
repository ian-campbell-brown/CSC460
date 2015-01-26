#include <Servo.h> 
#include "scheduler.h"
 
#define MAX_SERVO_VAL 180
#define MIN_SERVO_VAL 0
#define MAX_JOY_STICK_VAL 1023
#define MIN_JOY_STICK_VAL 0

Servo myservo;  // create servo object to control a servo 
 

uint8_t pulse1_pin = 3; //output pin for led, can be chagned to proper pin number.

int joy_stick_potpin = 0;  // analog pin used to connect the potentiometer
int joy_stick_val;    // variable to read the value from the analog pin 
 
void pulse_pin_task(){
  digitalWrite(pulse1_pin, HIGH);
  digitalWrite(pulse1_pin, LOW);
} \

void write_servo(){
}

void idle(uint32_t idle_period){
  read_joy_stick();
}

void read_joy_stick(){
  int delta = 0; //how much to move servo
  joy_stick_val 
  int val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  
  //move joystick
  if(val < (int)(MAX_JOY_STICK_VAL * 0.25f)){
    delta = -5;
  else if(val < (int)(MAX_JOY_STICK_VAL *0.45f)){
    delta = -2;
  }else if(val >= (int)(MAX_JOY_STICK_VAL * 0.45f) && joy_stick_val <= (int)(MAX_JOY_STICK_VAL * 0.55f)){
    delta = 0;
  }else if(val < (int)(MAX_JOY_STICK_VAL *0.75f)){
    delta = 2;
  }else{
    delta = 5;
  }
  
  joy_stick_val += delta;
  if(joy_stick_val < MIN_SERVO_VAL){
    joy_stick_val = MIN_SERVO_VAL;
  }else if (joy_stick_val > MAX_SERVO_VAL){
    joy_stick_val = MAX_SERVO_VAL; 
  }
}
 
void setup() 
{ 
  //initialize all pins
  pinMode(pulse1_pin, OUTPUT)
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object ;
  joy_stick_val = (MAX_JOY_STICK_VAL - MIN_JOY_STICK_VAL)/2; start servo in middle
  
  Scheduler_Init();
  
  Scheduler_StartTask(0,joy_stick_val, write_servo);
} 
 
void loop()
{
	uint32_t idle_period = Scheduler_Dispatch();
	if (idle_period)
	{
		idle(idle_period);
	}
} 

int main()
{
	init();
	setup();
 
	for (;;)
	{
		loop();
	}
	for (;;);
	return 0;
}
