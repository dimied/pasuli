
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_compress_test.h"

char *glParts[] = {
    "1",
    "2",
    "3",
    "b",
    "d",
    "f",
    "i",
    "s",
    "I",
    "P",
    "bv",
    "dv",
    "fv",
    "iv",
    "sv",
    "ub",
    "ui",
    "us",
    "1D",
    "2D",
    "2x3",
    "2x4",
    "3x2",
    "3x4",
    "4x2",
    "4x3",
    "i64",
    "ui64",
    "ARB",
    "Accum",
    "Active",
    "Alpha",
    "Are",
    "Array",
    //"Arrays",
    "Attach",
    "Attached",
    "Attachment",
    "Attrib",
    //"AttribI",
    //"AttribP",
    "Base",
    "Begin",
    "Binary",
    "Bind",
    "Binding",
    "Bitmap",
    "Blend",
    "Block",
    "Boolean",
    "Buffer",
    "Call",
    "Check",
    "Clamp",
    "Clear",
    "Client",
    "ClipPlane",
    "Color",
    //"ColorP",
    "Compile",
    "Compressed",
    "Conditional",
    "Convolution",
    "Coord",
    //"CoordP",
    "Copy",
    "Counter",
    "Create",
    "CullFace",
    "Data",
    "Delete",
    "Depth",
    "Detach",
    "Disable",
    "Divisor",
    "Double",
    "Draw",
    "EdgeFlag",
    "Element",
    "Enable",
    "End",
    "Env",
    "Equation",
    "Error",
    "Eval",
    "Feedback",
    "Fence",
    "Filter",
    "Finish",
    "Float",
    "Flush",
    "Fog",
    "Frag",
    "Framebuffer",
    "FrontFace",
    "Frustum",
    "Func",
    "Gen",
    "GenerateMipmap",
    "Get",
    "Grid",
    "Hint",
    "Histogram",
    "Identity",
    "Image",
    "Index",
    "Indexed",
    "Indices",
    "Indirect",
    "InfoLog",
    "Init",
    "Instanced",
    "Integer",
    "Interleaved"
    "Is",
    "Layer",
    "Light",
    "Line",
    "Link",
    "List",
    "Load",
    "Location",
    "Logic",
    "Mask",
    "Map",
    "Material",
    "Matrix",
    "Mesh",
    "Minmax",
    "MinSampleShading",
    "Mode",
    "Model",
    "Mult",
    "Multi",
    "Multisample",
    "Name",
    "New",
    "Normal",
    "NormalP",
    "Object",
    "Offset",
    "Op",
    "Ortho",
    "Parameter",
    "PassThrough",
    "Patch",
    "Pause",
    "Pipeline",
    "Pixel",
    "Point",
    "Pointer",
    "Polygon",
    "Pop",
    "PrecisionFormat",
    "Primitive",
    "Prioritize",
    "Program",
    "Provoking",
    "Queries",
    "Query",
    "Push",
    "Range",
    "RasterPos",
    "Read",
    "Rect",
    "Release",
    "Render",
    "Renderbuffer",
    "Reset",
    "Resident",
    "Restart",
    "Resume",
    "Rotate",
    "Sampler",
    "SampleCoverage",
    "Scale",
    "Scissor",
    "Secondary",
    "Select",
    "Separable",
    "Separate",
    "Shade",
    "Shader",
    "Size",
    "Source",
    "State",
    "Stage",
    "Status",
    "Stencil",
    "Stipple",
    "Store",
    "Storage",
    "String",
    "Sub",
    "Subroutine",
    "Sync",
    "Table",
    "Tex",
    "Texture",
    "Transfer",
    "TransformFeedback",
    "Translate",
    "Transpose",
    "Uniform",
    "Unmap",
    "Use",
    "Validate",
    "Varying",
    "Vertex",
    //"VertexP",
    "Viewport",
    "Wait",
    "Width",
    "WindowPos",
    "Zoom",
#if 0
    0
#endif
};

#define NAMES_COUNT 25

char *names[NAMES_COUNT] = {
    "glClear",
    "glClearAccum",
    "glClearColor",
    "glClearDepth",
    "glClearIndex",
    "glColorMask",
    "glColorPointer",
    //
    "glDepthFunc",
    "glDepthMask",
    "glDepthRange",
    "glDrawArrays",
    "glIndexMask",
    "glIndexPointer",
    "glLoadIdentity",
    "glLoadTransposeMatrixd",

    "glMatrixMode",
    "glMultTransposeMatrixf",
    "glOrtho",
    "glPopMatrix",
    "glPushMatrix",
    "glRotatef",
    "glVertex3fv",
    "glNormal3fv",
    "glBegin",
    "glEnd",
    //
};

#define TEMP_MEMORY_SIZE 1024
void *pTempMemory;

void *pCompressResult = 0;
void *pCompressResult2 = 0;
void *pCompressResult3 = 0;
void *pCompressResult4 = 0;
char **pReverseResult = 0;

int compressSize = 0;

int callIdx = 0;

void checkResult()
{
    if (pReverseResult)
    {
        char *p;
        for (int i = 0; i < NAMES_COUNT; i++)
        {
            p = pReverseResult[i];
            if (p == 0)
            {
                printf("DECOMPRESS FAILED @%i\n", i);
            }
            else
            {
                int res = strcmp(names[i], p);
                if (res != 0)
                {
                    printf("%i|RES =%i\n", i, res);
                    printf("O: %s\n", names[i]);
                    printf("C: %s\n", p);
                }
            }
        }
        return;
    }
    printf("Decompress failed\n");
}

/**
 * This will be the dymamic loader.
 */
void decompressCall(char *p, int s)
{
    char *rp = (char *)malloc(s + 3);
    pReverseResult[callIdx] = rp;
    *rp = 'g';
    ++rp;
    *rp = 'l';
    ++rp;
    memcpy(rp, p, s);
    rp[s] = 0;
    callIdx++;
}

int sizes(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        resSize += strlen(pNames[i]) + 1;
    }
    return resSize;
}

int compress(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];

        resSize += strlen(p) + 1 - 2;
    }
    resSize++;

    pCompressResult = malloc(resSize);
    memset(pCompressResult, 0, resSize);

    char *pResult = (char *)pCompressResult;

    int cs = 0;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        *pResult = (char)s;
        ++pResult;
        cs++;
        memcpy(pResult, p + 2, s);
        pResult += (s);
        cs += s;
        //++pResult;
    }
    return cs;
}

#define DECOMPRESS_SIZE 0x2A
void decompress()
{
    char *p = (char *)pCompressResult;
    while (*p != 0)
    {
        // int s = (int)*p;
        decompressCall(p + 1, *p);
        p += (*p) + 1;
    }
}

#define DECOMPRESS_PTR_SIZE 0x26
void decompressPtr(char *p)
{
    while (*p != 0)
    {
        // int s = (int)*p;
        decompressCall(p + 1, (*p));
        p += (*p) + 1;
    }
}

#define DECOMPRESS_B_SIZE 0x34
void decompressB()
{
    char *p = (char *)pCompressResult;
    for (int i = 0; i < NAMES_COUNT; i++)
    {
        int s = (int)*p;
        decompressCall(p + 1, s);
        p += s + 1;
    }
}

int compressCS(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];

        resSize += strlen(p) + 1 - 2;
    }
    resSize++;

    pCompressResult = malloc(resSize);
    memset(pCompressResult, 0, resSize);

    char *pResult = (char *)pCompressResult;

    int cs = 0;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        *pResult = (char)s;
        ++pResult;
        cs++;
        memcpy(pResult, p + 2, s);
        pResult += (s);
        cs += s;
        //++pResult;
    }
    return cs;
}

void decompressCS()
{
    char *p = (char *)pCompressResult;

    for (int i = 0; i < NAMES_COUNT; i++)
    {
        int s = (int)*p;
        decompressCall(p + 1, s);
        p += s + 1;
    }
}

#define COMPRESS2_BACKWARD_LIMIT 0x7
#define COMPRESS2_FORWARD_LIMIT 0x1F

int compress2Hits = 0;
int compress2(char **pNames, int size, int verbose)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];

        resSize += strlen(p) + 1 - 2;
    }
    resSize++;

    pCompressResult2 = malloc(resSize);
    memset(pCompressResult2, 0, resSize);

    char *pResult = (char *)pCompressResult2;

    int cs = 0;
    char *lastP = 0;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        // Error case
        if (s > COMPRESS2_FORWARD_LIMIT)
        {
            return resSize * 2;
        }

        if (lastP != 0)
        {
            char *p1 = p + 2;
            char *p2 = lastP + 2;
            int runIdx = 0, cmpRes = -1;

            while (*p1 != 0 && *p2 != 0)
            {
                if (*p1 != *p2)
                {
                    cmpRes = runIdx;
                    break;
                }
                ++p1;
                ++p2;
                ++runIdx;
            }
            if (cmpRes > 0)
            {
                // printf("Diff:I: @%i | %s <> %s\n", cmpRes, lastP, p);
                //  cmpRes-=2;
                int cmpRes1 = strlen(lastP + 2) - cmpRes;
                int cmpRes2 = strlen(p + 2) - cmpRes;
                // printf("Diff:R: @%i & %i | %s <> %s\n", cmpRes1, cmpRes2, lastP, p);

                // Hit? Can we encode?
                if (cmpRes1 > 0 && cmpRes1 <= COMPRESS2_BACKWARD_LIMIT && cmpRes2 > 0 && cmpRes2 <= COMPRESS2_FORWARD_LIMIT)
                {
                    if (verbose)
                    {
                        printf("HIT: %s & %s\n", lastP, p);
                    }

                    ++compress2Hits;
                    *pResult = (char)(((cmpRes1) << 5) | cmpRes2);
                    ++pResult;
                    cs++;
                    memcpy(pResult, p + 2 + cmpRes, cmpRes2);
                    pResult += cmpRes2;
                    cs += cmpRes2;
                    lastP = p;
                    continue;
                }
            }
        }
        *pResult = (char)s;
        ++pResult;
        cs++;
        memcpy(pResult, p + 2, s);
        pResult += (s);
        cs += s;
        lastP = p;
        //++pResult;
    }
    return cs;
}

#define DECOMPRESS2_SIZE 0x9b
void decompress2(int cs)
{
    char *ptr = pTempMemory;
    unsigned char *p = (unsigned char *)pCompressResult2;
    int lastS = 0, sb, s;

    do
    {
        s = (int)*p;
        ++p;

        sb = s >> 5;
        s = s & COMPRESS2_FORWARD_LIMIT;

        if (sb > 0)
        {
            // printf("GO BACK %i\n",sb);
            ptr -= sb;
            lastS -= sb;
        }
        else
        {
            ptr = memset(pTempMemory, 0, 100);
            lastS = 0;
        }
        ptr = memcpy(ptr, p, s);
        ptr = ptr + s;
        // printf("D? %s\n", pTempMemory);

        decompressCall(pTempMemory, lastS + s);
        lastS += s;
        p += s;

        cs -= (s + 1);
    } while (cs > 0);
}

#define NAME_PARTS_SIZE 16
typedef struct _NameParts
{
    int numParts;
    unsigned char parts[NAME_PARTS_SIZE];
} NameParts;

#define COMPRESS3_MARKER 0xFF

#define LAST_ALGO 1

int compress3(char **names, int numberOfNames)
{
    int cs = 0;
    int numParts = sizeof(glParts) / sizeof(char *);
    int allocSize = numParts * sizeof(int);
    int *pPartsCounts = (int *)malloc(allocSize);
    int *pPartsLengths = (int *)malloc(allocSize);

    if (pPartsCounts == 0)
    {
        printf("compress3: FAILED TO ALLOCATE COUNTS\n");
        return 0x1000;
    }
    if (pPartsLengths == 0)
    {
        free(pPartsCounts);
        printf("compress3: FAILED TO ALLOCATE LENGTHS\n");
        return 0x1000;
    }
    int nameAllocSize = sizeof(NameParts) * numberOfNames;
    NameParts *pNameParts = (NameParts *)malloc(nameAllocSize);

    if (pNameParts == 0)
    {
        free(pPartsCounts);
        free(pPartsLengths);
        printf("compress3: FAILED TO ALLOCATE NAME PARTS\n");
        return 0x1000;
    }

    const int mappingAllocSize = numParts;
    unsigned char *pMapping = (unsigned char *)malloc(mappingAllocSize);
    memset(pPartsCounts, 0, allocSize);
    memset(pPartsLengths, 0, allocSize);
    memset(pNameParts, 0, nameAllocSize);
    memset(pMapping, 0, mappingAllocSize);

    printf("#parts=%i\n", numParts);

    for (int i = 0; i < numParts; i++)
    {
        if (glParts[i] != 0)
        {
            // printf("?%s\n", glParts[i]);
            pPartsLengths[i] = strlen(glParts[i]);
        }
    }

    char funcNameBuffer[200];

    int pass = 0;
    int numNameParts = 0;
    int success = 1;

    while (pass < 1 && success == 1)
    {
        for (int checkNameIdx = 0; checkNameIdx < numberOfNames && success == 1; checkNameIdx++)
        {
            char *pName = names[checkNameIdx];

            if (pName == strstr(pName, "gl"))
            {
                pName += 2;
            }

            char nameSize = strlen(pName);
            memset(funcNameBuffer, 0, 200);
            memcpy(funcNameBuffer, pName, nameSize);

            char *p = funcNameBuffer;

            int currentParts = 0;

            while (*p != 0)
            {
                // char *pHit = 0;
                int hitIdx = -1;
                for (int partIdx = 0; partIdx < numParts; partIdx++)
                {
                    char *pSearch = glParts[partIdx];
                    if (pSearch == 0 || pPartsLengths[partIdx] == 0)
                    {
                        continue;
                    }
                    char *pPos = strstr(p, pSearch);
                    if (pPos == p)
                    {
                        // pHit = pPos;
                        hitIdx = partIdx;
                    }
                }
                if (hitIdx > 0)
                {
                    p += pPartsLengths[hitIdx];
                    if (pass == 0)
                    {
                        ++pPartsCounts[hitIdx];
                        ++currentParts;
                    }
                    int pIdx = pNameParts[checkNameIdx].numParts;
                    if (pIdx >= NAME_PARTS_SIZE)
                    {
                        success = 3;
                        break;
                    }
                    pNameParts[checkNameIdx].parts[pIdx] = hitIdx;
                    ++pNameParts[checkNameIdx].numParts;
                }
                else
                {
                    printf("Failed? %s | %s\n", p, funcNameBuffer);
                    success = 2;
                    break;
                }
                //++p;
            }

            numNameParts += currentParts;
        }
        //
        ++pass;
    }

    if (success != 1)
    {
        free(pPartsCounts);
        free(pPartsLengths);
        free(pNameParts);
        free(pMapping);
        return 0x10000;
    }

    int funcPartSizeSum = 0;
    int hits = 0;

    for (int i = 0; i < numParts; i++)
    {
        if (pPartsCounts[i] > 0)
        {
#if 0
            printf("%i : '%s'\n", pPartsCounts[i], glParts[i]);
#endif
            // mapping orig index to new index(+1), no 0 values
            pMapping[i] = hits + 1;
            ++hits;
            funcPartSizeSum += pPartsLengths[i];
        }
    }
    // Dict length + (no num names) + lengths + hits(i.e size bytes for every entry)
    // + 1
    cs += 1 + funcPartSizeSum + hits + numNameParts + numberOfNames + 1;

#if LAST_ALGO
    cs -= hits;
#endif

    unsigned char *pResult = (unsigned char *)malloc(cs);
    int sizeTrack = 0;

    if (pResult != 0)
    {
        memset(pResult, 0, cs);
        pCompressResult3 = pResult;
        unsigned char *p = pResult;
        //*p = (unsigned char)numberOfNames;
        //++p;
#if LAST_ALGO == 0
        *p = (unsigned char)hits;
        ++p;
        sizeTrack += 1;
#endif

        for (int partIdx = 0; partIdx < numParts; partIdx++)
        {
            if (pPartsCounts[partIdx] > 0)
            {
                // printf("%i : %s\n", pPartsCounts[i], glParts[i]);
                int l = pPartsLengths[partIdx];
                //*p = (unsigned char)l;
                //++p;
                memcpy(p, glParts[partIdx], l);

#if LAST_ALGO
                p += l - 1;
                *p |= 0x80;
                sizeTrack += l;
#else
                p += l;
                *p = (unsigned char)COMPRESS3_MARKER;

                sizeTrack += l + 1;
#endif
                ++p;
                if (sizeTrack >= cs)
                {
                    success = 5;
                    break;
                }
            }
        }
        if (success == 1)
        {
#if LAST_ALGO
            *p = COMPRESS3_MARKER;
            ++p;
            sizeTrack++;
#endif
            for (int nameIdx = 0; nameIdx < numberOfNames && success == 1; nameIdx++)
            {
                int numParts = pNameParts[nameIdx].numParts;
                //*p = (unsigned char)numParts;
                //++p;
                //++sizeTrack;
                if (sizeTrack >= cs)
                {
                    printf("Overflow @%i| %i<>%i\n", nameIdx, sizeTrack, cs);
                    success = 5;
                    break;
                }
                for (int pIdx = 0; pIdx < numParts; pIdx++)
                {
                    int idxOfName = pNameParts[nameIdx].parts[pIdx];
                    int mapped = pMapping[idxOfName];
                    *p = (unsigned char)mapped;
                    ++p;
                    ++sizeTrack;
                    if (sizeTrack >= cs)
                    {
                        printf("Overflow @%i| %i<>%i | p=%i(%s)\n",
                               nameIdx, sizeTrack, cs, pIdx, glParts[idxOfName]);
                        success = 5;
                        break;
                    }
                }
                *p = (unsigned char)COMPRESS3_MARKER;
                ++p;
                ++sizeTrack;
                if (sizeTrack >= cs)
                {
                    printf("Overflow @%i| %i<>%i\n",
                           nameIdx, sizeTrack, cs);
                    success = 5;
                    break;
                }
            }
            if (success == 1)
            {
                *p = 0;
            }
        }
    }
    else
    {
        success = 6;
    }

    free(pPartsCounts);
    free(pPartsLengths);
    free(pNameParts);
    free(pMapping);
    if (success != 1)
    {
        return 0x100000;
    }
    printf("RES: L =?= S: %i =?= %i | Hits=%i\n", cs, sizeTrack, hits);

    return cs;
}

#define DECOMPRESS3_VERBOSE 1

#define DECOMPRESS3_SIZE 0xCA
void decompress3(int cs, unsigned char *pData)
{
    // int i = *pData;
    //++pData;

#if 0
    char buffer[100];
#if DECOMPRESS3_VERBOSE
    // char *pIn = pData;
#endif
int i = *pData;
    ++pData;
    char *pDict[300];
    char **pDictCurrent = pDict;
    memset(pDict, 0, sizeof(char *) * 300);
    // Fill dictionary
    while (i > 0)
    {
        *pDictCurrent = (char *)pData;
        ++pDictCurrent;
        while (*pData != COMPRESS3_MARKER)
        {
            ++pData;
        }
        ++pData;
        --i;
    }
clearbuf:
    memset(buffer, 0, 100);
    while (*pData != 0)
    {
#if DECOMPRESS3_VERBOSE > 1
        printf("PARSE\n");
#endif

        int val = *pData;
        if (val == COMPRESS3_MARKER)
        {
            // call!
            // decompressCall(pTempMemory, lastS + s);
            //memset(buffer, 0, 100);
            ++pData;
            goto clearbuf;
            i=0;
        }
        else
        {
            char *p = buffer;
            char *pPart = pDict[val - 1];
#if DECOMPRESS3_VERBOSE
            printf("IDX %i|%i|%p|%p\n", i, val, (void *)pPart, (void *)pIn);
#endif
            while (*pPart != COMPRESS3_MARKER)
            {
                *p = *pPart;
                ++p;
                ++pPart;
                ++i;
            }
        }
        ++pData;
    }
#endif
#if 0
char buffer[100];
#if DECOMPRESS3_VERBOSE
    // char *pIn = pData;
#endif
int i = *pData;
    ++pData;
    int s, val;    
    unsigned char *pDict[200];
    unsigned char *pName = pData;
    char *p;
clearbuf:
    s = 0;
    //p = buffer;
    p = memset(buffer, 0, 100);
    //
    while (*pData != 0)
    {
        val = *pData;
#if DECOMPRESS3_VERBOSE
        printf("PARSE: %x | %x\n", i, val);
#endif
        if (i > 0)
        {
            if (val == COMPRESS3_MARKER)
            {
                pDict[s] = pName;
                ++s;
                pName = pData + 1;
                --i;
            }
        }
        else
        {
            if (val == COMPRESS3_MARKER)
            {
// call!
#if DECOMPRESS3_VERBOSE
                printf("F: %s\n", buffer);
#endif
                // decompressCall(pTempMemory, lastS + s);
                ++pData;
                goto clearbuf;
            }
            else
            {
                unsigned char *pPart = pDict[val - 1];
#if DECOMPRESS3_VERBOSE
                printf("IDX %i|%i|%p|%p\n", i, val, (void *)pPart, (void *)pIn);
#endif
                while (*pPart != COMPRESS3_MARKER)
                {
#if DECOMPRESS3_VERBOSE
                    printf("P:%i\n", (unsigned char)(*pPart));
#endif
                    *p = *pPart;
                    ++p;
                    ++pPart;
                    ++s;
                }
            }
        }

        ++pData;
    }
#endif
#if LAST_ALGO
    unsigned char buffer[100];
    int s = 1, val;
    unsigned char *pDict[200];
    unsigned char **pDictTemp = pDict;
    unsigned char *pName = buffer;
    memset(pDict, 0, 200 * sizeof(unsigned char *));
    unsigned char *p = pData;

    while (*pData != 0)
    {
        val = *pData;
        // printf("?%i|%x|%c?\n", s, val, val);
        if (s)
        {
            if (val > 0x80)
            {
                if (val == COMPRESS3_MARKER)
                {
                    s = 0;
                }
                else
                {
                    //*pData = (val&0x7F);
                    *pDictTemp = p;
                    ++pDictTemp;
                    p = pData + 1;
#if 0
                    char d = *p;
                    *p = 0;
                    *pData =val&0x7F;
                    printf("E: %s\n", pData);
                    *pData =val;
                    *p = d;
#endif
                }
            }
        }
        else
        {
            if (val != COMPRESS3_MARKER)
            {
                p = pDict[val - 1];
                while (*p < 0x80)
                {
                    *pName = *p;
                    ++pName;
                    ++p;
                }
                *pName = (*p) & 0x7F;
                ++pName;
            }
            else
            {
#if DECOMPRESS3_VERBOSE == 0
                printf("F:%s\n", buffer);
#endif
                // call
                memset(buffer, 0, 100);
                pName = buffer;
            }
        }

        ++pData;
    }
#endif
}

int compress4(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        resSize += strlen(pNames[i]) - 2;
    }
    ++resSize;
    void *pMem = malloc(resSize);
    memset(pMem, 0, resSize);
    pCompressResult4 = pMem;

    unsigned char *pUC = (unsigned char *)pMem;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        p += 2;
        int len = strlen(p);
        memcpy(pUC, p, len);
        pUC += len - 1;
        // set marker
        *pUC = 0x80 | (*pUC);
        ++pUC;
    }
    printf("SIZES: %i <> %li\n", resSize, pUC - (unsigned char *)pMem);

    return resSize;
}

#define DECOMPRESS4_SIZE 0x38
void decompress4(unsigned char *pData)
{
    unsigned char *pLast = pData;
    while (*pData != 0)
    {
        int val = *pData;
        // if (*pData > 0x80)
        if (val > 0x80)
        {
            *pData = (val) & 0x7F;

            ++pData;
            val = *pData;
            //int s = pData - pLast;
            *pData = 0;
            decompressCall((char *)pLast, (pData - pLast));
            *pData = val;
            pLast = pData;
            continue;
        }
        ++pData;
    }
}

typedef struct _CompressTestResult
{
    char *pName;
    int cs;
    int code;
} CompressTestResult;

void compressTest()
{
    int is = sizes(names, NAMES_COUNT);
    int cs = compress(names, NAMES_COUNT);
    int cs2 = compress2(names, NAMES_COUNT, 0);
    int cs3 = compress3(names, NAMES_COUNT);
    int cs4 = compress4(names, NAMES_COUNT);

    // printf("|1|%s\n", (char *)pCompressResult);
    // printf("|2|%s\n", (char *)pCompressResult2);
    printf("HITS(2) = %i\n", compress2Hits);

    pTempMemory = malloc(TEMP_MEMORY_SIZE);

    int reverseSize = NAMES_COUNT * sizeof(char *);
    pReverseResult = (char **)malloc(reverseSize);
    memset(pReverseResult, 0, reverseSize);

    decompress();
    checkResult();

    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress2(cs2);
    checkResult();

    // printf("|3|%s|\n", (char *)pCompressResult3);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress3(cs3, pCompressResult3);

    printf("|4|%s|\n", (char *)pCompressResult4);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress4(pCompressResult4);
    checkResult();

    // 3rd option: split names
    //  - store names as list
    //  - use indices to merge strings
    //  - one byte index for raw values
    //  - signed bytes means that indices follow to be merged

    CompressTestResult results[] = {
        {cs : cs, code : DECOMPRESS_SIZE, pName : "1"},
        {cs : cs2, code : DECOMPRESS2_SIZE, pName : "2"},
        {cs : cs3, code : DECOMPRESS3_SIZE, pName : "3"},
        {cs : cs4, code : DECOMPRESS4_SIZE, pName : "4"}};

    printf("\nIS=%i\n", is);
    int numRes = sizeof(results) / sizeof(CompressTestResult);
    for (int i = 0; i < numRes; i++)
    {
        printf("%s:CS+DC= %i + %i = %i\n", results[i].pName, results[i].cs, results[i].code, results[i].cs + results[i].code);
    }
}