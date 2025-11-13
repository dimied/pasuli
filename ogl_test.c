

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_test.h"
#include "ogl_names.h"
#include "opengl_header_parser.h"
#include "file_utils.h"

#include "ogl_compress/ogl_compress_test.h"
#include "ogl_parse.h"

//#include ""

int main()
{
    printf("OGL TEST\n");

    //compressTest();

#if 0
    int parseResult = parseHeaderFiles();
    printf("PARSE: %i\n", parseResult);
#endif
    return 0;
}

#if 0
void testCode() {
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
}
#endif