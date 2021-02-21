
#include "hole_disc.h"
#include "surfaces_c_includes.h"

#if (USE_HOLE_DISC != 0)
void HoleDisc(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HOLE_DISC)

    pasuli_calctype sin_v = sin(v);
    pasuli_calctype divisor = sqrt(2.0) + sin_v;
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype z_divisor = sqrt(2.0) + 1;

    P_X(sin_u / divisor);
    P_Y(cos_u / divisor);
    P_Z(cos_u / z_divisor);

    UD_X(PASULI_COND_COPY_POS_Y(cos_u / divisor));
    UD_Y(-PASULI_COND_COPY_POS_X(sin_u / divisor));
    UD_Z(-sin_u / z_divisor);

    pasuli_calctype cos_v = sin(v);
    // Skip division by (sqrt(2) + sin(v))^2
    VD_X(sin_u * cos_v);
    VD_Y(cos_u * cos_v);
    VD_Z(0);

    // Skip division by (sqrt(2) + sin(v))^2
    N_X(-cos_u * cos_v * sin_u / z_divisor);
    N_Y(cos_v * sin_u * sin_u / z_divisor);
    N_Z(-cos_v / divisor);

    UUD_X(-PASULI_COND_COPY_POS_X(sin_u / divisor));
    UUD_Y(-PASULI_COND_COPY_POS_Y(cos_u / divisor));
    UUD_Z(-PASULI_COND_COPY_POS_Z(cos_u / z_divisor));

    // Skip division by (sqrt(2) + sin(v))^2
    UVD_X(-cos_u * cos_v);
    UVD_Y(sin_u * cos_v);
    UVD_Z_CONST(0);

    // Skip division by (sqrt(2) + sin(v))^3
    z_divisor = 1 + cos_v * cos_v + sqrt(2) * sin_v;
    VVD_X(sin_u * z_divisor);
    VVD_Y(cos_u * z_divisor);
    VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDisc = {
    PSLDD_ID(HOLE_DISC)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI,
    0, 2, 3, 4.5, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descHoleDisc =
    "name: Hole Disc;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 3; ve: 4.5;\
x: sin(u)/(sqrt(2) + sin(v));\
y: cos(u)/(sqrt(2) + sin(v));\
z: cos(u)/(1 + sqrt(2));\
xu: cos(u)/(sqrt(2) + sin(v));\
yu: -sin(u)/(sqrt(2) + sin(v));\
zu: -sin(u)/(1 + sqrt(2));\
xv: sin(u)*cos(v)/(sqrt(2) + sin(v))^2;\
yv: cos(u)*cos(v)/(sqrt(2) + sin(v))^2;\
zv: 0;\
xn: -cos(u)*cos(v)*sin(u)/((1 + sqrt(2))*(sqrt(2) + sin(v))^2);\
yn: cos(v)*sin(u)^2/((1 + sqrt(2))*(sqrt(2) + sin(v))^2);\
zn: -cos(v)/((sqrt(2) + sin(v))^3);\
xuu: -sin(u)/(sqrt(2) + sin(v));\
yuu: -cos(u)/(sqrt(2) + sin(v));\
zuu: -cos(u)/(1 + sqrt(2));\
xuv: -cos(u)*cos(v)/(sqrt(2) + sin(v))^2;\
yuv: sin(u)*cos(v)/(sqrt(2) + sin(v))^2;\
zuv: 0;\
xvv: sin(u)*(1 + cos(v)^2 + sqrt(2)*sin(v))/(sqrt(2) + sin(v))^3;\
yvv: cos(u)*(1 + cos(v)^2 + sqrt(2)*sin(v))/(sqrt(2) + sin(v))^3;\
zvv: 0; ";
#endif
