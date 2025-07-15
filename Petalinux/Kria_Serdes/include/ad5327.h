/**
 ******************************************************************************
 * @file    ad5327.h
 * @author  Fabian Castano
 * @brief   This file contains all the structures and register
 *          map address for the ad5327 SoC
 ******************************************************************************
 */

#ifndef INC_AD5327_H_
#define INC_AD5327_H_

/* Includes ------------------------------------------------------------------*/
/**
 * @brief  HAL Status structures definition
 */
typedef enum
{
    HAL_AD_OK = 0x00U,
    HAL_AD_ERROR = 0x01U,
    HAL_AD_BUSY = 0x02U,
    HAL_AD_TIMEOUT = 0x03U
} HAL_ADStatusTypeDef;

/* Memory Map ----------------------------------------------------------------*/
/* DAC Memory Map */
typedef enum
{
    AD_DAC_A = 0b00, // DAC A Channel
    AD_DAC_B = 0b01, // DAC B Channel
    AD_DAC_C = 0b10, // DAC C Channel
    AD_DAC_D = 0b11  // DAC D Channel
} AD_DAC_REG_MAP_ADDR;

/* DAC Bit Mnemonics ---------------------------------------------------------*/
// REG0
typedef struct tagDACREG00BITS
{
    union
    {
        struct
        {
            uint16_t DAC_DATA : 12;
            uint16_t DAC_BUFFER : 1;
            uint16_t DAC_GAIN : 1;
            uint16_t DAC_ADDR : 2;
        };
        struct
        {
            uint16_t : 16;
        };
    };
} DACREG00BITS;

// Struct to save the Channel value
typedef struct tagDACCHVALUE
{
    uint16_t CH_A_memValue;
    uint16_t CH_B_memValue;
    uint16_t CH_C_memValue;
    uint16_t CH_D_memValue;
} DAC_CHVALUE;

// Struct to save the Channel Gain
typedef struct tagDACCHGAIN
{
    uint16_t CH_A_memGain;
    uint16_t CH_B_memGain;
    uint16_t CH_C_memGain;
    uint16_t CH_D_memGain;
} DAC_CHGAIN;

// Struct to save the Channel Buffer
typedef struct tagDACCHBUFFER
{
    uint16_t CH_A_memBuffer;
    uint16_t CH_B_memBuffer;
    uint16_t CH_C_memBuffer;
    uint16_t CH_D_memBuffer;
} DAC_CHBUFFER;

/* Instruction Mnemonics -----------------------------------------------------*/
// REG00
#define AD_REF_UNBUFFERED 0
#define AD_REF_BUFFERED 1

#define AD_GAIN_VREF 0
#define AD_GAIN_2VREF 1

/* TYPEDEF HAL_AFE Register Map --------------------------------------------------*/
/**
 * @brief  REGISTER_MAP for ADC AFE5808A
 */
typedef struct __AD_DACRegisterMap
{
    DACREG00BITS DACREG00bits; /*!< DAC REG00 Memory Map def */
} AD_DACRegisterMap;

#endif /* INC_AD5327_H_ */
