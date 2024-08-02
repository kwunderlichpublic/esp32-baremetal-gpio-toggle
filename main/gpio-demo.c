#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define GPIO_OUT_W1TS_REG 0x3FF44008
#define GPIO_OUT_W1TC_REG 0x3FF4400C
#define GPIO_ENABLE_REG   0x3FF44020
#define GPIO2			  2

void app_main(void)
{
	volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*) GPIO_OUT_W1TS_REG;
	volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*) GPIO_OUT_W1TC_REG;
	volatile uint32_t* gpio_enable_reg = (volatile uint32_t*) GPIO_ENABLE_REG;

	// set GPIO2 to output
	*gpio_enable_reg = (1 << GPIO2);

	while(1) {
		// set the level for GPIO2 high
		*gpio_out_w1ts_reg = (1 << GPIO2);
		// delay
		vTaskDelay(pdMS_TO_TICKS(2000));
		// set GPIO2 low
		*gpio_out_w1tc_reg = (1 << GPIO2);
		// delay
		vTaskDelay(pdMS_TO_TICKS(2000));
	}
}
