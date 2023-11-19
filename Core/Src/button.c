/*
 * input.c
 *
 *  Created on: Oct 24, 2023
 *      Author: ADMIN
 */

#include "main.h"
#include "button.h"
enum buttonState{
	BUTTON_RELEASE,
	BUTTON_PRESS,
	BUTTON_LONG_PRESS,
};
static int keyread0[NUM_BUTTON];
static int keyread1[NUM_BUTTON];
static int keyread2[NUM_BUTTON];
static int saveStateButton[NUM_BUTTON];
static int currentStateButton[NUM_BUTTON];
int countLongPress[NUM_BUTTON];
static int shortPressFlag[NUM_BUTTON];
static int longPressFlag[NUM_BUTTON];

void initButton(){
	for (int i = 0; i < NUM_BUTTON;i++) {
		keyread0[i] = BUTTON_IS_RELEASED;
		keyread1[i] = BUTTON_IS_RELEASED;
		keyread2[i] = BUTTON_IS_RELEASED;
		saveStateButton[i] = BUTTON_IS_RELEASED;
		currentStateButton[i] = BUTTON_IS_RELEASED;
		countLongPress[i] = 0;
		shortPressFlag[i] = 0;
		longPressFlag[i] = 0;
	}
}
int isButtonPress(int i){
	if (shortPressFlag[i] == 1){
		shortPressFlag[i] = 0;
		return 1;
	}
	return 0;
}
int isButtonPressLong(int i){
	if (longPressFlag[i] == 1){
		longPressFlag[i] = 0;
		return 1;
	}
    return 0;
}
void readPin(){
	for (int i = 0;i < NUM_BUTTON ;i++){
		keyread0[i] = keyread1[i];
		keyread1[i] = keyread2[i];

		switch (i)
		{
		case 0:
			keyread2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin);
			break;
		case 1:
			keyread2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin);
			break;
		case 2:
			keyread2[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin);
			break;
		default:
			break;
		}
		if ((keyread1[i] == keyread0[i]) && (keyread1[i] == keyread2[i])){
			currentStateButton[i] = keyread2[i];
			switch (saveStateButton[i])
			{
			case BUTTON_IS_RELEASED:
				if (currentStateButton[i] == BUTTON_IS_PRESSED ){
					saveStateButton[i] = BUTTON_IS_PRESSED;
				}
				break;

			case BUTTON_IS_PRESSED:
				countLongPress[i] ++;
				if (currentStateButton[i] == BUTTON_IS_RELEASED ){
					shortPressFlag[i] = 1;
					saveStateButton[i] = BUTTON_IS_RELEASED;
					countLongPress[i] = 0;
				}

				if (countLongPress[i] >= 200){
					// todo
					longPressFlag[i] = 1;
					saveStateButton[i] = BUTTON_IS_LONG_PRESSED;
					countLongPress[i] = 0;
				}
				break;

			case BUTTON_LONG_PRESS:
				countLongPress[i]++;
				if (countLongPress[i] >= 200 ){
					longPressFlag[i] = 1;
					countLongPress[i] = 0;
				}
				if( currentStateButton[i] == BUTTON_IS_RELEASED){
					countLongPress[i] = 0;
					saveStateButton[i] = BUTTON_IS_RELEASED;
				}
				break;

			default:
				break;
			}
		}
	}
}

