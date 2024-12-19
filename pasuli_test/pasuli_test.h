#ifndef __PASULI_TEST_TYPES_INCLUDED__
#define __PASULI_TEST_TYPES_INCLUDED__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#define SURFACE_PROG_SIZE 100

typedef struct _PaSuLiTestValues
{
    float u;
    float v;
    float x;
    float y;
    float z;
} PaSuLiTestValues;

typedef struct _PaSuLiTestSampling
{
    float uStart;
    float uEnd;
    int uNumSamples;
    float vStart;
    float vEnd;
    int vNumSamples;
} PaSuLiTestSampling;

typedef struct _PaSuLiTestDesc
{
    char *surfaceName;
    PaSuLiFuncPtr pasuliFunc;
    unsigned char *pTestProg;
    int testProgSize;
    PaSuLiTestValues *pPosTests;
    int posTestCount;
    PaSuLiTestSampling *pSampling;
} PaSuLiTestDesc;

#define PASULI_TEST(NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING) \
    {NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING}

#endif