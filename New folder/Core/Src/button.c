/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "button.h"

#define buttonNums 3

int KeyReg0[buttonNums] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[buttonNums] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[buttonNums] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[buttonNums] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[buttonNums] =  {50, 50, 50};
int button_pressed[buttonNums] = {0, 0, 0};
int button_long_pressed[buttonNums] = {0, 0, 0};
int button_flag[buttonNums] = {0, 0, 0};

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
	for(int i = 0; i < buttonNums; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		// Add your key
		switch (i) {
			case 0:
				KeyReg0[i] = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
				break;
			case 1:
				KeyReg0[i] = HAL_GPIO_ReadPin(MOFIDY_GPIO_Port, MOFIDY_Pin);
				break;
			case 2:
				KeyReg0[i] = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
				break;
		}
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


