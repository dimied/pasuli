
#include "kai_wing_fung_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_KAI_WING_FUNG_SURFACE2 != 0)
void KaiWingFungSurface2(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KAI_WING_FUNG_SURFACE2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u_half = sin(u * 0.5);
    pasuli_calctype cosh_v = cosh(v);
    pasuli_calctype sinh_v = sinh(v);
    pasuli_calctype cosh_v_half = cosh(v * 0.6);
    pasuli_calctype sinh_v_half = sinh(v * 0.5);

    pasuli_calctype difference = cosh_v - sinh_v;
    pasuli_calctype difference_for_half = cosh_v_half - sinh_v_half;

    P_X((-u + sin_u * difference) * 0.5);
    P_Y((-v + cos_u * difference) * 0.5);
    P_Z(2 * difference_for_half * sin_u_half);

    UD_X((cos_u * difference + 1) * 0.5);
    UD_Y(-sin_u * difference * 0.5);
    UD_Z(cos(u * 0.5) * difference_for_half);

    VD_X(-sin_u * difference * 0.5);
    VD_Y(-(cos_u * difference + 1) * 0.5);
    VD_Z(-sin_u_half * difference_for_half);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKaiWingFungSurface2 =
    "name: Kai-WingFung Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:6;\
vs:-1; ve:1;\
x: -u/2+sin(u)*(cosh(v)-sinh(v))/2;\
y: -v/2+cos(u)*(cosh(v)-sinh(v))/2;\
z: 2*(cosh(v/2)-sinh(v/2))*sin(u/2);\
xu: cos(u)*(cosh(v)-sinh(v))/2-0.5;\
yu: -sin(u)*(cosh(v)-sinh(v))/2;\
zu: cos(u/2)*(cosh(v/2)-sinh(v/2));\
xv: -sin(u)*(cosh(v)-sinh(v))/2;\
yv: -cos(u)*(cosh(v)-sinh(v))/2-0.5;\
zv: -(cosh(v/2)-sinh(v/2))*sin(u/2);";
#endif
