TARGET_DIR = ../../bin
$(TARGET_DIR)/port.o:port.s
	nasm -f elf32 -o $@ $<
$(TARGET_DIR)/put_char.o:put_char.c
	gcc -m32 -fno-builtin -c -o $@ $<
build:$(TARGET_DIR)/port.o $(TARGET_DIR)/put_char.o