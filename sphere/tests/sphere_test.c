
#ifdef USE_SPHERE
#undef USE_SPHERE
#endif

#define USE_SPHERE 1

#include "../../pasuli_test/pasuli_test.h"

#include "../sphere.h"
#include "../sphere_prog.h"

unsigned char sphereTestProg[] = {
    SPHERE_PROG};

PaSuLiTestDesc sphereTest =
    PASULI_TEST("sphere", Sphere, sphereTestProg, sizeof(sphereTestProg), 0, 0, 0);
