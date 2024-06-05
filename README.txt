
1. Download arduino IDE

2. Add teensy url in preferences

In the Arduino software, click File > Preferences. In "Additional boards manager URLs", copy this link:
https://www.pjrc.com/teensy/package_teensy_index.json

3. Install Teensyduino in Boards Manager

In the main Arduino window, open Boards Manager by clicking the left-side board icon, search for "teensy", and click "Install".


4. connect to teensy board in COM

5. Open sketch openSmiths.ino

6. Upload to teensy


teensy Pin 9, 5V and GND pins to servo
teensy pin 22 and GND to input

Currently tested using benchtop freq generator, for real use *** THIS INPUT WILL REQUIRE VOLTAGE DIVIDER AND PROTECTION DIODES ***

Tested working to 6000 RPM - > There will likely be some limit with the servos range of motion in this version





// stepper not servo or do we alter the servo?
