#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int top;
    int *arr;
}STACK;

int stack_pop(STACK*);
void stack_push(STACK*, int);