# 编译器和链接器
CC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -nostdlib
TARGET_DIR = ../bin
LDFLAGS = -T link.ld

TARGET = main

SRC = main.c

build: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET_DIR)/$@ $^

clean:
	rm -f $(TARGET)