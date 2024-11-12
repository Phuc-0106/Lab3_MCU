/*
 * traffic.h
 *
 *  Created on: Oct 29, 2024
 *      Author: admin
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#define SEG_ALL_Pin A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | G_Pin
#include "global.h"

int getRedDuration();
int getAmberDuration();
int getGreenDuration();
void updateClockBuffer();
void displayMode();
void display7Segment(int mode);
void traffic_run(int curLED, int curSideLED) ;
void init();
#endif /* INC_DISPLAY_H_ */
