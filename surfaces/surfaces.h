#ifndef __PARAMETRIC_SURFACE_LIBRARY_2008_
#define __PARAMETRIC_SURFACE_LIBRARY_2008_

//#include "../pasuli_defs.h"

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
#include "triaxial_teardrop.h"
#include "pillow_shape.h"
#include "fish_surface.h"
#include "horn.h"
#include "bent_horns.h"
#include "hyperbolic_octahedron.h"
#include "pseudo_cross_cap.h"
#include "cresent.h"
#include "stiletto_surface.h"
#include "kuens_surface.h"
#include "trefoil_knots.h"
#include "tranguloid_trefoil.h"
#include "crown.h"
#include "twisted_pipe_surface.h"
#include "loop.h"
#include "dupin_cyclide.h"
#include "guimard_surface.h"
#include "menns_surface.h"
#include "milk_bag.h"
#include "triaxial_tritorus.h"
#include "verrill_surface.h"
#include "zindlers_conoid.h"
#include "folium.h"
#include "lemniscape.h"
#include "triple_point_twist.h"
#include "trashcan.h"
#include "spring1.h"
#include "spring2.h"
#include "cone.h"
#include "egg.h"
#include "isolator.h"
#include "hyperbolic_paraboloid.h"
#include "facing_snail.h"
#include "paper_bag.h"
#include "jeener_klein_surface.h"
#include "bonan_jeener_klein_surface.h"
#include "drop_surface.h"
#include "klein_cycloid.h"
#include "double_cone.h"
#include "hole_disc.h"
#include "pisot_triaxial.h"
#include "triaxial_hexatorus.h"
#include "twisted_heart.h"
#include "hole_discus.h"
#include "disc.h"
#include "waves.h"
#include "sine_wave.h"
#include "cosine_wave.h"
#include "spiral_wave.h"
#include "bell.h"
#include "bell_polar.h"
#include "bell_wave.h"
#include "soucoupid.h"
#include "enneper_surface_polar.h"
#include "sine_cone.h"
#include "spinner.h"
#include "fresnel.h"
#include "trefoil_knots2.h"
#include "bow_curve.h"
#include "triple_cork_screw1.h"
#include "triple_cork_screw2.h"
#include "triple_cork_screw3.h"
#include "bicorn_surface.h"
#include "piriform_surface.h"
#include "kappa_surface.h"
#include "bullet_nose.h"
#include "sievert_surface.h"
#include "cosine_surface2.h"

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

/*
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

*/
#endif
