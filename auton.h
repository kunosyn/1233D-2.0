#include "vex.h"
using namespace vex;

// Main Autonomous Function
void auton()
{
  four_bar_group.setVelocity(-100, percent);
  wait(1, seconds);
  four_bar_group.setVelocity(0, percent);
}
