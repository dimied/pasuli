
#include "cayley_surface.h"
#include "surfaces_c_includes.h"

#if (USE_CAYLEY_SURFACE != 0)
void CayleySurface(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CAYLEY_SURFACE)

    pasuli_calctype u2 = u * u;
    pasuli_calctype v2 = v * v;
    P_X(u + v);
    P_Y((u2 + v2) * 0.5 + (v - u));
    P_Z((u2 * u + v2 * v) / 3 + (v2 - u2));

    UD_X(1);
    UD_Y(u - 1);
    pasuli_calctype ud_z = u * (u - 2);
    UD_Z(ud_z);

    VD_X(1);
    VD_Y(v + 1);
    pasuli_calctype vd_z = v * (v + 2);
    VD_Z(vd_z);

    N_X(-u * ((u - 2) - v * (v + 4 - u)) - vd_z);
    N_Y(ud_z - vd_z);
    N_Z(2 + v - u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCayleySurface =
    "name: Cayley Surface;\
ut:c; vt:o;\
us:-1.5; ue:1;\
vs:-1.5; ve:1.5;\
x: u+v;\
y: (u^2+v^2)/2+(v-u);\
z: (u^3+v^3)/3+(v^2-u^2);\
xu: 1;\
yu: u-1;\
zu: u*(u-2);\
xv: 1;\
yv: v+1;\
zv: v*(v+2);\
xn: -u*((u-2)-v*(v+4-u))-v*(v+2);\
yn: u*(u-2)-v*(v+2);\
zn: -u+v+2;";
#endif
