#pragma config(Motor,  port2,           rightDriveMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           armDriveMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           valveControlServo, tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           leftDriveMotor, tmotorServoContinuousRotation, openLoop)

const int zeroThreshold = 9;

float driveMotorFactor = .5;

void moveRobot()
{
	float rightMotorSpeed = -(vexRT[Ch3] + vexRT[Ch4])*driveMotorFactor;
	float leftMotorSpeed = -(vexRT[Ch3] - vexRT[Ch4])*driveMotorFactor;

	motor[rightDriveMotor] = abs(rightMotorSpeed) < zeroThreshold ? 0 : rightMotorSpeed;
  motor[leftDriveMotor]  = abs(leftMotorSpeed) < zeroThreshold ? 0 : leftMotorSpeed;
}

void moveArm()
{
	float armMotorSpeed = vexRT[Ch2];

  motor[armDriveMotor] = abs(armMotorSpeed) < zeroThreshold ? 0 : armMotorSpeed;
}

void moveValveControl()
{
	  if (vexRT[Btn7L] == 1){
  		motor[valveControlServo] = -127;
    }
  	if (vexRT[Btn7R] == 1){
  		motor[valveControlServo] = 127;
    }
    if (vexRT[Btn7U] == 1){
  		motor[valveControlServo] = 0;
    }
}

task main()
{
	while(1 == 1)
  {
  	if (vexRT[Btn8L] == 1){ //Go into "precision mode" (half default speed)
  		driveMotorFactor = .25;
  	}
  	if (vexRT[Btn8U] == 1){ //Go into "safety mode" (No movement, throttled by motors)
  		driveMotorFactor = 0;
  	}
  	if (vexRT[Btn8R] == 1){	//Go to "turbo mode" (2x default speed)
  		driveMotorFactor = 1;
  	}
  	if (vexRT[Btn8D] == 1){	//Return to normal speed (default speed)
  		driveMotorFactor = .5;
  	}


  	moveRobot();
  	moveArm();
  	moveValveControl();
  }
}
