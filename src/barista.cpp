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
#include "barista.h"

void GhettoBarista::setCelsiusMode(bool enable) {
  m_isCelsius = enable;
}

void GhettoBarista::setFahrenheitMode(bool enable) {
  m_isCelsius = !enable;
}

void GhettoBarista::setGroupHeadTemp(double temp) {
  m_groupTemp = temp;
}

void GhettoBarista::setGroupHeadOffset(double offset) {
  m_groupOffset = offset;
}

void GhettoBarista::setDesiredWaterTemp(double temp) {
  m_waterTempSetpoint = temp;
}

void GhettoBarista::startPumpTimer(unsigned long start) {
  if (m_pumpStart)
    return;
  m_pumpStart = start;
}

void GhettoBarista::startPumpTimer() {
  startPumpTimer(millis());
}

void GhettoBarista::stopPumpTimer() {
  updatePumpRuntime();
  m_pumpStart = 0;
}

void GhettoBarista::updatePumpRuntime() {
  if (m_pumpStart)
    m_pumpRuntime = millis() - m_pumpStart;
}

void GhettoBarista::resetPumpRuntime() {
  m_pumpRuntime = 0;
}

void GhettoBarista::estimateWaterTemp() {
  m_waterTemp = m_groupTemp + m_groupOffset;
}

void GhettoBarista::refresh() {
  estimateWaterTemp();
  if (m_isCooling && m_waterTemp <= m_waterTempSetpoint)
    stopCoolingFlush();
}

void GhettoBarista::startCoolingFlush() {
  if (m_waterTemp <= m_waterTempSetpoint)
    return;
  m_shouldStartPump = true;
  m_isCooling = true;
}

void GhettoBarista::stopCoolingFlush() {
  m_shouldStartPump = false;
  m_isCooling = false;
}

bool GhettoBarista::getPumpWantedState() {
  return m_shouldStartPump;
}
