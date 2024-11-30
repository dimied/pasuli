
#include <math.h>
#include "interpreter_config.h"
#include "interpreter.h"

#ifdef PARSE_CODE_TEXT
#include <stdio.h>


#define TOTAL_NUM_COMMANDS 16
const char *Commands[TOTAL_NUM_COMMANDS] = {
    "INIT/END (%i)",
    "SAVE ACCUM -> REG(%i)",
    "LOAD ACCUM <- REG(%i)",
    "SWITCH CODE PALETTE TO %i",
    //
    "ADD REG(%i) TO ACCUM -> ACCUM",
    "SUB REG(%i) TO ACCUM -> ACCUM",
    "MUL REG(%i) BY ACCUM -> ACCUM",
    "DIV ACCUM BY REG(%i) -> ACCUM",
    //
    "PUSH REG (%i)",
    "POP REG (%i) -> ACCUM",
    "NEGATE REG (%i) -> REG",
    "EXP ACCUM BY REG(%i)",
    //
    "COS REG(%i) -> ACCUM",
    "SIN REG(%i) -> ACCUM",
    "??? %i",
    "??? %i",
};

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

    while (nProgBytes > 0)
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
            //printf("");
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
            if(cmdRun == 1) {
                printf(" (PROG U)");
            }
            if(cmdRun == 2) {
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
                if(cmd < TOTAL_NUM_COMMANDS) {
                    printf(" ");
                    printf(Commands[cmd], paramValue);
                } else {
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
        --nProgBytes;
        ++ln;
    }
    printf("---\n");
}
#endif

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
}
