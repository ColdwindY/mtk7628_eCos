# Makefile

include $(TOPDIR)/.config
include $(TOPDIR)/rules.mak

ifeq ($(CHIPSET),3050)
EXTRA_CFLAGS += -DCONFIG_RT3050_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_RT3050
endif

ifeq ($(CHIPSET),3052)
EXTRA_CFLAGS += -DCONFIG_RT3052_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_RT3052
endif

ifeq ($(CHIPSET),3352)
EXTRA_CFLAGS += -DCONFIG_RT3352_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_RT3352
endif

ifeq ($(CHIPSET),5350)
EXTRA_CFLAGS += -DCONFIG_RT5350_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_RT5350
endif

ifeq ($(CHIPSET),7620)
EXTRA_CFLAGS += -DCONFIG_MT7620_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_MT7620
endif

ifeq ($(CHIPSET),mt7628)
EXTRA_CFLAGS += -DCONFIG_MT7628_ASIC
EXTRA_CFLAGS += -DCONFIG_RALINK_MT7628
endif

ALL_OBJS = ralink_gpio.o

MODULE = $(shell pwd | sed "s/.*\///" ).o


all: $(MODULE)

$(MODULE): $(ALL_OBJS:.o=.d)
	$(XLD) -r $(ENDIAN) -o $(MODULE) $(ALL_OBJS)

clean:
	rm $(MODULE) $(ALL_OBJS)
