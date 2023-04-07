#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
#include <WiFi.h>

// Commons
#include "IClockface.h"
#include "Icons.h"
#include "picopixel.h"



class Clockface: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    char time[9] = {0};
    char date[6] = {0};

  public:
    Clockface(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
    void refreshDate();
};
