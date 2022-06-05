/**
  ******************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   GPIO输出--使用固件库点亮LED灯
  ******************************************************************
  * @attention
  *
  * 实验平台:野火 STM32H743开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************
  */  
#include "board.h"
#include "rtthread.h"
static rt_thread_t led1_thread = RT_NULL;             //定义线程控制块
ALIGN(RT_ALIGN_SIZE)                             //定义地址对其方式
static rt_uint8_t rt_led1_thread_stack[1024];    //定义线程栈大小

static void led1_thread_entry(void* parameter);
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	led1_thread = 
	rt_thread_create("led1",
                   led1_thread_entry,
	                 RT_NULL,
	                 512,
									 3,
									 20);
   if (led1_thread != RT_NULL)
        rt_thread_startup(led1_thread);
    else
        return -1;
}
static void led1_thread_entry(void *parameter)
{
  while(1)
	{
	  LED1_ON;
		rt_thread_delay(500);
		LED1_OFF;
		rt_thread_delay(500);
	}
}
/****************************END OF FILE***************************/
