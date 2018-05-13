

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

  /* String a = "0";

      while (a!="1")
      {

      a = Serial.read();
    Serial.print(5);
    Serial.print(a);
    delay(500);
      }*/

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
    servo2.communicate();
servo2.setServoPosition(0, map(0, 0, 180, 0x18, 0xE8));
servo2.setServoPosition(1, map(180, 0, 180, 0x18, 0xE8));
delay(15);
servo3.communicate();
servo3.setServoPosition(0, map(180, 0, 180, 0x18, 0xE8));
servo3.setServoPosition(1, map(0, 0, 180, 0x18, 0xE8));
delay(15);
servo4.communicate();
servo4.setServoPosition(0, map(180, 0, 180, 0x18, 0xE8));
servo4.setServoPosition(1, map(0, 0, 180, 0x18, 0xE8));
delay(15);

servo.communicate();
servo.setServoPosition(0, map(90, 0, 180, 0x18, 0xE8));
servo.setServoPosition(1, map(90, 0, 180, 0x18, 0xE8));
delay(15);
servo2.communicate();
servo2.setServoPosition(0, map(90, 0, 180, 0x18, 0xE8));
servo2.setServoPosition(1, map(90, 0, 180, 0x18, 0xE8));
delay(15);
servo3.communicate();
servo3.setServoPosition(0, map(90, 0, 180, 0x18, 0xE8));
servo3.setServoPosition(1, map(90, 0, 180, 0x18, 0xE8));
delay(15);
servo4.communicate();
servo4.setServoPosition(0, map(90, 0, 180, 0x18, 0xE8));
servo4.setServoPosition(1, map(90, 0, 180, 0x18, 0xE8));
delay(15);


  







}









