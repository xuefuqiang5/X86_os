# 定义变量
DISK_IMG = ../disk_img_file/c.img

# 编译和写入 MBR 和 Loader
write_into: mbr.bin load.bin
	dd if=mbr.bin of=$(DISK_IMG) bs=512 count=1 conv=notrunc
	dd if=load.bin of=$(DISK_IMG) bs=512 seek=1 conv=notrunc

# 编译 MBR
mbr.bin: mbr.asm
	nasm mbr.asm -o mbr.bin

# 编译 Loader
load.bin: load.asm
	nasm load.asm -o load.bin

# 默认目标
run: write_into
	$(MAKE) -C ..

# 清理生成的文件
clean:
	rm -f *.bin
	$(MAKE) -C .. clean