//C Program to simulate a ring counter with switch ( SW2 ).

#include <LPC17xx.h>
int c = 0x1,temp=0x1;
unsigned int i;

int main(void)
{
	LPC_GPIO0->FIODIR = 0XFF0;
	LPC_GPIO2->FIODIR = 0XFFFFEFFF;
	while(1)
	{
		
		if(c==0x100)
			c = 0x1;
		else if(c==0x0)
			c = 0x10;
		
		LPC_GPIO0->FIOPIN = temp<<3;
		for(i=0;i<30000;i++);
		
		if(!(LPC_GPIO2->FIOPIN & 1<<12))
		{
			c <<= 1;
			temp = c;
		}
		
		else
		{
			temp = 0;
		}
	}
}