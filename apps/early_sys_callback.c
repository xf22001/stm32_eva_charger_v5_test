

/*================================================================
 *
 *
 *   文件名称：early_sys_callback.c
 *   创 建 者：肖飞
 *   创建日期：2021年03月25日 星期四 15时11分14秒
 *   修改日期：2021年12月06日 星期一 10时08分11秒
 *   描    述：
 *
 *================================================================*/
#include "early_sys_callback.h"
#include "os_utils.h"
#include "app.h"

void early_sys_callback(void)
{
	OS_ASSERT(app_event_init(10) == 0);
}
