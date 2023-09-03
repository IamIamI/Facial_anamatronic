##Running a facial animatronic rig using an ESP32

<img src="https://github.com/IamIamI/Facial_anamatronic/blob/main/images/IMG_20230830_120850.jpg?raw=true" width="400" />

This rig has been created by Will Cogley, you can find the build information on his instructables
https://www.instructables.com/Simplified-3D-Printed-Animatronic-Dual-Eye-Mechani/

I printed the parts with an Elegoo 3 Mars 4K using the Elegoo ABS-like V2 resin (great resin for this stuff btw).

The rig requires 6 servo's and i used generic cheap 'Micro Servo 9g, SG90' servo's that you can find on aliexpress for 1-2 euro per piece.

The rig has been connected to an ESP32 because i'm more familiar with that, but also it's a lot smaller than a full Arduino Uno which is used in the original instructables.

The particular ESP32 module that was used can be seen here, keep in mind that the pins might be on different locations in different ESP32 modules.

<img src="https://github.com/IamIamI/Facial_anamatronic/blob/main/images/esp32-development-board-wifi-and-bluetooth-with-ch340-usb-type-c-citytech-bd-bangladesh-1-1000x1000h.jpg?raw=true" width="400" />

# Version 0.1

The wiring diagram for the rig to the ESP32 can be found below:

##Wiring
| ESP32 | Joystick Module | Servo |
| ---|---|--- |
| Pin 15 | - | Servo Upper Left Eyelid|
| Pin 16 | - | Servo Eye Up-Down|
| Pin 17 | - | Servo Eye Left-Right|
| Pin 18 | - | Servo Lower Left Eyelid|
| Pin 19 | - | Servo Lower Right Eyelid|
| Pin 21 | - | Servo Upper Right Eyelid|
| 3V3 | VCC | VCC |
| GND | GND | GND |
| - | VRX | - |
| - | VRY | - |
| - | SW | - |

<img src="https://github.com/IamIamI/Facial_anamatronic/blob/main/images/FaceAnimatronic_V3_bb.jpg?raw=true" width="400" />

At the moment the joystick is not yet working, and the script just cycles through all the movements. Eyelids are not synched properly and the bottom lids have a tendency to get stuck a bit (too little torque i think) 

[<img src="https://github.com/IamIamI/Facial_anamatronic/blob/main/images/Screenshot%202023-09-03%20180255.png" width="400"/>](https://youtube.com/shorts/eza7w3FqX48)
