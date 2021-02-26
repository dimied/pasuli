#include "bours_minimal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_SINE_CUBE != 0)
void SineCube(pasuli_vartype u,
              pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SINE_CUBE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(sin_u * sin_v);
    P_Y(cos_u * sin_v);
    P_Z(cos_u * cos_v);

    UD_X(PASULI_COND_COPY_POS_Y(cos_u * sin_v));
    UD_Y(-PASULI_COND_COPY_POS_X(sin_u * sin_v));
    UD_Z(-cos_v * sin_u);

    VD_X(cos_v * sin_u);
    VD_Y(PASULI_COND_COPY_POS_Z(cos_u * cos_v));
    VD_Z(-PASULI_COND_COPY_POS_Y(cos_u * sin_v));

    //sin x · cos y = 1/2 [sin (x - y) + sin (x + y) ]
    pasuli_calctype sin_u_plus_v = sin(v + u);
    pasuli_calctype cos_sin_uv = sin(v - u) + sin_u_plus_v;
    pasuli_calctype cos_sin_vu = sin(u - v) + sin_u_plus_v;
    N_X(cos_u * sin_u);
    N_Y((cos_sin_uv * cos_sin_uv - cos_sin_vu * cos_sin_vu) * 0.25);
    N_Z(cos_v * sin_v);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSineCube =
    "name: Sine Cube;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: sin(u)*sin(v);\
y: cos(u)*sin(v);\
z: cos(u)*cos(v);\
xu: cos(u)*sin(v);\
yu: -sin(u)*sin(v);\
zu: -cos(v)*sin(u);\
xv: cos(v)*sin(u);\
yv: cos(u)*cos(v);\
zv: -cos(u)*sin(v);\
xn: cos(u)*sin(u);\
yn: cos(u)^2*sin(v)^2-cos(v)^2*sin(u)^2;\
zn: cos(v)*sin(v);";
#endif