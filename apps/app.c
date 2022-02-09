

/*================================================================
 *
 *
 *   文件名称：app.c
 *   创 建 者：肖飞
 *   创建日期：2019年10月11日 星期五 16时54分03秒
 *   修改日期：2022年02月09日 星期三 15时51分07秒
 *   描    述：
 *
 *================================================================*/
#include "app.h"

#include <string.h>

//#include "iwdg.h"

#include "os_utils.h"

#include "duty_cycle_pattern.h"

#include "log.h"

static app_info_t *app_info = NULL;
static os_signal_t app_event = NULL;

app_info_t *get_app_info(void)
{
	return app_info;
}

int app_event_init(size_t size)
{
	int ret = -1;

	if(app_event != NULL) {
		return ret;
	}

	app_event = signal_create(size);
	OS_ASSERT(app_event != NULL);
	ret = 0;
	return ret;
}

void app_init(void)
{
	mem_info_init();
}

void send_app_event(app_event_t event, uint32_t timeout)
{
	signal_send(app_event, event, timeout);
}

void app(void const *argument)
{
	int ret;

	app_init();

	app_info = (app_info_t *)os_calloc(1, sizeof(app_info_t));

	OS_ASSERT(app_info != NULL);

	//get_or_alloc_uart_debug_info(&huart1);
	//add_log_handler((log_fn_t)log_uart_data);

	debug("===========================================start app============================================");

	while(1) {
		uint32_t event;
		ret = signal_wait(app_event, &event, 1000);

		if(ret == 0) {
			switch(event) {
				case APP_EVENT_HOST_USER_CLASS_ACTIVE: {
				}
				break;

				case APP_EVENT_HOST_USER_CONNECTION: {
				}
				break;

				case APP_EVENT_HOST_USER_DISCONNECTION: {
				}
				break;

				default: {
					debug("unhandled event %x", event);
				}
				break;
			}
		}
	}
}

static pattern_state_t work_pattern_state = {
	.type = PWM_COMPARE_COUNT_UP,
	.duty_cycle = 0,
};

static void update_work_led(void)
{
	//计数值小于duty_cycle,输出1;大于duty_cycle输出0
	uint16_t duty_cycle = get_duty_cycle_pattern(&work_pattern_state, 1000, 0, 20);
	//__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_cycle);
}

void idle(void const *argument)
{
	//MX_IWDG_Init();
	//HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

	while(1) {
		//HAL_IWDG_Refresh(&hiwdg);
		update_work_led();
		osDelay(10);
	}
}
