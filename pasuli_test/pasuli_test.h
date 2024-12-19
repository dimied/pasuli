#ifndef __PASULI_TEST_TYPES_INCLUDED__
#define __PASULI_TEST_TYPES_INCLUDED__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#pragma pack(1)
typedef struct _PaSuLiTestPointTest
{
    pasuli_vartype u;
    pasuli_vartype v;
    pasuli_vartype x;
    pasuli_vartype y;
    pasuli_vartype z;
    pasuli_vartype *pConstants;
} PaSuLiTestPointTest;

#define PASULI_POINT_TEST(U, V, X, Y, Z, PTR_CONSTANTS) {U, V, X, Y, Z, PTR_CONSTANTS}

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
    PaSuLiTestPointTest *pPosTests;
    int posTestCount;
    PaSuLiTestSampling *pSampling;
} PaSuLiTestDesc;

#define PASULI_NO_TEST_VALUES ((PaSuLiTestPointTest *)0)
#define PASULI_NO_TEST_SAMPLING ((PaSuLiTestSampling *)0)

#define PASULI_TEST(NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING) \
    {NAME, FUNC_PTR, TEST_PROG, TEST_PROG_SIZE, POS_TEST_PTR, POS_TEST_COUNT, TEST_SAMPLING}

#endif