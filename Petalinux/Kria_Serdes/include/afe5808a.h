/**
 ******************************************************************************
 * @file    afe5808a.h
 * @author  Fabian Castano
 * @brief   This file contains all the structures and register
 *          map address for the afe5808a SoC
 ******************************************************************************
 */

#ifndef INC_AFE5808A_H_
#define INC_AFE5808A_H_

/* Includes ------------------------------------------------------------------*/
/**
 * @brief  HAL Status structures definition
 */
typedef enum
{
    HAL_AFE_OK = 0x00U,
    HAL_AFE_ERROR = 0x01U,
    HAL_AFE_BUSY = 0x02U,
    HAL_AFE_TIMEOUT = 0x03U
} HAL_AFEStatusTypeDef;

/* Memory Map ----------------------------------------------------------------*/
/* ADC Memory Map */
typedef enum
{
    AFE_REG00 = 0x00, // REGISTER 00
    AFE_REG01 = 0x01, // REGISTER 01
    AFE_REG02 = 0x02, // REGISTER 02
    AFE_REG03 = 0x03, // REGISTER 03
    AFE_REG04 = 0x04, // REGISTER 04
    AFE_REG05 = 0x05, // REGISTER 05
    AFE_REG10 = 0x0A, // REGISTER 10
    AFE_REG13 = 0x0D, // REGISTER 13
    AFE_REG15 = 0x0F, // REGISTER 15
    AFE_REG17 = 0x11, // REGISTER 17
    AFE_REG19 = 0x13, // REGISTER 19
    AFE_REG21 = 0x15, // REGISTER 21
    AFE_REG25 = 0x19, // REGISTER 25
    AFE_REG27 = 0x1B, // REGISTER 27
    AFE_REG29 = 0x1D, // REGISTER 29
    AFE_REG31 = 0x1F, // REGISTER 31
    AFE_REG33 = 0x21, // REGISTER 33
    AFE_REG66 = 0x42, // REGISTER 66
} AFE_ADC_REG_MAP_ADDR;

/* VCA Memory Map */
typedef enum
{
    AFE_REG50 = 0x32, // REGISTER 50
    AFE_REG51 = 0x33, // REGISTER 51
    AFE_REG52 = 0x34, // REGISTER 52
    AFE_REG53 = 0x35, // REGISTER 53
    AFE_REG54 = 0x36, // REGISTER 54
    AFE_REG55 = 0x37, // REGISTER 55
    AFE_REG56 = 0x38, // REGISTER 56
    AFE_REG57 = 0x39, // REGISTER 57
    AFE_REG59 = 0x3B, // REGISTER 59
} AFE_VCA_REG_MAP_ADDR;

/* ADC Bit Mnemonics ---------------------------------------------------------*/
// REG0
typedef struct tagREG00BITS
{
    union
    {
        struct
        {
            uint16_t SOFTWARE_RESET : 1;
            uint16_t REGISTER_READOUT_ENABLE : 1;
            uint16_t : 14;
        };
        struct
        {
            uint16_t : 16;
        };
    };
} REG00BITS;

// REG01
typedef struct tagREG01BITS
{
    union
    {
        struct
        {
            uint16_t ADC_COMPLETE_PDN : 1;
            uint16_t LVDS_OUTPUT_DISABLE : 1;
            uint16_t ADC_PDN_CH : 8;
            uint16_t PARTIAL_PDN : 1;
            uint16_t LOW_FREQUENCY_NOISE_SUPPRESSION : 1;
            uint16_t : 1;
            uint16_t EXT_REF : 1; // if 1, requires 3[15] in 1 too
            uint16_t LVDS_OUTPUT_RATE_2X : 1;
            uint16_t SINGLE_ENDED_CLK_MODE : 1;
        };
        struct
        {
            uint16_t : 2;
            uint16_t ADC_PDN_CH1 : 1;
            uint16_t ADC_PDN_CH2 : 1;
            uint16_t ADC_PDN_CH3 : 1;
            uint16_t ADC_PDN_CH4 : 1;
            uint16_t ADC_PDN_CH5 : 1;
            uint16_t ADC_PDN_CH6 : 1;
            uint16_t ADC_PDN_CH7 : 1;
            uint16_t ADC_PDN_CH8 : 1;
            uint16_t : 6;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG01BITS;

// REG02
typedef struct tagREG02BITS
{
    union
    {
        struct
        {
            uint16_t : 3;
            uint16_t POWER_DOWN_LVDS : 8;
            uint16_t AVERAGING_ENABLE : 1;
            uint16_t LOW_LATENCY : 1;
            uint16_t TEST_PATTERN_MODES : 3;
        };
        struct
        {
            uint16_t : 3;
            uint16_t POWER_DOWN_LVDS_CH1 : 1;
            uint16_t POWER_DOWN_LVDS_CH2 : 1;
            uint16_t POWER_DOWN_LVDS_CH3 : 1;
            uint16_t POWER_DOWN_LVDS_CH4 : 1;
            uint16_t POWER_DOWN_LVDS_CH5 : 1;
            uint16_t POWER_DOWN_LVDS_CH6 : 1;
            uint16_t POWER_DOWN_LVDS_CH7 : 1;
            uint16_t POWER_DOWN_LVDS_CH8 : 1;
            uint16_t : 5;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG02BITS;

// REG03
typedef struct tagREG03BITS
{
    union
    {
        struct
        {
            uint16_t INVERT_CHANNELS : 8;
            uint16_t CHANNEL_OFFSET_SUBSTRACTION_ENABLE : 1;
            uint16_t : 3;
            uint16_t DIGITAL_GAIN_ENABLE : 1;
            uint16_t SERIALIZED_DATA_RATE : 2;
            uint16_t ENABLE_EXTERNAL_REFERENCE_MODE : 1;
        };
        struct
        {
            uint16_t INVERT_CHANNELS_CH1 : 1;
            uint16_t INVERT_CHANNELS_CH2 : 1;
            uint16_t INVERT_CHANNELS_CH3 : 1;
            uint16_t INVERT_CHANNELS_CH4 : 1;
            uint16_t INVERT_CHANNELS_CH5 : 1;
            uint16_t INVERT_CHANNELS_CH6 : 1;
            uint16_t INVERT_CHANNELS_CH7 : 1;
            uint16_t INVERT_CHANNELS_CH8 : 1;
            uint16_t : 8;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG03BITS;

// REG04
typedef struct tagREG04BITS
{
    union
    {
        struct
        {
            uint16_t : 1;
            uint16_t ADC_RESOLUTION_SELECT : 1;
            uint16_t : 1;
            uint16_t ADC_OUTPUT_FORMAT : 1;
            uint16_t LSB_MSB_FIRST : 1;
            uint16_t : 11;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG04BITS;

// REG05
typedef struct tagREG05BITS
{
    union
    {
        struct
        {
            uint16_t CUSTOM_PATTERN : 14;
            uint16_t : 2;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG05BITS;

// REG10
typedef struct tagREG10BITS
{
    union
    {
        struct
        {
            uint16_t : 8;
            uint16_t SYNC_PATTERN : 1;
            uint16_t : 7;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG10BITS;

// REG13
typedef struct tagREG13BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH1 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH1 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG13BITS;

// REG15
typedef struct tagREG15BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH2 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH2 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG15BITS;

// REG17
typedef struct tagREG17BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH3 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH3 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG17BITS;

// REG19
typedef struct tagREG19BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH4 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH4 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG19BITS;

// REG21
typedef struct tagREG21BITS
{
    union
    {
        struct
        {
            uint16_t DIGITAL_HPF_FILTER_ENABLE_CH1_4 : 1;
            uint16_t DIGITAL_HPF_FILTER_K_CH1_4 : 4;
            uint16_t : 11;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG21BITS;

// REG25
typedef struct tagREG25BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH8 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH8 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG25BITS;

// REG27
typedef struct tagREG27BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH7 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH7 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG27BITS;

// REG29
typedef struct tagREG29BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH6 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH6 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG29BITS;

// REG31
typedef struct tagREG31BITS
{
    union
    {
        struct
        {
            uint16_t OFFSET_CH5 : 10;
            uint16_t : 1;
            uint16_t DIGITAL_GAIN_CH5 : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG31BITS;

// REG33
typedef struct tagREG33BITS
{
    union
    {
        struct
        {
            uint16_t DIGITAL_HPF_FILTER_ENABLE_CH5_8 : 1;
            uint16_t DIGITAL_HPF_FILTER_K_CH5_8 : 4;
            uint16_t : 11;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG33BITS;

// REG66
typedef struct tagREG66BITS
{
    union
    {
        struct
        {
            uint16_t : 15;
            uint16_t DITHER : 1;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG66BITS;

/* VCA Bit Mnemonics ---------------------------------------------------------*/
// REG50
typedef struct tagREG50BITS
{
    union
    {
        struct
        {
            uint16_t : 10;
            uint16_t PGA_CLAMP_m6dB : 1;
            uint16_t : 5;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG50BITS;

// REG51
typedef struct tagREG51BITS
{
    union
    {
        struct
        {
            uint16_t : 1;
            uint16_t LPF_PROGRAMMABILITY : 3;
            uint16_t PGA_INTEGRATOR_DISABLE : 1;
            uint16_t PGA_CLAMP_LEVEL : 3;
            uint16_t : 5;
            uint16_t PGA_GAIN_CONTROL : 1;
            uint16_t : 2;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG51BITS;

// REG52
typedef struct tagREG52BITS
{
    union
    {
        struct
        {
            uint16_t ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_CNTL : 5;
            uint16_t ACTIVE_TERMINATION_INDIVIDUAL_RESISTOR_ENABLE : 1;
            uint16_t PRESET_ACTIVE_TERMINATIONS : 2;
            uint16_t ACTIVE_TERMINATION_ENABLE : 1;
            uint16_t LNA_INPUT_CLAMP_SETTING : 2;
            uint16_t : 1;
            uint16_t LNA_INTEGRATOR_DISABLE : 1;
            uint16_t LNA_GAIN : 2;
            uint16_t LNA_INDIVIDUAL_CH_CNTL : 1;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG52BITS;

// REG53
typedef struct tagREG53BITS
{
    union
    {
        struct
        {
            uint16_t PDN_CH : 8;
            uint16_t : 2;
            uint16_t LOW_POWER : 1;
            uint16_t MED_POWER : 1;
            uint16_t PDN_VCAT_PGA : 1;
            uint16_t PDN_LNA : 1;
            uint16_t VCA_PARTIAL_PDN : 1;
            uint16_t VCA_COMPLETE_PDN : 1;
        };
        struct
        {
            uint16_t PDN_CH1 : 1;
            uint16_t PDN_CH2 : 1;
            uint16_t PDN_CH3 : 1;
            uint16_t PDN_CH4 : 1;
            uint16_t PDN_CH5 : 1;
            uint16_t PDN_CH6 : 1;
            uint16_t PDN_CH7 : 1;
            uint16_t PDN_CH8 : 1;
            uint16_t : 8;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG53BITS;

// REG54
typedef struct tagREG54BITS
{
    union
    {
        struct
        {
            uint16_t CW_SUM_AMP_GAIN_CNTL : 5;
            uint16_t CW_16X_CLK_SEL : 1;
            uint16_t CW_1X_CLK_SEL : 1;
            uint16_t : 1;
            uint16_t CW_TGC_SEL : 1;
            uint16_t CW_SUM_AMP_ENABLE : 1;
            uint16_t CW_CLK_MODE_SEL : 2;
            uint16_t : 4;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG54BITS;

// REG55
typedef struct tagREG55BITS
{
    union
    {
        struct
        {
            uint16_t CH1_CW_MIXER_PHASE : 4;
            uint16_t CH2_CW_MIXER_PHASE : 4;
            uint16_t CH3_CW_MIXER_PHASE : 4;
            uint16_t CH4_CW_MIXER_PHASE : 4;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG55BITS;

// REG56
typedef struct tagREG56BITS
{
    union
    {
        struct
        {
            uint16_t CH5_CW_MIXER_PHASE : 4;
            uint16_t CH6_CW_MIXER_PHASE : 4;
            uint16_t CH7_CW_MIXER_PHASE : 4;
            uint16_t CH8_CW_MIXER_PHASE : 4;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG56BITS;

// REG57
typedef struct tagREG57BITS
{
    union
    {
        struct
        {
            uint16_t CH1_LNA_GAIN_CNTL : 2;
            uint16_t CH2_LNA_GAIN_CNTL : 2;
            uint16_t CH3_LNA_GAIN_CNTL : 2;
            uint16_t CH4_LNA_GAIN_CNTL : 2;
            uint16_t CH5_LNA_GAIN_CNTL : 2;
            uint16_t CH6_LNA_GAIN_CNTL : 2;
            uint16_t CH7_LNA_GAIN_CNTL : 2;
            uint16_t CH8_LNA_GAIN_CNTL : 2;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG57BITS;

// REG59
typedef struct tagREG59BITS
{
    union
    {
        struct
        {
            uint16_t : 2;
            uint16_t HPF_LNA : 2;
            uint16_t DIG_TGC_ATT_GAIN : 3;
            uint16_t DIG_TGC_ATT : 1;
            uint16_t CW_SUM_AMP_PDN : 1;
            uint16_t PGA_TEST_MODE : 1;
            uint16_t : 6;
        };
        struct
        {
            uint16_t : 16;
        };
        struct
        {
            uint16_t VALUE : 16;
        };
    };
} REG59BITS;

/* Instruction Mnemonics -----------------------------------------------------*/
// REG0
#define READ_ENABLE 1  // operation to read register
#define WRITE_ENABLE 0 // operation to write register

// REG2 - TEST_PATTERN_MODES
#define R2_TPM_NORMAL_OP 0b000
#define R2_TPM_SYNC 0b001
#define R2_TPM_DE_SKEW 0b010
#define R2_TPM_CUSTOM 0b011
#define R2_TPM_ALL_1S 0b100
#define R2_TPM_TOGGLE 0b101
#define R2_TPM_ALL_0S 0b110
#define R2_TPM_RAMP 0b111

// REG3 - SERIALIZED_DATA_RATE
#define R3_SDR_14X 0b00
#define R3_SDR_16X 0b01
#define R3_SDR_12X 0b11

// REG4 - ADC_RESOLUTION_SELECT
#define R4_ARS_14bits 0
#define R4_ARS_12bits 1
//      - LSB_MSB_FIRST
#define R4_LMF_LSB 0
#define R4_LMF_MSB 1

// REG51 - LPF_PROGRAMABILITY
#define R51_LP_15MHz 0b000
#define R51_LP_20MHz 0b010
#define R51_LP_30MHz 0b011
#define R51_LP_10MHz 0b100

// REG52 - PRESET_ASCTIVE_TERMINATIONS
#define R52_PAT_50OHM 0b00
#define R52_PAT_100OHM 0b01
#define R52_PAT_200OHM 0b10
#define R52_PAT_400OHM 0b11
//       - LNA_INPUT_CLAMP_SETTING
#define R52_LIC_AUTO 0b00
#define R52_LIC_1_5V 0b01
#define R52_LIC_1_15V 0b10
#define R52_LIC_0_6V 0b11
//       - LNA_GAIN
#define R52_LG_18db 0b00
#define R52_LG_24db 0b01
#define R52_LG_12db 0b10

// REG54 - CW_CLK_MODE_SEL
#define R54_CMS_16X 0b00
#define R54_CMS_8X 0b01
#define R54_CMS_4X 0b10
#define R54_CMS_1X 0b11

// REG57 - CHx_LNA_GAIN_CNTL
#define R57_CLG_18dB 0b00
#define R57_CLG_24dB 0b01
#define R57_CLG_12dB 0b10

/* TYPEDEF HAL_AFE Register Map --------------------------------------------------*/
/**
 * @brief  REGISTER_MAP for ADC AFE5808A
 */
typedef struct __AFE_ADCRegisterMap
{
    REG00BITS REG00bits; /*!< AFE REG00 Memory Map def */
    REG01BITS REG01bits; /*!< AFE REG01 Memory Map def */
    REG02BITS REG02bits; /*!< AFE REG02 Memory Map def */
    REG03BITS REG03bits; /*!< AFE REG03 Memory Map def */
    REG04BITS REG04bits; /*!< AFE REG04 Memory Map def */
    REG05BITS REG05bits; /*!< AFE REG05 Memory Map def */
    REG10BITS REG10bits; /*!< AFE REG10 Memory Map def */
    REG13BITS REG13bits; /*!< AFE REG13 Memory Map def */
    REG15BITS REG15bits; /*!< AFE REG15 Memory Map def */
    REG17BITS REG17bits; /*!< AFE REG17 Memory Map def */
    REG19BITS REG19bits; /*!< AFE REG19 Memory Map def */
    REG21BITS REG21bits; /*!< AFE REG21 Memory Map def */
    REG25BITS REG25bits; /*!< AFE REG25 Memory Map def */
    REG27BITS REG27bits; /*!< AFE REG27 Memory Map def */
    REG29BITS REG29bits; /*!< AFE REG29 Memory Map def */
    REG31BITS REG31bits; /*!< AFE REG31 Memory Map def */
    REG33BITS REG33bits; /*!< AFE REG33 Memory Map def */
    REG66BITS REG66bits; /*!< AFE REG66 Memory Map def */
} AFE_ADCRegisterMap;

/**
 * @brief  REGISTER_MAP for VCA AFE5808A
 */
typedef struct __AFE_VCARegisterMap
{
    REG50BITS REG50bits; /*!< AFE REG50 Memory Map def */
    REG51BITS REG51bits; /*!< AFE REG51 Memory Map def */
    REG52BITS REG52bits; /*!< AFE REG52 Memory Map def */
    REG53BITS REG53bits; /*!< AFE REG53 Memory Map def */
    REG54BITS REG54bits; /*!< AFE REG54 Memory Map def */
    REG55BITS REG55bits; /*!< AFE REG55 Memory Map def */
    REG56BITS REG56bits; /*!< AFE REG56 Memory Map def */
    REG57BITS REG57bits; /*!< AFE REG57 Memory Map def */
    REG59BITS REG59bits; /*!< AFE REG59 Memory Map def */
} AFE_VCARegisterMap;

#endif /* INC_AFE5808A_H_ */
