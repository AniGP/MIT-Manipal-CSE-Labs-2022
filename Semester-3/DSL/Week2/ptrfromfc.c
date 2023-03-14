#include<stdio.h>
void exchange(int a ,int b);

void exchange(int *px, int *py)
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;

	return;
}

int main()
{
	int a,b;
	printf("Enter : ");
	scanf("%d%d",&a,&b);
	exchange(a,b);
	printf("%d%d",a,b);
    
    return 0;
}

