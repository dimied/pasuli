
#include "twisted_heart.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_HEART != 0)

void TwistedHeart(double u, double v,
                  double *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_HEART)

    double abs_u;
    double abs_v;
    double tanh_mum;
    double tanh_mvm;
    double cosh_mu;
    double m_inv = sqrt((double)2.0);

    abs_u = fabs((double)u);
    tanh_mum = fabs(tanh(u / m_inv) * m_inv);
    cosh_mu = cosh(u / m_inv);
    u = u * u;

    abs_v = fabs(v) - tanh_mum;
    tanh_mvm = fabs(tanh(v / m_inv) * m_inv) - abs_u;

    P_X((abs_v - tanh_mvm) * sin(v));
    P_Y((abs_v + tanh_mvm) * cos(v));
    P_Z((u + v * v) / (m_inv * cosh_mu * cosh(v / m_inv)));

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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedHeart = {
PSLDD_ID( TWISTED_HEART )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
0, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedHeart =
"name: Twisted Heart; \
ut: c; vt: c; \
us: 0; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
a:1:m: 1/sqrt(2); \
x: (|v| - |u| - |tanh(m*u)/m| + |tanh(m*v)/m|)*sin(v); \
y: (|v| + |u| - |(tanh(m*u)/m| - |tanh(m*v)/m|)*cos(v); \
z: m*(u*u + v*v)/(cosh(m*u)*cosh(m*v)); \
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
