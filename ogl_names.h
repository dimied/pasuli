#ifndef __OGL_NAMES__
#define __OGL_NAMES__

#define VOID_TYPE 1
#define BOOLEAN_TYPE 2
#define BITFIELD_TYPE 3

#define BYTE_TYPE 4
#define UBYTE_TYPE 5

#define SHORT_TYPE 6
#define USHORT_TYPE 7

#define INT_TYPE 8
#define UINT_TYPE 9

#define SIZEI_TYPE 10

#define ENUM_TYPE 11

#define FLOAT_TYPE 12
#define CLAMPF_TYPE 13

#define DOUBLE_TYPE 14
#define CLAMPD_TYPE 15

#define PTR_TYPE_OF(X) (0x20 | X)

#define VOID_PTR_TYPE PTR_TYPE_OF(VOID_TYPE)
#define BOOLEAN_PTR_TYPE PTR_TYPE_OF(BOOLEAN_TYPE)

#define BITFIELD_PTR_TYPE PTR_TYPE_OF(BITFIELD_TYPE)

#define BYTE_PTR_TYPE PTR_TYPE_OF(BYTE_TYPE)
#define UBYTE_PTR_TYPE PTR_TYPE_OF(UBYTE_TYPE)

#define SHORT_PTR_TYPE PTR_TYPE_OF(SHORT_TYPE)
#define USHORT_PTR_TYPE PTR_TYPE_OF(USHORT_TYPE)

#define INT_PTR_TYPE PTR_TYPE_OF(INT_TYPE)
#define UINT_PTR_TYPE PTR_TYPE_OF(UINT_TYPE)

#define SIZEI_PTR_TYPE PTR_TYPE_OF(SIZEI_TYPE)
#define ENUM_PTR_TYPE PTR_TYPE_OF(ENUM_TYPE)

#define CLAMPF_PTR_TYPE PTR_TYPE_OF(CLAMPF_TYPE)
#define FLOAT_PTR_TYPE PTR_TYPE_OF(FLOAT_TYPE)
#define FLOAT_MATRIX_TYPE FLOAT_PTR_TYPE

#define DOUBLE_PTR_TYPE PTR_TYPE_OF(DOUBLE_TYPE)
#define DOUBLE_MATRIX_TYPE DOUBLE_PTR_TYPE

#define VOID_VOID_PTR_TYPE 0x30
#define BYTE_BYTE_PTR_TYPE 0x31

//
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

#define V_FUNC_DECL0(V, VT, NAME) \
    {                             \
        rType : VT,               \
        name : NAME,              \
        paramCount : 0,           \
        version : V               \
    }

#define FUNC_DECL0(VT, NAME) V_FUNC_DECL0(1, VT, NAME)
#define V11_FUNC_DECL0(VT, NAME) V_FUNC_DECL0(11, VT, NAME)
#define V20_FUNC_DECL0(VT, NAME) V_FUNC_DECL0(20, VT, NAME)

#define V_FUNC_DECL1(V, VT, NAME, P1) \
    {                                 \
        rType : VT,                   \
        name : NAME,                  \
        paramCount : 1,               \
        params : {P1},                \
        version : V                   \
    }

#define FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(1, VT, NAME, P1)
#define V11_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(11, VT, NAME, P1)
#define V13_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(13, VT, NAME, P1)
#define V14_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(14, VT, NAME, P1)
#define V15_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(15, VT, NAME, P1)
#define V20_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(20, VT, NAME, P1)
// #define V30_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(30, VT, NAME, P1)

#define V_FUNC_DECL2(V, VT, NAME, P1, P2) \
    {                                     \
        rType : VT,                       \
        name : NAME,                      \
        paramCount : 2,                   \
        params : {P1, P2},                \
        version : V                       \
    }

#define FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(1, VT, NAME, P1, P2)
#define V11_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(11, VT, NAME, P1, P2)
#define V13_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(13, VT, NAME, P1, P2)
#define V14_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(14, VT, NAME, P1, P2)
#define V15_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(15, VT, NAME, P1, P2)
#define V20_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(20, VT, NAME, P1, P2)
#define V30_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(30, VT, NAME, P1, P2)

#define V_FUNC_DECL3(V, VT, NAME, P1, P2, P3) \
    {                                         \
        rType : VT,                           \
        name : NAME,                          \
        paramCount : 3,                       \
        params : {P1, P2, P3},                \
        version : V                           \
    }

#define FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(1, VT, NAME, P1, P2, P3)
#define V11_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(11, VT, NAME, P1, P2, P3)
#define V13_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(13, VT, NAME, P1, P2, P3)
#define V15_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(15, VT, NAME, P1, P2, P3)
#define V20_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(20, VT, NAME, P1, P2, P3)

#define V_FUNC_DECL4(V, VT, NAME, P1, P2, P3, P4) \
    {                                             \
        rType : VT,                               \
        name : NAME,                              \
        paramCount : 4,                           \
        params : {P1, P2, P3, P4},                \
        version : V                               \
    }

#define FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(1, VT, NAME, P1, P2, P3, P4)
#define V11_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(11, VT, NAME, P1, P2, P3, P4)
#define V13_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(13, VT, NAME, P1, P2, P3, P4)
#define V14_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(14, VT, NAME, P1, P2, P3, P4)
#define V15_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(15, VT, NAME, P1, P2, P3, P4)
#define V20_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(20, VT, NAME, P1, P2, P3, P4)
#define V21_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(21, VT, NAME, P1, P2, P3, P4)

#define V_FUNC_DECL5(V, VT, NAME, P1, P2, P3, P4, P5) \
    {                                                 \
        rType : VT,                                   \
        name : NAME,                                  \
        paramCount : 5,                               \
        params : {P1, P2, P3, P4, P5},                \
        version : V                                   \
    }

#define FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(1, VT, NAME, P1, P2, P3, P4, P5)
#define V11_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(11, VT, NAME, P1, P2, P3, P4, P5)
#define V13_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(13, VT, NAME, P1, P2, P3, P4, P5)
#define V14_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(14, VT, NAME, P1, P2, P3, P4, P5)
#define V20_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(20, VT, NAME, P1, P2, P3, P4, P5)

#define V_FUNC_DECL6(V, VT, NAME, P1, P2, P3, P4, P5, P6) \
    {                                                     \
        rType : VT,                                       \
        name : NAME,                                      \
        paramCount : 6,                                   \
        params : {P1, P2, P3, P4, P5, P6},                \
        version : V                                       \
    }

#define FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(1, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V11_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(11, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V12_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(12, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V20_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(20, VT, NAME, P1, P2, P3, P4, P5, P6)

#define V_FUNC_DECL7(V,VT, NAME, P1, P2, P3, P4, P5, P6, P7) \
    {                                                    \
        rType : VT,                                      \
        name : NAME,                                     \
        paramCount : 7,                                  \
        params : {P1, P2, P3, P4, P5, P6, P7},           \
        version : V                                      \
    }

#define FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(1,VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V11_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(11,VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V13_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(13,VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V20_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(20,VT, NAME, P1, P2, P3, P4, P5, P6, P7)


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
    {                                                                \
        rType : VT,                                                  \
        name : NAME,                                                 \
        paramCount : 9,                                              \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9},               \
        version : 12                                                 \
    }

#define V12_FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA) \
    {                                                                     \
        rType : VT,                                                       \
        name : NAME,                                                      \
        paramCount : 10,                                                  \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA},                \
        version : 12                                                      \
    }

#define V12_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB) \
    {                                                                         \
        rType : VT,                                                           \
        name : NAME,                                                          \
        paramCount : 11,                                                      \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB},                \
        version : 12                                                          \
    }

#define V13_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB) \
    {                                                                         \
        rType : VT,                                                           \
        name : NAME,                                                          \
        paramCount : 11,                                                      \
        params : {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB},                \
        version : 13                                                          \
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