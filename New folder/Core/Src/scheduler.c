/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2024
 *      Author: thaik
 */

#include "scheduler.h"
void SCH_Init() {
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		SCH_Delete_Task(index);
	}
	Error_code_G = 0;
}

void SCH_Update(void) {
	unsigned char index;

	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].pTask) {
			if (SCH_tasks_G[index].Delay == 0) {
				// The task is due to run
				SCH_tasks_G[index].RunMe += 1;
				if (SCH_tasks_G[index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
				}
			}
			else {
				SCH_tasks_G[index].Delay -= 1;
			}
		}
	}
}

unsigned char SCH_Add_Task(void (*pFunction) (), unsigned int DELAY, unsigned int PERIOD) {
	unsigned char index = 0;
	while ((SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS)) {
		index++;
	}
	if (index == SCH_MAX_TASKS) {
		// Task list is full
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	}
	// The array is not full
	SCH_tasks_G[index].pTask = pFunction;
	SCH_tasks_G[index].Delay = DELAY / TICK;
	SCH_tasks_G[index].Period = PERIOD / TICK;
	SCH_tasks_G[index].RunMe = 0;
	return index;
}

void SCH_Dispatch_Tasks(void) {
	uint8_t index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].RunMe > 0) {
			(*SCH_tasks_G[index].pTask) (); // Run the task
			SCH_tasks_G[index].RunMe -= 1; // Reset / reduce RunMe flag
			if (SCH_tasks_G[index].Period == 0) {
				SCH_Delete_Task(index);
			}
		}
	}
}

uint8_t SCH_Delete_Task(uint32_t TASK_INDEX) {
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		Return_code = RETURN_ERROR;
	}
	else {
		Return_code = RETURN_NORMAL;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	return Return_code;
}

