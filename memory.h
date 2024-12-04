#ifndef __MEMORY_INCLUDED__
#define __MEMORY_INCLUDED__

#define REALLOC_ALLOC 2
#define REALLOC_FREE 4

#define REALLOC_REALLOC 0x10

void clear2(void *pData, unsigned int size);

int myDataOp(int op, unsigned char **pData, unsigned int size, unsigned int oldSize);

#endif