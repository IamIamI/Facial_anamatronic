//https://www.instructables.com/Simplified-3D-Printed-Animatronic-Dual-Eye-Mechani/
#include <ESP32Servo.h>

//LR = Left-Right, UD = Up-Down

// declare variables for eye and eyelid movements
int EyePosLR_mid = 55; // Starts at EyeLR centre point
int EyePosLR_min = 10; // Min EyeLR movement (right)
int EyePosLR_max = 100; // Max EyeLR movement (left)
int EyePosUD_mid = 20; // Starts at EyeUD centre point
int EyePosUD_max = 40; // Max EyeUD movement (left)
int EyeLidU_max = 90; // Max opening of Eyelid upper
int EyeLidD_max = 90; // Max opening of Eyelid lower

// Create and declare servo variables for eyes and eyelids
Servo EyeLR_Servo;  // create servo object to control a servo
const int EyeLR_Pin = 17; // Pin output (D17)
int EyeLR_Pos = EyePosLR_mid;    // EyeLR_Pos mid pos (10 is looking to the right, 100 is looking to the left, 50 middle)

Servo EyeUD_Servo;  
const int EyeUD_Pin = 16; 
int EyeUD_Pos = EyePosUD_mid;    // EyeUD_Pos mid pos (45 is looking up, 0 is looking down, 23 is middle)

Servo EyeLidLU_Servo;  
const int EyeLidLU_Pin = 15; 
//int EyeLidLU_Pos = 60;    // EyeLidU_Pos open pos (10 is looking to the right, 100 is looking to the left, 55 middle)

Servo EyeLidRU_Servo; 
const int EyeLidRU_Pin = 21; 
//int EyeLidRU_Pos = 0;

Servo EyeLidLD_Servo;
const int EyeLidLD_Pin = 18; 
//int EyeLidLD_Pos = 0;    // EyeLidD_Pos open pos (10 is looking to the right, 100 is looking to the left, 55 middle)

Servo EyeLidRD_Servo; 
const int EyeLidRD_Pin = 19; 
//int EyeLidRD_Pos = 50; 
int EyeLid_Upper_Pos=0;
int EyeLid_Lower_Pos=0;


const int joy_y =  14; //pin for the joystick x-axis
const int joy_x =  34; //pin for the joystick y-axis
// Joydyivk min max = x[0,4095],y[0,4095]
int joy_x_val = 2048; // mid value of joystick
int joy_y_val = 2048;
const int joy_b = 35;  // the number of the pushbutton pin
int joy_b_State = 0; // on/off state of the button

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Initialize eyes LR / UD
  EyeLR_Servo.attach(EyeLR_Pin); // attaches the servo on pin ## to the servo object
  EyeUD_Servo.attach(EyeUD_Pin);

  // Initialize eyelids Open/Close
  EyeLidLU_Servo.attach(EyeLidLU_Pin);
  EyeLidLD_Servo.attach(EyeLidLD_Pin);
  EyeLidRU_Servo.attach(EyeLidRU_Pin);
  EyeLidRD_Servo.attach(EyeLidRD_Pin);

  //Initialize joystick
  pinMode(joy_y, INPUT);
  pinMode(joy_x, INPUT);
  pinMode(joy_b, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  joy_y_val = analogRead(joy_y);
  joy_x_val = analogRead(joy_x);
  joy_b_State = digitalRead(joy_b);
  Serial.print("Joystick_x:");
  Serial.print(joy_x_val);
  Serial.print(",");
  Serial.print("Joystick_y:");
  Serial.println(joy_y_val);
  Serial.print(",");
  Serial.print("Button:");
  Serial.println(joy_b_State);

  EyeLR_Servo.write(EyeLR_Pos);
//  Serial.print(EyeLR_Pos);
  if (EyeLR_Pos < 100) { // goes from 0 degrees to 180 degrees
    EyeLR_Pos += 10;
    EyeLR_Servo.write(EyeLR_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLR_Pos = 10;
  }

  EyeUD_Servo.write(EyeUD_Pos);
 
  if (EyeUD_Pos < EyePosUD_max) { // goes from 0 degrees to 180 degrees
    EyeUD_Pos += 5;
    EyeUD_Servo.write(EyeUD_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeUD_Pos = 0;
  }
/*
  EyeLidLD_Servo.write(EyeLidLD_Pos);
  if (EyeLidLD_Pos < 50) { // goes from 0 degrees to 180 degrees
    EyeLidLD_Pos += 5;
    EyeLidLD_Servo.write(EyeLidLD_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLidLD_Pos = 0;
  }

  EyeLidLU_Servo.write(EyeLidLU_Pos);
  if (EyeLidLU_Pos > 0) { // goes from 0 degrees to 180 degrees
    EyeLidLU_Pos -= 5;
    EyeLidLU_Servo.write(EyeLidLU_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLidLU_Pos = 60;
  }

  EyeLidRD_Servo.write(EyeLidRD_Pos);
  if (EyeLidRD_Pos > 0) { // goes from 0 degrees to 180 degrees
    EyeLidRD_Pos -= 5;
    EyeLidRD_Servo.write(EyeLidRD_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLidRD_Pos = 50;
  }

  EyeLidRU_Servo.write(EyeLidRU_Pos);
  if (EyeLidRU_Pos < 60) { // goes from 0 degrees to 180 degrees
    EyeLidRU_Pos += 5;
    EyeLidRU_Servo.write(EyeLidRU_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLidRU_Pos = 0;
  }
*/
//int EyeLidLU_Pos = 60;    // EyeLidU_Pos open pos (10 is looking to the right, 100 is looking to the left, 55 middle)
//int EyeLidRU_Pos = 0;
//int EyeLidLD_Pos = 0;    // EyeLidD_Pos open pos (10 is looking to the right, 100 is looking to the left, 55 middle)
//int EyeLidRD_Pos = 50; 

  EyeLidLD_Servo.write(0);
  EyeLidLU_Servo.write(60);
  EyeLidRD_Servo.write(50);
  EyeLidRU_Servo.write(0);
  if (EyeLid_Upper_Pos > 0) { // goes from 0 degrees to 180 degrees
    EyeLid_Upper_Pos -= 5;
    EyeLidLU_Servo.write(EyeLid_Upper_Pos);
    EyeLidRU_Servo.write(60-EyeLid_Upper_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLid_Upper_Pos = 60;
  }
  if (EyeLid_Lower_Pos > 0) { // goes from 0 degrees to 180 degrees
    EyeLid_Lower_Pos -= 5;
    EyeLidLD_Servo.write(EyeLid_Lower_Pos);              // tell servo to go to position in variable 'pos'     
    EyeLidRD_Servo.write(50-EyeLid_Lower_Pos);              // tell servo to go to position in variable 'pos'     
  } else {
    EyeLid_Lower_Pos = 50;
  }

  delay(50);
}
