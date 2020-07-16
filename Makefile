# Makefile

CC      := gcc

SOURCES += $(shell find -name "*.c" -type f -print)
OBJS    := $(patsubst %.c, %.o, $(SOURCES))

all: esoteric

esoteric: $(OBJS)
	@$(CC) $(OBJS) -o $@

clean:
	@rm -rf $(OBJS) esoteric

%.o: %.c
	@$(CC) -c $< -o $@ -w -g
