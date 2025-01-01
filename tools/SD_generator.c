#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
struct SegmentDescriptor {
    uint16_t limit_low;    
    uint16_t base_low;      
    uint8_t base_middle;   
    uint8_t access;        
    uint8_t granularity;    
    uint8_t base_high;     
} __attribute__((packed));

void set_segment_descriptor(struct SegmentDescriptor *sd, uint32_t segment_base_addr, uint32_t segment_limit, uint8_t access){
    sd->base_low = segment_base_addr & (uint32_t)0xffff;
    sd->base_high = (segment_base_addr >> 24) & (uint32_t)0xff;
    sd->base_middle = (segment_base_addr >> 16) & (uint32_t)0xff;
    sd->limit_low = segment_limit & (uint32_t)0xffff;
    sd->granularity = (segment_limit >> 16) & (uint32_t)0xf;
    printf("[0] 1B\n");
    printf("[1] 4KB\n");
    printf("selecte the granularity [0]");
    if(getchar() == 1) sd -> granularity |= 0xc0;
    else sd->granularity |= 0x40;
    sd->access = access;
}
int main(int argc, char *argv[]){
    struct SegmentDescriptor *sd = (struct SegmentDescriptor *)malloc (sizeof (struct SegmentDescriptor));
    uint32_t segment_base_addr;
    uint32_t segment_limit;
    uint8_t access;
    if(argc == 1){printf("Please input segment_base_addr, segment_limit, access\n"); return 0;}
    segment_base_addr = strtoul(argv[1], NULL, 16);
    segment_limit = strtoul(argv[2], NULL, 16);
    access = strtoul(argv[3], NULL, 16);
    
    printf("segment_base_addr: 0x%08x\n", segment_base_addr);
    printf("segment_limit: 0x%08x\n", segment_limit);
    printf("access: 0x%02x\n", access);

    set_segment_descriptor(sd, segment_base_addr, segment_limit, access);
    printf("Segment Descriptor:\n");
    uint64_t SD;
    memccpy(&SD, sd, 1, sizeof(struct SegmentDescriptor));
    printf("0x%016lx\n", SD);




    return 0;
}