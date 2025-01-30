CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -nostdlib -fno-stack-protector
TARGET_DIR = ../bin
LDFLAGS = -T link.ld
LIBRARY = ../bin/libklib.a  # 假设库文件的路径

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TARGET = $(TARGET_DIR)/kernel

# 默认目标
build: $(TARGET)
	rm -rf *.o
# 生成目标 .o 文件
$(TARGET_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -z noexecstack
$(LIBRARY):
	make -C ../lib/kernel build
debug:
	make -C .. debug
clean:
	rm -f $(TARGET_DIR)/*.o $(TARGET_DIR)/kernel $(LIBRARY)
	make -C ../lib/kernel clean
	rm -rf *.o
