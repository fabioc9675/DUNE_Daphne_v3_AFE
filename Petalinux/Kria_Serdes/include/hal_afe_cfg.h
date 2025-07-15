/**
 ******************************************************************************
 * @file    hal_afe_cfg.h
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the hal_afe_cfg.h file
 ******************************************************************************
 */

#ifndef __HAL_AFE_CFG_H__
#define __HAL_AFE_CFG_H__

/* Includes ------------------------------------------------------------------*/
#include "hal_afe5808a.h"

/* Prototype -----------------------------------------------------------------*/
HAL_AFEStatusTypeDef HAL_AFE_TestConfig(AFE_HandleTypeDef *hafe);
/* Configuration */
HAL_AFEStatusTypeDef HAL_AFE_InitialConfig(AFE_HandleTypeDef *hafe);
/* AFE Software Reset configuration */
HAL_AFEStatusTypeDef HAL_AFE_ResetConfig(AFE_HandleTypeDef *hafe);

/* Test Configuration Functions ----------------------------------------------*/
/* AFE Ramp test configuration */
HAL_AFEStatusTypeDef HAL_AFE_RampTest(AFE_HandleTypeDef *hafe);
/* AFE Sync test configuration */
HAL_AFEStatusTypeDef HAL_AFE_SyncTest(AFE_HandleTypeDef *hafe);
/* AFE Skew test configuration */
HAL_AFEStatusTypeDef HAL_AFE_SkewTest(AFE_HandleTypeDef *hafe);
/* AFE Custom test configuration */
HAL_AFEStatusTypeDef HAL_AFE_CustomTest(AFE_HandleTypeDef *hafe);
/* AFE All 1s test configuration */
HAL_AFEStatusTypeDef HAL_AFE_All1sTest(AFE_HandleTypeDef *hafe);
/* AFE Toggle test configuration */
HAL_AFEStatusTypeDef HAL_AFE_ToggleTest(AFE_HandleTypeDef *hafe);
/* AFE All 0s test configuration */
HAL_AFEStatusTypeDef HAL_AFE_All0sTest(AFE_HandleTypeDef *hafe);

#endif /* __HAL_AFE_CFG_H__ */
