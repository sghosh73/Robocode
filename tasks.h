#pragma config(Hubs,  S4, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,          spinnerA,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          spinnerB,      tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S4_C1_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C3_1,     front_right,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C3_2,     front_left,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C4_1,     back_right,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C4_2,     back_left,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C2_1,    hook,                 tServoStandard)
#pragma config(Servo,  srvo_S4_C2_2,    hook,                 tServoStandard)
#pragma config(Servo,  srvo_S4_C2_3,    spinner1,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C2_4,    spinner2,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C2_5,    door,                 tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#ifndef TASKS_H
#define TASKS_H

#include "JoystickDriver.c"
#include "utilities.h"
#include "constants.h"

/*
TODO: VALUES FOR DRIVE NEED TO BE TESTED, CHANGED
*/

void score_ball_tube(int startPos)
{
	if (startPos == RAMP_STARTING) {
		while (SensorValue(ultrasonic) < TUBE_DISTANCE) { //drive until TUBE_DISTANCE away from first tube
			driveForward(50, -1);
		}
		stop();
		clamp();
		raiseLift(LIFT_TUBE);
		depositBall();
	}
	else { //starting on ramp
		while (sensorValue(ultrasonic) < RAMP_DISTANCE) {
			driveBackWard(25, -1);
		}
		turnLeft(50, 100);
		while (SensorValue(ultrasonic) < TUBE_DISTANCE) { //drive until TUBE_DISTANCE away from first tube
			driveForward(50, -1);
		}
		stop();
		clamp();
		raiseLift(LIFT_TUBE);
		depositBall();
	}
}

void score_ball_center(int startPos)
{

}


#endif