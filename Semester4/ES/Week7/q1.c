//C Program to display 4 3 2 1 on the 7 Segment Display.

#include <LPC17xx.h>
#include<stdio.h>

void delay(void);
void display(void);
unsigned char dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int dig_count = 0;
unsigned int dig_value[4] = {4,3,2,1};
unsigned int dig_select[4] = {0<<23, 1<<23, 2<<23, 3<<23};

int main(void)
{
	LPC_GPIO0->FIODIR=0xFF<<4;
	LPC_GPIO1->FIODIR=0xF<<23;
	while(1)
	{
		delay();
		display();
		dig_count+=1;
		if(dig_count==4)
		{
			dig_count=0;
		}
	}
}

void display(void)
{
	LPC_GPIO1->FIOPIN=dig_select[dig_count];
	LPC_GPIO0->FIOPIN=dec[dig_value[dig_count]]<<4;
}

void delay(void)
{
	unsigned int i;
	for(i=0;i<100000;i++);
}