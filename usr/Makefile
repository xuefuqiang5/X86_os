CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -nostdlib -fno-stack-protector -O0 -g -Wall -Wextra
ASFLAGS = -m32 -g
TARGET_DIR = ../bin
LDFLAGS = -T link.ld
LIBRARY = ../bin/libklib.a

SRC_C = $(wildcard *.c)
SRC_S = $(wildcard *.S)
OBJ = $(patsubst %.c,$(TARGET_DIR)/%.o,$(SRC_C)) \
		$(patsubst %.S,$(TARGET_DIR)/%.o,$(SRC_S)) 
		

TARGET = $(TARGET_DIR)/kernel

.PHONY: build clean debug

build: $(TARGET)

clean:
	rm -rf $(TARGET_DIR)/*.o $(TARGET_DIR)/kernel $(LIBRARY)
	make -C ../lib/kernel clean

$(LIBRARY):
	make -C ../lib/kernel build

debug:
	make -C .. debug

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# 编译C文件
$(TARGET_DIR)/%.o: %.c | $(TARGET_DIR)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

# 汇编ASM文件
$(TARGET_DIR)/%.o: %.S | $(TARGET_DIR)
	@echo "Assembling $<"
	nasm -f elf32 -g -o $@ $<

# 链接
$(TARGET): $(OBJ) $(LIBRARY)
	@echo "Linking $@"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -z noexecstack


gdb_symol:
	@echo "generate symbol table...."
	objcopy --only-keep-debug $(TARGET_DIR)/kernel $(TARGET_DIR)/kernel.sym

clean_intermediate:
	rm -rf *.o