#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
	int top=-1;
	int stack[3];	
	printf("Length of stack = 3\n");
	push(stack,3, &top,1);
	push(stack,3, &top,2);
	push(stack,3, &top,3);
	push(stack,3, &top,4);
	printf("%d",pop(stack, &top));
	printf("%d",pop(stack, &top));
	printf("%d",pop(stack, &top));
	printf("%d",pop(stack, &top));
	exit(0);
}	
