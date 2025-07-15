/**
 ******************************************************************************
 * @file    hal_gpio.h
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the hal_gpio.c file
 ******************************************************************************
 */

#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* Variables -----------------------------------------------------------------*/

/* TypeDef ------------------------------------------------------------------*/
#define FALSE 0
#define TRUE 1

#define LOW_STATE 0
#define HIGH_STATE 1

/* Extern Variables -----------------------------------------------------------------*/

// AFE Pins
#define AFE_PDN_P_Pin 498
#define AFE_RST_P_Pin 499

#define AFE0_SEN_Pin 497
#define AFE1_SEN_Pin 476
#define AFE2_SEN_Pin 481
#define AFE3_SEN_Pin 486
#define AFE4_SEN_Pin 491

// DAC Pins
#define DAC_LDACn_Pin 497
#define DAC_SYNCn_Pin 496

#define SYNC0_TRM_Pin 472
#define SYNC1_TRM_Pin 477
#define SYNC2_TRM_Pin 482
#define SYNC3_TRM_Pin 487
#define SYNC4_TRM_Pin 492

#define LDAC0_TRM_Pin 473
#define LDAC1_TRM_Pin 478
#define LDAC2_TRM_Pin 483
#define LDAC3_TRM_Pin 488
#define LDAC4_TRM_Pin 492

#define SYNC0_OFF_Pin 474
#define SYNC1_OFF_Pin 479
#define SYNC2_OFF_Pin 484
#define SYNC3_OFF_Pin 489
#define SYNC4_OFF_Pin 494

#define LDAC0_OFF_Pin 475
#define LDAC1_OFF_Pin 480
#define LDAC2_OFF_Pin 485
#define LDAC3_OFF_Pin 490
#define LDAC4_OFF_Pin 495

/* Prototype -----------------------------------------------------------------*/

/* Base functions */

/* GPIO init functions */
void MX_GPIO_Init(void);
void HAL_GPIO_PinOut_Init(int gpio_pin);

/* GPIO state functions */
void HAL_GPIO_WritePin(int gpio_port, int gpio_pin, int value);

#endif /* __HAL_GPIO_H__ */
