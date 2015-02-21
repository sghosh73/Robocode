#pragma config(Hubs,  S4, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S3,     sonar,          sensorSONAR)
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

#include "utilities.h"
#include "JoystickDriver.c"
#include "hitechnic-irseeker-v2.h"

task main()
{


	waitForStart();
	while (SensorValue[sonar] > 30) {
		DriveBackward(50, -1);
		nxtDisplayBigTextLine(3, "%d", nMotorEncoder[front_left]);
	}
	stop();
		nxtDisplayBigTextLine(3, "%d", nMotorEncoder[front_left]);
	raiseLift(CENTER_SCORE);
	depositBall();
	lowerLift(CENTER_SCORE);

}