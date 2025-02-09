CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -nostdlib -fno-stack-protector -O0
ASFLAGS = -m32  # 汇编器标志
TARGET_DIR = ../bin
LDFLAGS = -T link.ld
LIBRARY = ../bin/libklib.a  # 假设库文件的路径

# 获取所有 .c 和 .S 文件
SRC_C = $(wildcard *.c)
SRC_S = $(wildcard *.S)
SRC = $(SRC_C) $(SRC_S)

# 将所有源文件转换为目标文件路径
OBJ = $(patsubst %.c,$(TARGET_DIR)/%.o,$(SRC_C)) $(patsubst %.S,$(TARGET_DIR)/%.o,$(SRC_S))

TARGET = $(TARGET_DIR)/kernel

.PHONY: build clean debug

build: $(TARGET)

clean:
	rm -rf $(TARGET_DIR)/*.o $(TARGET_DIR)/kernel $(LIBRARY)
	make -C ../lib/kernel clean
	rm -rf *.o

# 构建库文件
$(LIBRARY):
	make -C ../lib/kernel build

# 调试目标
debug:
	make -C .. debug

# 创建目标目录
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# 编译 .c 文件生成 .o 文件
$(TARGET_DIR)/%.o: %.c | $(TARGET_DIR)
	@echo "Compiling $<"
	@if $(CC) $(CFLAGS) -c -o $@ $<; then \
		echo "Running entry.sh"; \
		./entry.sh; \
	else \
		echo "Compilation failed, skipping entry.sh"; \
		exit 1; \
	fi

# 编译 .S 文件生成 .o 文件
$(TARGET_DIR)/%.o: %.S | $(TARGET_DIR)
	@echo "Assembling $<"
	@if nasm -f elf32 -o $@ $<; then \
		echo "Running entry.sh"; \
		./entry.sh; \
	else \
		echo "Assembly failed, skipping entry.sh"; \
		exit 1; \
	fi

# 链接生成最终目标文件
$(TARGET): $(OBJ) $(LIBRARY)
	@echo "Linking $@"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -z noexecstack

# 清理中间文件
clean_intermediate:
	rm -rf *.o