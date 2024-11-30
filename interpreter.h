#ifndef __CODE_INTEPRETER__
#define __CODE_INTEPRETER__

#define DEFINE_STEPS(U, V) (U | V << 4)
#define GET_STEP_U(VAL)   (VAL&0xF)
#define GET_STEP_V(VAL)   ((VAL>>4)U&0xF)

/**
 * @param pSamplesU
 * @param nSamplesU
 * @param pSamplesV
 * @param nSamplesV
 * @param sampleSteps lowest 4 bits for U, bits 4-7 for V
 * @param pConstants
 */
void parseCode(float *pSamplesU, int nSamplesU, float *pSamplesV, int nSamplesV,
               int sampleSteps, float *pConstants, float *pProgParams,
               int nProgBytes, unsigned char *pProgs);
#endif