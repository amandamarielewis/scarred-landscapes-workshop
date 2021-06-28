//Libraries included in the sketch
#include "U8glib.h"
#include <U8glib.h>
#include <Wire.h>
#include <GP2YDustSensor.h>
#include <SPI.h>
#include <SD.h>

#define time_delay 2000

//Initialize our specific type of OLED screen
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);  // Dev 0, Fast I2C / TWI

const uint8_t SHARP_LED_PIN = 10;   // Sharp Dust/particle sensor Led Pin
const uint8_t SHARP_VO_PIN = A0;    // Sharp Dust/particle analog out pin used for reading 

//Initialize our PM2.5 dust sensor
GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

const int chipSelect = 4;

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
    dustSensor.begin();


  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    //don't do anything more:
    //while (1);
  }
  Serial.println("card initialized.");

  //dustSensor.setBaseline(0.4); // set no dust voltage according to your own experiments
  //dustSensor.setCalibrationFactor(1.1); // calibrate against precision instrument
}

void loop(void) {
  // put your main code here, to run repeatedly:

  // Serial Print dust sensor data
  // Serial.print("Dust density: ");
  // Serial.print(dustSensor.getDustDensity());
  // Serial.print(" ug/m3; Running average: ");
  // Serial.print(dustSensor.getRunningAverage());
  // Serial.println(" ug/m3");

  // make a string for assembling the data to log:
  String dataString = "";
  
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println(dustSensor.getDustDensity());
    dataFile.close();
    Serial.print("writing to file: ");
    Serial.print(dustSensor.getDustDensity());
    Serial.println(" ug/m3");
  } else {
    Serial.println("error opening file");
  }

//OLED screen print dust sensor data picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  //delay before we run again
  delay(1000);
}

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.setPrintPos(0, 20); 
  u8g.print("Dust : ");
  u8g.print(dustSensor.getDustDensity());
  u8g.print(" ug/m3");
}
