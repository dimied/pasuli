#ifndef __PARAMETRIC_SURFACE_LIBRARY_2008_
#define __PARAMETRIC_SURFACE_LIBRARY_2008_

#include "../pasuli_defs.h"
#include "../pasuli_const.h"
#include <math.h>

#include "plane.h"
#include "bohemian_dome_surface.h"
#include "boys_surface.h"
#include "cross_cup.h"
#include "dini_surface.h"
#include "enneper_surface.h"
#include "handkerchief.h"
#include "klein_bottle_surface.h"
#include "moebius_band.h"
#include "monkey_saddle.h"
#include "pluecker_conoid.h"
#include "roman_surface.h"
#include "shoe_surface.h"
#include "sine_surface.h"
#include "steinbach_screw.h"
#include "whitney_umbrella.h"
#include "catenoid.h"
#include "helicoid.h"
#include "paraboloid.h"


#ifndef __PASULI_DINI_SURFACE__
#define __PASULI_DINI_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"
#if (USE_ENNEPER_SURFACE != 0)
#endif

#endif

#if(COMPILE_SURFACES != 0)

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

#if(COMPILE_DESC_SURFACES != 0)
extern char *descBohemianDomeSurface;
extern char *descBoysSurface;			// ?!?
extern char *descCrossCup;
extern char *descDiniSurface;
extern char *descEnneperSurface;
extern char *descHandkerchief;
extern char *descKleinBottleSurface;	//?!?
extern char *descMoebiusBand;
extern char *descMonkeySaddle;
extern char *descPlueckerConoid;
extern char *descRomanSurface;
extern char *descShoeSurface;
extern char *descSineSurface;
extern char *descSteinbachScrew;
extern char *descWhitneyUmbrella;
extern char *descCatenoid;
extern char *descHelicoid;
extern char *descParaboloid;
extern char *descHyperbolicHelicoid;
extern char *descFunnel;
extern char *descTractroid;
extern char *descCatalansSurface;
extern char *descHyperboloid;
extern char *descHennebergsSurface;
extern char *descSwallowSurface;
extern char *descWallisConicalSurface;
extern char *descMaedersOwl;
extern char *descRichmondSurface;
extern char *descScherkSurface;
extern char *descCosineSurface;
extern char *descEightSurface;
extern char *descJetSurface;
extern char *descDrop;
extern char *descTriaxialTeardrop;
extern char *descPillowShape;
extern char *descFishSurface;
extern char *descHorn;
extern char *descBentHorns;
extern char *descHyperbolicOctahedron;
extern char *descPseudoCrossCap;
extern char *descCresent;
extern char *descStilettoSurface;
extern char *descKuensSurface;
extern char *descTrefoilKnots;
extern char *descTranguloidTrefoil;
extern char *descCrown;
extern char *descTwistedPipeSurface;
extern char *descLoop;
extern char *descDupinCyclide;
extern char *descGuimardSurface;
extern char *descMennsSurface;
extern char *descMilkBag;
extern char *descTriaxialTritorus;
extern char *descVerrillSurface;
extern char *descZindlersConoid;
extern char *descFolium;
extern char *descLemniscape;
extern char *descTriplePointTwist;
extern char *descTrashcan;
extern char *descSpring1;
extern char *descSpring2;
extern char *descCone;
extern char *descEgg;
extern char *descIsolator;
extern char *descHyperbolicParaboloid;
extern char *descDropSurface;
extern char *descFacingSnail;
extern char *descPaperBag;
extern char *descJeenerKleinSurface;
extern char *descBonanJeenerKleinSurface;
extern char *descKleinCycloid;
extern char *descDoubleCone;
extern char *descHoleDisc;
extern char *descPisotTriaxial;
extern char *descTriaxialHexatorus;
extern char *descTwistedHeart;
extern char *descHoleDiscus;
extern char *descDisc;
extern char *descWaves;
extern char *descSineWave;
extern char *descCosineWave;
extern char *descSpiralWave;
extern char *descBell;
extern char *descBellPolar;
extern char *descBellWave;
extern char *descSoucoupoid;
extern char *descEnneperSurfacePolar;
extern char *descSineCone;
extern char *descSpinner;
extern char *descFresnel;
extern char *descTrefoilKnots2;
extern char *descBowCurve;
extern char *descTripleCorkScrew1;
extern char *descTripleCorkScrew2;
extern char *descTripleCorkScrew3;
extern char *descBicornSurface;
extern char *descPiriformSurface;
extern char *descKappaSurface;
extern char *descBulletNose;
extern char *descSievertSurface;
extern char *descCosineSurface2;
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
extern PaSuLiDefDesc pslddBohemianDomeSurface;
extern PaSuLiDefDesc pslddBoysSurface;			// ?!?
extern PaSuLiDefDesc pslddCrossCup;
extern PaSuLiDefDesc pslddDiniSurface;
extern PaSuLiDefDesc pslddEnneperSurface;
extern PaSuLiDefDesc pslddHandkerchief;
extern PaSuLiDefDesc pslddKleinBottleSurface;	//?!?
extern PaSuLiDefDesc pslddMoebiusBand;
extern PaSuLiDefDesc pslddMonkeySaddle;
extern PaSuLiDefDesc pslddPlueckerConoid;
extern PaSuLiDefDesc pslddRomanSurface;
extern PaSuLiDefDesc pslddShoeSurface;
extern PaSuLiDefDesc pslddSineSurface;
extern PaSuLiDefDesc pslddSteinbachScrew;
extern PaSuLiDefDesc pslddWhitneyUmbrella;
extern PaSuLiDefDesc pslddCatenoid;
extern PaSuLiDefDesc pslddHelicoid;
extern PaSuLiDefDesc pslddParaboloid;
extern PaSuLiDefDesc pslddHyperbolicHelicoid;
extern PaSuLiDefDesc pslddFunnel;
extern PaSuLiDefDesc pslddTractroid;
extern PaSuLiDefDesc pslddCatalansSurface;
extern PaSuLiDefDesc pslddHyperboloid;
extern PaSuLiDefDesc pslddHennebergsSurface;
extern PaSuLiDefDesc pslddSwallowSurface;
extern PaSuLiDefDesc pslddWallisConicalSurface;
extern PaSuLiDefDesc pslddMaedersOwl;
extern PaSuLiDefDesc pslddRichmondSurface;
extern PaSuLiDefDesc pslddScherkSurface;
extern PaSuLiDefDesc pslddCosineSurface;
extern PaSuLiDefDesc pslddEightSurface;
extern PaSuLiDefDesc pslddJetSurface;
extern PaSuLiDefDesc pslddDrop;
extern PaSuLiDefDesc pslddTriaxialTeardrop;
extern PaSuLiDefDesc pslddPillowShape;
extern PaSuLiDefDesc pslddFishSurface;
extern PaSuLiDefDesc pslddHorn;
extern PaSuLiDefDesc pslddBentHorns;
extern PaSuLiDefDesc pslddHyperbolicOctahedron;
extern PaSuLiDefDesc pslddPseudoCrossCap;
extern PaSuLiDefDesc pslddCresent;
extern PaSuLiDefDesc pslddStilettoSurface;
extern PaSuLiDefDesc pslddKuensSurface;
extern PaSuLiDefDesc pslddTrefoilKnots;
extern PaSuLiDefDesc pslddTranguloidTrefoil;
extern PaSuLiDefDesc pslddCrown;
extern PaSuLiDefDesc pslddTwistedPipeSurface;
extern PaSuLiDefDesc pslddLoop;
extern PaSuLiDefDesc pslddDupinCyclide;
extern PaSuLiDefDesc pslddGuimardSurface;
extern PaSuLiDefDesc pslddMennsSurface;
extern PaSuLiDefDesc pslddMilkBag;
extern PaSuLiDefDesc pslddTriaxialTritorus;
extern PaSuLiDefDesc pslddVerrillSurface;
extern PaSuLiDefDesc pslddZindlersConoid;
extern PaSuLiDefDesc pslddFolium;
extern PaSuLiDefDesc pslddLemniscape;
extern PaSuLiDefDesc pslddTriplePointTwist;
extern PaSuLiDefDesc pslddTrashcan;
extern PaSuLiDefDesc pslddSpring1;
extern PaSuLiDefDesc pslddSpring2;
extern PaSuLiDefDesc pslddCone;
extern PaSuLiDefDesc pslddEgg;
extern PaSuLiDefDesc pslddIsolator;
extern PaSuLiDefDesc pslddHyperbolicParaboloid;
extern PaSuLiDefDesc pslddDropSurface;
extern PaSuLiDefDesc pslddFacingSnail;
extern PaSuLiDefDesc pslddPaperBag;
extern PaSuLiDefDesc pslddJeenerKleinSurface;
extern PaSuLiDefDesc pslddBonanJeenerKleinSurface;
extern PaSuLiDefDesc pslddKleinCycloid;
extern PaSuLiDefDesc pslddDoubleCone;
extern PaSuLiDefDesc pslddHoleDisc;
extern PaSuLiDefDesc pslddPisotTriaxial;
extern PaSuLiDefDesc pslddTriaxialHexatorus;
extern PaSuLiDefDesc pslddTwistedHeart;
extern PaSuLiDefDesc pslddHoleDiscus;
extern PaSuLiDefDesc pslddDisc;
extern PaSuLiDefDesc pslddWaves;
extern PaSuLiDefDesc pslddSineWave;
extern PaSuLiDefDesc pslddCosineWave;
extern PaSuLiDefDesc pslddSpiralWave;
extern PaSuLiDefDesc pslddBell;
extern PaSuLiDefDesc pslddBellPolar;
extern PaSuLiDefDesc pslddBellWave;
extern PaSuLiDefDesc pslddSoucoupoid;
extern PaSuLiDefDesc pslddEnneperSurfacePolar;
extern PaSuLiDefDesc pslddSineCone;
extern PaSuLiDefDesc pslddSpinner;
extern PaSuLiDefDesc pslddFresnel;
extern PaSuLiDefDesc pslddTrefoilKnots2;
extern PaSuLiDefDesc pslddBowCurve;
extern PaSuLiDefDesc pslddTripleCorkScrew1;
extern PaSuLiDefDesc pslddTripleCorkScrew2;
extern PaSuLiDefDesc pslddTripleCorkScrew3;
extern PaSuLiDefDesc pslddBicornSurface;
extern PaSuLiDefDesc pslddPiriformSurface;
extern PaSuLiDefDesc pslddKappaSurface;
extern PaSuLiDefDesc pslddBulletNose;
extern PaSuLiDefDesc pslddSievertSurface;
extern PaSuLiDefDesc pslddCosineSurface2;
#endif

#endif
