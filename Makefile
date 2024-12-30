# 定义变量
BOCHS_FILE = bochs_file
DISK_IMG_FILE = disk_img_file

# 运行 Bochs
run:
	cd $(BOCHS_FILE) && bochs -f bochsrc && cd - 
clean:
	cd $(DISK_IMG_FILE) && rm -f c.img.lock && cd -



