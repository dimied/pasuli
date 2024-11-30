#ifndef __CODE_INTEPRETER__
#define __CODE_INTEPRETER__

#include "interpreter_config.h"

#define DEFINE_STEPS(U, V) (U | V << 4)
#define GET_STEP_U(VAL)    (VAL & 0xF)
#define GET_STEP_V(VAL)    ((VAL >> 4) U & 0xF)

#define GET_CMD(VAL)       ((VAL >> 4) & 0xF)
#define GET_PARAM(VAL)     (VAL & 0xF)

#define COMMAND(CMD, PARAM)     ((CMD<<4) + PARAM)
#define CMD_SETUP_START 0
#define CMD_SETUP_END 0
#define CMD_SETUP_INIT 0

#define CMD_SETUP_U 1
#define CMD_SETUP_V 2

#define CMD_DEFAULT_SHIFT 4
#define CMD_SETUP_SHIFT 5

//
#define CMD_SETUP_LOAD_PARAMS_VAL 0x2
#define CMD_SETUP_SET_PARAM_REGS_VAL 0x3
#define CMD_SETUP_SET_RESULT_REGS_VAL 0x4

#define CMD_SETUP_SET_U_SIZE_VAL 0x5
#define CMD_SETUP_SET_V_SIZE_VAL 0x6

//010?? ????
#define CMD_SETUP_LOAD_PARAMS(NUM_PARAMS)  ((CMD_SETUP_LOAD_PARAMS_VAL<<CMD_SETUP_SHIFT) | NUM_PARAMS)
#define CMD_SETUP_SET_PARAM_REGS(REG_START)  ((CMD_SETUP_SET_PARAM_REGS_VAL<<CMD_SETUP_SHIFT) | REG_START)
#define CMD_SETUP_SET_RESULT_REGS(REG_START)  ((CMD_SETUP_SET_RESULT_REGS_VAL<<CMD_SETUP_SHIFT) | REG_START)

#define CMD_SETUP_SET_U_SIZE(SZ)  ((CMD_SETUP_SET_U_SIZE_VAL<<CMD_SETUP_SHIFT) | SZ)
#define CMD_SETUP_SET_V_SIZE(SZ)  ((CMD_SETUP_SET_V_SIZE_VAL<<CMD_SETUP_SHIFT) | SZ)

#define CMD_SAVE_ACCUM_TO_REG 1
#define CMD_LOAD_ACCUM_FROM_REG 2
#define CMD_MUL_BY_REG 6

#define CMD_COS 12
#define CMD_SIN 13

#define REG_ACCUM 0
#define REG(X)  (X)

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
void parseCode(float *pSamplesU, int nSamplesU, float *pSamplesV, int nSamplesV,
               int sampleSteps, float *pConstants, float *pProgParams,
               int nProgBytes, unsigned char *pProgs, float *pResults);

#ifdef PARSE_CODE_TEXT
/**
 * For debuging
 */
void parseCodeText(int nProgBytes, unsigned char *pProgs);
#endif

#endif