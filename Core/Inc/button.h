#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NUM_BUTTON	3
#define BUTTON_IS_PRESSED		0
#define BUTTON_IS_RELEASED		1
#define BUTTON_IS_LONG_PRESSED	2
#define DURATION_FOR_AUTO_INCREASING	100

void initButton();
int isButtonPress(int i);
int isButtonPressLong(int i);
void readPin();
#endif /* INC_INPUT_H_ */
