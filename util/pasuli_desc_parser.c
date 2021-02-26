
#include "pasuli_desc_parser.h"
//
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
//
#include <stdio.h>

/**
 * \brief Copies trimmed string
 * \param[in] pSrc Pointer to source string
 * \param[in] srcLength number of characters to consider in source string
 * \param[out] pDesc Pointer to destination memory
 * \param[in] limitChar additional limiting character to abort at
 * 
 * \returns pointer in the source string after the copied section of text
 */
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

int extractRangeValue(char *pRangeText)
{
    int rangeTextLength = strlen(pRangeText);
    char nameBuffer[32];
    int result = 0;

    if (rangeTextLength > 0)
    {
        if (rangeTextLength >= 32)
        {
            // Buffer is too small
            return -1;
        }

        memset(nameBuffer, 0, 32);
        //char *pAfter =
        copyTrimmed(pRangeText,
                    rangeTextLength,
                    nameBuffer, 0);

        char *pAfterPoints = strstr(nameBuffer, ":");
        int copied = 0;
        char between[32];

        memset(between, 0, 32);

        if (pAfterPoints != 0)
        {
            char *pValueAfter = copyTrimmed(nameBuffer, strlen(nameBuffer), between, ':');

            if (strcmp("pi", between) == 0 && pValueAfter != 0)
            {
                memset(pRangeText, 0, rangeTextLength);
                copyTrimmed(pValueAfter, strlen(pValueAfter), pRangeText, ':');
                result = 1;
                copied = 1;
            }
        }

        if (copied == 0)
        {
            memset(pRangeText, 0, rangeTextLength);
            strcpy(pRangeText, nameBuffer);
        }
    }
    return result;
}

void extractText(char *pBuffer, PaSuLiFunctionDescription *pResult)
{

    char *firstSeparator = strstr(pBuffer, ":");
    //int bufferLength = strlen(pBuffer);

    if (firstSeparator == 0)
    {
        return;
    }

    ptrdiff_t offset = firstSeparator - pBuffer;
    if (firstSeparator == pBuffer)
    {
        // starts with ':', INVALID state
        return;
    }

    char nameBuffer[32];
    memset(nameBuffer, 0, 32);

    copyTrimmed(pBuffer, offset, nameBuffer, 0);
    int bufferLength = strlen(nameBuffer);

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
            strstr(nameBuffer, toCopy[i].name) != 0 &&
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

    if (nameBuffer[0] == 'c')
    {
        int idx = atoi(nameBuffer + 1);
        if (idx < 0)
        {
            printf("Error: failed to parse constant: %s\n", nameBuffer);
        }
        if (idx > MAX_NUMBER_OF_CONSTANTS)
        {
            printf("Error: can not save constant, out-of-range: %s\n", nameBuffer);
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
    if (nameBuffer[0] == 'a')
    {
        int idx = atoi(nameBuffer + 1);

        if (idx < 0)
        {
            printf("Error: failed to parse abbreviation: %s\n", nameBuffer);
        }
        if (idx > MAX_NUMBER_OF_ABBREVIATIONS)
        {
            printf("Error: can not save constant, out-of-range: %s\n", nameBuffer);
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

    int res = extractRangeValue(pResult->uRangeStart);
    int res2 = extractRangeValue(pResult->uRangeEnd);
    if (res > 0 || res2 > 0)
    {
        pResult->u_Pi = 1;
    }

    res = extractRangeValue(pResult->vRangeStart);
    res2 = extractRangeValue(pResult->vRangeEnd);
    if (res > 0 || res2 > 0)
    {
        pResult->v_Pi = 1;
    }
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

void printRangeInformation(char *name, char *start, char *end, int isPi)
{
    char *tmplStart = "%s-Start: %s%s";
    char *tmplEnd = "%s-End: %s%s";

    if (isPi)
    {
        tmplStart = "%s-Start:PI: %s%s";
        tmplEnd = "%s-End:PI: %s%s";
    }
    printf(tmplStart, name, start, separator);
    printf(tmplEnd, name, end, separator);
}

int printDescription(PaSuLiFunctionDescription *pDesc)
{
    if (pDesc == 0)
    {
        return 1;
    }

    printf("\nName: %s%s", pDesc->name, separator);
    printf("Category: %s%s", pDesc->category, separator);

    printRangeInformation("U", pDesc->uRangeStart, pDesc->uRangeEnd, pDesc->u_Pi);
    printRangeInformation("V", pDesc->vRangeStart, pDesc->vRangeEnd, pDesc->v_Pi);

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