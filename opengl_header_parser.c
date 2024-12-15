
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opengl_header_parser.h"

#define PARSE_RESULT_OK 0
#define PARSE_RESULT_INVALID_PARAMETERS 1
#define PARSE_RESULT_MEM_ALLOC_FAIL 2

const char *sGLAPI = "GLAPI ";
const char *sGLAPIENTRY = "GLAPIENTRY ";

#define PARSE_FUNC_NAME_MAX_LENGTH 100

void trimInplace(char *pStr)
{
  if(pStr == 0) {
    return;
  }
  char *pStart = pStr;
  while ((*pStart != 0) && (*pStart == ' ' || *pStart == '\t' || *pStart == '\n'))
  {
    ++pStart;
  }
  char *pEnd = 0;
  // printf("?%s\n", pStr);
  if (pStart != pStr)
  {
    char *p = pStr;
    while (*pStart != 0)
    {
      *p = *pStart;
      ++pStart;
      ++p;
    }
    pEnd = p;
    while (*p != 0)
    {
      *p = 0;
      ++p;
    }
  }
  if (pEnd == 0)
  {
    pEnd = pStr;
    while (*pEnd != 0)
    {
      ++pEnd;
    }
  }
  if (pEnd != pStr)
  {
    --pEnd;
    while (pEnd != pStr && (*pEnd == ' ' || *pEnd == '\t' || *pEnd == '\n'))
    {
      *pEnd = 0;
      --pEnd;
    }
  }
}

int parseOpenGLHeaderFile(char *fileContent, OpenGLFunctions *pFunctions)
{
  if (fileContent == (char *)0 || pFunctions == (OpenGLFunctions *)0)
  {
    return PARSE_RESULT_INVALID_PARAMETERS;
  }
  char *pData = fileContent;
  int maxLineLength = 0;
  int lineLength = 0, dataLength = 0;

  while (*pData != 0)
  {
    if (*pData == '\n')
    {
      if (maxLineLength < lineLength)
      {
        maxLineLength = lineLength;
      }
      lineLength = 0;
    }
    else
    {
      ++lineLength;
    }
    ++dataLength;
    ++pData;
  }

  int singleLineLength = maxLineLength + 10;
  char *pSingleLine = (char *)malloc(singleLineLength);

  if (0 == pSingleLine)
  {
    return PARSE_RESULT_MEM_ALLOC_FAIL;
  }

  char *pDataLimit = fileContent + dataLength;
  int numLines = 0, numFuncLines = 0, pass = 0;
  int codeMaxLineLength = 0;
  char *sFuncName;
  char *sReturnType;
  char *sParameters;

  int s1 = strlen(sGLAPI);
  int s2 = strlen(sGLAPIENTRY);

  while (pass < 2)
  {
    pData = fileContent;
    int lineNr = 0;
    // int lineRes = 0;
    while (*pData != 0 && pData < pDataLimit)
    {

      char *charPtr = strchr(pData, '\n');
      if (charPtr == 0)
      {
        ++pData;
        continue;
      }
      int lineLen = charPtr - pData;
      if (lineLen < 3)
      {
        ++pData;
        continue;
      }

      charPtr = strstr(pData, sGLAPI);

      int isFuncLine = 0, isHit = 0;
      char *pDataRaw = pData;

      if (charPtr == pData)
      {
        lineLen = 0;
        // char openBracketNotSeen=1,closeBracketNotSeen=1,
        while (*charPtr != 0 && *charPtr != ';' && *charPtr != '#')
        {
          ++lineLen;
          ++charPtr;
        }
        if (*charPtr != '#')
        {
          isFuncLine = 1;
        }
      }

      if (pass == 0)
      {
        if (isFuncLine)
        {
          if (codeMaxLineLength < lineLen)
          {
            codeMaxLineLength = lineLen;
#if 0
            char d = pDataRaw[lineLen];
            pDataRaw[lineLen] = 0;
            printf("LL: %i| %s\n*****\n", lineLen, pDataRaw);
            pDataRaw[lineLen] = d;
#endif
          }
          ++numFuncLines;
        }
      }
      else if (pass == 1)
      {
        memset(pSingleLine, 0, codeMaxLineLength);
        if (isFuncLine)
        {
          memcpy(pSingleLine, pDataRaw, lineLen);
          memset(sFuncName, 0, codeMaxLineLength);
          memset(sReturnType, 0, codeMaxLineLength / 2);
          memset(sParameters, 0, codeMaxLineLength);
          int state = 0;

          char *p = pSingleLine + s1;
          char *pApi = strstr(p, sGLAPIENTRY);
          int s3;

          if (pApi != 0)
          {
            s3 = pApi - p;
            memcpy(sReturnType, p, s3);
            p = pApi + s2;
            ++state;
          }
          char *fnName = strstr(p, "gl");
          if (fnName != 0 && state > 0)
          {
            char *pO = strchr(p, '(');
            if (pO != 0)
            {
              s3 = pO - fnName;
              memcpy(sFuncName, fnName, s3);
              p = pO + 1;
            }
            ++state;
          }
          if (state > 1)
          {
            char *pC = strchr(p, ')');
            if (pC != 0)
            {
              s3 = pC - p;
              memcpy(sParameters, p, s3);
            }
          }
          if (*sReturnType != 0 && *sFuncName != 0 && *sParameters != 0)
          {
            trimInplace(sReturnType);
            trimInplace(sFuncName);
            trimInplace(sParameters);
            if (lineNr < 10)
            {
              printf("!!!\n");
            }
          }

          if (lineNr < 10)
          {
            printf("|%s\n", pSingleLine);
            printf("|RT:%s|", sReturnType);
            printf("|FN:%s|\n", sFuncName);
            printf("|PA:%s|\n", sParameters);
          }
          ++lineNr;
        }
      }

      if (isHit)
      {
        pData = charPtr;
        ++pData;
      }

      // printf("LL:%i|%s\n", lineLen, pSingleLine);
      ++pData;
      if (pass == 0)
      {
        ++numLines;
      }
    }

    if (pass == 0)
    {
      if (codeMaxLineLength > maxLineLength)
      {
        free(pSingleLine);
        codeMaxLineLength += 10;
        pSingleLine = (char *)malloc(codeMaxLineLength);
        if (pSingleLine == 0)
        {
          return PARSE_RESULT_MEM_ALLOC_FAIL;
        }
      }

      void *pMem = malloc(codeMaxLineLength);
      if (pMem == 0)
      {
        return PARSE_RESULT_MEM_ALLOC_FAIL;
      }
      sFuncName = pMem;

      pMem = malloc(codeMaxLineLength / 2);
      if (pMem == 0)
      {
        return PARSE_RESULT_MEM_ALLOC_FAIL;
      }
      sReturnType = pMem;

      pMem = malloc(codeMaxLineLength);
      if (pMem == 0)
      {
        return PARSE_RESULT_MEM_ALLOC_FAIL;
      }
      sParameters = pMem;

      int funcAllocSize = numFuncLines * sizeof(OpenGLSingleFunction);
      pMem = malloc(funcAllocSize);
      if (pMem == 0)
      {
        return PARSE_RESULT_MEM_ALLOC_FAIL;
      }
      memset(pMem, 0, funcAllocSize);
      pFunctions->pFunctions = (OpenGLSingleFunction *)pMem;
      pFunctions->numFunctions = numFuncLines;
    }
    else if (pass == 1)
    {
      // TODO
    }

    ++pass;
  }

#if PARSE_HEADER_VERBOSE > 0
  printf("#max len: %i|%i| #lines: %i | #clines: %i\n", maxLineLength, codeMaxLineLength, numLines, numFuncLines);
#endif

  return PARSE_RESULT_OK;
}

char *pUnknown = "?";

int showHeaderInfo(OpenGLFunctions *pFunctions)
{
  if (pFunctions == NULL)
  {
    return 1;
  }
  printf("FILEPATH: %s\n", pFunctions->pFilepath);
  printf("VERSION: %s\n", pFunctions->glVersion);
  printf("FUNCS: %i\n", pFunctions->numFunctions);
  return 0;
}
