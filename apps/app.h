

/*================================================================
 *
 *
 *   文件名称：app.h
 *   创 建 者：肖飞
 *   创建日期：2019年10月11日 星期五 16时56分29秒
 *   修改日期：2022年02月09日 星期三 15时48分13秒
 *   描    述：
 *
 *================================================================*/
#ifndef _APP_H
#define _APP_H
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#include "app_platform.h"
#include "cmsis_os.h"

#include "callback_chain.h"

#define VER_MAJOR 0
#define VER_MINOR 0
#define VER_REV 0
#define VER_BUILD 0
#define APP_DEFAULT_REQUEST_TYPE REQUEST_TYPE_SSE

#pragma pack(push, 1)

#pragma pack(pop)

typedef struct {
	uint8_t unused;
} app_info_t;

typedef enum {
	APP_EVENT_NONE = 0,
	APP_EVENT_HOST_USER_SELECT_CONFIGURATION,
	APP_EVENT_HOST_USER_CLASS_ACTIVE,
	APP_EVENT_HOST_USER_CLASS_SELECTED,
	APP_EVENT_HOST_USER_CONNECTION,
	APP_EVENT_HOST_USER_DISCONNECTION,
	APP_EVENT_HOST_USER_UNRECOVERED_ERROR,
} app_event_t;

app_info_t *get_app_info(void);
int app_event_init(size_t size);
void app_init(void);
void send_app_event(app_event_t event, uint32_t timeout);
void app(void const *argument);
void idle(void const *argument);

#endif //_APP_H
