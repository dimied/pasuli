#ifndef __LOG_STACK__
#define __LOG_STACK__

#define STACK_LINE_SIZE 1024
#define STACK_LINES 32

void clearStack();
char* getLine();
void printStack();

#endif