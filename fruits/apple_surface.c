
#include "apple_surface.h"
#include "fruits_c_includes.h"

#if (USE_APPLE_SURFACE != 0)
void AppleSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(APPLE_SURFACE)

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_v_multiplied = 3.8 * cos(v);

    pasuli_calctype common_factor = 4 + cos_v_multiplied;
    pasuli_calctype log_value = log(1 - MY_PI * v / 10.0);

    P_X(cos_u * common_factor);
    P_Y(sin_u * common_factor);
    P_Z((cos_v + sin_v - 1) * (1 + sin_v) * log_value + 7.5 * sin_v);

    UD_X(-PASULI_COND_COPY_POS_Y(sin_u * common_factor));
    UD_Y(PASULI_COND_COPY_POS_X(cos_u * common_factor));
    UD_Z(0);

    pasuli_calctype common_v = MY_PI * v - 10;
    VD_X(-3.8 * cos_u * sin_v);
    VD_Y(-3.8 * sin_u * sin_v);
    VD_Z(7.5 * cos_v + log_value * (2 * cos_v * cos_v - 1 + sin_v * (2 * cos_v - 1)) +
         MY_PI * (1 - (cos_v + cos_v * sin_v + sin_v * sin_v)) / common_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_FRUITS != 0)
char *descAppleSurface =
    "name: Apple Surface; \
cat: fruits; \
ut: c; vt: c; \
us: 0; ue:pi: 2 ; \
vs:pi: -1; ve:pi: 1; \
x: cos(u)*(4 + 3.8*cos(v)); \
y: sin(u)*(4 + 3.8*cos(v)); \
z: (cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+7.5*sin(v); \
xu: -sin(u)*(4 + 3.8*cos(v)); \
yu: cos(u)*(4 + 3.8*cos(v)); \
zu: 0; \
xv: -3.8*cos(u)*sin(v); \
yv: -3.8*sin(u)*sin(v); \
zv: 7.5*cos(v)+log(1-pi*v/10)*(2*cos(v)^2 - 1 + sin(v)*(2*cos(v)-1))+\
pi*(1-(cos(v) + cos(v)*sin(v) + sin(v)^2))/(10-v*pi); \
xn: ?; \
yn: ?; \
zn: ?; \
xuu: -cos(u)*(4 + 3.8*cos(v)); \
yuu: -sin(u)*(4 + 3.8*cos(v)); \
zuu: 0; \
xuv: 3.8*sin(u)*sin(v); \
yuv: -3.8*cos(u)*sin(v); \
zuv: 0; \
xvv: -3.8*cos(u)*cos(v); \
yvv: -3.8*cos(v)*sin(u); \
zvv: pi^2*(1 - (cos(v) + cos(v)*sin(v) + sin(v)^2/(10 - pi*v)^2\
- pi*(cos(v)^2 + 2*cos(v)*sin(v) - sin(v)^2 -sin(v))/(5- v*pi/2)\
+log(1-v*pi)*(4*cos(v)^4 - cos(v)*(1-4*sin(v)) - 7.5*sin(v)); ";
#endif

#if (COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddAppleSurface = {
    PSLDD_ID(APPLE_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    0, 2, -1, 1, 0};
#endif