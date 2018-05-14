

#define CUSTOM_SETTINGS
#define INCLUDE_ORIENTATION_SENSOR_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>



#include "MeccaBrain.h"
MeccaBrain servo(5);
  int x = 90;
  int y = 90;
  int z = 90;



void setup() {

  

  delay(15000);
  OneSheeld.begin();
  Terminal.println("6");

  // OneSheeld.waitForAppConnection();
  Terminal.println("7");




}

void loop() {



    servo.communicate();
    x = int(OrientationSensor.getX());
    y = int(OrientationSensor.getY());
    z = int(OrientationSensor.getZ());
    if (x > 270)
    {
      x = 0;
    }
    if (x > 180)
    {
      x = 180;
    }
    x = 180 - x;
    y = 180 + y;
    z = 180 - (z + 90);

    servo.setServoPosition(0, map(x, 0, 180, 0x18, 0xE8));
    servo.setServoPosition(1, map(y, 0, 180, 0x18, 0xE8));
    servo.setServoPosition(2, map(z, 0, 180, 0x18, 0xE8));

    delay(15);
    



}









