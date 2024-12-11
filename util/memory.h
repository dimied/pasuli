#ifndef __MEMORY_INCLUDED__
#define __MEMORY_INCLUDED__

#ifndef USE_REALLOC_NO_COPY
#define USE_REALLOC_NO_COPY 0
#endif

#define REALLOC_ALLOC_IF_NEEDED 1
#define REALLOC_ALLOC 2
#define REALLOC_FREE 4

#if USE_REALLOC_NO_COPY
#define REALLOC_REALLOC_NO_COPY 0x8
#endif

#define REALLOC_COPY 0x10

#if USE_REALLOC_NO_COPY
#define REALLOC_REALLOC (REALLOC_REALLOC_NO_COPY | REALLOC_COPY)
#else
#define REALLOC_REALLOC REALLOC_COPY
#endif

#define REALLOC_INVERT 0x20

#define REALLOC_NULLIFY 0x40
#define REALLOC_NULLIFY_MASK (0x3F)

// #define USE_MY_DATA_OP_DEBUG 1

#ifndef USE_FAST_CLEAR_MEM
#define USE_FAST_CLEAR_MEM 0
#endif

#ifndef USE_MY_DATA_OP_DEBUG
#define USE_MY_DATA_OP_DEBUG 0
#endif

#define DATA_OP_RESULT_OK 0
#define DATA_OP_RESULT_INVALID 1
#define DATA_OP_RESULT_PARAM_INVALID 2

void clear2(void *pData, unsigned int size);

// c8, NO_COPY=b9
int myDataOp(int op, unsigned char **pData, unsigned int size, unsigned int oldSize);

#endif