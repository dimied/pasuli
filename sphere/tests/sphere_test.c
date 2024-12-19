
#ifdef USE_SPHERE
#undef USE_SPHERE
#endif

#define USE_SPHERE 1

#include "../../pasuli_test/pasuli_test.h"

#include "../sphere.h"
#include "../sphere_prog.h"

PaSuLiTestSampling sphereTestSampling =
    PASULI_TEST_SAMPLING(0, 2 * MY_PI, 100, 0, MY_PI, 100);

unsigned char sphereTestProg[] = {SPHERE_PROG};

PaSuLiTestDesc sphereTest =
    PASULI_TEST("sphere", Sphere, sphereTestProg, sizeof(sphereTestProg),
                PASULI_NO_TEST_VALUES, 0,
                &sphereTestSampling);
