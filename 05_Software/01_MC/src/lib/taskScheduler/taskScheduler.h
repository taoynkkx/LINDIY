/**
  ******************************************************************************
  * @file    taskScheduler.h
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

#ifndef  __TASK_SCHEDULER_H
#define  __TASK_SCHEDULER_H

#include "cfg/lib/taskScheduler_cfg.h"

/**
  * @brief  Initialization of task scheduler
  * @param  None
  * @retval None
  */
extern void tasch_init(void);

/**
  * @brief  Task of task scheduler
  *         Shall be called in main dead loop
  * @param  None
  * @retval None
  */
extern void tasch_task(void);

/**
  * @brief  Tick event of task scheduler
  *         Shall be called cyclically from interrupt
  * @param  None
  * @retval None
  */
extern void tasch_event_tickUp(void);

/**
  * @brief  Idle task of task scheduler
  *         Shall be called if tick time is not expired
  *         This interface can be used as a macro, defined in _cfg.h
  *         Otherwise, this shall be implemented in _cfg.c
  * @param  None
  * @retval None
  */
#ifndef tasch_cfg_idle
extern void tasch_cfg_idle(void);
#endif

/**
  * @brief  X2 task of task scheduler
  *         Shall be called every 2 times when tick time is expired
  *         This interface can be used as a macro, defined in _cfg.h
  *         Otherwise, this shall be implemented in _cfg.c
  * @param  None
  * @retval None
  */
#ifndef tasch_cfg_taskX2
extern void tasch_cfg_taskX2(void);
#endif

/**
  * @brief  X4 task of task scheduler
  *         Shall be called every 4 times when tick time is expired
  *         This interface can be used as a macro, defined in _cfg.h
  *         Otherwise, this shall be implemented in _cfg.c
  * @param  None
  * @retval None
  */
#ifndef tasch_cfg_taskX4
extern void tasch_cfg_taskX4(void);
#endif

#ifndef tasch_cfg_taskX8
extern void tasch_cfg_taskX8(void);
#endif

#ifndef tasch_cfg_taskX16
extern void tasch_cfg_taskX16(void);
#endif

#ifndef tasch_cfg_taskX32
extern void tasch_cfg_taskX32(void);
#endif

#ifndef tasch_cfg_taskX64
extern void tasch_cfg_taskX64(void);
#endif

#ifndef tasch_cfg_taskX128
extern void tasch_cfg_taskX128(void);
#endif

#ifndef tasch_cfg_taskX256
extern void tasch_cfg_taskX256(void);
#endif

#ifndef tasch_cfg_taskX512
extern void tasch_cfg_taskX512(void);
#endif

#ifndef tasch_cfg_taskX1024
extern void tasch_cfg_taskX1024(void);
#endif

#endif  //  __TASK_SCHEDULER_H
