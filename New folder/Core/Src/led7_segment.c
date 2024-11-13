/*
 * led7_segment.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#include "led7_segment.h"
#include "software_timer.h"

int buffer7SEG[4] = {1, 2, 3, 4};
int controllPin7SEG[4] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};
void clear() {
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, SET);
}

void display7SEG(int num) {
	char segNum[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	for (int i = 0; i < 7; ++i) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (segNum[num] >> i) & 1);
	}
}
void enable(int pin) {
	HAL_GPIO_WritePin(GPIOA, controllPin7SEG[pin], RESET);
}
void EnableLed() {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
}

void update7SEG(int index) {
	clear();
	EnableLed();
	switch (index) {
		case 0: {
			display7SEG(buffer7SEG[0]);
			enable(0);
			break;
		}
		case 1: {
			display7SEG(buffer7SEG[1]);
			enable(1);
			break;
		}
		case 2: {
			display7SEG(buffer7SEG[2]);
			enable(2);
			break;
		}
		case 3: {
			display7SEG(buffer7SEG[3]);
			enable(3);
			break;
		}
		default:
			break;
	}
}
void updateClockBuffer1(int value) {
	buffer7SEG[0] = value / 10;
	buffer7SEG[1] = value % 10;
}
void updateClockBuffer2(int value) {
	buffer7SEG[2] = value / 10;
	buffer7SEG[3] = value % 10;
}
