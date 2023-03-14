#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
	int r;
	int img;
}COMPLEX;

void read(COMPLEX *c1)
{
	printf("Enter the Complex Number\n");
	scanf("%d+%di",&c1->r,&c1->img);
}
void add(COMPLEX *c1,COMPLEX *c2,COMPLEX *ans)
{
	ans->r=c1->r+c2->r;
	ans->img=c1->img+c2->img;
}
void subt(COMPLEX *c1,COMPLEX *c2,COMPLEX* ans)
{
	ans->r=c1->r-c2->r;
	ans->img=c1->img-c2->img;
}
void mult(COMPLEX *c1,COMPLEX *c2,COMPLEX *ans)
{
	ans->r=c1->r*c2->r-c1->img*c2->img;
	ans->img=c1->r*c2->img+c1->img*c2->r;
}
void disp(COMPLEX *c)
{
	if(c.img>0)
	{
	   printf("%d+%di",c.r,c.img);
	}
	
	else if(c.img<0)
	{
		printf("%d-%di",c.r,abs(c.img));
	}
	else
	{
		printf("%d",c.r);
	}
}
\
int main()
{
	COMPLEX x,y,sum,diff,prod;
	read(&x);
	read(&y);
	
	add(&x,&y,&sum);
	subt(&x,&y,&diff);
	mult(&x,&y,&prod);
	
	printf("Sum = ");
	disp(sum);
	
	printf("Difference = ");
	disp(diff);
	
	printf("Product = ");
	disp(prod);

	return 0;
}