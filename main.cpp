/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\vex                                              */
/*    Created:      Thu Dec 09 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// left_motor           motor         1               
// right_motor          motor         4               
// Controller1          controller                    
// four_bar_group       motor_group   6, 7            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drivercontrol.h"
#include "auton.h"
using namespace vex;
competition Competition;

// Pre Autonomous Event Callback
void pre_auton()
{
  left_motor.setVelocity(0, percent);
  right_motor.setVelocity(0, percent);
  four_bar_group.setVelocity(0,  percent);

  left_motor.spin(forward);
  right_motor.spin(forward);
  four_bar_group.spin(forward);
}

// Main Function.
int main()
{
  pre_auton();
  
  Competition.drivercontrol(dc);
  Competition.autonomous(auton);
}
