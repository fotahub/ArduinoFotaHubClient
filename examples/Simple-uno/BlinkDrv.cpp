/*
 *  Copyright (C) 2022 FotaHub Inc. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of the FotaHub(R) Device SDK program (https://fotahub.com)
 */
#define USE_TIMER_1     true
#define USE_TIMER_2     false
#define USE_TIMER_3     false
#define USE_TIMER_4     false
#define USE_TIMER_5     false
 
#include "BlinkDrv.h"
#include <Arduino.h>
#include <TimerInterrupt_Generic.h>
  
void blinkCallback()
{
  digitalWrite(BLINK_PIN, !digitalRead(BLINK_PIN));
}

void BlinkDrvClass::init(uint16_t blinkPeriod)
{
  pinMode(BLINK_PIN, OUTPUT);
  ITimer1.init();
  ITimer1.attachInterruptInterval(blinkPeriod, blinkCallback);
}

BlinkDrvClass BlinkDrv;
