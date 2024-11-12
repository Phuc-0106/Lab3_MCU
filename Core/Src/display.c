/*
 * traffic.c
 *
 *  Created on: Oct 29, 2024
 *      Author: admin
 */
#include "display.h"
#include"main.h"
int curLED;
int curSideLED;
int redDuration, amberDuration, greenDuration;
int timer_flag;
void updateClockBuffer() {
	int temp_main = timer_counter /100;
	int temp_side = timer_counter_side /100;
	int tens_main_digit = temp_main/10;
	int unit_main_digit = temp_main % 10;
	int tens_side_digit = temp_side /10;
	int units_side_digit = temp_side % 10;

	HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin,  GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin,  GPIO_PIN_SET);
	switch(idx){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin,  GPIO_PIN_RESET);
		display7Segment(tens_main_digit);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin,  GPIO_PIN_RESET);
		display7Segment(unit_main_digit);
		break;

	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin,  GPIO_PIN_RESET);
		display7Segment(tens_side_digit);
		break;

	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin,  GPIO_PIN_RESET);
		display7Segment(units_side_digit);
		break;
	}
}
void displayMode() {
    int traffic_tens_digit = value[status-1] / 10000;
    int traffic_units_digit = (value[status-1] % 10000) / 1000;

    HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, GPIO_PIN_SET);

    switch (idx) {
        case 0:
            HAL_GPIO_WritePin(GPIOB, SEG7_1_Pin, GPIO_PIN_RESET);
            display7Segment(0);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, SEG7_2_Pin, GPIO_PIN_RESET);
            display7Segment(status);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, SEG7_3_Pin, GPIO_PIN_RESET);
            display7Segment(traffic_tens_digit);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, SEG7_4_Pin, GPIO_PIN_RESET);
            display7Segment(traffic_units_digit);
            break;
    }
}
void display7Segment(int display_number){
	HAL_GPIO_WritePin(GPIOB, SEG_ALL_Pin, SET);
	switch(display_number){
	case 0:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
		HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
		HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
		HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
		HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
		break;
	default:
		break;
}
}


