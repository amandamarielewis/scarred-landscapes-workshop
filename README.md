# Devices for the Study of Scarred Landscapes
Resources for the Study of Scarred Landscapes workshop for NØ SCHOOL 2021.

[Link to workshop presentation.](https://docs.google.com/presentation/d/1cTWqstJ5dMBbrx4FjO5AvwVebNW-ub3vGkTKbLXm1rg/edit?usp=sharing)

**Materials**

* Arduino & cord
* OLED Screen
* PM2.5 sensor
* Breadboard
* SD Card + Arduino card reader module
* Male Wires
* Laptop
* USB-A to USB-C converter (if needed for newer Macbooks)

**Software**

* Arduino IDE [(Download Arduino here.)](https://www.arduino.cc/en/software)

## Getting started

* Download Arduino IDE [(Download Arduino here.)](https://www.arduino.cc/en/software)

* Plugin your Arduino and open the Arduino software

* Go to (Tools > Board) and make sure "Arduino Uno" is selected


## Getting data : Setting up the Dust sensor

1. Wiring for PM2.5 sensor: Sharp GP2Y1010AU0F

    Wire 1 - Blue is connected to power through the resistor and ground via the capacitor.

    Wire 2 - Green is wired directly to ground

    Wire 3 - White is wired to a digital output - in this case - D12 on the 101

    Wire 4 - Yellow is wired directly to ground. 

    Wire 5 - Black is wired to an Analog Input, in this case A0 on the 101. A 10k ohm pulldown resistor is used so the value doesn't float.

    Wire 6 - Red is wired to power directly.

2. Download Sharp dust sensor library
3. Open example code titled "Basic Reading" (File > Examples > Sharp GP2Y Sensor > BasicReading)
4. Make sure the LED pin and Analog output pin match your wiring setup, then compile and upload the code
5. Open the serial monitor to see the readings from your sensor

You should now see your sensor output! 

If all is working well, we're going to make a new Arduino file which will eventually be our final code file that will include all of the elements covered in this workshop.


## Seeing up your screen : Connecting the OLED screen

1. Wiring for OLED screen
2. OLED library

```
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);	// Dev 0, Fast I2C / TWI
```

3. Arduino code

## Making it portable : Saving your data to SD cards

1. Wiring for SD card module
2. Open code example in the Arduino SD library titled "Datalogger" (File > Examples > SD > Datalogger)
