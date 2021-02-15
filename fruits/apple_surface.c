
#include "apple_surface.h"
#include "fruits_c_includes.h"

#if (USE_APPLE_SURFACE != 0)
void AppleSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(APPLE_SURFACE)

    pasuli_vartype sin_v = sin(v);
    pasuli_vartype cos_v = cos(v);
    pasuli_vartype x_or_y_mul = 4 + 3.8 * cos_v;

    P_X(cos(u) * x_or_y_mul);
    P_Y(sin(u) * x_or_y_mul);
    P_Z((cos_v + sin_v - 1) * (1 + sin_v) * log(1 - MY_PI * v / 10.0) + 7.5 * sin_v);

    UD_X(0);
    UD_Y(0);
    UD_Z(0);

    VD_X(0);
    VD_Y(0);
    VD_Z(0);
}
#endif

#if (COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddAppleSurface = {
    PSLDD_ID(APPLE_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    0, 2, -1, 1, 0};
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
z: (cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+7.5*sin(v); "
#if (COMPILE_DESC_DERIV_U_FRUITS != 0)
    "xu: -sin(u)*(4 + 3.8*cos(v)); \
yu: cos(u)*(4 + 3.8*cos(v)); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_FRUITS != 0)
    "xv: -3.8*cos(u)*sin(v); \
yv: -3.8*sin(u)*sin(v); \
zv: 7.5*cos(v) - log(1 - (pi*v)/10)*(1+sin(v)*(1-2*cos(v)) - 2*cos(v)*cos(v)) + pi*cos(v)*(1+sin(v)+cos(v))/(pi*v - 10); "
#endif
#if (COMPILE_DESC_NORMAL_FRUITS != 0)
    "xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if (COMPILE_DESC_DERIV2_U_FRUITS != 0)
    "xuu: -cos(u)*(4 + 3.8*cos(v)); \
yuu: -sin(u)*(4 + 3.8*cos(v)); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_FRUITS != 0)
    "xuv: 3.8*sin(u)*sin(v); \
yuv: -3.8*cos(u)*sin(v); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_FRUITS != 0)
    "xvv: -3.8*cos(u)*cos(v); \
yvv: -3.8*cos(v)*sin(u); \
zvv: log(1-v*pi)*(-2-cos(v)-4*cos(v)*sin(v)+4*cos(v)*cos(v)) + \
pi*(1-2*cos(v)*(sin(v)-cos(v)) +sin(v))/((5-0.5*v*pi) \
- pi*pi*cos(v)(1+sin(v)+cos(v))/((100 - 10*pi*v)^2) - 7.5*sin(v)); "
#endif
    "end;";
#endif