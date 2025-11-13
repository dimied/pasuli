
#include "neovius_surface.h"
#include "surfaces_c_includes.h"

#if (USE_NEOVIUS_SURFACE != 0)
void NeoviusSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(NEOVIUS_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_v = cos(v);

    P_X(u);
    P_Y(v);
    P_Z(acos(-3 * (cos_u + cos_v) / (3 + 4 * cos_u * cos_v)));
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descNeoviusSurface =
    "name: Neovius Surface;\
ut:c; vt:o;\
us:pi: -0.5; ue:pi: 0.5;\
vs:pi: -0.5; ve:pi: 0.5;\
x: u;\
y: v;\
z: arccos((-3*(cos(u)+cos(v)))/(3+4*cos(u)*cos(v)));";
#endif
