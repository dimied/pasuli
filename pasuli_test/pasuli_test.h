#ifndef __PASULI_TEST_TYPES_INCLUDED__
#define __PASULI_TEST_TYPES_INCLUDED__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

typedef struct _PaSuLiTestDesc
{
    char *surfaceName;
    PaSuLiFuncPtr pasuliFunc;
} PaSuLiTestDesc;

#define PASULI_TEST(NAME, FUNC_PTR) {NAME, FUNC_PTR}

#endif