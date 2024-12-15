
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_compress_test.h"

#define NAMES_COUNT 20

char *glParts[] = {
    "1",
    "2",
    "3",
    "b",
    "d",
    "f",
    "i",
    "s",
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
    "Arrays",
    "Attach",
    "Attached",
    "Attachment",
    "Attrib",
    "AttribI",
    "AttribP",
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
    "ColorP",
    "Compile",
    "Compressed",
    "Conditional",
    "Convolution",
    "Coord",
    "CoordP",
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
    "VertexP",
    "Viewport",
    "Wait",
    "Width",
    "WindowPos",
    "Zoom",
    0};

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
    //
};

#define TEMP_MEMORY_SIZE 1024
void *pTempMemory;

void *pCompressResult = 0;
void *pCompressResult2 = 0;
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
        //int s = (int)*p;
        decompressCall(p + 1, *p);
        p += (*p) + 1;
    }
}

#define DECOMPRESS_PTR_SIZE 0x26
void decompressPtr(char* p)
{
    while (*p != 0)
    {
        //int s = (int)*p;
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

int compress3(char **names, int size)
{
    int cs = 0;
    return cs;
}

void decompress3(int cs)
{
}

void compressTest()
{
    int is = sizes(names, NAMES_COUNT);
    int cs = compress(names, NAMES_COUNT);
    int cs2 = compress2(names, NAMES_COUNT, 0);
    int cs3 = compress3(names, NAMES_COUNT);

    // printf("|1|%s\n", (char *)pCompressResult);
    // printf("|2|%s\n", (char *)pCompressResult2);
    printf("HITS(2) = %i\n", compress2Hits);

    pTempMemory = malloc(TEMP_MEMORY_SIZE);

    pReverseResult = (char **)malloc(NAMES_COUNT * sizeof(char *));

    decompress();
    checkResult();
    callIdx = 0;
    decompress2(cs2);
    checkResult();

    callIdx = 0;
    decompress3(cs3);
    checkResult();

    // 3rd option: split names
    //  - store names as list
    //  - use indices to merge strings
    //  - one byte index for raw values
    //  - signed bytes means that indices follow to be merged

    printf("\nIS=%i | CS2=%i | CS3=%i\n\n", is, cs2, cs3);
    printf("CS+DC= %i + %i = %i\n", cs, DECOMPRESS_SIZE, cs + DECOMPRESS_SIZE);
}