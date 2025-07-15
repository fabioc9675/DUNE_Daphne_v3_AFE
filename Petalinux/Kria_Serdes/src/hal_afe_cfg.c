/**
 ******************************************************************************
 * @file    hal_afe_cfg.c
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the hal_afe_cfg.c file
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hal_afe_cfg.h"

/* Extern Handle -------------------------------------------------------------*/
extern AFE_HandleTypeDef hafe0;
extern AFE_HandleTypeDef hafe1;
extern AFE_HandleTypeDef hafe2;
extern AFE_HandleTypeDef hafe3;
extern AFE_HandleTypeDef hafe4;

extern AD_HandleTypeDef hdac_trimAfe0;
extern AD_HandleTypeDef hdac_trimAfe1;
extern AD_HandleTypeDef hdac_trimAfe2;
extern AD_HandleTypeDef hdac_trimAfe3;
extern AD_HandleTypeDef hdac_trimAfe4;

extern AD_HandleTypeDef hdac_offsAfe0;
extern AD_HandleTypeDef hdac_offsAfe1;
extern AD_HandleTypeDef hdac_offsAfe2;
extern AD_HandleTypeDef hdac_offsAfe3;
extern AD_HandleTypeDef hdac_offsAfe4;

/* Prototype -----------------------------------------------------------------*/
/* AFE Test configuration */
HAL_AFEStatusTypeDef HAL_AFE_TestConfig(AFE_HandleTypeDef *hafe)
{
    // configuration make according to datasheet, see page 46 in
    // https://www.ti.com/lit/ds/symlink/afe5808a.pdf

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    return errorcode;
}

/* AFE initial configuration */
HAL_AFEStatusTypeDef HAL_AFE_InitialConfig(AFE_HandleTypeDef *hafe)
{
    // configuration make according to datasheet, see page 46 in
    // https://www.ti.com/lit/ds/symlink/afe5808a.pdf

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Configuration ADC
    /* REG 00 */
    hafe->ADCRegisterMap.REG00bits.SOFTWARE_RESET = 0;
    hafe->ADCRegisterMap.REG00bits.REGISTER_READOUT_ENABLE = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG00,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG00bits);

    /* REG 01 */
    hafe->ADCRegisterMap.REG01bits.ADC_COMPLETE_PDN = 0;
    hafe->ADCRegisterMap.REG01bits.LVDS_OUTPUT_DISABLE = 0;
    hafe->ADCRegisterMap.REG01bits.ADC_PDN_CH = 0;
    hafe->ADCRegisterMap.REG01bits.PARTIAL_PDN = 0;
    hafe->ADCRegisterMap.REG01bits.LOW_FREQUENCY_NOISE_SUPPRESSION = 0;
    hafe->ADCRegisterMap.REG01bits.EXT_REF = 0;
    hafe->ADCRegisterMap.REG01bits.LVDS_OUTPUT_RATE_2X = 0;
    hafe->ADCRegisterMap.REG01bits.SINGLE_ENDED_CLK_MODE = 1;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG01,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG01bits);

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.POWER_DOWN_LVDS = 0;
    hafe->ADCRegisterMap.REG02bits.AVERAGING_ENABLE = 0;
    hafe->ADCRegisterMap.REG02bits.LOW_LATENCY = 0;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = 0;
    hafe->ADCRegisterMap.REG02bits.POWER_DOWN_LVDS = R2_TPM_NORMAL_OP;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    /* REG 03 */
    hafe->ADCRegisterMap.REG03bits.INVERT_CHANNELS = 0;
    hafe->ADCRegisterMap.REG03bits.CHANNEL_OFFSET_SUBSTRACTION_ENABLE = 0;
    hafe->ADCRegisterMap.REG03bits.DIGITAL_GAIN_ENABLE = 0;
    hafe->ADCRegisterMap.REG03bits.SERIALIZED_DATA_RATE = R3_SDR_14X;
    hafe->ADCRegisterMap.REG03bits.ENABLE_EXTERNAL_REFERENCE_MODE = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG03,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG03bits);

    /* REG 04 */
    hafe->ADCRegisterMap.REG04bits.ADC_RESOLUTION_SELECT = R4_ARS_14bits;
    hafe->ADCRegisterMap.REG04bits.ADC_OUTPUT_FORMAT = 0;
    hafe->ADCRegisterMap.REG04bits.LSB_MSB_FIRST = R4_LMF_LSB;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG04,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG04bits);

    /* REG 05 */
    hafe->ADCRegisterMap.REG05bits.CUSTOM_PATTERN = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG05,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG05bits);

    /* REG 10 */
    hafe->ADCRegisterMap.REG10bits.SYNC_PATTERN = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG10,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG10bits);

    /* REG 13 */
    hafe->ADCRegisterMap.REG13bits.OFFSET_CH1 = 0;
    hafe->ADCRegisterMap.REG13bits.DIGITAL_GAIN_CH1 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG13,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG13bits);

    /* REG 15 */
    hafe->ADCRegisterMap.REG15bits.OFFSET_CH2 = 0;
    hafe->ADCRegisterMap.REG15bits.DIGITAL_GAIN_CH2 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG15,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG15bits);

    /* REG 17 */
    hafe->ADCRegisterMap.REG17bits.OFFSET_CH3 = 0;
    hafe->ADCRegisterMap.REG17bits.DIGITAL_GAIN_CH3 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG17,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG17bits);

    /* REG 19 */
    hafe->ADCRegisterMap.REG19bits.OFFSET_CH4 = 0;
    hafe->ADCRegisterMap.REG19bits.DIGITAL_GAIN_CH4 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG19,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG19bits);

    /* REG 21 */
    hafe->ADCRegisterMap.REG21bits.DIGITAL_HPF_FILTER_ENABLE_CH1_4 = 0;
    hafe->ADCRegisterMap.REG21bits.DIGITAL_HPF_FILTER_K_CH1_4 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG21,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG21bits);

    /* REG 25 */
    hafe->ADCRegisterMap.REG25bits.OFFSET_CH8 = 0;
    hafe->ADCRegisterMap.REG25bits.DIGITAL_GAIN_CH8 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG25,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG25bits);

    /* REG 27 */
    hafe->ADCRegisterMap.REG27bits.OFFSET_CH7 = 0;
    hafe->ADCRegisterMap.REG27bits.DIGITAL_GAIN_CH7 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG27,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG27bits);

    /* REG 29 */
    hafe->ADCRegisterMap.REG29bits.OFFSET_CH6 = 0;
    hafe->ADCRegisterMap.REG29bits.DIGITAL_GAIN_CH6 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG29,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG29bits);

    /* REG 31 */
    hafe->ADCRegisterMap.REG31bits.OFFSET_CH5 = 0;
    hafe->ADCRegisterMap.REG31bits.DIGITAL_GAIN_CH5 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG31,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG31bits);

    /* REG 33 */
    hafe->ADCRegisterMap.REG33bits.DIGITAL_HPF_FILTER_ENABLE_CH5_8 = 0;
    hafe->ADCRegisterMap.REG33bits.DIGITAL_HPF_FILTER_K_CH5_8 = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG33,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG33bits);

    /* REG 66 */
    hafe->ADCRegisterMap.REG66bits.DITHER = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG66,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG66bits);

    // Configuration VCA
    /* REG 50 */
    hafe->VCARegisterMap.REG50bits.PGA_CLAMP_m6dB = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG50,
                                     (uint16_t *)&hafe->VCARegisterMap.REG50bits);

    /* REG 51 */
    hafe->VCARegisterMap.REG51bits.LPF_PROGRAMMABILITY = R51_LP_15MHz;
    hafe->VCARegisterMap.REG51bits.PGA_INTEGRATOR_DISABLE = 0;
    hafe->VCARegisterMap.REG51bits.PGA_CLAMP_LEVEL = 0;
    hafe->VCARegisterMap.REG51bits.PGA_GAIN_CONTROL = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG51,
                                     (uint16_t *)&hafe->VCARegisterMap.REG51bits);

    /* REG 52 */
    hafe->VCARegisterMap.REG52bits.ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_CNTL =
        0;
    hafe->VCARegisterMap.REG52bits.ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_ENABLE =
        0;
    hafe->VCARegisterMap.REG52bits.PRESET_ACTIVE_TERMINATIONS = R52_PAT_50OHM;
    hafe->VCARegisterMap.REG52bits.ACTIVE_TERMINATION_ENABLE = 0;
    hafe->VCARegisterMap.REG52bits.LNA_INPUT_CLAMP_SETTING = R52_LIC_AUTO;
    // hafe->VCARegisterMap.REG52bits.LNA_INTEGRATOR_DISABLE = 1; //DC offset correction = OFF (BIT 12)
    hafe->VCARegisterMap.REG52bits.LNA_INTEGRATOR_DISABLE = 0;
    hafe->VCARegisterMap.REG52bits.LNA_GAIN = R52_LG_18db;
    hafe->VCARegisterMap.REG52bits.LNA_INDIVIDUAL_CH_CNTL = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG52,
                                     (uint16_t *)&hafe->VCARegisterMap.REG52bits);

    /* REG 53 */
    hafe->VCARegisterMap.REG53bits.PDN_CH = 0;
    hafe->VCARegisterMap.REG53bits.LOW_POWER = 0;
    hafe->VCARegisterMap.REG53bits.MED_POWER = 0;
    hafe->VCARegisterMap.REG53bits.PDN_VCAT_PGA = 0;
    hafe->VCARegisterMap.REG53bits.PDN_LNA = 0;
    hafe->VCARegisterMap.REG53bits.VCA_PARTIAL_PDN = 0;
    hafe->VCARegisterMap.REG53bits.VCA_COMPLETE_PDN = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG53,
                                     (uint16_t *)&hafe->VCARegisterMap.REG53bits);

    /* REG 54 */
    hafe->VCARegisterMap.REG54bits.CW_SUM_AMP_GAIN_CNTL = 0;
    hafe->VCARegisterMap.REG54bits.CW_16X_CLK_SEL = 0;
    hafe->VCARegisterMap.REG54bits.CW_1X_CLK_SEL = 0;
    hafe->VCARegisterMap.REG54bits.CW_TGC_SEL = 0;
    hafe->VCARegisterMap.REG54bits.CW_SUM_AMP_ENABLE = 0;
    hafe->VCARegisterMap.REG54bits.CW_CLK_MODE_SEL = R54_CMS_16X;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG54,
                                     (uint16_t *)&hafe->VCARegisterMap.REG54bits);

    /* REG 55 */
    hafe->VCARegisterMap.REG55bits.CH1_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG55bits.CH2_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG55bits.CH3_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG55bits.CH4_CW_MIXER_PHASE = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG55,
                                     (uint16_t *)&hafe->VCARegisterMap.REG55bits);

    /* REG 56 */
    hafe->VCARegisterMap.REG56bits.CH5_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG56bits.CH6_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG56bits.CH7_CW_MIXER_PHASE = 0;
    hafe->VCARegisterMap.REG56bits.CH8_CW_MIXER_PHASE = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG56,
                                     (uint16_t *)&hafe->VCARegisterMap.REG56bits);

    /* REG 57 */
    hafe->VCARegisterMap.REG57bits.CH1_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH2_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH3_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH4_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH5_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH6_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH7_LNA_GAIN_CNTL = R57_CLG_18dB;
    hafe->VCARegisterMap.REG57bits.CH8_LNA_GAIN_CNTL = R57_CLG_18dB;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG57,
                                     (uint16_t *)&hafe->VCARegisterMap.REG57bits);

    /* REG 59 */
    hafe->VCARegisterMap.REG59bits.HPF_LNA = 0;
    hafe->VCARegisterMap.REG59bits.DIG_TGC_ATT_GAIN = 0;
    hafe->VCARegisterMap.REG59bits.DIG_TGC_ATT = 0;
    hafe->VCARegisterMap.REG59bits.CW_SUM_AMP_PDN = 0;
    hafe->VCARegisterMap.REG59bits.PGA_TEST_MODE = 0;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG59,
                                     (uint16_t *)&hafe->VCARegisterMap.REG59bits);

    return errorcode;
}

/* AFE Software Reset configuration */
HAL_AFEStatusTypeDef HAL_AFE_ResetConfig(AFE_HandleTypeDef *hafe)
{
    // Sequence to produce software reset
    // afe5808a EVM software

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    //	hafe->ADCRegisterMap.REG04bits.ADC_OUTPUT_FORMAT = 1;
    //	hafe->ADCRegisterMap.REG04bits.LSB_MSB_FIRST = 1;
    hafe->ADCRegisterMap.REG04bits.VALUE = 0x18;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG04,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG04bits);

    //	hafe->VCARegisterMap.REG59bits.CW_SUM_AMP_PDN = 1;
    hafe->VCARegisterMap.REG59bits.VALUE = 0x100;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG59,
                                     (uint16_t *)&hafe->VCARegisterMap.REG59bits);

    hafe->ADCRegisterMap.REG01bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG01,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG01bits);

    hafe->VCARegisterMap.REG57bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG57,
                                     (uint16_t *)&hafe->VCARegisterMap.REG57bits);

    hafe->ADCRegisterMap.REG01bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG01,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG01bits);

    hafe->ADCRegisterMap.REG01bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG01,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG01bits);

    hafe->ADCRegisterMap.REG03bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG03,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG03bits);

    hafe->VCARegisterMap.REG53bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG53,
                                     (uint16_t *)&hafe->VCARegisterMap.REG53bits);

    hafe->ADCRegisterMap.REG03bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG03,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG03bits);

    hafe->ADCRegisterMap.REG03bits.VALUE = 0x00;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG03,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG03bits);

    //	hafe->ADCRegisterMap.REG04bits.ADC_OUTPUT_FORMAT = 1;
    //	hafe->ADCRegisterMap.REG04bits.LSB_MSB_FIRST = 1;
    hafe->ADCRegisterMap.REG04bits.VALUE = 0x18;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG04,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG04bits);

    return errorcode;
}

/** *********************************************************************
 ** **** TEST CONFIGURATION FUNCTIONS ***********************************
 ** *********************************************************************/

/* AFE Ramp test configuration */
HAL_AFEStatusTypeDef HAL_AFE_RampTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_RAMP;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE Sync test configuration */
HAL_AFEStatusTypeDef HAL_AFE_SyncTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_SYNC;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE Skew test configuration */
HAL_AFEStatusTypeDef HAL_AFE_SkewTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_DE_SKEW;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE Custom test configuration */
HAL_AFEStatusTypeDef HAL_AFE_CustomTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_CUSTOM;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE All 1s test configuration */
HAL_AFEStatusTypeDef HAL_AFE_All1sTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_ALL_1S;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE Toggle test configuration */
HAL_AFEStatusTypeDef HAL_AFE_ToggleTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_TOGGLE;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}

/* AFE All 0s test configuration */
HAL_AFEStatusTypeDef HAL_AFE_All0sTest(AFE_HandleTypeDef *hafe)
{
    // put ramp generator in AFE output

    HAL_AFEStatusTypeDef errorcode = HAL_AFE_OK;

    // Software Reset AFE
    errorcode = HAL_AFE_ResetConfig(hafe);

    // Configuration ADC

    /* REG 02 */
    hafe->ADCRegisterMap.REG02bits.VALUE = 0x0000;
    hafe->ADCRegisterMap.REG02bits.TEST_PATTERN_MODES = R2_TPM_ALL_0S;
    errorcode = HAL_AFEWriteRegister(hafe, AFE_REG02,
                                     (uint16_t *)&hafe->ADCRegisterMap.REG02bits);

    return errorcode;
}
