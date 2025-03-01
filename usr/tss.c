#include "tss.h"
static struct tss t; 
static struct {
    unsigned short limit;  
    unsigned int base;    
} gdtr;
static struct descriptor {
  uint16_t limit;
  uint16_t baselo;
  uint8_t basemid;
  uint8_t flag0;
  uint8_t flag1;
  uint8_t basehi;
};
static struct descriptor *gdt;
static void get_gdt_base(){
    __asm__ volatile (
        "sgdt %0"  
        : "=m" (gdtr)  
    );
    gdt = gdtr.base;
}
void set_tss_dec(){
    get_gdt_base(); 
    gdt[GDT_TSS].limit = sizeof(struct tss)&0xffff;
    gdt[GDT_TSS].baselo = 0x0000; 
    gdt[GDT_TSS].basemid = 0x00; 
    gdt[GDT_TSS].flag0 = DESC_TSS|DESC_TSS32|DESC_DPL_0;
    gdt[GDT_TSS].flag1 = sizeof(struct tss)>>16;
    gdt[GDT_TSS].basehi = 0x00; 
    gdt_setdecbase(GDT_TSS, &t); 
}
void updata_esp(struct task_struct *pthread){
    t.esp0 = (uint32_t *)((uint32_t)pthread + PAGE_SIZE);
}
void gdt_setdecbase(uint16_t idx, void *base) {
  gdt[idx].baselo = (uint32_t)base & 0xffff;
  gdt[idx].basemid = ((uint32_t)base>>16) & 0xff;
  gdt[idx].basehi = (uint32_t)base >> 24;
  gdt[idx].flag0 |= DESC_PRESENT;
}
