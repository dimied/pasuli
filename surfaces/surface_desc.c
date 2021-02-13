
#include "surfaces.h"

pasulidefdesc_ct psldd_15_05_constants[] = {1.5, 0.5, 1.0, 1.0, 1.0, 1.0};
pasulidefdesc_ct psldd_10_constants[] = {1.0};

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTeardrop = {
PSLDD_ID( TRIAXIAL_TEARDROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTeardrop =
"name: Triaxial Teardrop; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs: 0; \
ve:pi: 2; \
x: (1 - cos(u))*cos(u + 2*pi/3)*cos(v + 2*pi/3)/2; \
y: (1 - cos(u))*cos(u + 2*pi/3)*cos(v - 2*pi/3)/2; \
z: cos(u - 2*pi/3); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPillowShape = {
PSLDD_ID( PILLOW_SHAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_FULL_IMPL| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPillowShape =
"name:pillow Shape; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:a: 1.5; \
x: cos(u); \
y: cos(v); \
z: a*sin(u)*sin(v); "
"xu: -sin(u); \
yu: 0; \
zu: a*cos(u)*sin(v); "
"xv: 0; \
yv: -sin(v); \
zv: a*cos(v)*sin(u); "
"xn: a*cos(u)*sin(v)*sin(v); \
yn: a*cos(v)*sin(u)*sin(u); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); \
yuu: 0; \
zuu: -a*sin(u)*sin(v); "
"xuv: 0; \
yuv: 0; \
zuv: a*cos(u)*cos(v); "
"xvv: 0; \
yvv: -cos(v); \
zvv: -a*sin(u)*sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFishSurface = {
PSLDD_ID( FISH_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFishSurface =
"name: Fish Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs: 0; \
ve:pi: 2; \
x: (cos(u) - cos(2*u))*cos(v)/4; \
y: (sin(u) - sin(2*u))*sin(v)/4; \
z: cos(u); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHorn = {
PSLDD_ID( HORN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(3),
0, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHorn =
"name: Horn; \
ut:c; \
vt:c; \
us: 0; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: (a + u*cos(v))*sin(b*pi*u); \
y: (a + u*cos(v))*cos(b*pi*u) + c*u; \
z: u*sin(v); "
"xu: b*pi*cos(b*pi*u)(a+u*cos(v)) + cos(v)*sin(b*pi*u); \
yu: c - b*pi*sin(b*pi*u)*(a+u*cos(v)) + cos(v)*cos(b*pi*u); \
zu: sin(v); "
"xv: -u*sin(v)*sin(b*pi*u); \
yv: -u*sin(v)*cos(b*pi*u); \
zv: u*cos(v); "
"xn: u*(b*pi*sin(b*pi*u)*cos(v)*(-a - u*cos(v)) +c*cos(v)+cos(b*pi*u)); \
yn: -u*(b*pi*cos(v)*cos(b*pi*u)*(a+u*cos(v)) + sin(b*pi*u)); \
zn: u*sin(v)*(-b*pi*(a+u*cos(v)) + c*sin(b*pi*u) ); "
"xuu: b*pi*(-b*pi*sin(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*cos(b*pi*u); \
yuu: b*pi*(-b*pi*cos(b*pi*u)*(a + u*cos(v))) - 2*cos(v)*sin(b*pi*u); \
zuu: 0; "
"xuv: -sin(v)*(b*pi*u*cos(b*pi*u) + sin(b*pi*u)); \
yuv: sin(v)*(b*pi*u*sin(b*pi*u) - cos(b*pi*u)); \
zuv: cos(v); "
"xvv: -u*cos(v)*sin(b*pi*u); \
yvv: -u*cos(v)*cos(b*pi*u); \
zvv: -u_sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBentHorns = {
PSLDD_ID( BENT_HORNS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBentHorns =
"name: Bent Horns; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -2; \
ve:pi: 2; \
x: (2 + cos(u))*(v/3 - sin(v)); \
y: (2 + cos(u + 2*pi/3))*(cos(v) - 1); \
z: (2 + cos(u - 2*pi/3))*(cos(v) - 1); \
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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicOctahedron = {
PSLDD_ID( HYPERBOLIC_OCTAHEDRON )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-0.5, 0.5 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicOctahedron =
"name: Hyperbolic Octahedron; \
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs:pi: -1; \
ve:pi: 1; \
x: (cos(u)*cos(v))^(3); \
y: (sin(u)*cos(v))^(3); \
z: sin(v)^(3); "
"xu: -3*(cos(u)^2)*(cos(v)^3)*sin(u); \
yu: 3*cos(u)*(cos(v)^3)*(sin(u)^2); \
zu: 0; "
"xv: -3*(cos(u)^3)*(cos(v)^2)*sin(v); \
yv: -3*(cos(v)^2)*(sin(u)^3)*sin(v); \
zv: 3*cos(v)*sin(v)*sin(v); "
"xn: 9*cos(u)*(cos(v)^4)*(sin(u)^2)*(sin(v)^2); \
yn: 9*(cos(u)^2)*(cos(v)^4)*sin(u)*(sin(v)^2); \
zn: 9*(cos(u)^2)*(cos(v)^5)*(sin(u)^2)*sin(v); "
"xuu: 3*cos(u)*(cos(v)^3)*(2-3*cos(u)*cos(u)); \
yuu: 3*sin(u)*(cos(v)^3)*(2-3*sin(u)*sin(u)); \
zuu: 0; "
"xuv: 9*((cos(u)*cos(v))^2)*sin(u)*sin(v); \
yuv: -9*(cos(u)*(cos(v)^2)*(sin(u)^2)*sin(v); \
zuv: 0; "
"xvv: 3*(2-3*cos(v)*cos(v))*(cos(u)^3)*cos(v); \
yvv: 3*(2-3*cos(v)*cos(v))*(sin(u)^3)*cos(v); \
zvv: 3*sin(v)*(2-3*sin(v)*sin(v)); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPseudoCrossCap = {
PSLDD_ID( PSEUDO_CROSS_CAP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPseudoCrossCap =
"name: Pseudo Cross Cap; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCresent = {
PSLDD_ID( CRESENT )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCresent =
"name: Cresent; \
ut:c; \
vt:c; \
us: 0; \
ue: 1; \
vs: 0; \
ve: 1; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: (a + sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v); \
y: (a + sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v); \
z: cos(b*pi*u)*sin(b*pi*v) + 4*v - 2; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddStilettoSurface = {
PSLDD_ID( STILETTO_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descStilettoSurface =
"name: Stiletto Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 1; \
x: (2+cos(u))*cos(v)*cos(v)*cos(v)*sin(v); \
y: (2+cos(u+2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
z: -(2+cos(u-2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKuensSurface = {
PSLDD_ID( KUENS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-4.3f, 4.3f , 0.03f , 3.11f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKuensSurface =
"name: Kuens Surface; \
ut:c; \
vt:c; \
us: -4.3; \
ue: 4.3; \
vs: 0.01; \
ve: 3.11; \
a:1:h: 1 + u*u*sin(v)*sin(v); \
x: (2*(cos(u) + u sin(u))*sin(v))/h; \
y: (2*(-u*cos(u) + sin(u))*sin(v))/h; \
z: log(tan(v/2)) + 2*cos(v)/h; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots = {
PSLDD_ID( TREFOIL_KNOTS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 12 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots =
"name: Trefoil Knots; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 12; \
vs: 0; \
ve:pi: 2; \
c1:R: 1.5; \
c2:r: 0.5; \
a:1:Bx: (R + r*cos(u/2))*cos(u/3); \
a:2:By: (R + r*cos(u/2))*sin(u/3); \
a:3:Bz: r + sin(u/2); \
x: Bx + r*cos(u/3)*cos(v-pi); \
y: By + r*sin(u/3)*cos(v-pi); \
z: Bz + r*sin(v-pi); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTranguloidTrefoil = {
PSLDD_ID( TRANGULOID_TREFOIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTranguloidTrefoil =
"name: Tranguloid Trefoil; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
x: 2*sin(3*u)/(2 + cos(v)); \
y: 2*(sin(u) + 2*sin(2*u))/(2 + cos(v + 2*pi/3)); \
z: (cos(u) - 2*cos(2*u))*(2 + cos(v))*(2 + cos(v + 2*pi/3))/4; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrown = {
PSLDD_ID( CROWN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCrown =
"name: Crown; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
x: cos(u + 4)/3; \
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v) + 0.5*cos(u); \
z: cos(v)*sin(u)*cos(u)*sin(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedPipeSurface = {
PSLDD_ID( TWISTED_PIPE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedPipeSurface =
"name: Twistedpipe Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
a:1:h: sqrt(1 + sin(v)*sin(v)); \
x: cos(v)*(2 + cos(u))/h; \
y: sin(v - 2*pi/3)*(2 + cos(u - 2*pi/3))/h; \
z: sin(v + 2*pi/3)*(2 + cos(u + 2*pi/3))/h; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLoop = {
PSLDD_ID( LOOP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLoop =
"name: Loop; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
x: sin(v)*cos(u); \
y: 2*cos(v); \
z: 4*sin(v)*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDupinCyclide = {
PSLDD_ID( DUPIN_CYCLIDE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDupinCyclide =
"name: Dupin Cyclide; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
c4:d: 1.0; \
a:1:h: a - c*cos(u)*cos(v); \
x: (d*(c - a*cos(u)*cos(v)) + b*b*cos(u))/h; \
y: (b*sin(u)*(a - d*cos(v)))/h; \
z: b*sin(v)*(c*cos(u) - d)/h; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddGuimardSurface = {
PSLDD_ID( GUIMARD_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descGuimardSurface =
"name: Guimard Surface; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: ((1 - u)*a + u*b)*cos(v); \
y: b*u*sin(v); \
z: c*u*sin(v)*sin(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMennsSurface = {
PSLDD_ID( MENNS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMennsSurface =
"name: Menns Surface; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
c1:a: 1.0; \
x: u; \
y: v; \
z: a*u^(4) + u*u*v - v*v; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMilkBag = {
PSLDD_ID( MILK_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMilkBag =
"name: Milk Bag; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:k: 1.0; \
x: k*(1 + u)*cos(v); \
y: k*(1 - u)*sin(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTritorus = {
PSLDD_ID( TRIAXIAL_TRITORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTritorus =
"name: Triaxial Tritorus; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
x: sin(u)*(1 + cos(v)); \
y: sin(u + 2*pi/3)*(1 + cos(v + 2*pi/3)); \
z: sin(u + 4*pi/3)*(1 + cos(v + 4*pi/3)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddVerrillSurface = {
PSLDD_ID( VERRILL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0.5, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descVerrillSurface =
"name: Verrill Surface; \
ut:c; \
vt:c; \
us: 0.5; \
ue: 1; \
vs: 0; \
ve:pi: 2; \
x: -2*u*cos(v) + (2*cos(v)/u) - 2*u^(3)*cos(3*v)/3; \
y: 6*u*sin(v) - 2*sin(v)/u - 2*u^(3)*cos(3*v)/3; \
z: 4*log(u); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddZindlersConoid = {
PSLDD_ID( ZINDLERS_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -0.75f , 0.75f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descZindlersConoid =
"name: Zindlers Conoid; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: -0.75; \
ve: 0.75; \
c1:a: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: a*tan(2*v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFolium = {
PSLDD_ID( FOLIUM )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFolium =
"name: Folium; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
x: cos(u)*(2*v/pi - tanh(v)); \
y: cos(u + 2*pi/3)/cosh(v); \
z: cos(u - 2*pi/3)/cosh(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLemniscape = {
PSLDD_ID( LEMNISCAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLemniscape =
"name: Lemniscape; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs: 0; \
ve:pi: 1; \
x: cos(v)*sqrt(abs(sin(2*u)))*cos(u); \
y: cos(v)*sqrt(abs(sin(2*u)))*sin(u); \
z: x*x - y*y + 2*x*y*tan(v)^(2);  \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriplePointTwist = {
PSLDD_ID( TRIPLE_POINT_TWIST )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-2, 1.7f , -1.5f , 1.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriplePointTwist =
"name: Triple point Twist; \
ut:c; \
vt:c; \
us: -2; \
ue: 1.7; \
vs: -1.5; \
ve: 1.5; \
c1:c: 1.5; \
x: u; \
y: v^(3) + c*v; \
z: u*v + v^(5) + c*v^(3); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrashcan = {
PSLDD_ID( TRASHCAN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrashcan =
"name: Trashcan; \
ut: c; \
vt: c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: (b + v)*cos(u); \
y: v*sin(u); \
z: a*v*v; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring1 = {
PSLDD_ID( SPRING1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4)|PASULI_CALC_U_END,//MUL_BY_CONST(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring1 =
"name: Spring 1; \
ut:c; \
vt:c; \
us: 0; \
ue:pi:c4: 2; \
vs: 0; \
ve:pi: 2; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:L: 1.0; \
c4:N: 1.0; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*(sin(v) + L*u/pi); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring2 = {
PSLDD_ID( SPRING2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
-1, 1 , 0 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring2 =
"name: Spring 2; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs: 0; \
ve:pi: 5; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:h: 1.0; \
a:1:w: sqrt(R*R + r*r); \
x: (R + r*cos(u))*cos(v) + r*h*sin(u)*sin(v)/w; \
y: (R + r*cos(u))*sin(v) - r*h*sin(u)*cos(v)/w; \
z: h*v + R*r*sin(u)/w; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCone = {
PSLDD_ID( CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
1, 3 , 0 , 2 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCone =
"name: Cone; \
ut:c; \
vt:c; \
us: 1; \
ue: 3; \
vs: 0; \
ve:pi: 2; \
c1:a: 1; \
x: u; \
y: a*u*sin(v); \
z: a*u*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddIsolator = {
PSLDD_ID( ISOLATOR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
1.5f, 9.5f , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descIsolator =
"name: Isolator; \
ut:c; \
vt:c; \
us: 1.5; \
ue:pi: 9.5; \
vs: 0; \
ve:pi: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: u; \
y: (a + b*sin(c*u*2*pi))*sin(v); \
z: (a + b*sin(c*u*2*pi))*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)		//TODO TODO
PaSuLiDefDesc pslddEgg = {
PSLDD_ID( EGG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(3)| \
PASULI_CALC_U_END,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEgg =
"name: Egg; \
ut: c; \
vt: c; \
us: 0; \
ue: c1: 1; \
vs: 0; \
ve:pi: 2; \
c1:a:<=c1: 0.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: c*sqrt(u*(u - a)*(u - b))*sin(v); \
y: u; \
z: c*sqrt(u*(u - a)*(u - b))*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicParaboloid = {
PSLDD_ID( HYPERBOLIC_PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicParaboloid =
"name: Hyperbolic Paraboloid; \
ut: c; \
vt: c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
x: u; \
y: v; \
z: u*v; \
xu: 1; \
yu: 0; \
zu: v; \
xv: 0; \
yv: 1; \
zv: u; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDropSurface = {
PSLDD_ID( DROP_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5, 0.5 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDropSurface =
"name: Drop Surface; \
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs: 0; \
ve:pi: 2; \
c1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: sin(u - a); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFacingSnail = {
PSLDD_ID( FACING_SNAIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f, 0.5f , 0 , 6 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFacingSnail =
"name: Facing Snail; \
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs: 0; \
ve:pi: 6; \
c1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: (1 - a*v)*sin(u); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPaperBag = {
PSLDD_ID( PAPER_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPaperBag =
"name: Paper Bag; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: v*cos(u); \
y: (v + b*u)*sin(u); \
z: a*v*v; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJeenerKleinSurface = {
PSLDD_ID( JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJeenerKleinSurface =
"name: Jeener Klein Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
c1:S: 1.5; \
c2:T: 0.5; \
c3:a: 1.0; \
a:1:W: ((S + 1)/4)*cos((S + 1)*u +pi/T) + sqrt(a); \
x: S*cos(u) + cos(S*u) - W*sin((S - 1)*u/2)*cos(v); \
y: W*sin(v); \
z: S*sin(u) - sin(S*u) - W*cos((S - 1)*u/2)*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBonanJeenerKleinSurface = {
PSLDD_ID( BONAN_JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBonanJeenerKleinSurface =
"name: Bonan Jeener Klein Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
c1:M: 1.5; \
c2:T: 0.5; \
a:1:W: sin((M - 1)*u) + T; \
x: M*cos(u) - cos(M*u) - ((M - 1)/M)*W*sin((M + 1)*u/2)*cos(v); \
y: W*sin(v); \
z: M*sin(u) - sin(M*u) + ((M - 1)/M)*W*cos((M + 1)*u/2)*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinCycloid = {			//TODO TODO
PSLDD_ID( KLEIN_CYCLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKleinCycloid =
"name: Klein Cycloid; \
ut: c; \
vt: c; \
us: 0; \
ue:pi:c2:c3: 2; \
vs: 0; \
ve:pi: 4; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: cos(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
y: sin(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
z: -sin(u/b)*(a + cos(v)) + cos(u/b)*sin(v)*cos(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDoubleCone = {
PSLDD_ID( DOUBLE_CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDoubleCone =
"name: Double Cone; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: -1; \
ve: 1; \
x: v*cos(u); \
y: (v - 1)*cos(u + 2*pi/3); \
z: (1 - v)*cos(u - 2*pi/3); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDisc = {
PSLDD_ID( HOLE_DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 3 , 4.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDisc =
"name: Hole Disc; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 3; \
ve: 4.5; \
x: sin(u)/(sqrt(2) + sin(v)); \
y: cos(u)/(sqrt(2) + sin(v)); \
z: cos(u)/(1 + sqrt(2)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPisotTriaxial = {
PSLDD_ID( PISOT_TRIAXIAL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPisotTriaxial =
"name:pisot Triaxial; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
x: 0.655866*cos(1.03002 + u)*(2 + cos(v)); \
y: 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v)); \
z: 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialHexatorus = {
PSLDD_ID( TRIAXIAL_HEXATORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 ,0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialHexatorus =
"name: Triaxial Hexatorus; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
x: sin(u)/(sqrt(2) + cos(v)); \
y: sin(u + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3)); \
z: cos(u - 2*pi/3)/(sqrt(2) + cos(v - 2*pi/3)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedHeart = {
PSLDD_ID( TWISTED_HEART )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
0, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedHeart =
"name: Twisted Heart; \
ut: c; \
vt: c; \
us: 0; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
a:1:m: 1/sqrt(2); \
x: (|v| - |u| - |tanh(m*u)/m| + |tanh(m*v)/m|)*sin(v); \
y: (|v| + |u| - |(tanh(m*u)/m| - |tanh(m*v)/m|)*cos(v); \
z: m*(u*u + v*v)/(cosh(m*u)*cosh(m*v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDiscus = {
PSLDD_ID( HOLE_DISCUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDiscus =
"name: Hole Discus; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: sin(u)/(a + sin(v)); \
y: cos(v)/b; \
z: cos(u)/(a + sin(v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDisc = {
PSLDD_ID( DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDisc =
"name: Disc; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 1; \
x: v*sin(u); \
y: 0; \
z: v*sin(u); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWaves = {
PSLDD_ID( WAVES )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-2, 2 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWaves =
"name: Waves; \
ut:c; \
vt:c; \
us:pi: -2; \
ue:pi: 2; \
vs:pi: -2; \
ve:pi: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: u; \
y: v; \
z: a*cos(b*u)*cos(c*v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineWave = {
PSLDD_ID( SINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineWave =
"name: Sine Wave; \
ut:c; \
vt:c; \
us: -5; \
ue: 5; \
vs: -5; \
ve: 5; \
c1:a: 1.5; \
c2:b: 0.5; \
x: u; \
y: v; \
z: a*sin(b*sqrt(u*u + v*v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineWave = {
PSLDD_ID( COSINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5, 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineWave =
"name: Cosine Wave; \
ut:c; \
vt:c; \
us: -5; \
ue: 5; \
vs: -5; \
ve: 5; \
c1:a: 1.5; \
c2:b: 0.5; \
x: u; \
y: v; \
z: a*cos(b*sqrt(u*u + v*v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpiralWave = {
PSLDD_ID( SPIRAL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(3),
0, 2 , 0 , 20 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpiralWave =
"name: Spiral Wave; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 20; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: v*cos(u); \
y: a*cos(b*u + c*v); \
z: v*sin(u); \
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
xvv: 0 \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBell = {
PSLDD_ID( BELL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBell =
"name: Bell; \
ut:c; \
vt:c; \
us: -5; \
ue: 5; \
vs: -5; \
ve: 5; \
c1:a: 1.5; \
c2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: b*exp(-(a*r)^(2)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellPolar = {
PSLDD_ID( BELL_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellPolar =
"name: Bell Polar; \
ut: c; \
vt: c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 12; \
c1:a: 1.5; \
c2:b: 0.5; \
a:1:r: sqrt(2*v*v) = sqrt(x*x + y*y); \
x: v*cos(u); \
y: v*sin(u); \
z: b*exp(-(a*r)^(2)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellWave = {
PSLDD_ID( BELL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellWave =
"name: Bell Wave; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 12; \
c1:a: 1.5; \
c2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: cos(c*r)*b*exp(-(a*r)^(2)); \
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
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs: 0; \
ve:pi: 1; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurfacePolar = {
PSLDD_ID( ENNEPER_SURFACE_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 2.5f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurfacePolar =
"name: Enneper Surface Polar; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve: 2.5; \
a:1:s: v*cos(u); \
a:2:t: v*sin(u); \
x: s - s^(3)/3 + s*t*t; \
y: t - t^(3)/3 + t*s*s; \
z: s*s - t*t; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineCone = {
PSLDD_ID( 0 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
-10, 10 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineCone =
"name: Sine Cone; \
ut:c; \
vt:c; \
us: -10; \
ue: 10; \
vs:pi: -1; \
ve:pi: 1; \
c1:k: 1.5; \
c2:N: 0.5; \
x: u*cos(v); \
y: k*u*cos(N*v); \
z: u*sin(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpinner = {
PSLDD_ID( SPINNER )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpinner =
"name: Spinner; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: 0; \
ve:pi: 2; \
c1:R: 1.5; \
c2:r: 0.5; \
x: (|u|-1)^(2)*cos(v); \
y: u; \
z: (|u|-1)^(2)*sin(v); \
xu: 0; \
yu: 1; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFresnel = {
PSLDD_ID( FRESNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-1, 1 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFresnel =
"name: Fresnel; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -0.5; \
ve:pi: 0.5; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
a:1:d: (sin(v)^(2)+c*c*cos(v)^(2)*(cos(u)^(2)/a*a + sin(u)^(2)/b*b)); \
x: (c*c/a)*(cos(u)^(2))/d; \
y: (c*c/b)*(sin(u)*cos(v))/d; \
z: c*(sin(v))/d; \
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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots2 = {
PSLDD_ID( TREFOIL_KNOTS2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0, 4 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots2 =
"name: Trefoil Knots 2; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 4; \
vs: 0; \
ve:pi: 2; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:a: 1.0; \
c4:N: 1.0; \
x: r*cos(v)*cos(u) + R*cos(u)*(1 + a*cos(N*u)); \
y: r*sin(v) + a*sin(N*u); \
z: r*cos(v)*sin(u) + R*sin(u)*(1 + a*cos(N*u)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBowCurve = {
PSLDD_ID( BOW_CURVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBowCurve =
"name: Bow Curve; \
ut:c; \
vt:c; \
us: 0; \
ue: 1; \
vs: 0; \
ve: 1; \
c1:T: 1.5; \
x: (2 + T*sin(2*pi*u))*sin(4*pi*v); \
y: (2 + T*sin(2*pi*u))*cos(4*pi*v); \
z: T*cos(2*pi*u) + 3*cos(2*pi*v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew1 = {
PSLDD_ID( TRIPLE_CORK_SCREW1 )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew1 =
"name: Triple Cork Screw 1; \
ut: c; \
vt: c; \
us: -1; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:L: 1.0; \
c4:N: 1.0; \
x: L*u; \
y: r*(1 - |u|)*cos(v) + R*(1 - |u|)*cos(u*N*pi); \
z: r*(1 - |u|)*sin(v) + R*(1 - |u|)*sin(u*N*pi); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew2 = {
PSLDD_ID( TRIPLE_CORK_SCREW2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(6),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew2 =
"name: Triple Cork Screw 2; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:L: 1.0; \
c4:N: 1.0; \
c5:a: 1.0; \
c:6:b: 1.0; \
a:1:c: r*exp(-(b*b*u*u)); \
a:2:d: R*exp(-(a*a*u*u)); \
x: L*u; \
y: c*cos(v) + d*cos(u*N*pi); \
z: c*sin(v) + d*sin(u*N*pi); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew3 = {
PSLDD_ID( TRIPLE_CORK_SCREW3 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew3 =
"name: Triple Cork Screw 3; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:L: 1.0; \
c4:N: 1.0; \
a:1:a: r*(1 - |u|); \
a:2:b: R*cos(u*pi/2); \
x: L*u; \
y: a*cos(v) + b*cos(u*N*pi); \
z: a*sin(v) + b*sin(u*N*pi); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBicornSurface = {
PSLDD_ID( BICORN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBicornSurface =
"name: Bicorn Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 1; \
x: sin(v)*cos(u); \
y: sin(v)*sin(u); \
z: cos(v)*cos(v)*(2 + cos(v))/(3 + sin(v)*sin(v)); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPiriformSurface = {
PSLDD_ID( PIRIFORM_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0, 2 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPiriformSurface =
"name:piriform Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs:pi: -0.5; \
ve:pi: 0.5; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:r: 1.0; \
a:1:c: (r + sin(v)); \
a:2:d: b*(cos(v)*c; \
x: d*cos(u); \
y: d*sin(u); \
z: a*c; \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKappaSurface = {
PSLDD_ID( KAPPA_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
0, 2 , 0.25f , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKappaSurface =
"name: Kappa Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0.25; \
ve:pi: 0.5; \
c1:a: 1.5; \
a:1:r: a*cos(v); \
x: r*cos(u); \
y: r*sin(u); \
z: -r/tan(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBulletNose = {
PSLDD_ID( BULLET_NOSE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0.25f , 0.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBulletNose =
"name: Bullet Nose; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 2; \
vs: 0.25; \
ve:pi: 0.5; \
c1:a: 1.5; \
c2:b: 0.5; \
a:1:c: a*cos(v); \
x: c*cos(u); \
y: c*sin(u); \
z: -b/tan(v); \
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


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSievertSurface = {
PSLDD_ID( SIEVERT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f , 0.5f , 0.1f , 3 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSievertSurface =
"name: Sievert Surface; \
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs: 0.1; \
ve:pi: 3; \
c1:C: 1.5; \
a:1:p: -u/sqrt(C + 1) + atan(tan(u)*sqrt(C + 1)); \
a:2:a: 2/(C + 1 - C*sin(v)*sin(v)*cos(u)*cos(u)); \
a:3:r: a*sqrt((C + 1)*(1 + C*sin(u)*sin(u)))*sin(v)/sqrt(C); \
x: r*cos(p); \
y: r*sin(p); \
z: (ln(tan(v/2)) + a*(C + 1)*cos(v))/sqrt(C); \
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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface2 = {
PSLDD_ID( COSINE_SURFACE2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface2 =
"name: Cosine Surface 2; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
x: cos(u); \
y: cos(v); \
z: -cos(u + v)^(2); \
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

