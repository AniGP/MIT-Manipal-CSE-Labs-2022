//C Program to do the following - Varying intensity using Row 0 of Matrix Keyboard.

/* Intensity Level 		Key Pressed
		10%					0
		25%					1
		50%					2
		75%					3
*/

#include<LPC17xx.h>

void initpwm(void);
void updatepulsewidth(unsigned int pulsewidth);
void delayms(unsigned int milliseconds);
int scan(void);
unsigned int temp3;
int pulsewidth[]={0,2500,5000,10000};
int dir=0;

int main(void)
{
	LPC_GPIO0->FIODIR = 0xf00;
	initpwm();
	while(1)
	{
		int count=scan();
		if(count==0x1)
			updatepulsewidth(pulsewidth[0]);
		else if(count==0x2)
			updatepulsewidth(pulsewidth[1]);
		else if(count==0x4)
			updatepulsewidth(pulsewidth[2]);
		else if(count==0x8)
			updatepulsewidth(pulsewidth[3]);
		delayms(100000);
	}

}

void initpwm(void)
{
	LPC_PINCON->PINSEL3|=0x8000;
	LPC_PWM1->PCR=0x1000;
	LPC_PWM1->PR=0;
	LPC_PWM1->MR0=10000;
	LPC_PWM1->MCR=2;
	LPC_PWM1->LER=0xff;
	LPC_PWM1->TCR=0x2;
	LPC_PWM1->TCR=0x9;
}

void updatepulsewidth(unsigned int pulsewidth)
{
	LPC_PWM1->MR4=pulsewidth;
	LPC_PWM1->LER=0xff;
}

void delayms(unsigned int milliseconds)
{
	LPC_TIM0->CTCR=0x0;
	LPC_TIM0->PR=2;
	LPC_TIM0->TCR=0x02;
	LPC_TIM0->TCR=0x1;
	while(LPC_TIM0->TC<milliseconds);
	LPC_TIM0->TCR=0;
}

int scan(void)
{
	LPC_GPIO0->FIOSET = 0x100;
	temp3 = LPC_GPIO0->FIOPIN;
	temp3 &= 0xf0;
	if(temp3!=0)
		return temp3>>4;
	return 1;
}