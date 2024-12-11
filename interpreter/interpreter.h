#ifndef __CODE_INTEPRETER__
#define __CODE_INTEPRETER__

#include <stdlib.h>
#include "interpreter_config.h"
#include "interpreter_commands.h"


#define PI (float)3.14159265358979323846f

#define DEFINE_STEPS(U, V) (U | (V << 4))
#define GET_STEP_U(VAL) (VAL & 0xF)
#define GET_STEP_V(VAL) ((VAL >> 4) & 0xF)

#define GET_CMD(VAL) ((VAL >> 4) & 0xF)
#define GET_PARAM(VAL) (VAL & 0xF)


#define TOTAL_NUM_COMMANDS 16

#define MODE_UNKNOWN 0
#define MODE_SETUP_START 1
#define MODE_SETUP_RUNNING 2

#ifdef NEED_COMMANDS
extern const char *Commands[TOTAL_NUM_COMMANDS];
#endif

typedef struct OverflowInfo {
    int indexU;
    int indexV;
    int mode;
}OverflowInfo;

#define INVALID_ACCESS_U 1
#define INVALID_ACCESS_V 2
#define INVALID_ACCESS_RESULT 3
#define INVALID_COMMAND 4

/**
 * @param pSamplesU pointer to U samples
 * @param nSamplesU number of samples for U direction
 * @param pSamplesV pointer to V samples
 * @param nSamplesV number of samples for V direction
 * @param sampleSteps lowest 4 bits for U, bits 4-7 for V
 * @param pConstants pointer to global constants
 * @param pProgParams prog params, prog will know how to use them
 * @param nProgBytes number of prog bytes
 * @param pProgs pointer to prog bytes
 */
int parseCode(float *pSamplesU, int nSamplesU, float *pSamplesV, int nSamplesV,
               int sampleSteps, float *pConstants, float *pProgParams,
               int nProgBytes, unsigned char *pProgs, float *pResults);

void setParseCodeOptions(int opts);
void getOverflowInfo(OverflowInfo* pInfo);

void nullify(float *pData, size_t size);
void zeroWithinLimit(float* pResults, float limit, size_t size);
#ifdef PARSE_CODE_TEXT
/**
 * For debuging
 */
void parseCodeText(int nProgBytes, unsigned char *pProgs);
#endif

#endif