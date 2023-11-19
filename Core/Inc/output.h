#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

enum statusLed{
    led1,
    led2,
    led3,
    led4,
};
extern enum statusLed status;
void display7SEG(int num);
void led7SEG4Mode(int state);
void subsLed7SEG();
void scanningLed7SEG();
#endif /* INC_OUTPUT_H_ */