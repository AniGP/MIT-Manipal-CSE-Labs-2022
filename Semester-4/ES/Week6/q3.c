//C Program to simulate an 8-bit ring counter with key press( SW2 ).

#include<LPC17xx.h>

unsigned int i,j,c=0;
unsigned long LED = 0x00000010;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	
	while(1)
	{
		c++;
		LPC_GPIO0->FIOPIN=c<<4;
		
		for(i=0;i<100000;i++);
		c<<=1;
		
		if(c == 0x100)
		{
			c=1;
		}
	}
}