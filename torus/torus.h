#ifndef __PARAMETRIC_SURFACE_LIBRARY_TORUS_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_TORUS_DECLARATIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"
#include "torus_desc.h"
#include <math.h>

#include "antisym_torus.h"
#include "umbillictorus.h"
#include "wavetorus.h"

#if (USE_TORUS != 0)
void Torus(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
extern char *descTorus;
#endif

#ifndef __PASULI_EIGHT_TORUS__
#define __PASULI_EIGHT_TORUS__

#include "../pasuli_defs.h"

extern char *descEightTorus;

#if (USE_EIGHT_TORUS != 0)
void EightTorus(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_ELLIPTIC_TORUS__
#define __PASULI_ELLIPTIC_TORUS__

#include "../pasuli_defs.h"

extern char *descEllipticTorus;

#if (USE_ELLIPTIC_TORUS != 0)
void EllipticTorus(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SADDLE_TORUS__
#define __PASULI_SADDLE_TORUS__

#include "../pasuli_defs.h"

extern char *descSaddleTorus;

#if (USE_SADDLE_TORUS != 0)
void SaddleTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TWISTED_EIGHT_TORUS__
#define __PASULI_TWISTED_EIGHT_TORUS__

#include "../pasuli_defs.h"

extern char *descTwistedEightTorus;

#if (USE_TWISTED_EIGHT_TORUS != 0)
void TwistedEightTorus(pasuli_vartype u,
					   pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BRAIDED_TORUS__
#define __PASULI_BRAIDED_TORUS__

#include "../pasuli_defs.h"

extern char *descBraidedTorus;

#if (USE_BRAIDED_TORUS != 0)
void BraidedTorus(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_LIMPET_TORUS__
#define __PASULI_LIMPET_TORUS__

#include "../pasuli_defs.h"

extern char *descLimpetTorus;

#if (USE_LIMPET_TORUS != 0)
void LimpetTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_STRANGLED_TORUS__
#define __PASULI_STRANGLED_TORUS__

#include "../pasuli_defs.h"

extern char *descStrangledTorus;

#if (USE_STRANGLED_TORUS != 0)
void StrangledTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_ASTROID_TORUS__
#define __PASULI_ASTROID_TORUS__

#include "../pasuli_defs.h"

extern char *descAstroidTorus;

#if (USE_ASTROID_TORUS != 0)
void AstroidTorus(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRICUSPOID_TORUS_1__
#define __PASULI_TRICUSPOID_TORUS_1__

#include "../pasuli_defs.h"

extern char *descTricuspoidTorus1;

#if (USE_TRICUSPOID_TORUS_1 != 0)
void TricuspoidTorus1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TRICUSPOID_TORUS_2__
#define __PASULI_TRICUSPOID_TORUS_2__

#include "../pasuli_defs.h"

extern char *descTricuspoidTorus2;

#if (USE_TRICUSPOID_TORUS_2 != 0)
void TricuspoidTorus2(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_NETHROID_TORUS_1__
#define __PASULI_NETHROID_TORUS_1__

#include "../pasuli_defs.h"

extern char *descNethroidTorus1;

#if (USE_NETHROID_TORUS_1 != 0)
void NethroidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_NETHROID_TORUS_2__
#define __PASULI_NETHROID_TORUS_2__

#include "../pasuli_defs.h"

extern char *descNethroidTorus2;

#if (USE_NETHROID_TORUS_2 != 0)
void NethroidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_LEMNISKATE_TORUS_1__
#define __PASULI_LEMNISKATE_TORUS_1__

#include "../pasuli_defs.h"

extern char *descLemniskateTorus1;

#if (USE_LEMNISKATE_TORUS_1 != 0)
void LemniskateTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif


#ifndef __PASULI_LEMNISKATE_TORUS_2__
#define __PASULI_LEMNISKATE_TORUS_2__

#include "../pasuli_defs.h"

extern char *descLemniskateTorus2;

#if (USE_LEMNISKATE_TORUS_2 != 0)
void LemniskateTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_EPIZYKLOID_TORUS_1__
#define __PASULI_EPIZYKLOID_TORUS_1__

#include "../pasuli_defs.h"

extern char *descEpizykloidTorus1;

#if (USE_EPIZYKLOID_TORUS_1 != 0)
void EpizykloidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_EPIZYKLOID_TORUS_2__
#define __PASULI_EPIZYKLOID_TORUS_2__

#include "../pasuli_defs.h"

extern char *descEpizykloidTorus2;

#if (USE_EPIZYKLOID_TORUS_2 != 0)
void EpizykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HYPOZYKLOID_TORUS_1__
#define __PASULI_HYPOZYKLOID_TORUS_1__

#include "../pasuli_defs.h"

extern char *descHypozykloidTorus1;

#if (USE_HYPOZYKLOID_TORUS_1 != 0)
void HypozykloidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_HYPOZYKLOID_TORUS_2__
#define __PASULI_HYPOZYKLOID_TORUS_2__

#include "../pasuli_defs.h"

extern char *descHypozykloidTorus2;

#if (USE_HYPOZYKLOID_TORUS_2 != 0)
void HypozykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PIRIFORM_TORUS_1__
#define __PASULI_PIRIFORM_TORUS_1__

#include "../pasuli_defs.h"

extern char *descPiriformTorus1;

#if (USE_PIRIFORM_TORUS_1 != 0)
void PiriformTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_PIRIFORM_TORUS_2__
#define __PASULI_PIRIFORM_TORUS_2__

#include "../pasuli_defs.h"

extern char *descPiriformTorus2;

#if (USE_PIRIFORM_TORUS_2 != 0)
void PiriformTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BICORN_TORUS_1__
#define __PASULI_BICORN_TORUS_1__

#include "../pasuli_defs.h"

extern char *descBicornTorus1;

#if (USE_BICORN_TORUS_1 != 0)
void BicornTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_BICORN_TORUS_2__
#define __PASULI_BICORN_TORUS_2__

#include "../pasuli_defs.h"

extern char *descBicornTorus2;

#if (USE_BICORN_TORUS_2 != 0)
void BicornTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CARDIOID_TORUS_1__
#define __PASULI_CARDIOID_TORUS_1__

#include "../pasuli_defs.h"

extern char *descCardioidTorus1;

#if (USE_CARDIOID_TORUS_1 != 0)
void CardioidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CARDIOID_TORUS_2__
#define __PASULI_CARDIOID_TORUS_2__

#include "../pasuli_defs.h"

extern char *descCardioidTorus2;

#if (USE_CARDIOID_TORUS_2 != 0)
void CardioidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CASSINIAN_OVAL_TORUS_1__
#define __PASULI_CASSINIAN_OVAL_TORUS_1__

#include "../pasuli_defs.h"

extern char *descCassinianOvalTorus1;

#if (USE_CASSINIAN_OVAL_TORUS_1 != 0)
void CassinianOvalTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CASSINIAN_OVAL_TORUS_2__
#define __PASULI_CASSINIAN_OVAL_TORUS_2__

#include "../pasuli_defs.h"

extern char *descCassinianOvalTorus2;

#if (USE_CASSINIAN_OVAL_TORUS_2 != 0)
void CassinianOvalTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_GERONO_LEMNISKATE_TORUS_1__
#define __PASULI_GERONO_LEMNISKATE_TORUS_1__

#include "../pasuli_defs.h"

extern char *descGeronoLemniskateTorus1;

#if (USE_GERONO_LEMNISKATE_TORUS_1 != 0)
void GeronoLemniskateTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_GERONO_LEMNISKATE_TORUS_2__
#define __PASULI_GERONO_LEMNISKATE_TORUS_2__

#include "../pasuli_defs.h"

extern char *descGeronoLemniskateTorus2;

#if (USE_GERONO_LEMNISKATE_TORUS_2 != 0)
void GeronoLemniskateTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CURLY_TORUS_1__
#define __PASULI_CURLY_TORUS_1__

#include "../pasuli_defs.h"

extern char *descCurlyTorus1;

#if (USE_CURLY_TORUS_1 != 0)
void CurlyTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_CURLY_TORUS_2__
#define __PASULI_CURLY_TORUS_2__

#include "../pasuli_defs.h"

extern char *descCurlyTorus2;

#if (USE_CURLY_TORUS_2 != 0)
void CurlyTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_SPIRAL_TORUS__
#define __PASULI_SPIRAL_TORUS__

#include "../pasuli_defs.h"

extern char *descSpiralTorus;

#if (USE_SPIRAL_TORUS != 0)
void SpiralTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_TORUS_KNOT__
#define __PASULI_TORUS_KNOT__

#include "../pasuli_defs.h"

extern char *descTorusKnot;

#if (USE_TORUS_KNOT != 0)
void TorusKnot(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif

#ifndef __PASULI_GEAR_TORUS__
#define __PASULI_GEAR_TORUS__

#include "../pasuli_defs.h"

extern char *descGearTorus;

#if (USE_GEAR_TORUS != 0)
void GearTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif



#endif
