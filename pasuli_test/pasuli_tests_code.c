
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pasuli_tests_code.h"
#include "../sphere/tests/all_sphere_tests.h"
#include "../interpreter/interpreter.h"

PaSuLiTestPair testPairs[] = {
    PASULI_TEST_PAIR("Spheres", allSphereTests, PASULI_ALL_SPHERE_TESTS_COUNT)};

int numTestPairs = sizeof(testPairs) / sizeof(PaSuLiTestPair);

void executeSuiteTests(PaSuLiTestPair *testPair);

void executePaSuLiTests()
{
    for (int testSuiteIdx = 0; testSuiteIdx < numTestPairs; testSuiteIdx++)
    {
        executeSuiteTests(&testPairs[testSuiteIdx]);
    }
}

#define MAX_DIFF 0.000001

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

float globalConstants[10] = {0};

void executeSuiteTests(PaSuLiTestPair *testPair)
{
    char *pName = testPair->name;
    int numTests = testPair->numTests;
    printf("Tests: %s | #tests: %i\n", pName, numTests);
    printf("---\n");
    char *pTestIndent = "  ";

    PaSuLiObject testPoint;
    memset(&testPoint, 0, sizeof(PaSuLiObject));

    for (int testIdx = 0; testIdx < numTests; testIdx++)
    {
        PaSuLiTestDesc *pTest = testPair->tests[testIdx];
        if (0 == pTest)
        {
            printf("Skip @%i (is null)\n", testIdx);
            continue;
        }
        printf("  -----\n");
        printf("%sTest: %s\n", pTestIndent, pTest->surfaceName);
        if (0 == pTest->pasuliFunc)
        {
            printf("%sMissing PaSuLi test function\n", pTestIndent);
            printf("  -----\n");
            continue;
        }
        PaSuLiTestPointTest *pTestPoints = pTest->pPosTests;
        int nPoints = pTest->posTestCount;
        if (pTestPoints)
        {
            //float funcConstants[10] = {0};
            float interpreterResultPoint[3] = {0};
            float progParams[10] = {0};

            printf("%sPoints(count): %i\n", pTestIndent, nPoints);
            for (int testPointIdx = 0; testPointIdx < nPoints; testPointIdx++)
            {
                double u = pTestPoints[testPointIdx].u;
                double v = pTestPoints[testPointIdx].v;
                double *pConst = pTestPoints[testPointIdx].pConstants;

                PaSuLiTestPointTest *pPointTest = &pTestPoints[testPointIdx];

                float us[] = {u};
                float vs[] = {v};

                pTest->pasuliFunc(u, v, pConst, &testPoint);

                if (pTestPoints[testPointIdx].pConstants)
                {
                    for (int cIdx = 0; cIdx < pTestPoints[testPointIdx].numConstants; cIdx++)
                    {
                        progParams[cIdx] = (float)pConst[cIdx];
                    }
                }

                if (comparePos(&testPoint, pPointTest))
                {
                    printf("%sPoint(%i):", pTestIndent, testPointIdx);
                    printf(" (%f,%f) =>(%f,%f,%f)\n",
                           u, v, testPoint.pos[0], testPoint.pos[1], testPoint.pos[2]);

                    printf("%sERROR: (%f,%f,%f)\n",
                           pTestIndent, pTestPoints[testPointIdx].x, pTestPoints[testPointIdx].y, pTestPoints[testPointIdx].z);
                }
                if (pTest->pTestProg)
                {

                    // int interpreterRes =
                    parseCode(
                        us,
                        1,
                        vs,
                        1,
                        DEFINE_STEPS(1, 1),
                        globalConstants,
                        progParams,
                        pTest->testProgSize,
                        pTest->pTestProg,
                        interpreterResultPoint);
                    if (comparePosFloat(interpreterResultPoint, pPointTest))
                    {
                        printf("%s|I|Point(%i):", pTestIndent, testPointIdx);
                        printf(" (%f,%f) =>(%f,%f,%f)\n",
                               u, v, interpreterResultPoint[0], interpreterResultPoint[1], interpreterResultPoint[2]);

                        printf("%sERROR: (%f,%f,%f)\n",
                               pTestIndent, pTestPoints[testPointIdx].x, pTestPoints[testPointIdx].y, pTestPoints[testPointIdx].z);
                    }
                }
            }
        }
        printf("  -----\n");
        //
    }
    printf("---\n");
}