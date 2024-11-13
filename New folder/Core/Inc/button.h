/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define BUTTON_NUMS 10

extern int KeyReg0[BUTTON_NUMS];
extern int KeyReg1[BUTTON_NUMS];
extern int KeyReg2[BUTTON_NUMS];
extern int KeyReg3[BUTTON_NUMS];

extern int TimeOutForKeyPress[BUTTON_NUMS];
extern int button_pressed[BUTTON_NUMS];
extern int button_long_pressed[BUTTON_NUMS];
extern int button_flag[BUTTON_NUMS];

extern int isButtonPressed(int index);
extern int isButtonLongPressed(int index);
void initButton();
void getKeyInput();
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */

