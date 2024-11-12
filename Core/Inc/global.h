/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

int redDuration, greenDuration, amberDuration;
#define MODE_NORMAL 0
#define MODE_RED 1
#define MODE_AMBER 2
#define MODE_GREEN 3

#define MODIFY_RED 11
#define MODIFY_AMBER 12
#define MODIFY_GREEN 13


extern int curLED, curSideLED;
extern int idx; //to point which led segment is displayed
extern int status;
extern int value[3];

extern int timer_counter;
extern int timer_flag;

extern int timer_counter_side;
extern int timer_flag_side;

extern int display_timer_counter;
extern int display_timer_flag;

extern int mode_timer_counter;
extern int mode_timer_flag;

#endif /* INC_GLOBAL_H_ */
