
main:     file format elf32-i386


Disassembly of section .init:

00001000 <_init>:
    1000:	53                   	push   %ebx
    1001:	83 ec 08             	sub    $0x8,%esp
    1004:	e8 87 00 00 00       	call   1090 <__x86.get_pc_thunk.bx>
    1009:	81 c3 cf 2f 00 00    	add    $0x2fcf,%ebx
    100f:	8b 83 1c 00 00 00    	mov    0x1c(%ebx),%eax
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

00001040 <printf@plt>:
    1040:	ff a3 10 00 00 00    	jmp    *0x10(%ebx)
    1046:	68 08 00 00 00       	push   $0x8
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

00001050 <__cxa_finalize@plt>:
    1050:	ff a3 18 00 00 00    	jmp    *0x18(%ebx)
    1056:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00001060 <_start>:
    1060:	31 ed                	xor    %ebp,%ebp
    1062:	5e                   	pop    %esi
    1063:	89 e1                	mov    %esp,%ecx
    1065:	83 e4 f0             	and    $0xfffffff0,%esp
    1068:	50                   	push   %eax
    1069:	54                   	push   %esp
    106a:	52                   	push   %edx
    106b:	e8 18 00 00 00       	call   1088 <_start+0x28>
    1070:	81 c3 68 2f 00 00    	add    $0x2f68,%ebx
    1076:	6a 00                	push   $0x0
    1078:	6a 00                	push   $0x0
    107a:	51                   	push   %ecx
    107b:	56                   	push   %esi
    107c:	ff b3 20 00 00 00    	push   0x20(%ebx)
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
    10a5:	81 c2 33 2f 00 00    	add    $0x2f33,%edx
    10ab:	8d 8a 30 00 00 00    	lea    0x30(%edx),%ecx
    10b1:	8d 82 30 00 00 00    	lea    0x30(%edx),%eax
    10b7:	39 c8                	cmp    %ecx,%eax
    10b9:	74 1d                	je     10d8 <deregister_tm_clones+0x38>
    10bb:	8b 82 14 00 00 00    	mov    0x14(%edx),%eax
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
    10e5:	81 c2 f3 2e 00 00    	add    $0x2ef3,%edx
    10eb:	55                   	push   %ebp
    10ec:	89 e5                	mov    %esp,%ebp
    10ee:	53                   	push   %ebx
    10ef:	8d 8a 30 00 00 00    	lea    0x30(%edx),%ecx
    10f5:	8d 82 30 00 00 00    	lea    0x30(%edx),%eax
    10fb:	83 ec 04             	sub    $0x4,%esp
    10fe:	29 c8                	sub    %ecx,%eax
    1100:	89 c3                	mov    %eax,%ebx
    1102:	c1 e8 1f             	shr    $0x1f,%eax
    1105:	c1 fb 02             	sar    $0x2,%ebx
    1108:	01 d8                	add    %ebx,%eax
    110a:	d1 f8                	sar    $1,%eax
    110c:	74 14                	je     1122 <register_tm_clones+0x42>
    110e:	8b 92 24 00 00 00    	mov    0x24(%edx),%edx
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
    113d:	81 c3 9b 2e 00 00    	add    $0x2e9b,%ebx
    1143:	83 ec 04             	sub    $0x4,%esp
    1146:	80 bb 30 00 00 00 00 	cmpb   $0x0,0x30(%ebx)
    114d:	75 27                	jne    1176 <__do_global_dtors_aux+0x46>
    114f:	8b 83 18 00 00 00    	mov    0x18(%ebx),%eax
    1155:	85 c0                	test   %eax,%eax
    1157:	74 11                	je     116a <__do_global_dtors_aux+0x3a>
    1159:	83 ec 0c             	sub    $0xc,%esp
    115c:	ff b3 2c 00 00 00    	push   0x2c(%ebx)
    1162:	e8 e9 fe ff ff       	call   1050 <__cxa_finalize@plt>
    1167:	83 c4 10             	add    $0x10,%esp
    116a:	e8 31 ff ff ff       	call   10a0 <deregister_tm_clones>
    116f:	c6 83 30 00 00 00 01 	movb   $0x1,0x30(%ebx)
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

0000118d <main>:
    118d:	8d 4c 24 04          	lea    0x4(%esp),%ecx
    1191:	83 e4 f0             	and    $0xfffffff0,%esp
    1194:	ff 71 fc             	push   -0x4(%ecx)
    1197:	55                   	push   %ebp
    1198:	89 e5                	mov    %esp,%ebp
    119a:	53                   	push   %ebx
    119b:	51                   	push   %ecx
    119c:	83 ec 10             	sub    $0x10,%esp
    119f:	e8 ec fe ff ff       	call   1090 <__x86.get_pc_thunk.bx>
    11a4:	81 c3 34 2e 00 00    	add    $0x2e34,%ebx
    11aa:	83 ec 08             	sub    $0x8,%esp
    11ad:	6a 14                	push   $0x14
    11af:	6a 0a                	push   $0xa
    11b1:	e8 8f 00 00 00       	call   1245 <sub>
    11b6:	83 c4 10             	add    $0x10,%esp
    11b9:	89 45 ec             	mov    %eax,-0x14(%ebp)
    11bc:	83 ec 08             	sub    $0x8,%esp
    11bf:	ff 75 ec             	push   -0x14(%ebp)
    11c2:	8d 83 30 e0 ff ff    	lea    -0x1fd0(%ebx),%eax
    11c8:	50                   	push   %eax
    11c9:	e8 72 fe ff ff       	call   1040 <printf@plt>
    11ce:	83 c4 10             	add    $0x10,%esp
    11d1:	83 ec 08             	sub    $0x8,%esp
    11d4:	6a 14                	push   $0x14
    11d6:	6a 0a                	push   $0xa
    11d8:	e8 51 00 00 00       	call   122e <add>
    11dd:	83 c4 10             	add    $0x10,%esp
    11e0:	89 45 f0             	mov    %eax,-0x10(%ebp)
    11e3:	83 ec 08             	sub    $0x8,%esp
    11e6:	ff 75 f0             	push   -0x10(%ebp)
    11e9:	8d 83 30 e0 ff ff    	lea    -0x1fd0(%ebx),%eax
    11ef:	50                   	push   %eax
    11f0:	e8 4b fe ff ff       	call   1040 <printf@plt>
    11f5:	83 c4 10             	add    $0x10,%esp
    11f8:	83 ec 08             	sub    $0x8,%esp
    11fb:	6a 14                	push   $0x14
    11fd:	6a 0a                	push   $0xa
    11ff:	e8 7c 00 00 00       	call   1280 <ass_add>
    1204:	83 c4 10             	add    $0x10,%esp
    1207:	89 45 f4             	mov    %eax,-0xc(%ebp)
    120a:	83 ec 08             	sub    $0x8,%esp
    120d:	ff 75 f4             	push   -0xc(%ebp)
    1210:	8d 83 30 e0 ff ff    	lea    -0x1fd0(%ebx),%eax
    1216:	50                   	push   %eax
    1217:	e8 24 fe ff ff       	call   1040 <printf@plt>
    121c:	83 c4 10             	add    $0x10,%esp
    121f:	b8 00 00 00 00       	mov    $0x0,%eax
    1224:	8d 65 f8             	lea    -0x8(%ebp),%esp
    1227:	59                   	pop    %ecx
    1228:	5b                   	pop    %ebx
    1229:	5d                   	pop    %ebp
    122a:	8d 61 fc             	lea    -0x4(%ecx),%esp
    122d:	c3                   	ret

0000122e <add>:
    122e:	55                   	push   %ebp
    122f:	89 e5                	mov    %esp,%ebp
    1231:	e8 3a 00 00 00       	call   1270 <__x86.get_pc_thunk.ax>
    1236:	05 a2 2d 00 00       	add    $0x2da2,%eax
    123b:	8b 55 08             	mov    0x8(%ebp),%edx
    123e:	8b 45 0c             	mov    0xc(%ebp),%eax
    1241:	01 d0                	add    %edx,%eax
    1243:	5d                   	pop    %ebp
    1244:	c3                   	ret

00001245 <sub>:
    1245:	55                   	push   %ebp
    1246:	89 e5                	mov    %esp,%ebp
    1248:	e8 23 00 00 00       	call   1270 <__x86.get_pc_thunk.ax>
    124d:	05 8b 2d 00 00       	add    $0x2d8b,%eax
    1252:	8b 45 08             	mov    0x8(%ebp),%eax
    1255:	2b 45 0c             	sub    0xc(%ebp),%eax
    1258:	5d                   	pop    %ebp
    1259:	c3                   	ret

0000125a <mul>:
    125a:	55                   	push   %ebp
    125b:	89 e5                	mov    %esp,%ebp
    125d:	e8 0e 00 00 00       	call   1270 <__x86.get_pc_thunk.ax>
    1262:	05 76 2d 00 00       	add    $0x2d76,%eax
    1267:	8b 45 08             	mov    0x8(%ebp),%eax
    126a:	0f af 45 0c          	imul   0xc(%ebp),%eax
    126e:	5d                   	pop    %ebp
    126f:	c3                   	ret

00001270 <__x86.get_pc_thunk.ax>:
    1270:	8b 04 24             	mov    (%esp),%eax
    1273:	c3                   	ret
    1274:	66 90                	xchg   %ax,%ax
    1276:	66 90                	xchg   %ax,%ax
    1278:	66 90                	xchg   %ax,%ax
    127a:	66 90                	xchg   %ax,%ax
    127c:	66 90                	xchg   %ax,%ax
    127e:	66 90                	xchg   %ax,%ax

00001280 <ass_add>:
    1280:	55                   	push   %ebp
    1281:	89 e5                	mov    %esp,%ebp
    1283:	8b 45 08             	mov    0x8(%ebp),%eax
    1286:	8b 5d 0c             	mov    0xc(%ebp),%ebx
    1289:	01 d8                	add    %ebx,%eax
    128b:	5d                   	pop    %ebp
    128c:	c3                   	ret

Disassembly of section .fini:

00001290 <_fini>:
    1290:	53                   	push   %ebx
    1291:	83 ec 08             	sub    $0x8,%esp
    1294:	e8 f7 fd ff ff       	call   1090 <__x86.get_pc_thunk.bx>
    1299:	81 c3 3f 2d 00 00    	add    $0x2d3f,%ebx
    129f:	83 c4 08             	add    $0x8,%esp
    12a2:	5b                   	pop    %ebx
    12a3:	c3                   	ret
