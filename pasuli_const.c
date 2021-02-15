
#include "pasuli_const.h"


#define PASULI_PARSUR_STATIC	static
//#define PASULI_PARSUR_STATIC


//PASULI_PARSUR_STATIC


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
	/*
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
					*/
};

