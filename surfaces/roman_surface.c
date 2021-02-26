
#include "roman_surface.h"
#include "surfaces_c_includes.h"

#if (USE_ROMAN_SURFACE != 0)
void RomanSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ROMAN_SURFACE);

    pasuli_calctype sqrt_minus_u2 = sqrt(1 - u * u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(2 * u * cos_v * sqrt_minus_u2);
    P_Y(2 * u * sin_v * sqrt_minus_u2);
    P_Z(1 - 2 * u * u * cos_v * cos_v);

    pasuli_calctype one_minus_2u2 = (1 - 2 * u * u);

    // Multiply by sqrt(1 - u * u) and divide by 2
    UD_X(one_minus_2u2 * cos_v);
    UD_Y(one_minus_2u2 * sin_v);
    UD_Z(-2 * u * cos_v * cos_v * sqrt_minus_u2);

    VD_X(-PASULI_COND_COPY_POS_Y(2 * u * sin_v * sqrt_minus_u2));
    VD_Y(PASULI_COND_COPY_POS_X(2 * u * cos_v * sqrt_minus_u2));
    VD_Z(4 * u * u * cos_v * sin_v);

    // Multiply by sqrt(1 - u * u) and divide by 4
    N_X(2 * cos_v * (u * u * (1 - u * u * (1 + sin_v * sin_v))));
    N_Y(2 * u * u * u * u * cos_v * cos_v * sin_v);
    N_Z(u * one_minus_2u2 * sqrt_minus_u2);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRomanSurface = {
    ROMAN_SURFACE,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_FULL_IMPL,
    0, 1, 0, 2, 0};
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRomanSurface =
    "name: Roman Surface;\
ut:c; vt:c;\
us:0; ue: 1;\
vs:0; ve:pi:2;\
x: 2*u*cos(v)*sqrt(1 - u*u);\
y: 2*u*sin(v)*sqrt(1 - u*u);\
z: 1 - 2*u*u*cos(v)*cos(v);\
xu: 2*(1-2*u*u)*cos(v)/(sqrt(1-u*u));\
yu: 2*(1-2*u*u)*sin(v)/(sqrt(1-u*u));\
zu: -4*u*cos(v)*cos(v);\
xv: -2*u*sqrt(1-u*u)*sin(v);\
yv: 2*u*sqrt(1-u*u)*cos(v);\
zv: 4*u*u*cos(v)*sin(v);\
xn: 8*(u*u*( (1-u^2) - u^2*sin(v)^2 ))*cos(v)/(sqrt(1-u*u));\
yn: 8*(u^4*cos(v)^2)*sin(v)/(sqrt(1-u*u));\
zn: 4*u(1-2*u*u); ";
#endif