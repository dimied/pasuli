
#include "twisted_heart.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_HEART != 0)

void TwistedHeart(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_HEART)

    pasuli_calctype sqrt_2 = sqrt((double)2.0);

    pasuli_calctype abs_u = fabs((double)u);
    pasuli_calctype abs_v = fabs((double)v);
    pasuli_calctype tanh_mu = fabs(tanh(u / sqrt_2) * sqrt_2);
    pasuli_calctype tanh_mv = fabs(tanh(v / sqrt_2) * sqrt_2);

    P_X((abs_v - abs_u - tanh_mu + tanh_mv) * sin(v));
    P_Y((abs_v + abs_u - tanh_mu - tanh_mv) * cos(v));
    P_Z((u * u + v * v) / (sqrt_2 * cosh(u / sqrt_2) * cosh(v / sqrt_2)));
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedHeart = {
    PSLDD_ID(TWISTED_HEART)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI,
    0, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTwistedHeart =
    "name: Twisted Heart;\
ut: c; vt: c;\
us: 0; ue:pi: 1;\
vs:pi: -1; ve:pi: 1;\
a1:m: 1/sqrt(2);\
x: (|v| - |u| - |tanh(m*u)/m| + |tanh(m*v)/m|)*sin(v);\
y: (|v| + |u| - |tanh(m*u)/m| - |tanh(m*v)/m|)*cos(v);\
z: m*(u*u + v*v)/(cosh(m*u)*cosh(m*v));";
#endif
