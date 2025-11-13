
#include <math.h>
#include "../pasuli_common/pasuli_const.h"
#include "../pasuli_common/pasuli_macros.h"
#include "../pasuli_conf/pasuli_cfg.h"
#include "sphere.h"
#include "tests/sphere_test_conf.h"

#if (USE_SPHERE != 0)
void Sphere(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype r = *constants;
	pasuli_calctype rsinu = r * sin_u;

	P_X(cos_v * rsinu);
	P_Y(sin_v * rsinu);
	P_Z(cos_u * r);

	// No scaling by sin_v
#if (PASULIOBJECT_UD != 0)
	UD_X(-sin_u);
	UD_Y(cos_u);
	UD_Z_CONST(0);
#endif

#if (PASULIOBJECT_VD != 0)
	VD_X(cos_u * cos_v);
	VD_Y(sin_u * cos_v);
	VD_Z(-sin_v);
#endif

	// No scaling by sin_v
	N_X(-PASULI_COND_COPY_POS_X(sin_u * cos_v));
	N_Y(-PASULI_COND_COPY_POS_Y(sin_u * sin_v));
	N_Z(-PASULI_COND_COPY_POS_Z(cos_u));

	// No scaling by sin_v
	UUD_X(-cos_v);
	UUD_Y(-sin_v);
	UUD_Z_CONST(0);

	// No scaling by cos_v
	UVD_X(-sin_v);
	UVD_Y(cos_v);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(cos_v * sin_u));
	VVD_Y(-PASULI_COND_COPY_POS_Y(sin_v * sin_u));
	VVD_Z(-cos_u);
}

#endif

///////////////////////////////////////////////

pasulidefdesc_ct sphere_def_constants[] = {1.5, 1.0, 1.0};

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphere = {
	SPHERE,
	PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(0),
	0, 2, 0, 1, 0};
#endif

#if (COMPILE_DESC_SPHERE != 0)
char *descSphere =
	"name: Sphere;\
cat: sphere;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: cos(u)*sin(v);\
y: sin(u)*sin(v);\
z: cos(v);\
xu: -sin(u)*sin(v);\
yu: cos(u)*sin(v);\
zu: 0;\
xv: cos(u)*cos(v);\
yv: sin(u)*cos(v);\
zv: -sin(v);\
xn: -cos(u)*sin(v)*sin(v);\
yn: -sin(u)*sin(v)*sin(v);\
zn: -sin(v)*cos(v);\
xuu: -cos(u)*sin(v);\
yuu: -sin(u)*sin(v);\
zuu:  0;\
xuv: -sin(u)*cos(v);\
yuv: cos(u)*cos(v);\
zuv: 0;\
xvv: -cos(u)*sin(v);\
yvv: -sin(u)*sin(v);\
zvv:  -cos(v); ";
#endif
