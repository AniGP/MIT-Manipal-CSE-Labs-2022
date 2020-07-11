//C Program to display the digital value representing the
//difference in analog voltage and ADC channel 4 and channel 5 
//on LCD using BURST and Software Mode.

#include <LPC17xx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lcd_msg.h"
#define Ref_Vtg  3.3
#define Full_Scale 0xFFF

unsigned char str[]={"0123456789"};
unsigned long x,temp,t1=0,t2=0;
unsigned int channel,result,i,j, flag1;
unsigned char Msg1[10]={"ADC value"};

void ADC_IRQHandler(void)
{
	x=LPC_ADC->ADSTAT&(3<<4);
	if(x == (x & 1 << 4)) {
		t1 = (LPC_ADC->ADDR4&(0xFFF<<4)>>4);
	} else {
		t2 = (LPC_ADC->ADDR5&(0xFFF<<4)>>4);
	}
	t1 = ceil((t1*3.3)/4096);
	t2 = ceil((t2*3.3)/4096);
	result = abs(t1-t2);
	Msg1[0] = str[result];
	Msg1[1] = '\0';
	temp1 = 0xc0;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg1[0]);
}

int main(void)
{
	
	lcd_init();
	LPC_PINCON->PINSEL3=(0xF)<<28; //P1.31 as AD0.5
	LPC_SC->PCONP |=(1<<12);
	LPC_ADC->ADCR = (1 << 4 | 1 << 5 | 1 << 16 | 1 << 21);
	LPC_ADC->ADINTEN = (1<<4|1<<5);
	flag1 = 1;
	temp1=0x80;
	lcd_com();
	delay_lcd(800);
	lcd_puts(Msg1);
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
