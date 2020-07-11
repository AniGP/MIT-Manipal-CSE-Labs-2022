//C Program to configure and read analog data from ADC channel number 5, and
//display the digital data on the LCD.

#include<LPC17xx.h>
#include<stdio.h>
#include "lcd_disp.c"
#define ref_vtg  3.300
#define full_scale 0xFFF //12 bit ADC

int main()
{
	unsigned long adc_temp;
	unsigned int i;
	float in_vtg;
	unsigned char vtg[7],dval[7];
	unsigned char Msg1[12]={"Analog Input"};
	unsigned char Msg[12]-{"Analog Output"};
	lcd_init();
	LPC_PINCON->PINSEL3=3<<30;
	LPC_SC->PCONP |=(1<<12);
	temp=0x80;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg1[0]);
	temp1=0xC0;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg2[0]);
	while(1)
	{
		LPC_ADC->ADCR=(1<<5)|(1<<21)|(1<<24);
		while((adc_temp=LPC_ADC->ADDR5)&0x80000000);
		adc_temp=LPC_ADC->ADDR5;
		//for(i=0;i<2000;i++)
		adc_temp>>=4;
		adc_temp &= 0x00000fff;
		in_vtg=((float) adc_temp * ref_vtg/full_scale);
		sprintf(vtg,"%3.2fV",in_vtg);
		sprintf(dval,"%x",adc_temp);
		for(i=0;i<2000;i++)
			temp1=0x89;
		lcd_com();
		lcd_puts(&vtg[0]);
		for(i=0;i<20000;i++);
		temp1=0xc8;
		lcd_com();
		delay_lcd(800);
		lcd_puts(&dval[0]);
		for(i=0;i<20000;i++);
		for(i=0;i<7;i++)
		{
			vtg[i]=dval[i]=0x00;
		}
		adc_temp=0;
		in_vtg=0;
	}
}