#include "stack.h"

void stack_push(STACK* a, int ele)
{
    int n = (a->top);
    a->arr = (int*)realloc(a->arr, (n+1)*sizeof(int));
    *((a->arr)+n) = ele;
    (a->top) = n+1;
}