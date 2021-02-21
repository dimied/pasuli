
#include "bullet_nose.h"
#include "surfaces_c_includes.h"

#if (USE_BULLET_NOSE != 0)
void BulletNose(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BULLET_NOSE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype a_cos_v = a * cos(v);

    P_X(a_cos_v * cos_u);
    P_Y(a_cos_v * sin_u);
    P_Z((-b) / tan(v));

    UD_X(-PASULI_COND_COPY_POS_Y(a_cos_v * sin_u));
    UD_Y(PASULI_COND_COPY_POS_X(a_cos_v * cos_u));
    UD_Z(0);

    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_v2 = sin_v * sin_v;

    if (sin_v2 < 0.0001)
    {
        VD_X(-a * sin_v * cos_u * sin_v2);
        VD_Y(-a * sin_v * sin_u * sin_v2);
        VD_Z(b);
    }
    else
    {
        VD_X(-a * sin_v * cos_u);
        VD_Y(-a * sin_v * sin_u);
        VD_Z(b / sin_v2);
    }

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v_cos_v = sin_v * cos_v;

    //Skip scaling by a
    if(fabs(sin_v_cos_v)< 0.0001) {
        sin_v_cos_v = 0.0001;
    } 

    N_X(b*cos_u*cos_v/(sin_v*sin_v_cos_v));
    N_Y(b*sin_u*cos_v/(sin_v*sin_v_cos_v));
    N_Z(a*sin_v_cos_v);
    
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBulletNose = {
PSLDD_ID( BULLET_NOSE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0.25f , 0.5f , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBulletNose =
    "name: Bullet Nose;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0.25; ve:pi: 0.5;\
c1:a: 1.5; c2:b: 0.5;\
x: a*cos(v)*cos(u);\
y: a*cos(v)*sin(u);\
z: -b/tan(v);\
x: a*cos(v)*cos(u);\
y: a*cos(v)*sin(u);\
z: -b/tan(v);\
xu: -a*cos(v)*sin(u);\
yu: a*cos(v)*cos(u);\
zu: 0;\
xv: -a*sin(v)*cos(u);\
yv: -a*sin(v)*sin(u);\
zv: b/sin(v)^2;\
xn: a*b*cos(u)/(cos(v)*tan(v)^2);\
yn: a*b*sin(u)/(cos(v)*tan(v)^2);\
zn: a*a*cos(v)*sin(v);\
xuu: -a*cos(v)*cos(u);\
yuu: -a*cos(v)*sin(u);\
zuu: 0;\
xuv: a*sin(v)*sin(u);\
yuv: -a*sin(v)*cos(u);\
zuv: 0;\
xvv: -a*cos(v)*cos(u);\
yvv: -a*cos(v)*sin(u);\
zvv: 2*b*cos(v)/(cos(v)^2*sin(v)) - 2*b/(cos(v)*sin(v)^3);";
#endif