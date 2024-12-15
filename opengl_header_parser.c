
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opengl_header_parser.h"

#define PARSE_RESULT_OK 0
#define PARSE_RESULT_INVALID_PARAMETERS 1
#define PARSE_RESULT_MEM_ALLOC_FAIL 2

#ifdef IS_EMPTY_CHAR
#define PARSER_SOME_PREVIOUS_IS_EMPTY_CHAR_STAFF IS_EMPTY_CHAR
#endif
#define IS_EMPTY_CHAR(C) (((C) == ' ') || ((C) == '\t') || ((C) == '\n'))

const char *sGLAPI = "GLAPI ";
const char *sGLAPIENTRY = "GLAPIENTRY ";

#define PARSE_FUNC_NAME_MAX_LENGTH 100

int understandType(char *pStr, int *pTypeResult, int *pPointerResult);

void trimInplace(char *pStr)
{
  if (pStr == 0)
  {
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

int parseOpenGLHeaderFile(char *fileContent, OpenGLFunctions *pResult)
{
  if (fileContent == (char *)0 || pResult == (OpenGLFunctions *)0)
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
  char *sFuncName = 0;
  char *sReturnType = 0;
  char *sParameters = 0;

  char *pParameterPositions[20][2];

  const int glapiLength = strlen(sGLAPI);
  const int glApiEntryLength = strlen(sGLAPIENTRY);
  int funcIdxToStore = 0;

  while (pass < 2)
  {
    pData = fileContent;
    int lineNr = 0;

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

          char *p = pSingleLine + glapiLength;
          char *pApi = strstr(p, sGLAPIENTRY);
          int s3;

          if (pApi != 0)
          {
            s3 = pApi - p;
            memcpy(sReturnType, p, s3);
            p = pApi + glApiEntryLength;
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
          int funcIdx = 0;
          OpenGLSingleFunction *pResFunc = &pResult->pFunctions[funcIdxToStore];

          if (*sReturnType != 0 && *sFuncName != 0 && *sParameters != 0)
          {
            trimInplace(sReturnType);
            trimInplace(sFuncName);
            trimInplace(sParameters);
            memset(pParameterPositions, 0, sizeof(pParameterPositions));

            if (strlen(sFuncName) > OGL_FUNC_NAME_MAX_LENGTH)
            {
              printf("Func name truncate\n");
              return 1;
            }

            if (strlen(sReturnType) > OGL_FUNC_RETURN_TYPE_MAX_LENGTH)
            {
              printf("Return type truncate\n");
              return 1;
            }

            if (strcmp(sParameters, "") != 0 || strcmp(sParameters, "void") != 0)
            {
              p = sParameters;
              char *pLast = p;

              while (*p != 0)
              {
                if (*p == ',')
                {
                  pParameterPositions[funcIdx][0] = pLast;
                  pParameterPositions[funcIdx][1] = p;
                  ++funcIdx;
                  ++p;

                  while (IS_EMPTY_CHAR(*p) && *p != 0)
                  {
                    ++p;
                  }
                  if (*p == 0)
                  {
                    break;
                  }
                  pLast = p;
                }
                ++p;
              }

              if (pLast != p)
              {
                while (pLast != p && IS_EMPTY_CHAR(*pLast))
                {
                  ++pLast;
                }
                pParameterPositions[funcIdx][0] = pLast;
                pParameterPositions[funcIdx][1] = p;
                ++funcIdx;
              }
            }
          }
          if (funcIdx > 0)
          {
            unsigned int paramSizes = sizeof(OpenGLParameter) * funcIdx;
            // printf("?mal?%u|%s|%s\n", paramSizes, pSingleLine, sParameters);
            OpenGLParameter *pParameters = (OpenGLParameter *)malloc(paramSizes);
            // printf("PARAMS!\n");

            if (pParameters == 0)
            {
              return PARSE_RESULT_MEM_ALLOC_FAIL;
            }
            memset(pParameters, 0, paramSizes);

            for (int fIdx = 0; fIdx < funcIdx; fIdx++)
            {
              char *pFS = pParameterPositions[fIdx][0],
                   *pFE = pParameterPositions[fIdx][1],
                   *pFN = 0;

              while (pFS != pFE)
              {
                if (*pFE == ' ')
                {
                  pFN = pFE;
                  break;
                }
                if (*pFE == '*')
                {
                  pFN = pFE + 1;
                  break;
                }
                --pFE;
              }
              if (pFN != 0)
              {
                pFE = pParameterPositions[fIdx][1];
                char ec = *pFE;
                char d = *pFN;
                *pFN = 0;
                *pFE = 0;
                int paramTypeSize = strlen(pFS);
                int paramNameSize = strlen(pFN + 1);
                // printf("P?%s?%s\n", pFS, pFN + 1);
                *pFN = d;
                *pFE = ec;

                if (paramTypeSize < OGL_FUNC_PARAMETER_TYPE_MAX_LENGTH &&
                    paramNameSize < OGL_FUNC_PARAMETER_NAME_MAX_LENGTH)
                {
                  memcpy(pParameters[fIdx].sType, pFS, paramTypeSize);

                  if (paramNameSize > 0)
                  {
                    memcpy(pParameters[fIdx].sName, pFN + 1, paramNameSize);
                  }
                }
                else
                {
                  *pFE = 0;
                  printf("Parameter would be lost: %s(%i,%i)'%s'\n", pSingleLine, paramNameSize, paramTypeSize, pFS);
                  return 1;
                }
              }
            }

            memcpy(pResFunc->sFuncName, sFuncName, strlen(sFuncName));
            memcpy(pResFunc->sReturnType, sReturnType, strlen(sReturnType));
            pResFunc->numParameters = funcIdx;
            pResFunc->pParameters = pParameters;
            ++funcIdxToStore;
          }

          if (lineNr < 10)
          {
            printf("|%s\n", pSingleLine);
            printf("|RT:%s|", sReturnType);
            printf("|FN:%s|\n", sFuncName);
            printf("|PA:%s|\n", sParameters);
            printf("#funcs: %i\n", funcIdx);
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
      pResult->pFunctions = (OpenGLSingleFunction *)pMem;
      pResult->numFunctions = numFuncLines;
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

int clearFunctions(OpenGLFunctions *pFunctions)
{
  if (pFunctions == 0)
  {
    return 1;
  }
  if (pFunctions->numFunctions > 0)
  {
    if (pFunctions->pFunctions == 0)
    {
      return 2;
    }
    int num = pFunctions->numFunctions;
    for (int funcIdx = 0; funcIdx < num; funcIdx++)
    {
      // int res =
      clearSingleFunction(&pFunctions->pFunctions[funcIdx]);
    }
    free(pFunctions->pFunctions);
    pFunctions->pFunctions = 0;
  }

  if (pFunctions->pNextFunctions)
  {
    int res = clearFunctions((OpenGLFunctions *)pFunctions->pNextFunctions);
    pFunctions->pNextFunctions = 0;
    return res;
  }
  return 0;
}

int understandType(char *pStr, int *pTypeResult, int *pPointerResult)
{
  if(pStr == 0 || pTypeResult == 0) {
    return -1;
  }

  return 0;
}

int clearSingleFunction(OpenGLSingleFunction *pSingleFunction)
{
  if (pSingleFunction == 0)
  {
    return 1;
  }
  if (pSingleFunction->numParameters > 0)
  {
    if (pSingleFunction->pParameters == 0)
    {
      return 2;
    }
    free(pSingleFunction->pParameters);
    pSingleFunction->pParameters = 0;
  }
  return 0;
}

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

#ifdef PARSER_SOME_PREVIOUS_IS_EMPTY_CHAR_STAFF
#define IS_EMPTY_CHAR PARSER_SOME_PREVIOUS_IS_EMPTY_CHAR_STAFF
#endif
