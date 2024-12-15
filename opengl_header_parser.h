#ifndef __OPENGL_HEADER_PARSER__
#define __OPENGL_HEADER_PARSER__

#define OGL_FUNC_NAME_MAX_LENGTH 40
#define OGL_FUNC_PARAMETER_TYPE_MAX_LENGTH 30
#define OGL_FUNC_PARAMETER_NAME_MAX_LENGTH 20
#define OGL_FUNC_RETURN_TYPE_MAX_LENGTH 20

typedef struct _OpenGLParameter {
  char type[OGL_FUNC_PARAMETER_TYPE_MAX_LENGTH];
  char *pType;
  char name[OGL_FUNC_PARAMETER_NAME_MAX_LENGTH];
  char *pName;
} OpenGLParameter;

typedef struct _OpenGLSingleFunction {
  int glVersion;
  // array to store function name
  char funcName[OGL_FUNC_NAME_MAX_LENGTH];
  // if array is not enough, then memory is dynamically allocated for func name
  char *pFuncName;
  // stores return types
  char returnType[OGL_FUNC_RETURN_TYPE_MAX_LENGTH];
  // if array is not enough, then memory is dynamically allocated for return
  // type
  char *pRreturnType;
  // number of parameters
  int numParameters;
  // pointer to array containing numParameters elements
  OpenGLParameter *pParameters;
} OpenGLSingleFunction;

typedef struct _OpenGLFunctions {
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

int showHeaderInfo(OpenGLFunctions *pFunctions);

#endif