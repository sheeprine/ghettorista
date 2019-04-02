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
#include "display.h"

unsigned int doubleLen(double num) {
  if (num >= 100)
    return 3;
  if (num >= 10)
    return 2;
  return 1;
}

Display::Display(LiquidCrystal_I2C *lcd) : mp_lcd(lcd) {
  mp_lcd->clear();
}

void Display::setCelsius() {
  sign = 'C';
}

void Display::setFahrenheit() {
  sign = 'F';
}

void Display::updateDisplayState(GhettoBarista *state) {
  //  =================
  // |GH:300C  FLUSH   |
  // |WT:300C  P:030.1s|
  //  =================
  snprintf(m_displayBuffer[0], sizeof(m_displayBuffer[0]),
    "GH:%.0f%-*c  %-*s",
    state->m_groupTemp, 4-doubleLen(state->m_groupTemp), sign,
    15 - static_cast<int>(strlen(state->m_stateStr)), state->m_stateStr);
  snprintf(m_displayBuffer[1], sizeof(m_displayBuffer[1]),
    "WT:%.0f%-*c  P:%04.1fs",
    state->m_waterTemp, 4-doubleLen(state->m_waterTemp), sign,
    state->m_pumpRuntime/1000.0);
}

void Display::commitDisplay() {
  mp_lcd->setCursor(0, 0);
  mp_lcd->print(m_displayBuffer[0]);
  mp_lcd->setCursor(0, 1);
  mp_lcd->print(m_displayBuffer[1]);
}

void Display::printState() {
  printf("%s\n", m_displayBuffer[0]);
  printf("%s\n", m_displayBuffer[1]);
}
