#define ARM_MOTOR_ZERO                                                         \
  { motor[M2] = motor[M9] = 0; };
// do not set arm motor power to 127, otherwise it will thud and change
// alignment
#define ARM_MOTOR_DOWN                                                         \
  {                                                                            \
    motor[M2] = -64;                                                           \
    motor[M9] = 64;                                                            \
  };
#define ARM_MOTOR_UP                                                           \
  {                                                                            \
    motor[M2] = 64;                                                            \
    motor[M9] = -64;                                                           \
  };

#define BASE_MOTOR_FWD basemotor(127, -127);
#define BASE_MOTOR_BKD basemotor(-127, 127);
#define BASE_MOTOR_ZERO basemotor(0, 0);
#define BASE_MOTOR_CLOCKWISE basemotor(sign * 127, sign * 127);
#define BASE_MOTOR_COUNTERCLOCKWISE basemotor(-127 * sign, -127 * sign);

#define BELLY_MOTOR_DOWN                                                       \
  {                                                                            \
    motor[M7] = -127;                                                          \
    motor[M8] = 127;                                                           \
  }
#define BELLY_MOTOR_UP                                                         \
  {                                                                            \
    motor[M7] = 127;                                                           \
    motor[M8] = -127;                                                          \
  }
#define BELLY_MOTOR_ZERO                                                       \
  { motor[M7] = motor[M8] = 0; }

#define CLAW_MOTOR_OPEN                                                        \
  { motor[M6] = 127; }
#define CLAW_MOTOR_ZERO                                                        \
  { motor[M6] = 0; }

#define BELLY_POT_REST 725   // value of pot when loader is all the way back
#define BELLY_POT_FRONT 3275 // value of pot when loader is all the way front
#define BELLY_POT_MID 2000
