#ifndef __PRIME_NUMBER_COMPRESSOR__
#define __PRIME_NUMBER_COMPRESSOR__

/*
typedef struct _LINT
{
	union
	{
		unsigned int* x;//polynomial data
		unsigned char* byte_data;
	};
	unsigned long long size;//allocated size, measured in blocks of 32 bits
	unsigned long long used_size;//actual space occupied by the number, measured in blocks of 32 bits
	unsigned char sign;//0=positive,anything else=negative
}LINT;
*/

#define REALLOC_ALLOC 2
#define REALLOC_FREE 4

#define REALLOC_REALLOC 0x10

int myDataOp(int op, unsigned char **pData, unsigned int size, unsigned int oldSize);

#define INITIAL_INIT_SIZE 2

#define INT_OP_CLEAR_SRC 1
#define INT_OP_CLEAR_SRC2 2
#define INT_OP_CLEAR_RESULT 4
#define INT_OP_CLEAR_ALL (INT_OP_CLEAR_SRC|INT_OP_CLEAR_SRC2|INT_OP_CLEAR_RESULT)

#define INT_INTERNAL_CHECK_CLEAR(OP, VAL)    ((OP&VAL) == VAL)
//
#define INT_OP_INIT_SRC 0x10
#define INT_OP_INIT_SRC2 0x20
#define INT_OP_INIT_RESULT 0x40
#define INT_OP_INIT_ALL (INT_OP_INIT_SRC|INT_OP_INIT_SRC2|INT_OP_INIT_RESULT)

#define INT_INTERNAL_CHECK_INIT(OP, VAL)    ((OP&VAL) == VAL)
//
#define INT_OP_ZERO 0x80
#define INT_OP_ONE 0x81
//
#define INT_OP_ADD 0x82
#define INT_OP_SUB 0x83
#define INT_OP_MUL 0x84
#define INT_OP_DIV 0x85

#define INT_ALLOCATION_ERROR 10
#define INT_COMMAND_ERROR 11

typedef struct _MYINT
{
	unsigned char *pBytes;
	unsigned char *pBuffer;

	unsigned int size;		// allocated size in bytes
	unsigned int used_size; // actual space occupied by the number in bytes
	unsigned int buffer_size;
	unsigned char sign; //stores sign
	unsigned char options;
	struct _MYINT *rest; //rest for 
} MYINT;

int myintOp(int op, MYINT* pSrc, MYINT* pSrc2,MYINT* pResult);

extern int compressType;

void compress(void *pData, int size, void *pResultData, int resultSize);
#endif