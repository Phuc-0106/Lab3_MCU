/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

// Trạng thái của nút
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

// Định nghĩa các chế độ

// Biến thời lượng cho các đèn LED

// Biến cho chế độ hiện tại
extern int current_mode;

// Hàm kiểm tra trạng thái nút
void isButton1Pressed();
void isButton2Pressed();
void isButton3Pressed();

// Xử lý sự kiện nút
void subKeyProcess(int button_id);

// Đọc tín hiệu nút
void getKeyInput1();
void getKeyInput2();
void getKeyInput3();

#endif /* INC_BUTTON_H_ */
