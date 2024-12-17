#ifndef __COMPRESS_ALGORITHMS__
#define __COMPRESS_ALGORITHMS__

#include "ogl_compress_types.h"

int compress(char **pNames, int size);

#define DECOMPRESS_SIZE 0x2A
void decompress();

extern int compress2Hits;
int compress2(char **pNames, int size, int verbose);

#define COMPRESS2_BACKWARD_LIMIT 0x7
#define COMPRESS2_FORWARD_LIMIT 0x1F

#define DECOMPRESS2_SIZE 0x9b
void decompress2(int cs);


#define DECOMPRESS3_VERBOSE 1
int compress3(char **names, int numberOfNames);

#define DECOMPRESS3_SIZE 0xCA
void decompress3(int cs, unsigned char *pData);


int compress4(char **pNames, int size);

#define DECOMPRESS4_SIZE 0x3A
void decompress4(unsigned char *pData, decompressFPtr func);

#define DECOMPRESS4ASM_SIZE 0x31
void decompress4asm(unsigned char *pData, decompressFPtr func);

#define PRINT_STATS 0
#define COMPRESS5_VERBOSE 0
int compress5(char **names, int numNames, int inputNameOffset);

#define DECOMPRESS5_SIZE 0x9F
void decompress5(unsigned char *pData, decompressFPtr func);

#define DECOMPRESS5SORTED_SIZE 0x9D
void decompress5s(unsigned char *pData, decompressFPtr func);

#endif