#!/bin/bash

# 定义目标文件
DISK_IMG="../disk_img_file/c.img"

# 定义起始扇区和写入的扇区数量
START_SECTOR=9  # 第九扇区（从0开始计数）
NUM_SECTORS=5

# 创建并写入数据
for ((i=0; i<NUM_SECTORS; i++)); do
    # 计算要写入的字节值
    BYTE_VALUE=$((0x11 * (i + 1)))
    # 创建一个包含 512 字节相同数据的文件
    dd if=/dev/zero bs=1 count=512 2>/dev/null | tr '\0' $(printf "\\$(printf '%03o' $BYTE_VALUE)") > temp.bin

    # 将 temp.bin 写入目标文件的指定扇区位置
    dd if=temp.bin of=$DISK_IMG bs=512 seek=$((START_SECTOR + i)) conv=notrunc

    # 删除临时文件
    rm temp.bin
done

echo "数据写入完成。"