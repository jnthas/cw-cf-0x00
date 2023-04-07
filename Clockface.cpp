
#include "Clockface.h"

unsigned long lastMillis = 0;

Clockface::Clockface(Adafruit_GFX* display)
{
  _display = display;
  Locator::provide(display);
}

void Clockface::setup(CWDateTime *dateTime) {
  this->_dateTime = dateTime;
  
  // Clear screen
  Locator::getDisplay()->fillRect(0, 0, 64, 64, 0x0000);

  // Set font (Picopixel is present in commons package)
  Locator::getDisplay()->setFont(&Picopixel);

  // Write on display
  Locator::getDisplay()->setCursor(3, 10);
  Locator::getDisplay()->print("Clockwise");
  
  // Text color
  Locator::getDisplay()->setTextColor(0xC81F);
  Locator::getDisplay()->setCursor(25, 18);
  Locator::getDisplay()->print("Template");
  Locator::getDisplay()->setTextColor(0xFFFF);

  // Draw Bitmaps (also present in commons package)
  Locator::getDisplay()->drawRGBBitmap(3, 23, MAIL, 8, 8);
  Locator::getDisplay()->drawRGBBitmap(15, 22, WEATHER_CLOUDY_SUN, 8, 8);

  // Draw date (it's also used in loop())
  refreshDate();

  // Clear font (now using the default one)
  Locator::getDisplay()->setFont();
}


void Clockface::update() 
{  
  if (millis() - lastMillis >= 1000) {

    snprintf(time, sizeof(time), "%d:%02d:%02d", _dateTime->getHour(), _dateTime->getMinute(), _dateTime->getSecond());

    // Used for testing
    // snprintf(time, sizeof(time), "%d:%d:%d", 20, 45, 15);

    // Draw a black rect to clean the area
    Locator::getDisplay()->fillRect(7, 45, 50, 8, 0x0000);

    Locator::getDisplay()->setTextColor(random(LONG_MAX));
    Locator::getDisplay()->setCursor(8, 45);
    Locator::getDisplay()->print(time);

    if (_dateTime->getMinute() == 0 && _dateTime->getSecond() == 0) {
      refreshDate();
    }

    lastMillis = millis();
  }  

}

void Clockface::refreshDate() {
  Locator::getDisplay()->setFont(&Picopixel);

  snprintf(date, sizeof(date), "%02d/%02d", _dateTime->getMonth(), _dateTime->getDay());
  
  //snprintf(date, sizeof(date), "%d/%d", 12, 25);

  Locator::getDisplay()->fillRect(32, 24, 25, 7, 0xFFFF);
  Locator::getDisplay()->setTextColor(0x0000);
  Locator::getDisplay()->setCursor(35, 29);
  Locator::getDisplay()->print(date);
  
  Locator::getDisplay()->setFont();
}
