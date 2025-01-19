
main:     file format elf32-i386


Disassembly of section .text:

c0001500 <_start>:
c0001500:	55                   	push   %ebp
c0001501:	89 e5                	mov    %esp,%ebp
c0001503:	83 ec 08             	sub    $0x8,%esp
c0001506:	e8 1d 00 00 00       	call   c0001528 <__x86.get_pc_thunk.ax>
c000150b:	05 7d 01 00 00       	add    $0x17d,%eax
c0001510:	e8 03 00 00 00       	call   c0001518 <main>
c0001515:	90                   	nop
c0001516:	eb fd                	jmp    c0001515 <_start+0x15>

c0001518 <main>:
c0001518:	55                   	push   %ebp
c0001519:	89 e5                	mov    %esp,%ebp
c000151b:	e8 08 00 00 00       	call   c0001528 <__x86.get_pc_thunk.ax>
c0001520:	05 68 01 00 00       	add    $0x168,%eax
c0001525:	90                   	nop
c0001526:	eb fd                	jmp    c0001525 <main+0xd>

Disassembly of section .text.__x86.get_pc_thunk.ax:

c0001528 <__x86.get_pc_thunk.ax>:
c0001528:	8b 04 24             	mov    (%esp),%eax
c000152b:	c3                   	ret
