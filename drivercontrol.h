#include "vex.h"
using namespace vex;

// Event Callbacks.
void move_fourbar_up()
{
  four_bar_group.setVelocity(100, percent);
}

void move_fourbar_down()
{ 
  four_bar_group.setVelocity(-100, percent);
}

// Main DriverControl Function
void dc()
{
  // Drivetrain right group.
  right_motor.setVelocity(Controller1.Axis3.position() - Controller1.Axis1.position(), percent); 
  
  // Drivetrain left group.
  left_motor.setVelocity(Controller1.Axis3.position() + Controller1.Axis1.position(), percent);

  // Four Bar controls using R1/R2 buttons.
  Controller1.ButtonR1.pressed(move_fourbar_up);
  Controller1.ButtonR2.pressed(move_fourbar_down);
}
