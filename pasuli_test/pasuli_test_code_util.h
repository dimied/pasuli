#ifndef __PASULI_TEST_CODE_UTIL_INCLUDED__
#define __PASULI_TEST_CODE_UTIL_INCLUDED__

#include "../pasuli_common/pasuli_defs.h"
#include "pasuli_test.h"

#define MAX_DIFF 0.000001

#define RESULT_POINT_LEN 3
#define PROG_PARAMS_LEN 20
#define US_LEN 1
#define VS_LEN 1
typedef struct _TestVars
{
    float *pResultPoint;
    float *pProgParams;
    float *pU;
    float *pV;
} TestVars;

typedef struct _TestSampling {
    float *pUValues;
    float *pVValues;
    float uStart;
    float uEnd;
    float vStart;
    float vEnd;
    int uNumValues;
    int vNumValues;
}TestSampling;

int allocTestVars(TestVars *pTestVars);

int clearTestVars(TestVars *pTestVars);

int sampleValues(TestSampling*pSampling);

int clearSampleValues(TestSampling*pSampling);

int comparePos(PaSuLiObject *pResult, PaSuLiTestPointTest *pExpected);

int comparePosFloat(float *pPos, PaSuLiTestPointTest *pExpected);

int comparePosArray(PaSuLiObject *pResult, float* pPos);

void convertConstants(pasuli_vartype *inConstants, int numConstants, float *outConstants);

#endif