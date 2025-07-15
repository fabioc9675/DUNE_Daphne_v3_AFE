/**
 ******************************************************************************
 * @file    hal_gpio.c
 * @author  Fabian Castano
 * @brief   This file contains all the function prototypes for
 *          the hal_gpio.c file
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hal_gpio.h"

/* Handle --------------------------------------------------------------------*/

/* Registers -----------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/

/* Prototype -----------------------------------------------------------------*/

/* GPIO init functions */
void MX_GPIO_Init(void)
{

    // AFE Pins
    HAL_GPIO_PinOut_Init(AFE_PDN_P_Pin);
    HAL_GPIO_PinOut_Init(AFE_RST_P_Pin);

    HAL_GPIO_PinOut_Init(AFE0_SEN_Pin);
   // HAL_GPIO_PinOut_Init(AFE1_SEN_Pin);
   // HAL_GPIO_PinOut_Init(AFE2_SEN_Pin);
   // HAL_GPIO_PinOut_Init(AFE3_SEN_Pin);
   // HAL_GPIO_PinOut_Init(AFE4_SEN_Pin);

    // DAC Pins
   // HAL_GPIO_PinOut_Init(DAC_LDACn_Pin);
   // HAL_GPIO_PinOut_Init(DAC_SYNCn_Pin);

   // HAL_GPIO_PinOut_Init(LDAC0_TRM_Pin);
   // HAL_GPIO_PinOut_Init(LDAC1_TRM_Pin);
   // HAL_GPIO_PinOut_Init(LDAC2_TRM_Pin);
   // HAL_GPIO_PinOut_Init(LDAC3_TRM_Pin);
   // HAL_GPIO_PinOut_Init(LDAC4_TRM_Pin);

   // HAL_GPIO_PinOut_Init(SYNC0_TRM_Pin);
   // HAL_GPIO_PinOut_Init(SYNC1_TRM_Pin);
   // HAL_GPIO_PinOut_Init(SYNC2_TRM_Pin);
   // HAL_GPIO_PinOut_Init(SYNC3_TRM_Pin);
   // HAL_GPIO_PinOut_Init(SYNC4_TRM_Pin);

   // HAL_GPIO_PinOut_Init(LDAC0_OFF_Pin);
   // HAL_GPIO_PinOut_Init(LDAC1_OFF_Pin);
   // HAL_GPIO_PinOut_Init(LDAC2_OFF_Pin);
   // HAL_GPIO_PinOut_Init(LDAC3_OFF_Pin);
   // HAL_GPIO_PinOut_Init(LDAC4_OFF_Pin);

   // HAL_GPIO_PinOut_Init(SYNC0_OFF_Pin);
   // HAL_GPIO_PinOut_Init(SYNC1_OFF_Pin);
   // HAL_GPIO_PinOut_Init(SYNC2_OFF_Pin);
   // HAL_GPIO_PinOut_Init(SYNC3_OFF_Pin);
   // HAL_GPIO_PinOut_Init(SYNC4_OFF_Pin);

    return;
}

/* GPIO init functions */
void HAL_GPIO_PinOut_Init(int gpio_pin)
{
    char buffer[256];
    int fd;

    // Configurar el pin GPIO como salida
    snprintf(buffer, sizeof(buffer), "/sys/class/gpio/gpio%d/direction", gpio_pin);
    // printf("%s\n", buffer);
    fd = open(buffer, O_WRONLY);
    write(fd, "out", 3);
    close(fd);

    return;
}

/* GPIO state functions */
void HAL_GPIO_WritePin(int gpio_port, int gpio_pin, int value)
{
    char buffer[256];
    int fd;

    // Establecer el valor del pin GPIO
    snprintf(buffer, sizeof(buffer), "/sys/class/gpio/gpio%d/value", gpio_pin);
    // printf("%s\n", buffer);
    fd = open(buffer, O_WRONLY);
    if (value)
        write(fd, "1", 1);
    else
        write(fd, "0", 1);
    close(fd);

    return;
}
