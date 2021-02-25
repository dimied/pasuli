
#include "planar_enneper_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PLANAR_ENNEPER_SURFACE != 0)
void PlanarEnneperSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLANAR_ENNEPER_SURFACE)

    pasuli_consttype n = constants[0];
    pasuli_consttype A = constants[1];
    pasuli_consttype a = constants[2];

    pasuli_calctype exp_2au = exp(2 * a * u);
    pasuli_calctype exp_minus_nu = exp(-(n + 1) * u);
    pasuli_calctype exp_plus_nu = exp((n + 1) * u);
    pasuli_calctype divisor1 = 2 * a * A - A * (n + 1);
    pasuli_calctype common_divisor = 2 * a * (n + 1);

    P_X(exp_2au * (exp_minus_nu * cos(2 * a - (n + 1) * v) / divisor1 - A * exp_plus_nu * cos(2 * a + (n + 1) * v) / common_divisor) / common_divisor);
    P_Y(exp_2au * (exp_minus_nu * sin(2 * a - (n + 1) * v) / divisor1 + A * exp_plus_nu * sin(2 * a + (n + 1) * v) / common_divisor) / common_divisor);
    P_Z(-exp_2au * cos(2 * a * v) / common_divisor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlanarEnneperSurface =
    "name: Planar Enneper Surface;\
ut:c; vt:o;\
us:-0.8; ue:0.5;\
vs:-1.5; ve:1.5;\
c1:n: 2; c1:A: 0.4; c3:a: 1;\
x: exp(2*a*u)*(exp(-(n+1)*u)*cos((2*a-(n+1))*v)/(2*a*A-A*(n+1)) - A*exp((n+1)*u)*cos((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
y: exp(2*a*u)*(exp(-(n+1)*u)*sin((2*a-(n+1))*v)/(2*a*A-A*(n+1)) + A*exp((n+1)*u)*sin((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
z: -exp(2*a*u)*cos(2*a*v)/(2*a*(n+1));";
#endif
