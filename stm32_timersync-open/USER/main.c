#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
//灰色 SWIO  7 左4
//白色 SWCLK 9 左5
//黑色 GND 右 2


extern vu16 var_Exp;
int main(void)
{

	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	//uart_init(115200);	 //串口初始化为115200
	uart_init(9600);		 //  UART1_TX PA9
 	LED_Init();			     //LED端口初始化
	//1000 ms 50 

	// PWM频率 = 系统时钟 / (预分频系数 * 自动重装载值)
	// 			 72MHz   / ((PSC+1) * (ARR+1))
	
	// PWM定时器配置 假设系统为72Mhz
	// 预分频值（PSC）：7199 → 实际分频系数 = 7199 + 1 = 7200
	// 定时器时钟 = 72MHz / 7200 = 10kHz
	// 自动重装载值（ARR）：999 → 实际计数值 = 999 + 1 = 1000
	// PWM频率 = 10kHz / 1000 = 10Hz
	TIM2_PWM_Init(999,7199); // 10 Hz    pin_A1       

 	TIM3_PWM_Init(9999,7199);	 // 1 Hz  pin_B5


	
	while(1)
	{
		
	}
}
