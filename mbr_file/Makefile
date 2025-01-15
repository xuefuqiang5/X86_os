write_into: mbr.bin
	dd if=mbr.bin of=../disk_img_file/c.img bs=512 count=1 conv=notrunc

mbr.bin: mbr.asm
	nasm mbr.asm -o mbr.bin

all: write_into
	$(MAKE) -C ..

clean:
	$(MAKE) -C .. clean