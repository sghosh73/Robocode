#ifndef TASKS_H
#define TASKS_H

#define LIFT_HEIGHT 0
#define DOOR_UP 0
#define DOOR_DOWN 0

void driveForward(int speed, int distance)
{
	nMotorEncoder[right] = 0;
	nMotorEncoder[left] = 0;

	nMotorEncoderTarget[right] = distance;
	nMotorEncoderTarget[left] = distance;

	motor[left] = -speed;
	motor[right] = speed;

	while (nMotorStaRunState[left] != runStateIdle) {}

	motor[left] = 0;
	motor[right] = 0;
}

void strafeRight(int speed, int distance) 
{

}

void strafeLeft(int speed, int distance)
{

}

void driveBackward(int speed, int distance)
{
	nMotorEncoder[right] = 0;
	nMotorEncoder[left] = 0;

	nMotorEncoderTarget[right] = distance;
	nMotorEncoderTarget[left] = distance;

	motor[left] = speed;
	motor[right] = -speed;

	while (nMotorStaRunState[left] != runStateIdle) {}

	motor[left] = 0;
	motor[right] = 0;
}

void turnRight(int speed, int distance)
{
	nMotorEncoder[right] = 0;

	nMotorEncoderTarget[right] = distance;

	motor[right] = speed;

	while (nMotorStaRunState[right] != runStateIdle) {}

	motor[right] = 0;
	wait1Msec(10);
}

void turnLeft(int speed, int distance)
{
	nMotorEncoder[left] = 0;

	nMotorEncoderTarget[left] = distance;

	motor[left] = speed;

	while (nMotorStaRunState[left] != runStateIdle) {}
		
	motor[right] = 0;
	wait1Msec(10);
}

void point_turn(int speed, int distance)
{
	nMotorEncoder[left] = 0;
	nMotorEncoder[right] = 0;

	nMotorEncoderTarget[right] = distance;
	nMotorEncoderTarget[left] = distance;

	motor[left] = speed;
	motor[right] = -speed;

	while (nMotorStaRunState[left] != runStateIdle) {}

	motor[left] = 0;
	motor[right] = 0;

	wait1Msec(10);
}


void raiseLift()
{
	nMotorEncoder[lift] = 0;
	nMotorEncoderTarget = LIFT_HEIGHT
	motor[lift] = 50;
	while (nMotorStaRunState[lift] != runStateIdle) {}
	motor[lift] = 0;
}

void depositBall()
{
	servo[door] = DOOR_DOWN;
	wait1Msec(500);
	servo[door] = DOOR_UP;
}

#endif 