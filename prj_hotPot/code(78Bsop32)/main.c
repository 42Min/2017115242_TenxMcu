#define __main_c
#include "includeAll.h"

//===============================main主函数====================================
void main() {

  SysInit();				//芯片系统初始化
  VarsInit();
  F_turnOnWDT();    //使能看门狗

  while (1) {
		
    F_clearWDT();	  //喂狗
		
		/***实现LED灯点亮***/
		//初始化Led灯,将P1_0置为0
		F_ledcom_On();	
		
		/**P_led1、P_led2分别置为1或0，控制相应LED灯的亮或灭**/
		//点亮LED1
		//P_led1=1;
		//P_led2=0;
		
		//点亮LED2
		P_led1=0;
		P_led2=1;

	
		
	  //开始煮水（数码管计数，从30-99，模拟煮水的过程）
		//Num_display();
		
		//煮水沸腾之后（数码管计数到99时），LED灯开始闪烁并且蜂鸣器警报提醒
		//LedFlash();			//让LED灯闪烁
		//Buzz();					//蜂鸣器报警提醒
  }
}


//===========================定义时间处理函数==================================
//控制时钟
void TimeProcess() {

static uint8_t timer5ms = 0;

  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
  }
  if (timer5ms >= 5) {
		P1MODL = 0xa8;
    	GetKeys();
  }
}


//=============================定义任务建立函数==================================
//===================任务：实现单端口复用进行按键控制led亮灭==================//
void TaskSetting() {

	if (ledcom_State){
		//LED状态转换
		if(D_keyValue1 == keyValue){
			ledcom_State = ~ledcom_State;		
		}
		P1MODL = 0xaa;
	}
	else {
			if(D_keyValue1 == keyValue){
				ledcom_State = ~ledcom_State;	
			}
	}
}


//=================================延时函数====================================
void Delay(uint16_t time) {
     uint16_t i, j;
     for (i = 0; i < time; i++) {
           for (j = 0; j < 1000; j++) {
              /* code */
             // F_turnOnWDT();
           }
     }
}
//=============================================================================