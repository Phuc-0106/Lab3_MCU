/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: admin
 */
#include "button.h"
#include"main.h"
#include"fsm_mode.h"
// Button flag
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

// default value of led
int current_mode = MODE_NORMAL;

static int KeyReg1_0 =NORMAL_STATE;
static int KeyReg1_1 =NORMAL_STATE;
static int KeyReg1_2 = NORMAL_STATE;
static int KeyReg1_3 = NORMAL_STATE;

static int KeyReg2_0 =NORMAL_STATE;
static int KeyReg2_1 =NORMAL_STATE;
static int KeyReg2_2 = NORMAL_STATE;
static int KeyReg2_3 = NORMAL_STATE;

static int KeyReg3_0 =NORMAL_STATE;
static int KeyReg3_1 =NORMAL_STATE;
static int KeyReg3_2 = NORMAL_STATE;
static int KeyReg3_3 = NORMAL_STATE;

static int TimerForKeyPress = 200;

void getKeyInput1(){
	KeyReg1_0 = KeyReg1_1;
	KeyReg1_1 = KeyReg1_2;
	KeyReg1_2 = HAL_GPIO_ReadPin(button_1_GPIO_Port, button_1_Pin);
	if((KeyReg1_0 == KeyReg1_1) && (KeyReg1_1 == KeyReg1_2)){
		if(KeyReg1_3 != KeyReg1_2){
			KeyReg1_3 = KeyReg1_2;
			if(KeyReg1_3 == PRESSED_STATE){
				subKeyProcess(1);
				TimerForKeyPress = 200;
			}
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				KeyReg1_3 = NORMAL_STATE;
			}
		}
}
}

void getKeyInput2(){
		KeyReg2_0 = KeyReg2_1;
		KeyReg2_1 = KeyReg2_2;
		KeyReg2_2 = HAL_GPIO_ReadPin(button_2_GPIO_Port, button_2_Pin);
		if((KeyReg2_0 == KeyReg1_1) && (KeyReg2_1 == KeyReg2_2)){
			if(KeyReg2_3 != KeyReg2_2){
				KeyReg2_3 = KeyReg2_2;
				if(KeyReg2_2 == PRESSED_STATE){
					subKeyProcess(2);
					TimerForKeyPress = 200;
				}
			}else{
				TimerForKeyPress--;
				if(TimerForKeyPress == 0){
					KeyReg2_3 = NORMAL_STATE;
				}
			}
		}
}

void getKeyInput3(){
		KeyReg3_0 = KeyReg3_1;
		KeyReg3_1 = KeyReg3_2;
		KeyReg3_2 = HAL_GPIO_ReadPin(button_3_GPIO_Port, button_3_Pin);
		if((KeyReg3_0 == KeyReg3_1) && (KeyReg3_1 == KeyReg3_2)){
			if(KeyReg3_3 != KeyReg3_2){
				KeyReg3_3 = KeyReg3_2;
				if(KeyReg3_2 == PRESSED_STATE){
					subKeyProcess(3);
					TimerForKeyPress = 200;
				}
			}else{
				TimerForKeyPress--;
				if(TimerForKeyPress == 0){
					KeyReg3_3 = NORMAL_STATE;
				}
			}
		}
}

void isButton1Pressed() {
    if (button1_flag == 1) {
        status++;
        if(status>=4){
        	status = 0;
        }
        else if(status!=0){
        	display_timer_flag = 1;
        }
    	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
    }
}

void isButton2Pressed() {
    if (button2_flag == 1) {
        value[status - 1] += 1000;
        if(value[status - 1]>99000){
        	value[status-1] = 0;
        }
    }
}

void isButton3Pressed() {
    if (button3_flag == 1) {
        if(status==1){
        	redDuration = value[status-1];
        	greenDuration = redDuration - amberDuration;
        }
        else if(status==2){
        	amberDuration = value[status-1];
        	redDuration = amberDuration + greenDuration;
        }
        else if(status==3){
        	greenDuration = value[status-1];
        	redDuration = amberDuration + greenDuration;
        }
        else if(status!=0){
        	initial();
        	status = 0;
        }
    }
}

void subKeyProcess(int button_id) {
    // record the button state
    switch (button_id) {
        case 1:
            button1_flag = 1;
            isButton1Pressed();
            break;
        case 2:
            button2_flag = 1;
            isButton2Pressed();
            break;
        case 3:
            button3_flag = 1;
            isButton3Pressed();
            break;
        default:
            break;
    }
}



