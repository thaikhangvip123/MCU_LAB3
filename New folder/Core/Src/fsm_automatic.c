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
	int index = 0;
	update7SEG(index++);
	if(index >= 4) {
		cdX--;
		cdY--;
		index = 0;
	}
}

void fsm_automatic_run() {
	switch(status) {
		case AUTO:
			if (1) {
				status = G_R;
				cdX = timerGreen - 1;
				cdY = timerRed - 1;
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
			}
			break;
		case G_R:
			trafficG_R();
			cdX--;
			cdY--;
			status = Y_R;
			if(cdX == 0) {
				status = Y_R;
				cdX = timerYellow - 1;
			}
			// UPDATE DISPLAY
			updateClockBuffer2(cdX);
			updateClockBuffer1(cdY);
			if (isButtonPressed(0)) {
				status = MANUAL;
				clearLed();
			}
			break;
		case Y_R:
			trafficY_R();
			cdX--;
			cdY--;
			if(cdX == 0 || cdY == 0) {
				status = R_G;
				cdX = timerRed - 1;
				cdY = timerGreen - 1;
			}
			// UPDATE DISPLAY
			updateClockBuffer2(cdX);
			updateClockBuffer1(cdY);
			if (isButtonPressed(0)) {
				status = MANUAL;
				clearLed();
			}
			break;
		case R_G:
			trafficR_G();
			cdX--;
			cdY--;
			if(cdY == 0) {
				status = R_Y;
				cdY = timerYellow - 1;
			}
			// UPDATE DISPLAY
			updateClockBuffer2(cdX);
			updateClockBuffer1(cdY);
			if (isButtonPressed(0)) {
				status = MANUAL;
				clearLed();
			}
			break;
		case R_Y:
			trafficR_Y();
			cdX--;
			cdY--;
			if(cdX == 0 || cdY == 0) {
				status = G_R;
				cdX = timerGreen - 1;
				cdY = timerRed - 1;
			}
			// UPDATE DISPLAY
			updateClockBuffer2(cdX);
			updateClockBuffer1(cdY);
			if (isButtonPressed(0)) {
				status = MANUAL;
				clearLed();
			}
			break;
		default:
			break;
	}
}

//void updateDisplay() {
//    if (status == G_R || status == Y_R || status == R_G || status == R_Y) {
//        updateClockBuffer2(cdX);
//        updateClockBuffer1(cdY);
//        if (cdX > 0) cdX--;
//        if (cdY > 0) cdY--;
//    }
//}

