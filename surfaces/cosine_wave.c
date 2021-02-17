
#include "cosine_wave.h"
#include "surfaces_c_includes.h"

#if (USE_COSINE_WAVE != 0)

void CosineWave(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(COSINE_WAVE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_calctype sqrt_uv = sqrt(u * u + v * v);

	P_X(u);
	P_Y(v);
	P_Z(a * cos(b * sqrt_uv));

	pasuli_calctype sin_b_sqrt = sin(b * sqrt_uv);
	// Multiplied by sqrt(u*u + v*v)
	UD_X(sqrt_uv);
	UD_Y_CONST(0);
	UD_Z(a * b * u * sin_b_sqrt);

	// Multiplied by sqrt(u*u + v*v)
	VD_X_CONST(0);
	VD_Y(sqrt_uv);
	VD_Z(a * b * v * sin_b_sqrt);

	if (sqrt_uv > 0.01)
	{
		N_X(PASULI_COND_COPY_UD_X(a * b * u * sin_b_sqrt) / sqrt_uv);
		N_Y(PASULI_COND_COPY_VD_X(a * b * v * sin_b_sqrt) / sqrt_uv);
		N_Z(1);
	}
	else
	{
		// Multiplied by sqrt(u*u + v*v)
		N_X(PASULI_COND_COPY_UD_X(a * b * u * sin_b_sqrt));
		N_Y(PASULI_COND_COPY_VD_X(a * b * v * sin_b_sqrt));
		N_Z(sqrt_uv);
	}
}

#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineWave = {
PSLDD_ID( COSINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5, 5 , -5 , 5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descCosineWave =
	"name: Cosine Wave; \
ut:c; vt:c; \
us: -5; ue: 5; \
vs: -5; ve: 5; \
c1:a: 1.5; c2:b: 0.5; \
x: u; \
y: v; \
z: a*cos(b*sqrt(u*u + v*v)); \
xu: 1; \
yu: 0; \
zu: a*b*u*sin(b*sqrt(u*u + v*v))/sqrt(u*u + v*v); \
xv: 0; \
yv: 1; \
zv: a*b*v*sin(b*sqrt(u*u + v*v))/sqrt(u*u + v*v); \
xn: a*b*u*sin(b*sqrt(u*u + v*v))/sqrt(u*u + v*v); \
yn: a*b*v*sin(b*sqrt(u*u + v*v))/sqrt(u*u + v*v); \
zn: 1;";
#endif
