
#include "bicorn_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BICORN_SURFACE != 0)
void BicornSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BICORN_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);

    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_v = cos(v);

    pasuli_calctype sin_v2_plus_3 = sin_v * sin_v + 3.0;

    P_X(sin_v * cos_u);
    P_Y(sin_v * sin_u);
    P_Z(cos_v * cos_v * (2.0 + cos_v) / sin_v2_plus_3);

    UD_X(-PASULI_COND_COPY_POS_Y(sin_v * sin_u));
    UD_Y(PASULI_COND_COPY_POS_X(sin_v * cos_u));
    UD_Z(0);

    // Scale vector by (sin(v)^2+3)^2 to avoid divisions
    VD_X(cos_u * cos_v * sin_v2_plus_3 * sin_v2_plus_3);
    VD_Y(sin_u * cos_v * sin_v2_plus_3 * sin_v2_plus_3);
    VD_Z(-(3 * cos_v * cos_v * sin_v * sin_v2_plus_3 +
           4 * cos_v * sin_v * sin_v2_plus_3 +
           2 * cos_v * cos_v * cos_v * cos_v * sin_v +
           4 * cos_v * cos_v * cos_v * sin_v));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBicornSurface = {
    PSLDD_ID(BICORN_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
    0, 2, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descBicornSurface =
    "name: Bicorn Surface;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 1;\
x: sin(v)*cos(u);\
y: sin(v)*sin(u);\
z: cos(v)*cos(v)*(2 + cos(v))/(3 + sin(v)*sin(v));\
xu: -sin(u)*sin(v);\
yu: cos(u)*sin(v);\
zu: 0;\
xv: cos(u)*cos(v);\
yv: sin(u)*cos(v);\
zv: -(3*cos(v)^2*sin(v)/(sin(v)^2+3) + 4*cos(v)*sin(v)/(sin(v)^2+3) + 2*cos(v)^4*sin(v)/(sin(v)^2+3)^2 + 4*cos(v)^3*sin(v)/(sin(v)^2+3)^2);\
xn: -cos(v)*sin(v)*(3*cos(u)*cos(v)*sin(v)/(sin(v)^2+3) + 4*cos(u)*sin(v)/(sin(v)^2+3) + 2*cos(u)*cos(v)^3*sin(v)/(sin(v)^2+3)^2 + 4*cos(u)*cos(v)^2*sin(v)/(sin(v)^2+3)^2);\
yn: -cos(v)*sin(v)*(3*sin(u)*cos(v)*sin(v)/(sin(v)^2+3) + 4*sin(u)*sin(v)/(sin(v)^2+3) + 2*sin(u)*cos(v)^3*sin(v)/(sin(v)^2+3)^2 + 4*sin(u)*cos(v)^2*sin(v)/(sin(v)^2+3)^2);\
zn: -cos(v)*sin(v); ";
#endif