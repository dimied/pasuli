#ifndef __MYINT_TEST_DATA__
#define __MYINT_TEST_DATA__

#define NUM_MYINT_TESTS 2000

typedef struct
{
    const char *ptrA;
    const char *ptrB;
    const char *ptrC;
    char signA;
    char signB;
    char signC;
    unsigned char *aBytes;
    unsigned char *bBytes;
    unsigned char *cBytes;
    unsigned int numBytesA;
    unsigned int numBytesB;
    unsigned int numBytesC;
    const char *ptrR;
    unsigned char *rBytes;
    unsigned int numBytesR;
} IntTest;

#define USE_INT_TEST_INITIALIZER_DEFAULT 1

#ifdef IS_PEDANTIC_GCC
#define USE_INT_TEST_INITIALIZER 0
#else 
#define USE_INT_TEST_INITIALIZER USE_INT_TEST_INITIALIZER_DEFAULT
#endif

#if USE_INT_TEST_INITIALIZER

#define INIT_INT_TEST(PTRA, PTRB, PTRC, SIGNA, SIGNB, SIGNC, ABYTES, BBYTES, CBYTES, NBYTESA, NBYTESB, NBYTESC) \
    {                                                                                                           \
        ptrA : PTRA,                                                                                            \
        ptrB : PTRB,                                                                                            \
        ptrC : PTRC,                                                                                            \
        signA : SIGNA,                                                                                          \
        signB : SIGNB,                                                                                          \
        signC : SIGNC,                                                                                          \
        aBytes : ABYTES,                                                                                        \
        bBytes : BBYTES,                                                                                        \
        cBytes : CBYTES,                                                                                        \
        numBytesA : NBYTESA,                                                                                    \
        numBytesB : NBYTESB,                                                                                    \
        numBytesC : NBYTESC,                                                                                    \
        0,                                                                                                      \
        0,                                                                                                      \
        0                                                                                                       \
    }

#define INIT_INT_TEST_DIV(PTRA, PTRB, PTRC, SIGNA, SIGNB, SIGNC, ABYTES, BBYTES, CBYTES, NBYTESA, NBYTESB, NBYTESC, PTRR, RBYTES, NBYTESR) \
    {                                                                                                                                      \
        ptrA : PTRA,                                                                                                                       \
        ptrB : PTRB,                                                                                                                       \
        ptrC : PTRC,                                                                                                                       \
        signA : SIGNA,                                                                                                                     \
        signB : SIGNB,                                                                                                                     \
        signC : SIGNC,                                                                                                                     \
        aBytes : ABYTES,                                                                                                                   \
        bBytes : BBYTES,                                                                                                                   \
        cBytes : CBYTES,                                                                                                                   \
        numBytesA : NBYTESA,                                                                                                               \
        numBytesB : NBYTESB,                                                                                                               \
        numBytesC : NBYTESC,                                                                                                               \
        ptrR : PTRR,                                                                                                                       \
        rBytes : RBYTES,                                                                                                                   \
        numBytesC : NBYTESR                                                                                                                \
    }
#else
#define INIT_INT_TEST(PTRA, PTRB, PTRC, SIGNA, SIGNB, SIGNC, ABYTES, BBYTES, CBYTES, NBYTESA, NBYTESB, NBYTESC) \
    {                                                                                                           \
        PTRA,                                                                                                   \
        PTRB,                                                                                                   \
        PTRC,                                                                                                   \
        SIGNA,                                                                                                  \
        SIGNB,                                                                                                  \
        SIGNC,                                                                                                  \
        ABYTES,                                                                                                 \
        BBYTES,                                                                                                 \
        CBYTES,                                                                                                 \
        NBYTESA,                                                                                                \
        NBYTESB,                                                                                                \
        NBYTESC, 0, 0, 0}

#define INIT_INT_TEST_DIV(PTRA, PTRB, PTRC, SIGNA, SIGNB, SIGNC, ABYTES, BBYTES, CBYTES, NBYTESA, NBYTESB, NBYTESC, PTRR, RBYTES, NBYTESR) \
    {                                                                                                                                      \
        PTRA,                                                                                                                              \
        PTRB,                                                                                                                              \
        PTRC,                                                                                                                              \
        SIGNA,                                                                                                                             \
        SIGNB,                                                                                                                             \
        SIGNC,                                                                                                                             \
        ABYTES,                                                                                                                            \
        BBYTES,                                                                                                                            \
        CBYTES,                                                                                                                            \
        NBYTESA,                                                                                                                           \
        NBYTESB,                                                                                                                           \
        NBYTESC,                                                                                                                           \
        PTRR,                                                                                                                              \
        RBYTES,                                                                                                                            \
        NBYTESR}
#endif

extern IntTest addTests[NUM_MYINT_TESTS];
extern IntTest subTests[NUM_MYINT_TESTS];
extern IntTest mulTests[NUM_MYINT_TESTS];
extern IntTest divTests[NUM_MYINT_TESTS];

#endif