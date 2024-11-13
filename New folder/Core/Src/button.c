/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "button.h"

#define BUTTON_NUMS 10

int KeyReg0[BUTTON_NUMS];
int KeyReg1[BUTTON_NUMS];
int KeyReg2[BUTTON_NUMS];
int KeyReg3[BUTTON_NUMS];

int TimeOutForKeyPress[BUTTON_NUMS];
int button_pressed[BUTTON_NUMS];
int button_long_pressed[BUTTON_NUMS];
int button_flag[BUTTON_NUMS];

void initButton() {
	for (int i = 0; i < BUTTON_NUMS; i++) {
		KeyReg0[i] = NORMAL_STATE;
		KeyReg1[i] = NORMAL_STATE;
		KeyReg2[i] = NORMAL_STATE;
		KeyReg3[i] = NORMAL_STATE;
		TimeOutForKeyPress[i] = 500;
		button_pressed[i] = 0;
		button_long_pressed[i] = 0;
		button_flag[i] = 0;
	}
}
int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int i = 0; i < BUTTON_NUMS; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		// Add your key
	}
		KeyReg0[0] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
		KeyReg0[1] = HAL_GPIO_ReadPin(MODIFY_GPIO_Port, MODIFY_Pin);
		KeyReg0[2] = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
//		switch (i) {
//			case 0:
//				KeyReg0[i] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
//				break;
//			case 1:
//				KeyReg0[i] = HAL_GPIO_ReadPin(MOFIDY_GPIO_Port, MOFIDY_Pin);
//				break;
//			case 2:
//				KeyReg0[i] = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
//				break;
//		}
	for(int i = 0; i < BUTTON_NUMS; i++) {
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = 500;
					//subKeyProcess();
					button_flag[i] = 1;
				}
			} else{
				TimeOutForKeyPress[i] --;
				if (TimeOutForKeyPress[i] == 0){
					TimeOutForKeyPress[i] = 500;
					if (KeyReg3[i] == PRESSED_STATE){
						//subKeyProcess();
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}


