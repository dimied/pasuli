
#include <math.h>

#include "interpreter_config.h"
#ifdef PARSE_CODE_TEXT
#include <stdio.h>
#endif
#include "interpreter.h"

#define TOTAL_NUM_COMMANDS 16

#if PARSE_CODE_TEXT

#ifndef NEED_COMMANDS
#define NEED_COMMANDS 1
#endif

#endif

#if PARSE_CODE_VERBOSE

#ifndef NEED_COMMANDS
#define NEED_COMMANDS 1
#endif

#endif

#ifdef NEED_COMMANDS
const char *Commands[TOTAL_NUM_COMMANDS] = {
    "INIT/END (%i)",
    "SAVE ACCUM -> REG(%i)",
    "LOAD ACCUM <- REG(%i)",
    "SWITCH CODE PALETTE TO %i",
    //
    "ADD REG(%i) TO ACCUM -> ACCUM",
    "SUB REG(%i) FROM ACCUM -> ACCUM",
    "MUL REG(%i) BY ACCUM -> ACCUM",
    "DIV ACCUM BY REG(%i) -> ACCUM",
    //
    "PUSH REG (%i)",
    "POP REG (%i) -> ACCUM",
    "NEGATE REG (%i) -> REG",
    "EXP ACCUM BY REG(%i)",
    //
    "SQRT REG(%i) -> ACCUM",
    "LOG REG(%i) -> ACCUM",
    "COS REG(%i) -> ACCUM",
    "SIN REG(%i) -> ACCUM",
};
#endif

#ifdef PARSE_CODE_TEXT

void printBits(int const size, void const *const ptr, int sizes, int breakAfter, int skip)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j, c = 0;

    int s = 0;

    for (i = size - 1; i >= 0; i--)
    {

        for (j = 7; j >= 0; j--)
        {
            if (c < skip)
            {
                ++s;
                ++c;
                continue;
            }
            if (c >= breakAfter)
            {
                return;
            }
            if (s > 0 && s % sizes == 0)
            {
                printf(" ");
            }
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
            ++s;
            ++c;
        }
    }
    // puts("");
}

#define MODE_UNKNOWN 0
#define MODE_SETUP_START 1
#define MODE_SETUP_RUNNING 2

void parseCodeText(int nProgBytes, unsigned char *pProgs)
{
    printf("---\n");
    int mode = 0;
    int cmd = 0, paramValue = 0;
    int cmdRun = 0;
    int shift = CMD_DEFAULT_SHIFT;
    int paramMask = 4;

    int ln = 0;

    while (ln < nProgBytes)
    {
        unsigned char code = *pProgs;
    MODE_SWITCH:
        printf("(%i) ", ln);
        printBits(1, &code, 4, 8, 0);
        printf(": ");

        cmd = (code >> shift) & 0xF;
        paramMask = ((0x1 << (shift)) - 1);
        paramValue = code & paramMask;

        printf("[ ");
        printBits(1, &code, 16, 8 - shift, 0);
        printf(" , ");
        printBits(1, &code, 16, 16, shift);
        printf(" ](x<<%i) ", shift);
        // printf("[ %i, %i]", cmd, param);

        switch (mode)
        {
        case MODE_UNKNOWN: // unknown
            printf("(UNKNOWN):");

            if (cmd == 0)
            {
                mode = MODE_SETUP_START;
                printf("\n");
                goto MODE_SWITCH;
            }
            // printf("");
            break;
        case MODE_SETUP_START:
            printf("(START):");
            mode = MODE_SETUP_RUNNING;
            printf("PROG %i", paramValue);
            if (paramValue == 0)
            {
                printf(" (START INIT!)");
                shift = CMD_SETUP_SHIFT;
            }
            else
            {
                shift = CMD_DEFAULT_SHIFT;
            }
            cmdRun = paramValue;
            if (cmdRun == 1)
            {
                printf(" (PROG U)");
            }
            if (cmdRun == 2)
            {
                printf(" (PROG V)");
            }
            break;
        case MODE_SETUP_RUNNING:
            printf("(PROG):%i:", cmdRun);
            if (cmd == 0)
            {
                if (paramValue == cmdRun)
                {
                    printf("FINISH %i\n", paramValue);
                }
                else
                {
                    printf(" UNKNOWN => ERROR");
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
                    printf("LOAD PARAMS: %i", paramValue);
                    break;
                case CMD_SETUP_SET_PARAM_REGS_VAL:
                    printf("PARAM REGS: (%i, %i)", paramValue, paramValue + 1);
                    break;
                case CMD_SETUP_SET_RESULT_REGS_VAL:
                    printf("RESULT REGS: (%i, %i, %i) ", paramValue, paramValue + 1, paramValue + 2);
                    break;
                default:
                    printf("UNKNOWN (%i): => ERROR, (PARAM: %i)", cmd, paramValue);
                }
            }
            else
            {
                if (cmd < TOTAL_NUM_COMMANDS)
                {
                    printf(" ");
                    printf(Commands[cmd], paramValue);
                }
                else
                {
                    printf("UNKNOWN COMMAND %i", cmd);
                }
            }
            break;
        default:
            printf("UNKNOWN COMMAND => ERROR");
            break;
        }
        printf("\n");
        ++pProgs;
        ++ln;
    }
    printf("---\n");
}
#endif

void calc(int lineU, int to, int shift, float *registers, unsigned char *pMyProgs, int opts)
{
    while (lineU < to)
    {
        int code = pMyProgs[lineU];
        int cmd = (code >> shift) & 0xF;
        int paramMask = ((0x1 << (shift)) - 1);
        int paramValue = code & paramMask;
#if PARSE_CODE_VERBOSE
        if (opts > 0)
        {
            printf("CMD/PARAM: %i | %i ", cmd, paramValue);
            if (cmd < TOTAL_NUM_COMMANDS)
            {
                printf(Commands[cmd], paramValue);
            }
            printf("\n");
            printf("  ");
        }
#endif

        switch (cmd)
        {
        case CMD_SAVE_ACCUM_TO_REG:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("ACCUM -> REG(%i) = %f\n", paramValue, registers[0]);
            }

#endif
            registers[paramValue] = registers[0];
            break;
        case CMD_LOAD_ACCUM_FROM_REG:
            registers[0] = registers[paramValue];
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("REG(%i) -> ACCUM = %f\n", paramValue, registers[0]);
            }
#endif
            break;
        case CMD_ADD:
#if PARSE_CODE_VERBOSE

            printf("ACCUM + REG(%i)-> ACCUM = %f + %f = %f\n",
                   paramValue, registers[0], registers[paramValue], registers[paramValue] + registers[0]);
#endif
            registers[0] += registers[paramValue];
            break;
        case CMD_SUB:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("ACCUM - REG(%i)-> ACCUM = %f - %f = %f\n",
                       paramValue, registers[0], registers[paramValue], registers[0] - registers[paramValue]);
            }
#endif
            registers[0] -= registers[paramValue];
            break;
        case CMD_MUL_BY_REG:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("ACCUM * REG(%i)-> ACCUM = %f * %f = %f\n",
                       paramValue, registers[0], registers[paramValue], registers[0] * registers[paramValue]);
            }
#endif
            registers[0] *= registers[paramValue];
            break;
        case CMD_DIV_BY_REG:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("ACCUM / REG(%i)-> ACCUM = %f * %f = %f\n",
                       paramValue, registers[0], registers[paramValue], registers[0] / registers[paramValue]);
            }
#endif
            registers[0] /= registers[paramValue];
            break;

        case CMD_PUSH:
            // TODO
            break;
        case CMD_POP:
            // TODO
            break;

        case CMD_NEGATE_REG:
            registers[0] = -registers[paramValue];
            break;
        case CMD_POW:
            registers[0] = (float)pow(registers[0], registers[paramValue]);
            break;
        case CMD_SQRT:
            registers[0] = sqrtf(registers[paramValue]);
            break;
        case CMD_LOG_REG:
            registers[0] = logf(registers[paramValue]);
            break;

        case CMD_COS:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("COS( REG(%i) )-> ACCUM = cos(%f) = %f\n",
                       paramValue, registers[paramValue], (float)cos((double)registers[paramValue]));
            }
#endif
            registers[0] = cosf(registers[paramValue]);
            break;
        case CMD_SIN:
#if PARSE_CODE_VERBOSE
            if (opts > 0)
            {
                printf("SIN( REG(%i) )-> ACCUM = sin(%f) = %f\n",
                       paramValue, registers[paramValue], (float)sin((double)registers[paramValue]));
            }
#endif
            registers[0] = sinf(registers[paramValue]);
            break;
        }
        ++lineU;
    }
}

void parseCode(
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
#if PARSE_CODE_VERBOSE
    printf("---EXEC---\n");
#endif
    int paramMask, mode = 0, cmd = 0, paramValue = 0, cmdRun = 0, currentLine = 0;
    int uRegIndex = 1, vRegIndex = 2, regIndex = 1, resultRegisterIdx = 13;
    int shift = CMD_DEFAULT_SHIFT;
    unsigned char *pMyProgs = pProgs;

    int progStarts[16] = {0};
    int progEnds[16] = {0};
    float registers[16] = {0.0};

    while (currentLine < nProgBytes)
    {
        unsigned char code = *pProgs;
    MODE_SWITCH:
#if PARSE_CODE_VERBOSE
        printf("(%i) ", currentLine);
        // printBits(1, &code, 4, 8, 0);
        printf(": ");
#endif

        cmd = (code >> shift) & 0xF;
        paramMask = ((0x1 << (shift)) - 1);
        paramValue = code & paramMask;

        // printf("[ ");
        // printBits(1, &code, 16, 8 - shift, 0);
        // printf(" , ");
        // printBits(1, &code, 16, 16, shift);
        // printf(" ](x<<%i) ", shift);

        // printf("[ %i, %i]", cmd, param);

        switch (mode)
        {
        case MODE_UNKNOWN: // unknown
#if PARSE_CODE_VERBOSE
            printf("(UNKNOWN):");
#endif
            if (cmd == 0)
            {
                mode = MODE_SETUP_START;
                printf("\n");
                goto MODE_SWITCH;
            }
            // printf("");
            break;
        case MODE_SETUP_START:
            printf("(START):");
            mode = MODE_SETUP_RUNNING;
            printf("PROG %i", paramValue);
            if (paramValue == 0)
            {
                printf(" (START INIT!)");
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
            printf("(PROG):%i:", cmdRun);
            if (cmd == 0)
            {
                if (paramValue == cmdRun)
                {
                    printf("FINISH %i\n", paramValue);
                    progEnds[cmdRun] = currentLine;
                    cmdRun = -1;
                }
                else
                {
                    printf(" UNKNOWN => ERROR");
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
                    while (paramValue > 0)
                    {
                        registers[regIndex] = *pProgParams;
                        --paramValue;
                        ++regIndex;
                        ++pProgParams;
                    }
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
                    printf("UNKNOWN (%i): => ERROR, (PARAM: %i)", cmd, paramValue);
                }
            }
            break;
        default:
#if PARSE_CODE_VERBOSE
            printf("UNKNOWN COMMAND => ERROR");
#endif
            break;
        }
        //
#if PARSE_CODE_VERBOSE
        printf("\n");
#endif
        ++pProgs;
        ++currentLine;
    }

#if PARSE_CODE_VERBOSE
    printf("PROG-U: %i - %i | V: %i-%i\n", progStarts[1], progEnds[1], progStarts[2], progEnds[2]);
#endif
    shift = CMD_DEFAULT_SHIFT;
    int doCalcU = progStarts[1] < progEnds[1];
    int doCalcV = progStarts[2] < progEnds[2];
    int stepU = GET_STEP_U(sampleSteps);
    int stepV = GET_STEP_V(sampleSteps);
    int opts = 1;

    printf("->REGS\n");
    for (int i = 0; i < 16; i++)
    {
        if (i > 0 && i % 2 == 0)
        {
            printf("\n");
        }
        printf("(%i) = (%f) ", i, registers[i]);
    }
    printf("\n-<REGS\n");

    for (int idxU = 0; idxU < nSamplesU; idxU++)
    {
        registers[uRegIndex] = *pSamplesU;
        pSamplesU += stepU;

        if (doCalcU)
        {
            calc(progStarts[1], progEnds[1], shift, registers, pMyProgs, opts);
        }

        for (int idxV = 0; idxV < nSamplesV; idxV++)
        {
            registers[vRegIndex] = *pSamplesV;
            pSamplesV += stepV;

            if (doCalcV)
            {
                calc(progStarts[2], progEnds[2], shift, registers, pMyProgs, opts);
            }
            int i = resultRegisterIdx + 2;
            while (i >= resultRegisterIdx)
            {
                if (fabs(registers[i]) < 0.000001)
                {
                    registers[i] = 0;
                }
                --i;
            }

            *pResults = registers[resultRegisterIdx];
            ++pResults;
            *pResults = registers[resultRegisterIdx + 1];
            ++pResults;
            *pResults = registers[resultRegisterIdx + 2];
            ++pResults;
            opts = 0;
        }
    }
#if PARSE_CODE_VERBOSE
    printf("---EXEC-END---\n");
#endif
}
