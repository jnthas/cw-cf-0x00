# cw-cf-0x00

### This repo contains just a simple clockface template. Start from here if you want to create a **new one**.

To create a new Clockface, you just need a:
- a class implementing the [IClockface](https://github.com/jnthas/clockwise/blob/main/firmware/lib/cw-commons/IClockface.h) interface 
  - in the [main.cpp](https://github.com/jnthas/clockwise/blob/main/firmware/src/main.cpp#L53) I'm considering the constructor will receive an instance of `Adafruit_GFX` so that the display can be handled inside your clockface
- the interface has two methods setup() and loop() that is called the same way as Arduino does, setup() when it starts, loop() every time.
  - setup() receives an instace of `CWDateTime` where contains methods to get date/time updated 

Check out this repo's [source code](https://github.com/jnthas/cw-cf-0x00/blob/main/Clockface.cpp) to get more information.


## Useful links when making a clockface

### Fonts
- Adafuit GFX fonts https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts
- truetype2gfx - Converting fonts from TrueType to Adafruit GFX https://rop.nl/truetype2gfx/
- Amazing tool to customize every character of your font https://tchapi.github.io/Adafruit-GFX-Font-Customiser/
- Adafruit tool to covert fonts https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts#adding-new-fonts-2002831

### Colors RGB565 
- Those LED matrices and its libraries uses 2 bytes to define a RGB color, it's called RGB565 and it's slighty different than the "original" RGB. Here is a color picker for that format http://www.barth-dev.de/online/rgb565-color-picker/
- Convert RGB to RGB565 https://embeddednotepad.com/page/RGB565-color-picker

### Image converters (from png/jpg to C header file)

- Rinky Dink Electronics have a lot of useful online tools and libraries like the image converter http://www.rinkydinkelectronics.com/t_imageconverter565.php
- image2cpp is another online tool with many paramters to generate your sprites https://javl.github.io/image2cpp/   

