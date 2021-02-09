

#include "sf3d_examples.h"

#pragma warning(once: 4309)			//VC specific

#define RN(X,Y)					SF3D_RATIONAL(X,Y)
#define NRN(X,Y)				SF3D_NEG_RATIONAL(X,Y)
#define NN(X)					SF3D_NATURAL(X)
#define NN10(X)					SF3D_NATURAL10(X)
#define NWN(X)					SF3D_NEG_WHOLE(X)

SuperFormula3D_Desc* examplesPB[32] = {
&examplePB1, &examplePB2, &examplePB3, &examplePB4, &examplePB5,
&examplePB6, &examplePB7, &examplePB8, &examplePB9, &examplePB10,
&examplePB11, &examplePB12, &examplePB13, &examplePB14, &examplePB15,
&examplePB16, &examplePB17, &examplePB18, &examplePB19, &examplePB20,
&examplePB21, &examplePB22, &examplePB23, &examplePB24, 

&examplePBCube, &examplePBCone, &examplePBDiamond, 
&examplePBSphere, &examplePBPrism, &examplePBCylinder,
&examplePBHexagon, &examplePBPentagon };

void getSF3DExamplesConstants(unsigned int exampleNum, pasuli_consttype* pC) {

	sf3d_packtype *p = examplesPB[exampleNum%MAX_NUM_OF_SUPERFORMULA_3D_EXAMPLES]->constants;

	if( pC != 0) {
		for(int i = 0; i < 12; i++) {

			pC[i] = SF3D_EXTRACT_DOUBLE(p[i]);
		}
	}
	//return examplesPB[exampleNum%MAX_NUM_OF_SUPERFORMULA_3D_EXAMPLES]->constants;
}

//Following examples are from the webpage 
//of Paul Bourke in zig-zag order of two-column view
//a1, b1, a2, b2 are 1
//pic = C_0000
SuperFormula3D_Desc examplePB1 = {
{ NN(1) , NN(1) , NN(2) , RN(7,10), RN(3,10) , RN(1,5) ,
NN(1) , NN(1) , NN(3) , NN(100) , NN(100), NN(100) } };

//pic = C_0038
SuperFormula3D_Desc examplePB2 = {
{NN(1) , NN(1) , NN(7) , RN(1,5) , RN(17,10) , RN(17,10) ,
NN(1) , NN(1) , NN(7) , RN(1,5) , RN(17,10), RN(17,10) } };

//pic = C_0004
SuperFormula3D_Desc examplePB3 = {
{NN(1) , NN(1) , NN(2) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(4) , NN(1) , NN(1), NN(1) } };

//pic = C_0005
SuperFormula3D_Desc examplePB4 = {
{NN(1) , NN(1) , NN(6) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(3) , NN(1) , NN(1), NN(1) } };

//pic = C_0006
SuperFormula3D_Desc examplePB5 = {
{NN(1) , NN(1) , NN(3) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(6) , NN(1) , NN(1), NN(1) } };

//pic = C_0007
SuperFormula3D_Desc examplePB6 = {
{NN(1) , NN(1) , NN(1) , RN(3,10) , RN(3,10) , RN(3,10) ,
NN(1) , NN(1) , NN(0) , NN(1) , NN(1) , NN(1) } };

//pic = C_0026,  modified( i.e. discretized)
SuperFormula3D_Desc examplePB7 = {
{NN(1) , NN(1) , NN(6) , RN(1,4) , RN(12,25) , NRN(29,33) ,
NN(1) , NN(1) , NN(7) , NWN(77) , RN(1,2), NWN(57)} };

//pic = C_0009
SuperFormula3D_Desc examplePB8 = {
{NN(1) , NN(1) , NN(6) , NN10(300) , NN10(100) , NN10(100) ,
NN(1) , NN(1) , NN(6) , NN(250) , NN(100) , NN(100) } };

// pic = C_0010
SuperFormula3D_Desc examplePB9 = {
{NN(1) , NN(1) , NN(6) , NN10(6) , NN(55) , NN10(100) ,
NN(1) , NN(1) , NN(6) , NN10(25) , NN10(10), NN10(10) } };

//pic = C_0011
SuperFormula3D_Desc examplePB10 = {
{NN(1) , NN(1) , NN(8) , NN10(6) , NN10(10) , NN10(3) ,
NN(1) , NN(1) , NN(2) , NN10(1) , NN10(1), NN10(1) } };

//pic = C_0012
SuperFormula3D_Desc examplePB11 = {
{NN(1) , NN(1) , NN(3) , RN(1,2) , RN(17, 10) , RN(17,10) ,
NN(1) , NN(1) , NN(2) , NN(10) , NN(10), NN(10) } };

//pic = C_0013, beautiful star
SuperFormula3D_Desc examplePB12 = {
{NN(1) , NN(1) , NN(5) , RN(1,10) , RN(17,10) , RN(17,10) ,
NN(1) , NN(1) , NN(1) , RN(3,10) , RN(1,2), RN(1,2) } };

//pic = C_0014,  UFO
SuperFormula3D_Desc examplePB13 = {
{NN(1) , NN(1) , RN(2,10) , RN(1,10) , RN(17,10) , RN(17,10) ,
NN(1) , NN(1) , NN(2) , RN(1,2) , RN(2,10), RN(1,5) } };

//pic = C_0015
SuperFormula3D_Desc examplePB14 = {
{NN(1) , NN(1) , RN(26,10) , RN(1,10) , NN(1) , RN(10,4) ,
NN(1) , NN(1) , NN(3) , NN(3) , RN(1,5), NN(1) } };

//pic = C_0016
SuperFormula3D_Desc examplePB15 = {
{NN(1) , NN(1) , RN(57,10) , RN(1,2) , NN(1) , RN(10,4) ,
NN(1), NN(1) , NN(10) , NN(3) , RN(1,5), NN(1) } };

//pic = C_0017
SuperFormula3D_Desc examplePB16 = {
{NN(1) , NN(1) , NN(5) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(3) , NN(100) , NN(100), NN(100) } };

//pic = C_0018
SuperFormula3D_Desc examplePB17 = {
{NN(1) , NN(1) , NN(6) , RN(7,10) , NN(47) , NRN(4,5) ,
NN(1) , NN(1) , NN(7) , NWN(31) , NRN(1,5), NN(97) } };

//pic = C_0019
SuperFormula3D_Desc examplePB18 = {
{NN(1) , NN(1) , NN(4) , RN(38,100) , NN(51) , NRN(2,3) ,
NN(1) , NN(1) , NN(9) , NWN(74) , NRN(7,10), NWN(41) } };

//pic = C_0020
SuperFormula3D_Desc examplePB19 = {
{NN(1) , NN(1) , NN(2) , RN(99,100) , NN(98) , NRN(43,100) ,
NN(1) , NN(1) , NN(7) , NRN(81,10) , NRN(8,100), NN(93) } };

//pic = C_0021
SuperFormula3D_Desc examplePB20 = {
{NN(1) , NN(1) , NN(0) , RN(24,50) , RN(121,4) , RN(7,20) ,
NN(1) , NN(1) , NN(5) , RN(154,10) , NRN(9,20), NN(87) } };

//pic = C_0022
SuperFormula3D_Desc examplePB21 = {
{NN(1) , NN(1) , NN(2) , RN(11,25) , NN(13) , RN(13,20) ,
NN(1) , NN(1) , NN(1) , NWN(22) , RN(16,25) , RN(69,100) } };

//pic = C_0023
SuperFormula3D_Desc examplePB22 = {
{NN(1) , NN(1) , NN(0) , NRN(9,20) , NWN(97) , RN(3,25) ,
NN(1) , NN(1) , NN(1) , NN(77) , NRN(43,50), NWN(88) } };

//pic = C_0024
SuperFormula3D_Desc examplePB23 = {
{NN(1) , NN(1) , NN(6) , RN(17,100) , NN(32) , NRN(49,50) ,
NN(1) , NN(1) , NN(5) , NN(93) , NRN(1,3), NN(69)} };

//pic = C_0025
SuperFormula3D_Desc examplePB24 = {
{NN(1) , NN(1) , NN(6) , RN(77,100) , NN(52) , NRN(1,5) ,
NN(1) , NN(1) , NN(5) , RN(19,50) , RN(13,25), NWN(19) } };



// m values not integer
//classical objects
//cube
SuperFormula3D_Desc examplePBCube = {
{NN(1) , NN(1) , NN(4) , NN10(10) , NN10(10) , NN10(10) ,
NN(1) , NN(1) , NN(4) , NN10(10) , NN10(10), NN10(10) } };

//cone
SuperFormula3D_Desc examplePBCone = {
{NN(1) , NN(1) , NN(4) , NN(100) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(4) , NN(1) , NN(1), NN(1) } };

//diamond
SuperFormula3D_Desc examplePBDiamond = {
{NN(1) , NN(1) , NN(4) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(4) , NN(1) , NN(1) , NN(1) } };

//sphere
SuperFormula3D_Desc examplePBSphere = {
{NN(1) , NN(1) , NN(0) , NN(1) , NN(1) , NN(1) ,
NN(1) , NN(1) , NN(0) , NN(1) , NN(1) , NN(1) } };

//prism
SuperFormula3D_Desc examplePBPrism = {
{NN(1) , NN(1) , NN(3) , NN10(26) , NN10(50) , NN10(50) ,
NN(1) , NN(1) , NN(4) , NN10(20) , NN10(20), NN10(20) } };

//cylinder
SuperFormula3D_Desc examplePBCylinder = {
{RN(11,10) , RN(19,10) , NN(1) , NN(37) , NRN(6,25) , NN(19) ,
NN(1) , NN(1) , NN(4) , NN10(10) , NN10(10), NN10(10) } };

//hexagon
SuperFormula3D_Desc examplePBHexagon = {
{NN(1) , NN(1) , NN(6) , NN10(100) , NN10(40) , NN10(40) ,
NN(1) , NN(1) , NN(4) , NN10(30) , NN10(30), NN10(30) } };

//pentagon
SuperFormula3D_Desc examplePBPentagon = {
{NN(1) , NN(1) , NN(5) , NN10(100) , NN10(60) , NN10(60) ,
NN(1) , NN(1) , NN(4) , NN10(30) , NN10(30), NN10(30)} };

#undef NN
#undef RN


