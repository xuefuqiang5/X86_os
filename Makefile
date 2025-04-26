# 定义变量
BOCHS_FILE = bochs_file
DISK_IMG = ./disk_img_file/c.img
TARGET_DIR = ./bin
DISK = /home/xuefuqiang5/X86_os/disk_img_file/c.img
BOCHS = /home/xuefuqiang5/bochs/bin/bochs

$(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin:
	make -C ./loader build
$(TARGET_DIR)/kernel:
	make -C ./kernel build


write_into: $(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin $(TARGET_DIR)/kernel
	dd if=./bin/mbr.bin of=$(DISK_IMG) bs=512 count=1 conv=notrunc
	dd if=./bin/loader.bin of=$(DISK_IMG) bs=512 seek=1 conv=notrunc
	dd if=$(TARGET_DIR)/kernel of=$(DISK_IMG) bs=512 count=200 seek=9 conv=notrunc 
debug: write_into
	cd $(BOCHS_FILE) && /home/xuefuqiang5/bochs/bin/bochs -f bochsrc && cd -  

run:
	qemu-system-i386 -m 32M -smp 1 -drive file=/home/xuefuqiang5/X86_os/disk_img_file/c.img,format=raw -boot d
	
clean: 
	make -C ./loader clean
	rm -f $(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin
	

