
#ifdef USE_ELLIPSOID
#undef USE_ELLIPSOID
#endif

#define USE_ELLIPSOID 1

#include "../../pasuli_test/pasuli_test.h"

#include "../ellipsoid.h"
#include "../ellipsoid_prog.h"

unsigned char ellipsoidTestProg[] = {ELLIPSOID_PROG};

pasuli_vartype eTestConstants[] = {1,1,1};
pasuli_vartype eTestConstants2[] = {2,2,2};
pasuli_vartype eTestConstants3[] = {-2.5};

PaSuLiTestSampling ellipsoidTestSampling[] = {
    PASULI_TEST_SAMPLING(0, MY_PI, 100, 0, 2 * MY_PI, 100, eTestConstants, 1),
    //PASULI_TEST_SAMPLING(0, MY_PI, 100, 0, 2 * MY_PI, 100, eTestConstants2, 1),
    //PASULI_TEST_SAMPLING(0, MY_PI, 50, 0, 2 * MY_PI, 50, eTestConstants3, 1),
};

PaSuLiTestPointTest ellipsoidPointTests[] = {
    PASULI_POINT_TEST(0, 0, 0, 0, 1, eTestConstants, 1),
    PASULI_POINT_TEST(0, 2 * MY_PI, 0, 0, 1, eTestConstants, 1),
    PASULI_POINT_TEST(MY_PI, 0, 0, 0, -1, eTestConstants, 1),
    PASULI_POINT_TEST(MY_PI, 0, 0, 0, -2.5, eTestConstants2, 1),
    PASULI_POINT_TEST(0, 2 * MY_PI, 0, 0, 2.5, eTestConstants2, 1),
};

PaSuLiTestDesc ellipsoidTest =
    PASULI_TEST("ellipsoid", Ellipsoid, ellipsoidTestProg, sizeof(ellipsoidTestProg),
                ellipsoidPointTests, 5,
                ellipsoidTestSampling, 1);
