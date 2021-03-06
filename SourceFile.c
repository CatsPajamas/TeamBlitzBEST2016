#pragma config(Motor,  port2,           rightDriveMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftDriveMotor, tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int speed = 2;
void moveRobot()
{
	motor[rightDriveMotor] = (vexRT[Ch3] - vexRT[Ch4])/speed;
  motor[leftDriveMotor]  = (vexRT[Ch3] + vexRT[Ch4])/speed;
}

task main()
{
	while(1 == 1)
  {
  	if (vexRT[Btn8L] == 1){ //Go into "precision mode" (half default speed)
  	speed = 4;
  	}
  	if (vexRT[Btn8U] == 1){ //Go into "safety mode" (No movement, throttled by motors)
  	speed = 100;
  	}
  	if (vexRT[Btn8R] == 1){	//Go to "turbo mode" (2x default speed)
  	speed = 1;
  	}
  	if (vexRT[Btn8D] == 1){	//Return to normal speed (default speed)
  	speed = 2;
  	}
  	moveRobot();
  }
}
