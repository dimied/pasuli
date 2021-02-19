
#include "pasuli_repository.h"
#include <stdlib.h>

#include "cylinder/cylinder_all.h"
#include "fruits/fruits.h"
#include "shells/shells.h"
#include "sphere/sphere.h"
#include "spiral/spiral.h"
//
#include "surfaces/surfaces.h"
//
#include "torus/torus_all.h"

typedef struct
{
    unsigned char id;
    parsurFunc pFunc;
} PaSuLiRepositoryItem;

#define DEFINE_SURFACE(ID, FUNC_PTR) \
    {                                \
        ID, FUNC_PTR                 \
    }

void NoneSurface(pasuli_vartype u, pasuli_vartype v, pasuli_consttype *constants, PaSuLiObject *pO)
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
#if (USE_MOEBIUS_BAND2 != 0)
    DEFINE_SURFACE(MOEBIUS_BAND2, &MoebiusBand2),
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

typedef struct _pasuli_name_type
{
    char *szName;
    int _ID;
} pasuli_name_type;

pasuli_name_type parsur_name_array[] = {
#if (COMPILE_NAMES_SURFACES != 0)
    PASULI_SET_NAME("Plane", PLANE),
    PASULI_SET_NAME("Bohemian Dome Surface", BOHEMIAN_DOME_SURFACE),
    PASULI_SET_NAME("Boys Surface", BOYS_SURFACE),
    PASULI_SET_NAME("Cross Cup", CROSS_CUP),
    PASULI_SET_NAME("Dini Surface", DINI_SURFACE),
    PASULI_SET_NAME("Enneper Surface", ENNEPER_SURFACE),
    PASULI_SET_NAME("Handkerchief", HANDKERCHIEF),
    PASULI_SET_NAME("Klein Bottle Surface", KLEIN_BOTTLE_SURFACE),
    PASULI_SET_NAME("Moebius Band", MOEBIUS_BAND),
    PASULI_SET_NAME("Monkey Saddle", MONKEY_SADDLE),
    PASULI_SET_NAME("Pluecker Conoid", PLUECKER_CONOID),
    PASULI_SET_NAME("Roman Surface", ROMAN_SURFACE),
    PASULI_SET_NAME("Shoe Surface", SHOE_SURFACE),
    PASULI_SET_NAME("Sine Surface", SINE_SURFACE),
    PASULI_SET_NAME("Steinbach Screw", STEINBACH_SCREW),
    PASULI_SET_NAME("Whitney Umbrella", WHITNEY_UMBRELLA),
    PASULI_SET_NAME("Catenoid", CATENOID),
    PASULI_SET_NAME("Helicoid", HELICOID),
    PASULI_SET_NAME("Paraboloid", PARABOLOID),
    PASULI_SET_NAME("Hyperbolic Helicoid", HYPERBOLIC_HELICOID),
    PASULI_SET_NAME("Funnel", FUNNEL),
    PASULI_SET_NAME("Tractroid", TRACTROID),
    PASULI_SET_NAME("Catalans Surface", CATALANS_SURFACE),
    PASULI_SET_NAME("Hyperboloid", HYPERBOLOID),
    PASULI_SET_NAME("Hennebergs Surface", HENNEBERGS_SURFACE),
    PASULI_SET_NAME("Swallow Surface", SWALLOW_SURFACE),
    PASULI_SET_NAME("Wallis Conical Surface", WALLIS_CONICAL_SURFACE),
    PASULI_SET_NAME("Maeders Owl", MAEDERS_OWL),
    PASULI_SET_NAME("Richmond Surface", RICHMOND_SURFACE),
    PASULI_SET_NAME("Scherk Surface", SCHERK_SURFACE),
    PASULI_SET_NAME("Cosine Surface", COSINE_SURFACE),
    PASULI_SET_NAME("Eight Surface", EIGHT_SURFACE),
    PASULI_SET_NAME("Jet Surface", JET_SURFACE),
    PASULI_SET_NAME("Drop", DROP),
    PASULI_SET_NAME("Triaxial Teardrop", TRIAXIAL_TEARDROP),
    PASULI_SET_NAME("Pillow Shape", PILLOW_SHAPE),
    PASULI_SET_NAME("Fish Surface", FISH_SURFACE),
    PASULI_SET_NAME("Horn", HORN),
    PASULI_SET_NAME("Bent Horns", BENT_HORNS),
    PASULI_SET_NAME("Hyperbolic Octahedron", HYPERBOLIC_OCTAHEDRON),
    PASULI_SET_NAME("Pseudo Cross Cap", PSEUDO_CROSS_CAP),
    PASULI_SET_NAME("Cresent", CRESENT),
    PASULI_SET_NAME("Stiletto Surface", STILETTO_SURFACE),
    PASULI_SET_NAME("Kuens Surface", KUENS_SURFACE),
    PASULI_SET_NAME("Trefoil Knots", TREFOIL_KNOTS),
    PASULI_SET_NAME("Tranguloid Trefoil", TRANGULOID_TREFOIL),
    PASULI_SET_NAME("Crown", CROWN),
    PASULI_SET_NAME("Twisted Pipe Surface", TWISTED_PIPE_SURFACE),
    PASULI_SET_NAME("Loop", LOOP),
    PASULI_SET_NAME("Dupin Cyclide", DUPIN_CYCLIDE),
    PASULI_SET_NAME("Guimard Surface", GUIMARD_SURFACE),
    PASULI_SET_NAME("Menns Surface", MENNS_SURFACE),
    PASULI_SET_NAME("MilkBag", MILK_BAG),
    PASULI_SET_NAME("Triaxial Tritorus", TRIAXIAL_TRITORUS),
    PASULI_SET_NAME("Verrill Surface", VERRILL_SURFACE),
    PASULI_SET_NAME("Zindlers Conoid", ZINDLERS_CONOID),
    PASULI_SET_NAME("Folium", FOLIUM),
    PASULI_SET_NAME("Lemniscape", LEMNISCAPE),
    PASULI_SET_NAME("Triple Point Twist", TRIPLE_POINT_TWIST),
    PASULI_SET_NAME("Trashcan", TRASHCAN),
    PASULI_SET_NAME("Spring1", SPRING1),
    PASULI_SET_NAME("Spring2", SPRING2),
    PASULI_SET_NAME("Cone", CONE),
    PASULI_SET_NAME("Egg", EGG),
    PASULI_SET_NAME("Isolator", ISOLATOR),
    PASULI_SET_NAME("Hyperbolic Paraboloid", HYPERBOLIC_PARABOLOID),
    PASULI_SET_NAME("Drop Surface", DROP_SURFACE),
    PASULI_SET_NAME("Facing Snail", FACING_SNAIL),
    PASULI_SET_NAME("Paper Bag", PAPER_BAG),
    PASULI_SET_NAME("Jeener Klein Surface", JEENER_KLEIN_SURFACE),
    PASULI_SET_NAME("Bonan Jeener Klein Surface", BONAN_JEENER_KLEIN_SURFACE),
    PASULI_SET_NAME("Klein Cycloid", KLEIN_CYCLOID),
    PASULI_SET_NAME("Double Cone", DOUBLE_CONE),
    PASULI_SET_NAME("Hole Disc", HOLE_DISC),
    PASULI_SET_NAME("Pisot Triaxial", PISOT_TRIAXIAL),
    PASULI_SET_NAME("Triaxial Hexatorus", TRIAXIAL_HEXATORUS),
    PASULI_SET_NAME("Twisted Heart", TWISTED_HEART),
    PASULI_SET_NAME("Hole Discus", HOLE_DISCUS),
    PASULI_SET_NAME("Disc", DISC),
    PASULI_SET_NAME("Waves", WAVES),
    PASULI_SET_NAME("Sine Wave", SINE_WAVE),
    PASULI_SET_NAME("Cosine Wave", COSINE_WAVE),
    PASULI_SET_NAME("Spiral Wave", SPIRAL_WAVE),
    PASULI_SET_NAME("Bell", BELL),
    PASULI_SET_NAME("Bell Polar", BELL_POLAR),
    PASULI_SET_NAME("Bell Wave", BELL_WAVE),
    PASULI_SET_NAME("Soucoupoid", SOUCOUPOID),
    PASULI_SET_NAME("Enneper Surface Polar", ENNEPER_SURFACE_POLAR),
    PASULI_SET_NAME("Spinner", SPINNER),
    PASULI_SET_NAME("Fresnel", FRESNEL),
    PASULI_SET_NAME("Trefoil Knots2", TREFOIL_KNOTS2),
    PASULI_SET_NAME("Bow Curve", BOW_CURVE),
    PASULI_SET_NAME("Triple Cork Screw 1", TRIPLE_CORK_SCREW1),
    PASULI_SET_NAME("Triple Cork Screw 2", TRIPLE_CORK_SCREW2),
    PASULI_SET_NAME("Triple Cork Screw 3", TRIPLE_CORK_SCREW3),
    PASULI_SET_NAME("Bicorn Surface", BICORN_SURFACE),
    PASULI_SET_NAME("Piriform Surface", PIRIFORM_SURFACE),
    PASULI_SET_NAME("Kappa Surface", KAPPA_SURFACE),
    PASULI_SET_NAME("Bullet Nose", BULLET_NOSE),
    PASULI_SET_NAME("Sievert Surface", SIEVERT_SURFACE),
    PASULI_SET_NAME("Cosine Surface2", COSINE_SURFACE2),
#endif
#if (COMPILE_NAMES_CYLINDER != 0)
    PASULI_SET_NAME("Cylinder", CYLINDER),
    PASULI_SET_NAME("Epizykloid Cylinder", EPIZYKLOID_CYLINDER),
    PASULI_SET_NAME("Hypozykloid Cylinder", HYPOZYKLOID_CYLINDER),
    PASULI_SET_NAME("Lemniskate Cylinder", LEMNISKATE_CYLINDER),
    PASULI_SET_NAME("Strophoide Cylinder", STROPHOIDE_CYLINDER),
    PASULI_SET_NAME("Zissoide Cylinder", ZISSOIDE_CYLINDER),
    PASULI_SET_NAME("Versiera Agnesi Cylinder", VERSIERA_AGNESI_CYLINDER),
    PASULI_SET_NAME("Gauss Cylinder", GAUSS_CYLINDER),
#endif
#if (COMPILE_NAMES_FRUITS != 0)
    PASULI_SET_NAME("Kidney Surface", KIDNEY_SURFACE),
    PASULI_SET_NAME("Apple Surface", APPLE_SURFACE),
    PASULI_SET_NAME("Apple Surface (2.nd Version)", APPLE2_SURFACE),
    PASULI_SET_NAME("Lemon Surface", LEMON_SURFACE),
#endif
#if (COMPILE_NAMES_SHELLS != 0)
    PASULI_SET_NAME("Cornucopia", CORNUCOPIA),
    PASULI_SET_NAME("Snail", SNAIL),
    PASULI_SET_NAME("Seashell", SEASHELL),
    PASULI_SET_NAME("Snail surface", SNAIL_SURFACE),
    PASULI_SET_NAME("Snails", SNAILS),
    PASULI_SET_NAME("Pseudoheliceras Subcatenatum", PSEUDOHELICERAS_SUBCATENATUM),
    PASULI_SET_NAME("Astroceras", ASTROCERAS),
    PASULI_SET_NAME("Bellerophina", BELLEROPHINA),
    PASULI_SET_NAME("Euhoplites", EUHOPLITES),
    PASULI_SET_NAME("Nautilus", NAUTILUS),
    PASULI_SET_NAME("Natica Stellata", NATICA_STELLATA),
    PASULI_SET_NAME("Mya Arenaria", MYA_ARENARIA),
#endif
#if (COMPILE_NAMES_SPHERE != 0)
    PASULI_SET_NAME("Sphere", SPHERE),
    PASULI_SET_NAME("Ellipsoid", ELLIPSOID),
    PASULI_SET_NAME("SphereV", SPHERE_V),
    PASULI_SET_NAME("SphereUV", SPHERE_UV),
    PASULI_SET_NAME("Pseudo-Sphere", PSEUDOSPHERE),
    PASULI_SET_NAME("Twisted Sphere", TWISTED_SPHERE),
    PASULI_SET_NAME("Open Sphere", OPEN_SPHERE),
    PASULI_SET_NAME("Wave Sphere", WAVE_SPHERE),
#endif
#if (COMPILE_NAMES_SPIRAL != 0)
    PASULI_SET_NAME("Archimedic Spiral", ARCHIMEDIC_SPIRAL),
    PASULI_SET_NAME("Hyperbolic Spiral", HYPERBOLIC_SPIRAL),
    PASULI_SET_NAME("Fermat Spiral", FERMAT_SPIRAL),
    PASULI_SET_NAME("Tanh Spiral", TANH_SPIRAL),
    PASULI_SET_NAME("Logarithmic Spiral", LOG_SPIRAL),
#endif
#if (COMPILE_NAMES_TORUS != 0)
    PASULI_SET_NAME("Torus", TORUS),
    PASULI_SET_NAME("Eight Torus", EIGHT_TORUS),
    PASULI_SET_NAME("Elliptic Torus", ELLIPTIC_TORUS),
    PASULI_SET_NAME("Saddle Torus", SADDLE_TORUS),
    PASULI_SET_NAME("Antisymmetric Torus", ANTISYMMETRIC_TORUS),
    PASULI_SET_NAME("Twisted Eight Torus", TWISTED_EIGHT_TORUS),
    PASULI_SET_NAME("Umbillic Torus", UMBILLIC_TORUS),
    PASULI_SET_NAME("Wave Torus", WAVE_TORUS),
    PASULI_SET_NAME("Braided Torus", BRAIDED_TORUS),
    PASULI_SET_NAME("Limpet Torus", LIMPET_TORUS),
    PASULI_SET_NAME("Strangled Torus", STRANGLED_TORUS),
    PASULI_SET_NAME("Astroid Torus", ASTROID_TORUS),
    PASULI_SET_NAME("Tricuspoid Torus 1", TRICUSPOID_TORUS_1),
    PASULI_SET_NAME("Tricuspoid Torus 2", TRICUSPOID_TORUS_2),
    PASULI_SET_NAME("Nethroid Torus 1", NETHROID_TORUS_1),
    PASULI_SET_NAME("Nethroid Torus 2", NETHROID_TORUS_2),
    PASULI_SET_NAME("Lemniskate Torus 1", LEMNISKATE_TORUS_1),
    PASULI_SET_NAME("Lemniskate Torus 2", LEMNISKATE_TORUS_2),
    PASULI_SET_NAME("Epizykloid Torus 1", EPIZYKLOID_TORUS_1),
    PASULI_SET_NAME("Epizykloid Torus 2", EPIZYKLOID_TORUS_2),
    PASULI_SET_NAME("Hypozykloid Torus 1", HYPOZYKLOID_TORUS_1),
    PASULI_SET_NAME("Hypozykloid Torus 2", HYPOZYKLOID_TORUS_2),
    PASULI_SET_NAME("Piriform Torus 1", PIRIFORM_TORUS_1),
    PASULI_SET_NAME("Piriform Torus 2", PIRIFORM_TORUS_2),
    PASULI_SET_NAME("Bicorn Torus 1", BICORN_TORUS_1),
    PASULI_SET_NAME("Bicorn Torus 2", BICORN_TORUS_2),
    PASULI_SET_NAME("Cardioid Torus 1", CARDIOID_TORUS_1),
    PASULI_SET_NAME("Cardioid Torus 2", CARDIOID_TORUS_2),
    PASULI_SET_NAME("Cassinian Oval Torus 1", CASSINIAN_OVAL_TORUS_1),
    PASULI_SET_NAME("Cassinian Oval Torus 2", CASSINIAN_OVAL_TORUS_2),
    PASULI_SET_NAME("Gerono-Lemniskate Torus 1", GERONO_LEMNISKATE_TORUS_1),
    PASULI_SET_NAME("Gerono-Lemniskate Torus 2", GERONO_LEMNISKATE_TORUS_2),
    PASULI_SET_NAME("Curly Torus 1", CURLY_TORUS_1),
    PASULI_SET_NAME("Curly Torus 2", CURLY_TORUS_2),
    PASULI_SET_NAME("Spiral Torus", SPIRAL_TORUS),
    PASULI_SET_NAME("Torus Knot", TORUS_KNOT),
    PASULI_SET_NAME("Gear Torus", GEAR_TORUS)
#endif
};

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
