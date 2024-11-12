/*
 * fsm_man.c
 *
 *  Created on: Oct 29, 2024
 *      Author: admin
 */

#include "fsm_mode.h"
#include "main.h"
#include "timer.h"
#include "button.h"
#include "display.h"
int value[3]={5000,2000,3000};
int status = 0;
int curLED = 0;
int curSideLED = 1;
int redDuration = 5000;
int greenDuration = 3000;
int amberDuration = 2000;
void fsm_run(){
	switch(status){
	case MODE_NORMAL:{
			if (display_timer_flag) {
				display_timer_flag = 0;
				setDisplayTimer(250);
				updateClockBuffer();
			}
			if(timer_flag){
				timer_flag = 0;
			switch (curLED) {
				case 0:
					curLED=1;
					HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_SET);
					setTimer(greenDuration);
					break;

				case 1:
					curLED = 2;
					HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, GPIO_PIN_SET);
					setTimer(amberDuration);
					break;

				case 2:
					curLED = 0;
					HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
					setTimer(redDuration);
					break;
				}
			}
			if (timer_flag_side) {
				timer_flag_side = 0;

				switch (curSideLED) {
				case 0:
					curSideLED = 1;
					HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
					setTimerSide(greenDuration);
					break;

				case 1:
					curSideLED = 2;
					HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, GPIO_PIN_SET);
					setTimerSide(amberDuration);
					break;

				case 2:
					curSideLED = 0;
					HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
					setTimerSide(redDuration);
					break;
				}
			}
			break;
}
	case MODE_RED:{
		//blink led 1
		if(display_timer_flag){
			display_timer_flag=0;
			setDisplayTimer(250);
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
			displayMode();
		}
		break;
	}
	case MODE_AMBER:{
		if(display_timer_flag){
			display_timer_flag=0;
			setDisplayTimer(250);
			HAL_GPIO_TogglePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin);
			HAL_GPIO_TogglePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin);
			displayMode();
		}
		break;
	}
	case MODE_GREEN:{
		if(display_timer_flag){
			display_timer_flag=0;
			setDisplayTimer(250);
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
			displayMode();
		}
		break;
	}
	default:
		break;
}
}
void initial(){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_SET);
  setTimer(500);

  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
  setTimerSide(300);

  setDisplayTimer(250);

  curLED = 0;
  curSideLED = 2;


  idx = 0;
}

