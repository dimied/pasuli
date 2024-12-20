
#ifdef USE_SPHERE
#undef USE_SPHERE
#endif

#define USE_SPHERE 1

#include "../../pasuli_test/pasuli_test.h"

#include "../sphere.h"
#include "../sphere_prog.h"

unsigned char sphereTestProg[] = {SPHERE_PROG};

pasuli_vartype testConstants[] = {1};
pasuli_vartype testConstants2[] = {2.5};
pasuli_vartype testConstants3[] = {-2.5};

PaSuLiTestSampling sphereTestSampling[] = {
    PASULI_TEST_SAMPLING(0, MY_PI, 100, 0, 2 * MY_PI, 100, testConstants, 1),
    PASULI_TEST_SAMPLING(0, MY_PI, 100, 0, 2 * MY_PI, 100, testConstants2, 1),
    PASULI_TEST_SAMPLING(0, MY_PI, 50, 0, 2 * MY_PI, 50, testConstants3, 1),
};

PaSuLiTestPointTest spherePointTests[] = {
    PASULI_POINT_TEST(0, 0, 0, 0, 1, testConstants, 1),
    PASULI_POINT_TEST(0, 2 * MY_PI, 0, 0, 1, testConstants, 1),
    PASULI_POINT_TEST(MY_PI, 0, 0, 0, -1, testConstants, 1),
    PASULI_POINT_TEST(MY_PI, 0, 0, 0, -2.5, testConstants2, 1),
    PASULI_POINT_TEST(0, 2 * MY_PI, 0, 0, 2.5, testConstants2, 1),
};

PaSuLiTestDesc sphereTest =
    PASULI_TEST("sphere", Sphere, sphereTestProg, sizeof(sphereTestProg),
                spherePointTests, 5,
                sphereTestSampling, 3);
