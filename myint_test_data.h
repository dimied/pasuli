#ifndef __MYINT_TEST_DATA__
#define __MYINT_TEST_DATA__

#define NUM_MYINT_TESTS 2000

typedef struct {
    const char* ptrA;
    const char* ptrB;
    const char* ptrC;
    char signA;
    char signB;
    char signC;
    unsigned char aBytes[20];
    unsigned char bBytes[20];
    unsigned char cBytes[20];
    unsigned int numBytesA;
    unsigned int numBytesB;
    unsigned int numBytesC;
    const char* ptrR;
    unsigned char rBytes[20];
    unsigned int numBytesR;
} IntTest;

extern IntTest addTests[NUM_MYINT_TESTS];
extern IntTest subTests[NUM_MYINT_TESTS];
extern IntTest mulTests[NUM_MYINT_TESTS];
extern IntTest divTests[NUM_MYINT_TESTS];

#endif