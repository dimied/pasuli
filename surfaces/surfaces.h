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
#include "hyperbolic_helicoid.h"
#include "funnel.h"
#include "tractroid.h"
#include "catalans_surface.h"
#include "hyperboloid.h"
#include "hennebergs_surface.h"
#include "swallow_surface.h"
#include "wallis_conical_surface.h"
#include "maeders_owl.h"
#include "richmond_surface.h"
#include "scherk_surface.h"
#include "cosine_surface.h"
#include "eight_surface.h"
#include "jet_surface.h"
#include "drop.h"

#ifndef __PASULI_TRIAXIAL_TEARDROP__
#define __PASULI_TRIAXIAL_TEARDROP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_TEARDROP != 0)
void TriaxialTeardrop(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PILLOW_SHAPE__
#define __PASULI_PILLOW_SHAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PILLOW_SHAPE != 0)
void PillowShape(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_FISH_SURFACE__
#define __PASULI_FISH_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FISH_SURFACE != 0)
void FishSurface(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HORN__
#define __PASULI_HORN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HORN != 0)
void Horn(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BENT_HORNS__
#define __PASULI_BENT_HORNS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BENT_HORNS != 0)
void BentHorns(double u, double v,
			   double *constants,
			   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HYPERBOLIC_OCTAHEDRON__
#define __PASULI_HYPERBOLIC_OCTAHEDRON__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(double u, double v,
						  double *constants,
						  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PSEUDO_CROSS_CAP__
#define __PASULI_PSEUDO_CROSS_CAP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDO_CROSS_CAP != 0)
void PseudoCrossCap(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CRESENT__
#define __PASULI_CRESENT__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CRESENT != 0)
void Cresent(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_STILETTO_SURFACE__
#define __PASULI_STILETTO_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_STILETTO_SURFACE != 0)
void StilettoSurface(double u, double v,
					 double *constants,
					 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_KUENS_SURFACE__
#define __PASULI_KUENS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KUENS_SURFACE != 0)
void KuensSurface(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TREFOIL_KNOTS__
#define __PASULI_TREFOIL_KNOTS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS != 0)
void TrefoilKnots(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRANGULOID_TREFOIL__
#define __PASULI_TRANGULOID_TREFOIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRANGULOID_TREFOIL != 0)
void TranguloidTrefoil(double u, double v,
					   double *constants,
					   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CROWN__
#define __PASULI_CROWN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROWN != 0)
void Crown(double u, double v,
		   double *constants,
		   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TWISTED_PIPE_SURFACE__
#define __PASULI_TWISTED_PIPE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_PIPE_SURFACE != 0)
void TwistedPipeSurface(double u, double v,
						double *constants,
						PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_LOOP__
#define __PASULI_LOOP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LOOP != 0)
void Loop(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_DUPIN_CYCLIDE__
#define __PASULI_DUPIN_CYCLIDE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DUPIN_CYCLIDE != 0)
void DupinCyclide(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_GUIMARD_SURFACE__
#define __PASULI_GUIMARD_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GUIMARD_SURFACE != 0)
void GuimardSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_MENNS_SURFACE__
#define __PASULI_MENNS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MENNS_SURFACE != 0)
void MennsSurface(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_MILK_BAG__
#define __PASULI_MILK_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MILK_BAG != 0)
void MilkBag(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIAXIAL_TRITORUS__
#define __PASULI_TRIAXIAL_TRITORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_TRITORUS != 0)
void TriaxialTritorus(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_VERRILL_SURFACE__
#define __PASULI_VERRILL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_VERRILL_SURFACE != 0)
void VerrillSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_ZINDLERS_CONOID__
#define __PASULI_ZINDLERS_CONOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ZINDLERS_CONOID != 0)
void ZindlersConoid(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_FOLIUM__
#define __PASULI_FOLIUM__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FOLIUM != 0)
void Folium(double u, double v,
			double *constants,
			PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_LEMNISCAPE__
#define __PASULI_LEMNISCAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIPLE_POINT_TWIST__
#define __PASULI_TRIPLE_POINT_TWIST__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_POINT_TWIST != 0)
void TriplePointTwist(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRASHCAN__
#define __PASULI_TRASHCAN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRASHCAN != 0)
void Trashcan(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SPRING1__
#define __PASULI_SPRING1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPRING1 != 0)
void Spring1(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SPRING2__
#define __PASULI_SPRING2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPRING2 != 0)
void Spring2(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CONE__
#define __PASULI_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CONE != 0)
void Cone(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_EGG__
#define __PASULI_EGG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EGG != 0)
void Egg(double u, double v,
		 double *constants,
		 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_ISOLATOR__
#define __PASULI_ISOLATOR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ISOLATOR != 0)
void Isolator(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HYPERBOLIC_PARABOLOID__
#define __PASULI_HYPERBOLIC_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_PARABOLOID != 0)
void HyperbolicParaboloid(double u, double v,
						  double *constants,
						  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_DROP_SURFACE__
#define __PASULI_DROP_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DROP_SURFACE != 0)
void DropSurface(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_FACING_SNAIL__
#define __PASULI_FACING_SNAIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FACING_SNAIL != 0)
void FacingSnail(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PAPER_BAG__
#define __PASULI_PAPER_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PAPER_BAG != 0)
void PaperBag(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_JEENER_KLEIN_SURFACE__
#define __PASULI_JEENER_KLEIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_JEENER_KLEIN_SURFACE != 0)
void JeenerKleinSurface(double u, double v,
						double *constants,
						PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BONAN_JEENER_KLEIN_SURFACE__
#define __PASULI_BONAN_JEENER_KLEIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)
void BonanJeenerKleinSurface(double u, double v,
							 double *constants,
							 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_KLEIN_CYCLOID__
#define __PASULI_KLEIN_CYCLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KLEIN_CYCLOID != 0)
void KleinCycloid(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_DOUBLE_CONE__
#define __PASULI_DOUBLE_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DOUBLE_CONE != 0)
void DoubleCone(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HOLE_DISC__
#define __PASULI_HOLE_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISC != 0)
void HoleDisc(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PISOT_TRIAXIAL__
#define __PASULI_PISOT_TRIAXIAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PISOT_TRIAXIAL != 0)
void PisotTriaxial(double u, double v,
				   double *constants,
				   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIAXIAL_HEXATORUS__
#define __PASULI_TRIAXIAL_HEXATORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_HEXATORUS != 0)
void TriaxialHexatorus(double u, double v,
					   double *constants,
					   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TWISTED_HEART__
#define __PASULI_TWISTED_HEART__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_HEART != 0)
void TwistedHeart(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HOLE_DISCUS__
#define __PASULI_HOLE_DISCUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISCUS != 0)
void HoleDiscus(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_DISC__
#define __PASULI_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DISC != 0)
void Disc(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_WAVES__
#define __PASULI_WAVES__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVES != 0)
void Waves(double u, double v,
		   double *constants,
		   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SINE_WAVE__
#define __PASULI_SINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_WAVE != 0)
void SineWave(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_COSINE_WAVE__
#define __PASULI_COSINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_WAVE != 0)
void CosineWave(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SPIRAL_WAVE__
#define __PASULI_SPIRAL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPIRAL_WAVE != 0)
void SpiralWave(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BELL__
#define __PASULI_BELL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL != 0)
void Bell(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BELL_POLAR__
#define __PASULI_BELL_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_POLAR != 0)
void BellPolar(double u, double v,
			   double *constants,
			   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BELL_WAVE__
#define __PASULI_BELL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_WAVE != 0)
void BellWave(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SOUCOUPOID__
#define __PASULI_SOUCOUPOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SOUCOUPOID != 0)
void Soucoupoid(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_ENNEPER_SURFACE_POLAR__
#define __PASULI_ENNEPER_SURFACE_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ENNEPER_SURFACE_POLAR != 0)
void EnneperSurfacePolar(double u, double v,
						 double *constants,
						 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SINE_CONE__
#define __PASULI_SINE_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_CONE != 0)
void SineCone(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SPINNER__
#define __PASULI_SPINNER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPINNER != 0)
void Spinner(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_FRESNEL__
#define __PASULI_FRESNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FRESNEL != 0)
void Fresnel(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TREFOIL_KNOTS2__
#define __PASULI_TREFOIL_KNOTS2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS2 != 0)
void TrefoilKnots2(double u, double v,
				   double *constants,
				   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BOW_CURVE__
#define __PASULI_BOW_CURVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOW_CURVE != 0)
void BowCurve(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIPLE_CORK_SCREW1__
#define __PASULI_TRIPLE_CORK_SCREW1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW1 != 0)
void TripleCorkScrew1(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIPLE_CORK_SCREW2__
#define __PASULI_TRIPLE_CORK_SCREW2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW2 != 0)
void TripleCorkScrew2(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRIPLE_CORK_SCREW3__
#define __PASULI_TRIPLE_CORK_SCREW3__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW3 != 0)
void TripleCorkScrew3(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BICORN_SURFACE__
#define __PASULI_BICORN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BICORN_SURFACE != 0)
void BicornSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PIRIFORM_SURFACE__
#define __PASULI_PIRIFORM_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PIRIFORM_SURFACE != 0)
void PiriformSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_KAPPA_SURFACE__
#define __PASULI_KAPPA_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KAPPA_SURFACE != 0)
void KappaSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BULLET_NOSE__
#define __PASULI_BULLET_NOSE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BULLET_NOSE != 0)
void BulletNose(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SIEVERT_SURFACE__
#define __PASULI_SIEVERT_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SIEVERT_SURFACE != 0)
void SievertSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_COSINE_SURFACE2__
#define __PASULI_COSINE_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_SURFACE2 != 0)
void CosineSurface2(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif

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

extern PaSuLiDefDesc pslddBohemianDomeSurface;
extern PaSuLiDefDesc pslddBoysSurface; // ?!?
extern PaSuLiDefDesc pslddCrossCup;
extern PaSuLiDefDesc pslddDiniSurface;
extern PaSuLiDefDesc pslddEnneperSurface;
extern PaSuLiDefDesc pslddHandkerchief;
extern PaSuLiDefDesc pslddKleinBottleSurface; //?!?
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
