#include "astroidal_ellipsoid.h"
#include "surfaces_c_includes.h"

#if (USE_ASTROIDAL_ELLIPSOID != 0)
void AstroidalEllipsoid(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAstroidalEllipsoid =
    "name: Astroidal Ellipsoid;\
ut:c; vt:c;\
us:pi:-0.5; ue:pi:0.5;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: a*cos(u)^3*cos(v)^3;\
y: b*sin(u)^3*cos(v)^3;\
z: c*sin(v)^3;";
#endif