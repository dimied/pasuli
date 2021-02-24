
#include "lawson_bottle.h"
#include "surfaces_c_includes.h"

#if (USE_LAWSON_BOTTLE != 0)
void LawsonBottle(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(LAWSON_BOTTLE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u_half = sin(u * 0.5);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype divisor = 1 + (sin_u * sin_v + sin_u_half * cos_v) * 0.5;

    P_X((sin_u * sin_v - sin_u_half * cos_v) * sqrt(0.5) / divisor);
    P_Y(cos_u * sin_v / divisor);
    P_Z(cos(u * 0.5) * cos_v / divisor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descLawsonBottle =
    "name: Lawson Bottle;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
a1:w: (sin(u)*sin(v)+sin(u/2)*cos(v))/2;\
x: (sin(u)*sin(v)-sin(u/2)*cos(v))*sqrt(1/2)/(1+w);\
y: cos(u)*sin(v)/(1+w);\
z: cos(u/2)*cos(v)/(1+w);";
#endif
