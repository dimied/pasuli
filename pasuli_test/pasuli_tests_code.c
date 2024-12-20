
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
                    int interpreterRes = parseCode(
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

                    if (interpreterRes)
                    {
                        printf("ERROR: Interpreter fail (%i)|res: %i\n", interpreterRes, testPointIdx);
                        break;
                    }
                    if (comparePosFloat(pPoint, pPointTest))
                    {
                        printf("%s|I|Point(%i):", pTestIndent, testPointIdx);
                        printf(" (%f,%f) => (%f,%f,%f)\n",
                               u, v, pPoint[0], pPoint[1], pPoint[2]);

                        printf("%sERROR: (%f,%f,%f)\n",
                               pTestIndent, pTestPoints[testPointIdx].x, pTestPoints[testPointIdx].y, pTestPoints[testPointIdx].z);
                    }
                }
            }
        }
        if (pTest->pTestProg && pTest->testProgSize > 0 && pTest->pSampling && pTest->numSamplings)
        {
            long int allNumSampleTests = 0;

            for (int samplingIdx = 0; samplingIdx < pTest->numSamplings; samplingIdx++)
            {
                int numSampleTests = 0;
                printf("%sSample:idx: %i\n", pTestIndent, samplingIdx);
                clearSampleValues(&testSampling);

                PaSuLiTestSampling *pTestSampling = &pTest->pSampling[samplingIdx];
                testSampling.uStart = pTestSampling->uStart;
                testSampling.uEnd = pTestSampling->uEnd;
                testSampling.vStart = pTestSampling->vStart;
                testSampling.vEnd = pTestSampling->vEnd;
                testSampling.uNumValues = pTestSampling->uNumSamples;
                testSampling.vNumValues = pTestSampling->vNumSamples;
                pasuli_consttype *pConstPoint = pTestSampling->pConstants;

                printf("%sSample:#consts: %i\n", pTestIndent, pTestSampling->numConstants);

                if (sampleValues(&testSampling))
                {
                    printf("ERROR: Failed to sample\n");
                    continue;
                }
                printf("%sSamples OK!\n", pTestIndent);
                clearTestVars(&testVars);
                convertConstants(pConstPoint, pTestSampling->numConstants, testVars.pProgParams);

                float *pPoint = testVars.pResultPoint;
                pasuli_vartype *pPos = testPoint.pos;
                int numFails = 0;

                // printf("CONSTS: %f|%p\n",testVars.pProgParams[0], (void*)pConstPoint);

                for (int iU = 0; iU < testSampling.uNumValues && numFails < 10; iU++)
                {
                    double u = testSampling.pUValues[iU];
                    testVars.pU[0] = (float)u;
                    for (int iV = 0; iV < testSampling.vNumValues && numFails < 10; iV++)
                    {
                        double v = testSampling.pVValues[iV];
                        testVars.pV[0] = (float)v;
                        // PaSuLi
                        pTest->pasuliFunc(u, v, pConstPoint, &testPoint);

                        int interpreterRes =
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
                        if (interpreterRes)
                        {
                            printf("ERROR: Interpreter (%i)(%i,%i)\n", interpreterRes, iU, iV);
                            break;
                        }
                        if (comparePosArray(&testPoint, pPoint))
                        {
                            printf("%s|S|Point(%i,%i):", pTestIndent, iU, iV);
                            printf(" (%f,%f) => (%f,%f,%f)\n",
                                   u, v, pPos[0], pPos[1], pPos[2]);

                            printf("%s   ERROR: (%f,%f,%f)\n",
                                   pTestIndent, pPoint[0], pPoint[1], pPoint[2]);
                            ++numFails;
                            continue;
                        }
                        ++numSampleTests;
                    }
                }
                allNumSampleTests += numSampleTests;
                printf("%sSamples tested(%i): %i\n", pTestIndent, samplingIdx, numSampleTests);
            }
            printf("%sSamples tested(all): %li\n", pTestIndent,allNumSampleTests );
        }

        printf("  -----\n");
        //
    }
    printf("---\n");
}