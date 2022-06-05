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
static struct rt_thread led1_thread;             //�����߳̿��ƿ�
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
	rt_thread_init(&led1_thread,
	                "led",
                   led1_thread_entry,
	                 RT_NULL,
	                 &rt_led1_thread_stack[0],
	                 sizeof(rt_led1_thread_stack),
									 3,
									 20);
	rt_thread_startup(&led1_thread);
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
