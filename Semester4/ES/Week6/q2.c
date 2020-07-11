//C Program to display 8-bit binary up counter on the LEDs.

#include<LPC17xx.h>

unsigned int i,j,c=0;
unsigned long LED = 0x00000010;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	
	while(1)
	{
		LPC_GPIO0->FIOPIN=c<<4;
		for(i=0;i<10000;i++);
		
		if(c == 0x80)
			c=1;
		else
			c<<=1;
	}
}