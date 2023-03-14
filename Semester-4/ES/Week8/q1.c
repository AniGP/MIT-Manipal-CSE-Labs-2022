//C Program to display message on LCD.

#include<LPC17xx.h>

#define RS_CTRL 0x08000000;
#define EN_CTRL 0x10000000;
#define DT_CTRL 0x07800000;

unsigned char msg3[11] = "MIT";
unsigned char msg4[20] = "Manipal, Dept. of CSE";
unsigned long int temp1 = 0, temp2 = 0;
void lcd_init(void);
void lcd_com(void);
void clear_ports(void);
void delay_lcd(unsigned int);
void lcd_puts(unsigned char*);
void lcd_data(void);
void wr_cn(void);
void wr_dn(void);

int main(void)
{
	lcd_init();
	temp1=0x80;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&msg3[0]);
	temp1=0xc0;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&msg4[0]);

}

void lcd_init(void)
{
	LPC_GPIO0->FIODIR |= DT_CTRL;
	LPC_GPIO0->FIODIR |= RS_CTRL;
	LPC_GPIO0->FIODIR |= EN_CTRL;
	clear_ports();
	delay_lcd(3200);
	temp1 = 0x33;
	lcd_com();
	delay_lcd(800);
	temp1 = 0x32;
	lcd_com();
	delay_lcd(800);
	temp1 = 0x28;
	lcd_com();
	delay_lcd(800);
	temp1 = 0x0c;
	lcd_com();
	delay_lcd(800);
	temp1 = 0x06;
	lcd_com();
	delay_lcd(800);
	temp1 = 0x01;
	lcd_com();
	delay_lcd(10000);
	return;
}

void clear_ports(void)
{
	LPC_GPIO0->FIOCLR = DT_CTRL;
	LPC_GPIO0->FIOCLR = RS_CTRL;
	LPC_GPIO0->FIOCLR = EN_CTRL;
}

void delay_lcd(unsigned int r1)
{
	unsigned int r;
	for(r=0; r<r1; r++);
	return;
}

void lcd_com(void)
{
	temp2 = temp1 & 0xf0;
	temp2 = temp2<<19;
	wr_cn();
	delay_lcd(30000);
	temp2 = temp1 & 0x0f;
	temp2 = temp2<<23;
	wr_cn();
	delay_lcd(30000);
	return;
}

void wr_cn()
{
	LPC_GPIO0->FIOPIN = temp2;
	LPC_GPIO0->FIOCLR = RS_CTRL;
	LPC_GPIO0->FIOSET = EN_CTRL;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = EN_CTRL;
}

void lcd_puts(unsigned char* buf)
{
	unsigned int i=0;
	while(buf[i]!='\0')
	{
		temp1=buf[i];
		lcd_data();
		delay_lcd(800);
		i++;
		if(i==16)
		{
			temp1=0xc0;
			lcd_com();
			delay_lcd(800);
		}
	} 
	return;
}

void lcd_data(void)
{
	temp2 = temp1 & 0xf0;
	temp2 = temp2<<19;
	wr_dn();
	delay_lcd(30000);
	temp2 = temp1 & 0x0f;
	temp2 = temp2<<23;
	wr_dn();
	delay_lcd(30000);
	return;
}

void wr_dn()
{
	LPC_GPIO0->FIOPIN = temp2;
	LPC_GPIO0->FIOSET = RS_CTRL;
	LPC_GPIO0->FIOSET = EN_CTRL;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = EN_CTRL;
	return;
}