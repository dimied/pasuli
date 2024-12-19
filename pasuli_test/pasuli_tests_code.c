
#include <stdio.h>
#include "pasuli_tests_code.h"
#include "../sphere/tests/all_sphere_tests.h"

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
void executeSuiteTests(PaSuLiTestPair *testPair)
{
    char *pName = testPair->name;
    int numTests = testPair->numTests;
    printf("Tests: %s | #tests: %i\n", pName, numTests);
    printf("---\n");
    printf("---\n");
}