#include <GP2YDustSensor.h>

const uint8_t SHARP_LED_PIN = 10;   // Sharp Dust/particle sensor Led Pin (White wire)
const uint8_t SHARP_VO_PIN = A0;    // Sharp Dust/particle analog out pin used for reading (Black wire)

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

void setup() {
  Serial.begin(9600);
  //dustSensor.setBaseline(0.4); // set no dust voltage according to your own experiments
  //dustSensor.setCalibrationFactor(1.1); // calibrate against precision instrument
  dustSensor.begin();
}

void loop() {

//Open serial monitor to read dust sensor recordings
  Serial.print("Dust density: ");
  Serial.print(dustSensor.getDustDensity());
  Serial.print(" ug/m3; Running average: ");
  Serial.print(dustSensor.getRunningAverage());
  Serial.println(" ug/m3");
  delay(1000);
}
