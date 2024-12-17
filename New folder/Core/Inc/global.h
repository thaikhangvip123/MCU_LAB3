/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"

#define INIT	0
#define AUTO	1
#define MANUAL	2

#define G_R		11
#define Y_R		12
#define R_G		13
#define R_Y		14

#define MODE2 21
#define MODE3 22
#define MODE4 23

extern int status;
//extern int status2;

extern int count7SEG;
extern int ledDuration;

void check_timer_and_display(int mode, int duration);
#endif /* INC_GLOBAL_H_ */
