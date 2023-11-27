/*
 * timer.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"
void timerInit(int scale, int period);
void setTimeOutTimer(uint16_t duration);
void timer_run();
uint8_t getTimeOutFlag();
#endif /* INC_TIMER_H_ */
