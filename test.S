.global _start
_start:
 
/*
mov r1, #1 * set GPM4_0 as output
*/
ldr r0, =0x11000100
bic r0,r0,#0xfffffffe
orr r0,r0,#0x00000001
ldr r5, =0x11000060
bic r5,r5,#0xffffffef
orr r5,r5,#0x00000010
ldr r6, =0x110000A0
bic r6,r6,#0xffffff5f
orr r6,r6,#0x000000A0

leds_loop:
/*
*set GPM4_0 as Low
*/
ldr r0, =0x11000104 //
ldr r3, =0x11000064
ldr r4, =0x110000A4
ldr r1, [r0] // 
bic r1, r1, #1 // 清除bit[0]为0,led亮
str r1, [r0] // 写入GPM4_0

ldr r2,=0xffffff
bl delay

orr r1, r1, #0xf
str r1, [r0] // 写1 led灭
ldr r2,=0xffffff
bl delay

b leds_loop
halt_loop:
b halt_loop
 
delay:
sub r2,r2,#1 //sub 减法
cmp r2,#0x0 //将r0 与0比较
bne delay //b是跳 ne 是不相等 ，不相等就跳到delay
mov pc,lr //lr 里存的是调用函数时的下一条指令，让Pc指针指向lr就可以完成函数的返回

