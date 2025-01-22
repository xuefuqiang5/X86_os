/**
 * ICW1 0X11
 * ICW2 设置中断向量号
 * ICW3 指定用哪个引脚实现芯片级联
 * ICW4 用于控制chip的工作方式
 * 0 0 0 0 0 0 AEOI 1 
 * AEOI == 1 表明自动结束中断
 * */
void init_all(){
    idt_init();
    
}