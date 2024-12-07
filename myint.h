#ifndef __MY_INT__
#define __MY_INT__

#include <stdint.h>


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

#define INT_OP_CMP_ABS 0x90
#define INT_OP_CMP 0x91

#define INT_RESULT_CMP_EQUAL 0
#define INT_RESULT_CMP_LESS 1
#define INT_RESULT_CMP_GREATER 2

#define INT_ALLOCATION_ERROR 10
#define INT_COMMAND_ERROR 11

#define  INT_PTR_SIZE sizeof(unsigned char *)

#define INT_DEBUG_SHOW_SUB 0
#define INT_DEBUG_SHOW_DIV 1

typedef struct _MYINT
{
	union {
		unsigned char *pBytes;
		unsigned char raw[INT_PTR_SIZE];
	}data;
	//unsigned char *pBuffer;

	unsigned int size;		// allocated size in bytes
	unsigned int used_size; // actual space occupied by the number in bytes
	//unsigned int buffer_size;
	unsigned char sign; //stores sign
	unsigned char options;
	struct _MYINT *rest; //rest for 
} MYINT;

uint64_t fromBytes(unsigned char*pBytes, unsigned int size);

void nullifyMyInt(MYINT* pMyInt);

int myintOp(int op, MYINT* pSrc, MYINT* pSrc2,MYINT* pResult);

void myintCleanup();

int printMyInt(MYINT* pSrc, char* pResult, unsigned int resultLength);

int printBytes(unsigned char *p, unsigned int size, char *pResult, unsigned int resultLength);

#endif