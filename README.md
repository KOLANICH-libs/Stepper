Stepper Library for Raspberry Pi
================================

A simple library for controlling stepper motors through the GPIO pins on a raspberry pi.
Adapted from the arduino library using bcm2835.

For information about the original arduino library, visit
http://www.arduino.cc/en/Reference/Stepper

For information about bcm2835, visit
http://www.airspayce.com/mikem/bcm2835

Move.cpp is a simple example program that bounces the stepper motor. Edit the file to reflect the steps per revolution and speed.

Building
--------

Requires bcm2835. To install first download the latest version of bcm2835.

E.g. `curl -O http://www.airspayce.com/mikem/bcm2835/bcm2835-1.xx.tar.gz`

Then  
```
tar zxf bcm2835-1.xx.tar.gz
cd bcm2835-1.xx
./configure
make
sudo make check
sudo make install
```

To build, run `g++ Move.cpp Stepper.cpp -std=c++11 -lbcm2835`

License
-------

Orginal library
Copyright (c) Arduino LLC. All right reserved;
Copyright (c) Sebastian Gassner. All right reserved;
Copyright (c) Noah Shibley. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
