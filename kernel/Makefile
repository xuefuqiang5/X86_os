CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -nostdlib 
TARGET_DIR = ../bin
LDFLAGS = -T link.ld
TARGET_FILE = $(TARGET_DIR)/libklib.a
TARGET = main.o
build: $(TARGET_DIR)/kernel
	rm -rf ../bin/main.o 
$(TARGET_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<
$(TARGET_DIR)/kernel: $(TARGET_FILE) $(TARGET_DIR)/main.o
	$(CC) $(CFLAGS) ../bin/main.o -L../bin -lklib -o $@ $(LDFLAGS) -z -noexecstack
$(TARGET_FILE):
	make -C ../lib/kernel build
debug:
	make -C ../ debug
clean:
	rm -f ../bin/*.o ../bin/kernel ../bin/libklib.a