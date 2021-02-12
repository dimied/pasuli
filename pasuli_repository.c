
#include "pasuli_repository.h"
#include <stdlib.h>


#include "cylinder/cylinder.h"
#include "fruits/fruits.h"
#include "shells/shells.h"
#include "sphere/sphere.h"
#include "spiral/spiral.h"
//
#include "surfaces/plane.h"
#include "surfaces/surfaces.h"
//
#include "torus/antisym_torus.h"
#include "torus/torus.h"
#include "torus/umbillictorus.h"
#include "torus/wavetorus.h"

typedef struct
{
    char id;
    parsurFunc pFunc;
} PaSuLiRepositoryItem;

#define DEFINE_SURFACE(ID, FUNC_PTR) \
    {                                \
        ID, FUNC_PTR                 \
    }

void NoneSurface(double u, double v, double *constants, PaSuLiObject *pO)
{
}

PaSuLiRepositoryItem repositoryItems[] = {
#if (USE_PLANE != 0)
    DEFINE_SURFACE(PLANE, &Plane),
#endif
#if (USE_BOHEMIAN_DOME_SURFACE != 0)
    DEFINE_SURFACE(BOHEMIAN_DOME_SURFACE, &BohemianDomeSurface),
#endif
#if (USE_BOYS_SURFACE != 0)
    DEFINE_SURFACE(BOYS_SURFACE, &BoysSurface),
#endif
#if (USE_CROSS_CUP != 0)
    DEFINE_SURFACE(CROSS_CUP, &CrossCup),
#endif
#if (USE_DINI_SURFACE != 0)
    DEFINE_SURFACE(DINI_SURFACE, &DiniSurface),
#endif
#if (USE_ENNEPER_SURFACE != 0)
    DEFINE_SURFACE(ENNEPER_SURFACE, &EnneperSurface),
#endif
#if (USE_HANDKERCHIEF != 0)
    DEFINE_SURFACE(HANDKERCHIEF, &Handkerchief),
#endif
#if (USE_KLEIN_BOTTLE_SURFACE != 0)
    DEFINE_SURFACE(KLEIN_BOTTLE_SURFACE, &KleinBottleSurface),
#endif
#if (USE_MOEBIUS_BAND != 0)
    DEFINE_SURFACE(MOEBIUS_BAND, &MoebiusBand),
#endif
#if (USE_MONKEY_SADDLE != 0)
    DEFINE_SURFACE(MONKEY_SADDLE, &MonkeySaddle),
#endif
#if (USE_PLUECKER_CONOID != 0)
    DEFINE_SURFACE(PLUECKER_CONOID, &PlueckerConoid),
#endif
#if (USE_ROMAN_SURFACE != 0)
    DEFINE_SURFACE(ROMAN_SURFACE, &RomanSurface),
#endif
#if (USE_SHOE_SURFACE != 0)
    DEFINE_SURFACE(SHOE_SURFACE, &ShoeSurface),
#endif
#if (USE_SINE_SURFACE != 0)
    DEFINE_SURFACE(SINE_SURFACE, &SineSurface),
#endif
#if (USE_STEINBACH_SCREW != 0)
    DEFINE_SURFACE(STEINBACH_SCREW, &SteinbachScrew),
#endif
#if (USE_WHITNEY_UMBRELLA != 0)
    DEFINE_SURFACE(WHITNEY_UMBRELLA, &WhitneyUmbrella),
#endif
#if (USE_CATENOID != 0)
    DEFINE_SURFACE(CATENOID, &Catenoid),
#endif
#if (USE_HELICOID != 0)
    DEFINE_SURFACE(HELICOID, &Helicoid),
#endif
#if (USE_PARABOLOID != 0)
    DEFINE_SURFACE(PARABOLOID, &Paraboloid),
#endif
#if (USE_HYPERBOLIC_HELICOID != 0)
    DEFINE_SURFACE(HYPERBOLIC_HELICOID, &HyperbolicHelicoid),
#endif
#if (USE_FUNNEL != 0)
    DEFINE_SURFACE(FUNNEL, &Funnel),
#endif
#if (USE_TRACTROID != 0)
    DEFINE_SURFACE(TRACTROID, &Tractroid),
#endif
#if (USE_CATALANS_SURFACE != 0)
    DEFINE_SURFACE(CATALANS_SURFACE, &CatalansSurface),
#endif
#if (USE_HYPERBOLOID != 0)
    DEFINE_SURFACE(HYPERBOLOID, &Hyperboloid),
#endif
#if (USE_HENNEBERGS_SURFACE != 0)
    DEFINE_SURFACE(HENNEBERGS_SURFACE, &HennebergsSurface),
#endif
#if (USE_SWALLOW_SURFACE != 0)
    DEFINE_SURFACE(SWALLOW_SURFACE, &SwallowSurface),
#endif
#if (USE_WALLIS_CONICAL_SURFACE != 0)
    DEFINE_SURFACE(WALLIS_CONICAL_SURFACE, &WallisConicalSurface),
#endif
#if (USE_MAEDERS_OWL != 0)
    DEFINE_SURFACE(MAEDERS_OWL, &MaedersOwl),
#endif
#if (USE_RICHMOND_SURFACE != 0)
    DEFINE_SURFACE(RICHMOND_SURFACE, &RichmondSurface),
#endif
#if (USE_SCHERK_SURFACE != 0)
    DEFINE_SURFACE(SCHERK_SURFACE, &ScherkSurface),
#endif
#if (USE_COSINE_SURFACE != 0)
    DEFINE_SURFACE(COSINE_SURFACE, &CosineSurface),
#endif
#if (USE_EIGHT_SURFACE != 0)
    DEFINE_SURFACE(EIGHT_SURFACE, &EightSurface),
#endif
#if (USE_JET_SURFACE != 0)
    DEFINE_SURFACE(JET_SURFACE, &JetSurface),
#endif
#if (USE_DROP != 0)
    DEFINE_SURFACE(DROP, &Drop),
#endif
#if (USE_TRIAXIAL_TEARDROP != 0)
    DEFINE_SURFACE(TRIAXIAL_TEARDROP, &TriaxialTeardrop),
#endif
#if (USE_PILLOW_SHAPE != 0)
    DEFINE_SURFACE(PILLOW_SHAPE, &PillowShape),
#endif
#if (USE_FISH_SURFACE != 0)
    DEFINE_SURFACE(FISH_SURFACE, &FishSurface),
#endif
#if (USE_HORN != 0)
    DEFINE_SURFACE(HORN, &Horn),
#endif
#if (USE_BENT_HORNS != 0)
    DEFINE_SURFACE(BENT_HORNS, &BentHorns),
#endif
#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
    DEFINE_SURFACE(HYPERBOLIC_OCTAHEDRON, &HyperbolicOctahedron),
#endif
#if (USE_PSEUDO_CROSS_CAP != 0)
    DEFINE_SURFACE(PSEUDO_CROSS_CAP, &PseudoCrossCap),
#endif
#if (USE_CRESENT != 0)
    DEFINE_SURFACE(CRESENT, &Cresent),
#endif
#if (USE_STILETTO_SURFACE != 0)
    DEFINE_SURFACE(STILETTO_SURFACE, &StilettoSurface),
#endif
#if (USE_KUENS_SURFACE != 0)
    DEFINE_SURFACE(KUENS_SURFACE, &KuensSurface),
#endif
#if (USE_TREFOIL_KNOTS != 0)
    DEFINE_SURFACE(TREFOIL_KNOTS, &TrefoilKnots),
#endif
#if (USE_TRANGULOID_TREFOIL != 0)
    DEFINE_SURFACE(TRANGULOID_TREFOIL, &TranguloidTrefoil),
#endif
#if (USE_CROWN != 0)
    DEFINE_SURFACE(CROWN, &Crown),
#endif
#if (USE_TWISTED_PIPE_SURFACE != 0)
    DEFINE_SURFACE(TWISTED_PIPE_SURFACE, &TwistedPipeSurface),
#endif
#if (USE_LOOP != 0)
    DEFINE_SURFACE(LOOP, &Loop),
#endif
#if (USE_DUPIN_CYCLIDE != 0)
    DEFINE_SURFACE(DUPIN_CYCLIDE, &DupinCyclide),
#endif
#if (USE_GUIMARD_SURFACE != 0)
    DEFINE_SURFACE(GUIMARD_SURFACE, &GuimardSurface),
#endif
#if (USE_MENNS_SURFACE != 0)
    DEFINE_SURFACE(MENNS_SURFACE, &MennsSurface),
#endif
#if (USE_MILK_BAG != 0)
    DEFINE_SURFACE(MILK_BAG, &MilkBag),
#endif
#if (USE_TRIAXIAL_TRITORUS != 0)
    DEFINE_SURFACE(TRIAXIAL_TRITORUS, &TriaxialTritorus),
#endif
#if (USE_VERRILL_SURFACE != 0)
    DEFINE_SURFACE(VERRILL_SURFACE, &VerrillSurface),
#endif
#if (USE_ZINDLERS_CONOID != 0)
    DEFINE_SURFACE(ZINDLERS_CONOID, &ZindlersConoid),
#endif
#if (USE_FOLIUM != 0)
    DEFINE_SURFACE(FOLIUM, &Folium),
#endif
#if (USE_LEMNISCAPE != 0)
    DEFINE_SURFACE(LEMNISCAPE, &Lemniscape),
#endif
#if (USE_TRIPLE_POINT_TWIST != 0)
    DEFINE_SURFACE(TRIPLE_POINT_TWIST, &TriplePointTwist),
#endif
#if (USE_TRASHCAN != 0)
    DEFINE_SURFACE(TRASHCAN, &Trashcan),
#endif
#if (USE_SPRING1 != 0)
    DEFINE_SURFACE(SPRING1, &Spring1),
#endif
#if (USE_SPRING2 != 0)
    DEFINE_SURFACE(SPRING2, &Spring2),
#endif
#if (USE_CONE != 0)
    DEFINE_SURFACE(CONE, &Cone),
#endif
#if (USE_EGG != 0)
    DEFINE_SURFACE(EGG, &Egg),
#endif
#if (USE_ISOLATOR != 0)
    DEFINE_SURFACE(ISOLATOR, &Isolator),
#endif
#if (USE_HYPERBOLIC_PARABOLOID != 0)
    DEFINE_SURFACE(HYPERBOLIC_PARABOLOID, &HyperbolicParaboloid),
#endif
#if (USE_DROP_SURFACE != 0)
    DEFINE_SURFACE(DROP_SURFACE, &DropSurface),
#endif
#if (USE_FACING_SNAIL != 0)
    DEFINE_SURFACE(FACING_SNAIL, &FacingSnail),
#endif
#if (USE_PAPER_BAG != 0)
    DEFINE_SURFACE(PAPER_BAG, &PaperBag),
#endif
#if (USE_JEENER_KLEIN_SURFACE != 0)
    DEFINE_SURFACE(JEENER_KLEIN_SURFACE, &JeenerKleinSurface),
#endif
#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)
    DEFINE_SURFACE(BONAN_JEENER_KLEIN_SURFACE, &BonanJeenerKleinSurface),
#endif
#if (USE_KLEIN_CYCLOID != 0)
    DEFINE_SURFACE(KLEIN_CYCLOID, &KleinCycloid),
#endif
#if (USE_DOUBLE_CONE != 0)
    DEFINE_SURFACE(DOUBLE_CONE, &DoubleCone),
#endif
#if (USE_HOLE_DISC != 0)
    DEFINE_SURFACE(HOLE_DISC, &HoleDisc),
#endif
#if (USE_PISOT_TRIAXIAL != 0)
    DEFINE_SURFACE(PISOT_TRIAXIAL, &PisotTriaxial),
#endif
#if (USE_TRIAXIAL_HEXATORUS != 0)
    DEFINE_SURFACE(TRIAXIAL_HEXATORUS, &TriaxialHexatorus),
#endif
#if (USE_TWISTED_HEART != 0)
    DEFINE_SURFACE(TWISTED_HEART, &TwistedHeart),
#endif
#if (USE_HOLE_DISCUS != 0)
    DEFINE_SURFACE(HOLE_DISCUS, &HoleDiscus),
#endif
#if (USE_DISC != 0)
    DEFINE_SURFACE(DISC, &Disc),
#endif
#if (USE_WAVES != 0)
    DEFINE_SURFACE(WAVES, &Waves),
#endif
#if (USE_SINE_WAVE != 0)
    DEFINE_SURFACE(SINE_WAVE, &SineWave),
#endif
#if (USE_COSINE_WAVE != 0)
    DEFINE_SURFACE(COSINE_WAVE, &CosineWave),
#endif
#if (USE_SPIRAL_WAVE != 0)
    DEFINE_SURFACE(SPIRAL_WAVE, &SpiralWave),
#endif
#if (USE_BELL != 0)
    DEFINE_SURFACE(BELL, &Bell),
#endif
#if (USE_BELL_POLAR != 0)
    DEFINE_SURFACE(BELL_POLAR, &BellPolar),
#endif
#if (USE_BELL_WAVE != 0)
    DEFINE_SURFACE(BELL_WAVE, &BellWave),
#endif
#if (USE_SOUCOUPOID != 0)
    DEFINE_SURFACE(SOUCOUPOID, &Soucoupoid),
#endif
#if (USE_ENNEPER_SURFACE_POLAR != 0)
    DEFINE_SURFACE(ENNEPER_SURFACE_POLAR, &EnneperSurfacePolar),
#endif
#if (USE_SPINNER != 0)
    DEFINE_SURFACE(SPINNER, &Spinner),
#endif
#if (USE_FRESNEL != 0)
    DEFINE_SURFACE(FRESNEL, &Fresnel),
#endif
#if (USE_TREFOIL_KNOTS2 != 0)
    DEFINE_SURFACE(TREFOIL_KNOTS2, &TrefoilKnots2),
#endif
#if (USE_BOW_CURVE != 0)
    DEFINE_SURFACE(BOW_CURVE, &BowCurve),
#endif
#if (USE_TRIPLE_CORK_SCREW1 != 0)
    DEFINE_SURFACE(TRIPLE_CORK_SCREW1, &TripleCorkScrew1),
#endif
#if (USE_TRIPLE_CORK_SCREW2 != 0)
    DEFINE_SURFACE(TRIPLE_CORK_SCREW2, &TripleCorkScrew2),
#endif
#if (USE_TRIPLE_CORK_SCREW3 != 0)
    DEFINE_SURFACE(TRIPLE_CORK_SCREW3, &TripleCorkScrew3),
#endif
#if (USE_BICORN_SURFACE != 0)
    DEFINE_SURFACE(BICORN_SURFACE, &BicornSurface),
#endif
#if (USE_PIRIFORM_SURFACE != 0)
    DEFINE_SURFACE(PIRIFORM_SURFACE, &PiriformSurface),
#endif
#if (USE_KAPPA_SURFACE != 0)
    DEFINE_SURFACE(KAPPA_SURFACE, &KappaSurface),
#endif
#if (USE_BULLET_NOSE != 0)
    DEFINE_SURFACE(BULLET_NOSE, &BulletNose),
#endif
#if (USE_SIEVERT_SURFACE != 0)
    DEFINE_SURFACE(SIEVERT_SURFACE, &SievertSurface),
#endif
#if (USE_COSINE_SURFACE2 != 0)
    DEFINE_SURFACE(COSINE_SURFACE2, &CosineSurface2),
#endif
//// Cylinder
#if (USE_CYLINDER != 0)
    DEFINE_SURFACE(CYLINDER, &Cylinder),
#endif
#if (USE_EPIZYKLOID_CYLINDER != 0)
    DEFINE_SURFACE(EPIZYKLOID_CYLINDER, &EpizykloidCylinder),
#endif
#if (USE_HYPOZYKLOID_CYLINDER != 0)
    DEFINE_SURFACE(HYPOZYKLOID_CYLINDER, &HypozykloidCylinder),
#endif
#if (USE_LEMNISKATE_CYLINDER != 0)
    DEFINE_SURFACE(LEMNISKATE_CYLINDER, &LemniskateCylinder),
#endif
#if (USE_STROPHOIDE_CYLINDER != 0)
    DEFINE_SURFACE(STROPHOIDE_CYLINDER, &StrophoideCylinder),
#endif
#if (USE_ZISSOIDE_CYLINDER != 0)
    DEFINE_SURFACE(ZISSOIDE_CYLINDER, &ZissoideCylinder),
#endif
#if (USE_VERSIERA_AGNESI_CYLINDER != 0)
    DEFINE_SURFACE(VERSIERA_AGNESI_CYLINDER, &VersieraAgnesiCylinder),
#endif
#if (USE_GAUSS_CYLINDER != 0)
    DEFINE_SURFACE(GAUSS_CYLINDER, &GaussCylinder),
#endif
//// Fruits
#if (USE_KIDNEY_SURFACE != 0)
    DEFINE_SURFACE(KIDNEY_SURFACE, &KidneySurface),
#endif
#if (USE_APPLE_SURFACE != 0)
    DEFINE_SURFACE(APPLE_SURFACE, &AppleSurface),
#endif
#if (USE_APPLE2_SURFACE != 0)
    DEFINE_SURFACE(APPLE2_SURFACE, &Apple2_Surface),
#endif
#if (USE_LEMON_SURFACE != 0)
    DEFINE_SURFACE(LEMON_SURFACE, &LemonSurface),
#endif
//// Shells & snails
#if (USE_CORNUCOPIA != 0)
    DEFINE_SURFACE(CORNUCOPIA, &Cornucopia),
#endif
#if (USE_SNAIL != 0)
    DEFINE_SURFACE(SNAIL, &Snail),
#endif
#if (USE_SEASHELL != 0)
    DEFINE_SURFACE(SEASHELL, &Seashell),
#endif
#if (USE_SNAIL_SURFACE != 0)
    DEFINE_SURFACE(SNAIL_SURFACE, &SnailSurface),
#endif
#if (USE_SNAILS != 0)
    DEFINE_SURFACE(SNAILS, &Snails),
#endif
#if (USE_PSEUDOHELICERAS_SUBCATENATUM != 0)
    DEFINE_SURFACE(PSEUDOHELICERAS_SUBCATENATUM, &PseudohelicerasSubcatenatum),
#endif
#if (USE_ASTROCERAS != 0)
    DEFINE_SURFACE(ASTROCERAS, &Astroceras),
#endif
#if (USE_BELLEROPHINA != 0)
    DEFINE_SURFACE(BELLEROPHINA, &Bellerophina),
#endif
#if (USE_EUHOPLITES != 0)
    DEFINE_SURFACE(EUHOPLITES, &Euhoplites),
#endif
#if (USE_NAUTILUS != 0)
    DEFINE_SURFACE(NAUTILUS, &Nautilus),
#endif
#if (USE_NATICA_STELLATA != 0)
    DEFINE_SURFACE(NATICA_STELLATA, &NaticaStellata),
#endif
#if (USE_MYA_ARENARIA != 0)
    DEFINE_SURFACE(MYA_ARENARIA, &MyaArenaria),
#endif
//// Spheres
#if (USE_SPHERE != 0)
    DEFINE_SURFACE(SPHERE, &Sphere),
#endif
#if (USE_ELLIPSOID != 0)
    DEFINE_SURFACE(ELLIPSOID, &Ellipsoid),
#endif
#if (USE_SPHERE_V != 0)
    DEFINE_SURFACE(SPHERE_V, &SphereV),
#endif
#if (USE_SPHERE_UV != 0)
    DEFINE_SURFACE(SPHERE_UV, &SphereUV),
#endif
#if (USE_PSEUDOSPHERE != 0)
    DEFINE_SURFACE(PSEUDOSPHERE, &PseudoSphere),
#endif
#if (USE_TWISTED_SPHERE != 0)
    DEFINE_SURFACE(TWISTED_SPHERE, &TwistedSphere),
#endif
#if (USE_OPEN_SPHERE != 0)
    DEFINE_SURFACE(OPEN_SPHERE, &OpenSphere),
#endif
#if (USE_WAVE_SPHERE != 0)
    DEFINE_SURFACE(WAVE_SPHERE, &WaveSphere),
#endif
//// Spirals
#if (USE_ARCHIMEDIC_SPIRAL != 0)
    DEFINE_SURFACE(ARCHIMEDIC_SPIRAL, &ArchimedicSpiral),
#endif
#if (USE_HYPERBOLIC_SPIRAL != 0)
    DEFINE_SURFACE(HYPERBOLIC_SPIRAL, &HyperbolicSpiral),
#endif
#if (USE_FERMAT_SPIRAL != 0)
    DEFINE_SURFACE(FERMAT_SPIRAL, &FermatSpiral),
#endif
#if (USE_TANH_SPIRAL != 0)
    DEFINE_SURFACE(TANH_SPIRAL, &TanhSpiral),
#endif
#if (USE_LOG_SPIRAL != 0)
    DEFINE_SURFACE(LOG_SPIRAL, &LogSpiral),
#endif
//// Torus
#if (USE_TORUS != 0)
    DEFINE_SURFACE(TORUS, &Torus),
#endif
#if (USE_EIGHT_TORUS != 0)
    DEFINE_SURFACE(EIGHT_TORUS, &EightSurface),
#endif
#if (USE_ELLIPTIC_TORUS != 0)
    DEFINE_SURFACE(ELLIPTIC_TORUS, &EllipticTorus),
#endif
#if (USE_SADDLE_TORUS != 0)
    DEFINE_SURFACE(SADDLE_TORUS, &SaddleTorus),
#endif
#if (USE_ANTISYMMETRIC_TORUS != 0)
    DEFINE_SURFACE(ANTISYMMETRIC_TORUS, &AntisymmetricTorus),
#endif
#if (USE_TWISTED_EIGHT_TORUS != 0)
    DEFINE_SURFACE(TWISTED_EIGHT_TORUS, &TwistedEightTorus),
#endif
#if (USE_UMBILLIC_TORUS != 0)
    DEFINE_SURFACE(UMBILLIC_TORUS, &UmbillicTorus),
#endif
#if (USE_WAVE_TORUS != 0)
    DEFINE_SURFACE(WAVE_TORUS, &WaveTorus),
#endif
#if (USE_BRAIDED_TORUS != 0)
    DEFINE_SURFACE(BRAIDED_TORUS, &BraidedTorus),
#endif
#if (USE_LIMPET_TORUS != 0)
    DEFINE_SURFACE(LIMPET_TORUS, &LimpetTorus),
#endif
#if (USE_STRANGLED_TORUS != 0)
    DEFINE_SURFACE(STRANGLED_TORUS, &StrangledTorus),
#endif
#if (USE_ASTROID_TORUS != 0)
    DEFINE_SURFACE(ASTROID_TORUS, &AstroidTorus),
#endif
#if (USE_TRICUSPOID_TORUS_1 != 0)
    DEFINE_SURFACE(TRICUSPOID_TORUS_1, &TricuspoidTorus1),
#endif
#if (USE_TRICUSPOID_TORUS_2 != 0)
    DEFINE_SURFACE(TRICUSPOID_TORUS_2, &TricuspoidTorus2),
#endif
#if (USE_NETHROID_TORUS_1 != 0)
    DEFINE_SURFACE(NETHROID_TORUS_1, &NethroidTorus1),
#endif
#if (USE_NETHROID_TORUS_2 != 0)
    DEFINE_SURFACE(NETHROID_TORUS_2, &NethroidTorus2),
#endif
#if (USE_LEMNISKATE_TORUS_1 != 0)
    DEFINE_SURFACE(LEMNISKATE_TORUS_1, &LemniskateTorus1),
#endif
#if (USE_LEMNISKATE_TORUS_2 != 0)
    DEFINE_SURFACE(LEMNISKATE_TORUS_2, &LemniskateTorus2),
#endif
#if (USE_EPIZYKLOID_TORUS_1 != 0)
    DEFINE_SURFACE(EPIZYKLOID_TORUS_1, &EpizykloidTorus1),
#endif
#if (USE_EPIZYKLOID_TORUS_2 != 0)
    DEFINE_SURFACE(EPIZYKLOID_TORUS_2, &EpizykloidTorus2),
#endif
#if (USE_HYPOZYKLOID_TORUS_1 != 0)
    DEFINE_SURFACE(HYPOZYKLOID_TORUS_1, &HypozykloidTorus1),
#endif
#if (USE_HYPOZYKLOID_TORUS_2 != 0)
    DEFINE_SURFACE(HYPOZYKLOID_TORUS_2, &HypozykloidTorus2),
#endif
#if (USE_PIRIFORM_TORUS_1 != 0)
    DEFINE_SURFACE(PIRIFORM_TORUS_1, &PiriformTorus1),
#endif
#if (USE_PIRIFORM_TORUS_2 != 0)
    DEFINE_SURFACE(PIRIFORM_TORUS_2, &PiriformTorus2),
#endif
#if (USE_BICORN_TORUS_1 != 0)
    DEFINE_SURFACE(BICORN_TORUS_1, &BicornTorus1),
#endif
#if (USE_BICORN_TORUS_2 != 0)
    DEFINE_SURFACE(BICORN_TORUS_2, &BicornTorus2),
#endif
#if (USE_CARDIOID_TORUS_1 != 0)
    DEFINE_SURFACE(CARDIOID_TORUS_1, &CardioidTorus1),
#endif
#if (USE_CARDIOID_TORUS_2 != 0)
    DEFINE_SURFACE(CARDIOID_TORUS_2, &CardioidTorus2),
#endif
#if (USE_CASSINIAN_OVAL_TORUS_1 != 0)
    DEFINE_SURFACE(CASSINIAN_OVAL_TORUS_1, &CassinianOvalTorus1),
#endif
#if (USE_CASSINIAN_OVAL_TORUS_2 != 0)
    DEFINE_SURFACE(CASSINIAN_OVAL_TORUS_2, &CassinianOvalTorus2),
#endif
#if (USE_GERONO_LEMNISKATE_TORUS_1 != 0)
    DEFINE_SURFACE(GERONO_LEMNISKATE_TORUS_1, &GeronoLemniskateTorus1),
#endif
#if (USE_GERONO_LEMNISKATE_TORUS_2 != 0)
    DEFINE_SURFACE(GERONO_LEMNISKATE_TORUS_2, &GeronoLemniskateTorus2),
#endif
#if (USE_CURLY_TORUS_1 != 0)
    DEFINE_SURFACE(CURLY_TORUS_1, &CurlyTorus1),
#endif
#if (USE_CURLY_TORUS_2 != 0)
    DEFINE_SURFACE(CURLY_TORUS_2, &CurlyTorus2),
#endif
#if (USE_SPIRAL_TORUS != 0)
    DEFINE_SURFACE(SPIRAL_TORUS, &SpiralTorus),
#endif
#if (USE_TORUS_KNOT != 0)
    DEFINE_SURFACE(TORUS_KNOT, &TorusKnot),
#endif
#if (USE_GEAR_TORUS != 0)
    DEFINE_SURFACE(GEAR_TORUS, &GearTorus),
#endif
    //DEFINE_SURFACE(255, &NoneSurface)
};

#undef DEFINE_SURFACE

unsigned int numberOfPasuliRepositoryItems = sizeof(repositoryItems) / sizeof(PaSuLiRepositoryItem);

parsurFunc findPasuliFunctionById(unsigned int id)
{
    if (id >= 255)
    {
        return 0;
    }
    for (size_t i = 0; i < numberOfPasuliRepositoryItems; i++)
    {
        if (repositoryItems[i].id == id)
        {
            return repositoryItems[i].pFunc;
        }
    }
    return 0;
}

/*
void* getPaSuLiPointer(unsigned int uiSurfaceType, unsigned int uiInfo) {

	////if((!(uiInfo < PASULI_MAX_INFO_DESCRIPTIONS))||
	////	(!(uiSurfaceType < NUMB_OF_SURFACES))) {	//De Morgan ==>
	if(!((uiInfo < PASULI_MAX_INFO_DESCRIPTIONS) &&
		(uiSurfaceType < NUMB_OF_SURFACES))) {
		return 0;		//NOT SAVED INFORMATION ANYWAY
	}
	//bool not_available = false;
	int cat = -1;
	int curImpl = 0, fullImpl = 0;
	int i = 0;
	//search in pasuli_cat_func_ranges - array first
	int iSurfaceType = (int) uiSurfaceType;
	for(; i < 7; i++) {

		fullImpl += pasuli_cat_func_ranges[i];
		//Is info available
		if(PASULI_GET_AVAILABLE(availablePaSuLiInfo[i], uiInfo)) {
			curImpl += pasuli_cat_func_ranges[i];
		}
		
		if(iSurfaceType <= fullImpl) {
			cat = i;
			//calculate real index 
			iSurfaceType = curImpl - (fullImpl - iSurfaceType);
			break;
		}
	}
	uiSurfaceType = iSurfaceType;
	if(cat == -1) {
		return 0;		//NOT FOUND, i.e. NOT COMPILED IN THIS VERSION
	}

	switch( uiInfo ) {
		case PASULI_INFO_FUNC_PTR:
						return (void*)parsur_array[uiSurfaceType];

		case PASULI_INFO_DESC_PTR:
						return (void*)parsur_desc_array[uiSurfaceType];

		case PASULI_INFO_DEF_DESC_PTR:
						return (void*)parsur_def_desc_array[uiSurfaceType];

		case PASULI_INFO_NAME_PTR:
		return (void*)PASULI_NAME_CHAR_PTR(parsur_name_array[uiSurfaceType] );

		default:	return 0;
	}

	return 0;
}
*/

//PASULI_PARSUR_STATIC parsurFunc parsur_array[] = {
/*
Plane

#if(COMPILE_SURFACES != 0)
,BohemianDomeSurface
,BoysSurface
,CrossCup
,DiniSurface
,EnneperSurface
,Handkerchief
,KleinBottleSurface
,MoebiusBand
,MonkeySaddle

,PlueckerConoid
,RomanSurface
,ShoeSurface
,SineSurface
,SteinbachScrew
,WhitneyUmbrella
,Catenoid
,Helicoid
,Paraboloid
,HyperbolicHelicoid

,Funnel
,Tractroid
,CatalansSurface
,Hyperboloid
,HennebergsSurface
,SwallowSurface
,WallisConicalSurface
,MaedersOwl
,RichmondSurface
,ScherkSurface

,CosineSurface
,EightSurface
,JetSurface
,Drop
,TriaxialTeardrop
,PillowShape
,FishSurface
,Horn
,BentHorns
,HyperbolicOctahedron

,PseudoCrossCap
,Cresent
,StilettoSurface
,KuensSurface
,TrefoilKnots
,TranguloidTrefoil
,Crown
,TwistedPipeSurface
,Loop
,DupinCyclide

,GuimardSurface
,MennsSurface
,MilkBag
,TriaxialTritorus
,VerrillSurface
,ZindlersConoid
,Folium
,Lemniscape
,TriplePointTwist
,Trashcan

,Spring1
,Spring2
,Cone
,Egg
,Isolator
,HyperbolicParaboloid
,DropSurface
,FacingSnail
,PaperBag
,JeenerKleinSurface

,BonanJeenerKleinSurface
,KleinCycloid
,DoubleCone
,HoleDisc
,PisotTriaxial
,TriaxialHexatorus
,TwistedHeart
,HoleDiscus
,Disc
,Waves

,SineWave
,CosineWave
,SpiralWave
,Bell
,BellPolar
,BellWave
,Soucoupoid
,EnneperSurfacePolar
,Spinner
,Fresnel

,TrefoilKnots2
,BowCurve
,TripleCorkScrew1
,TripleCorkScrew2
,TripleCorkScrew3
,BicornSurface
,PiriformSurface
,KappaSurface
,BulletNose
,SievertSurface

,CosineSurface2
#endif
#if(COMPILE_CYLINDER != 0)
,Cylinder
,EpizykloidCylinder
,HypozykloidCylinder
,LemniskateCylinder
,StrophoideCylinder
,ZissoideCylinder
,VersieraAgnesiCylinder
,GaussCylinder
#endif
#if(COMPILE_FRUITS != 0)
,KidneySurface
,AppleSurface
,Apple2_Surface
,LemonSurface
#endif
#if(COMPILE_SHELLS != 0)
//////SHELLS & SNAILS
,Cornucopia
,Snail
,Seashell
,SnailSurface
,Snails
,PseudohelicerasSubcatenatum
,Astroceras
,Bellerophina
,Euhoplites
,Nautilus
,NaticaStellata
,MyaArenaria
#endif
#if(COMPILE_SPHERE != 0)
,Sphere
,Ellipsoid
,SphereV
,SphereUV
,PseudoSphere
,TwistedSphere
,OpenSphere

,WaveSphere
#endif
#if(COMPILE_SPIRAL != 0)
,ArchimedicSpiral
,HyperbolicSpiral
,FermatSpiral
,TanhSpiral
,LogSpiral
#endif
#if(COMPILE_TORUS != 0)
,Torus
,EightTorus
,EllipticTorus
,SaddleTorus

,AntisymmetricTorus
,TwistedEightTorus
,UmbillicTorus
,WaveTorus
,BraidedTorus
,LimpetTorus
,StrangledTorus
,AstroidTorus
,TricuspoidTorus1
,TricuspoidTorus2

,NethroidTorus1
,NethroidTorus2
,LemniskateTorus1
,LemniskateTorus2
,EpizykloidTorus1
,EpizykloidTorus2
,HypozykloidTorus1
,HypozykloidTorus2
,PiriformTorus1
,PiriformTorus2

,BicornTorus1
,BicornTorus2
,CardioidTorus1
,CardioidTorus2
,CassinianOvalTorus1
,CassinianOvalTorus2
,GeronoLemniskateTorus1
,GeronoLemniskateTorus2
,CurlyTorus1
,CurlyTorus2

,SpiralTorus
,TorusKnot
,GearTorus
#endif
*/
//};
