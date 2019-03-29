#include <ets_sys.h>
#include <osapi.h>
#include <mem.h>
#include <user_interface.h>
#include <driver/uart.h>
#include <gpio.h>
#include <string.h>
#include <eagle_soc.h>
#include <os_type.h>

#include "partition.h"

static ETSTimer t;
static uint32_t ticks = 0;

void timer_func(void *args) {
	os_printf("Timer: %u\r\n", ticks);
	ticks++;
}

void ICACHE_FLASH_ATTR
init_done(void) {
	os_printf("Starting timer\r\n");
	os_timer_disarm(&t);
	os_timer_setfn(&t, (os_timer_func_t*) timer_func, NULL);
	os_timer_arm(&t, 2000, 1);
}

void ICACHE_FLASH_ATTR user_pre_init(void)
{
    if(!system_partition_table_regist(at_partition_table, sizeof(at_partition_table)/sizeof(at_partition_table[0]),SPI_FLASH_SIZE_MAP)) {
		os_printf("system_partition_table_regist fail\r\n");
		while(1);
	}
}

void ICACHE_FLASH_ATTR
user_init(void)
{
	uart_init(BIT_RATE_115200, BIT_RATE_115200);
	os_delay_us(150);
	os_printf("\r\nBefore Boot\r\n");
	system_init_done_cb(init_done);
}
