#ifndef __OPENGL_HEADER_PARSER__
#define __OPENGL_HEADER_PARSER__

#define OGL_FUNC_NAME_MAX_LENGTH 40
#define OGL_FUNC_PARAMETER_TYPE_MAX_LENGTH 30
#define OGL_FUNC_PARAMETER_NAME_MAX_LENGTH 20
#define OGL_FUNC_RETURN_TYPE_MAX_LENGTH 20

#define PARSER_VOID_TYPE 1
#define PARSER_BOOLEAN_TYPE 2
#define PARSER_BITFIELD_TYPE 3

#define PARSER_CHAR_TYPE 4
#define PARSER_BYTE_TYPE 4
#define PARSER_UBYTE_TYPE 5

#define PARSER_SHORT_TYPE 6
#define PARSER_USHORT_TYPE 7

#define PARSER_INT_TYPE 8
#define PARSER_UINT_TYPE 9

#define PARSER_SIZEI_TYPE 10

#define PARSER_ENUM_TYPE 11

#define PARSER_FLOAT_TYPE 12
#define PARSER_CLAMPF_TYPE 13

#define PARSER_DOUBLE_TYPE 14
#define PARSER_CLAMPD_TYPE 15

#define PARSER_PTR_TYPE 0x20
#define PARSER_PTR_PTR_TYPE 0x40

typedef struct _OpenGLParameter
{
  char sType[OGL_FUNC_PARAMETER_TYPE_MAX_LENGTH];
  char *pType;
  char sName[OGL_FUNC_PARAMETER_NAME_MAX_LENGTH];
  char *pName;
  char iType;
  char isPtr;
} OpenGLParameter;

typedef struct _OpenGLSingleFunction
{
  int glVersion;
  // array to store function name
  char sFuncName[OGL_FUNC_NAME_MAX_LENGTH];
  // if array is not enough, then memory is dynamically allocated for func name
  // char *pFuncName;
  // stores return types
  char sReturnType[OGL_FUNC_RETURN_TYPE_MAX_LENGTH];
  // if array is not enough, then memory is dynamically allocated for return
  // type
  // char *pReturnType;
  // pointer to array containing numParameters elements
  OpenGLParameter *pParameters;
  // number of parameters
  int numParameters;
  char iReturnType;
  char iReturnTypePtr;
} OpenGLSingleFunction;

typedef struct _OpenGLFunctions
{
  // file path, optional
  char *pFilepath;
  // GL version recognized
  char glVersion[20];
  int numFunctions;
  // pointer to an array with numFunctions values
  OpenGLSingleFunction *pFunctions;
  // pointer to other functions, real type is OpenGLFunctions*,
  // i.e. it's a linked list
  void *pNextFunctions;
} OpenGLFunctions;

#ifndef PARSE_HEADER_VERBOSE
#define PARSE_HEADER_VERBOSE 1
#endif

int parseOpenGLHeaderFile(char *fileContent, OpenGLFunctions *pFunctions);

int clearFunctions(OpenGLFunctions *pFunctions);
int clearSingleFunction(OpenGLSingleFunction *pSingleFunction);

int showHeaderInfo(OpenGLFunctions *pFunctions);

#endif