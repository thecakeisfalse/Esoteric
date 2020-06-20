# Makefile

AUTHOR       := Simon Chaykin
VERSION      := 0.0.1a

SOURCE_DIR   := src
INCLUDE_DIR  := include
ESOTERIC_DIR := $(SOURCE_DIR)/esoteric
LIB_DIR      := $(SOURCE_DIR)/lib

CC           := gcc
CFLAGS       := -g -I $(INCLUDE_DIR) -w

OBJS         := $(SOURCE_DIR)/main.o \
				$(ESOTERIC_DIR)/brainfuck.o \
				$(ESOTERIC_DIR)/hq9+.o \
				$(ESOTERIC_DIR)/ook!.o \
				$(ESOTERIC_DIR)/spoon.o \
				$(ESOTERIC_DIR)/malbolge.o \
				$(LIB_DIR)/utils.o \
				$(LIB_DIR)/args.o

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)

all: esoteric

esoteric: $(OBJS)
	@$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
	@rm -rf $(OBJS) esoteric
