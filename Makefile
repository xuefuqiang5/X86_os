# 定义变量
BOCHS_FILE = bochs_file
DISK_IMG = ./disk_img_file/c.img
TARGET_DIR = ./bin
DISK = /home/my_linux/LEARN/X86_os/disk_img_file/c.img

$(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin:
	make -C ./loader build
$(TARGET_DIR)/kernel:
	make -C ./kernel build


write_into: $(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin $(TARGET_DIR)/kernel
	dd if=./bin/mbr.bin of=$(DISK_IMG) bs=512 count=1 conv=notrunc
	dd if=./bin/loader.bin of=$(DISK_IMG) bs=512 seek=1 conv=notrunc
	dd if=$(TARGET_DIR)/kernel of=$(DISK_IMG) bs=512 count=200 seek=9 conv=notrunc 
debug: write_into
	cd $(BOCHS_FILE) && bochs -f bochsrc && cd -  

clean: 
	make -C ./loader clean
	rm -f $(TARGET_DIR)/mbr.bin $(TARGET_DIR)/loader.bin
	

