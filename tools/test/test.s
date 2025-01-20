
test:     file format elf32-i386


Disassembly of section .init:

00001000 <_init>:
    1000:	53                   	push   %ebx
    1001:	83 ec 08             	sub    $0x8,%esp
    1004:	e8 87 00 00 00       	call   1090 <__x86.get_pc_thunk.bx>
    1009:	81 c3 d3 2f 00 00    	add    $0x2fd3,%ebx
    100f:	8b 83 18 00 00 00    	mov    0x18(%ebx),%eax
    1015:	85 c0                	test   %eax,%eax
    1017:	74 02                	je     101b <_init+0x1b>
    1019:	ff d0                	call   *%eax
    101b:	83 c4 08             	add    $0x8,%esp
    101e:	5b                   	pop    %ebx
    101f:	c3                   	ret

Disassembly of section .plt:

00001020 <__libc_start_main@plt-0x10>:
    1020:	ff b3 04 00 00 00    	push   0x4(%ebx)
    1026:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
    102c:	00 00                	add    %al,(%eax)
	...

00001030 <__libc_start_main@plt>:
    1030:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

00001040 <__cxa_finalize@plt>:
    1040:	ff a3 14 00 00 00    	jmp    *0x14(%ebx)
    1046:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00001050 <main>:
    1050:	31 c0                	xor    %eax,%eax
    1052:	c3                   	ret
    1053:	66 90                	xchg   %ax,%ax
    1055:	66 90                	xchg   %ax,%ax
    1057:	66 90                	xchg   %ax,%ax
    1059:	66 90                	xchg   %ax,%ax
    105b:	66 90                	xchg   %ax,%ax
    105d:	66 90                	xchg   %ax,%ax
    105f:	90                   	nop

00001060 <_start>:
    1060:	31 ed                	xor    %ebp,%ebp
    1062:	5e                   	pop    %esi
    1063:	89 e1                	mov    %esp,%ecx
    1065:	83 e4 f0             	and    $0xfffffff0,%esp
    1068:	50                   	push   %eax
    1069:	54                   	push   %esp
    106a:	52                   	push   %edx
    106b:	e8 18 00 00 00       	call   1088 <_start+0x28>
    1070:	81 c3 6c 2f 00 00    	add    $0x2f6c,%ebx
    1076:	6a 00                	push   $0x0
    1078:	6a 00                	push   $0x0
    107a:	51                   	push   %ecx
    107b:	56                   	push   %esi
    107c:	ff b3 1c 00 00 00    	push   0x1c(%ebx)
    1082:	e8 a9 ff ff ff       	call   1030 <__libc_start_main@plt>
    1087:	f4                   	hlt
    1088:	8b 1c 24             	mov    (%esp),%ebx
    108b:	c3                   	ret
    108c:	66 90                	xchg   %ax,%ax
    108e:	66 90                	xchg   %ax,%ax

00001090 <__x86.get_pc_thunk.bx>:
    1090:	8b 1c 24             	mov    (%esp),%ebx
    1093:	c3                   	ret
    1094:	66 90                	xchg   %ax,%ax
    1096:	66 90                	xchg   %ax,%ax
    1098:	66 90                	xchg   %ax,%ax
    109a:	66 90                	xchg   %ax,%ax
    109c:	66 90                	xchg   %ax,%ax
    109e:	66 90                	xchg   %ax,%ax

000010a0 <deregister_tm_clones>:
    10a0:	e8 e4 00 00 00       	call   1189 <__x86.get_pc_thunk.dx>
    10a5:	81 c2 37 2f 00 00    	add    $0x2f37,%edx
    10ab:	8d 8a 2c 00 00 00    	lea    0x2c(%edx),%ecx
    10b1:	8d 82 2c 00 00 00    	lea    0x2c(%edx),%eax
    10b7:	39 c8                	cmp    %ecx,%eax
    10b9:	74 1d                	je     10d8 <deregister_tm_clones+0x38>
    10bb:	8b 82 10 00 00 00    	mov    0x10(%edx),%eax
    10c1:	85 c0                	test   %eax,%eax
    10c3:	74 13                	je     10d8 <deregister_tm_clones+0x38>
    10c5:	55                   	push   %ebp
    10c6:	89 e5                	mov    %esp,%ebp
    10c8:	83 ec 14             	sub    $0x14,%esp
    10cb:	51                   	push   %ecx
    10cc:	ff d0                	call   *%eax
    10ce:	83 c4 10             	add    $0x10,%esp
    10d1:	c9                   	leave
    10d2:	c3                   	ret
    10d3:	2e 8d 74 26 00       	lea    %cs:0x0(%esi,%eiz,1),%esi
    10d8:	c3                   	ret
    10d9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

000010e0 <register_tm_clones>:
    10e0:	e8 a4 00 00 00       	call   1189 <__x86.get_pc_thunk.dx>
    10e5:	81 c2 f7 2e 00 00    	add    $0x2ef7,%edx
    10eb:	55                   	push   %ebp
    10ec:	89 e5                	mov    %esp,%ebp
    10ee:	53                   	push   %ebx
    10ef:	8d 8a 2c 00 00 00    	lea    0x2c(%edx),%ecx
    10f5:	8d 82 2c 00 00 00    	lea    0x2c(%edx),%eax
    10fb:	83 ec 04             	sub    $0x4,%esp
    10fe:	29 c8                	sub    %ecx,%eax
    1100:	89 c3                	mov    %eax,%ebx
    1102:	c1 e8 1f             	shr    $0x1f,%eax
    1105:	c1 fb 02             	sar    $0x2,%ebx
    1108:	01 d8                	add    %ebx,%eax
    110a:	d1 f8                	sar    $1,%eax
    110c:	74 14                	je     1122 <register_tm_clones+0x42>
    110e:	8b 92 20 00 00 00    	mov    0x20(%edx),%edx
    1114:	85 d2                	test   %edx,%edx
    1116:	74 0a                	je     1122 <register_tm_clones+0x42>
    1118:	83 ec 08             	sub    $0x8,%esp
    111b:	50                   	push   %eax
    111c:	51                   	push   %ecx
    111d:	ff d2                	call   *%edx
    111f:	83 c4 10             	add    $0x10,%esp
    1122:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1125:	c9                   	leave
    1126:	c3                   	ret
    1127:	2e 8d b4 26 00 00 00 	lea    %cs:0x0(%esi,%eiz,1),%esi
    112e:	00 
    112f:	90                   	nop

00001130 <__do_global_dtors_aux>:
    1130:	f3 0f 1e fb          	endbr32
    1134:	55                   	push   %ebp
    1135:	89 e5                	mov    %esp,%ebp
    1137:	53                   	push   %ebx
    1138:	e8 53 ff ff ff       	call   1090 <__x86.get_pc_thunk.bx>
    113d:	81 c3 9f 2e 00 00    	add    $0x2e9f,%ebx
    1143:	83 ec 04             	sub    $0x4,%esp
    1146:	80 bb 2c 00 00 00 00 	cmpb   $0x0,0x2c(%ebx)
    114d:	75 27                	jne    1176 <__do_global_dtors_aux+0x46>
    114f:	8b 83 14 00 00 00    	mov    0x14(%ebx),%eax
    1155:	85 c0                	test   %eax,%eax
    1157:	74 11                	je     116a <__do_global_dtors_aux+0x3a>
    1159:	83 ec 0c             	sub    $0xc,%esp
    115c:	ff b3 28 00 00 00    	push   0x28(%ebx)
    1162:	e8 d9 fe ff ff       	call   1040 <__cxa_finalize@plt>
    1167:	83 c4 10             	add    $0x10,%esp
    116a:	e8 31 ff ff ff       	call   10a0 <deregister_tm_clones>
    116f:	c6 83 2c 00 00 00 01 	movb   $0x1,0x2c(%ebx)
    1176:	8b 5d fc             	mov    -0x4(%ebp),%ebx
    1179:	c9                   	leave
    117a:	c3                   	ret
    117b:	2e 8d 74 26 00       	lea    %cs:0x0(%esi,%eiz,1),%esi

00001180 <frame_dummy>:
    1180:	f3 0f 1e fb          	endbr32
    1184:	e9 57 ff ff ff       	jmp    10e0 <register_tm_clones>

00001189 <__x86.get_pc_thunk.dx>:
    1189:	8b 14 24             	mov    (%esp),%edx
    118c:	c3                   	ret
    118d:	66 90                	xchg   %ax,%ax
    118f:	90                   	nop

00001190 <sum>:
    1190:	8b 44 24 08          	mov    0x8(%esp),%eax
    1194:	03 44 24 04          	add    0x4(%esp),%eax
    1198:	03 44 24 0c          	add    0xc(%esp),%eax
    119c:	03 44 24 10          	add    0x10(%esp),%eax
    11a0:	c3                   	ret

Disassembly of section .fini:

000011a4 <_fini>:
    11a4:	53                   	push   %ebx
    11a5:	83 ec 08             	sub    $0x8,%esp
    11a8:	e8 e3 fe ff ff       	call   1090 <__x86.get_pc_thunk.bx>
    11ad:	81 c3 2f 2e 00 00    	add    $0x2e2f,%ebx
    11b3:	83 c4 08             	add    $0x8,%esp
    11b6:	5b                   	pop    %ebx
    11b7:	c3                   	ret
