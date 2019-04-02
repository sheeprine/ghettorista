/*
Copyright 2019 Stephane Albert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "main.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
MAX6675 TC_GROUPHEAD;
GhettoBarista state;
Display *display;

#ifdef USE_CELSIUS
  double readGHTemp() { return TC_GROUPHEAD.readCelsius(); }
#else
  double readGHTemp() { return TC_GROUPHEAD.readFahrenheit(); }
#endif

volatile bool pumpActive = false;
volatile double pumpStart = 0;

void updatePumpState() {
  pumpActive = !pumpActive;
  pumpStart = millis();
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(PUMP_SENSE_PIN), updatePumpState, CHANGE);
  SPI.begin();
  TC_GROUPHEAD.begin(TC_GROUPHEAD_PIN);
  lcd.init();
  lcd.backlight();
  display = new Display(&lcd);
}

void loop() {
  if (pumpActive)
    state.startPumpTimer(pumpStart);
  else
    state.stopPumpTimer();
  state.setGroupHeadTemp(readGHTemp());
  state.refresh();
  display->updateDisplayState(&state);
  display->printState();
  delay(100);
}
