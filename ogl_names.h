#ifndef __OGL_NAMES__
#define __OGL_NAMES__

#define VOID_TYPE 1
#define FLOAT_TYPE 2
#define CLAMPF_TYPE 2
#define BITMASK_TYPE 3
#define BITFIELD_TYPE 3
#define UINT_TYPE 4
#define BOOLEAN_TYPE 5
#define ENUM_TYPE 6
#define INT_TYPE 7
#define SIZEI_TYPE 7
#define USHORT_TYPE 8
#define CLAMPD_TYPE 9
#define DOUBLE_TYPE 9
#define SHORT_TYPE 10
#define BYTE_TYPE 11
#define UBYTE_TYPE 12

#define VOID_PTR_TYPE 0x10
#define BOOLEAN_PTR_TYPE 0x11
#define UBYTE_PTR_TYPE 0x12
#define DOUBLE_PTR_TYPE 0x13
#define FLOAT_PTR_TYPE 0x14
#define CLAMPF_PTR_TYPE 0x14
#define INT_PTR_TYPE 0x15
#define SHORT_PTR_TYPE 0x16
#define BYTE_PTR_TYPE 0x17
#define USHORT_PTR_TYPE 0x18
#define UINT_PTR_TYPE 0x19
#define VOID_VOID_PTR_TYPE 0x1A

#define OGL_FUNC_DESC_NAME_LENGTH 32
#define OGL_FUNC_DESC_PARAMS_COUNT 12

typedef struct _OGL_FUNC_DESC
{
    char name[OGL_FUNC_DESC_NAME_LENGTH];
    unsigned char params[OGL_FUNC_DESC_PARAMS_COUNT];
    unsigned char rType;
    unsigned char paramCount;
    unsigned char version;
} OGL_FUNC_DESC;

#define FUNC_DECL0(VT, NAME) \
    {                        \
        rType : VT,          \
        name : NAME,         \
        paramCount : 0,      \
        version : 1          \
    }

#define V11_FUNC_DECL0(VT, NAME) \
    {                            \
        rType : VT,              \
        name : NAME,             \
        paramCount : 0,          \
        version : 11             \
    }

#define FUNC_DECL1(VT, NAME, P1) \
    {                            \
        rType : VT,              \
        name : NAME,             \
        paramCount : 1,          \
        params : {P1},           \
        version : 1              \
    }

#define V11_FUNC_DECL1(VT, NAME, P1) \
    {                                \
        rType : VT,                  \
        name : NAME,                 \
        paramCount : 1,              \
        params : {P1},               \
        version : 11                 \
    }

#define V13_FUNC_DECL1(VT, NAME, P1) \
    {                                \
        rType : VT,                  \
        name : NAME,                 \
        paramCount : 1,              \
        params : {P1},               \
        version : 13                 \
    }

#define FUNC_DECL2(VT, NAME, P1, P2) \
    {                                \
        rType : VT,                  \
        name : NAME,                 \
        paramCount : 3,              \
        params : {P1, P2},           \
        version : 1                  \
    }

#define V11_FUNC_DECL2(VT, NAME, P1, P2) \
    {                                    \
        rType : VT,                      \
        name : NAME,                     \
        paramCount : 3,                  \
        params : {P1, P2},               \
        version : 11                     \
    }

#define V13_FUNC_DECL2(VT, NAME, P1, P2) \
    {                                    \
        rType : VT,                      \
        name : NAME,                     \
        paramCount : 3,                  \
        params : {P1, P2},               \
        version : 13                     \
    }

#define FUNC_DECL3(VT, NAME, P1, P2, P3) \
    {                                    \
        rType : VT,                      \
        name : NAME,                     \
        paramCount : 3,                  \
        params : {P1, P2, P3},           \
        version : 1                      \
    }

#define V11_FUNC_DECL3(VT, NAME, P1, P2, P3) \
    {                                        \
        rType : VT,                          \
        name : NAME,                         \
        paramCount : 3,                      \
        params : {P1, P2, P3},               \
        version : 11                         \
    }

#define V13_FUNC_DECL3(VT, NAME, P1, P2, P3) \
    {                                        \
        rType : VT,                          \
        name : NAME,                         \
        paramCount : 3,                      \
        params : {P1, P2, P3},               \
        version : 13                         \
    }

#define FUNC_DECL4(VT, NAME, P1, P2, P3, P4) \
    {                                        \
        rType : VT,                          \
        name : NAME,                         \
        paramCount : 4,                      \
        params : {P1, P2, P3, P4},           \
        version : 1                          \
    }

#define FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) \
    {                                            \
        rType : VT,                              \
        name : NAME,                             \
        paramCount : 5,                          \
        params : {P1, P2, P3, P4, P5},           \
        version : 1                              \
    }

#define V11_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) \
    {                                                \
        rType : VT,                                  \
        name : NAME,                                 \
        paramCount : 5,                              \
        params : {P1, P2, P3, P4, P5},               \
        version : 1                                  \
    }

#define FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) \
    {                                                \
        rType : VT,                                  \
        name : NAME,                                 \
        paramCount : 6,                              \
        params : {P1, P2, P3, P4, P5, P6},           \
        version : 1                                  \
    }

#define V11_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) \
    {                                                    \
        rType : VT,                                      \
        name : NAME,                                     \
        paramCount : 6,                                  \
        params : {P1, P2, P3, P4, P5, P6},               \
        version : 11                                     \
    }

#define V12_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) \
    {                                                    \
        rType : VT,                                      \
        name : NAME,                                     \
        paramCount : 6,                                  \
        params : {P1, P2, P3, P4, P5, P6},               \
        version : 12                                     \
    }

#define FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) \
    {                                                    \
        rType : VT,                                      \
        name : NAME,                                     \
        paramCount : 7,                                  \
        params : {P1, P2, P3, P4, P5, P6, P7},           \
        version : 1                                      \
    }

#define V13_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) \
    {                                                    \
        rType : VT,                                      \
        name : NAME,                                     \
        paramCount : 7,                                  \
        params : {P1, P2, P3, P4, P5, P6, P7},           \
        version : 13                                      \
    }

#define V11_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) \
    {                                                        \
        rType : VT,                                          \
        name : NAME,                                         \
        paramCount : 7,                                      \
        params : {P1, P2, P3, P4, P5, P6, P7},               \
        version : 11                                         \
    }

#define FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) \
    {                                                        \
        rType : VT,                                          \
        name : NAME,                                         \
        paramCount : 8,                                      \
        params : {P1, P2, P3, P4, P5, P6, P7, P8},           \
        version : 1                                          \
    }

#define V11_FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) \
    {                                                            \
        rType : VT,                                              \
        name : NAME,                                             \
        paramCount : 8,                                          \
        params : {P1, P2, P3, P4, P5, P6, P7, P8},               \
        version : 11                                             \
    }

#define V13_FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) \
    {                                                            \
        rType : VT,                                              \
        name : NAME,                                             \
        paramCount : 8,                                          \
        params : {P1, P2, P3, P4, P5, P6, P7, P8},               \
        version : 13                                             \
    }

#define FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) \
    {                                                            \
        rType : VT,                                              \
        name : NAME,                                             \
        paramCount : 9,                                          \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9},           \
        version : 1                                              \
    }

#define V11_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) \
    {                                                                \
        rType : VT,                                                  \
        name : NAME,                                                 \
        paramCount : 9,                                              \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9},               \
        version : 11                                                 \
    }

#define V13_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) \
    {                                                                \
        rType : VT,                                                  \
        name : NAME,                                                 \
        paramCount : 9,                                              \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9},               \
        version : 13                                                 \
    }

#define FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) \
    {                                                                  \
        rType : VT,                                                    \
        name : NAME,                                                   \
        paramCount : 10,                                               \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10},            \
        version : 1                                                    \
    }

#define V11_FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) \
    {                                                                      \
        rType : VT,                                                        \
        name : NAME,                                                       \
        paramCount : 10,                                                   \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10},                \
        version : 11                                                       \
    }

#define V12_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) \
    {                                                                     \
        rType : VT,                                                       \
        name : NAME,                                                      \
        paramCount : 9,                                                  \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9},                \
        version : 12                                                      \
    }

#define V12_FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA) \
    {                                                                     \
        rType : VT,                                                       \
        name : NAME,                                                      \
        paramCount : 10,                                                  \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA},                \
        version : 12                                                      \
    }

#define V12_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA,PB) \
    {                                                                     \
        rType : VT,                                                       \
        name : NAME,                                                      \
        paramCount : 11,                                                  \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA,PB},                \
        version : 12                                                      \
    }

#define V13_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA,PB) \
    {                                                                     \
        rType : VT,                                                       \
        name : NAME,                                                      \
        paramCount : 11,                                                  \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA,PB},                \
        version : 13                                                      \
    }

#define V12_FUNC_DECL12(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB, PC) \
    {                                                                             \
        rType : VT,                                                               \
        name : NAME,                                                              \
        paramCount : 12,                                                          \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB, PC},                \
        version : 12                                                              \
    }

//
OGL_FUNC_DESC *getNames(int *pSize);

#endif