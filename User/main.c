/**
  ******************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   GPIO���--ʹ�ù̼������LED��
  ******************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� STM32H743������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************
  */  
#include "board.h"
#include "rtthread.h"
static rt_thread_t led1_thread = RT_NULL;             //�����߳̿��ƿ�
ALIGN(RT_ALIGN_SIZE)                             //�����ַ���䷽ʽ
static rt_uint8_t rt_led1_thread_stack[1024];    //�����߳�ջ��С

static void led1_thread_entry(void* parameter);
/**
  * @brief  ������
  * @param  ��
  * @retval ��
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
