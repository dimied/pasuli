#ifndef __PASULI_TEST_TYPES_INCLUDED__
#define __PASULI_TEST_TYPES_INCLUDED__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#pragma pack(1)
typedef struct _PaSuLiTestValues
{
    float u;
    float v;
    float x;
    float y;
    float z;
} PaSuLiTestValues;

#define PASULI_TEST_VALUE(U, V, X, Y, Z) {U, V, X, Y, Z}

typedef struct _PaSuLiTestSampling
{
    float uStart;
    float uEnd;
    int uNumSamples;
    float vStart;
    float vEnd;
    int vNumSamples;
} PaSuLiTestSampling;

#define PASULI_TEST_SAMPLING(USTART, UEND, UCOUNT, VSTART, VEND, VCOUNT) \
    {USTART, UEND, UCOUNT, VSTART, VEND, VCOUNT}

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

#define PASULI_NO_TEST_VALUES ((PaSuLiTestValues *)0)
#define PASULI_NO_TEST_SAMPLING ((PaSuLiTestSampling *)0)

#define PASULI_TEST(NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING) \
    {NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING}

#endif