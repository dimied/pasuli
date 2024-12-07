#ifndef __MYINT_TEST_DATA__
#define __MYINT_TEST_DATA__

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
    int numBytesA;
    int numBytesB;
    int numBytesC;
    const char* ptrR;
    unsigned char rBytes[20];
    int numBytesR;
} IntTest;

#endif