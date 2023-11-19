#ifndef INC_FSM_TRAFFIC_SYSTEM_H_
#define INC_FSM_TRAFFIC_SYSTEM_H_

#define INIT                    1
#define RED1_GREEN2             2
#define RED1_YELLOW2            3
#define GREEN1_RED2             4
#define YELLOW1_RED2            5
#define RED1_RED2               14
#define GREEN1_GREEN2           15
#define YELLOW1_YELLOW2         16
#define MODE2                   6
#define MODE3                   7
#define MODE4                   8

extern int state;
extern int led7SEGbuffer[4];
extern int timeRoad[3];
void fsmTrafficSystemRun();
void setStateTrafficSystem(int state);

#endif /* INC_FSM_TRAFFIC_SYSTEM_H_ */
