
#include <string.h>
#include <stdio.h>
#include "log_stack.h"

int used = STACK_LINES;

char stack[STACK_LINES][STACK_LINE_SIZE];

void clearStack()
{
    for (int i = 0; i < used; i++)
    {
        memset(&stack[i][0], 0, STACK_LINE_SIZE);
    }
    used = 0;
}
char *getLine()
{
    if (used < STACK_LINES)
    {
        ++used;
        return &stack[used - 1][0];
    }
    return NULL;
}
void printStack()
{
    for (int i = 0; i < used; i++)
    {
        printf("%s", &stack[i][0]);
    }
}