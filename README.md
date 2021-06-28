# Devices for the Study of Scarred Landscapes
Resources for the Study of Scarred Landscapes workshop for NØ SCHOOL on June 28, 2021.

[Link to workshop presentation.](https://docs.google.com/presentation/d/1cTWqstJ5dMBbrx4FjO5AvwVebNW-ub3vGkTKbLXm1rg/edit?usp=sharing)

**Materials**

* Arduino & cord
* OLED Screen
* PM2.5 sensor
* Breadboard
* SD Card + Arduino SD card reader module
* Male Wires
* Laptop
* USB-A to USB-C converter (if needed for newer Macbooks)
* SD card reader (if your computer doesn't have one)

**Software**

* Arduino IDE [(Download Arduino here.)](https://www.arduino.cc/en/software)

## Getting started

* Download Arduino IDE [(Download Arduino here.)](https://www.arduino.cc/en/software)

* Plugin your Arduino and open the Arduino software

* Go to (Tools > Board) and make sure "Arduino Uno" is selected

* Check to see your Arduino is recognized by your computer.  You should see a new usbserial connection in this list, sometimes it will be labeled as an Arduino Uno.

![Image of selecting the correct serial](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/selectarduino.png)

If your Arduino isn't recognized immediately, you may have to [download the C3H40 driver for your computer.](https://sparks.gogo.co.nz/ch340.html)  Windows 10 users will definitely need to download and install the driver.

## Getting data : Setting up the Dust sensor

![Image of Dust sensor setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/ASSL_workshop_dustonly_bb.jpg)


1. Wiring for PM2.5 sensor: Sharp GP2Y1010AU0F. [More info about the sensor here.](https://www.mouser.com/catalog/additional/Sharp_Microelectronics_Application_Guide_for_Sharp_GP2Y1026AU0F_Dust_Sensor.pdf)

    * Wire 1 - Blue is connected to power through the resistor and ground via the capacitor.
    * Wire 2 - Green is wired directly to ground
    * Wire 3 - White is wired to a digital output - in this case - D10 on the 101
    * Wire 4 - Yellow is wired directly to ground. 
    * Wire 5 - Black is wired to an Analog Input, in this case A0 on the 101. A 10k ohm pulldown resistor is used so the value doesn't float.
    * Wire 6 - Red is wired to power directly.

If needed, solder the wires onto the extra pins that come with your Arduino and cut them separately.  

2. Download Sharp dust sensor library. (Sketch > Include Library > Manage Libraries > Search for "Sharp Dust" and install) [Check out the library documentation here.](https://github.com/luciansabo/GP2YDustSensor)
3. Open example code titled "Basic Reading" (File > Examples > Sharp GP2Y Sensor > BasicReading)
4. Make sure the LED pin and Analog output pin match your wiring setup, then compile and upload the code
5. Open the serial monitor to see the readings from your sensor.

You should now see your sensor output! 

If all is working well, we're going to make a new Arduino file which will eventually be our final code file that will include all of the elements covered in this workshop.  You can basically copy and paste this code into a new file, and we'll continue to add to it.


## Seeing up your screen : Connecting the OLED screen

![Image of Dust sensor and OLED setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/ASSL_workshop_dustoled_bb.jpg)


1. Wiring for OLED screen
2. Install the U8G2 library (Sketch > Include Library > Manage Libraries > Search for "U8G2" and install). Install also the U8Glib library (Sketch > Include Library > Manage Libraries > Search for "U8Glib" and install)

![Image of U8G2 library](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/OLEDArduinoLibrary.png)

3. Open the PrintTest example from the library. Copy and paste the following underneath the #include and run the code. 

```
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);	// Dev 0, Fast I2C / TWI
```
You should see "Hello World!" written on your screen.
Alternatively, you can also run the test code included on this Github to see the full extend of what kinds of animations and characters you can use on the OLED screens.

4. Now, we are going to have the data we got from our dust sensors write onto the OLED screens. 


## Making it portable : Saving your data to SD cards

![Image of Dust sensor, OLED, SD card setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/ASSL_workshop_complete_bb.png)

1. Setup the wiring for your SD card module.
2. Check the Arduino SD library. [You can find more documentation on the SD card library here.](https://www.arduino.cc/en/reference/SD)  Open code example in the Arduino SD library titled "CardInfo" (File > Examples > SD > CardInfo).  Run the example code and check the serial port to make sure your card is initializing properly.
3. Check the SD card in your computer to make sure the data file is there and has been written. 

## Issues

Any common issues or bug fixes will be noted here.

* Was previously missing instruction to add the U8Glib for the OLED screen.

* Pinout on the OLED screen is different from the diagram. the 5V and GND pins are switched, so make sure the VCC pin is connected to the power (+) and the GND pin is connected to the ground (-).
