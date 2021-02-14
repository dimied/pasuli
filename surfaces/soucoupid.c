
#include "soucoupid.h"
#include "surfaces_c_includes.h"

#if (USE_SOUCOUPOID != 0)

void Soucoupoid(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SOUCOUPOID)

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X(cu * cv);
	P_Y(su * su * su);
	P_Z(cu * sv);

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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSoucoupoid = {
PSLDD_ID( SOUCOUPOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI,
-1, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSoucoupoid =
"name: Soucoupoid; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs: 0; ve:pi: 1; \
x: cos(u)*cos(v); \
y: (sin(u))^(3); \
z: cos(u)*sin(v); \
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