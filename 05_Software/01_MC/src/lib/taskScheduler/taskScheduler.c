/**
  ******************************************************************************
  * @file    taskScheduler.c
  * @author  taoynkkx@163.com
  * @version V0.0
  * @date    2018.5.24
  * @brief   task scheduler
  ******************************************************************************
  * @history
  *
  *
  ******************************************************************************
  */

#include "taskScheduler.h"

typedef struct
{
  // input signals
  struct
  {
    unsigned char tick;	// count up for tick interrupt
  }
  input;
  // local signals
  struct
  {
    unsigned char tick;	// follow the tick from interrupt
	unsigned short count;	// count for task scheduling
  }
  local;
}
T_TASCH;

static T_TASCH tasch;	// local struct variable of this module

/**
  * @brief  Initialization of task scheduler
  * @param  None
  * @retval None
  */
void tasch_init(void)
{
  tasch.input.tick = 0;
  tasch.local.tick = 0;
  tasch.local.count = 0;
}

/**
  * @brief  Task of task scheduler
  *         Shall be called in main dead loop
  * @param  None
  * @retval None
  */
void tasch_task(void)
{
  // check if tick is updated
  if( tasch.local.tick!=tasch.input.tick )	// updated
  {
  	// update tick and count
	tasch.local.tick = tasch.input.tick;
	tasch.local.count++;

	// run a task
	if     ( tasch.local.count&0x0001 ) tasch_cfg_taskX2();
	else if( tasch.local.count&0x0002 ) tasch_cfg_taskX4();
	else if( tasch.local.count&0x0004 ) tasch_cfg_taskX8();
	else if( tasch.local.count&0x0008 ) tasch_cfg_taskX16();
	else if( tasch.local.count&0x0010 ) tasch_cfg_taskX32();
	else if( tasch.local.count&0x0020 ) tasch_cfg_taskX64();
	else if( tasch.local.count&0x0040 ) tasch_cfg_taskX128();
	else if( tasch.local.count&0x0080 ) tasch_cfg_taskX256();
	else if( tasch.local.count&0x0100 ) tasch_cfg_taskX512();
	else if( tasch.local.count&0x0200 ) tasch_cfg_taskX1024();
	else;	// reserved for CPU load
  }
  else	// no updated
  {
  	// run idle task
	tasch_cfg_idle();
  }
}

/**
  * @brief  Tick event of task scheduler
  *         Shall be called cyclically from interrupt
  * @param  None
  * @retval None
  */
void tasch_event_tick(void)
{
  tasch.input.tick++;
}
