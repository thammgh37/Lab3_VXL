#include "main.h"
#include "fsm_traffic_system.h"
int led7SEGbuffer[4];
int timeRoad[3] = {5,3,2};
int setTimeRoad[3];
int state = INIT;

void plusLed7SEG(){
    int time = led7SEGbuffer[0] * 10 + led7SEGbuffer[1];
    time ++;
    if (time > 99){
        time = 1;
    }
    led7SEGbuffer[0] = time/10;
    led7SEGbuffer[1] = time%10;
}
void checkSetTimeValid(){
    if (setTimeRoad[1] + setTimeRoad[2] == setTimeRoad[0]){
        for (int i = 0; i < 3 ; i++){
            timeRoad[i] = setTimeRoad[i];
        }
    }
}
void updateTimeRoad(int state){
    int time = led7SEGbuffer[0]*10 + led7SEGbuffer[1];
    switch (state)
    {
    case MODE2:
        setTimeRoad[0] = time;
        break;
    case MODE3:
        setTimeRoad[1] = time;
        break;
    case MODE4:
        setTimeRoad[2] = time;
        break;
    default:
        break;
    }
}
void setStateTrafficSystem(int state){
    switch (state)
    {
    case RED1_GREEN2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,RESET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,RESET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,SET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,RESET);
        break;   
    case RED1_YELLOW2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,RESET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,RESET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,SET);
        break; 
    case GREEN1_RED2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,SET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,RESET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,SET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,RESET);
        break;  
    case YELLOW1_RED2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,SET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,SET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,RESET);
        break;
    case RED1_RED2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,SET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,RESET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,SET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,RESET);
        break;
    case YELLOW1_YELLOW2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,SET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,RESET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,SET);
        break;
    case GREEN1_GREEN2:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,SET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,RESET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,SET);
        break;
    case INIT:
        HAL_GPIO_WritePin(RED1_GPIO_Port,RED1_Pin,RESET);
        HAL_GPIO_WritePin(GREEN1_GPIO_Port,GREEN1_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW1_GPIO_Port,YELLOW1_Pin,RESET);
        HAL_GPIO_WritePin(RED2_GPIO_Port,RED2_Pin,RESET);
        HAL_GPIO_WritePin(GREEN2_GPIO_Port,GREEN2_Pin,RESET);
        HAL_GPIO_WritePin(YELLOW2_GPIO_Port,YELLOW2_Pin,RESET);
        break;
    default:
        break;
    }
}
void fsmTrafficSystemRun(){
    switch (state)
    {
    case INIT:
        // Control LED 3 mau
        setStateTrafficSystem(INIT);

        // trans state mode1
        state = RED1_GREEN2;
        setTimer1(timeRoad[1]*1000);

        // control led 7 doan
        setTimer3(1000);
        led7SEG4Mode(RED1_GREEN2);
        break; 
    case RED1_GREEN2:
        //control led 3 mau
        setStateTrafficSystem(RED1_GREEN2);

        // tru second moi giay
        if (timer3_flag == 1){
            setTimer3(1000);
            subsLed7SEG();
        }
        // trans state mode1
        if (timer1_flag == 1){
            state = RED1_YELLOW2;
            setTimer1(timeRoad[2]*1000);

            setTimer3(1000);
            led7SEG4Mode(RED1_YELLOW2);
        }

        // control button
        if (isButtonPress(0) == 1){
            // flag for debug
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            // trans state mode2
            state = MODE2;
            setStateTrafficSystem(INIT);
            setTimer1(10000);

            // control led 7 segment mode2
            led7SEG4Mode(MODE2);
            setTimer2(250);
        }

        break; 
    case RED1_YELLOW2:
        //control led 3 mau
        setStateTrafficSystem(RED1_YELLOW2);

        // tru second moi giay
        if (timer3_flag == 1){
            setTimer3(1000);
            subsLed7SEG();
        }

        // trans state mode1
        if (timer1_flag == 1){
            state = GREEN1_RED2;
            setTimer1(timeRoad[1]*1000);

            setTimer3(1000);
            led7SEG4Mode(GREEN1_RED2);
        }
        //control button
        if (isButtonPress(0) == 1){
            //flag for debug
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            //trans state mode2
            state = MODE2;
            setStateTrafficSystem(INIT);
            setTimer1(10000);

            //control led 7 segment mode2
            led7SEG4Mode(MODE2);
            setTimer2(250);
        }

        break; 
    case GREEN1_RED2:
        //control led 3 mau
        setStateTrafficSystem(GREEN1_RED2);

        // tru second moi giay
        if (timer3_flag == 1){
            setTimer3(1000);
            subsLed7SEG();
        }

        //trans state mode1
        if (timer1_flag == 1){
            state = YELLOW1_RED2;
            setTimer1(timeRoad[2]*1000);

            setTimer3(1000);
            led7SEG4Mode(YELLOW1_RED2);
        }

        //control button
        if (isButtonPress(0) == 1){
            // flag for debug
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            // trans state mode2
            state = MODE2;
            setStateTrafficSystem(INIT);
            setTimer1(10000);

            // control led 7 doan cho mode2
            led7SEG4Mode(MODE2);
            setTimer2(250);
        }
        break; 
    case YELLOW1_RED2:
        //control led 3 mau
        setStateTrafficSystem(YELLOW1_RED2);

        // tru second moi giay
        if (timer3_flag == 1){
            setTimer3(1000);
            subsLed7SEG();
        }

        // trans state mode normal
        if (timer1_flag == 1){
            state = RED1_GREEN2;
            setTimer1(timeRoad[1]*1000);

            setTimer3(1000);
            led7SEG4Mode(RED1_GREEN2);
        }
        //control button
        if (isButtonPress(0) == 1){
            // flag for debug
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            // trans state mode2
            state = MODE2;
            setStateTrafficSystem(INIT);
            setTimer1(10000);

            // control led 7 doan cho mode2
            led7SEG4Mode(MODE2);
            setTimer2(250);
        }
        break;
    case MODE2:
        // hen gio return mode1
        if(timer1_flag == 1){
            state = GREEN1_RED2;
            // kiem tra time duration duoc set co hop le chua
            checkSetTimeValid();
            setTimer1(timeRoad[1]*1000);
            
            // cap nhat lai 4 led 7 seg cho che do normal
            setTimer3(1000);
            led7SEG4Mode(GREEN1_RED2);
        }

        // control button
        // button chinh mode
        if(isButtonPress(0) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            state = MODE3;
            setTimer1(10000);
            setStateTrafficSystem(INIT);
            led7SEG4Mode(MODE3);

            // chuyen sang MODE3 reset flag de den khong bi blink ngay
            setTimer2(250);
        }
        //button chinh thoi gian
        if (isButtonPress(1) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            plusLed7SEG();
            setTimer1(10000);
        }
        //button save thoi gian
        if (isButtonPress(2) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            updateTimeRoad(MODE2);

            setTimer1(10000);
        }

        if(timer2_flag == 1){
            setTimer2(250);
            HAL_GPIO_TogglePin(RED1_GPIO_Port,RED1_Pin);
            HAL_GPIO_TogglePin(RED2_GPIO_Port,RED2_Pin);
        }
        break;
    case MODE3:
        // alarm return mode1
        if(timer1_flag == 1){
            state = GREEN1_RED2;
            checkSetTimeValid();
            setTimer1(timeRoad[1]*1000);
            
            // cap nhat lai 4 led 7 seg cho che do normal
            setTimer3(1000);
            led7SEG4Mode(GREEN1_RED2);
        }

        //control button
        //button chinh mode
        if(isButtonPress(0) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            state = MODE4;
            setTimer1(10000);
            setStateTrafficSystem(INIT);
            led7SEG4Mode(MODE4);

            // chuyen sang MODE3 reset flag de den khong bi blink ngay
            setTimer2(250);
        }
        // button chinh gio
        if (isButtonPress(1) == 1 ){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            plusLed7SEG();
            setTimer1(10000);
        }
        //button save gio
        if (isButtonPress(2) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            updateTimeRoad(MODE3);

            setTimer1(10000);
        }

        if(timer2_flag == 1){
            setTimer2(250);
            HAL_GPIO_TogglePin(GREEN1_GPIO_Port,GREEN1_Pin);
            HAL_GPIO_TogglePin(GREEN2_GPIO_Port,GREEN2_Pin);
        }
        break;
    case MODE4:
        //alarm return mode1
        if(timer1_flag == 1){
            state = GREEN1_RED2;
            checkSetTimeValid();
            setTimer1(timeRoad[1]*1000);

            // cap nhat lai 4 led 7 seg cho che do normal
            setTimer3(1000);
            led7SEG4Mode(GREEN1_RED2);
        }
        //control button
        //button chinh mode
        if(isButtonPress(0) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            state = GREEN1_RED2;
            checkSetTimeValid();
            
            setTimer1(timeRoad[1]*1000);
            setTimer3(1000);
            led7SEG4Mode(GREEN1_RED2);
            // chuyen sang MODE3 reset flag de den khong bi blink ngay
            setTimer2(250);
        }
        //button chinh gio
        if (isButtonPress(1) == 1 ){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            plusLed7SEG();
            setTimer1(10000);            
        }
        //button save gio
        if (isButtonPress(2) == 1){
            HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
            updateTimeRoad(MODE4);

            setTimer1(10000);
        }

        if(timer2_flag == 1){
            setTimer2(250);
            HAL_GPIO_TogglePin(YELLOW1_GPIO_Port,YELLOW1_Pin);
            HAL_GPIO_TogglePin(YELLOW2_GPIO_Port,YELLOW2_Pin);
        }
        break;
    default:
        break;
    }
    if (timer4_flag == 1){
        setTimer4(100);
        scanningLed7SEG();
    }
}