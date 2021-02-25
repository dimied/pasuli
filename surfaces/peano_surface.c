
#include "peano_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PEANO_SURFACE != 0)
void PeanoSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PEANO_SURFACE)

    pasuli_calctype u2 = u * u;

    P_X(u);
    P_Y(v);
    P_Z((2 * u2 - v) * (v - u2));

    UD_X(1);
    UD_Y(0);
    UD_Z(2 * u * (3 * v - 4 * u2));

    VD_X(0);
    VD_Y(1);
    VD_Z(3 * u2 - 2 * v);

    N_X(-PASULI_COND_COPY_UD_Z(2 * u * (3 * v - 4 * u2)));
    N_Y(-PASULI_COND_COPY_VD_Z(3 * u2 - 2 * v));
    N_Z(1);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPeanoSurface =
    "name: Peano Surface;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v;\
z: (2*u^2-v)*(v-u^2);\
xu: 1;\
yu: 0;\
zu: 2*u*(3*v-4*u^2);\
xv: 0;\
yv: 1;\
zv: 3*u*u-2*v;\
xn: -2*u*(3*v-4*u^2);\
yn: -3*u*u+2*v;\
zn: 1;";
#endif
