/**
 ******************************************************************************
 * @file    hal_spi.c
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the spi.c file
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hal_spi.h"

/* Variables -----------------------------------------------------------------*/
SPI_HandleTypeDef hspi3;
SPI_HandleTypeDef hspi4;
SPI_HandleTypeDef hspi5;
SPI_HandleTypeDef hspi6;

/* Variables -----------------------------------------------------------------*/
#define SPI_DEVICE_3_0 "/dev/spidev3.0"
#define SPI_DEVICE_4_0 "/dev/spidev4.0"
#define SPI_DEVICE_5_0 "/dev/spidev5.0"
#define SPI_DEVICE_6_0 "/dev/spidev6.0"

/* Prototype -----------------------------------------------------------------*/

/* SPI init functions */
HAL_SPIStatusTypeDef MX_SPI3_Init(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	hspi3.spi_trx.bits_per_word = 0;
	hspi3.spi_trx.speed_hz = 20000000;
	hspi3.spi_trx.delay_usecs = 0;
	hspi3.SPI_Device = SPI_DEVICE_3_0;

	// open SPI device
	errorcode = HAL_SPI_OPEN(&hspi3);

	return (errorcode);
}

/* SPI init functions */
HAL_SPIStatusTypeDef MX_SPI4_Init(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	hspi4.spi_trx.bits_per_word = 0;
	hspi4.spi_trx.speed_hz = 25000000;
	hspi4.spi_trx.delay_usecs = 0;
	hspi4.SPI_Device = SPI_DEVICE_4_0;

	// open SPI device
	errorcode = HAL_SPI_OPEN(&hspi4);

	return (errorcode);
}

/* SPI init functions */
HAL_SPIStatusTypeDef MX_SPI5_Init(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	hspi5.spi_trx.bits_per_word = 0;
	hspi5.spi_trx.speed_hz = 25000000;
	hspi5.spi_trx.delay_usecs = 0;
	hspi5.SPI_Device = SPI_DEVICE_5_0;

	// open SPI device
	errorcode = HAL_SPI_OPEN(&hspi5);

	return (errorcode);
}

/* SPI init functions */
HAL_SPIStatusTypeDef MX_SPI6_Init(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	hspi6.spi_trx.bits_per_word = 0;
	hspi6.spi_trx.speed_hz = 25000000;
	hspi6.spi_trx.delay_usecs = 0;
	hspi6.SPI_Device = SPI_DEVICE_6_0;

	// open SPI device
	errorcode = HAL_SPI_OPEN(&hspi6);

	return (errorcode);
}

/* SPI Stop functions */
HAL_SPIStatusTypeDef MX_SPI3_Deinit(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// close SPI device
	errorcode = HAL_SPI_CLOSE(&hspi3);
	// printf("Cerrado exitosamente\n");

	return (errorcode);
}

/* SPI Stop functions */
HAL_SPIStatusTypeDef MX_SPI4_Deinit(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// close SPI device
	errorcode = HAL_SPI_CLOSE(&hspi4);
	// printf("Cerrado exitosamente\n");

	return (errorcode);
}

/* SPI Stop functions */
HAL_SPIStatusTypeDef MX_SPI5_Deinit(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// close SPI device
	errorcode = HAL_SPI_CLOSE(&hspi5);
	// printf("Cerrado exitosamente\n");

	return (errorcode);
}

/* SPI Stop functions */
HAL_SPIStatusTypeDef MX_SPI6_Deinit(void)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// close SPI device
	errorcode = HAL_SPI_CLOSE(&hspi6);
	// printf("Cerrado exitosamente\n");

	return (errorcode);
}


/* *****************************************************************************
 * ** TRANSMIT RECEIVE FUNCTION
 * *****************************************************************************/

/* Transmit and Receive function */
HAL_SPIStatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *dataW, uint8_t *dataR,
											 uint8_t dataSize, uint16_t Timeout)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	hspi->spi_trx.tx_buf = (unsigned long)dataW;
	hspi->spi_trx.rx_buf = (unsigned long)dataR;
	hspi->spi_trx.len = dataSize;

	// Transmit and receive data from buffer
	hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_MESSAGE(1), &(hspi->spi_trx));
	if (hspi->fileReturn != 0)
	{
		// printf("SPI transfer returned %d...\r\n", hspi->fileReturn);
        // fflush(stdout);
	}

	return (errorcode);
}

/* *****************************************************************************
 * ** BASE FUNCTIONS
 * *****************************************************************************/

/* SPI open function */
HAL_SPIStatusTypeDef HAL_SPI_OPEN(SPI_HandleTypeDef *hspi)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// open SPI device
	hspi->fileDevice = open(hspi->SPI_Device, O_RDWR);
	if (hspi->fileDevice < 0)
	{
		printf("Could not open the SPI device...\r\n");
        fflush(stdout);
		errorcode = HAL_SPI_ERROR;
		return (errorcode);
	}

	// Configure SPI mode
	hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_RD_MODE32, &(hspi->spi_state));
	if (hspi->fileReturn != 0)
	{
		printf("Could not read SPI mode...\r\n");
        fflush(stdout);
		close(hspi->fileDevice);
		errorcode = HAL_SPI_ERROR;
		return (errorcode);
	}
	hspi->spi_state = SPI_MODE_0; // CPHA = 0; CPOL = 0;
	hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_WR_MODE32, &(hspi->spi_state));
	if (hspi->fileReturn != 0)
	{
		printf("Could not write SPI mode...\r\n");
        fflush(stdout);
		close(hspi->fileDevice);
		errorcode = HAL_SPI_ERROR;
		return (errorcode);
	}

	// Configure SPI Speed
	hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_RD_MAX_SPEED_HZ, &(hspi->spi_state));
	if (hspi->fileReturn != 0)
	{
		printf("Could not read the SPI max speed...\r\n");
        fflush(stdout);
		close(hspi->fileDevice);
		errorcode = HAL_SPI_ERROR;
		return (errorcode);
	}
	hspi->spi_state = 20000000;
	hspi->fileReturn = ioctl(hspi->fileDevice, SPI_IOC_WR_MAX_SPEED_HZ, &(hspi->spi_state));
	if (hspi->fileReturn != 0)
	{
		printf("Could not write the SPI max speed...\r\n");
        fflush(stdout);
		close(hspi->fileDevice);
		errorcode = HAL_SPI_ERROR;
		return (errorcode);
	}

	// printf("Configurado exitosamente\n");

	// Configuration OK
	return (errorcode);
}

/* SPI close function */
HAL_SPIStatusTypeDef HAL_SPI_CLOSE(SPI_HandleTypeDef *hspi)
{
	HAL_SPIStatusTypeDef errorcode = HAL_SPI_OK;

	// Close the SPI device
	close(hspi->fileDevice);

	// Configuration OK
	return (errorcode);
}

/* SPI AFE operation config ***************************************************/
