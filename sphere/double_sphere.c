
#include "double_sphere.h"
#include "sphere_c_includes.h"

#if (USE_DOUBLE_CONE != 0)
void SomeSurface(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DOUBLE_CONE)

    pasuli_calctype two_pi_div_3 = (2 * MY_PI) / 3.0;
    pasuli_calctype cos_u = cos(u);

    pasuli_calctype cos_u_plus = cos(u + two_pi_div_3);
    pasuli_calctype cos_u_minus = cos(u - two_pi_div_3);

    P_X(v * cos_u);
    P_Y((v - 1) * cos_u_plus);
    P_Z((1 - v) * cos_u_minus);

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u_plus = sin(u + two_pi_div_3);
    pasuli_calctype sin_u_minus = sin(two_pi_div_3 - u);

    UD_X(-v * sin_u);
    UD_Y((1 - v) * sin_u_plus);
    UD_Z((1 - v) * sin_u_minus);

    VD_X(cos_u);
    VD_Y(cos_u_plus);
    VD_Z(-cos_u_minus);

    N_X((v - 1) * (cos_u_plus * sin_u_minus + cos_u_minus * sin_u_plus));
    N_Y(-(v * cos_u * sin_u_minus + v * cos_u_minus * sin_u + cos_u * sin_u_minus));
    N_Z(v * cos_u * sin_u_plus - v * cos_u_plus * sin_u - cos_u * sin_u_plus);

    UUD_X(-v * cos_u);
    UUD_Y((1 - v) * cos_u_plus);
    UUD_Z((v - 1) * cos_u_minus);

    UVD_X(-sin_u);
    UVD_Y(-sin_u_plus);
    UVD_Z(-sin_u_minus);

    VVD_ALL(0);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descParabolicHummingTop =
    "name: Parabolic Humming Top;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: -h; ve: h;\
c1:1:r: 1; c2:h: 1; c3:p: 1;\
x: (|v|-h)^2*cos(u)/(2*p);\
y: (|v|-h)^2*sin(u)/(2*p);\
z: v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRuledRotorCylindroid =
    "name: Ruled Rotor Cylindroid;\
ut:c; vt:o;\
us: 0; ue:pi: 2;\
vs: 0; ve: 2;\
c1:1:a: 1; c2:b: 1; c3:n: 1;\
x: (a+b*sin(n*u))*cos(u)-v*sin(u);\
y: (a+b*sin(n*u))*sin(u)+v*cos(u);\
z: b*cos(n*u);";
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

#if (COMPILE_DESC_SURFACES != 0)
char *descKissSurface =
    "name: Kiss Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v^2*sqrt((1-v)/2)*cos(u);\
y: v^2*sqtt((1-v)/2)*sin(u);\
z: v;";
#endif


// Schon vorhanden ???
#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop1 =
    "name: Spinning Top 1;\
ut:c; vt:o;\
us:-1; ue:pi:1;\
vs:0; ve:pi:2;\
x: (|u|-1)^2*cos(v);\
y: (|u|-1)^2*sin(v);\
z: u;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop2 =
    "name: Spinning Top 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: cos(2*u)*sin(u)*cos(v);\
y: cos(2*u)*sin(u)*sin(v);\
z: cos(2*u)*cos(u);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAgnesiCurl =
    "name: Agnesi Curl;\
ut:c; vt:o;\
us:0; ue:T;\
vs:0; ve:pi:2;\
c1:T: 1; c2:L: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: L*sqrt((T-u)/(T+u));";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHectorGuinardsSurface =
    "name: Hector Guinards Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: ((1-u)*a+u*b)*cos(v);\
y: b*u*sin(v);\
z: c*u*sin(v)^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossedTroughSurface =
    "name: Crossed Trough Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:c: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: c*u^4*sin(2*v)^2/4;";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descMorinSurface =
    "name: Morin Surface;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
c1:k: 1; c2:n: 1;\
a1:K: cos(u)/(sqrt(2)-k*sin(2*u)*sin(n*v));\
x: K*((2/(n-1))*cos(u)*cos((n-1)*v)+sqrt(2)*sin(u)*cos(v));\
y: K*((2/(n-1))*cos(u)*sin((n-1)*v)-sqrt(2)*sin(u)*sin(v));\
z: K*cos(u);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEpitrochoidalSurface =
    "name: Epitrochoidal Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:pi:-0.5; ve:pi:0.5;\
c1:a: 1; c2:m: 1;\
a1:R: a*(1+m*cos(u));\
x: 2*R*cos(v)^2*cos(u);\
y: 2*R*cos(v)^2*sin(u);\
z: R*sin(2*v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBallsCylindroid =
    "name: Balls Cylindroid;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:pi:2;\
c1:k: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: k*sin(v)*cos(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHornletSurface =
    "name: Hornlet Surface;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: (a+sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v);\
y: (a+sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v);\
z: cos(b*pi*u)*sin(b*pi*v)+h*v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBowtie =
    "name: Bowtie;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: sin(u)/(sqrt(2)+sin(v));\
y: sin(u)/(sqrt(2)+cos(v));\
z: cos(u)/(1+sqrt(2));";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descGoblet =
    "name: Goblet;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: cos(u)*cos(2*v);\
y: sin(u)*cos(2*v);\
z: -2*sin(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descLawsonBottle =
    "name: LawsonBottle;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
a1:w: (sin(u)*sin(v)+sin(u/2)*cos(v))/2;\
x: (sin(u)*sin(v)-sin(u/2)*cos(v))*sqrt(1/2)/(1+w);\
y: cos(u)*sin(v)/(1+w);\
z: cos(u/2)*cos(v)/(1+w);";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descToothSurface =
    "name: Tooth Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
a1:R: sqrt(1/((sin(u)^4+cos(u)^4)*cos(v)^4+sin(v)^4));\
x: R*cos(v)*cos(u);\
y: R*cos(v)*sin(u);\
z: R*sin(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descDingDongSurface =
    "name: Ding Dong Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v*sqrt(1-v)*cos(u);\
y: v*sqrt(1-v)*sin(u);\
z: v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalBeaks =
    "name: Cuspidal Beaks;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.75; ve:0.75;\
x: u;\
y: 2*v^3-u^2*v;\
z: 3*v^4-u^2*v^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalEdge =
    "name: Cuspidal Edge;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v^2;\
z: v^3;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalLips =
    "name: Cuspidal Lips;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 2*v^3+u^2*v;\
z: 3*v^4+u^2*v^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalButterfly =
    "name: Cuspidal Butterfly;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 5*v^4+2*u*v;\
z: 4*v^5+u*v^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup2 =
    "name: Cross Cup 2;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
x: cos(u)*sin(2*v)/2;\
y: sin(u)*sin(2*v)/2;\
z: (cos(v)^2-cos(u)^2*sin(v)^2)/2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup3 =
    "name: Cross Cup 3;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
x: a*sin(u)*sin(2*v)/2;\
y: a*sin(2*u)*sin(v)^2;\
z: a*cos(2*u)*sin(v)^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPseudodevelopableHelicoid =
    "name: Pseudodevelopable Helicoid;\
ut:c; vt:o;\
us:-1.5; ue:0;\
vs:0; ve:pi:4;\
x: a*cos(v)-u*sin(v);\
y: a*sin(v)+u*cos(v);\
z: b*v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descVirichCyclicSurface =
    "name: Virich Cyclic Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
a1:f: a*b/sqrt(a^2*sin(v)^2+b^2*cos(v)^2);\
x: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*cos(v)/2;\
y: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*sin(v)/2;\
z: (f-(d^2-c^2)/f)*sin(u);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand3 =
    "name: Moebius Band 3;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0.7; ve:1;\
x: (3*v^2*(v^2-1)-6*v*(1+v^4)*cos(u)+(v^6-1)*(4*cos(u)^2-1))*sin(u)/(3*v^3);\
y: (4*(1-v^6)*cos(u)^3-3*v*(1+v^4)+3*(v^2-1)*(1+v^4)*cos(u)+6*v*(1+v^4)*cos(u)^2)/(3*v^3);\
z: 2*sin(u)*(v^2-1)/v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRomanSurface2 =
    "name: Roman Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-0.5; ve:pi:0.5;\
x: sin(2*u)*sin(v)^2/2;\
y: sin(u)*cos(2*v)/2;\
z: cos(u)*sin(2*v)/2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCayleySurface =
    "name: Cayley Surface;\
ut:c; vt:o;\
us:-1.5; ue:1;\
vs:-1.5; ve:1.5;\
x: u+v;\
y: (u^2+v^2)/2+a(v-u);\
z: (u^3+v^3)/3+a(v^2-u^2);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlanarEnneperSurface =
    "name: Planar Enneper Surface;\
ut:c; vt:o;\
us:-0.8; ue:0.5;\
vs:-1.5; ve:1.5;\
c1:n: 2; c1:A: 0.4;\
x: exp(2*a*u)*(exp(-(n+1)*u)*cos((2*a-(n+1))*v)/(2*a*A-A*(n+1)) - A*exp((n+1)*u)*cos((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
y: exp(2*a*u)*(exp(-(n+1)*u)*sin((2*a-(n+1))*v)/(2*a*A-A*(n+1)) + A*exp((n+1)*u)*sin((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
z: -exp(2*a*u)*cos(2*a*v)/(2*a*(n+1));";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descTwistedRibbon =
    "name: Twisted Ribbon;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: 3*sin(u)*cos(v);\
y: 3*sin(u)*sin(v);\
z: cos(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface3 =
    "name: Richmond Surface 3;\
ut:c; vt:o;\
us:0.5; ue:1;\
vs:0; ve:pi:2;\
c1:n:2;\
x: -cos(v)/(2*u)-(u^(2*n+1)*cos(-(2*n+1)*v))/(4*n+2);\
y: -sin(v)/(2*u)+(u^(2*n+1)*sin(-(2*n+1)*v))/(4*n+2);\
z: u^n*cos(n*v)/n;";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descWavyEnneperSurface =
    "name: Wavy Enneper Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
c1:s: 2;\
x: u*cos(v)-u^(2*s-1)*cos((2*s-1)*v)/(2*s-1);\
y: -u*sin(v)-u^(2*s-1)*sin((2*s-1)*v)/(2*s-1);\
z: 2/s*u^s*cos(s*v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface3 =
    "name: Enneper Surface 3;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: -u*(-6+u^2-3*v^2)/(6*sqrt(2));\
y: v*(-6+v^2-3*u^2)/(6*sqrt(2));\
z: (u^2-v^2)/2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface2 =
    "name: Enneper Surface 2;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: exp(u)*(3*cos(v)-exp(2*u)*cos(3*v))/6;\
y: exp(u)*(-3*sin(v)-exp(2*u)*sin(3*v))/6;\
z: exp(2*u)*cos(2*v)/2;";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface2 =
    "name: Richmond Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u^3/3-u*v^2+u/(u^2+v^2);\
y: v^3/3-v*u^2-v/(u^2+v^2);\
z: 2*u;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKaiWingFungSurface1 =
    "name: Kai-WingFung Surface 1;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:0; ve:pi:2;\
c1:n: 2;\
a1:a: sin(pi/n);\
a2:b: cos(pi/n);\
a3:C: cosh(u)+sinh(u);\
a4:D: sin(v)*cosh(u)*sinh(u);\
a5:E: cos(v)*cosh(u)*sinh(u);\
x: (-b*cos(v)*cosh(u)^2-b*E+a*sin(v)*cosh(u)^2+a*D-a*sin(v))/C;\
y: (-a*cos(v)*cosh(u)^2+a*E-a*cos(v)+b*sin(v)*cosh(u)^2+b*D)/C;\
z: b*u-a*v;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKaiWingFungSurface2 =
    "name: Kai-WingFung Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:6;\
vs:-1; ve:1;\
x: -u/2+sin(u)*(cosh(v)-sinh(v))/2;\
y: -v/2+cos(u)*(cosh(v)-sinh(v))/2;\
z: 2*(cosh(v/2)-sinh(v/2))*sin(u/2);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descFourIntersectingDiscs =
    "name: Four intersecting discs;\
ut:c; vt:o;\
us:0; ue:pi:4;\
vs:0; ve:pi:2;\
x: v*cos(u)-v^2*cos(2*u)/2;\
y: -v*sin(u)-v^2*sin(2*u)/2;\
z: 4*v^(3/2)*cos(3*u/2)/3;";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descKleinBottle2 =
    "name: Klein Bottle 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
a1:A: cos(u)*cos(v)*sin(u);\
a2:B: 48*cos(u)^4*cos(v)+48*cos(u)^6*cos(v)-60*sin(u);\
a3:C: 80*cos(v)*sin(u)*(cos(u)^5+cos(u)^7);\
x: -2*cos(u)*(3*cos(v)-30*sin(u)+90*cos(u)^4*sin(u)-60*cos(u)^6*sin(u)+5*A)/15;\
y: -sin(u)*(3*cos(v)-3*cos(u)^2*cos(v)-B+5*A-5*cos(u)^3*cos(v)*sin(u)-C)/15;\
z: 2*(3+5*cos(u)*sin(u))*sin(v)/15;";
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descSnail2 =
    "name: Snail 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-2; ve:pi:2;\
c1:a: 1;\
x: a^v*sin(u)^2*sin(v);\
y: a^v*sin(u)^2*cos(v);\
z: a^v*sin(u)*cos(u);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere =
    "name: Wrinkle Sphere;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: sin(u)*sin(v)+0.05*cos(20*v);\
y: cos(u)*sin(v)+0.05*cos(20*u);\
z: cos(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere2 =
    "name: Wrinkle Sphere 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
c1:n: 20;\
x: sin(u)*sin(v)+cos(n*v)/n;\
y: cos(u)*sin(v)+cos(n*u)/n;\
z: cos(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface1 =
    "name: Catalan's Surface 1;\
ut:c; vt:o;\
us:pi:-2; ue:pi:2;\
vs:-1.4; ve:1.4;\
x: u-cosh(v)*sin(u);\
y: 1-cosh(v)*cos(u);\
z: -4*sin(u/2)*sinh(v/2);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCatalanSurface2 =
    "name: Catalan Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-5; ve:5;\
c1:a: 1;\
x: a*(2*v-(1+2*u^2)*sin(2*v));\
y: a*(1+2*u^2)*cos(2*v);\
z: 4*a*u*sin(v)*cos(v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descScherkSurface2 =
    "name: Scherk Surface 2;\
ut:c; vt:o;\
us:0; ue:0.75;\
vs:0; ve:pi:2;\
x: log*((1+u^2+2*u*cos(v))/(1+u^2-2*u*cos(v)));\
y: log*((1+u^2-2*u*cos(v))/(1+u^2+2*u*cos(v)));\
z: 2*arctan(2*u^2*sin(2*v)/(u^2-1));";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSkidanRuledSurface =
    "name: Skidan Ruled Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1; c2:h: 1; c3:n: 1;\
a1:b: h*|cos(n*v)|;\
x: (u*sin(a)+b*cos(a))*cos(v);\
y: (u*sin(a)+b*cos(a))*sin(v);\
z: u*cos(a)-b*sin(a);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBoySurface2 =
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

#if (COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle2 =
    "name: Monkey Saddle 2;\
ut:u; vt:c;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: a*u^3*sin(3*v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlueckersConoid2 =
    "name: Pluecker's Conoid 2;\
ut:u; vt:c;\
us:0; ue:2;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: sin(2*v);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descVaseHead =
    "name: Vase Head;\
ut:u; vt:c;\
us:0; ue:pi:2;\
vs:-2; ve:2;\
c1:a: 1; c2:b: 1;\
x: v*cos(b*v+u);\
y: v*sin(u);\
z: a*v^2;";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPeanoSurface =
    "name: Peano Surface;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v;\
z: (2*u^2-v)*(v-u^2);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
// Own invention
char *descPeanoSurface2 =
    "name: Peano Surface 2;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:d: 1;\
x: u;\
y: v;\
z: (2*a*u^2-b*v)*(c*v-d*u^2);";
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAstroidalEllipsoid =
    "name: Astroidal Ellipsoid;\
ut:c; vt:c;\
us:pi:-0.5; ue:pi:0.5;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: a*cos(u)^3*cos(v)^3;\
y: b*sin(u)^3*cos(v)^3;\
z: c*sin(v)^3;";
#endif
