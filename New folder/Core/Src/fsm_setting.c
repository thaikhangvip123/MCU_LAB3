/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "fsm_setting.h"

void fsm_setting_run() {
	switch(status) {
		case INIT:
			if (1) status = AUTO;
			break;
		case AUTO:
			if (isButtonPressed(0)) {
				status = MANUAL;
				setTimer3(10000); // Timer 3
				setTimer4(500); // Timer 4
				clearLed();
			}
			break;
		case MANUAL:
			if (isButtonPressed(2)) {
				status = AUTO;
				break;
			}
			if (timer3_flag == 1) {
				status = AUTO;
				break;
			}
			break;
		default:
			break;
	}
}
