
#include "pseudo_cross_cap.h"
#include "surfaces_c_includes.h"

#if (USE_PSEUDO_CROSS_CAP != 0)
void PseudoCrossCap(pasuli_vartype u, pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PSEUDO_CROSS_CAP)

	double one_minus_usq = 1.0 - u * u;

	P_X(one_minus_usq * sin(v));
	P_Y(one_minus_usq * sin(2 * v));
	P_Z(u);

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPseudoCrossCap = {
	PSLDD_ID(PSEUDO_CROSS_CAP)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPseudoCrossCap =
	"name: Pseudo Cross Cap; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
x: (1 - u*u)*sin(v); \
y: (1 - u*u)*sin(2*v); \
z: u; \
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