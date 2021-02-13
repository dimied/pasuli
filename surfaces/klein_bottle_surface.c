
#include "klein_bottle_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_KLEIN_BOTTLE_SURFACE != 0)
void KleinBottleSurface(double u, double v,
                        double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KLEIN_BOTTLE_SURFACE)

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);
#endif

    UD_X(0);
    UD_Y(0);
    UD_Z(0);

    VD_X(0);
    VD_Y(0);
    VD_Z(0);

    N_X(0);
    N_Y(0);
    N_Z(0);

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(0);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(0);

    VVD_X(0);
    VVD_Y(0);
    VVD_Z(0);
}
#endif

/**

r = 4 (1 - cos(u)/2)

0 <= u <pi
x = a cos(u) (1 + sin(u)) + r cos(u) cos(v)
y = b sin(u) + r sin(u) cos(v)
z = r sin(v)

pi < u <= 2pi
x = a cos(u) (1 + sin(u)) + r cos(v +pi)
y = b sin(u)
z = r sin(v)
*/

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinBottleSurface = {
PSLDD_ID( KLEIN_BOTTLE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
//TODO TODO TODO
char *descKleinBottleSurface =
"name: Klein Bottle Surface; \
ut:c; \
vt:c; \
us: 0;  \
ue:pi: 2;  \
vs: 0;  \
ve:pi: 2;  \
c1:a: 1.5; \
c2:b: 0.5; \
x: 0; \
y: 0; \
z: 0; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif