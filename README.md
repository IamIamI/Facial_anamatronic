#Running a facial animatronic rig using an ESP32

This rig has been created by Will Cogley, you can find the build information on his instructables
https://www.instructables.com/Simplified-3D-Printed-Animatronic-Dual-Eye-Mechani/

I printed the parts with an Elegoo 3 Mars 4K using the Elegoo ABS-like V2 resin (great resin for this stuff btw).

The rig requires 6 servo's and i used generic cheap 'Micro Servo 9g, SG90' servo's that you can find on aliexpress for 1-2 euro per piece.

The rig has been connected to an ESP32 because i'm more familiar with that, but also it's a lot smaller than a full Arduino Uno which is used in the original instructables.

The wiring diagram for the rig to the ESP32 can be found below:

##Wiring
| ESP32 | MPU-6050 Gyro | GC9A01 TFT |
| ---|---|--- |
| Pin 4 | - | RST |
| Pin 19 | - | CS |
| Pin 16 | - | DC |
| Pin 23 | - | SDA |
| Pin 18 | - | SCL |
| 3V3 | VCC | VCC |
| GND | GND | GND |
| Pin 21 | SDA | - |
| Pin 22 | SCL | - |
| - | XDA | - |
| - | XCL | - |
| - | ADO | - |
| - | INT | - |

<img src="https://github.com/IamIamI/Gyro_HAT/blob/main/images/IMG_20230715_161058.jpg?raw=true" width="400" />

[<img src="https://github.com/IamIamI/Gyro_HAT/blob/main/images/video3-3.jpg" width="400"/>](https://youtube.com/shorts/zsiIzT4D0e4)
