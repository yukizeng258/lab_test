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
GPL2CON &= 0xfffffffe;
GPL2CON |= 0x00000001;
GPK1CON &= 0xffffffef;
GPK1CON |= 0x00000010;
GPD0CON &= 0xfffffffe;
GPD0CON |= 0x00000001;
while(1)
	{	
	GPL2DAT=1;
	GPK1DAT=0;
	GPD0DAT=1;
	delay(0x80000);
	GPL2DAT=0;
	GPK1DAT=0x2;
	GPD0DAT=0;
	delay(0x80000);
	}
} 
void main()
{
led_blink();
return ;
}
