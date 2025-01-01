#!/bin/bash

# 定义目标文件
DISK_IMG="../disk_img_file/c.img"

# 创建一个包含 1KB 0x11 的文件
dd if=/dev/zero bs=1 count=1024 | tr '\0' '\x11' > temp.bin

# 将 temp.bin 写入目标文件的第二个扇区位置
dd if=temp.bin of=$DISK_IMG bs=512 seek=1 conv=notrunc

# 删除临时文件
rm temp.bin
