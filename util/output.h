#ifndef __OUTPUT__
#define __OUTPUT__

void sprintHex(unsigned char *vals, unsigned int sss, char *pResult, unsigned int size);

int printBytes(unsigned char *p, unsigned int size, char *pResult, unsigned int resultLength);

void printResultLine(int t, float u, float v, float *pRes);

#endif