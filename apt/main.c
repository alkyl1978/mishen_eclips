
#include <libopencm3/stm32/rcc.h>

int main(void)
{
	rcc_clock_setup_in_hsi_out_48mhz();
	while(1)
	{

	}
}
