#ifndef __PASULI_SHELLS__
#define __PASULI_SHELLS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"

#include "astroceras.h"
#include "bellerophina.h"
#include "cornucopia.h"
#include "euhoplites.h"
#include "mya_arenaria.h"
#include "natica_stellata.h"
#include "nautilus.h"
#include "pseudoheliceras_subcatenatum.h"
#include "seashell.h"
#include "snail.h"
#include "snail_surface.h"
#include "snails.h"

#if (COMPILE_DEF_DESC_SHELLS != 0)
extern PaSuLiDefDesc pslddCornucopia;
extern PaSuLiDefDesc pslddSnail;
extern PaSuLiDefDesc pslddSeashell;
extern PaSuLiDefDesc pslddSnailSurface;
extern PaSuLiDefDesc pslddSnails;
extern PaSuLiDefDesc pslddPseudohelicerasSubcatenatum;
extern PaSuLiDefDesc pslddAstroceras;
extern PaSuLiDefDesc pslddBellerophina;
extern PaSuLiDefDesc pslddEuhoplites;
extern PaSuLiDefDesc pslddNautilus;
extern PaSuLiDefDesc pslddNaticaStellata;
extern PaSuLiDefDesc pslddMyaArenaria;
#endif

#endif
