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
#pragma once

#include <cstdio>

#include <LiquidCrystal_I2C.h>

#include "barista.h"

unsigned int doubleLen(double num);

class Display {
   private:
  LiquidCrystal_I2C *mp_lcd = nullptr;
  char m_displayBuffer[2][17];
  char sign = 'C';

   public:
  Display(LiquidCrystal_I2C *lcd);
  void setCelsius();
  void setFahrenheit();
  void updateDisplayState(GhettoBarista *state);
  void commitDisplay();
  void printState();
};
