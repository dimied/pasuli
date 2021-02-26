
#include "boys_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_BOYS_SURFACE2 != 0)
void BoysSurface2(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOYS_SURFACE2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype A = sin_u * sin_v;
    pasuli_calctype B = cos_u * sin_v;
    pasuli_calctype C = cos_v;
    pasuli_calctype AplusBplusC = A + B + C;
    pasuli_calctype A_q2 = A * A;
    pasuli_calctype B_q2 = B * B;
    pasuli_calctype C_q2 = C * C;

    P_X(((2 * B_q2 - A_q2 - C_q2) * (A_q2 + B_q2 + C_q2) + 2 * A * C * (A_q2 - C_q2 + B * C * (B_q2 - C_q2) + A * B * (A_q2 - B_q2))) * 0.5);
    P_Y(((A_q2 - C_q2) * (A_q2 + B_q2 + C_q2) + B * C * (C_q2 - B_q2) + A * B * (A_q2 - B_q2)) * sqrt(3) * 0.5);
    P_Z(AplusBplusC * (AplusBplusC * AplusBplusC * AplusBplusC + 4 * (A - B) * (C - A) * (B - C)) * 0.125f);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBoysSurface2 =
    "name: Boy Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
a1:A: sin(u)*sin(v);\
a2:B: cos(u)*sin(v);\
a3:C: cos(v);\
x: ((2*B^2-A^2-C^2)*(A^2+B^2+C^2)+2*A*C*(A^2-C^2)+B*C*(B^2-C^2)+A*B*(A^2-B^2))/2;\
y: ((A^2-C^2)*(A^2+B^2+C^2)+B*C*(C^2-B^2)+A*B*(A^2-B^2))*sqrt(3)/2;\
z: (A+B+C)*((A+B+C)^3+4*(A-B)*(C-A)*(B-C))/8;";
#endif
