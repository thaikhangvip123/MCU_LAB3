/*
 * traffic_light.h
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

extern int timerRed;
extern int timerYellow;
extern int timerGreen;

void trafficG_R();
void trafficY_R();
void trafficR_G();
void trafficR_Y();

void updateTime();
void setTimeRED();
void setTimeYELLOW();
void setTimeGREEN();

void RedBlinky();
void YellowBlinky();
void GreenBlinky();
void LedBlinky();

void clearLed();

#endif /* INC_TRAFFIC_LIGHT_H_ */
