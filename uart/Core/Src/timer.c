/*
 * timer.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Admin
 */
#include "timer.h"
static int timeOut_counter = 0;
static int timeOut_flag = 0;
static float TIMER_CYCLE = 10;

void timerInit(int scale, int period){
	TIMER_CYCLE = ((scale+1)*(period+1))/8000;
};

void setTimeOutTimer(uint16_t duration){
	timeOut_counter = duration/TIMER_CYCLE;
};
void timer_run(){
	if(timeOut_counter > 0){
	timeOut_counter--;
		if(timeOut_counter == 0) timeOut_flag = 1;
	};
};
uint8_t getTimeOutFlag(){
	if(timeOut_flag == 1){
		timeOut_flag = 0;
		return 1;
	}
	return 0;
};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	timer_run();
}
