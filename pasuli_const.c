
#include "pasuli_const.h"


#define PASULI_PARSUR_STATIC	static
//#define PASULI_PARSUR_STATIC




//PASULI_PARSUR_STATIC
pasuli_name_type parsur_name_array[] = {
PASULI_SET_NAME( "Plane", PLANE )
#if(COMPILE_NAMES_SURFACES != 0)
,PASULI_SET_NAME("Bohemian Dome Surface", BOHEMIAN_DOME_SURFACE )
,PASULI_SET_NAME("Boys Surface", BOYS_SURFACE )
,PASULI_SET_NAME("Cross Cup", CROSS_CUP )
,PASULI_SET_NAME("Dini Surface", DINI_SURFACE )
,PASULI_SET_NAME("Enneper Surface", ENNEPER_SURFACE )
,PASULI_SET_NAME("Handkerchief", HANDKERCHIEF)
,PASULI_SET_NAME("Klein Bottle Surface", KLEIN_BOTTLE_SURFACE )
,PASULI_SET_NAME("Moebius Band", MOEBIUS_BAND )
,PASULI_SET_NAME("Monkey Saddle", MONKEY_SADDLE)

,PASULI_SET_NAME("Pluecker Conoid", PLUECKER_CONOID)
,PASULI_SET_NAME("Roman Surface", ROMAN_SURFACE )
,PASULI_SET_NAME("Shoe Surface", SHOE_SURFACE )
,PASULI_SET_NAME("Sine Surface", SINE_SURFACE )
,PASULI_SET_NAME("Steinbach Screw", STEINBACH_SCREW )
,PASULI_SET_NAME("Whitney Umbrella", WHITNEY_UMBRELLA )
,PASULI_SET_NAME("Catenoid", CATENOID )
,PASULI_SET_NAME("Helicoid", HELICOID )
,PASULI_SET_NAME("Paraboloid", PARABOLOID )
,PASULI_SET_NAME("Hyperbolic Helicoid", HYPERBOLIC_HELICOID )

,PASULI_SET_NAME("Funnel", FUNNEL )
,PASULI_SET_NAME("Tractroid", TRACTROID )
,PASULI_SET_NAME("Catalans Surface", CATALANS_SURFACE )
,PASULI_SET_NAME("Hyperboloid", HYPERBOLOID )
,PASULI_SET_NAME("Hennebergs Surface", HENNEBERGS_SURFACE )
,PASULI_SET_NAME("Swallow Surface", SWALLOW_SURFACE )
,PASULI_SET_NAME("Wallis Conical Surface", WALLIS_CONICAL_SURFACE )
,PASULI_SET_NAME("Maeders Owl", MAEDERS_OWL )
,PASULI_SET_NAME("Richmond Surface", RICHMOND_SURFACE )
,PASULI_SET_NAME("Scherk Surface", SCHERK_SURFACE )

,PASULI_SET_NAME("Cosine Surface", COSINE_SURFACE )
,PASULI_SET_NAME("Eight Surface", EIGHT_SURFACE )
,PASULI_SET_NAME("Jet Surface", JET_SURFACE )
,PASULI_SET_NAME("Drop", DROP )
,PASULI_SET_NAME("Triaxial Teardrop", TRIAXIAL_TEARDROP )
,PASULI_SET_NAME("Pillow Shape", PILLOW_SHAPE )
,PASULI_SET_NAME("Fish Surface", FISH_SURFACE )
,PASULI_SET_NAME("Horn", HORN )
,PASULI_SET_NAME("Bent Horns", BENT_HORNS )
,PASULI_SET_NAME("Hyperbolic Octahedron", HYPERBOLIC_OCTAHEDRON )

,PASULI_SET_NAME("Pseudo Cross Cap", PSEUDO_CROSS_CAP )
,PASULI_SET_NAME("Cresent", CRESENT )
,PASULI_SET_NAME("Stiletto Surface", STILETTO_SURFACE )
,PASULI_SET_NAME("Kuens Surface", KUENS_SURFACE )
,PASULI_SET_NAME("Trefoil Knots", TREFOIL_KNOTS )
,PASULI_SET_NAME("Tranguloid Trefoil", TRANGULOID_TREFOIL )
,PASULI_SET_NAME("Crown", CROWN )
,PASULI_SET_NAME("Twisted Pipe Surface", TWISTED_PIPE_SURFACE )
,PASULI_SET_NAME("Loop", LOOP )
,PASULI_SET_NAME("Dupin Cyclide", DUPIN_CYCLIDE )

,PASULI_SET_NAME("Guimard Surface", GUIMARD_SURFACE )
,PASULI_SET_NAME("Menns Surface", MENNS_SURFACE )
,PASULI_SET_NAME("MilkBag", MILK_BAG )
,PASULI_SET_NAME("Triaxial Tritorus", TRIAXIAL_TRITORUS )
,PASULI_SET_NAME("Verrill Surface", VERRILL_SURFACE )
,PASULI_SET_NAME("Zindlers Conoid", ZINDLERS_CONOID )
,PASULI_SET_NAME("Folium", FOLIUM )
,PASULI_SET_NAME("Lemniscape", LEMNISCAPE )
,PASULI_SET_NAME("Triple Point Twist", TRIPLE_POINT_TWIST )
,PASULI_SET_NAME("Trashcan", TRASHCAN )

,PASULI_SET_NAME("Spring1", SPRING1 )
,PASULI_SET_NAME("Spring2", SPRING2 )
,PASULI_SET_NAME("Cone", CONE )
,PASULI_SET_NAME("Egg", EGG )
,PASULI_SET_NAME("Isolator", ISOLATOR )
,PASULI_SET_NAME("Hyperbolic Paraboloid", HYPERBOLIC_PARABOLOID )
,PASULI_SET_NAME("Drop Surface", DROP_SURFACE )
,PASULI_SET_NAME("Facing Snail", FACING_SNAIL )
,PASULI_SET_NAME("Paper Bag", PAPER_BAG )
,PASULI_SET_NAME("Jeener Klein Surface", JEENER_KLEIN_SURFACE )

,PASULI_SET_NAME("Bonan Jeener Klein Surface", BONAN_JEENER_KLEIN_SURFACE )
,PASULI_SET_NAME("Klein Cycloid", KLEIN_CYCLOID )
,PASULI_SET_NAME("Double Cone", DOUBLE_CONE )
,PASULI_SET_NAME("Hole Disc", HOLE_DISC )
,PASULI_SET_NAME("Pisot Triaxial", PISOT_TRIAXIAL )
,PASULI_SET_NAME("Triaxial Hexatorus", TRIAXIAL_HEXATORUS )
,PASULI_SET_NAME("Twisted Heart", TWISTED_HEART )
,PASULI_SET_NAME("Hole Discus", HOLE_DISCUS )
,PASULI_SET_NAME("Disc", DISC )
,PASULI_SET_NAME("Waves", WAVES )

,PASULI_SET_NAME("Sine Wave", SINE_WAVE )
,PASULI_SET_NAME("Cosine Wave", COSINE_WAVE )
,PASULI_SET_NAME("Spiral Wave", SPIRAL_WAVE )
,PASULI_SET_NAME("Bell", BELL )
,PASULI_SET_NAME("Bell Polar", BELL_POLAR )
,PASULI_SET_NAME("Bell Wave", BELL_WAVE )
,PASULI_SET_NAME("Soucoupoid", SOUCOUPOID )
,PASULI_SET_NAME("Enneper Surface Polar", ENNEPER_SURFACE_POLAR )
,PASULI_SET_NAME("Spinner", SPINNER )
,PASULI_SET_NAME("Fresnel", FRESNEL )

,PASULI_SET_NAME("Trefoil Knots2", TREFOIL_KNOTS2 )
,PASULI_SET_NAME("Bow Curve", BOW_CURVE )
,PASULI_SET_NAME("Triple Cork Screw 1", TRIPLE_CORK_SCREW1 )
,PASULI_SET_NAME("Triple Cork Screw 2", TRIPLE_CORK_SCREW2 )
,PASULI_SET_NAME("Triple Cork Screw 3", TRIPLE_CORK_SCREW3 )
,PASULI_SET_NAME("Bicorn Surface", BICORN_SURFACE )
,PASULI_SET_NAME("Piriform Surface", PIRIFORM_SURFACE )
,PASULI_SET_NAME("Kappa Surface", KAPPA_SURFACE )
,PASULI_SET_NAME("Bullet Nose", BULLET_NOSE )
,PASULI_SET_NAME("Sievert Surface", SIEVERT_SURFACE )

,PASULI_SET_NAME("Cosine Surface2", COSINE_SURFACE2)
#endif
#if(COMPILE_NAMES_CYLINDER != 0)
,PASULI_SET_NAME("Cylinder", CYLINDER )
,PASULI_SET_NAME("Epizykloid Cylinder", EPIZYKLOID_CYLINDER )
,PASULI_SET_NAME("Hypozykloid Cylinder", HYPOZYKLOID_CYLINDER )
,PASULI_SET_NAME("Lemniskate Cylinder", LEMNISKATE_CYLINDER )
,PASULI_SET_NAME("Strophoide Cylinder", STROPHOIDE_CYLINDER )
,PASULI_SET_NAME("Zissoide Cylinder", ZISSOIDE_CYLINDER )
,PASULI_SET_NAME("Versiera Agnesi Cylinder", VERSIERA_AGNESI_CYLINDER )
,PASULI_SET_NAME("Gauss Cylinder", GAUSS_CYLINDER )
#endif
#if(COMPILE_NAMES_FRUITS != 0)
,PASULI_SET_NAME("Kidney Surface", KIDNEY_SURFACE )
,PASULI_SET_NAME("Apple Surface", APPLE_SURFACE )
,PASULI_SET_NAME("Apple Surface (2.nd Version)", APPLE2_SURFACE )
,PASULI_SET_NAME("Lemon Surface", LEMON_SURFACE )
#endif
#if(COMPILE_NAMES_SHELLS != 0)
,PASULI_SET_NAME("Cornucopia", CORNUCOPIA )
,PASULI_SET_NAME("Snail", SNAIL)
,PASULI_SET_NAME("Seashell", SEASHELL )
,PASULI_SET_NAME("Snail surface", SNAIL_SURFACE )
,PASULI_SET_NAME("Snails", SNAILS )
,PASULI_SET_NAME("Pseudoheliceras Subcatenatum", PSEUDOHELICERAS_SUBCATENATUM )
,PASULI_SET_NAME("Astroceras", ASTROCERAS)
,PASULI_SET_NAME("Bellerophina", BELLEROPHINA )
,PASULI_SET_NAME("Euhoplites", EUHOPLITES )
,PASULI_SET_NAME("Nautilus", NAUTILUS )
,PASULI_SET_NAME("Natica Stellata", NATICA_STELLATA )
,PASULI_SET_NAME("Mya Arenaria", MYA_ARENARIA )
#endif
#if(COMPILE_NAMES_SPHERE != 0)
,PASULI_SET_NAME("Sphere", SPHERE )
,PASULI_SET_NAME("Ellipsoid", ELLIPSOID )
,PASULI_SET_NAME("SphereV", SPHERE_V)
,PASULI_SET_NAME("SphereUV", SPHERE_UV )
,PASULI_SET_NAME("Pseudo-Sphere", PSEUDOSPHERE )
,PASULI_SET_NAME("Twisted Sphere", TWISTED_SPHERE )
,PASULI_SET_NAME("Open Sphere", OPEN_SPHERE )
,PASULI_SET_NAME("Wave Sphere", WAVE_SPHERE )
#endif
#if(COMPILE_NAMES_SPIRAL != 0)
,PASULI_SET_NAME("Archimedic Spiral", ARCHIMEDIC_SPIRAL )
,PASULI_SET_NAME("Hyperbolic Spiral", HYPERBOLIC_SPIRAL )
,PASULI_SET_NAME("Fermat Spiral", FERMAT_SPIRAL )
,PASULI_SET_NAME("Tanh Spiral", TANH_SPIRAL )
,PASULI_SET_NAME("Logarithmic Spiral", LOG_SPIRAL )
#endif
#if(COMPILE_NAMES_TORUS != 0)
,PASULI_SET_NAME("Torus", TORUS )
,PASULI_SET_NAME("Eight Torus", EIGHT_TORUS )
,PASULI_SET_NAME("Elliptic Torus", ELLIPTIC_TORUS )
,PASULI_SET_NAME("Saddle Torus", SADDLE_TORUS )
,PASULI_SET_NAME("Antisymmetric Torus", ANTISYMMETRIC_TORUS )
,PASULI_SET_NAME("Twisted Eight Torus", TWISTED_EIGHT_TORUS )
,PASULI_SET_NAME("Umbillic Torus", UMBILLIC_TORUS )
,PASULI_SET_NAME("Wave Torus", WAVE_TORUS )
,PASULI_SET_NAME("Braided Torus", BRAIDED_TORUS )
,PASULI_SET_NAME("Limpet Torus", LIMPET_TORUS )
,PASULI_SET_NAME("Strangled Torus", STRANGLED_TORUS )
,PASULI_SET_NAME("Astroid Torus", ASTROID_TORUS )
,PASULI_SET_NAME("Tricuspoid Torus 1", TRICUSPOID_TORUS_1 )
,PASULI_SET_NAME("Tricuspoid Torus 2", TRICUSPOID_TORUS_2 )
,PASULI_SET_NAME("Nethroid Torus 1", NETHROID_TORUS_1 )
,PASULI_SET_NAME("Nethroid Torus 2", NETHROID_TORUS_2 )
,PASULI_SET_NAME("Lemniskate Torus 1", LEMNISKATE_TORUS_1 )
,PASULI_SET_NAME("Lemniskate Torus 2", LEMNISKATE_TORUS_2 )
,PASULI_SET_NAME("Epizykloid Torus 1", EPIZYKLOID_TORUS_1 )
,PASULI_SET_NAME("Epizykloid Torus 2", EPIZYKLOID_TORUS_2 )
,PASULI_SET_NAME("Hypozykloid Torus 1", HYPOZYKLOID_TORUS_1 )
,PASULI_SET_NAME("Hypozykloid Torus 2", HYPOZYKLOID_TORUS_2 )
,PASULI_SET_NAME("Piriform Torus 1", PIRIFORM_TORUS_1 )
,PASULI_SET_NAME("Piriform Torus 2", PIRIFORM_TORUS_2 )
,PASULI_SET_NAME("Bicorn Torus 1", BICORN_TORUS_1 )
,PASULI_SET_NAME("Bicorn Torus 2", BICORN_TORUS_2 )
,PASULI_SET_NAME("Cardioid Torus 1", CARDIOID_TORUS_1 )
,PASULI_SET_NAME("Cardioid Torus 2", CARDIOID_TORUS_2 )
,PASULI_SET_NAME("Cassinian Oval Torus 1", CASSINIAN_OVAL_TORUS_1 )
,PASULI_SET_NAME("Cassinian Oval Torus 2", CASSINIAN_OVAL_TORUS_2 )
,PASULI_SET_NAME("Gerono-Lemniskate Torus 1", GERONO_LEMNISKATE_TORUS_1 )
,PASULI_SET_NAME("Gerono-Lemniskate Torus 2", GERONO_LEMNISKATE_TORUS_2 )
,PASULI_SET_NAME("Curly Torus 1", CURLY_TORUS_1 )
,PASULI_SET_NAME("Curly Torus 2", CURLY_TORUS_2 )
,PASULI_SET_NAME("Spiral Torus", SPIRAL_TORUS )
,PASULI_SET_NAME("Torus Knot", TORUS_KNOT )
,PASULI_SET_NAME("Gear Torus", GEAR_TORUS )
#endif
};


PASULI_PARSUR_STATIC char* parsur_desc_array[] = {
	/*
descPlane		//0
#if(COMPILE_DESC_SURFACES != 0)
,descBohemianDomeSurface
,descBoysSurface
,descCrossCup
,descDiniSurface
,descEnneperSurface
,descHandkerchief
,descKleinBottleSurface
,descMoebiusBand
,descMonkeySaddle

,descPlueckerConoid
,descRomanSurface
,descShoeSurface
,descSineSurface
,descSteinbachScrew
,descWhitneyUmbrella
,descCatenoid
,descHelicoid
,descParaboloid
,descHyperbolicHelicoid

,descFunnel
,descTractroid
,descCatalansSurface
,descHyperboloid
,descHennebergsSurface
,descSwallowSurface
,descWallisConicalSurface
,descMaedersOwl
,descRichmondSurface
,descScherkSurface

,descCosineSurface
,descEightSurface
,descJetSurface
,descDrop
,descTriaxialTeardrop
,descPillowShape
,descFishSurface
,descHorn
,descBentHorns
,descHyperbolicOctahedron

,descPseudoCrossCap
,descCresent
,descStilettoSurface
,descKuensSurface
,descTrefoilKnots
,descTranguloidTrefoil
,descCrown
,descTwistedPipeSurface
,descLoop
,descDupinCyclide

,descGuimardSurface
,descMennsSurface
,descMilkBag
,descTriaxialTritorus
,descVerrillSurface
,descZindlersConoid
,descFolium
,descLemniscape
,descTriplePointTwist
,descTrashcan

,descSpring1			//60
,descSpring2
,descCone
,descEgg
,descIsolator
,descHyperbolicParaboloid
,descDropSurface
,descFacingSnail
,descPaperBag
,descJeenerKleinSurface

,descBonanJeenerKleinSurface
,descKleinCycloid
,descDoubleCone
,descHoleDisc
,descPisotTriaxial
,descTriaxialHexatorus
,descTwistedHeart
,descHoleDiscus
,descDisc
,descWaves

,descSineWave
,descCosineWave
,descSpiralWave
,descBell
,descBellPolar
,descBellWave
,descSoucoupoid
,descEnneperSurfacePolar
,descSpinner
,descFresnel

,descTrefoilKnots2
,descBowCurve
,descTripleCorkScrew1
,descTripleCorkScrew2
,descTripleCorkScrew3
,descBicornSurface
,descPiriformSurface
,descKappaSurface
,descBulletNose
,descSievertSurface

,descCosineSurface2
#endif
//////////////////////////////////////
////////////  CYLINDER   /////////////
//////////////////////////////////////
#if(COMPILE_DESC_CYLINDER != 0)
,descCylinder			//101
,descEpizykloidCylinder
,descHypozykloidCylinder
,descLemniskateCylinder
,descStrophoideCylinder
,descZissoideCylinder
,descVACylinder
,descGaussCylinder
#endif
//////////////////////////////////////
////////////  FRUITS     /////////////
//////////////////////////////////////
#if(COMPILE_DESC_FRUITS != 0)
,descKidneySurface		//109
,descAppleSurface
,descApple2_Surface
,descLemonSurface
#endif
#if(COMPILE_DESC_SHELLS != 0)
,descCornucopia
,descSnail
,descSeashell
,descSnailSurface
,descSnails
,descPseudohelicerasSubcatenatum
,descAstroceras
,descBellerophina
,descEuhoplites
,descNautilus
,descNaticaStellata
,descMyaArenaria
#endif
//////////////////////////////////////
////////////  SPHERE     /////////////
//////////////////////////////////////
#if(COMPILE_DESC_SPHERE != 0)
,descSphere
,descEllipsoid
,descSphereV
,descSphereUV
,descPseudoSphere
,descTwistedSphere
,descOpenSphere
,descWaveSphere
#endif
//////////////////////////////////////
////////////  SPIRAL     /////////////
//////////////////////////////////////
#if(COMPILE_DESC_SPIRAL != 0)
,descArchimedicSpiral
,descHyperbolicSpiral
,descFermatSpiral
,descTanhSpiral
,descLogSpiral
#endif
#if(COMPILE_DESC_TORUS != 0)
,descTorus
,descEightTorus
,descEllipticTorus
,descSaddleTorus
,descAntisymmetricTorus
,descTwistedEightTorus
,descUmbillicTorus
,descWaveTorus
,descBraidedTorus
,descLimpetTorus
,descStrangledTorus
,descAstroidTorus
,descTricuspoidTorus1
,descTricuspoidTorus2

,descNethroidTorus1
,descNethroidTorus2
,descLemniskateTorus1
,descLemniskateTorus2
,descEpizykloidTorus1
,descEpizykloidTorus2
,descHypozykloidTorus1
,descHypozykloidTorus2
,descPiriformTorus1
,descPiriformTorus2

,descBicornTorus1
,descBicornTorus2
,descCardioidTorus1
,descCardioidTorus2
,descCassinianOvalTorus1
,descCassinianOvalTorus2
,descGeronoLemniskateTorus1
,descGeronoLemniskateTorus2
,descCurlyTorus1
,descCurlyTorus2

,descSpiralTorus
,descTorusKnot
,descGearTorus
#endif
*/
};



PASULI_PARSUR_STATIC PaSuLiDefDesc* parsur_def_desc_array[] = {
	/*
&pslddPlane		//0
#if(COMPILE_DEF_DESC_SURFACES != 0)
,&pslddBohemianDomeSurface		//1
,&pslddBoysSurface
,&pslddCrossCup
,&pslddDiniSurface
,&pslddEnneperSurface
,&pslddHandkerchief
,&pslddKleinBottleSurface
,&pslddMoebiusBand
,&pslddMonkeySaddle

,&pslddPlueckerConoid			//10
,&pslddRomanSurface
,&pslddShoeSurface
,&pslddSineSurface
,&pslddSteinbachScrew
,&pslddWhitneyUmbrella
,&pslddCatenoid
,&pslddHelicoid
,&pslddParaboloid
,&pslddHyperbolicHelicoid

,&pslddFunnel				//20
,&pslddTractroid
,&pslddCatalansSurface
,&pslddHyperboloid
,&pslddHennebergsSurface
,&pslddSwallowSurface
,&pslddWallisConicalSurface
,&pslddMaedersOwl
,&pslddRichmondSurface
,&pslddScherkSurface

,&pslddCosineSurface		//30
,&pslddEightSurface
,&pslddJetSurface
,&pslddDrop
,&pslddTriaxialTeardrop
,&pslddPillowShape
,&pslddFishSurface
,&pslddHorn
,&pslddBentHorns
,&pslddHyperbolicOctahedron

,&pslddPseudoCrossCap			//40
,&pslddCresent
,&pslddStilettoSurface
,&pslddKuensSurface
,&pslddTrefoilKnots
,&pslddTranguloidTrefoil
,&pslddCrown
,&pslddTwistedPipeSurface
,&pslddLoop
,&pslddDupinCyclide

,&pslddGuimardSurface			//50
,&pslddMennsSurface
,&pslddMilkBag
,&pslddTriaxialTritorus
,&pslddVerrillSurface
,&pslddZindlersConoid
,&pslddFolium
,&pslddLemniscape
,&pslddTriplePointTwist
,&pslddTrashcan

,&pslddSpring1			//60
,&pslddSpring2
,&pslddCone
,&pslddEgg
,&pslddIsolator
,&pslddHyperbolicParaboloid
,&pslddDropSurface
,&pslddFacingSnail
,&pslddPaperBag
,&pslddJeenerKleinSurface

,&pslddBonanJeenerKleinSurface	//70
,&pslddKleinCycloid
,&pslddDoubleCone
,&pslddHoleDisc
,&pslddPisotTriaxial
,&pslddTriaxialHexatorus
,&pslddTwistedHeart
,&pslddHoleDiscus
,&pslddDisc
,&pslddWaves

,&pslddSineWave				//80
,&pslddCosineWave
,&pslddSpiralWave
,&pslddBell
,&pslddBellPolar
,&pslddBellWave
,&pslddSoucoupoid
,&pslddEnneperSurfacePolar
,&pslddSpinner
,&pslddFresnel

,&pslddTrefoilKnots2			//90
,&pslddBowCurve
,&pslddTripleCorkScrew1
,&pslddTripleCorkScrew2
,&pslddTripleCorkScrew3
,&pslddBicornSurface
,&pslddPiriformSurface
,&pslddKappaSurface
,&pslddBulletNose
,&pslddSievertSurface

,&pslddCosineSurface2		//100
#endif
//////////////////////////////////////
////////////  CYLINDER   /////////////
//////////////////////////////////////
#if(COMPILE_DEF_DESC_CYLINDER != 0)
,&pslddCylinder			//101
,&pslddEpizykloidCylinder
,&pslddHypozykloidCylinder
,&pslddLemniskateCylinder
,&pslddStrophoideCylinder
,&pslddZissoideCylinder
,&pslddVACylinder
,&pslddGaussCylinder
#endif
//////////////////////////////////////
////////////  FRUITS     /////////////
//////////////////////////////////////
#if(COMPILE_DEF_DESC_FRUITS != 0)
,&pslddKidneySurface		//109
,&pslddAppleSurface
,&pslddApple2_Surface
,&pslddLemonSurface
#endif
#if(COMPILE_DEF_DESC_SHELLS != 0)
,&pslddCornucopia
,&pslddSnail
,&pslddSeashell
,&pslddSnailSurface
,&pslddSnails
,&pslddPseudohelicerasSubcatenatum
,&pslddAstroceras
,&pslddBellerophina
,&pslddEuhoplites
,&pslddNautilus
,&pslddNaticaStellata
,&pslddMyaArenaria
#endif
//////////////////////////////////////
////////////  SPHERE     /////////////
//////////////////////////////////////
#if(COMPILE_DEF_DESC_SPHERE != 0)
,&pslddSphere
,&pslddEllipsoid
,&pslddSphereV
,&pslddSphereUV
,&pslddPseudoSphere
,&pslddTwistedSphere
,&pslddOpenSphere
,&pslddWaveSphere
#endif
//////////////////////////////////////
////////////  SPIRAL     /////////////
//////////////////////////////////////
#if(COMPILE_DEF_DESC_SPIRAL != 0)
,&pslddArchimedicSpiral
,&pslddHyperbolicSpiral
,&pslddFermatSpiral
,&pslddTanhSpiral
,&pslddLogSpiral
#endif
#if(COMPILE_DEF_DESC_TORUS != 0)
,&pslddTorus
,&pslddEightTorus
,&pslddEllipticTorus
,&pslddSaddleTorus
,&pslddAntisymmetricTorus
,&pslddTwistedEightTorus
,&pslddUmbillicTorus
,&pslddWaveTorus
,&pslddBraidedTorus
,&pslddLimpetTorus
,&pslddStrangledTorus
,&pslddAstroidTorus
,&pslddTricuspoidTorus1
,&pslddTricuspoidTorus2

,&pslddNethroidTorus1
,&pslddNethroidTorus2
,&pslddLemniskateTorus1
,&pslddLemniskateTorus2
,&pslddEpizykloidTorus1
,&pslddEpizykloidTorus2
,&pslddHypozykloidTorus1
,&pslddHypozykloidTorus2
,&pslddPiriformTorus1
,&pslddPiriformTorus2

,&pslddBicornTorus1
,&pslddBicornTorus2
,&pslddCardioidTorus1
,&pslddCardioidTorus2
,&pslddCassinianOvalTorus1
,&pslddCassinianOvalTorus2
,&pslddGeronoLemniskateTorus1
,&pslddGeronoLemniskateTorus2
,&pslddCurlyTorus1
,&pslddCurlyTorus2

,&pslddSpiralTorus
,&pslddTorusKnot
,&pslddGearTorus
#endif
*/
};


pasuli_funcnum_range_type pasuli_cat_func_ranges[PASULI_CATEGORY_COUNT] = {
PASULI_CAT_SURFACES_COUNT	//entries for SURFACES
,PASULI_CAT_CYLINDER_COUNT	//Cylinder
,PASULI_CAT_FRUIT_COUNT		//Fruits
,PASULI_CAT_SHELL_COUNT		//Shells
,PASULI_CAT_SPHERE_COUNT	//Sphere
,PASULI_CAT_SPIRAL_COUNT	//Spiral
,PASULI_CAT_TORUS_COUNT		//Torus
};

pasuli_avail_info_type availablePaSuLiInfo[PASULI_CATEGORY_COUNT] = {
PASULI_SET_AVAILABLE(COMPILE_SURFACES, COMPILE_DEF_DESC_SURFACES, 
					COMPILE_DESC_SURFACES, COMPILE_NAMES_SURFACES)

,PASULI_SET_AVAILABLE(COMPILE_CYLINDER, COMPILE_DEF_DESC_CYLINDER, 
					COMPILE_DESC_CYLINDER, COMPILE_NAMES_CYLINDER)

,PASULI_SET_AVAILABLE(COMPILE_FRUITS, COMPILE_DEF_DESC_FRUITS, 
					COMPILE_DESC_FRUITS, COMPILE_NAMES_FRUITS)

,PASULI_SET_AVAILABLE(COMPILE_SHELLS, COMPILE_DEF_DESC_SHELLS, 
					COMPILE_DESC_SHELLS, COMPILE_NAMES_SHELLS)

,PASULI_SET_AVAILABLE(COMPILE_SPHERE, COMPILE_DEF_DESC_SPHERE, 
					COMPILE_DESC_SPHERE, COMPILE_NAMES_SPHERE)

,PASULI_SET_AVAILABLE(COMPILE_SPIRAL, COMPILE_DEF_DESC_SPIRAL, 
					COMPILE_DESC_SPIRAL, COMPILE_NAMES_SPIRAL)

,PASULI_SET_AVAILABLE(COMPILE_TORUS, COMPILE_DEF_DESC_TORUS, 
					COMPILE_DESC_TORUS, COMPILE_NAMES_TORUS)
};

