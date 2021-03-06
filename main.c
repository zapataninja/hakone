#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Motor,  port1,           LB,            tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           LF,            tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           RF,            tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          RB,            tmotorVex393TurboSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

string firstLine, secondLine;
int Program = 1;

const int DRIVE_THRESHOLD = 20;

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;


	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	//Leave this value alone
	int lcdScreenMin = 1;
	//This keeps track of which program you want to run
	int lcdScreen = 1;
	//Change this value to be the maximum number of programs you want on the robot
	int lcdScreenMax = 4;
	//Turns on the Backlight
	bLCDBacklight = true;

	//Copied from someone's sample code because the documentation for RobotC won't tell me anything useful
	//These should logically work, but I'm not 100% sure
	const short leftButton = 1;
	const short centerButton = 2;
	const short rightButton = 4;



	while (vrDisabled == 1) { //Ensures this code will run ONLY when the robot is disabled
		if (nLCDButtons == leftButton) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				wait1Msec(250);
			} else {
				lcdScreen --;
				wait1Msec(250);
			}
		}
		if (nLCDButtons == rightButton) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				wait1Msec(250);
			} else {
				lcdScreen++;
				wait1Msec(250);
			}
		}
		if (lcdScreen == 1 && Program != 1) {
			displayLCDCenteredString (0, "Program"); //Name the first program here
			displayLCDCenteredString (1, "1"); //Name the first program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 1 && Program == 1) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[1]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 2 && Program != 2) {
			displayLCDCenteredString (0, "Program"); //Name the second program here
			displayLCDCenteredString (1, "2"); //Name the second program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 2 && Program == 2) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[2]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 3 && Program != 3) {
			displayLCDCenteredString (0, "Program"); //Name the third program here
			displayLCDCenteredString (1, "3"); //Name the third program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 3 && Program == 3) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[3]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 4 && Program != 4) {
			displayLCDCenteredString (0, "Program"); //Name the fourth program here
			displayLCDCenteredString (1, "4"); //Name the fourth program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 4 && Program == 4) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[4]"); //So that while we're scrolling, we can have one marked
		}
	}

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................
	if(Program == 1){
		//Put your second program in here
	}
	else if(Program == 2){
		//Put your second program in here
	}
	else if(Program == 3){
		//Put your third program in here
	}
	else if(Program == 4){
		//Pur your fourth program in here
	}


  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.

  	sprintf(firstLine, "C2:%d; C3:%d", vexRT[Ch2], vexRT[Ch3]);
		displayLCDCenteredString(0, firstLine);

		if (abs(vexRT[Ch2]) > DRIVE_THRESHOLD) {
	  	motor[RF] = vexRT[Ch2];
	  	motor[RB] = vexRT[Ch2];
		} else {
	  	motor[RF] = 0;
	  	motor[RB] = 0;
		}

	if (abs(vexRT[Ch3]) > DRIVE_THRESHOLD) {
	  	motor[LF] = vexRT[Ch3];
	  	motor[LB] = vexRT[Ch3];
		} else {
	  	motor[LF] = 0;
	  	motor[LB] = 0;
		}

    UserControlCodePlaceholderForTesting();
  }
}
