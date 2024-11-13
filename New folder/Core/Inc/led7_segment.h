/*
 * led7_segment.h
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"

extern int buffer7SEG[4];
extern int controllPin7SEG[4];
void clearLed();
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer1();
void updateClockBuffer2();

#endif /* INC_LED7_SEGMENT_H_ */
