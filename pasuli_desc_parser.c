
#include "pasuli_desc_parser.h"
//
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
//
#include <stdio.h>

char *copyTrimmed(char *pSrc, int srcLength, char *pDest, char limitChar)
{
    if (pSrc != 0 && srcLength > 0 && pDest != 0)
    {
        while (0 < srcLength--)
        {
            if (limitChar != 0 && *pSrc == limitChar)
            {
                return pSrc + 1;
            }

            if (*pSrc != ' ')
            {
                *pDest = *pSrc;
                ++pDest;
            }
            ++pSrc;
        }
        return pSrc;
    }

    return 0;
}

typedef struct
{
    char *name;
    char *dst;
} SimpleToCopy;

void extractText(char *pBuffer, PaSuLiFunctionDescription *pResult)
{

    char *firstSeparator = strstr(pBuffer, ":");
    //int bufferLength = strlen(pBuffer);

    if (firstSeparator == 0)
    {
        return;
    }

    ptrdiff_t offset = firstSeparator - pBuffer;
    if (offset < 1)
    {
        // starts with ':', INVALID state
        return;
    }

    char tempBuffer[512];
    memset(tempBuffer, 0, 512);

    copyTrimmed(pBuffer, offset, tempBuffer, 0);
    int bufferLength = strlen(tempBuffer);

    int maxEntries = 27;

    SimpleToCopy toCopy[27] = {
        {"name", pResult->name},
        {"cat", pResult->category},

        {"us", pResult->uRangeStart},
        {"ue", pResult->uRangeEnd},

        {"vs", pResult->vRangeStart},
        {"ve", pResult->vRangeEnd},

        {"x", pResult->x},
        {"y", pResult->y},
        {"z", pResult->z},
        {"xu", pResult->xu},
        {"yu", pResult->yu},
        {"zu", pResult->zu},
        {"xv", pResult->xv},
        {"yv", pResult->yv},
        {"zv", pResult->zv},

        {"xn", pResult->xn},
        {"yn", pResult->yn},
        {"zn", pResult->zn},

        {"xuu", pResult->xuu},
        {"yuu", pResult->yuu},
        {"zuu", pResult->zuu},

        {"xuv", pResult->xuv},
        {"yuv", pResult->yuv},
        {"zuv", pResult->zuv},

        {"xvv", pResult->xvv},
        {"yvv", pResult->yvv},
        {"zvv", pResult->zvv},
    };

    char *pValue = firstSeparator + 1;
    int found = 0;

    for (int i = 0; i < maxEntries; i++)
    {
        // Exact match !
        if (toCopy[i].name &&
            strstr(tempBuffer, toCopy[i].name) != 0 &&
            strlen(toCopy[i].name) == bufferLength)
        {
            int valueLength = strlen(pValue);

            if (valueLength >= MAX_FUNCTION_LENGTH)
            {
                printf("Error: not enough space to save. Abort");
                return;
            }
            copyTrimmed(pValue, valueLength, toCopy[i].dst, 0);
            found++;
        }
    }

    if (found > 0)
    {
        return;
    }

    if (tempBuffer[0] == 'c')
    {
        int idx = atoi(tempBuffer + 1);
        if(idx < 0) {
            printf("Error: failed to parse constant: %s\n", tempBuffer);
        }
        if(idx > MAX_NUMBER_OF_CONSTANTS) {
            printf("Error: can not save constant, out-of-range: %s\n", tempBuffer);
        }
        printf("Found constant: %s|%d \n", pValue, idx);

        char *pConstValue = copyTrimmed(pValue,
                                        strlen(pValue),
                                        pResult->constants[idx].name,
                                        ':');

        if (pConstValue != 0)
        {
            copyTrimmed(pConstValue,
                        strlen(pConstValue),
                        pResult->constants[idx].value,
                        ':');
        }
    }
    if (tempBuffer[0] == 'a')
    {
        int idx = atoi(tempBuffer + 1);
        if(idx < 0) {
            printf("Error: failed to parse abbreviation: %s\n", tempBuffer);
        }
        if(idx > MAX_NUMBER_OF_ABBREVIATIONS) {
            printf("Error: can not save constant, out-of-range: %s\n", tempBuffer);
        }
        printf("Found abbreviation: %s|%d \n", pValue, idx);

        char *pConstValue = copyTrimmed(pValue,
                                        strlen(pValue),
                                        pResult->abbreviations[idx].name,
                                        ':');

        if (pConstValue != 0)
        {
            copyTrimmed(pConstValue,
                        strlen(pConstValue),
                        pResult->abbreviations[idx].value,
                        ':');
        }
    }

    //printf("Trimmed|%s|%ld, %ld\n", tempBuffer, offset, strlen(tempBuffer));
}

int parseDescription(char *pDescription, PaSuLiFunctionDescription *pResult)
{
    if (pDescription == 0 || pResult == 0)
    {
        return 1;
    }
    printf("Size is %ld\n", sizeof(PaSuLiFunctionDescription));

    char *defSeparator = ";";
    char *pCurrent = pDescription;

    int descLength = strlen(pDescription);

    int numFound = 0;
    char buffer[1024];

    while (descLength > 0)
    {
        char *newPos = strstr(pCurrent, defSeparator);

        if (newPos == 0)
        {
            break;
        }
        numFound++;

        // Copy chunk to buffer
        memset(buffer, 0, 1024);

        ptrdiff_t length = newPos - pCurrent;

        if (length > 1)
        {
            memcpy(buffer, pCurrent, length);

            printf("Found|%s|\n", buffer);

            extractText(buffer, pResult);
        }

        pCurrent = newPos + 1;

        length = pCurrent - pDescription;

        int offset = (int)length;

        if (offset >= descLength)
        {
            break;
        }
    }

    printf("#found ';' = %d\n", numFound);

    return 0;
}

char *separator = "\n";

void printFunctionDesc(char *name, char *value)
{
    printf("%s : %s%s", name, value, separator);
}

int printDescription(PaSuLiFunctionDescription *pDesc)
{
    if (pDesc == 0)
    {
        return 1;
    }

    printf("\nName: %s%s", pDesc->name, separator);
    printf("Category: %s%s", pDesc->category, separator);

    printf("U-Start: %s%s", pDesc->uRangeStart, separator);
    printf("U-End: %s%s", pDesc->uRangeEnd, separator);

    printf("V-Start: %s%s", pDesc->vRangeStart, separator);
    printf("V-End: %s%s", pDesc->vRangeEnd, separator);

    for (int i = 0; i < MAX_NUMBER_OF_CONSTANTS; i++)
    {
        if (strlen(pDesc->constants[i].name) > 0)
        {
            printf("Constant:%d: %s = %s %s",
                   i,
                   pDesc->constants[i].name,
                   pDesc->constants[i].value,
                   separator);
        }
    }

    for (int i = 0; i < MAX_NUMBER_OF_ABBREVIATIONS; i++)
    {
        if (strlen(pDesc->abbreviations[i].name) > 0)
        {
            printf("Abbreviation:%d: %s = %s %s",
                   i,
                   pDesc->abbreviations[i].name,
                   pDesc->abbreviations[i].value,
                   separator);
        }
    }

    printFunctionDesc("x", pDesc->x);
    printFunctionDesc("y", pDesc->y);
    printFunctionDesc("z", pDesc->z);

    printFunctionDesc("xu", pDesc->xu);
    printFunctionDesc("yu", pDesc->yu);
    printFunctionDesc("zu", pDesc->zu);

    printFunctionDesc("xv", pDesc->xv);
    printFunctionDesc("yv", pDesc->yv);
    printFunctionDesc("zv", pDesc->zv);

    printFunctionDesc("xn", pDesc->xn);
    printFunctionDesc("yn", pDesc->yn);
    printFunctionDesc("zn", pDesc->zn);

    printFunctionDesc("xuu", pDesc->xuu);
    printFunctionDesc("yuu", pDesc->yuu);
    printFunctionDesc("zuu", pDesc->zuu);

    printFunctionDesc("xuv", pDesc->xuv);
    printFunctionDesc("yuv", pDesc->yuv);
    printFunctionDesc("zuv", pDesc->zuv);

    printFunctionDesc("xvv", pDesc->xvv);
    printFunctionDesc("yvv", pDesc->yvv);
    printFunctionDesc("zvv", pDesc->zvv);
    return 0;
}