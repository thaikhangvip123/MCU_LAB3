/*
 * fsm_MANUALual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "fsm_manual.h"

int mode = 1;
int countRed = 0;
int countYellow = 0;
int countGreen = 0;

void fsm_manual_run() {
	switch(status) {
		case MANUAL:
			updateClockBufferX(mode);
			updateClockBufferY(0);
//			if (timer4_flag == 1) {
//				setTimer4(500); // Timer 4
//				LedBlinky(); // Blink 2Hz
//			}
			LedBlinky();
			if (isButtonPressed(0)) {
				status = MODE2;
				mode = 2;
				// Save original values
				countRed = timerRed;
				countYellow = timerYellow;
				countGreen = timerGreen;
				updateClockBufferX(mode);
				updateClockBufferY(timerRed);
				clearLed();
			}
			break;
		case MODE2:
//			if (timer4_flag == 1) {
//				setTimer4(500); // Timer 4
//				RedBlinky(); // Blink 2Hz
//			}
			RedBlinky();
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MODE3;
				mode = 3;
				// Adjust Time to the original, not save the updated value
				setTimeRED(countRed);
				setTimeYELLOW(countYellow);
				setTimeGREEN(countGreen);
				updateClockBufferX(mode);
				updateClockBufferY(timerYellow);
				clearLed();
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updatetimerRed();
				updateClockBufferY(timerRed);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MANUAL;
//				setTimer3(10000); // Timer 3
				clearLed();
				mode = 0;
				break;
			}
			break;
		case MODE3:
//			if (timer4_flag == 1) {
//				setTimer4(500); // Timer 4
//				YellowBlinky(); // Blink 2Hz
//			}
			YellowBlinky();
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MODE4;
				mode = 4;
				// Adjust Time to the original, not save the updated value
				setTimeRED(countRed);
				setTimeYELLOW(countYellow);
				setTimeGREEN(countGreen);
				updateClockBufferX(mode);
				updateClockBufferY(timerGreen);
				clearLed();
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updatetimerYellow();
				updateClockBufferY(timerYellow);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MANUAL;
//				setTimer3(10000); // Timer 3
				clearLed();
				mode = 0;
				break;
			}
			break;
		case MODE4:
//			if (timer4_flag == 1) {
//				setTimer4(500); // Timer 4
//				GreenBlinky(); // Blink 2Hz
//			}
			GreenBlinky();
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MANUAL;
//				setTimer3(10000); // Timer 3
				clearLed();
				mode = 0;
				// Adjust Time to the original, not save the updated value
				setTimeRED(countRed);
				setTimeYELLOW(countYellow);
				setTimeGREEN(countGreen);
				updateClockBufferX(mode);
				updateClockBufferY(0);
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updatetimerGreen();
				updateClockBufferY(timerGreen);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MANUAL;
//				setTimer3(10000); // Timer 3
				clearLed();
				mode = 0;
				break;
			}
			break;
		default:
			break;
	}
}
