# Makefile

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic-errors -std=c89

SOURCES += $(shell find src -name "*.c" -type f -print)
OBJS    := $(patsubst %.c, %.o, $(SOURCES))

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

all: esoteric

esoteric: $(OBJS)
	@$(CC) $(OBJS) -o $@

install: esoteric
	@install -d $(PREFIX)/bin/
	@install -m 644 esoteric $(PREFIX)/bin/
	@chmod +rx $(PREFIX)/bin/esoteric

clean:
	@rm -rf $(OBJS) esoteric

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)
