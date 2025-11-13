
#include "opengl_header_parser.h"
#include "ogl_parse.h"

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
    if (0 == pResults)
    {
        printf("Failed to alloc for functions\n");
        return 1;
    }

    memset(pResults, 0, allocSize);

    int fpIdx = 0;
    char *pFileContent = 0;

    for (; fpIdx < filepathCount; fpIdx++)
    {
        char *fp = filepaths[fpIdx];

        pFileContent = 0;

        int fileResult = readFile(fp, &pFileContent, 0);
        if (fileResult != 0 || (0 == pFileContent ))
        {
            printf("FILE: %s | Failed to read file | Idx: @%i | RES: %i\n", fp, fpIdx, fileResult);
            continue;
        }

        int fileSize = strlen(pFileContent);
        printf("Filesize: %i | path:%s\n", fileSize, fp);

        OpenGLFunctions *pFunctions = (OpenGLFunctions *)malloc(sizeof(OpenGLFunctions));
        if (0 == pFunctions)
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
