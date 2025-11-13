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
    unsigned char rType;
    char name[OGL_FUNC_DESC_NAME_LENGTH];
    unsigned char paramCount;
    unsigned char params[OGL_FUNC_DESC_PARAMS_COUNT];
    unsigned char version;
} OGL_FUNC_DESC;

#define V_FUNC_DECL0(V, VT, NAME) \
    {                             \
        VT,                       \
        NAME,                     \
        0,                        \
        {0},                      \
        V}

#define FUNC_DECL0(VT, NAME) V_FUNC_DECL0(1, VT, NAME)
#define V11_FUNC_DECL0(VT, NAME) V_FUNC_DECL0(11, VT, NAME)
#define V20_FUNC_DECL0(VT, NAME) V_FUNC_DECL0(20, VT, NAME)

#define V_FUNC_DECL1(V, VT, NAME, P1) \
    {                                 \
        VT,                           \
        NAME,                         \
        1,                            \
        {P1},                         \
        V}

#define FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(1, VT, NAME, P1)
#define V11_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(11, VT, NAME, P1)
#define V13_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(13, VT, NAME, P1)
#define V14_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(14, VT, NAME, P1)
#define V15_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(15, VT, NAME, P1)
#define V20_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(20, VT, NAME, P1)
// #define V30_FUNC_DECL1(VT, NAME, P1) V_FUNC_DECL1(30, VT, NAME, P1)

#define V_FUNC_DECL2(V, VT, NAME, P1, P2) \
    {                                     \
        VT,                               \
        NAME,                             \
        2,                                \
        {P1, P2},                         \
        V}

#define FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(1, VT, NAME, P1, P2)
#define V11_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(11, VT, NAME, P1, P2)
#define V13_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(13, VT, NAME, P1, P2)
#define V14_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(14, VT, NAME, P1, P2)
#define V15_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(15, VT, NAME, P1, P2)
#define V20_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(20, VT, NAME, P1, P2)
#define V30_FUNC_DECL2(VT, NAME, P1, P2) V_FUNC_DECL2(30, VT, NAME, P1, P2)

#define V_FUNC_DECL3(V, VT, NAME, P1, P2, P3) \
    {                                         \
        VT,                                   \
        NAME,                                 \
        3,                                    \
        {P1, P2, P3},                         \
        V}

#define FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(1, VT, NAME, P1, P2, P3)
#define V11_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(11, VT, NAME, P1, P2, P3)
#define V13_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(13, VT, NAME, P1, P2, P3)
#define V15_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(15, VT, NAME, P1, P2, P3)
#define V20_FUNC_DECL3(VT, NAME, P1, P2, P3) V_FUNC_DECL3(20, VT, NAME, P1, P2, P3)

#define V_FUNC_DECL4(V, VT, NAME, P1, P2, P3, P4) \
    {                                             \
        VT,                                       \
        NAME,                                     \
        4,                                        \
        {P1, P2, P3, P4},                         \
        V}

#define FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(1, VT, NAME, P1, P2, P3, P4)
#define V11_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(11, VT, NAME, P1, P2, P3, P4)
#define V13_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(13, VT, NAME, P1, P2, P3, P4)
#define V14_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(14, VT, NAME, P1, P2, P3, P4)
#define V15_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(15, VT, NAME, P1, P2, P3, P4)
#define V20_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(20, VT, NAME, P1, P2, P3, P4)
#define V21_FUNC_DECL4(VT, NAME, P1, P2, P3, P4) V_FUNC_DECL4(21, VT, NAME, P1, P2, P3, P4)

#define V_FUNC_DECL5(V, VT, NAME, P1, P2, P3, P4, P5) \
    {                                                 \
        VT,                                           \
        NAME,                                         \
        5,                                            \
        {P1, P2, P3, P4, P5},                         \
        V}

#define FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(1, VT, NAME, P1, P2, P3, P4, P5)
#define V11_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(11, VT, NAME, P1, P2, P3, P4, P5)
#define V13_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(13, VT, NAME, P1, P2, P3, P4, P5)
#define V14_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(14, VT, NAME, P1, P2, P3, P4, P5)
#define V20_FUNC_DECL5(VT, NAME, P1, P2, P3, P4, P5) V_FUNC_DECL5(20, VT, NAME, P1, P2, P3, P4, P5)

#define V_FUNC_DECL6(V, VT, NAME, P1, P2, P3, P4, P5, P6) \
    {                                                     \
        VT,                                               \
        NAME,                                             \
        6,                                                \
        {P1, P2, P3, P4, P5, P6},                         \
        V}

#define FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(1, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V11_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(11, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V12_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(12, VT, NAME, P1, P2, P3, P4, P5, P6)
#define V20_FUNC_DECL6(VT, NAME, P1, P2, P3, P4, P5, P6) V_FUNC_DECL6(20, VT, NAME, P1, P2, P3, P4, P5, P6)

#define V_FUNC_DECL7(V, VT, NAME, P1, P2, P3, P4, P5, P6, P7) \
    {                                                         \
        VT,                                                   \
        NAME,                                                 \
        7,                                                    \
        {P1, P2, P3, P4, P5, P6, P7},                         \
        V}

#define FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(1, VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V11_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(11, VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V13_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(13, VT, NAME, P1, P2, P3, P4, P5, P6, P7)
#define V20_FUNC_DECL7(VT, NAME, P1, P2, P3, P4, P5, P6, P7) V_FUNC_DECL7(20, VT, NAME, P1, P2, P3, P4, P5, P6, P7)

#define V_FUNC_DECL8(V,VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) \
    {                                                          \
        VT,                                                    \
        NAME,                                                  \
        8,                                                     \
        {P1, P2, P3, P4, P5, P6, P7, P8},                      \
        V}

#define FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) V_FUNC_DECL8(1, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8)
#define V11_FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) V_FUNC_DECL8(11, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8)
#define V13_FUNC_DECL8(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8) V_FUNC_DECL8(13, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8)

#define V_FUNC_DECL9(V, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) \
    {                                                                 \
        VT,                                                           \
        NAME,                                                         \
        9,                                                            \
        {P1, P2, P3, P4, P5, P6, P7, P8, P9},                         \
        V}

#define FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) V_FUNC_DECL9(1, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9)
#define V11_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) V_FUNC_DECL9(11, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9)
#define V12_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) V_FUNC_DECL9(12, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9)
#define V13_FUNC_DECL9(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9) V_FUNC_DECL9(13, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9)

#define V_FUNC_DECL10(V, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) \
    {                                                                       \
        VT,                                                                 \
        NAME,                                                               \
        10,                                                                 \
        {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10},                          \
        V}

#define FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) V_FUNC_DECL10(1, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)
#define V11_FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) V_FUNC_DECL10(11, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)
#define V12_FUNC_DECL10(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) V_FUNC_DECL10(12, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)

#define V_FUNC_DECL11(V, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB) \
    {                                                                          \
        VT,                                                                    \
        NAME,                                                                  \
        11,                                                                    \
        {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB},                          \
        V}

#define V12_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB) V_FUNC_DECL11(12, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB)
#define V13_FUNC_DECL11(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB) V_FUNC_DECL11(13, VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB)

#define V12_FUNC_DECL12(VT, NAME, P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB, PC) \
    {                                                                             \
        VT,                                                                       \
        NAME,                                                                     \
        12,                                                                       \
        {P1, P2, P3, P4, P5, P6, P7, P8, P9, PA, PB, PC},                         \
        12}

//
OGL_FUNC_DESC *getNames(int *pSize);

#endif