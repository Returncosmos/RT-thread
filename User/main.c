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

static rt_thread_t led1_thread = RT_NULL;
static rt_thread_t led2_thread = RT_NULL;             //定义线程控制块
//ALIGN(RT_ALIGN_SIZE)                             //定义地址对其方式
//static rt_uint8_t rt_led1_thread_stack[1024];    //定义线程栈大小


static void led1_thread_entry(void* parameter);
static void led2_thread_entry(void* parameter);
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{

	led1_thread =                          /* 线程控制块指针 */
    rt_thread_create( "led1",              /* 线程名字 */
                      led1_thread_entry,   /* 线程入口函数 */
                      RT_NULL,             /* 线程入口函数参数 */
                      512,                 /* 线程栈大小 */
                      3,                   /* 线程的优先级 */
                      20);                 /* 线程时间片 */
                   
    /* 启动线程，开启调度 */

   if (led1_thread != RT_NULL)
        rt_thread_startup(led1_thread);
    else
        return -1;

    
    led2_thread =                          /* 线程控制块指针 */
    rt_thread_create( "led2",              /* 线程名字 */
                      led2_thread_entry,   /* 线程入口函数 */
                      RT_NULL,             /* 线程入口函数参数 */
                      512,                 /* 线程栈大小 */
                      4,                   /* 线程的优先级 */
                      20);                 /* 线程时间片 */
                   
    /* 启动线程，开启调度 */
   if (led2_thread != RT_NULL)
        rt_thread_startup(led2_thread);
    else
        return -1;

}
static void led1_thread_entry(void* parameter)
{	
    while (1)
    {
        LED1_ON;
        rt_thread_delay(500);   /* 延时500个tick */
			  rt_kprintf("led1_thread running,LED1_ON\r\n");
        
        LED1_OFF;     
        rt_thread_delay(500);   /* 延时500个tick */		 		
        rt_kprintf("led1_thread running,LED1_OFF\r\n");
    }
}

static void led2_thread_entry(void* parameter)
{	
    while (1)
    {
        LED2_ON;
        rt_thread_delay(300);   /* ��ʱ300��tick */
			  rt_kprintf("led1_thread running,LED2_ON\r\n");
        
        LED2_OFF;     
        rt_thread_delay(300);   /* ��ʱ300��tick */		
        rt_kprintf("led1_thread running,LED2_OFF\r\n");			
    }
}
/****************************END OF FILE***************************/
