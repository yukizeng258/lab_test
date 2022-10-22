#define GPL2CON (*(volatile unsigned long*)0x11000100)
#define GPL2DAT (*(volatile unsigned long*)0x11000104)

#define GPK1CON (*(volatile unsigned long*)0x11000060)
#define GPK1DAT (*(volatile unsigned long*)0x11000064)
#define GPD0CON	(*(volatile unsigned long*)0x114000A0)
#define GPD0DAT (*(volatile unsigned long*)0x114000A4)

void delay(int r0)
{
	volatile int count =r0;
while (count --)
;
}

void led_blink()
{
GPL2CON &= 0xfffffff0;
GPL2CON |= 0x00000001;
GPK1CON &= 0xffffff0f;
GPK1CON |= 0x00000010;
GPD0CON &= 0xfffffff0;
GPD0CON |= 0x00000001;
while(1)
	{	
	GPL2DAT &= 0xf0;
	GPK1DAT &=0xf0;
	GPD0DAT &=0xf0;
	delay(0x80000);
	GPL2DAT |= 0x1;
	GPK1DAT |=0x02;
	GPD0DAT |=0xf1;
	delay(0x80000);
	}
} 
void main()
{
led_blink();
return ;
}
