/*
 * timer.c
 *
 *  Created on: Oct 30, 2024
 *      Author: thaik
 */
#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}

