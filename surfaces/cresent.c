
#include "cresent.h"
#include "surfaces_c_includes.h"

#if (USE_CRESENT != 0)
void Cresent(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CRESENT)

    double a = constants[0];
    double bpi = constants[1] * MY_PI;
    double cpi = constants[2] * MY_PI;

    double a_sinsin = a + sin(bpi * u) * sin(bpi * v);

    P_X(a_sinsin * sin(cpi * v));
    P_Y(a_sinsin * cos(cpi * v));
    P_Z(cos(bpi * u) * sin(bpi * v) + v * 4.0 - 2.0);

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

/*
#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCresent = {
    PSLDD_ID(CRESENT)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_CONST_COUNT(3),
    0, 1, 0, 1, psldd_15_05_constants};
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descCresent =
    "name: Cresent; \
ut:c; vt:c; \
us: 0; ue: 1; \
vs: 0; ve: 1; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: (a + sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v); \
y: (a + sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v); \
z: cos(b*pi*u)*sin(b*pi*v) + 4*v - 2; \
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