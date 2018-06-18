#pragma config(Sensor, in1,    belly_angle,    sensorNone)
#pragma config(Sensor, in2,    arm_angle,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  jumper,         sensorDigitalIn)
#pragma config(Sensor, dgtl2,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, auto_mode_jumper, sensorDigitalIn)
#pragma config(Motor,  port1,           front_left,    tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           back_right,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           back_left,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          front_right,   tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

// Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void pre_auton() {
  return;
}

task autonomous() {
}

void user_control_iteration() {
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

  left = (ch1 + ch3);
  right = (ch1 - ch3);

  motor[back_left] = left;
  motor[front_left] = left;
  motor[back_right] = right;
  motor[front_right] = right;
}

task usercontrol() {
  // User control code here, inside the loop
  while (true) {
    user_control_iteration();
  }
}
