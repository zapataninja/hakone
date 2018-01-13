void basemotor(short left, short right) {
  motor[M3] = left;
  motor[M1] = left;
  motor[M10] = right;
  motor[M5] = right;
}

void bellymotor(short stimulus) {
  short sat = stimulus > 127 ? 127 : (stimulus < -127 ? -127 : stimulus);
  int kBellyUpPot = 2275;
  if (stimulus < 0 && SensorValue[belly_angle] < kBellyUpPot) {
    sat = 0;
  }
  motor[M7] = -1 * sat;
  motor[M8] = sat;
}

/***** get all sensor data on a new thread *****/
task get_sensor_data() {
  while (1) {
    string string1, string2;

    // battery data
    clearLCDLine(0);
    clearLCDLine(1);

    // Display the Primary Robot battery voltage
    displayLCDString(0, 0, "Chasis: ");
    sprintf(string1, "%1.2f%c", nImmediateBatteryLevel / 1000.0,
            'V'); // Build the value to be displayed
    displayNextLCDString(string1);

    // Display the Backup battery voltage
    displayLCDString(1, 0, "Arm: ");
    sprintf(string2, "%1.2f%c", ((float)SensorValue[M2] / 280),
            'V'); // Build the value to be displayed
    displayNextLCDString(string2);
    wait1Msec(3000);

    /**** get motor encoder data *****/
    clearLCDLine(0);
    clearLCDLine(1);
    string1 = "";
    string2 = "";
    displayLCDString(0, 0, "RM: ");
    sprintf(string1, "%d Rtns",
            abs(nMotorEncoder[M1])); // Build the value to be displayed
    displayNextLCDString(string1);

    displayLCDString(1, 0, "LM: ");
    sprintf(string2, "%d Rtns",
            abs(nMotorEncoder[M10])); // Build the value to be displayed
    displayNextLCDString(string2);
    wait1Msec(3000);

    /**** get sonar data ****/
    /*
    clearLCDLine(0);
    clearLCDLine(1);
    string1 = "";
    string2 = "";
    displayLCDString(0, 0, "SONAR: ");
    sprintf(string1, "%d CMs", SensorValue(sonar));	//Build the value to be
    displayed
    displayNextLCDString(string1);
    wait1Msec(3000);
    */
  }
}

#include "defines.h"

void auto_static_goal() {
  BASE_MOTOR_BKD
  sleep(250);
  BASE_MOTOR_ZERO
  ARM_MOTOR_UP
  sleep(1300);
  ARM_MOTOR_ZERO
  sleep(500);
  // cone is on static
  CLAW_MOTOR_OPEN
  sleep(500);
  ARM_MOTOR_DOWN
  sleep(500);
  CLAW_MOTOR_ZERO
  ARM_MOTOR_ZERO
  BASE_MOTOR_FWD
  sleep(500);
  BASE_MOTOR_ZERO
}

void auto_mobile_goal() {
  short sign = SensorValue[jumper] ? -1 : 1;

  ARM_MOTOR_UP
  sleep(700);
  ARM_MOTOR_ZERO

  // arm should have been vertical now.

  BELLY_MOTOR_DOWN
  sleep(1100);
  BELLY_MOTOR_ZERO

  BASE_MOTOR_FWD
  sleep(1800);
  BASE_MOTOR_ZERO

  // goal is picked
  BELLY_MOTOR_UP
  sleep(1700);
  BELLY_MOTOR_ZERO

  // goal is in the belly
  ARM_MOTOR_DOWN
  BASE_MOTOR_BKD
  sleep(1500);

  BASE_MOTOR_ZERO
  sleep(200);
  ARM_MOTOR_ZERO
  // cone is now on the goal

  BASE_MOTOR_CLOCKWISE
  sleep(700);
  BASE_MOTOR_BKD
  sleep(500);
  BASE_MOTOR_ZERO
  // Should be at the bump here

  BASE_MOTOR_FWD
  CLAW_MOTOR_OPEN
  ARM_MOTOR_UP
  sleep(500);
  CLAW_MOTOR_ZERO
  BASE_MOTOR_CLOCKWISE
  sleep(650);
  ARM_MOTOR_ZERO

  BASE_MOTOR_FWD
  sleep(2000);
  BASE_MOTOR_ZERO

  BELLY_MOTOR_DOWN
  sleep(1700);
  BELLY_MOTOR_ZERO

  BASE_MOTOR_BKD
  sleep(1500);
  BASE_MOTOR_ZERO
}

short nonlinear(short val) {
  int square = val * abs(val);
  return (short)square / 127;
}

void user_control_iteration() {
  // This is the main execution loop for the user control program.
  // Each time through the loop your program should update motor + servo
  // values based on feedback from the joysticks.

  // ........................................................................
  // Insert user code here. This is where you use the joystick values to
  // update your motors, etc.
  // ........................................................................

  // Remove this function call once you have "real" code.
  // UserControlCodePlaceholderForTesting();

  // Chassis motors
  short DEAD_ZONE = 15;
  short left;
  short right;
  short ch3 = vexRT[Ch3]; // + vexRT[Ch3Xmtr2];
  short ch1 = vexRT[Ch1]; // + vexRT[Ch1Xmtr2];

  if (abs(ch1) < DEAD_ZONE) {
    ch1 = 0;
  }

  if (abs(ch3) < DEAD_ZONE) {
    ch3 = 0;
  }

  short slow_factor = 1;
  ch1 = ch1 / slow_factor; // to make turning slower

  left = nonlinear(ch1 + ch3);
  right = nonlinear(ch1 - ch3);

  motor[M3] = left;
  motor[M1] = left;
  motor[M10] = right;
  motor[M5] = right;

  // BellyLoader motor
  if (vexRT[Btn6U] == 1 || vexRT[Btn6UXmtr2]) {
    bellymotor(120);
  } else if (vexRT[Btn6D] == 1 || vexRT[Btn6DXmtr2]) {
    bellymotor(-120);
  } else {
    bellymotor(0);
  }

#if 0
		// Belly control loop
		if (vexRT[Btn7L] == 1) target_pot = BELLY_POT_FRONT;
		if (vexRT[Btn7R] == 1) target_pot = BELLY_POT_REST;
		if (vexRT[Btn7U] == 1) target_pot = BELLY_POT_MID;
		short belly_pot_delta = target_pot - SensorValue(belly_angle);
		short stim = belly_pot_delta / 20; // bpd can go from -2400 to 2400
		bellymotor(stim);
#endif

  // Arm loader
  if (vexRT[Btn5U] == 1 || vexRT[Btn5UXmtr2]) {
    motor[M2] = 50;
    motor[M9] = -50;
  } else if (vexRT[Btn5D] == 1 || vexRT[Btn5DXmtr2]) {
    motor[M2] = -50;
    motor[M9] = 50;
  } else {
    motor[M2] = motor[M9] = 0;
  }

  // Gripper
  if (vexRT[Btn8R] == 1 || vexRT[Btn8RXmtr2]) {
    motor[M6] = 100;
  } else if (vexRT[Btn8L] == 1 || vexRT[Btn8LXmtr2]) {
    motor[M6] = -100;
  } else {
    motor[M6] = 0;
  }
}
