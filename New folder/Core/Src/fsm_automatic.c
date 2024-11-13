/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "fsm_automatic.h"

int cdX = 0;
int cdY = 0;

void fsm_automatic_run() {
	switch(status) {
		case AUTO: {
			if (1) {
				status = G_R;
				cdX = timerGreen - 1;
				cdY = timerRed - 1;
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
				setTimer1(timerGreen * 1000); // Timer 1
				setTimer2(1000);
			}
			break;
		}
		case G_R: {
			trafficG_R();
			if (timer1_flag == 1) {
				status = Y_R;
				setTimer1(timerYellow * 1000); // Timer 1
				cdX = timerYellow - 1;
			}
			if (timer2_flag == 1) {
				// UPDATE DISPLAY
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
				cdX--;
				cdY--;
				setTimer2(1000); // Timer 2
			}
			if (isButtonPressed(0)) {
			// Check button1_flag == 1, then reset button1_flag = 0
				status = MANUAL;
				setTimer3(10000); // Timer 3
				clearLed();
			}
			break;
		}
		case Y_R: {
			trafficY_R();
			if (timer1_flag == 1) {
				status = R_G;
				setTimer1(timerGreen * 1000); // Timer 1
				cdX = timerRed - 1;
				cdY = timerGreen - 1;
			}
			if (timer2_flag == 1) {
				// UPDATE DISPLAY
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
				cdX--;
				cdY--;
				setTimer2(1000); // Timer 2
			}
			if (isButtonPressed(0)) {
			// Check button1_flag == 1, then reset button1_flag = 0
				status = MANUAL;
				setTimer3(10000); // Timer 3
				clearLed();
			}
			break;
		}
		case R_G: {
			trafficR_G();
			if (timer1_flag == 1) {
				status = R_Y;
				setTimer1(timerYellow * 1000); // Timer 1
				cdY = timerYellow - 1;
			}
			if (timer2_flag == 1) {
				// UPDATE DISPLAY
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
				cdX--;
				cdY--;
				setTimer2(1000); // Timer 2
			}
			if (isButtonPressed(0)) {
			// Check button1_flag == 1, then reset button1_flag = 0
				status = MANUAL;
				setTimer3(10000); // Timer 3
				clearLed();
			}
			break;
		}
		case R_Y: {
			trafficR_Y();
			if (timer1_flag == 1) {
				status = G_R;
				setTimer1(timerGreen * 1000); // Timer 1
				cdX = timerGreen - 1;
				cdY = timerRed - 1;
			}
			if (timer2_flag == 1) {
				// UPDATE DISPLAY
				updateClockBuffer2(cdX);
				updateClockBuffer1(cdY);
				cdX--;
				cdY--;
				setTimer2(1000); // Timer 2
			}
			if (isButtonPressed(0)) {
			// Check button1_flag == 1, then reset button1_flag = 0
				status = MANUAL;
				setTimer3(10000); // Timer 3
				clearLed();
			}
			break;
		}
		default: {
			break;
		}
	}
}
