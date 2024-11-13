/*
 * led7_segment.h
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"

int buffer[4] = {1, 2, 3, 4};
int controllPin[4] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};
void clearLed();
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer1();
void updateClockBuffer2();

#endif /* INC_LED7_SEGMENT_H_ */
