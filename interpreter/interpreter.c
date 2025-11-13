
#include <math.h>

#include "interpreter_config.h"
#ifdef PARSE_CODE_TEXT
#include <stdio.h>
#endif
#include <string.h>

#include "interpreter.h"
#include "interpreter_debug.h"
#include "interpreter_cmd_config.h"
#include "../util/util_macros.h"

#if PARSE_CODE_VERBOSE

void printCommand(int cmd, int paramValue)
{
    printf("CMD/PARAM: %i | %i ", cmd, paramValue);
    if (cmd < TOTAL_NUM_COMMANDS)
    {
        printf(Commands[cmd], paramValue);
    }
    printf("\n");
    printf("  ");
}
#define PRINT_COMMAND(cmd, paramValue, opts) \
    if (opts > 0)                            \
    {                                        \
        printCommand(cmd, paramValue);       \
    }

#define PRINT_DEBUG_LINE(currentLine, opts) \
    if (opts > 0)                           \
    {                                       \
        printf("(%i) ", currentLine);       \
        printf(": ");                       \
    }
#else
#define PRINT_COMMAND(cmd, paramValue, opts)
#define PRINT_DEBUG_LINE(currentLine, opts)
#endif

int globalOpts = 0;
OverflowInfo overflow;

void setParseCodeOptions(int opts)
{
    globalOpts = opts;
}

void getOverflowInfo(OverflowInfo *pInfo)
{
    if (pInfo != NULL)
    {
        pInfo->indexU = overflow.indexU;
        pInfo->indexV = overflow.indexV;
        pInfo->mode = overflow.mode;
    }
}

int parseCode(
    float *pSamplesU,
    int nSamplesU,
    float *pSamplesV,
    int nSamplesV,
    int sampleSteps,
    float *pConstants,
    float *pProgParams,
    int nProgBytes,
    unsigned char *pProgs,
    float *pResults)
{
    int mode = 0, cmd = 0, paramValue = 0, cmdRun = 0, currentLine = 0;
    int uRegIndex = 1, vRegIndex = 2, regIndex = 1, resultRegisterIdx = 13;
    int shift = CMD_DEFAULT_SHIFT;
    float *pInitSamplesV = pSamplesV;

#if PARSE_CODE_PTR_CHECK
    float *const pResultsEnd = pResults + (nSamplesU * nSamplesV * 3);

    float *const pSamplesEndU = pSamplesU + nSamplesU;
    float *const pSamplesEndV = pSamplesV + nSamplesV;
#endif
#if 0
    printf("PTR-U: %p %p %li\n", pSamplesU, pSamplesEndU, (pSamplesEndU - pSamplesU));
    printf("PTR-V: %p %p %li\n", pSamplesV, pSamplesEndV, (pSamplesEndV - pSamplesV));
#endif

    int opts = globalOpts;
    int progStarts[16] = {0};
    int progEnds[16] = {0};
    float registers[16] = {0.0};

    if (opts > 0)
    {
        printf("---EXEC---\n");
    }

    unsigned char code;

    while (currentLine < nProgBytes)
    {
        code = pProgs[currentLine];
    MODE_SWITCH:
        PRINT_DEBUG_LINE(currentLine, opts)

        cmd = (code >> shift) & 0xF;
        paramValue = ((0x1 << (shift)) - 1);
        paramValue = code & paramValue;

        switch (mode)
        {
        case MODE_UNKNOWN: // unknown
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("(UNKNOWN):");
            }

#endif
            if (cmd == 0)
            {
                mode = MODE_SETUP_START;
#if PARSE_CODE_VERBOSE
                if (opts > 0)
                {
                    printf("\n");
                }
#endif
                goto MODE_SWITCH;
            }
            break;
        case MODE_SETUP_START:
            mode = MODE_SETUP_RUNNING;
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("(START):PROG %i", paramValue);
            }

#endif
            if (paramValue == 0)
            {
#if PARSE_CODE_VERBOSE
                if (opts > 0)
                {
                    printf(" (START INIT!)");
                }
#endif
                shift = CMD_SETUP_SHIFT;
            }
            else
            {
                shift = CMD_DEFAULT_SHIFT;
            }
            cmdRun = paramValue;
            progStarts[cmdRun] = currentLine + 1;
            break;
        case MODE_SETUP_RUNNING:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("(PROG):%i:", cmdRun);
            }
#endif
            if (cmd == 0)
            {
                if (paramValue == cmdRun)
                {
#if PARSE_CODE_VERBOSE
                    if (opts > 0)
                    {
                        printf("FINISH %i\n", paramValue);
                    }
#endif
                    progEnds[cmdRun] = currentLine;
                    cmdRun = -1;
                }
                else
                {
#if PARSE_CODE_VERBOSE
                    printf(" UNKNOWN => ERROR");
#endif
                }
                mode = MODE_UNKNOWN;
                shift = CMD_DEFAULT_SHIFT;
                break;
            }
            // SETUP?
            if (cmdRun == 0)
            {
                switch (cmd)
                {
                case CMD_SETUP_LOAD_PARAMS_VAL:
                    // printf("LOAD PARAMS: %i", paramValue);
#if PARSE_CODE_MEMCPY
                    memcpy(&registers[regIndex], pProgParams, paramValue*sizeof(float));
                    regIndex+= paramValue;
#else
                    while (paramValue > 0)
                    {
                        registers[regIndex++] = *pProgParams;
                        --paramValue;
                        ++pProgParams;
                    }
#endif
                    break;
                case CMD_SETUP_SET_PARAM_REGS_VAL:
                    // printf("PARAM REGS: (%i, %i)", paramValue, paramValue + 1);
                    uRegIndex = paramValue;
                    vRegIndex = paramValue + 1;
                    regIndex = vRegIndex + 1;
                    break;
                case CMD_SETUP_SET_RESULT_REGS_VAL:
                    // printf("RESULT REGS: (%i, %i, %i) ", paramValue, paramValue + 1, paramValue + 2);
                    resultRegisterIdx = paramValue;
                    break;
                default:
#if PARSE_CODE_VERBOSE
                    if (opts > 0)
                    {
                        printf("UNKNOWN (%i): => ERROR, (PARAM: %i)", cmd, paramValue);
                    }
#endif
                    break;
                }
            }
            break;
#if PARSE_CODE_VERBOSE
        default:

            if (opts > 0)
            {
                printf("UNKNOWN COMMAND => ERROR");
            }

            break;
#endif
        }
        //
#if PARSE_CODE_VERBOSE
        if (opts > 0)
        {
            printf("\n");
        }
#endif
        ++currentLine;
    }

#if PARSE_CODE_VERBOSE
    if (opts > 0)
    {
        printf("PROG-U: %i - %i | V: %i-%i\n", progStarts[1], progEnds[1], progStarts[2], progEnds[2]);
    }
#endif
    shift = CMD_DEFAULT_SHIFT;

#if PARSE_CODE_CUSTOM_STEP_U
    int stepU = GET_STEP_U(sampleSteps);
#endif
#if PARSE_CODE_CUSTOM_STEP_V
    int stepV = GET_STEP_V(sampleSteps);
#endif

#if PARSE_CODE_VERBOSE
    if (opts > 0)
    {
        printf("->REGS (u,v) = (%i,%i)| STEPS: u=%i,v=%i\n", uRegIndex, vRegIndex, stepU, stepV);
        for (int i = 0; i < 16; i++)
        {
            if (i > 0 && i % 2 == 0)
            {
                printf("\n");
            }
            printf("(%i) = (%f) ", i, registers[i]);
        }

        printf("\n-<REGS\n");
    }
#endif

    int modeV, codeLine, codeLineEnd, uStart = progStarts[1], uEnd = progEnds[1],
                                      vStart = progStarts[2], vEnd = progEnds[2];

    float *pResultRegs = &registers[resultRegisterIdx];

    for (int idxU = 0; idxU < nSamplesU; idxU++)
    {
#if PARSE_CODE_PTR_CHECK
        overflow.indexU = idxU;
        if (pSamplesEndU == pSamplesU)
        {
            return INVALID_ACCESS_U;
        }
#endif

        registers[uRegIndex] = *pSamplesU;
#if PARSE_CODE_CUSTOM_STEP_U
        pSamplesU += stepU;
#else
        ++pSamplesU;
#endif
        modeV = 0;
        codeLine = uStart;
        codeLineEnd = uEnd;
        pSamplesV = pInitSamplesV;

        for (int idxV = 0; idxV < nSamplesV;)
        {
#if PARSE_CODE_PTR_CHECK
            overflow.indexV = idxV;
            overflow.mode = modeV;
            if (pSamplesEndV == pSamplesV)
            {
                printf("INVALID V PTR %p %p\n", pSamplesV, pSamplesEndV);
                return INVALID_ACCESS_V;
            }
#endif

            registers[vRegIndex] = *pSamplesV;
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf(">> %i |@(u,v) = (%i, %i)\n", modeV, idxU, idxV);
            }
#endif
            while (codeLine < codeLineEnd)
            {
                code = pProgs[codeLine];
                cmd = (code >> shift) & 0xF;
                paramValue = ((0x1 << (shift)) - 1);
                paramValue = code & paramValue;

                PRINT_COMMAND(cmd, paramValue, opts)

                switch (cmd)
                {
                case CMD_SAVE_ACCUM_TO_REG:
                    PRINT_ACCUM_TO_REG(paramValue, registers[0], opts)
                    registers[paramValue] = registers[0];
                    break;
                case CMD_LOAD_ACCUM_FROM_REG:
                    registers[0] = registers[paramValue];
                    PRINT_REG_TO_ACCUM(paramValue, registers[0], opts)
                    break;
                case CMD_ADD:
                    PRINT_CMD_ADD(paramValue, registers, opts)
                    registers[0] += registers[paramValue];
                    break;
#if USE_CMD_SUB
                case CMD_SUB:
                    PRINT_CMD_SUB(paramValue, registers, opts)
                    registers[0] -= registers[paramValue];
                    break;
#endif
                case CMD_MUL_BY_REG:
                    PRINT_CMD_MUL(paramValue, registers, opts)
                    registers[0] *= registers[paramValue];
                    break;
#if USE_CMD_DIV
                case CMD_DIV_BY_REG:
                    PRINT_CMD_DIV(paramValue, registers, opts)
                    registers[0] /= registers[paramValue];
                    break;
#endif
#if USE_CMD_PUSH
                case CMD_PUSH: // TODO
                    break;
#endif
#if USE_CMD_POP
                case CMD_POP: // TODO
                    break;
#endif
#if USE_CMD_NEGATE
                case CMD_NEGATE_REG:
                    registers[0] = -registers[paramValue];
                    break;
#endif
#if USE_CMD_POW
                case CMD_POW:
                    registers[0] = (float)pow(registers[0], registers[paramValue]);
                    break;
#endif
#if USE_CMD_SQRT
                case CMD_SQRT:
                    registers[0] = sqrtf(registers[paramValue]);
                    break;
#endif
#if USE_CMD_LOG
                case CMD_LOG_REG:
                    registers[0] = logf(registers[paramValue]);
                    break;
#endif
                case CMD_COS:
                    PRINT_CMD_COS(paramValue, registers, opts)
                    registers[0] = cosf(registers[paramValue]);
                    break;
                case CMD_SIN:
                    PRINT_CMD_SIN(paramValue, registers, opts)
                    registers[0] = sinf(registers[paramValue]);
                    break;
                default:
                    return INVALID_COMMAND;
                }
                ++codeLine;
            }

            if (modeV)
            {
#if PARSE_CODE_ZERO_CLAMP
                if (fabs(*pResultRegs) < 0.000001)
                {
                    *pResultRegs = 0;
                }
                if (fabs(pResultRegs[1]) < 0.000001)
                {
                    pResultRegs[1] = 0;
                }
                if (fabs(pResultRegs[2]) < 0.000001)
                {
                    pResultRegs[2] = 0;
                }
#endif

#if PARSE_CODE_MEMCPY
                memcpy(pResults, pResultRegs, 3*sizeof(float));
#else
#if PARSE_CODE_PTR_CHECK
                //
                if (pResultsEnd == pResults)
                {
                    return INVALID_ACCESS_RESULT;
                }
#endif
                *pResults = *pResultRegs;
                ++pResults;
#if PARSE_CODE_PTR_CHECK
                if (pResultsEnd == pResults)
                {
                    return INVALID_ACCESS_RESULT;
                }
#endif
                *pResults = pResultRegs[1];
                ++pResults;
#if PARSE_CODE_PTR_CHECK
                if (pResultsEnd == pResults)
                {
                    return INVALID_ACCESS_RESULT;
                }
#endif
                *pResults = pResultRegs[2];
                ++pResults;
#endif

                ++idxV;
#if PARSE_CODE_CUSTOM_STEP_V
                pSamplesV += stepV;
#else
                ++pSamplesV;
#endif
            }
            else
            {
                modeV = 1; // else
                codeLineEnd = vEnd;
            }
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("<< %i\n", modeV);
            }
#endif
            // common
            codeLine = vStart;
        }
#if PARSE_CODE_VERBOSE
        if (opts > 0)
        {
            printf("----\n\n");
        }

#endif
        // opts = 0;
    }
#if PARSE_CODE_VERBOSE
    if (opts > 0)
    {
        printf("---EXEC-END---\n");
    }
#endif
    return 0;
}

void zeroWithinLimit(float *pResults, float limit, size_t size)
{
    while (size > 0)
    {
        if (fabs(*pResults) < limit)
        {
            *pResults = 0;
        }
        --size;
        ++pResults;
    }
}

void nullify(float *pData, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        *pData = 0;
        ++pData;
    }
}
