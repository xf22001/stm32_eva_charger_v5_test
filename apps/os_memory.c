

/*================================================================
 *   
 *   
 *   文件名称：os_memory.c
 *   创 建 者：肖飞
 *   创建日期：2021年02月04日 星期四 10时23分08秒
 *   修改日期：2021年02月04日 星期四 11时01分44秒
 *   描    述：
 *
 *================================================================*/
#include <stdlib.h>

#include "cmsis_os.h"
#include "app_platform.h"

#if(configAPPLICATION_ALLOCATED_HEAP == 1)
uint8_t ucHeap[ configTOTAL_HEAP_SIZE ] CCMRAM;
#endif

void *port_malloc(size_t size)
{
	return malloc(size);
}

void port_free(void *p)
{
	free(p);
}

extern uint32_t _Min_Heap_Size;
uint32_t get_total_heap_size(void)
{
	return (uint32_t)&_Min_Heap_Size;
}
