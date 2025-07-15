/**
 ******************************************************************************
 * @file    hal_spi.h
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the spi.c file
 ******************************************************************************
 */

#ifndef __HAL_SPI_H__
#define __HAL_SPI_H__

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

/* Variables -----------------------------------------------------------------*/

/* TypeDef ------------------------------------------------------------------*/
#define FALSE 0
#define TRUE 1

#define LOW_STATE 0
#define HIGH_STATE 1

/* TYPEDEF HAL_AFE Register Map --------------------------------------------------*/
/**
 * @brief  HAL Status structures definition
 */
typedef enum
{
	HAL_SPI_OK = 0x00U,
	HAL_SPI_ERROR = 0x01U
} HAL_SPIStatusTypeDef;

/**
 * @brief  AFE5808A handle Structure definition
 */
typedef struct __SPI_HandleTypeDef
{
	char *SPI_Device; /*!< SPI Handle type def */

	struct spi_ioc_transfer spi_trx; /*!< PORT Handle type def */

	int fileDevice; /*!< PORT Handle type def */

	int fileReturn; /*!< PORT Handle type def */

	uint32_t spi_state; /*!< PORT Handle type def */

} SPI_HandleTypeDef;

/* Extern Variables -----------------------------------------------------------------*/
extern SPI_HandleTypeDef hspi3;
extern SPI_HandleTypeDef hspi4;
extern SPI_HandleTypeDef hspi5;
extern SPI_HandleTypeDef hspi6;

/* Prototype -----------------------------------------------------------------*/

/* Base functions */
HAL_SPIStatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *dataW, uint8_t *dataR,
											 uint8_t dataSize, uint16_t Timeout);

HAL_SPIStatusTypeDef HAL_SPI_OPEN(SPI_HandleTypeDef *hspi);
HAL_SPIStatusTypeDef HAL_SPI_CLOSE(SPI_HandleTypeDef *hspi);

/* SPI init functions */
HAL_SPIStatusTypeDef MX_SPI3_Init(void);
HAL_SPIStatusTypeDef MX_SPI4_Init(void);
HAL_SPIStatusTypeDef MX_SPI5_Init(void);
HAL_SPIStatusTypeDef MX_SPI6_Init(void);

/* SPI close functions */
HAL_SPIStatusTypeDef MX_SPI3_Deinit(void);
HAL_SPIStatusTypeDef MX_SPI4_Deinit(void);
HAL_SPIStatusTypeDef MX_SPI5_Deinit(void);
HAL_SPIStatusTypeDef MX_SPI6_Deinit(void);

#endif /* __HAL_SPI_H__ */
