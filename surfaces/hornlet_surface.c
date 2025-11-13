
#include "hornlet_surface.h"
#include "surfaces_c_includes.h"

#if (USE_HORNLET_SURFACE != 0)
void HornletSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HORNLET_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];
    pasuli_consttype h = constants[3];

    pasuli_calctype cos_b_pi_u = cos(b * MY_PI * u);
    pasuli_calctype sin_b_pi_u = sin(b * MY_PI * u);

    pasuli_calctype sin_b_pi_v = sin(b * MY_PI * v);
    pasuli_calctype cos_c_pi_v = cos(c * MY_PI * v);
    pasuli_calctype sin_c_pi_v = sin(c * MY_PI * v);

    pasuli_calctype factor = a + sin_b_pi_u * sin_b_pi_v;

    P_X(factor * sin_c_pi_v);
    P_Y(factor * cos_c_pi_v);
    P_Z(cos_b_pi_u * sin_b_pi_v + h * v);

    // Ignore scaling by b*pi*sin(b*pi*v)
    factor = b * sin_b_pi_v;
    factor = PASULI_CALC_SIGN(factor);
    UD_X(factor * cos_b_pi_u * sin_c_pi_v);
    UD_Y(factor * cos_b_pi_u * cos_c_pi_v);
    UD_Z(-factor * sin_b_pi_u);

    pasuli_calctype cos_b_pi_v = cos(b * MY_PI * v);
    factor = b * cos_b_pi_v * sin_b_pi_u;
    pasuli_calctype factor2 = c * sin_b_pi_u * sin_b_pi_v;
    VD_X(MY_PI * (a * c * cos_c_pi_v + factor * sin_c_pi_v + cos_c_pi_v * factor2));
    VD_Y(-MY_PI * (a * c * sin_c_pi_v - factor * cos_c_pi_v + sin_c_pi_v * factor2));
    VD_Z(b * MY_PI * cos_b_pi_u * cos_b_pi_v + h);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHornletSurface =
    "name: Hornlet Surface;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:h: 1;\
x: (a+sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v);\
y: (a+sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v);\
z: cos(b*pi*u)*sin(b*pi*v)+h*v;\
xu: b*pi*cos(b*pi*u)*sin(b*pi*v)*sin(c*pi*v);\
yu: b*pi*cos(b*pi*u)*sin(b*pi*v)*cos(c*pi*v);\
zu: -b*pi*sin(b*pi*u)*sin(b*pi*v);\
xv: pi*(a*c*cos(c*pi*v)+b*cos(b*pi*v)*sin(b*pi*u)*sin(c*pi*v)+c*cos(c*pi*v)*sin(b*pi*u)*sin(b*pi*v));\
yv: -pi*(a*c*sin(c*pi*v)-b*cos(b*pi*v)*sin(b*pi*u)*cos(c*pi*v)+c*sin(c*pi*v)*sin(b*pi*u)*sin(b*pi*v));\
zv: b*pi*cos(b*pi*u)*cos(b*pi*v)+h;";
#endif