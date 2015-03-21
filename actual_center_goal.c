#pragma config(Hubs,  S4, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     sonar,          sensorSONAR)
#pragma config(Sensor, S3,     color,          sensorColorNxtFULL)
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


task main()
{

	waitForStart();

	string sColor;
	driveBackward(50, 2500);
	wait1Msec(2000);
	int distance = SensorValue[sonar];
	wait1Msec(2000);
	if (distance < 50) {
		driveBackward(50, 500);
		string sColor;
			switch (SensorValue[color])
    	{
      	case BLACKCOLOR:    sColor = "Black";     break;
      	case BLUECOLOR:     sColor = "Blue";      break;
      	case GREENCOLOR:    sColor = "Green";     break;
      	case YELLOWCOLOR:   sColor = "Yellow";    break;
      	case REDCOLOR:      sColor = "Red";       break;
      	case WHITECOLOR:    sColor = "White";     break;
      	default:            sColor = "???";       break;
    }
    if (sColor == "YELLOW") {
    	driveForward(50, 1000);
    	raiseLift(1);
    	depositBall();
    	lowerLift(1);
  	}
	}
	else {
		while (true) {
			nxtDisplayBigTextLine(3, "%d\n", distance);
		}
	}
}
