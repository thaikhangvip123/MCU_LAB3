/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#include "traffic_light.h"

int timerRed = 5;
int timerYellow = 2;
int timerGreen = 3;

void trafficG_R() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_RESET);
}
void trafficY_R() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_RESET);
}
void trafficR_G() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_SET);
}
void trafficR_Y() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_RESET);
}

void updateTime() {
	if(timerRed < 99) {
		timerRed++;
		timerGreen++;
	}
	if(timerRed < 99) {
		timerGreen++;
		timerRed++;
	}
	if(timerYellow < 99 && timerYellow < timerGreen) {
		timerYellow++;
		timerRed++;
	}
}
//void updateRedTime() {
//	if (redTime < 99) {
//		redTime++;
//		greenTime++;
//	}
//}
//void updateGreenTime() {
//	if (redTime < 99) {
//		greenTime++;
//		redTime++;
//	}
//}
//void updateYellowTime() {
//	if (redTime < 99 && yellowTime < greenTime) {
//		yellowTime++;
//		redTime++;
//	}
//}

void setTimeRED(int countRed) {
	timerRed = countRed;
}
void setTimeYELLOW(int countYellow) {
	timerYellow = countYellow;
}
void setTimeGREEN(int countGreen) {
	timerGreen = countGreen;
}
void RedBlinky() {
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
}
void YellowBlinky() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin,			RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	RESET);
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}
void GreenBlinky() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
}
void LedBlinky() {
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}
void clearLed() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 		GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, 	GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 	GPIO_PIN_RESET);
}
