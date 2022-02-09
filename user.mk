#
#
#================================================================
#   
#   
#   文件名称：user.mk
#   创 建 者：肖飞
#   创建日期：2019年10月25日 星期五 13时04分38秒
#   修改日期：2022年02月09日 星期三 15时54分20秒
#   描    述：
#
#================================================================

include config.mk

ifndef_any_of = $(filter undefined,$(foreach v,$(1),$(origin $(addprefix CONFIG_,$(v)))))
ifdef_any_of = $(filter-out undefined,$(foreach v,$(1),$(origin $(addprefix CONFIG_,$(v)))))

USER_C_INCLUDES += -Iapps
USER_C_INCLUDES += -Iapps/modules
USER_C_INCLUDES += -Iapps/modules/os
USER_C_INCLUDES += -Iapps/modules/drivers
USER_C_INCLUDES += -Iapps/modules/drivers/mcp2518
USER_C_INCLUDES += -Iapps/modules/drivers/mcp2518/mcp25xxfd_driver/canfdspi
USER_C_INCLUDES += -Iapps/modules/drivers/mcp2518/mcp25xxfd_driver/spi
USER_C_INCLUDES += -Iapps/modules/hardware
USER_C_INCLUDES += -Iapps/modules/app

C_INCLUDES += $(USER_C_INCLUDES)

USER_C_SOURCES += apps/os_memory.c
USER_C_SOURCES += apps/os_random.c
USER_C_SOURCES += apps/early_sys_callback.c
USER_C_SOURCES += apps/app.c
USER_C_SOURCES += apps/can_config.c

USER_C_SOURCES += apps/modules/app/duty_cycle_pattern.c
USER_C_SOURCES += apps/modules/drivers/spi_txrx.c
USER_C_SOURCES += apps/modules/drivers/can_txrx.c
USER_C_SOURCES += apps/modules/drivers/can_ops_hal.c
USER_C_SOURCES += apps/modules/drivers/mcp2518/mcp25xxfd_driver/canfdspi/drv_canfdspi_api.c
USER_C_SOURCES += apps/modules/drivers/can_ops_spi_can.c
USER_C_SOURCES += apps/modules/drivers/usart_txrx.c
USER_C_SOURCES += apps/modules/os/event_helper.c
USER_C_SOURCES += apps/modules/os/callback_chain.c
USER_C_SOURCES += apps/modules/os/bitmap_ops.c
USER_C_SOURCES += apps/modules/os/iap.c
USER_C_SOURCES += apps/modules/os/os_utils.c
USER_C_SOURCES += apps/modules/os/cpu_utils.c
USER_C_SOURCES += apps/modules/os/log.c
USER_C_SOURCES += apps/modules/os/object_class.c
USER_C_SOURCES += apps/modules/os/soft_timer.c

C_SOURCES += $(USER_C_SOURCES)

USER_CFLAGS += -DtraceTASK_SWITCHED_IN=StartIdleMonitor -DtraceTASK_SWITCHED_OUT=EndIdleMonitor
USER_CFLAGS += -DSAL_HOOK
USER_CFLAGS += -DLOG_CONFIG_FILE=\"log_config.h\"
USER_CFLAGS += -DCJSON_API_VISIBILITY -DCJSON_EXPORT_SYMBOLS -DENABLE_LOCALES -Dcjson_EXPORTS

#USER_CFLAGS += -DLOG_DISABLE
#USER_CFLAGS += -DALLOC_TRACE_DISABLE

CFLAGS += $(USER_CFLAGS) $(CONFIG_CFLAGS)

#LDFLAGS += -u _printf_float -Wl,--wrap=srand  -Wl,--wrap=rand
LDFLAGS += -u _printf_float

default: all

IAP_FILE := apps/modules/os/iap.h

define update-iap-include
	if [ -f $(IAP_FILE) ]; then
		touch $(IAP_FILE);
	fi
endef

ifneq ($(call ifdef_any_of,USER_APP),)
build-type := .app.stamps
build-type-invalid := .bootloader.stamps
CFLAGS += -DUSER_APP
LDSCRIPT = STM32F407VETx_FLASH_APP.ld
#$(info $(shell $(update-iap-include)))
$(info "build app!")
else
build-type := .bootloader.stamps
build-type-invalid := .app.stamps
LDSCRIPT = STM32F407VETx_FLASH.ld
#$(info $(shell $(update-iap-include)))
$(info "build bootloader!")
endif

$(build-type) :
#	$(shell $(update-iap-include))
	-rm $(build-type-invalid)
	touch $@


PHONY += all
PHONY += default

USER_DEPS := config.mk $(build-type) $(LDSCRIPT)

cscope: all
	rm cscope e_cs -rf
	mkdir -p cscope
	#$(silent)tags.sh prepare;
	$(silent)touch dep_files;
	$(silent)touch raw_dep_files;
	$(silent)for f in $$(find . -type f -name "*.d" 2>/dev/null); do \
		cat "$$f" >> raw_dep_files; \
	done;
	for i in $$(cat "raw_dep_files" | sed 's/^.*://g' | sed 's/[\\ ]/\n/g' | sort -h | uniq); do \
		if test "$${i:0:1}" = "/";then \
			echo "$$i" >> dep_files; \
		else \
			readlink -f "$$i" >> dep_files; \
		fi; \
	done; \
	$(silent)rm raw_dep_files
	$(silent)cat dep_files | sort | uniq | sed 's/^\(.*\)$$/\"\1\"/g' >> cscope/cscope.files;
	$(silent)cat dep_files | sort | uniq >> cscope/ctags.files;
	$(silent)rm dep_files
	$(silent)tags.sh cscope;
	$(silent)tags.sh tags;
	$(silent)tags.sh env;

clean: clean-cscope
clean-cscope:
	rm cscope e_cs -rf

firmware:
	python apps/modules/fw.py -f build/eva.bin

