
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opengl_header_parser.h"

#define PARSE_RESULT_OK 0
#define PARSE_RESULT_INVALID_PARAMETERS 1
#define PARSE_RESULT_MEM_ALLOC_FAIL 2

const char *sGLAPI = "GLAPI ";

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

  while (pass < 2)
  {
    pData = fileContent;
    // int lineRes = 0;
    while (*pData != 0 && pData < pDataLimit)
    {

      char *charPtr = strchr(pData, '\n');
      if (charPtr == 0)
      {
        break;
      }
      int lineLen = charPtr - pData;
      if (lineLen < 3)
      {
        ++pData;
        continue;
      }

      charPtr = strstr(pData, sGLAPI);

      int isFuncLine = 0;
      //char *pDataRaw = pData;

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

        pData = charPtr;
        ++pData;
        
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
      }

      // printf("LL:%i|%s\n", lineLen, pSingleLine);
      ++pData;
      ++numLines;
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

      int funcAllocSize = numFuncLines*sizeof(OpenGLSingleFunction);
      void *pMem = malloc(funcAllocSize);
      if(pMem == 0) {
        return PARSE_RESULT_MEM_ALLOC_FAIL;
      }
      memset(pMem, 0, funcAllocSize);
      pFunctions->pFunctions = (OpenGLSingleFunction*)pMem;
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
