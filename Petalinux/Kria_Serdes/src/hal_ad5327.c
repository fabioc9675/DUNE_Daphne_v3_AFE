/**
 ******************************************************************************
 * @file    hal_ad5327.c
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the hal_ad5327.c file
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hal_ad5327.h"

/* Handle --------------------------------------------------------------------*/
AD_HandleTypeDef hdac_biasset;

AD_HandleTypeDef hdac_trimAfe0;
AD_HandleTypeDef hdac_trimAfe1;
AD_HandleTypeDef hdac_trimAfe2;
AD_HandleTypeDef hdac_trimAfe3;
AD_HandleTypeDef hdac_trimAfe4;

AD_HandleTypeDef hdac_offsAfe0;
AD_HandleTypeDef hdac_offsAfe1;
AD_HandleTypeDef hdac_offsAfe2;
AD_HandleTypeDef hdac_offsAfe3;
AD_HandleTypeDef hdac_offsAfe4;

/* Registers -----------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/* AD_DAC1 init function */
void MX_AD_DAC_BIASSET_Init(void)
{

    hdac_biasset.SPI_handle = &hdacbiasspi;
    hdac_biasset.Ldac_Port = DAC_LDACn_Pin;
    hdac_biasset.Ldac_Pin = DAC_LDACn_Pin;
    hdac_biasset.Sync_Port = DAC_SYNCn_Pin;
    hdac_biasset.Sync_Pin = DAC_SYNCn_Pin;
    hdac_biasset.is_DaisyChained = TRUE; // it is daisy chained
    hdac_biasset.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_biasset.Ldac_Port, hdac_biasset.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_biasset.Sync_Port, hdac_biasset.Sync_Pin,
                      SYNC_DEACT);
}

/* AD_DAC0 init function */
void MX_AD_DAC_AFE0_Init(void)
{

    // DAC trim initialization
    hdac_trimAfe0.SPI_handle = &hdactrim0spi;
    hdac_trimAfe0.Ldac_Port = LDAC0_TRM_Pin;
    hdac_trimAfe0.Ldac_Pin = LDAC0_TRM_Pin;
    hdac_trimAfe0.Sync_Port = SYNC0_TRM_Pin;
    hdac_trimAfe0.Sync_Pin = SYNC0_TRM_Pin;
    hdac_trimAfe0.is_DaisyChained = TRUE; // it is daisy chained
    hdac_trimAfe0.is_Transmiting = FALSE;

    // DAC offset initialization
    hdac_offsAfe0.SPI_handle = &hdacoffs0spi;
    hdac_offsAfe0.Ldac_Port = LDAC0_OFF_Pin;
    hdac_offsAfe0.Ldac_Pin = LDAC0_OFF_Pin;
    hdac_offsAfe0.Sync_Port = SYNC0_OFF_Pin;
    hdac_offsAfe0.Sync_Pin = SYNC0_OFF_Pin;
    hdac_offsAfe0.is_DaisyChained = TRUE; // it is daisy chained
    hdac_offsAfe0.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_trimAfe0.Ldac_Port, hdac_trimAfe0.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe0.Ldac_Port, hdac_offsAfe0.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_trimAfe0.Sync_Port, hdac_trimAfe0.Sync_Pin,
                      SYNC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe0.Sync_Port, hdac_offsAfe0.Sync_Pin,
                      SYNC_DEACT);
}

/* AD_DAC1 init function */
void MX_AD_DAC_AFE1_Init(void)
{

    // DAC trim initialization
    hdac_trimAfe1.SPI_handle = &hdactrim1spi;
    hdac_trimAfe1.Ldac_Port = LDAC1_TRM_Pin;
    hdac_trimAfe1.Ldac_Pin = LDAC1_TRM_Pin;
    hdac_trimAfe1.Sync_Port = SYNC1_TRM_Pin;
    hdac_trimAfe1.Sync_Pin = SYNC1_TRM_Pin;
    hdac_trimAfe1.is_DaisyChained = TRUE; // it is daisy chained
    hdac_trimAfe1.is_Transmiting = FALSE;

    // DAC offset initialization
    hdac_offsAfe1.SPI_handle = &hdacoffs1spi;
    hdac_offsAfe1.Ldac_Port = LDAC1_OFF_Pin;
    hdac_offsAfe1.Ldac_Pin = LDAC1_OFF_Pin;
    hdac_offsAfe1.Sync_Port = SYNC1_OFF_Pin;
    hdac_offsAfe1.Sync_Pin = SYNC1_OFF_Pin;
    hdac_offsAfe1.is_DaisyChained = TRUE; // it is daisy chained
    hdac_offsAfe1.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_trimAfe1.Ldac_Port, hdac_trimAfe1.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe1.Ldac_Port, hdac_offsAfe1.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_trimAfe1.Sync_Port, hdac_trimAfe1.Sync_Pin,
                      SYNC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe1.Sync_Port, hdac_offsAfe1.Sync_Pin,
                      SYNC_DEACT);
}

/* AD_DAC2 init function */
void MX_AD_DAC_AFE2_Init(void)
{

    // DAC trim initialization
    hdac_trimAfe2.SPI_handle = &hdactrim2spi;
    hdac_trimAfe2.Ldac_Port = LDAC2_TRM_Pin;
    hdac_trimAfe2.Ldac_Pin = LDAC2_TRM_Pin;
    hdac_trimAfe2.Sync_Port = SYNC2_TRM_Pin;
    hdac_trimAfe2.Sync_Pin = SYNC2_TRM_Pin;
    hdac_trimAfe2.is_DaisyChained = TRUE; // it is daisy chained
    hdac_trimAfe2.is_Transmiting = FALSE;

    // DAC offset initialization
    hdac_offsAfe2.SPI_handle = &hdacoffs2spi;
    hdac_offsAfe2.Ldac_Port = LDAC2_OFF_Pin;
    hdac_offsAfe2.Ldac_Pin = LDAC2_OFF_Pin;
    hdac_offsAfe2.Sync_Port = SYNC2_OFF_Pin;
    hdac_offsAfe2.Sync_Pin = SYNC2_OFF_Pin;
    hdac_offsAfe2.is_DaisyChained = TRUE; // it is daisy chained
    hdac_offsAfe2.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_trimAfe2.Ldac_Port, hdac_trimAfe2.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe2.Ldac_Port, hdac_offsAfe2.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_trimAfe2.Sync_Port, hdac_trimAfe2.Sync_Pin,
                      SYNC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe2.Sync_Port, hdac_offsAfe2.Sync_Pin,
                      SYNC_DEACT);
}

/* AD_DAC3 init function */
void MX_AD_DAC_AFE3_Init(void)
{

    // DAC trim initialization
    hdac_trimAfe3.SPI_handle = &hdactrim3spi;
    hdac_trimAfe3.Ldac_Port = LDAC3_TRM_Pin;
    hdac_trimAfe3.Ldac_Pin = LDAC3_TRM_Pin;
    hdac_trimAfe3.Sync_Port = SYNC3_TRM_Pin;
    hdac_trimAfe3.Sync_Pin = SYNC3_TRM_Pin;
    hdac_trimAfe3.is_DaisyChained = TRUE; // it is daisy chained
    hdac_trimAfe3.is_Transmiting = FALSE;

    // DAC offset initialization
    hdac_offsAfe3.SPI_handle = &hdacoffs3spi;
    hdac_offsAfe3.Ldac_Port = LDAC3_OFF_Pin;
    hdac_offsAfe3.Ldac_Pin = LDAC3_OFF_Pin;
    hdac_offsAfe3.Sync_Port = SYNC3_OFF_Pin;
    hdac_offsAfe3.Sync_Pin = SYNC3_OFF_Pin;
    hdac_offsAfe3.is_DaisyChained = TRUE; // it is daisy chained
    hdac_offsAfe3.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_trimAfe3.Ldac_Port, hdac_trimAfe3.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe3.Ldac_Port, hdac_offsAfe3.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_trimAfe3.Sync_Port, hdac_trimAfe3.Sync_Pin,
                      SYNC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe3.Sync_Port, hdac_offsAfe3.Sync_Pin,
                      SYNC_DEACT);
}

/* AD_DAC4 init function */
void MX_AD_DAC_AFE4_Init(void)
{

    // DAC trim initialization
    hdac_trimAfe4.SPI_handle = &hdactrim4spi;
    hdac_trimAfe4.Ldac_Port = LDAC4_TRM_Pin;
    hdac_trimAfe4.Ldac_Pin = LDAC4_TRM_Pin;
    hdac_trimAfe4.Sync_Port = SYNC4_TRM_Pin;
    hdac_trimAfe4.Sync_Pin = SYNC4_TRM_Pin;
    hdac_trimAfe4.is_DaisyChained = TRUE; // it is daisy chained
    hdac_trimAfe4.is_Transmiting = FALSE;

    // DAC offset initialization
    hdac_offsAfe4.SPI_handle = &hdacoffs4spi;
    hdac_offsAfe4.Ldac_Port = LDAC4_OFF_Pin;
    hdac_offsAfe4.Ldac_Pin = LDAC4_OFF_Pin;
    hdac_offsAfe4.Sync_Port = SYNC4_OFF_Pin;
    hdac_offsAfe4.Sync_Pin = SYNC4_OFF_Pin;
    hdac_offsAfe4.is_DaisyChained = TRUE; // it is daisy chained
    hdac_offsAfe4.is_Transmiting = FALSE;

    // initialization of SPI CS state
    HAL_GPIO_WritePin(hdac_trimAfe4.Ldac_Port, hdac_trimAfe4.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe4.Ldac_Port, hdac_offsAfe4.Ldac_Pin,
                      LDAC_DEACT);
    HAL_GPIO_WritePin(hdac_trimAfe4.Sync_Port, hdac_trimAfe4.Sync_Pin,
                      SYNC_DEACT);
    HAL_GPIO_WritePin(hdac_offsAfe4.Sync_Port, hdac_offsAfe4.Sync_Pin,
                      SYNC_DEACT);
}

/**
 * @brief  SPI Write Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC_TrimOffsetWriteRegister(AD_HandleTypeDef *haddac,
                                                    uint16_t *regData1W, uint16_t *regData2W, uint32_t Timeout)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    uint8_t dataSize = 4;

    uint8_t dataW[dataSize];
    uint8_t dataR[dataSize];

    // Configure SPI
    errorcode = MX_SPI_DAC_OP_Config(haddac->SPI_handle);

    // decompose data
    dataW[0] = ((*regData2W) >> 8) & 0xFF;
    dataW[1] = (*regData2W) & 0xFF;
    dataW[2] = ((*regData1W) >> 8) & 0xFF;
    dataW[3] = (*regData1W) & 0xFF;

    // Activate device
    HAL_GPIO_WritePin(haddac->Ldac_Port, haddac->Ldac_Pin, LDAC_DEACT);
    HAL_GPIO_WritePin(haddac->Sync_Port, haddac->Sync_Pin, SYNC_ACT);

    // Write data to the register
    if (haddac->is_DaisyChained == TRUE)
    {
        // Use SPI
        haddac->is_Transmiting = TRUE;

        // Write data to the register
        (void)HAL_SPI_TransmitReceive(haddac->SPI_handle, dataW, dataR, dataSize, Timeout);
    }

    // Deactivate device
    HAL_GPIO_WritePin(haddac->Sync_Port, haddac->Sync_Pin, SYNC_DEACT);
    HAL_GPIO_WritePin(haddac->Ldac_Port, haddac->Ldac_Pin, LDAC_ACT);
    haddac->is_Transmiting = FALSE;

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC_BiasSetWriteRegister(AD_HandleTypeDef *haddac,
                                                 uint16_t *regData1W, uint16_t *regData2W, uint16_t *regData3W,
                                                 uint32_t Timeout)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    uint8_t dataSize = 6;

    uint8_t dataW[dataSize];
    uint8_t dataR[dataSize];

    // decompose data
    dataW[0] = ((*regData3W) >> 8) & 0xFF;
    dataW[1] = (*regData3W) & 0xFF;
    dataW[2] = ((*regData2W) >> 8) & 0xFF;
    dataW[3] = (*regData2W) & 0xFF;
    dataW[4] = ((*regData1W) >> 8) & 0xFF;
    dataW[5] = (*regData1W) & 0xFF;

    // Activate device
    HAL_GPIO_WritePin(haddac->Ldac_Port, haddac->Ldac_Pin, LDAC_DEACT);
    HAL_GPIO_WritePin(haddac->Sync_Port, haddac->Sync_Pin, SYNC_ACT);

    // Write data to the register
    if (haddac->is_DaisyChained == TRUE)
    {

        // Use SPI Emulation
        haddac->is_Transmiting = TRUE;

        // Write data to the register
        (void)HAL_SPI_TransmitReceive(haddac->SPI_handle, (uint8_t *)dataW,
                                      (uint8_t *)dataR, dataSize, Timeout);
    }

    // Deactivate device
    HAL_GPIO_WritePin(haddac->Sync_Port, haddac->Sync_Pin, SYNC_DEACT);
    HAL_GPIO_WritePin(haddac->Ldac_Port, haddac->Ldac_Pin, LDAC_ACT);

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC1TrimOffset_ModifyParam(AD_HandleTypeDef *haddac,
                                                   uint16_t channel, uint16_t gain, uint16_t buffer, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    // compose data DAC1 DaisyChained
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_ADDR = channel;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_GAIN = gain;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_BUFFER = buffer;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_DATA = value;

    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        haddac->DAC1_ChMemGain.CH_A_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_A_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_A_memValue = value;
        break;
    case AD_DAC_B:
        haddac->DAC1_ChMemGain.CH_B_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_B_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_B_memValue = value;
        break;
    case AD_DAC_C:
        haddac->DAC1_ChMemGain.CH_C_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_C_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_C_memValue = value;
        break;
    case AD_DAC_D:
        haddac->DAC1_ChMemGain.CH_D_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_D_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_D_memValue = value;
        break;
    default:
        break;
    }

    // send data to Daisy Chain DACs
    errorcode = HAL_DAC_TrimOffsetWriteRegister(haddac,
                                                (uint16_t *)&haddac->DAC1DCRegisterMap.DACREG00bits,
                                                (uint16_t *)&haddac->DAC2DCRegisterMap.DACREG00bits, 0xFFFF);

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC2TrimOffset_ModifyParam(AD_HandleTypeDef *haddac,
                                                   uint16_t channel, uint16_t gain, uint16_t buffer, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    // compose data DAC1 DaisyChained
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_ADDR = channel;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_GAIN = gain;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_BUFFER = buffer;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_DATA = value;

    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        haddac->DAC2_ChMemGain.CH_A_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_A_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_A_memValue = value;
        break;
    case AD_DAC_B:
        haddac->DAC2_ChMemGain.CH_B_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_B_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_B_memValue = value;
        break;
    case AD_DAC_C:
        haddac->DAC2_ChMemGain.CH_C_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_C_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_C_memValue = value;
        break;
    case AD_DAC_D:
        haddac->DAC2_ChMemGain.CH_D_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_D_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_D_memValue = value;
        break;
    default:
        break;
    }

    // send data to Daisy Chain DACs
    errorcode = HAL_DAC_TrimOffsetWriteRegister(haddac,
                                                (uint16_t *)&haddac->DAC1DCRegisterMap.DACREG00bits,
                                                (uint16_t *)&haddac->DAC2DCRegisterMap.DACREG00bits, 0xFFFF);

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC1BiasSet_ModifyParam(AD_HandleTypeDef *haddac,
                                                uint16_t channel, uint16_t gain, uint16_t buffer, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    // compose data DAC1 DaisyChained
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_ADDR = channel;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_GAIN = gain;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_BUFFER = buffer;
    haddac->DAC1DCRegisterMap.DACREG00bits.DAC_DATA = value;

    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        haddac->DAC1_ChMemGain.CH_A_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_A_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_A_memValue = value;
        break;
    case AD_DAC_B:
        haddac->DAC1_ChMemGain.CH_B_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_B_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_B_memValue = value;
        break;
    case AD_DAC_C:
        haddac->DAC1_ChMemGain.CH_C_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_C_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_C_memValue = value;
        break;
    case AD_DAC_D:
        haddac->DAC1_ChMemGain.CH_D_memGain = gain;
        haddac->DAC1_ChMemBuffer.CH_D_memBuffer = buffer;
        haddac->DAC1_ChMemValue.CH_D_memValue = value;
        break;
    default:
        break;
    }

    // send data to Daisy Chain DACs
    errorcode = HAL_DAC_BiasSetWriteRegister(haddac,
                                             (uint16_t *)&haddac->DAC1DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC2DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC3DCRegisterMap.DACREG00bits, 0xFFFF);

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC2BiasSet_ModifyParam(AD_HandleTypeDef *haddac,
                                                uint16_t channel, uint16_t gain, uint16_t buffer, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    // compose data DAC1 DaisyChained
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_ADDR = channel;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_GAIN = gain;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_BUFFER = buffer;
    haddac->DAC2DCRegisterMap.DACREG00bits.DAC_DATA = value;

    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        haddac->DAC2_ChMemGain.CH_A_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_A_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_A_memValue = value;
        break;
    case AD_DAC_B:
        haddac->DAC2_ChMemGain.CH_B_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_B_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_B_memValue = value;
        break;
    case AD_DAC_C:
        haddac->DAC2_ChMemGain.CH_C_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_C_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_C_memValue = value;
        break;
    case AD_DAC_D:
        haddac->DAC2_ChMemGain.CH_D_memGain = gain;
        haddac->DAC2_ChMemBuffer.CH_D_memBuffer = buffer;
        haddac->DAC2_ChMemValue.CH_D_memValue = value;
        break;
    default:
        break;
    }

    // send data to Daisy Chain DACs
    errorcode = HAL_DAC_BiasSetWriteRegister(haddac,
                                             (uint16_t *)&haddac->DAC1DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC2DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC3DCRegisterMap.DACREG00bits, 0xFFFF);

    return errorcode;
}

/**
 * @brief  SPI Emul Write Daisy Chained Register DAC
 * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @param  pTxData pointer to transmission data buffer
 * @param  pRxData pointer to reception data buffer
 * @param  Size amount of data to be sent and received
 * @param  Timeout Timeout duration
 * @retval HAL status
 */
HAL_ADStatusTypeDef HAL_DAC3BiasSet_ModifyParam(AD_HandleTypeDef *haddac,
                                                uint16_t channel, uint16_t gain, uint16_t buffer, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;

    // compose data DAC1 DaisyChained
    haddac->DAC3DCRegisterMap.DACREG00bits.DAC_ADDR = channel;
    haddac->DAC3DCRegisterMap.DACREG00bits.DAC_GAIN = gain;
    haddac->DAC3DCRegisterMap.DACREG00bits.DAC_BUFFER = buffer;
    haddac->DAC3DCRegisterMap.DACREG00bits.DAC_DATA = value;

    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        haddac->DAC3_ChMemGain.CH_A_memGain = gain;
        haddac->DAC3_ChMemBuffer.CH_A_memBuffer = buffer;
        haddac->DAC3_ChMemValue.CH_A_memValue = value;
        break;
    case AD_DAC_B:
        haddac->DAC3_ChMemGain.CH_B_memGain = gain;
        haddac->DAC3_ChMemBuffer.CH_B_memBuffer = buffer;
        haddac->DAC3_ChMemValue.CH_B_memValue = value;
        break;
    case AD_DAC_C:
        haddac->DAC3_ChMemGain.CH_C_memGain = gain;
        haddac->DAC3_ChMemBuffer.CH_C_memBuffer = buffer;
        haddac->DAC3_ChMemValue.CH_C_memValue = value;
        break;
    case AD_DAC_D:
        haddac->DAC3_ChMemGain.CH_D_memGain = gain;
        haddac->DAC3_ChMemBuffer.CH_D_memBuffer = buffer;
        haddac->DAC3_ChMemValue.CH_D_memValue = value;
        break;
    default:
        break;
    }

    // send data to Daisy Chain DACs
    errorcode = HAL_DAC_BiasSetWriteRegister(haddac,
                                             (uint16_t *)&haddac->DAC1DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC2DCRegisterMap.DACREG00bits,
                                             (uint16_t *)&haddac->DAC3DCRegisterMap.DACREG00bits, 0xFFFF);

    return errorcode;
}

/* ***************************************************************************************************
 * **** Set data value in DAC output *****************************************************************
 * ***************************************************************************************************/

/* AD DAC1 trim Set value */
HAL_ADStatusTypeDef HAL_DAC1TrimOffset_SetValue(AD_HandleTypeDef *haddac,
                                                uint16_t channel, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint16_t gain, buff;
    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        gain = haddac->DAC1_ChMemGain.CH_A_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_A_memBuffer;
        break;
    case AD_DAC_B:
        gain = haddac->DAC1_ChMemGain.CH_B_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_B_memBuffer;
        break;
    case AD_DAC_C:
        gain = haddac->DAC1_ChMemGain.CH_C_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_C_memBuffer;
        break;
    case AD_DAC_D:
        gain = haddac->DAC1_ChMemGain.CH_D_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_D_memBuffer;
        break;
    default:
        break;
    }

    errorcode = HAL_DAC1TrimOffset_ModifyParam(haddac, channel, gain, buff,
                                               value);

    return errorcode;
}

/* AD DAC2 trim Set value */
HAL_ADStatusTypeDef HAL_DAC2TrimOffset_SetValue(AD_HandleTypeDef *haddac,
                                                uint16_t channel, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint16_t gain, buff;
    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        gain = haddac->DAC2_ChMemGain.CH_A_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_A_memBuffer;
        break;
    case AD_DAC_B:
        gain = haddac->DAC2_ChMemGain.CH_B_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_B_memBuffer;
        break;
    case AD_DAC_C:
        gain = haddac->DAC2_ChMemGain.CH_C_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_C_memBuffer;
        break;
    case AD_DAC_D:
        gain = haddac->DAC2_ChMemGain.CH_D_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_D_memBuffer;
        break;
    default:
        break;
    }

    errorcode = HAL_DAC2TrimOffset_ModifyParam(haddac, channel, gain, buff,
                                               value);

    return errorcode;
}

/* AD DAC1 BiasSet Set value */
HAL_ADStatusTypeDef HAL_DAC1BiasSet_SetValue(AD_HandleTypeDef *haddac,
                                             uint16_t channel, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint16_t gain, buff;
    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        gain = haddac->DAC1_ChMemGain.CH_A_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_A_memBuffer;
        break;
    case AD_DAC_B:
        gain = haddac->DAC1_ChMemGain.CH_B_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_B_memBuffer;
        break;
    case AD_DAC_C:
        gain = haddac->DAC1_ChMemGain.CH_C_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_C_memBuffer;
        break;
    case AD_DAC_D:
        gain = haddac->DAC1_ChMemGain.CH_D_memGain;
        buff = haddac->DAC1_ChMemBuffer.CH_D_memBuffer;
        break;
    default:
        break;
    }

    errorcode = HAL_DAC1BiasSet_ModifyParam(haddac, channel, gain, buff, value);

    return errorcode;
}

/* AD DAC2 BiasSet Set value */
HAL_ADStatusTypeDef HAL_DAC2BiasSet_SetValue(AD_HandleTypeDef *haddac,
                                             uint16_t channel, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint16_t gain, buff;
    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        gain = haddac->DAC2_ChMemGain.CH_A_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_A_memBuffer;
        break;
    case AD_DAC_B:
        gain = haddac->DAC2_ChMemGain.CH_B_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_B_memBuffer;
        break;
    case AD_DAC_C:
        gain = haddac->DAC2_ChMemGain.CH_C_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_C_memBuffer;
        break;
    case AD_DAC_D:
        gain = haddac->DAC2_ChMemGain.CH_D_memGain;
        buff = haddac->DAC2_ChMemBuffer.CH_D_memBuffer;
        break;
    default:
        break;
    }

    errorcode = HAL_DAC2BiasSet_ModifyParam(haddac, channel, gain, buff, value);

    return errorcode;
}

/* AD DAC3 BiasSet Set value */
HAL_ADStatusTypeDef HAL_DAC3BiasSet_SetValue(AD_HandleTypeDef *haddac,
                                             uint16_t channel, uint16_t value)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint16_t gain, buff;
    // update memory DAC configuration
    switch (channel)
    {
    case AD_DAC_A:
        gain = haddac->DAC3_ChMemGain.CH_A_memGain;
        buff = haddac->DAC3_ChMemBuffer.CH_A_memBuffer;
        break;
    case AD_DAC_B:
        gain = haddac->DAC3_ChMemGain.CH_B_memGain;
        buff = haddac->DAC3_ChMemBuffer.CH_B_memBuffer;
        break;
    case AD_DAC_C:
        gain = haddac->DAC3_ChMemGain.CH_C_memGain;
        buff = haddac->DAC3_ChMemBuffer.CH_C_memBuffer;
        break;
    case AD_DAC_D:
        gain = haddac->DAC3_ChMemGain.CH_D_memGain;
        buff = haddac->DAC3_ChMemBuffer.CH_D_memBuffer;
        break;
    default:
        break;
    }

    errorcode = HAL_DAC3BiasSet_ModifyParam(haddac, channel, gain, buff, value);

    return errorcode;
}

/* ---------------------------------------------------------------------------------------- */
/* - SPI DAC OPERATION CONFIG ------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------- */

/* SPIx DAC operation config function */
HAL_ADStatusTypeDef MX_SPI_DAC_OP_Config(SPI_HandleTypeDef *hspi)
{

    HAL_ADStatusTypeDef errorcode = HAL_AD_OK;
    uint32_t temp_State = 0;

    // Configure SPI mode
    hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_RD_MODE, &(hspi->spi_state));
    if (hspi->fileReturn != 0)
    {
        printf("Could not read SPI mode...\r\n");
        fflush(stdout);
        // close(hspi->fileDevice);
        errorcode = HAL_AD_ERROR;
        return (errorcode);
    }

    temp_State = hspi->spi_state; // Evaluation of the mode
    hspi->spi_state = SPI_MODE_2; // CPHA = 0; CPOL = 1;

    if (hspi->spi_state != temp_State)
    {
        // Comment this line
        // printf("Configuring SPI MODE_2, Previous = %d, New = %d \n", temp_State, hspi->spi_state);

        hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_WR_MODE, &(hspi->spi_state));
        if (hspi->fileReturn != 0)
        {
            printf("Could not write SPI mode...\r\n");
            fflush(stdout);
            // close(hspi->fileDevice);
            errorcode = HAL_AD_ERROR;
            return (errorcode);
        }
    }
    // else
    // {
    //     // Comment this line
    //     printf("SPI MODE_2 configured\n");
    // }

    return (errorcode);
}
