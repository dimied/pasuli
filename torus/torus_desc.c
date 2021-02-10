

#include "../pasuli_cfg.h"
#include "torus_desc.h"
#include "../pasuli_const.h"
#include "torus_const.h"


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTwistedEightTorus = {
PSLDD_ID( TWISTED_EIGHT_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTwistedEightTorus =
"start; \
name: Twisted Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: (R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*cos(u); \
y: (R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*sin(u); \
z: r*(sin(u/2)*sin(v) + cos(u/2)*sin(2*v)); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddUmbillicTorus = {
PSLDD_ID( UMBILLIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI|\
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1 , 1 , -1 , 1 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descUmbillicTorus =
"start; \
name: umbillic torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: pi: -1; \
uend: pi: 1; \
vstart: pi: -1; \
vend: pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: sin(u)*(7 + cos(u/3 - 2*v) + 2*cos(u/3 + v));  \
y: cos(u)*(7 + cos(u/3 - 2*v) + 2*cos(u/3 + v)); \
z: sin(u/3 - 2*v) + 2*sin(u/3 + v); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEightTorus = {
PSLDD_ID( EIGHT_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI|\
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1 , 1 , -1 , 1 , &torus_def_constants[2] };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descEightTorus =
"start; \
name: Eight Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: pi : -1; \
uend: pi: 1; \
vstart: pi: -1; \
vend: pi : 1; \
c:1:c: 1.0; \
x: cos(u) (c + sin(v) cos(u) - sin(2 v) sin(u)/2); \
y: sin(u) sin(v) + cos(u) sin(2 v)/2; \
z: sin(u) (c + sin(v) cos(u) - sin(2 v) sin(u)/2); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEllipticTorus = {
PSLDD_ID( ELLIPTIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
0 , 2 , 0 , 2 , &torus_def_constants[2] };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descEllipticTorus =
"start; \
name: Elliptic Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
c:1:a: 1.0; \
x: (a + cos(v))*cos(u); \
y: (a + cos(v))*sin(u); \
z: sin(v) + cos(v); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddSaddleTorus = {
PSLDD_ID( SADDLE_TORUS )	
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI,
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descSaddleTorus =
"start; \
name: Saddle Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
a:1:F: 1-cos(x)*cos(x) - cos(x + 2 pi/3)*cos(x + 2 pi/3); \
x: (2 + cos(u))*cos(v); \
y: (2 + cos(u + 2*pi/3))*cos(v + 2*pi/3); \
z: (2 + sign(F(u))*sqrt(abs(F(u))))*sign(F(v))*sqrt(abs(F(v))); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBraidedTorus = {
PSLDD_ID( BRAIDED_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 8 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descBraidedTorus =
"start; \
name: Braided Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 8; \
vstart: 0; \
vend: pi: 2; \
c:1:a: 1.0; \
c:2:R: 1.0; \
c:3:r: 1.0; \
c:4:n: 1.0; \
x: r*cos(v)*cos(u) + cos(u)*R*(1 + a*cos(n*u)); \
y: 2.5*(r*sin(v) + a*sin(n*u)); \
z: r*cos(v)*sin(u) + sin(u)*R*(1 + a*cos(n*u)); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLimpetTorus = {
PSLDD_ID( LIMPET_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI,
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descLimpetTorus =
"start; \
name: Limpet Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
x: cos(u)/(sqrt(2) + sin(v)); \
y: 1/(sqrt(2) + cos(v)); \
z: sin(u)/(sqrt(2) + sin(v)); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddStrangledTorus = {
PSLDD_ID( STRANGLED_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descStrangledTorus =
"start; \
name: Strangled Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.0; \
c:2:r: 1.0; \
c:3:n: 1.0; \
x: (R + r*sin(v))*cos(u); \
y: r*cos(v)*cos(n*u/2); \
z: (R + r*sin(v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddAstroidTorus = {
PSLDD_ID( ASTROID_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descAstroidTorus =
"start; \
name: Astroid Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.0; \
c:2:r: 1.0; \
a:1:F: (R + r*cos(v)*cos(v)*cos(v)); \
x: F*cos(u); \
y: r*sin(v)*sin(v)*sin(v); \
z: F*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTricuspoidTorus1 = {
PSLDD_ID( TRICUSPOID_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTricuspoidTorus1 =
"start; \
name: Tricuspoid Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
x: (R + r (2*cos(v) + cos(2*v)))*cos(u); \
y: r*(2*sin(v) - sin(2*v)); \
z: (R + r*(2*cos(v) + cos(2*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTricuspoidTorus2 = {
PSLDD_ID( TRICUSPOID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTricuspoidTorus2 =
"start; \
name: Tricuspoid Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
x: (R + r*(2*sin(v) - sin(2*v)))*cos(u); \
y: r*(2*cos(v) + cos(2*v)); \
z: (R + r*(2*sin(v) - sin(2*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddNethroidTorus1 = {
PSLDD_ID( NETHROID_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descNethroidTorus1 =
"start; \
name: Nethroid Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
x: (R + r*(3*cos(v) - cos(3*v)))*cos(u); \
y: r*(3*sin(v) - sin(3*v)); \
z: (R + r*(3*cos(v) - cos(3*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddNethroidTorus2 = {
PSLDD_ID( NETHROID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descNethroidTorus2 =
"start; \
name: Nethroid Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
x: (R + r*(3 sin(v) - sin(3*v)))*cos(u); \
y: r*(3*cos(v) - cos(3*v)); \
z: (R + r*(3*sin(v) - sin(3*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLemniskateTorus1 = {
PSLDD_ID( LEMNISKATE_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descLemniskateTorus1 =
"start; \
name: Lemniskate Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
a:1:F: r cos(v)/(1 + sin(v) sin(v)); \
x: (R + F)*cos(u); \
y: r*sin(v)*F; \
z: (R + F)*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLemniskateTorus2 = {
PSLDD_ID(LEMNISKATE_TORUS_2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descLemniskateTorus2 =
"start; \
name: Lemniskate Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.5; \
c:2:r:0.5; \
x: (R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))*cos(u); \
y: r*cos(v)/(1 + sin(v)*sin(v)); \
z: (R + r*sin(v) cos(v)/(1 + sin(v)*sin(v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEpizykloidTorus1 = {
PSLDD_ID( EPIZYKLOID_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descEpizykloidTorus1 =
"start; \
name: Epizykloid Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
c:3:r:0.5; \
c:4:h: 1.0; \
x: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r) v))*cos(u); \
y: (R + r)*sin(v) - h*sin(((R + r)/r)*v); \
z: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEpizykloidTorus2 = {
PSLDD_ID( EPIZYKLOID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descEpizykloidTorus2 =
"start; \
name: Epizykloid Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
c:3:r:0.5; \
c:4:h: 1.0; \
x: (R1 + (R + r)*sin(v) - h*sin(((R + r)/r)*v))*cos(u); \
y: (R + r)*cos(v) - h*cos(((R + r)/r) v); \
z: (R1 + (R + r)*sin(v) - h*sin(((R + r)/r)*v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddHypozykloidTorus1 = {
PSLDD_ID( HYPOZYKLOID_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descHypozykloidTorus1 =
"start; \
name: HypozykloidTorus1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
c:3:r:0.5; \
c:4:h: 1.0; \
x = (R1 + (R - r)*cos(v) - h*cos(((R - r)/r)*v))*cos(u); \
y = (R - r)*sin(v) - h*sin(((R + r)/r)*v); \
z = (R1 + (R - r)*cos(v) - h*cos(((R - r)/r)*v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddHypozykloidTorus2 = {
PSLDD_ID( HYPOZYKLOID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descHypozykloidTorus2 =
"start; \
name: HypozykloidTorus2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
c:3:r:0.5; \
c:4:h: 1.0; \
a:1:F: (R1 + (R - r)*sin(v) - h*sin(((R - r)/r)*v)); \
x: F*cos(u); \
y: (R - r)*cos(v) - h*cos(((R + r)/r)*v); \
z: F*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddPiriformTorus1 = {
PSLDD_ID( PIRIFORM_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descPiriformTorus1 =
"start; \
name: Piriform Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + (r + sin(v)))*cos(u); \
y: cos(v)*(r + sin(v)); \
z: (R + (r + sin(v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddPiriformTorus2 = {
PSLDD_ID( PIRIFORM_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descPiriformTorus2 =
"start; \
name: Piriform Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + cos(v)*(r + sin(v)))*cos(u); \
y: r + sin(v); \
z: (R + cos(v)*(r + sin(v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBicornTorus1 = {
PSLDD_ID( BICORN_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descBicornTorus1 =
"start; \
name: Bicorn Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + r*cos(v)^{2}*(2 + cos(v))/(3 + sin(v)^{2}))*cos(u); \
y: r*sin(v); \
z: (R + r*cos(v)^{2}*(2 + cos(v))/(3 + sin(v)^{2}))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBicornTorus2 = {
PSLDD_ID( BICORN_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descBicornTorus2 =
"start; \
name: Bicorn Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + r*sin(v))*cos(u); \
y: r*cos(v)^{2}*(2 + cos(v))/(3 + sin(v)^{2}); \
z: (R + r*sin(v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCardioidTorus1 = {
PSLDD_ID( CARDIOID_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descCardioidTorus1 =
"start; \
name: Cardioid Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + r*(2*cos(v) - cos(2*v)))*cos(u); \
y: r (2 sin(v) - sin(2 v)); \
z: (R + r*(2*cos(v) - cos(2*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCardioidTorus2 = {
PSLDD_ID( CARDIOID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descCardioidTorus2 =
"start; \
name: Cardioid Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1:1.0; \
c:2:R: 1.0; \
x: (R + r*(2*sin(v) - sin(2*v)))*cos(u); \
y: r*(2*cos(v) - cos(2*v)); \
z: (R + r*(2*sin(v) - sin(2*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif



//#if(COMPILE_DESC_DERIV_U_TORUS != 0)
//"xu: 0; \
//yu: 0; \
//zu: 0; "
//#endif
//#if(COMPILE_DESC_DERIV_V_TORUS != 0)
//"xv: 0; \
//yv: 0; \
//zv: 0; "
//#endif
//#if(COMPILE_DESC_NORMAL_TORUS != 0)
//"xn: 0; \
//yn: 0; \
//zn: 0; "
//#endif
//#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
//"xuu: 0; \
//yuu: 0; \
//zuu: 0; "
//#endif
//#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
//"xuv: 0; \
//yuv: 0; \
//zuv: 0; "
//#endif
//#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
//"xvv: 0; \
//yvv: 0; \
//zvv: 0; "
//#endif

