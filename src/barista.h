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

class Display;

class GhettoBarista {
   private:
  double m_groupTemp, m_groupOffset, m_waterTemp = 0.0;
  double m_waterTempSetpoint = 0.0;
  unsigned long m_pumpStart, m_pumpRuntime = 0;
  bool m_isCelsius = true;
  bool m_isCooling = false;
  bool m_shouldStartPump = false;
  char m_stateStr[8];
  void estimateWaterTemp();
  void updatePumpRuntime();

   public:
  friend class Display;
  void setCelsiusMode(bool enable);
  void setFahrenheitMode(bool enable);
  void setGroupHeadTemp(double offset);
  void setGroupHeadOffset(double offset);
  void setDesiredWaterTemp(double temp);
  void startPumpTimer(unsigned long start);
  void startPumpTimer();
  void stopPumpTimer();
  void resetPumpRuntime();
  void refresh();
  void startCoolingFlush();
  void stopCoolingFlush();
  bool getPumpWantedState();
};
