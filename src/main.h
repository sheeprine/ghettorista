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

#include <Arduino.h>
#include <max6675.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "barista.h"
#include "display.h"

#define TC_GROUPHEAD_PIN D0
#define PUMP_SENSE_PIN D1
#define PUMP_START_PIN D2
#define USE_CELSIUS 1
