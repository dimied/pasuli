#ifndef __PASULI_DESCRIPTION_PARSER_INCL__
#define __PASULI_DESCRIPTION_PARSER_INCL__

#define MAX_NAME_LENGTH 30
#define MAX_CATEGORY_LENGTH 10
#define MAX_RANGE_LENGTH 10
#define MAX_FUNCTION_LENGTH 160
#define MAX_NUMBER_OF_CONSTANTS 12
#define MAX_NUMBER_OF_ABBREVIATIONS 4

typedef struct {
    char name[10];
    char value[10];
} PaSuLiFunctionDescriptionConstant;


typedef PaSuLiFunctionDescriptionConstant PaSuLiFunctionDescriptionAbbreviation;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    //
    char uRangeStart[MAX_RANGE_LENGTH];
    char uRangeEnd[MAX_RANGE_LENGTH];
    char u_Pi;
    //
    char vRangeStart[MAX_RANGE_LENGTH];
    char vRangeEnd[MAX_RANGE_LENGTH];
    char v_Pi;
    //
    PaSuLiFunctionDescriptionConstant constants[MAX_NUMBER_OF_CONSTANTS];
    //
    PaSuLiFunctionDescriptionAbbreviation abbreviations[MAX_NUMBER_OF_ABBREVIATIONS];
    // Position
    char x[MAX_FUNCTION_LENGTH];
    char y[MAX_FUNCTION_LENGTH];
    char z[MAX_FUNCTION_LENGTH];
    // Normal
    char xn[MAX_FUNCTION_LENGTH];
    char yn[MAX_FUNCTION_LENGTH];
    char zn[MAX_FUNCTION_LENGTH];
    //
    char xu[MAX_FUNCTION_LENGTH];
    char yu[MAX_FUNCTION_LENGTH];
    char zu[MAX_FUNCTION_LENGTH];
    //
    char xv[MAX_FUNCTION_LENGTH];
    char yv[MAX_FUNCTION_LENGTH];
    char zv[MAX_FUNCTION_LENGTH];
    //
    char xuu[MAX_FUNCTION_LENGTH];
    char yuu[MAX_FUNCTION_LENGTH];
    char zuu[MAX_FUNCTION_LENGTH];
    //
    char xuv[MAX_FUNCTION_LENGTH];
    char yuv[MAX_FUNCTION_LENGTH];
    char zuv[MAX_FUNCTION_LENGTH];
    //
    char xvv[MAX_FUNCTION_LENGTH];
    char yvv[MAX_FUNCTION_LENGTH];
    char zvv[MAX_FUNCTION_LENGTH];


} PaSuLiFunctionDescription;

int parseDescription(char *pDescription, PaSuLiFunctionDescription *pResult);
int printDescription(PaSuLiFunctionDescription *pDesc);

#endif
