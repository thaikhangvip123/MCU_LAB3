/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "global.h"

int status = INIT;



int count7SEG = 0;
int ledDuration = 250;

void check_timer_and_display(int mode, int duration){
	count7SEG++;
	if (count7SEG >= 4)
		count7SEG = 0;
	if (count7SEG % 2 == 0){
		if (mode == 2)
			RedBlinky();
		else if (mode == 3)
			GreenBlinky();
		else if (mode == 4)
			YellowBlinky();
		else ;
	}

	updateClockBufferX(mode);
	updateClockBufferY(duration);
}
