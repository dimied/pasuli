#ifndef __PASULI_COMPILATION_CONFIGURATION_FILE__
#define __PASULI_COMPILATION_CONFIGURATION_FILE__

// For MS compiler
#define PASULI_COMPILER_MSVC 1
// For GCC compiler collection
#define PASULI_COMPILER_GCC 2

#include "../pasuli_custom_cfg.h"

// Used compiler
#ifndef PASULI_COMPILER
#define PASULI_COMPILER PASULI_COMPILER_GCC
#endif

//Debuging
#ifndef PASULI_DEBUG_MODE
#define PASULI_DEBUG_MODE 1
#endif

// If not 0, then the ID will be assigned in the evaluation function
#ifndef USE_ID_IN_PASULI_FUNCTION
#define USE_ID_IN_PASULI_FUNCTION 0
#endif

#ifndef PASULIOBJECT_POS
// Positions & Normal vectors are commonly used
#define PASULIOBJECT_POS 1
#endif

#ifndef PASULIOBJECT_UD
#define PASULIOBJECT_UD 0
#endif

#ifndef PASULIOBJECT_VD
#define PASULIOBJECT_VD 0
#endif

#ifndef PASULIOBJECT_N
// Positions & Normal vectors are commonly used
#define PASULIOBJECT_N 1
#endif

#ifndef PASULIOBJECT_UUD
#define PASULIOBJECT_UUD 0
#endif

#ifndef PASULIOBJECT_UVD
#define PASULIOBJECT_UVD 0
#endif

#ifndef PASULIOBJECT_VVD
#define PASULIOBJECT_VVD 0
#endif

/////////////////////////
/////////////////////////
#ifndef COMPILE_DEF_DESC_SURFACES
#define COMPILE_DEF_DESC_SURFACES 1
#endif

#ifndef COMPILE_DESC_SURFACES
#define COMPILE_DESC_SURFACES 1
#endif

#ifndef COMPILE_DEF_DESC_CYLINDER
#define COMPILE_DEF_DESC_CYLINDER 1
#endif

#ifndef COMPILE_DESC_CYLINDER
#define COMPILE_DESC_CYLINDER 1
#endif

#ifndef COMPILE_DEF_DESC_FRUITS
#define COMPILE_DEF_DESC_FRUITS 1
#endif

#ifndef COMPILE_DESC_FRUITS
#define COMPILE_DESC_FRUITS 1
#endif

#ifndef COMPILE_DEF_DESC_SHELLS
#define COMPILE_DEF_DESC_SHELLS 1
#endif

#ifndef COMPILE_DESC_SHELLS
#define COMPILE_DESC_SHELLS 1
#endif

#ifndef COMPILE_DEF_DESC_SPHERE
#define COMPILE_DEF_DESC_SPHERE 1
#endif

#ifndef COMPILE_DESC_SPHERE
#define COMPILE_DESC_SPHERE 1
#endif

#ifndef COMPILE_DEF_DESC_SPIRAL
#define COMPILE_DEF_DESC_SPIRAL 1
#endif

#ifndef COMPILE_DESC_SPIRAL
#define COMPILE_DESC_SPIRAL 1
#endif

#ifndef COMPILE_DEF_DESC_TORUS
#define COMPILE_DEF_DESC_TORUS 1
#endif

#ifndef COMPILE_DESC_TORUS
#define COMPILE_DESC_TORUS 1
#endif

//////////////////////////////////////////
#ifndef USE_USE_PLANE
#define USE_USE_PLANE 1
#endif

#ifndef USE_USE_ASTROIDAL_ELLIPSOID
#define USE_USE_ASTROIDAL_ELLIPSOID 1
#endif

#ifndef USE_USE_BOHEMIAN_DOME_SURFACE
#define USE_USE_BOHEMIAN_DOME_SURFACE 1
#endif

#ifndef USE_USE_BOYS_SURFACE
#define USE_USE_BOYS_SURFACE 1
#endif

#ifndef USE_USE_CROSS_CUP
#define USE_USE_CROSS_CUP 1
#endif

#ifndef USE_USE_DINI_SURFACE
#define USE_USE_DINI_SURFACE 1
#endif

#ifndef USE_USE_ENNEPER_SURFACE
#define USE_USE_ENNEPER_SURFACE 1
#endif

#ifndef USE_USE_HANDKERCHIEF
#define USE_USE_HANDKERCHIEF 1
#endif

#ifndef USE_USE_KLEIN_BOTTLE_SURFACE
#define USE_USE_KLEIN_BOTTLE_SURFACE 1
#endif

#ifndef USE_USE_MOEBIUS_BAND
#define USE_USE_MOEBIUS_BAND 1
#endif

#ifndef USE_USE_MOEBIUS_BAND2
#define USE_USE_MOEBIUS_BAND2 1
#endif

#ifndef USE_USE_MONKEY_SADDLE
#define USE_USE_MONKEY_SADDLE 1
#endif

#ifndef USE_USE_PLUECKER_CONOID
#define USE_USE_PLUECKER_CONOID 1
#endif

#ifndef USE_USE_ROMAN_SURFACE
#define USE_USE_ROMAN_SURFACE 1
#endif

#ifndef USE_USE_SHOE_SURFACE
#define USE_USE_SHOE_SURFACE 1
#endif

#ifndef USE_USE_SINE_SURFACE
#define USE_USE_SINE_SURFACE 1
#endif

#ifndef USE_USE_STEINBACH_SCREW
#define USE_USE_STEINBACH_SCREW 1
#endif

#ifndef USE_USE_WHITNEY_UMBRELLA
#define USE_USE_WHITNEY_UMBRELLA 1
#endif

#ifndef USE_USE_CATENOID
#define USE_USE_CATENOID 1
#endif

#ifndef USE_USE_HELICOID
#define USE_USE_HELICOID 1
#endif

#ifndef USE_USE_PARABOLOID
#define USE_USE_PARABOLOID 1
#endif

#ifndef USE_USE_HYPERBOLIC_HELICOID
#define USE_USE_HYPERBOLIC_HELICOID 1
#endif

#ifndef USE_USE_FUNNEL
#define USE_USE_FUNNEL 1
#endif

#ifndef USE_USE_TRACTROID
#define USE_USE_TRACTROID 1
#endif

#ifndef USE_USE_CATALANS_SURFACE
#define USE_USE_CATALANS_SURFACE 1
#endif

#ifndef USE_USE_HYPERBOLOID
#define USE_USE_HYPERBOLOID 1
#endif

#ifndef USE_USE_HENNEBERGS_SURFACE
#define USE_USE_HENNEBERGS_SURFACE 1
#endif

#ifndef USE_USE_SWALLOW_SURFACE
#define USE_USE_SWALLOW_SURFACE 1
#endif

#ifndef USE_USE_WALLIS_CONICAL_SURFACE
#define USE_USE_WALLIS_CONICAL_SURFACE 1
#endif

#ifndef USE_USE_MAEDERS_OWL
#define USE_USE_MAEDERS_OWL 1
#endif

#ifndef USE_USE_RICHMOND_SURFACE
#define USE_USE_RICHMOND_SURFACE 1
#endif

#ifndef USE_USE_SCHERK_SURFACE
#define USE_USE_SCHERK_SURFACE 1
#endif

#ifndef USE_USE_COSINE_SURFACE
#define USE_USE_COSINE_SURFACE 1
#endif

#ifndef USE_USE_EIGHT_SURFACE
#define USE_USE_EIGHT_SURFACE 1
#endif

#ifndef USE_USE_JET_SURFACE
#define USE_USE_JET_SURFACE 1
#endif

#ifndef USE_USE_DROP
#define USE_USE_DROP 1
#endif

#ifndef USE_USE_TRIAXIAL_TEARDROP
#define USE_USE_TRIAXIAL_TEARDROP 1
#endif

#ifndef USE_USE_PILLOW_SHAPE
#define USE_USE_PILLOW_SHAPE 1
#endif

#ifndef USE_USE_FISH_SURFACE
#define USE_USE_FISH_SURFACE 1
#endif

#ifndef USE_USE_HORN
#define USE_USE_HORN 1
#endif

#ifndef USE_USE_BENT_HORNS
#define USE_USE_BENT_HORNS 1
#endif


#ifndef USE_USE_BOURS_MINIMAL_SURFACE
#define USE_USE_BOURS_MINIMAL_SURFACE 1
#endif

#ifndef USE_USE_SINE_CUBE
#define USE_USE_SINE_CUBE 1
#endif

#ifndef USE_USE_EGG_SURFACE
#define USE_USE_EGG_SURFACE 1
#endif

#ifndef USE_USE_WREATH
#define USE_USE_WREATH 1
#endif


#ifndef USE_USE_HYPERBOLIC_OCTAHEDRON
#define USE_USE_HYPERBOLIC_OCTAHEDRON 1
#endif

#ifndef USE_USE_PSEUDO_CROSS_CAP
#define USE_USE_PSEUDO_CROSS_CAP 1
#endif

#ifndef USE_USE_CRESENT
#define USE_USE_CRESENT 1
#endif

#ifndef USE_USE_STILETTO_SURFACE
#define USE_USE_STILETTO_SURFACE 1
#endif

#ifndef USE_USE_KUENS_SURFACE
#define USE_USE_KUENS_SURFACE 1
#endif

#ifndef USE_USE_TREFOIL_KNOTS
#define USE_USE_TREFOIL_KNOTS 1
#endif

#ifndef USE_USE_TRANGULOID_TREFOIL
#define USE_USE_TRANGULOID_TREFOIL 1
#endif

#ifndef USE_USE_CROWN
#define USE_USE_CROWN 1
#endif

#ifndef USE_USE_TWISTED_PIPE_SURFACE
#define USE_USE_TWISTED_PIPE_SURFACE 1
#endif

#ifndef USE_USE_LOOP
#define USE_USE_LOOP 1
#endif

#ifndef USE_USE_DUPIN_CYCLIDE
#define USE_USE_DUPIN_CYCLIDE 1
#endif

#ifndef USE_USE_GUIMARD_SURFACE
#define USE_USE_GUIMARD_SURFACE 1
#endif

#ifndef USE_USE_MENNS_SURFACE
#define USE_USE_MENNS_SURFACE 1
#endif

#ifndef USE_USE_MILK_BAG
#define USE_USE_MILK_BAG 1
#endif

#ifndef USE_USE_SADDLE_TORUS
#define USE_USE_SADDLE_TORUS 1
#endif

#ifndef USE_USE_TRIAXIAL_TRITORUS
#define USE_USE_TRIAXIAL_TRITORUS 1
#endif

#ifndef USE_USE_VERRILL_SURFACE
#define USE_USE_VERRILL_SURFACE 1
#endif

#ifndef USE_USE_ZINDLERS_CONOID
#define USE_USE_ZINDLERS_CONOID 1
#endif

#ifndef USE_USE_FOLIUM
#define USE_USE_FOLIUM 1
#endif

#ifndef USE_USE_LEMNISCAPE
#define USE_USE_LEMNISCAPE 1
#endif

#ifndef USE_USE_TRIPLE_POINT_TWIST
#define USE_USE_TRIPLE_POINT_TWIST 1
#endif

#ifndef USE_USE_TRASHCAN
#define USE_USE_TRASHCAN 1
#endif

#ifndef USE_USE_SPRING1
#define USE_USE_SPRING1 1
#endif

#ifndef USE_USE_SPRING2
#define USE_USE_SPRING2 1
#endif

#ifndef USE_USE_CONE
#define USE_USE_CONE 1
#endif

#ifndef USE_USE_EGG
#define USE_USE_EGG 1
#endif

#ifndef USE_USE_ISOLATOR
#define USE_USE_ISOLATOR 1
#endif

#ifndef USE_USE_HYPERBOLIC_PARABOLOID
#define USE_USE_HYPERBOLIC_PARABOLOID 1
#endif

#ifndef USE_USE_DROP_SURFACE
#define USE_USE_DROP_SURFACE 1
#endif

#ifndef USE_USE_FACING_SNAIL
#define USE_USE_FACING_SNAIL 1
#endif

#ifndef USE_USE_PAPER_BAG
#define USE_USE_PAPER_BAG 1
#endif

#ifndef USE_USE_JEENER_KLEIN_SURFACE
#define USE_USE_JEENER_KLEIN_SURFACE 1
#endif

#ifndef USE_USE_BONAN_JEENER_KLEIN_SURFACE
#define USE_USE_BONAN_JEENER_KLEIN_SURFACE 1
#endif

#ifndef USE_USE_KLEIN_CYCLOID
#define USE_USE_KLEIN_CYCLOID 1
#endif

#ifndef USE_USE_DOUBLE_CONE
#define USE_USE_DOUBLE_CONE 1
#endif

#ifndef USE_USE_HOLE_DISC
#define USE_USE_HOLE_DISC 1
#endif

#ifndef USE_USE_PISOT_TRIAXIAL
#define USE_USE_PISOT_TRIAXIAL 1
#endif

#ifndef USE_USE_TRIAXIAL_HEXATORUS
#define USE_USE_TRIAXIAL_HEXATORUS 1
#endif

#ifndef USE_USE_TWISTED_HEART
#define USE_USE_TWISTED_HEART 1
#endif

#ifndef USE_USE_HOLE_DISCUS
#define USE_USE_HOLE_DISCUS 1
#endif

#ifndef USE_USE_DISC
#define USE_USE_DISC 1
#endif

#ifndef USE_USE_WAVES
#define USE_USE_WAVES 1
#endif

#ifndef USE_USE_SINE_WAVE
#define USE_USE_SINE_WAVE 1
#endif

#ifndef USE_USE_COSINE_WAVE
#define USE_USE_COSINE_WAVE 1
#endif

#ifndef USE_USE_SPIRAL_WAVE
#define USE_USE_SPIRAL_WAVE 1
#endif

#ifndef USE_USE_BELL
#define USE_USE_BELL 1
#endif

#ifndef USE_USE_BELL_POLAR
#define USE_USE_BELL_POLAR 1
#endif

#ifndef USE_USE_BELL_WAVE
#define USE_USE_BELL_WAVE 1
#endif

#ifndef USE_USE_SOUCOUPOID
#define USE_USE_SOUCOUPOID 1
#endif

#ifndef USE_USE_ENNEPER_SURFACE_POLAR
#define USE_USE_ENNEPER_SURFACE_POLAR 1
#endif

#ifndef USE_USE_SINE_CONE
#define USE_USE_SINE_CONE 1
#endif

#ifndef USE_USE_SPINNER
#define USE_USE_SPINNER 1
#endif

#ifndef USE_USE_FRESNEL
#define USE_USE_FRESNEL 1
#endif

#ifndef USE_USE_TREFOIL_KNOTS2
#define USE_USE_TREFOIL_KNOTS2 1
#endif

#ifndef USE_USE_BOW_CURVE
#define USE_USE_BOW_CURVE 1
#endif

#ifndef USE_USE_TRIPLE_CORK_SCREW1
#define USE_USE_TRIPLE_CORK_SCREW1 1
#endif

#ifndef USE_USE_TRIPLE_CORK_SCREW2
#define USE_USE_TRIPLE_CORK_SCREW2 1
#endif

#ifndef USE_USE_TRIPLE_CORK_SCREW3
#define USE_USE_TRIPLE_CORK_SCREW3 1
#endif

#ifndef USE_USE_BICORN_SURFACE
#define USE_USE_BICORN_SURFACE 1
#endif

#ifndef USE_USE_PIRIFORM_SURFACE
#define USE_USE_PIRIFORM_SURFACE 1
#endif

#ifndef USE_USE_KAPPA_SURFACE
#define USE_USE_KAPPA_SURFACE 1
#endif

#ifndef USE_USE_BULLET_NOSE
#define USE_USE_BULLET_NOSE 1
#endif

#ifndef USE_USE_SIEVERT_SURFACE
#define USE_USE_SIEVERT_SURFACE 1
#endif

#ifndef USE_USE_COSINE_SURFACE2
#define USE_USE_COSINE_SURFACE2 1
#endif


//CYLINDER SURFACES
#ifndef USE_USE_CYLINDER
#define USE_USE_CYLINDER 1
#endif

#ifndef USE_USE_EPIZYKLOID_CYLINDER
#define USE_USE_EPIZYKLOID_CYLINDER 1
#endif

#ifndef USE_USE_HYPOZYKLOID_CYLINDER
#define USE_USE_HYPOZYKLOID_CYLINDER 1
#endif

#ifndef USE_USE_LEMNISKATE_CYLINDER
#define USE_USE_LEMNISKATE_CYLINDER 1
#endif

#ifndef USE_USE_STROPHOIDE_CYLINDER
#define USE_USE_STROPHOIDE_CYLINDER 1
#endif

#ifndef USE_USE_ZISSOIDE_CYLINDER
#define USE_USE_ZISSOIDE_CYLINDER 1
#endif

#ifndef USE_USE_VERSIERA_AGNESI_CYLINDER
#define USE_USE_VERSIERA_AGNESI_CYLINDER 1
#endif

#ifndef USE_USE_GAUSS_CYLINDER
#define USE_USE_GAUSS_CYLINDER 1
#endif


//FRUITS SURFACES
#ifndef USE_USE_KIDNEY_SURFACE
#define USE_USE_KIDNEY_SURFACE 1
#endif

#ifndef USE_USE_APPLE_SURFACE
#define USE_USE_APPLE_SURFACE 1
#endif

#ifndef USE_USE_APPLE2_SURFACE
#define USE_USE_APPLE2_SURFACE 1
#endif

#ifndef USE_USE_LEMON_SURFACE
#define USE_USE_LEMON_SURFACE 1
#endif


// Shells
#ifndef USE_USE_CORNUCOPIA
#define USE_USE_CORNUCOPIA 1
#endif

#ifndef USE_USE_SNAIL
#define USE_USE_SNAIL 1
#endif

#ifndef USE_USE_SEASHELL
#define USE_USE_SEASHELL 1
#endif

#ifndef USE_USE_SNAIL_SURFACE
#define USE_USE_SNAIL_SURFACE 1
#endif

#ifndef USE_USE_SNAILS
#define USE_USE_SNAILS 1
#endif

#ifndef USE_USE_PSEUDOHELICERAS_SUBCATENATUM
#define USE_USE_PSEUDOHELICERAS_SUBCATENATUM 1
#endif

#ifndef USE_USE_ASTROCERAS
#define USE_USE_ASTROCERAS 1
#endif

#ifndef USE_USE_BELLEROPHINA
#define USE_USE_BELLEROPHINA 1
#endif

#ifndef USE_USE_EUHOPLITES
#define USE_USE_EUHOPLITES 1
#endif

#ifndef USE_USE_NAUTILUS
#define USE_USE_NAUTILUS 1
#endif

#ifndef USE_USE_NATICA_STELLATA
#define USE_USE_NATICA_STELLATA 1
#endif

#ifndef USE_USE_MYA_ARENARIA
#define USE_USE_MYA_ARENARIA 1
#endif


// Sphere surfaces
#ifndef USE_USE_SPHERE
#define USE_USE_SPHERE 1
#endif

#ifndef USE_USE_ELLIPSOID
#define USE_USE_ELLIPSOID 1
#endif

#ifndef USE_USE_SPHERE_V
#define USE_USE_SPHERE_V 1
#endif

#ifndef USE_USE_SPHERE_UV
#define USE_USE_SPHERE_UV 1
#endif

#ifndef USE_USE_PSEUDOSPHERE
#define USE_USE_PSEUDOSPHERE 1
#endif

#ifndef USE_USE_TWISTED_SPHERE
#define USE_USE_TWISTED_SPHERE 1
#endif

#ifndef USE_USE_OPEN_SPHERE
#define USE_USE_OPEN_SPHERE 1
#endif

#ifndef USE_USE_WAVE_SPHERE
#define USE_USE_WAVE_SPHERE 1
#endif


// Spiral surfaces
#ifndef USE_USE_ARCHIMEDIC_SPIRAL
#define USE_USE_ARCHIMEDIC_SPIRAL 1
#endif

#ifndef USE_USE_HYPERBOLIC_SPIRAL
#define USE_USE_HYPERBOLIC_SPIRAL 1
#endif

#ifndef USE_USE_FERMAT_SPIRAL
#define USE_USE_FERMAT_SPIRAL 1
#endif

#ifndef USE_USE_TANH_SPIRAL
#define USE_USE_TANH_SPIRAL 1
#endif

#ifndef USE_USE_LOG_SPIRAL
#define USE_USE_LOG_SPIRAL 1
#endif


// TORUS SURFACES
#ifndef USE_USE_TORUS
#define USE_USE_TORUS 1
#endif

#ifndef USE_USE_EIGHT_TORUS
#define USE_USE_EIGHT_TORUS 1
#endif

#ifndef USE_USE_ELLIPTIC_TORUS
#define USE_USE_ELLIPTIC_TORUS 1
#endif

#ifndef USE_USE_SADDLE_TORUS
#define USE_USE_SADDLE_TORUS 1
#endif

#ifndef USE_USE_ANTISYMMETRIC_TORUS
#define USE_USE_ANTISYMMETRIC_TORUS 1
#endif

#ifndef USE_USE_TWISTED_EIGHT_TORUS
#define USE_USE_TWISTED_EIGHT_TORUS 1
#endif

#ifndef USE_USE_UMBILLIC_TORUS
#define USE_USE_UMBILLIC_TORUS 1
#endif

#ifndef USE_USE_BRAIDED_TORUS
#define USE_USE_BRAIDED_TORUS 1
#endif

#ifndef USE_USE_LIMPET_TORUS
#define USE_USE_LIMPET_TORUS 1
#endif

#ifndef USE_USE_STRANGLED_TORUS
#define USE_USE_STRANGLED_TORUS 1
#endif

#ifndef USE_USE_ASTROID_TORUS
#define USE_USE_ASTROID_TORUS 1
#endif

#ifndef USE_USE_TRICUSPOID_TORUS_1
#define USE_USE_TRICUSPOID_TORUS_1 1
#endif

#ifndef USE_USE_TRICUSPOID_TORUS_2
#define USE_USE_TRICUSPOID_TORUS_2 1
#endif

#ifndef USE_USE_NEPHROID_TORUS_1
#define USE_USE_NEPHROID_TORUS_1 1
#endif

#ifndef USE_USE_NEPHROID_TORUS_2
#define USE_USE_NEPHROID_TORUS_2 1
#endif

#ifndef USE_USE_LEMNISKATE_TORUS_1
#define USE_USE_LEMNISKATE_TORUS_1 1
#endif

#ifndef USE_USE_LEMNISKATE_TORUS_2
#define USE_USE_LEMNISKATE_TORUS_2 1
#endif

#ifndef USE_USE_EPIZYKLOID_TORUS_1
#define USE_USE_EPIZYKLOID_TORUS_1 1
#endif

#ifndef USE_USE_EPIZYKLOID_TORUS_2
#define USE_USE_EPIZYKLOID_TORUS_2 1
#endif

#ifndef USE_USE_HYPOZYKLOID_TORUS_1
#define USE_USE_HYPOZYKLOID_TORUS_1 1
#endif

#ifndef USE_USE_HYPOZYKLOID_TORUS_2
#define USE_USE_HYPOZYKLOID_TORUS_2 1
#endif

#ifndef USE_USE_PIRIFORM_TORUS_1
#define USE_USE_PIRIFORM_TORUS_1 1
#endif

#ifndef USE_USE_PIRIFORM_TORUS_2
#define USE_USE_PIRIFORM_TORUS_2 1
#endif

#ifndef USE_USE_BICORN_TORUS_1
#define USE_USE_BICORN_TORUS_1 1
#endif

#ifndef USE_USE_BICORN_TORUS_2
#define USE_USE_BICORN_TORUS_2 1
#endif

#ifndef USE_USE_CARDIOID_TORUS_1
#define USE_USE_CARDIOID_TORUS_1 1
#endif

#ifndef USE_USE_CARDIOID_TORUS_2
#define USE_USE_CARDIOID_TORUS_2 1
#endif

#ifndef USE_USE_CASSINIAN_OVAL_TORUS_1
#define USE_USE_CASSINIAN_OVAL_TORUS_1 1
#endif

#ifndef USE_USE_CASSINIAN_OVAL_TORUS_2
#define USE_USE_CASSINIAN_OVAL_TORUS_2 1
#endif

#ifndef USE_USE_GERONO_LEMNISKATE_TORUS_1
#define USE_USE_GERONO_LEMNISKATE_TORUS_1 1
#endif

#ifndef USE_USE_GERONO_LEMNISKATE_TORUS_2
#define USE_USE_GERONO_LEMNISKATE_TORUS_2 1
#endif

#ifndef USE_USE_CURLY_TORUS_1
#define USE_USE_CURLY_TORUS_1 1
#endif

#ifndef USE_USE_CURLY_TORUS_2
#define USE_USE_CURLY_TORUS_2 1
#endif

#ifndef USE_USE_SPIRAL_TORUS
#define USE_USE_SPIRAL_TORUS 1
#endif

#ifndef USE_USE_TORUS_KNOT
#define USE_USE_TORUS_KNOT 1
#endif

#ifndef USE_USE_GEAR_TORUS
#define USE_USE_GEAR_TORUS 1
#endif

#ifndef USE_USE_WAVE_TORUS
#define USE_USE_WAVE_TORUS 1
#endif


// New Ones
#ifndef USE_USE_ASTROIDAL_ELLIPSOID
#define USE_USE_ASTROIDAL_ELLIPSOID 1
#endif

#ifndef USE_USE_PEANO_SURFACE
#define USE_USE_PEANO_SURFACE 1
#endif

#ifndef USE_USE_PEANO_SURFACE2
#define USE_USE_PEANO_SURFACE2 1
#endif

#ifndef USE_USE_UMBRELLA_SURFACE
#define USE_USE_UMBRELLA_SURFACE 1
#endif

#ifndef USE_USE_VASE_HEAD
#define USE_USE_VASE_HEAD 1
#endif

#ifndef USE_USE_PLUECKER_CONOID2
#define USE_USE_PLUECKER_CONOID2 1
#endif

#ifndef USE_USE_MONKEY_SADDLE2
#define USE_USE_MONKEY_SADDLE2 1
#endif

#ifndef USE_USE_BOYS_SURFACE2
#define USE_USE_BOYS_SURFACE2 1
#endif

#ifndef USE_USE_SKIDAN_RULED_SURFACE
#define USE_USE_SKIDAN_RULED_SURFACE 1
#endif

#ifndef USE_USE_SCHERK_SURFACE2
#define USE_USE_SCHERK_SURFACE2 1
#endif

#ifndef USE_USE_CATALANS_SURFACE2
#define USE_USE_CATALANS_SURFACE2 1
#endif

#ifndef USE_USE_WRINKLE_SPHERE
#define USE_USE_WRINKLE_SPHERE 1
#endif

#ifndef USE_USE_WRINKLE_SPHERE2
#define USE_USE_WRINKLE_SPHERE2 1
#endif

#ifndef USE_USE_SNAIL2
#define USE_USE_SNAIL2 1
#endif

#ifndef USE_USE_KLEIN_BOTTLE_SURFACE2
#define USE_USE_KLEIN_BOTTLE_SURFACE2 1
#endif

#ifndef USE_USE_FOUR_INTERSECTING_DISCS
#define USE_USE_FOUR_INTERSECTING_DISCS 1
#endif

#ifndef USE_USE_KAI_WING_FUNG_SURFACE1
#define USE_USE_KAI_WING_FUNG_SURFACE1 1
#endif

#ifndef USE_USE_KAI_WING_FUNG_SURFACE2
#define USE_USE_KAI_WING_FUNG_SURFACE2 1
#endif

#ifndef USE_USE_RICHMOND_SURFACE2
#define USE_USE_RICHMOND_SURFACE2 1
#endif

#ifndef USE_USE_RICHMOND_SURFACE3
#define USE_USE_RICHMOND_SURFACE3 1
#endif

#ifndef USE_USE_ENNEPER_SURFACE2
#define USE_USE_ENNEPER_SURFACE2 1
#endif

#ifndef USE_USE_ENNEPER_SURFACE3
#define USE_USE_ENNEPER_SURFACE3 1
#endif

#ifndef USE_USE_WAVY_ENNEPER_SURFACE
#define USE_USE_WAVY_ENNEPER_SURFACE 1
#endif

#ifndef USE_USE_TWISTED_RIBBON
#define USE_USE_TWISTED_RIBBON 1
#endif

#ifndef USE_USE_PLANAR_ENNEPER_SURFACE
#define USE_USE_PLANAR_ENNEPER_SURFACE 1
#endif

#ifndef USE_USE_CAYLEY_SURFACE
#define USE_USE_CAYLEY_SURFACE 1
#endif

#ifndef USE_USE_ROMAN_SURFACE2
#define USE_USE_ROMAN_SURFACE2 1
#endif

#ifndef USE_USE_MOEBIUS_BAND3
#define USE_USE_MOEBIUS_BAND3 1
#endif

#ifndef USE_USE_VIRICH_CYCLIC_SURFACE
#define USE_USE_VIRICH_CYCLIC_SURFACE 1
#endif

#ifndef USE_USE_PSEUDODEVELOPABLE_HELICOID
#define USE_USE_PSEUDODEVELOPABLE_HELICOID 1
#endif

#ifndef USE_USE_CROSS_CUP2
#define USE_USE_CROSS_CUP2 1
#endif

#ifndef USE_USE_CROSS_CUP3
#define USE_USE_CROSS_CUP3 1
#endif

#ifndef USE_USE_CUSPIDAL_BUTTERFLY
#define USE_USE_CUSPIDAL_BUTTERFLY 1
#endif

#ifndef USE_USE_CUSPIDAL_EDGE
#define USE_USE_CUSPIDAL_EDGE 1
#endif

#ifndef USE_USE_CUSPIDAL_LIPS
#define USE_USE_CUSPIDAL_LIPS 1
#endif

#ifndef USE_USE_CUSPIDAL_BEAKS
#define USE_USE_CUSPIDAL_BEAKS 1
#endif

#ifndef USE_USE_DING_DONG_SURFACE
#define USE_USE_DING_DONG_SURFACE 1
#endif

#ifndef USE_USE_TOOTH_SURFACE
#define USE_USE_TOOTH_SURFACE 1
#endif

#ifndef USE_USE_LAWSON_BOTTLE
#define USE_USE_LAWSON_BOTTLE 1
#endif

#ifndef USE_USE_GOBLET
#define USE_USE_GOBLET 1
#endif

#ifndef USE_USE_BOWTIE
#define USE_USE_BOWTIE 1
#endif

#ifndef USE_USE_HORNLET_SURFACE
#define USE_USE_HORNLET_SURFACE 1
#endif

#ifndef USE_USE_BALLS_CYLINDROID
#define USE_USE_BALLS_CYLINDROID 1
#endif

#ifndef USE_USE_EPITROCHOIDAL_SURFACE
#define USE_USE_EPITROCHOIDAL_SURFACE 1
#endif

#ifndef USE_USE_MORIN_SURFACE
#define USE_USE_MORIN_SURFACE 1
#endif

#ifndef USE_USE_CROSSED_TROUGH_SURFACE
#define USE_USE_CROSSED_TROUGH_SURFACE 1
#endif

#ifndef USE_USE_HECTOR_GUINARDS_SURFACE
#define USE_USE_HECTOR_GUINARDS_SURFACE 1
#endif

#ifndef USE_USE_AGNESI_CURL
#define USE_USE_AGNESI_CURL 1
#endif

#ifndef USE_USE_SPINNING_TOP1
#define USE_USE_SPINNING_TOP1 1
#endif

#ifndef USE_USE_SPINNING_TOP2
#define USE_USE_SPINNING_TOP2 1
#endif

#ifndef USE_USE_KISS_SURFACE
#define USE_USE_KISS_SURFACE 1
#endif

#ifndef USE_USE_NEOVIUS_SURFACE
#define USE_USE_NEOVIUS_SURFACE 1
#endif

#ifndef USE_USE_RULED_ROTOR_CYLINDROID
#define USE_USE_RULED_ROTOR_CYLINDROID 1
#endif

#ifndef USE_USE_PARABOLIC_HUMMING_TOP
#define USE_USE_PARABOLIC_HUMMING_TOP 1
#endif

#endif
