
CC = gcc
CFLAGS = -m32 -c -fno-stack-protector -nostdlib -ffreestanding
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIB = ../../bin/libklib.a

build:$(LIB)
	rm -rf *.o 
	
%.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ && ./cm.sh

$(LIB):$(OBJS)
	ar rcs $(LIB) *.o 
clean:
	rm -rf *.o


