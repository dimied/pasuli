
#include "klein_bottle_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_KLEIN_BOTTLE_SURFACE2 != 0)
void KleinBottleSurface2(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KLEIN_BOTTLE_SURFACE2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_u_pow4 = cos_u * cos_u * cos_u * cos_u;
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype A = cos_u * cos_v * sin_u;
    pasuli_calctype B = 48 * cos_u * cos_u_pow4 * (1 + cos_u * cos_u) - 60 * sin_u;
    pasuli_calctype C = 80 * cos_v * sin_u * cos_u_pow4 * cos_u * (1 + cos_u * cos_u);

    P_X(-2 * cos_u * (3 * cos_v - 30 * sin_u + 90 * cos_u_pow4 * sin_u - 60 * cos_u_pow4 * cos_u * cos_u * sin_u + 5 * A) / 15);
    P_Y(-sin_u * (3 * cos_v - 3 * cos_u * cos_u * cos_v - B + 5 * A - 5 * cos_u * cos_u * cos_u * cos_v * sin_u - C) / 15);
    P_Z(2 * (3 + 5 * cos_u * sin_u) * sin_v / 15);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKleinBottleSurface2 =
    "name: Klein Bottle 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
a1:A: cos(u)*cos(v)*sin(u);\
a2:B: 48*cos(u)^4*cos(v)+48*cos(u)^6*cos(v)-60*sin(u);\
a3:C: 80*cos(v)*sin(u)*(cos(u)^5+cos(u)^7);\
x: -2*cos(u)*(3*cos(v)-30*sin(u)+90*cos(u)^4*sin(u)-60*cos(u)^6*sin(u)+5*A)/15;\
y: -sin(u)*(3*cos(v)-3*cos(u)^2*cos(v)-B+5*A-5*cos(u)^3*cos(v)*sin(u)-C)/15;\
z: 2*(3+5*cos(u)*sin(u))*sin(v)/15;";
#endif
