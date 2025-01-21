# 编译器和链接器
CC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -nostdlib -c
TARGET_DIR = ../bin
LDFLAGS = -T link.ld
TARGET_FILE =$(TARGET_DIR)/port.o $(TARGET_DIR)/put_char.o
TARGET = main.o



build: $(TARGET_DIR)/kernel

$(TARGET_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<
$(TARGET_DIR)/kernel: $(TARGET_FILE) $(TARGET_DIR)/main.o
	gcc -m32 -ffreestanding -nostdlib -o $@ $^ -T link.ld -z noexecstack
$(TARGET_FILE): ../lib/kernel/port.s ../lib/kernel/put_char.c
	make -C ../lib/kernel build
debug:
	make -C ../ debug
clean:
	rm -f ../bin/*.o ../bin/kernel 