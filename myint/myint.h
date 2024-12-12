#ifndef __MY_INT__
#define __MY_INT__

#include <stdint.h>

#ifndef INITIAL_INIT_SIZE
#define INITIAL_INIT_SIZE 4
#endif

#ifndef INT_OP_DEFAULT_USE
#define INT_OP_DEFAULT_USE 1
#endif

#ifndef INT_USE_OP_CLEAR
#define INT_USE_OP_CLEAR INT_OP_DEFAULT_USE
#endif

#ifndef INT_USE_OP_INIT
#define INT_USE_OP_INIT INT_OP_DEFAULT_USE
#endif

#if INT_USE_OP_CLEAR
#define INT_OP_CLEAR_SRC 1
#define INT_OP_CLEAR_SRC2 2
#define INT_OP_CLEAR_RESULT 4
#define INT_OP_CLEAR_ALL (INT_OP_CLEAR_SRC | INT_OP_CLEAR_SRC2 | INT_OP_CLEAR_RESULT)

#define INT_INTERNAL_CHECK_CLEAR(OP, VAL) ((OP & VAL) == VAL)
#endif

//
#if INT_USE_OP_INIT
#define INT_OP_INIT_SRC 0x8
#define INT_OP_INIT_SRC2 0x10
#define INT_OP_INIT_RESULT 0x20
#define INT_OP_INIT_ALL (INT_OP_INIT_SRC | INT_OP_INIT_SRC2 | INT_OP_INIT_RESULT)

#define INT_INTERNAL_CHECK_INIT(OP, VAL) ((OP & VAL) == VAL)
#endif
//
#define INT_OP_ZERO 0x40
#define INT_OP_ONE 0x41
//
#define INT_OP_CMP_ABS 0x42
#define INT_OP_CMP 0x43
//
#define INT_OP_ADD 0x44
#define INT_OP_ADD_TO_SRC 0x45
#define INT_OP_SUB 0x46
#define INT_OP_MUL 0x47
#define INT_OP_DIV 0x48

#define INT_RESULT_CMP_EQUAL 0
#define INT_RESULT_CMP_LESS 1
#define INT_RESULT_CMP_GREATER 2

#define INT_ALLOCATION_ERROR 10
#define INT_COMMAND_ERROR 11

#define INT_DEBUG_SHOW_CMP 0
#define INT_DEBUG_SHOW_SUB 0
#define INT_DEBUG_SHOW_DIV 0

#ifndef USE_TEMP_MEMORY
#define USE_TEMP_MEMORY 0
#endif

#define USE_AB_INIT 1

// If set, then data
#define INT_STATE_NO_DYNAMIC_MEMORY 0x1

// #define INT_PTR_SIZE sizeof(unsigned char *)
#if UINTPTR_MAX == 0xFFFFFFFF
#define INT_PTR_SIZE 4
#elif UINTPTR_MAX == 0xFFFFFFFFFFFFFFFFu
#define INT_PTR_SIZE 8
#else
#error TBD pointer size
#endif

typedef struct _MYINT
{
	//by default pointers, can also be used directly for small values
	//see state/props
	union
	{
		unsigned char *pBytes;
		unsigned short *pShorts;
		unsigned int *pUInts;
		unsigned char rawBytes[INT_PTR_SIZE];
#if INT_PTR_SIZE == 8
		unsigned char rawUint64;
#endif
	} data;
	unsigned int used_size; // actual space occupied by the number in bytes
	unsigned int size;		// allocated size in bytes
	struct _MYINT *rest;	// rest for division
	unsigned char sign;		// stores sign
	unsigned char state;	// properties
} MYINT;

extern int intOps;

uint64_t fromBytes(void *pBytes, unsigned int size);

void nullifyMyInt(MYINT *pMyInt);

void adjust(MYINT *pData);

// 10.12 = 0x652, 12.12 = 0x65e
int myintOp(int op, MYINT *pSrc, MYINT *pSrc2, MYINT *pResult);

#if USE_TEMP_MEMORY
void myintCleanup();
#endif

int printMyInt(MYINT *pSrc, char *pResult, unsigned int resultLength);

#endif