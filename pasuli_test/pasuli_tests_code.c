
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pasuli_tests_code.h"
#include "../sphere/tests/all_sphere_tests.h"
#include "../interpreter/interpreter.h"
#include "pasuli_test_code_util.h"

PaSuLiTestPair testPairs[] = {
    PASULI_TEST_PAIR("Spheres", allSphereTests, PASULI_ALL_SPHERE_TESTS_COUNT)};

int numTestPairs = sizeof(testPairs) / sizeof(PaSuLiTestPair);

void executeSuiteTests(PaSuLiTestPair *testPair);

TestVars testVars = {0, 0, 0, 0};

TestSampling testSampling = {0, 0, 0, 0, 0, 0};

void executePaSuLiTests()
{
    for (int testSuiteIdx = 0; testSuiteIdx < numTestPairs; testSuiteIdx++)
    {
        executeSuiteTests(&testPairs[testSuiteIdx]);
    }
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

    allocTestVars(&testVars);

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

        clearTestVars(&testVars);
        clearSampleValues(&testSampling);

        if (pTestPoints)
        {
            printf("%sPoints(count): %i\n", pTestIndent, nPoints);
            for (int testPointIdx = 0; testPointIdx < nPoints; testPointIdx++)
            {
                double u = pTestPoints[testPointIdx].u;
                double v = pTestPoints[testPointIdx].v;
                double *pConst = pTestPoints[testPointIdx].pConstants;

                PaSuLiTestPointTest *pPointTest = &pTestPoints[testPointIdx];

                pTest->pasuliFunc(u, v, pConst, &testPoint);

                convertConstants(pConst, pTestPoints[testPointIdx].numConstants, testVars.pProgParams);

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
                    testVars.pU[0] = u;
                    testVars.pV[0] = v;
                    float *pPoint = testVars.pResultPoint;
                    // int interpreterRes =
                    parseCode(
                        testVars.pU,
                        1,
                        testVars.pV,
                        1,
                        DEFINE_STEPS(1, 1),
                        globalConstants,
                        testVars.pProgParams,
                        pTest->testProgSize,
                        pTest->pTestProg,
                        pPoint);
                    if (comparePosFloat(pPoint, pPointTest))
                    {
                        printf("%s|I|Point(%i):", pTestIndent, testPointIdx);
                        printf(" (%f,%f) =>(%f,%f,%f)\n",
                               u, v, pPoint[0], pPoint[1], pPoint[2]);

                        printf("%sERROR: (%f,%f,%f)\n",
                               pTestIndent, pTestPoints[testPointIdx].x, pTestPoints[testPointIdx].y, pTestPoints[testPointIdx].z);
                    }
                    
                }
            }
        }
        if(pTest->pSampling && pTest->numSamplings) {
            for(int samplingIdx=0; samplingIdx < pTest->numSamplings; samplingIdx++) {
                clearSampleValues(&testSampling);

                PaSuLiTestSampling* pTestSampling = &pTest->pSampling[samplingIdx];
                testSampling.uStart = pTestSampling->uStart;
                testSampling.uEnd = pTestSampling->uEnd;
                testSampling.vStart = pTestSampling->vStart;
                testSampling.vEnd = pTestSampling->vEnd;
                testSampling.uNumValues = pTestSampling->uNumSamples;
                testSampling.vNumValues = pTestSampling->vNumSamples;

                if(sampleValues(&testSampling)) {
                    printf("ERROR: Failed to sample\n");
                    continue;
                }
                printf("%sSamples OK!\n", pTestIndent);

            }
        }
                    
        printf("  -----\n");
        //
    }
    printf("---\n");
}