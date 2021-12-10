#include <thread>
#include "vex.h"
using namespace vex;

// Main DriverControl Function
void dc()
{
  // Drivetrain right group.
  right_motor.setVelocity(Controller1.Axis3.position() - Controller1.Axis1.position(), percent); 
  
  // Drivetrain left group.
  left_motor.setVelocity(Controller1.Axis3.position() + Controller1.Axis1.position(), percent);

  // Claw Thread.
  thread claw_controller([](){
    while(true)
    {
      if (Controller1.ButtonL1.pressing())
      {
        claw_motor.setVelocity(claw_motor.velocity(percent) + 10, percent);
      }
      else
      {
        claw_motor.setVelocity(0, percent);
      }

      if (Controller1.ButtonL2.pressing())
      {
        claw_motor.setVelocity(claw_motor.velocity(percent) + 10, percent);
      }
      else
      {
        claw_motor.setVelocity(0, percent);
      }
    }
    wait(50, msec);
  });

  // Four Bar controls using R1/R2 buttons.
  Controller1.ButtonR1.pressed([](){
    four_bar_group.setVelocity(100, percent);
  });

  Controller1.ButtonR2.pressed([](){
    four_bar_group.setVelocity(-100, percent);
  });
}
