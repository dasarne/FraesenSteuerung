//
//    FILE: AS5600_demo_radians.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo


#include "AS5600.h"
#include "Wire.h"

AS5600 as5600(&Wire);   //  use default Wire


void setup()
{
  Serial.begin(115200);

  Wire.begin(33,32);
  
  as5600.begin(4);  //  set direction pin.
  as5600.setDirection(AS5600_CLOCK_WISE);  // default, just be explicit.
  as5600.setOutputMode(2);
}

// Dieses Beispiel addiert die Position, statt den Winkel anzugeben.
void loop()
{
  static uint32_t lastTime = 0;

  //  set initial position
  as5600.getCumulativePosition();

  //  update every 100 ms
  //  should be enough up to ~200 RPM
  if (millis() - lastTime >= 100)
  {
    lastTime = millis();
    Serial.print(as5600.getCumulativePosition());
    Serial.print("\t");
    Serial.println(as5600.getRevolutions());
  }

}


// -- END OF FILE --
