
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

int readFile(char *pFilename, char **pContent, long *pSize)
{
    if (pFilename == NULL)
    {
        return READFILE_RESULT_FILENAME_NULL;
    }
    if (pContent == NULL)
    {
        return READFILE_RESULT_CONTENT_NULL;
    }
    // b: binary mode, otherwise fseek&ftell don't work correctly
    FILE *fp = fopen(pFilename, "rb");
    if (fp == NULL)
    {
        return READFILE_RESULT_FILE_OPEN_FAIL;
    }

    if (fseek(fp, 0, SEEK_END) != 0)
    {
        fclose(fp);
        return READFILE_RESULT_FILE_SEEK_FAIL;
    }
    long pos = ftell(fp);

#if READ_FILE_VERBOSE
    printf("FILE: %s | SIZE: %li\n", pFilename, pos);
#endif
    rewind(fp);

    if (0 != ftell(fp))
    {
        fclose(fp);
        return READFILE_RESULT_FILE_REWIND_FAIL;
    }
    if (pos < 10)
    {
        pos = 0;
        int c = 0;
        while (1)
        {
            c = getc(fp);
            if (c == EOF)
            {
                break;
            }
            pos++;
        };
#if READ_FILE_VERBOSE
        printf("LINE-BY-LINE: %s |SIZE: %li\n", pFilename, pos);
#endif
    }
    long allocSize = pos + 10;
    void *pMem = malloc(allocSize);
    if (pMem == NULL)
    {
        fclose(fp);
        return READFILE_RESULT_MEM_ALLOC_FAIL;
    }
    memset(pMem, 0, allocSize);

    rewind(fp);

    if (0 != ftell(fp))
    {
        fclose(fp);
        return READFILE_RESULT_FILE_REWIND_FAIL;
    }

    size_t bytesRead = fread(pMem, 1, pos, fp);
    if (bytesRead != pos)
    {
#if READ_FILE_VERBOSE
        printf("FILE: %s | BYTES: %li <> %li", pFilename, bytesRead, pos);
#endif
        fclose(fp);
        free(pMem);
        return READFILE_RESULT_FILE_READ_FAIL;
    }

    *pContent = pMem;
    if (pSize != NULL)
    {
        *pSize = pos;
    }

    if (0 != fclose(fp))
    {
        return READFILE_RESULT_FILE_CLOSE_FAIL;
    }

    return READFILE_RESULT_SUCCESS;
}
