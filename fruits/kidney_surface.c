
#include "kidney_surface.h"
#include "fruits_c_includes.h"

#if (USE_KIDNEY_SURFACE != 0)
void KidneySurface(pasuli_vartype u, pasuli_vartype v,
				   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(KIDNEY_SURFACE)

	pasuli_vartype cos_v = cos(v);
	pasuli_vartype cos_3v = cos(3 * v);
	pasuli_vartype sin_v = sin(v);
	pasuli_vartype sin_3v = sin(3 * v);
	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);

	pasuli_vartype xy = (3 * cos_v - cos_3v);

	P_X(cos_u * xy);
	P_Y(sin_u * xy);
	P_Z(3 * sin_v - sin_3v);

	xy = (3 * cos_v - cos_3v);
	UD_X(-sin_u * xy);
	UD_Y(cos_u * xy);
	UD_Z_CONST(0);

	xy = (3 * sin_3v - 3 * sin_v);
	VD_X(cos_u * xy);
	VD_Y(sin_u * xy);
	VD_Z(3 * cos_v - 3 * cos_3v);

	xy = (3 * cos_v - cos_3v) * (3 * cos_v - 3 * cos_3v);
	N_X(cos_u * xy);
	N_Y(-sin_u * xy);
	N_Z(-(3 * sin_3v - 3 * sin_v) * (3 * cos_v - cos_3v));

	xy = (3 * cos_v - cos_3v);
	UUD_X(-cos_u * xy);
	UUD_Y(-sin_u * xy);
	UUD_Z(0);

	xy = (3 * sin_3v - 3 * sin_v);
	UVD_X(-sin_u * xy);
	UVD_Y(cos_u * xy);
	UVD_Z(0);

	xy = (9 * cos_3v - 3 * cos_v);
	VVD_X(cos_u * xy);
	VVD_Y(sin_u * xy);
	VVD_Z(9 * sin_3v - 3 * sin_v);
}
/*

void KidneySurface_UA(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KIDNEY_SURFACE )

	pasuli_vartype cv = cos(v);
	pasuli_vartype c3v = cos(3*v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype s3v = sin(3*v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	
	pasuli_vartype xy = (3*cv - c3v);

	P_X( cu*xy );
	P_Y( su*xy );
	P_Z( 3*sv - s3v );

	xy = (3*cv - c3v);
	UD_X( -su*xy );
	UD_Y( cu*xy );
	UD_Z_CONST( 0 );

	xy = (3*s3v - 3*sv);
	VD_X( cu*xy );
	VD_Y( su*xy );
	VD_Z( 3*cv - 3*c3v );

	xy = (3*cv - c3v)*(3*cv - 3*c3v);
	N_X( cu*xy );
	N_Y( -su*xy );
	N_Z( -(3*s3v - 3*sv)*(3*cv - c3v) );

	xy = (3*cv - c3v);
	UUD_X( -cu*xy );
	UUD_Y( -su*xy );
	UUD_Z( 0 );

	xy = (3*s3v - 3*sv);
	UVD_X( -su*xy );
	UVD_Y( cu*xy );
	UVD_Z( 0 );

	xy = (9*c3v -3*cv);
	VVD_X( cu*xy );
	VVD_Y( su*xy );
	VVD_Z( 9*s3v - 3*sv );
}

void KidneySurface_VA(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KIDNEY_SURFACE )

	pasuli_vartype cv = cos(v);
	pasuli_vartype c3v = cos(3*v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype s3v = sin(3*v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	
	pasuli_vartype xy = (3*cv - c3v);

	P_X( cu*xy );
	P_Y( su*xy );
	P_Z( 3*sv - s3v );

	xy = (3*cv - c3v);
	UD_X( -su*xy );
	UD_Y( cu*xy );
	UD_Z_CONST( 0 );

	xy = (3*s3v - 3*sv);
	VD_X( cu*xy );
	VD_Y( su*xy );
	VD_Z( 3*cv - 3*c3v );

	xy = (3*cv - c3v)*(3*cv - 3*c3v);
	N_X( cu*xy );
	N_Y( -su*xy );
	N_Z( -(3*s3v - 3*sv)*(3*cv - c3v) );

	xy = (3*cv - c3v);
	UUD_X( -cu*xy );
	UUD_Y( -su*xy );
	UUD_Z( 0 );

	xy = (3*s3v - 3*sv);
	UVD_X( -su*xy );
	UVD_Y( cu*xy );
	UVD_Z( 0 );

	xy = (9*c3v -3*cv);
	VVD_X( cu*xy );
	VVD_Y( su*xy );
	VVD_Z( 9*s3v - 3*sv );
}
*/
#endif

#if (COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddKidneySurface = {
	PSLDD_ID(KIDNEY_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
	0, 2, -0.5f, 0.5, 0};
#endif
#if (COMPILE_DESC_FRUITS != 0)
char *descKidneySurface =
	"name: Kidney Surface; \
cat: fruits; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs:pi: -0.5; ve:pi: 0.5; \
x: cos(u)*(3*cos(v) - cos(3*v)); \
y: sin(u)*(3*cos(v) - cos(3*v)); \
z: 3*sin(v) - sin(3*v); "
#if (COMPILE_DESC_DERIV_U_FRUITS != 0)
	"xu: -sin(u)*(3*cos(v) - cos(3*v)); \
yu: cos(u)*(3*cos(v) - cos(3*v)); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_FRUITS != 0)
	"xv: 3*cos(u)*(sin(3*v) - sin(v)); \
yv: 3*sin(u)*(sin(3*v) - sin(v)); \
zv: 3*cos(v) - 3*cos(3*v); "
#endif
#if (COMPILE_DESC_NORMAL_FRUITS != 0)
	"xn: 3*cos(u)*(3*cos(v) - cos(3*v))*(cos(v) - cos(3*v)); \
yn: -3*sin(u)*(3*cos(v) - cos(3*v))*(cos(v) - cos(3*v)); \
zn: -(3*sin(3*v) - 3*sin(v))*(3*cos(v) - cos(3*v)); "
#endif
#if (COMPILE_DESC_DERIV2_U_FRUITS != 0)
	"xuu: -cos(u)*(3*cos(v) - cos(3*v)); \
yuu: -sin(u)*(3*cos(v) - cos(3*v)); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_FRUITS != 0)
	"xuv: -3*sin(u)*(sin(3*v) - sin(v)); \
yuv: 3*cos(u)*(sin(3*v) - sin(v)); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_FRUITS != 0)
	"xvv: 3*cos(u)*(3*cos(3*v) -cos(v)); \
yvv: 3*sin(u)*(3*cos(3*v) -3*cos(v)); \
zvv: 3*(3*sin(3*v) - sin(v)); "
#endif
	"end;";
#endif
