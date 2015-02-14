#pragma config(Hubs,  S4, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,          spinnerA,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          spinnerB,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S4_C1_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     collector,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C3_1,     front_right,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C3_2,     front_left,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C4_1,     back_right,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C4_2,     back_left,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C2_1,    hook1,                tServoStandard)
#pragma config(Servo,  srvo_S4_C2_2,    hook2,                tServoStandard)
#pragma config(Servo,  srvo_S4_C2_3,    spinner1,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C2_4,    spinner2,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C2_5,    door,                 tServoStandard)
#pragma config(Servo,  srvo_S4_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

#define DOOR_DOWN 90
#define DOOR_UP 250

#define HOOK_DOWN 120
#define HOOK_UP 200


void TankDrive()
{
	getJoystickSettings(joystick);			 // Allows use of Joysticks

	int leftspeed =  joystick.joy1_y1;
 	int rightspeed =  joystick.joy1_y2;
  	int threshold = 20;


	if (abs(leftspeed) < threshold) {
		motor[front_left] = 0;
		motor[back_left] = 0;
	}
	else {
		motor[front_left] = leftspeed;
		motor[back_left] = leftspeed;
	}

	if (abs(rightspeed) < threshold) {
		motor[front_right] = 0;
		motor[back_right] = 0;
	}
	else {
		motor[front_right] = -rightspeed;
		motor[back_right] = -rightspeed;
	}
}

task main()
{
	motor[spinnerA] = 0;
  	motor[spinnerB] = 0;

 	motor[lift] = 0;

	servo[spinner1] = 128;
	servo[spinner2] = 128;

	servo[door] = DOOR_UP;

	bool hookSwitcher = false;
	bool hookPressed = false;

	bool doorSwitcher = false;
	bool doorPressed = false;

	int threshold = 20;

	getJoystickSettings(joystick);

	while (true) {

		TankDrive();

		//stops spinners
		if (joy1Btn(05)) {
			//motor[spinnerA] = 0;
			//motor[spinnerB] = 0;

			motor[collector] = 0;

			servo[spinner1] = 128;
			servo[spinner2] = 128;
		}

		//spins spinner
		if (joy1Btn(07)) {
			//motor[spinnerA] = -100;
			//motor[spinnerB] = -100;

			motor[collector] = 100;

			servo[spinner1] = 100;
			servo[spinner2] = 200;
		}

		//raise or lower lift (controller 2)
		if (abs(joystick.joy2_y2) > threshold) {
			motor[lift] = -joystick.joy2_y2;
		}
		//lift up (controller 1)
		else if (joy1Btn(04) && abs(joystick.joy2_y2) < threshold) {
			motor[lift] = -100;
		}
		//lift down (controller 1)
		else if (joy1Btn(02) && abs(joystick.joy2_y2) < threshold) {
			motor[lift] = 100;
		}
		//lift stopped
		else {
			motor[lift] = 0;
		}

		if ((joy1Btn(03) || joy2Btn(03)) && !doorPressed) {
			if (doorSwitcher){
			   doorSwitcher = false;
		  	}
		  	else {
		     	doorSwitcher = true;
		  	}
	  		doorPressed = true;
		}

		if (!(joy1Btn(03) || joy2Btn(03)) && doorPressed) {
    		doorPressed = false;
    	}

		if (!doorSwitcher) {
     		servo[door] = DOOR_DOWN;
		}
    	else {
    		servo[door] = DOOR_UP;
    	}

		if (joy1Btn(06)) {
     		servo[hook1] = HOOK_UP+15;
     		servo[hook2] = 180-HOOK_UP;
		}
    	if (joy1Btn(08)) {
    		servo[hook1] = HOOK_DOWN+20;
    		servo[hook2] = HOOK_DOWN-50;
    	}
	}
}
