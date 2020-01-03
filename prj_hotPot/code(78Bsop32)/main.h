#ifndef __main_h
#define __main_h
// Hal: exp: #define LED_COM P10 -----------------

// Const: exp: #define D_data 1 ----------------
// base 1ms
#define D_5ms 5
#define D_1000ms 1000
// Globle Var ----------------------------------

#ifdef __main_c
uint8_t ledState;
#else
extern uint8_t ledState;
#endif

// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void LedOn();
void LedOff();
void LedFlash();
void NumDisplay()
void Buzz();
void TimeProcess();
void TaskSetting();
void Delay(uint16_t time);
#endif