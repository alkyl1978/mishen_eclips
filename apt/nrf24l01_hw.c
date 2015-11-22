/*
 * nrf24l01_hw.c
 *
 *  Created on: 20 марта 2015 г.
 *      Author: aleks
 */
#include "../inc/nrf24l01_hw.h"

void spi0_init(void)
{
	rcc_periph_clock_enable(RCC_SPI_PORT); // включаем тактирование порта
	rcc_periph_clock_enable(RCC_SPI);      // включаем тактирование SPI
	gpio_mode_setup(SPI_PORT,GPIO_MODE_AF,GPIO_PUPD_NONE, SPI_SCK|SPI_MISO|SPI_MOSI);
	gpio_set_af(SPI_PORT,SPI_AF,SPI_SCK|SPI_MISO|SPI_MOSI);
	spi_reset(SPI_NRF); //сбрасываем порт

}

void nrf24l01_init(void)
{
	spi0_init();
	rcc_periph_clock_enable(RCC_NRF_PORT); // включаем тактирование порта
	// настраиваем выводы nrf24l01
	gpio_mode_setup(NRF_PORT,GPIO_MODE_OUTPUT,GPIO_PUPD_PULLUP,CE|CSN);
	gpio_mode_setup(NRF_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,IRQ);
	CE_OFF;
	CSN_ON;
}
