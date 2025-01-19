#include <elf.h>
#include <stdio.h>
int main() {
    printf("ELF header size: %lu\n", sizeof(Elf64_Ehdr));
    return 0;
}