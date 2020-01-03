#ifndef __display_h
#define __display_h
// Hal: exp: #define LED_COM P10 -----------------
#define LED_COM P1_0

// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  	//高电平led灯亮
#define D_ledOff 0 	//低电平led灯灭
// Globle Var ----------------------------------

#ifdef __display_c

#else

#endif
// Action Macro: exp: #define F_getData() ------
#define F_ledOn() LED_COM = D_ledOn
#define F_ledOff() LED_COM = D_ledOff
#define F_ledNeg() LED_COM = ~LED_COM
// Function ------------------------------------
#endif