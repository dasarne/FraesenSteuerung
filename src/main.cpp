#include <Steuerung.hpp>

// Logging-Tag für Easy-Logger
static const char *TAG = "MAIN";

Encoder theEncoder;

void setup()
{

#if LOG_LEVEL != LOG_LEVEL_NONE
  Serial.begin(115200); // Start Serial Monitor
#endif

  theEncoder.init();
}

// Dieses Beispiel addiert die Position, statt den Winkel anzugeben.
void loop()
{
  theEncoder.setCounts360(100);
  
  LOG_DEBUG(TAG, "Position: " << theEncoder.readPos());
  LOG_DEBUG(TAG, "Rotation: " << theEncoder.readUmdrehungen());
  delay(1000);
}

// -- END OF FILE --
