//C Program to simulate an up/down ring counter with switch,i.e, 
//key press ( SW2 ).

#include <LPC17xx.h>

unsigned int i,j,c=0;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPI0->FIODIR |= 0x00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0x0;

	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
		{
			c++;
		}

		else
		{
			c--;
		}

		if(c == -1)
		{
			c=0xFF;
		}

		if(c == 0x100)
		{
			c=0x00;
		}

		LPC_GPIO0->FIOPIN = c<<4;

		for(i=0;i<500000;i++);
	}
}