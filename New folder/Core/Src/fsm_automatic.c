/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "fsm_automatic.h"

int cdX = 0;
int cdY = 0;

void countdown() {
	count7SEG++;
	if(count7SEG >= 4) {
		cdX--;
		cdY--;
		count7SEG = 0;
	}
}
void updateClock() {
        updateClockBufferX(cdX);
        updateClockBufferY(cdY);
}

void fsm_automatic_run() {
	switch(status) {
		case AUTO:
			status = G_R;
			cdX = timerGreen - 1;
			cdY = timerRed - 1;
			SCH_Add_Task(trafficG_R, 10, 3000);
			SCH_Add_Task(updateClock, 10, 1000);

			break;
		case G_R:
			cdX--;
			cdY--;
			if(cdX == 0) {
				status = Y_R;
				cdX = timerYellow - 1;
				SCH_Add_Task(trafficY_R, 10, 2000);
			}

			if (isButtonPressed(0)) {
				status = MANUAL;
				SCH_Delete_Task(updateClock);
				clearLed();
			}
			break;
		case Y_R:
			cdX--;
			cdY--;
			if(cdX == 0 || cdY == 0) {
				status = R_G;
				cdX = timerRed - 1;
				cdY = timerGreen - 1;
				SCH_Add_Task(trafficR_G, 0, 5000);
			}
			if (isButtonPressed(0)) {
				status = MANUAL;
				SCH_Delete_Task(updateClock);
				clearLed();
			}
			break;
		case R_G:
			cdX--;
			cdY--;
			if(cdY == 0) {
				status = R_Y;
				cdY = timerYellow - 1;
				SCH_Add_Task(trafficR_Y, 0, 2000);
			}
			// UPDATE DISPLAY
			if (isButtonPressed(0)) {
				status = MANUAL;
				SCH_Delete_Task(updateClock);
				clearLed();
			}
			break;
		case R_Y:
			cdX--;
			cdY--;
			if(cdX == 0 || cdY == 0) {
				status = G_R;
				cdX = timerGreen - 1;
				cdY = timerRed - 1;
				SCH_Add_Task(trafficG_R, 0, 3000);
			}
			// UPDATE DISPLAY
			if (isButtonPressed(0)) {
				status = MANUAL;
				SCH_Delete_Task(updateClock);
				clearLed();
			}
			break;
		default:
			break;
	}
}


