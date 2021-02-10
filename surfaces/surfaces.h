#ifndef __PARAMETRIC_SURFACE_LIBRARY_2008_
#define __PARAMETRIC_SURFACE_LIBRARY_2008_

#include "../pasuli_defs.h"
#include "../pasuli_const.h"
#include "surfaces_desc.h"
#include <math.h>

void Plane(double u, double v, double* constants, PaSuLiObject* pParticles);

extern char *descPlane;

extern PaSuLiDefDesc pslddPlane;

void initConstPlane(PaSuLiObject* pO, pasuli_consttype* constants);


#if(COMPILE_SURFACES != 0)

void BohemianDomeSurface(double u, double v, 
						double* constants, PaSuLiObject* pO);

void BoysSurface(double u, double v, 
				double* constants, PaSuLiObject* pO);	// ?!?

void CrossCup(double u, double v, double* constants, PaSuLiObject* pO);

void DiniSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void EnneperSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void Handkerchief(double u, double v, 
					double* constants, PaSuLiObject* pO);

void KleinBottleSurface(double u, double v, 
						double* constants, PaSuLiObject* pO);	//?!?

void MoebiusBand(double u, double v, 
					double* constants, PaSuLiObject* pO);

void MonkeySaddle(double u, double v, 
					double* constants, PaSuLiObject* pO);

void PlueckerConoid(double u, double v, 
					double* constants, PaSuLiObject* pO);

void RomanSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void ShoeSurface(double u, double v, 
				double* constants, PaSuLiObject* pO);

void SineSurface(double u, double v, 
				double* constants, PaSuLiObject* pO);

void SteinbachScrew(double u, double v, 
					double* constants, PaSuLiObject* pO);

void WhitneyUmbrella(double u, double v, 
					double* constants, PaSuLiObject* pO);

void Catenoid(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Helicoid(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Paraboloid(double u, double v, 
				double* constants, PaSuLiObject* pO);

void HyperbolicHelicoid(double u, double v, 
						double* constants, PaSuLiObject* pO);

void Funnel(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Tractroid(double u, double v, 
				double* constants, PaSuLiObject* pO);

void CatalansSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void Hyperboloid(double u, double v, 
				double* constants, PaSuLiObject* pO);

void HennebergsSurface(double u, double v, 
						double* constants, PaSuLiObject* pO);

void SwallowSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void WallisConicalSurface(double u, double v, 
							double* constants, PaSuLiObject* pO);

void MaedersOwl(double u, double v, 
				double* constants, PaSuLiObject* pO);

void RichmondSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void ScherkSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void CosineSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void EightSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void JetSurface(double u, double v, 
				double* constants, PaSuLiObject* pO);

void Drop(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TriaxialTeardrop(double u, double v, 
						double* constants, PaSuLiObject* pO);

void PillowShape(double u, double v, 
					double* constants, PaSuLiObject* pO);

void FishSurface(double u, double v, 
				 double* constants, PaSuLiObject* pO);

void Horn(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void BentHorns(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void HyperbolicOctahedron(double u, double v, 
							double* constants, PaSuLiObject* pO);

void PseudoCrossCap(double u, double v, 
					double* constants, PaSuLiObject* pO);

void Cresent(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void StilettoSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void KuensSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void TrefoilKnots(double u, double v, 
					double* constants, PaSuLiObject* pO);

void TranguloidTrefoil(double u, double v, 
						double* constants, PaSuLiObject* pO);

void Crown(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TwistedPipeSurface(double u, double v, 
						double* constants, PaSuLiObject* pO);

void Loop(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void DupinCyclide(double u, double v, 
					double* constants, PaSuLiObject* pO);

void GuimardSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void MennsSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void MilkBag(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TriaxialTritorus(double u, double v, 
						double* constants, PaSuLiObject* pO);

void VerrillSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void ZindlersConoid(double u, double v, 
					double* constants, PaSuLiObject* pO);

void Folium(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Lemniscape(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TriplePointTwist(double u, double v, 
						double* constants, PaSuLiObject* pO);

void Trashcan(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Spring1(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Spring2(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Cone(double u, double v, 
			double* constants, PaSuLiObject* pO);

void Egg(double u, double v, double* constants, PaSuLiObject* pO);

void Isolator(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void HyperbolicParaboloid(double u, double v, 
							double* constants, PaSuLiObject* pO);

void DropSurface(double u, double v, 
				double* constants, PaSuLiObject* pO);

void FacingSnail(double u, double v, 
				double* constants, PaSuLiObject* pO);

void PaperBag(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void JeenerKleinSurface(double u, double v, 
						double* constants, PaSuLiObject* pO);

void BonanJeenerKleinSurface(double u, double v, 
							double* constants, PaSuLiObject* pO);

void KleinCycloid(double u, double v, 
				double* constants, PaSuLiObject* pO);

void DoubleCone(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void HoleDisc(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void PisotTriaxial(double u, double v, 
					double* constants, PaSuLiObject* pO);

void TriaxialHexatorus(double u, double v, 
						double* constants, PaSuLiObject* pO);

void TwistedHeart(double u, double v, 
					double* constants, PaSuLiObject* pO);

void HoleDiscus(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Disc(double u, double v, 
			double* constants, PaSuLiObject* pO);

void Waves(double u, double v, double* constants, PaSuLiObject* pO);

void SineWave(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void CosineWave(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void SpiralWave(double u, double v, 
				double* constants, PaSuLiObject* pO);

void Bell(double u, double v, 
			double* constants, PaSuLiObject* pO);

void BellPolar(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void BellWave(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Soucoupoid(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void EnneperSurfacePolar(double u, double v, 
						double* constants, PaSuLiObject* pO);

void SineCone(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Spinner(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Fresnel(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TrefoilKnots2(double u, double v, 
				double* constants, PaSuLiObject* pO);

void BowCurve(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void TripleCorkScrew1(double u, double v, 
						double* constants, PaSuLiObject* pO);

void TripleCorkScrew2(double u, double v, 
						double* constants, PaSuLiObject* pO);

void TripleCorkScrew3(double u, double v, 
						double* constants, PaSuLiObject* pO);

void BicornSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void PiriformSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void KappaSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void BulletNose(double u, double v, 
				double* constants, PaSuLiObject* pO);

void SievertSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);

void CosineSurface2(double u, double v, 
					double* constants, PaSuLiObject* pO);

#endif

#endif

