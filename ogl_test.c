

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_test.h"
#include "ogl_names.h"
#include "opengl_header_parser.h"
#include "file_utils.h"


#include "ogl_compress_test.h"

int parseHeaderFiles();

int main()
{
    printf("OGL TEST\n");

    compressTest();

#if 0
    int size = 0, l;
    OGL_FUNC_DESC *pNames = getNames(&size);
    printf("#names = %i\n", size);

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i].name;
        l = 0;
        while (l < OGL_FUNC_DESC_NAME_LENGTH)
        {
            if (p[l] == 0)
            {
                break;
            }
            l++;
        }
        if (l == OGL_FUNC_DESC_NAME_LENGTH)
        {
            printf("HIT: @%i\n", i);
        }
    }
#endif
#if 0
    int parseResult = parseHeaderFiles();
    printf("PARSE: %i\n", parseResult);
#endif
    return 0;
}

int parseHeaderFiles()
{
    char *filepaths[] = {
        "/usr/include/GL/gl.h",
        //"/usr/include/GL/glcorearb.h",
        //"/usr/include/GL/glext.h",
    };

    int filepathCount = sizeof(filepaths) / sizeof(char *);

    int allocSize = filepathCount * sizeof(OpenGLFunctions *);

    OpenGLFunctions **pResults = (OpenGLFunctions **)malloc(allocSize);
    if (pResults == NULL)
    {
        printf("Failed to alloc for functions\n");
        return 1;
    }

    memset(pResults, 0, allocSize);

    int fpIdx = 0;
    char *pFileContent = NULL;

    for (; fpIdx < filepathCount; fpIdx++)
    {
        char *fp = filepaths[fpIdx];

        pFileContent = NULL;

        int fileResult = readFile(fp, &pFileContent, NULL);
        if (fileResult != 0 || (pFileContent == NULL))
        {
            printf("FILE: %s | Failed to read file | Idx: @%i | RES: %i\n", fp, fpIdx, fileResult);
            continue;
        }

        int fileSize = strlen(pFileContent);
        printf("Filesize: %i | path:%s\n", fileSize, fp);

        OpenGLFunctions *pFunctions = (OpenGLFunctions *)malloc(sizeof(OpenGLFunctions));
        if (pFunctions == NULL)
        {
            printf("Failed to allocate functions @%i: %s\n", fpIdx, fp);
            break;
        }
        memset(pFunctions, 0, sizeof(OpenGLFunctions));

        int parseResult = parseOpenGLHeaderFile(pFileContent, pFunctions);
        printf("%i | %s\n", parseResult, fp);
        showHeaderInfo(pFunctions);
        
        int clearRes = clearFunctions(pFunctions);
        printf("CLEAR: %i\n", clearRes);
    }
    return 0;
}
