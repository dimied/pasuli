#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"

// extern void* pTempMemory;
extern void *pCompressResult5;
extern char *glParts[];
extern int numGLParts;
// extern void decompressCall(char *p, int s);

void printStats(int frequencies[64][64], char *alphabetFound)
{
    printf("? |");
    for (int fIdx = 1; fIdx < 64; fIdx++)
    {
        char c = alphabetFound[fIdx - 1];

        if (c > 0)
        {
            printf("  %c |", c);
        }
    }
    printf("\n");
    char *cFormat = "  %i |";
    char *c3Format = " %3i|";

    for (int fIdx = 1; fIdx < 64; fIdx++)
    {
        char c = alphabetFound[fIdx - 1];
        if (c > 0)
        {
            printf("%c |", c);
            for (int sIdx = 0; sIdx < 64; sIdx++)
            {
                int f = frequencies[fIdx][sIdx];
                if (f > 0)
                {
                    char *fs = f < 10 ? cFormat : c3Format;
                    printf(fs, f);
                }
                else
                {
                    printf("    |");
                }
            }
            printf("\n");
        }
    }
}

int findIndex(char *pAlphabet, char c)
{
    int l = strlen(pAlphabet);

    const char *pChar = (char *)memchr(pAlphabet, c, l);

    return (pChar != 0) ? pChar - pAlphabet : -1;
}

#define INC_MARKER 0x40
#define LAST_CHAR_MARKER 0x80

int compress5(char **names, int numNames, int inputNameOffset)
{
    unsigned int charCounters[256];
    memset(charCounters, 0, 256 * sizeof(unsigned int));

    int numChars = 0, maxValue = 0, minValue = 0xFF;
    int totalLength = 0;
    char alphabetFound[64] = {0};
    char alphabetFrequencies[64] = {0};
    char alphabetLastPosFrequencies[64] = {0};
    int alphabetIdx = 0;

    for (int i = 0; i < numNames; i++)
    {
        char *pStr = names[i] + inputNameOffset;
        int sLen = strlen(pStr);
        int aIdx = -1, hasFail = 0;
        for (int cIdx = 0; cIdx < sLen; cIdx++)
        {
            unsigned char c = (unsigned char)pStr[cIdx];
            if (maxValue < c)
            {
                maxValue = c;
            }
            if (minValue > c)
            {
                minValue = c;
            }

            if (0 == charCounters[c])
            {
                if (alphabetIdx < 63)
                {
                    alphabetFound[alphabetIdx] = c;
                }
                ++alphabetIdx;
                ++numChars;
            }

            char *pChar = strchr(alphabetFound, c);

            if (pChar != 0 && (alphabetIdx < 63))
            {
                aIdx = pChar - alphabetFound;
                ++alphabetFrequencies[aIdx];
            }
            else
            {
                hasFail = 1;
                printf("FREQ FAIL %c\n", c);
            }
            ++charCounters[c];
        }
        if (aIdx >= 0 && hasFail == 0)
        {
            ++alphabetLastPosFrequencies[aIdx];
        }
        totalLength += sLen + 1;
    }

    printf("#chars = %i |#total = %i | max = %c | min = %c\n", numChars, totalLength, maxValue, minValue);

    // Can fit into 6 bits? 0 is reserved, i.e. vals 1-63 available
    if (numChars >= 0x40 - 1)
    {
        return 0x100000;
    }
    printf("ABC: %s | %i\n", alphabetFound, alphabetIdx);
    // store min value first
    // store chars so that frequent pairs are near in the store
    // use 7.th bit (i.e. 0x40) to store whether the next byte in the store should also be used
    // use 8.th bit to end strings
    // 0 is end of string
    //[first Byte][frequency of second byte appearing after first]
    int frequencies[64][64];
    memset(frequencies, 0, sizeof(int) * 64 * 64);

    for (int i = 0; i < numNames; i++)
    {
        char *pStr = names[i] + inputNameOffset;
        int sLen = strlen(pStr);
        unsigned char lastC = 0;
        for (int cIdx = 0; cIdx < sLen; cIdx++)
        {
            unsigned char c = (unsigned char)pStr[cIdx];
            int offset = findIndex(alphabetFound, c);
            if (offset < 0)
            {
                return -2;
            }
            c = offset + 1; // no zeros!
            if (lastC > 0)
            {
                ++frequencies[lastC][c];
            }
            lastC = c;
        }
    }

#if PRINT_STATS
    printStats(frequencies, alphabetFound);
#endif

    int alphabetFreq[64] = {0};
    // last chars can't encode 2 chars
    for (int i = 0; i < 64; i++)
    {
        alphabetFreq[i] = alphabetFrequencies[i] - alphabetLastPosFrequencies[i];
    }

    unsigned char done[64] = {0};
    char newAlphabet[64] = {0};
    alphabetIdx = 0;

    int tries = numChars, tryIdx = 0;
    // int checkCapitalCaseFirst = 1;
    const int limit = numChars + 1;

    int cand1 = 63, cand2 = 63;

    // TODO: Optimization problem
    while (tryIdx < tries)
    {
        int maxFreq = 1;

        for (int freqIdx = 0; freqIdx < limit; freqIdx++)
        {
            if (alphabetFreq[freqIdx] <= 0 || (1 == done[freqIdx]))
            {
                continue;
            }
            int sCandidate = freqIdx;
            if (cand2 > 0)
            {
                // sCandidate = cand2;
            }

            for (int sIdx = 0; sIdx < limit; sIdx++)
            {
                if (done[sIdx] == 1 && freqIdx != sIdx && sIdx != sCandidate)
                {
                    continue;
                }
                if (maxFreq < frequencies[freqIdx][sIdx] - alphabetLastPosFrequencies[sIdx])
                {
                    maxFreq = frequencies[freqIdx][sIdx];
                    cand1 = freqIdx;
                    cand2 = sIdx;
                }
            }
        }

        if (maxFreq < 2)
        {
            break;
        }
#if COMPRESS5_VERBOSE
        printf("%i|MAX: %c|%c ? %i\n", tryIdx, alphabetFound[cand1 - 1], alphabetFound[cand2 - 1], maxFreq);
#endif
        newAlphabet[alphabetIdx++] = alphabetFound[cand1 - 1];
        done[cand1] = 1;
        alphabetFreq[cand1] -= maxFreq;

        newAlphabet[alphabetIdx++] = alphabetFound[cand2 - 1];
        done[cand2] = 1;
        alphabetFreq[cand2] -= maxFreq;

        ++tryIdx;
    }
    int l = strlen(alphabetFound);
    // copy rest
    for (int i = 0; i < l; i++)
    {
        char c = alphabetFound[i];
        int offset = findIndex(newAlphabet, c);
        if (offset >= 0)
        {
            continue;
        }
        newAlphabet[alphabetIdx++] = c;
    }

    printf("NA: '%s' | %i(%x)\n", newAlphabet, alphabetIdx, alphabetIdx);
    if (alphabetIdx != numChars)
    {
        printf("ERROR: Consistency error: %i <> %i\n", alphabetIdx, numChars);
        return 0x10000;
    }

    // 2 passes. 1st step: estimate size, 2nd step: allocate and write
    int pass = 0;
    int resSize = 0, allocSize = 0;
    unsigned char *pResult = 0, *pDest = 0;
    // const int charOffset = minValue - 1;

    int numMerges;

    while (pass < 2)
    {
        numMerges = 0;
        allocSize = 2; // alphabet length, offset, new line
        if (pass)
        {
            //*pDest = (unsigned char)charOffset; //-1, because of offset for chars
            //++pDest;
            *pDest = (unsigned char)numChars;
            ++pDest;
        }
        allocSize += numChars;
        if (pass)
        {
            memcpy(pDest, newAlphabet, numChars);
            pDest += numChars;
        }
        for (int idx = 0; idx < numNames; idx++)
        {
            char *pStr = names[idx] + inputNameOffset;
            size_t sLen = strlen(pStr);
            if (sLen == 0)
            {
                continue;
            }
            ++allocSize;

            unsigned char lastC = 0;
            char c;
            int curOffset;

            for (int cIdx = 0; cIdx < sLen; cIdx++)
            {
                c = pStr[cIdx];
                curOffset = findIndex(newAlphabet, c);
                if (curOffset < 0)
                {
                    printf("Alphabet search failed: %c | %s", c, pStr);
                    return 0x10000;
                }
                if (curOffset + 1 > 0x3F)
                {
                    printf("Index out of range:%i| %c | %s", curOffset, c, pStr);
                    return 0x10000;
                }

                // current index different only by +1 from last?
                if ((lastC > 0) && (lastC == curOffset))
                {
                    if (pass)
                    {
                        --pDest;
                        *pDest = lastC | INC_MARKER;
                        ++pDest;
                    }
                    // printf("M: %c%c\n", newAlphabet[lastC-1], newAlphabet[curOffset]);
                    ++numMerges;
                    lastC = 0;
                }
                else
                {
                    ++allocSize;
                    lastC = (unsigned char)curOffset + 1;
                    if (pass)
                    {
                        *pDest = lastC;
                        ++pDest;
                    }
                }
            }
            // Mask/mark last
            if (pass)
            {
                --pDest;
                *pDest = (*pDest) | LAST_CHAR_MARKER;
                ++pDest;
            }
        }

        if (pass == 0)
        {
            resSize = allocSize;
            pResult = (unsigned char *)malloc(resSize);
            if (pResult == 0)
            {
                return 0x10000;
            }
            pDest = pResult;
            memset(pResult, 0, resSize);
        }
        ++pass;
    }
    printf("#merges = %i\n", numMerges);
    pCompressResult5 = pResult;

    return resSize;
}

#define DECOMPRESS5_DEBUG 0

void decompress5(unsigned char *pData, decompressFPtr func)
{
    unsigned int val = *pData, alphabetIdx;
    ++pData;

    const char *pAlphabet = (char *)pData;
    pData += val;
    char buffer[50];
    char *pWord;

memclear:
    pWord = memset(buffer, 0, 50);

    while (*pData != 0)
    {
        val = *pData;
        alphabetIdx = (val & 0x3F) - 1;
        *pWord = pAlphabet[alphabetIdx];
        ++pWord;
        if (val & INC_MARKER)
        {
            *pWord = pAlphabet[alphabetIdx + 1];
            ++pWord;
        }

        ++pData;
        if (val > LAST_CHAR_MARKER)
        {
            func(buffer, pWord - buffer);

            goto memclear;
        }
    }
}

void decompress5s(unsigned char *pData, decompressFPtr func)
{
    unsigned int val = *pData, alphabetIdx;
    ++pData;

    const char *pAlphabet = (char *)pData;
    pData += val;
    char buffer[50];
    char *pWord = memset(buffer, 0, 50);
    
    while (*pData != 0)
    {
        val = *pData;
        alphabetIdx = (val & 0x3F) - 1;
        *pWord = pAlphabet[alphabetIdx];
        ++pWord;
        if (val & INC_MARKER)
        {
            *pWord = pAlphabet[alphabetIdx + 1];
            ++pWord;
        }

        ++pData;
        if (val > LAST_CHAR_MARKER)
        {
            func(buffer, pWord - buffer);
            pWord = buffer;
        }
    }
}