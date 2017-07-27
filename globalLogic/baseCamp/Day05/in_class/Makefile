include common.mk
#app output name
OUT_NAME := app
ifeq ($(OUT_NAME),)
	$(error OUT_NAME is not define)
endif

GCC_STD ?=gnu99 #use by default if another didnt set

CFLAGS += -std=$(GCC_STD) # simply '=' if call make with flags from console this well clear and new flagss add
	            # += concotinate flags from console
CFLAGS += -DLOGNAME="\"$(LOGNAME)\""

.PHONY: all clean cbuild error warn

all:
	$(CC) $(CFLAGS) main.c -o $(OUT_NAME)

clean:
	$(RM) -f $(OUT_NAME)

cbuild: clean all
	$(ECHO) "Done"

help:
	$(CAT) README

error:
	$(error XXX: test)

warn:

	$(warning WWW: test)
