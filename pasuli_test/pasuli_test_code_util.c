
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pasuli_test_code_util.h"

const int allocResultPoint = RESULT_POINT_LEN * sizeof(float);
const int allocProgParams = PROG_PARAMS_LEN * sizeof(float);
const int allocU = US_LEN * sizeof(float);
const int allocV = VS_LEN * sizeof(float);

int allocTestVars(TestVars *pTestVars)
{
    pTestVars->pResultPoint = (float *)malloc(allocResultPoint);
    pTestVars->pProgParams = (float *)malloc(allocProgParams);
    pTestVars->pU = (float *)malloc(allocU);
    pTestVars->pV = (float *)malloc(allocV);

    if (pTestVars->pResultPoint != 0 && pTestVars->pProgParams != 0 &&
        pTestVars->pU != 0 && pTestVars->pV != 0)
    {
        return 0;
    }
    return 1;
}

int clearTestVars(TestVars *pTestVars)
{
    if (!pTestVars)
    {
        return 1;
    }
    memset(pTestVars->pResultPoint, 0, allocResultPoint);
    memset(pTestVars->pProgParams, 0, allocProgParams);
    memset(pTestVars->pU, 0, allocU);
    memset(pTestVars->pV, 0, allocV);

    return 0;
}

void sampleRange(float start, float end, int numPoints, float *pResults)
{
    if (numPoints <= 0)
    {
        return;
    }
    if (numPoints < 3)
    {
        if (1 == numPoints)
        {
            *pResults = start;
            ++pResults;
        }
        if (2 == numPoints)
        {
            *pResults = end;
        }
        return;
    }

    float diff = end - start;

    pResults[0] = start;
    int n = numPoints - 1;
    float nFloat = (float)n;
    for (int i = 1; i < n; i++)
    {
        pResults[i] = start + (((float)i) * diff) / nFloat;
    }
    pResults[numPoints - 1] = end;
}

int sampleValues(TestSampling *pSampling)
{
    if (!pSampling)
    {
        return 1;
    }
    long int numSamples = pSampling->uNumValues * pSampling->vNumValues;
    if (numSamples <= 0)
    {
        printf("Error: num samples <= 0. #samples: %li\n", numSamples);
        return 1;
    }
    if (numSamples > 0x10000)
    {
        printf("Error: too many samples . #samples: %li\n", numSamples);
        return 1;
    }
    if (pSampling->pUValues)
    {
        free(pSampling->pUValues);
        pSampling->pUValues = 0;
    }
    if (pSampling->pVValues)
    {
        free(pSampling->pVValues);
        pSampling->pVValues = 0;
    }

    pSampling->pUValues = (float *)malloc(pSampling->uNumValues * sizeof(float));

    if (!pSampling->pUValues)
    {
        return 1;
    }
    pSampling->pVValues = (float *)malloc(pSampling->vNumValues * sizeof(float));
    if (!pSampling->pVValues)
    {
        free(pSampling->pUValues);
        pSampling->pUValues = 0;
        return 1;
    }

    sampleRange(pSampling->uStart, pSampling->uEnd, pSampling->uNumValues, pSampling->pUValues);
    sampleRange(pSampling->vStart, pSampling->vEnd, pSampling->vNumValues, pSampling->pVValues);

    return 0;
}

int clearSampleValues(TestSampling *pSampling)
{
    if (!pSampling)
    {
        return 1;
    }
    if (pSampling->pUValues)
    {
        free(pSampling->pUValues);
        pSampling->pUValues = 0;
    }
    if (pSampling->pVValues)
    {
        free(pSampling->pVValues);
        pSampling->pVValues = 0;
    }
    return 0;
}

int comparePos(PaSuLiObject *pResult, PaSuLiTestPointTest *pExpected)
{
    double xDiff = pResult->pos[0] - pExpected->x;
    double yDiff = pResult->pos[1] - pExpected->y;
    double zDiff = pResult->pos[2] - pExpected->z;

    if (fabs(xDiff) > MAX_DIFF || fabs(yDiff) > MAX_DIFF || fabs(zDiff) > MAX_DIFF)
    {
        return 1;
    }
    return 0;
}

int comparePosArray(PaSuLiObject *pResult, float* pPos)
{
    double xDiff = pResult->pos[0] - pPos[0];
    double yDiff = pResult->pos[1] - pPos[1];
    double zDiff = pResult->pos[2] - pPos[2];

    if (fabs(xDiff) > MAX_DIFF || fabs(yDiff) > MAX_DIFF || fabs(zDiff) > MAX_DIFF)
    {
        return 1;
    }
    return 0;
}

int comparePosFloat(float *pPos, PaSuLiTestPointTest *pExpected)
{
    double xDiff = pPos[0] - pExpected->x;
    double yDiff = pPos[1] - pExpected->y;
    double zDiff = pPos[2] - pExpected->z;

    if (fabs(xDiff) > MAX_DIFF || fabs(yDiff) > MAX_DIFF || fabs(zDiff) > MAX_DIFF)
    {
        return 1;
    }
    return 0;
}

void convertConstants(pasuli_vartype *inConstants, int numConstants, float *outConstants)
{
    if (inConstants)
    {
        for (int cIdx = 0; cIdx < numConstants; cIdx++)
        {
            outConstants[cIdx] = (float)inConstants[cIdx];
        }
    }
}