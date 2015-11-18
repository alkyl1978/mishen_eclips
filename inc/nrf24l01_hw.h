/*
 * nrf24l01_hw.h
 *
 *  Created on: 20 марта 2015 г.
 *      Author: aleks
 */

#ifndef NRF24L01_HW_H_
#define NRF24L01_HW_H_

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>

#define SPI_SCK        GPIO5
#define SPI_MISO       GPIO6
#define SPI_MOSI       GPIO7
#define IRQ            GPIO8
#define CE             GPIO11
#define CSN            GPIO12
#define RCC_SPI_PORT   RCC_GPIOA
#define RCC_NRF_PORT   RCC_GPIOA
#define SPI_PORT       GPIOA
#define NRF_PORT       GPIOA
#define SPI_NRF        SPI1
#define SPI_NRF_br     SPI_CR1_BAUDRATE_FPCLK_DIV_4| SPI_CR1_BAUDRATE_FPCLK_DIV_8
#define RCC_SPI        RCC_SPI1
#define SPI_AF         GPIO_AF0
#define CE_OFF         gpio_clear(NRF_PORT,CE)
#define CE_ON          gpio_set(NRF_PORT,CE)
#define CSN_ON         gpio_clear(NRF_PORT,CE)
#define CSN_OFF        gpio_set(NRF_PORT,CE)

void spi0_init(void);
void nrf24l01_init(void);

#endif /* NRF24L01_HW_H_ */
