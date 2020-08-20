# Makefile

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic-errors -std=c89 -g

SOURCES += $(shell find -name "*.c" -type f -print)
OBJS    := $(patsubst %.c, %.o, $(SOURCES))

all: esoteric

esoteric: $(OBJS)
	@$(CC) $(OBJS) -o $@

clean:
	@rm -rf $(OBJS) esoteric

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)
