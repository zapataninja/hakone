#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    belly_angle,    sensorNone)
#pragma config(Sensor, in2,    arm_angle,      sensorPotentiometer)
#pragma config(Sensor, dgtl1,  jumper,         sensorDigitalIn)
#pragma config(Sensor, dgtl2,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, auto_mode_jumper, sensorDigitalIn)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           M1,            tmotorVex393HighSpeed_HBridge, PIDControl, encoderPort, I2C_1)
#pragma config(Motor,  port2,           M2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           M3,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           M4,            tmotorNone, openLoop)
#pragma config(Motor,  port5,           M5,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           M6,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           M7,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           M8,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           M9,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          M10,           tmotorVex393HighSpeed_HBridge, PIDControl, encoderPort, I2C_2)
