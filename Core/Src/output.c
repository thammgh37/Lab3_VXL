#include "main.h"

enum statusLed status = led1;
void scanningLed7SEG(){
    switch (status) {
    case led1:
        display7SEG(led7SEGbuffer[0]);
        HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin, 0);
        HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin, 1);
        HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin, 1);
        HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin, 1);
        status = led2;
        break;
    case led2:
        display7SEG(led7SEGbuffer[1]);
        HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin, 1);
        HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin, 0);
        HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin, 1);
        HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin, 1);
        status = led3;
        break;
    case led3:
        display7SEG(led7SEGbuffer[2]);
        HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin, 1);
        HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin, 1);
        HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin, 0);
        HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin, 1);
        status = led4;
        break;
    case led4:
        display7SEG(led7SEGbuffer[3]);
        HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin, 1);
        HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin, 1);
        HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin, 1);
        HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin, 0);
        status = led1;
        break;
    default:
        break;
}
}
void led7SEG4Mode(int state){
    int redTime = timeRoad[0];
    int greenTime = timeRoad[1];
    int yellowTime = timeRoad[2];
    switch (state)
    {
    case GREEN1_RED2:
        led7SEGbuffer[0] = greenTime/10;
        led7SEGbuffer[1] = greenTime%10;
        led7SEGbuffer[2] = redTime/10;
        led7SEGbuffer[3] = redTime%10;
        break;
    case YELLOW1_RED2:
        led7SEGbuffer[0] = yellowTime/10;
        led7SEGbuffer[1] = yellowTime%10;
        break;
    case RED1_GREEN2:
        led7SEGbuffer[0] = redTime/10;
        led7SEGbuffer[1] = redTime%10;
        led7SEGbuffer[2] = greenTime/10;
        led7SEGbuffer[3] = greenTime%10;
        break;
    case RED1_YELLOW2:
        led7SEGbuffer[2] = yellowTime/10;
        led7SEGbuffer[3] = yellowTime%10;
        break;
    case MODE2:
        led7SEGbuffer[0] = redTime/10;
        led7SEGbuffer[1] = redTime%10;
        led7SEGbuffer[2] = 0;
        led7SEGbuffer[3] = 2;
        break;
    case MODE3:
        led7SEGbuffer[0] = greenTime/10;
        led7SEGbuffer[1] = greenTime%10;
        led7SEGbuffer[2] = 0;
        led7SEGbuffer[3] = 3;
        break;
    case MODE4:
        led7SEGbuffer[0] = yellowTime/10;
        led7SEGbuffer[1] = yellowTime%10;
        led7SEGbuffer[2] = 0;
        led7SEGbuffer[3] = 4;
        break;
    
    default:
        break;
    }
}
void driverLed7SEG(){
    
}
void subsLed7SEG(){
    // 2 led 7 seg EN0 va EN1
    int time1  = led7SEGbuffer[0]*10 + led7SEGbuffer[1];
    time1--;
    if (time1 <0){
        time1 = 9;
    }
    led7SEGbuffer[0] = time1/10;
    led7SEGbuffer[1] = time1%10;
 
    // 2 led 7 seg EN2 va EN3
    int time2 = led7SEGbuffer[2]*10 + led7SEGbuffer[3];
    time2--;
    if (time2 <0){
        time2 = 9;
    }
    led7SEGbuffer[2] = time2/10;
    led7SEGbuffer[3] = time2%10;
}
void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 1);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 1);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 1);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 1);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 1);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, 0);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, 0);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, 0);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, 0);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, 0);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, 0);
		break;
	}
}
// void fsmOutputRun(){
//     switch (state)
//     {
//     case INIT:
//         led7SEG4Mode(GREEN1_RED2);
//         break;
//     case GREEN1_RED2:
//         if(isButtonPress(0)){
//             led7SEG4Mode(MODE2);
//             setTimer2(25);
//         }
//         if (timer1_flag == 1){
//             led7SEG4Mode(YELLOW1_RED2);
//         }
//         if (timer3_flag == 1){
//             setTimer3(100);
//             subsLed7SEG();
//         }
//         break;
//     case YELLOW1_RED2:
//         if(isButtonPress(0)){
//             led7SEG4Mode(MODE2);
//             setTimer2(25);
//         }
//         if (timer1_flag == 1){
//             led7SEG4Mode(RED1_GREEN2);
//         }
//         if (timer3_flag == 1){
//             setTimer3(100);
//             subsLed7SEG();
//         }
//         break;
//     case RED1_GREEN2:
//         if(isButtonPress(0)){
//             led7SEG4Mode(MODE2);
//             setTimer2(25);
//         }
//         if (timer1_flag == 1){
//             led7SEG4Mode(RED1_YELLOW2);
//         }
//         if (timer3_flag == 1){
//             setTimer3(100);
//             subsLed7SEG();
//         }
//         break;
//     case RED1_YELLOW2:
//         if(isButtonPress(0)){
//             led7SEG4Mode(MODE2);
//             setTimer2(25);
//         }
//         if (timer1_flag == 1){
//             led7SEG4Mode(GREEN1_RED2);
//         }
//         if (timer3_flag == 1){
//             setTimer3(100);
//             subsLed7SEG();
//         }
//         break;
//     case MODE2:
//         if (timer1_flag == 1){
//             // cap nhat lai 4 led 7 seg cho che do normal
//             led7SEG4Mode(GREEN1_RED2);
//         }
//         if (isButtonPress(0) == 1){
//             // chuyen sang MODE3 reset flag de den khong bi blink ngay
//             setTimer2(25);
//         }
//         if (isButtonPress(2) == 1){
//             // chuyen sang MODE3 reset flag de den khong bi blink ngay
//             setTimer2(25);
//         }
//         if(timer2_flag == 1){
//             setTimer2(25);
//             HAL_GPIO_TogglePin(RED1_GPIO_Port,RED1_Pin);
//             HAL_GPIO_TogglePin(RED2_GPIO_Port,RED2_Pin);
//         }
//         break;
//     case MODE3:
//         if (timer1_flag == 1){
//             // cap nhat lai 4 led 7 seg cho che do normal
//             led7SEG4Mode(GREEN1_RED2);
//         }
//         if (isButtonPress(0) == 1){
//             // chuyen sang MODE3 reset flag de den khong bi blink ngay
//             setTimer2(25);
//         }
//         if (isButtonPress(2) == 1){
//             // chuyen sang MODE3 reset flag de den khong bi blink ngay
//             setTimer2(25);
//         }
//         if(timer2_flag == 1){
//             setTimer2(25);
//             HAL_GPIO_TogglePin(GREEN1_GPIO_Port,GREEN1_Pin);
//             HAL_GPIO_TogglePin(GREEN2_GPIO_Port,GREEN2_Pin);
//         }
//         break;
//     case MODE4:
//         if (timer1_flag == 1){
//             // cap nhat lai 4 led 7 seg cho che do normal
//             led7SEG4Mode(GREEN1_RED2);
//         }
//         if (isButtonPress(0) == 1){
//             // chuyen sang MODE3 reset flag de den khong bi blink ngay
//             setTimer2(25);
//         }
//         if (isButtonPress(2) == 1){
//             // cap nhat lai 4 led 7 seg cho che do normal
//             led7SEG4Mode(GREEN1_RED2);
//         }
//         if(timer2_flag == 1){
//             setTimer2(25);
//             HAL_GPIO_TogglePin(YELLOW1_GPIO_Port,YELLOW1_Pin);
//             HAL_GPIO_TogglePin(YELLOW2_GPIO_Port,YELLOW2_Pin);
//         }
//         break;
    
//     default:
//         break;
//     }
//     if (timer4_flag == 1){
//         setTimer4(5);
//         scanningLed7SEG();
//     }
// }