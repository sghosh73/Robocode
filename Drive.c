#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     back_right,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     front_right,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     back_left,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     front_left,    tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

#define ROT_CONST 0.39 
#define DRIVE_CONST 0.78

/*
Drive configuration:

	   Front
	  _______
  1 O|       |O 2
	 |       |
	 |       |
	 |       |
  3 O|_______|O 4

  1: cos(theta-PI/4)
  2: cos(theta+PI/4)
  3: cos(theta+PI/4)
  4: cos(theta-PI/4)

  Positive rotation is forward
*/
void drive()
{
	getJoystickSettings(joystick);

	int threshold = 20; //minimum value of joystick before activating drive

	int x = joystick.joy1_x1;
	int y = -1*joystick.joy1_y1; //y is inverted

	int rot = joystick.joy1_x2;
	int rotL;
	int rotR;

	float angle = atan2(y,x);
	float length = sqrt(pow(x,2)+pow(y,2));

	if(length < threshold){
		length = 0;
  	}

	if (abs(rot) < threshold) {
		rotL = 0;
		rotR = 0;
	}

	else {
		rotL = ROT_CONST * rot; 
		rotR = ROT_CONST * rot;
	}

	int f_left = DRIVE_CONST * cos(angle-(PI/4)) * length + rotL;
	int f_right = DRIVE_CONST * cos(angle+(PI/4)) * length + rotL;
	int b_left = DRIVE_CONST * cos(angle+(PI/4)) * length + rotR;
	int b_right = DRIVE_CONST * cos(angle-(PI/4)) * length + rotR;

	motor[front_left] = f_left;
	motor[front_right] = f_right;
	motor[back_left] = b_left;
	motor[back_right] = b_right;

	//nxtDisplayBigTextLine(3, "X: %d Y: %d", x, y);
}
