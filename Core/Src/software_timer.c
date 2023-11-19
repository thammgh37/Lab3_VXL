/*
 * software_timer.c
 *
 *  Created on: Jul 11, 2023
 *      Author: ADMIN
 */

#include "software_timer.h"
int timer1_flag = 0;
int timer2_flag = 0;
int timer3_flag = 0;
int timer4_flag = 0;
int timer1_count = 0;
int timer2_count = 0;
int timer3_count = 0;
int timer4_count = 0;
const int TIMER_CYCLE = 10;
void setTimer1(int duration){
	timer1_count = duration/TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_count = duration/TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_count = duration/TIMER_CYCLE;
	timer3_flag = 0;
}
void setTimer4(int duration){
	timer4_count = duration/TIMER_CYCLE	;
	timer4_flag = 0;
}

void timerRun(){
	if (timer1_count >= 0){
		timer1_count--;
		if (timer1_count <=0){
			timer1_flag = 1;
		}
	}
	if (timer2_count >= 0){
		timer2_count--;
		if (timer2_count <=0){
			timer2_flag = 1;
		}
	}
	if (timer3_count >= 0){
		timer3_count--;
		if (timer3_count <=0){
			timer3_flag = 1;
		}
	}
	if (timer4_count >= 0){
		timer4_count--;
		if (timer4_count <=0){
			timer4_flag = 1;
		}
	}
}
