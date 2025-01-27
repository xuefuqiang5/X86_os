[bits 32]
section .text
global out8
out8:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  mov al, [ebp+12]
  out dx, al
  pop ebp
  ret

global out16
out16:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  mov ax, [ebp+12]
  out dx, ax
  pop ebp
  ret

global out32
out32:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  mov eax, [ebp+12]
  out dx, eax
  pop ebp
  ret

global in8
in8:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  xor eax, eax
  in al, dx
  pop ebp
  ret

global in16
in16:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  xor eax, eax
  in ax, dx
  pop ebp
  ret

global in32
in32:
  push ebp
  mov ebp, esp
  mov dx, [ebp+8]
  xor eax, eax
  in eax, dx
  pop ebp
  ret
global ex_write
ex_write:
  push ebp 
  mov ebp, esp
  mov eax, [ebp + 8]
  mov ecx, [ebp + 0xc]
  mov edx, [ebp + 0x10]
  mov al, [gs:eax]
  mov [gs:ecx], al
  mov byte [gs:edx], 0x0f
  pop ebp
  ret 

global write_one_char
write_one_char:
  push ebp
  mov ebp, esp
  mov eax, [ebp + 8]
  mov cl, [ebp + 0xc]
  mov [gs:eax], cl
  inc eax
  mov [gs:eax], byte 0x0f
  pop ebp
  ret


  global lidt
lidt:
  push ebp
  mov ebp, esp
  mov eax, [ebp+8]
  lidt [eax]
  pop ebp
  ret
  
global intr_enable
  intr_enable:
    push ebp 
    mov ebp, esp
    pushf 
    sti
    pop eax
    and eax, 0x200
    pop ebp 
    ret  
global intr_disable
  intr_disable:
    push ebp 
    mov ebp, esp
    pushf 
    cli
    pop eax
    and eax, 0x200
    pop ebp 
    ret  