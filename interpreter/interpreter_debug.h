#ifndef __CODE_INTEPRETER_DEBUG__
#define __CODE_INTEPRETER_DEBUG__
#include "interpreter_config.h"

#if PARSE_CODE_VERBOSE

#define PRINT_ACCUM_TO_REG(REG, ACCUM, opts)           \
    if (opts > 0)                                      \
    {                                                  \
        printf("ACCUM -> REG(%i) = %f\n", REG, ACCUM); \
    }

#define PRINT_REG_TO_ACCUM(REG, ACCUM, opts)           \
    if (opts > 0)                                      \
    {                                                  \
        printf("REG(%i) -> ACCUM = %f\n", REG, ACCUM); \
    }

#define PRINT_CMD_ADD(paramValue, registers, opts)                                                     \
    if (opts > 0)                                                                                      \
    {                                                                                                  \
        printf("ACCUM + REG(%i)-> ACCUM = %f + %f = %f\n",                                             \
               paramValue, registers[0], registers[paramValue], registers[paramValue] + registers[0]); \
    }

#define PRINT_CMD_SUB(paramValue, registers, opts)                                                     \
    if (opts > 0)                                                                                      \
    {                                                                                                  \
        printf("ACCUM - REG(%i)-> ACCUM = %f - %f = %f\n",                                             \
               paramValue, registers[0], registers[paramValue], registers[0] - registers[paramValue]); \
    }

#define PRINT_CMD_MUL(paramValue, registers, opts)                                                     \
    if (opts > 0)                                                                                      \
    {                                                                                                  \
        printf("ACCUM * REG(%i)-> ACCUM = %f * %f = %f\n",                                             \
               paramValue, registers[0], registers[paramValue], registers[0] * registers[paramValue]); \
    }

#define PRINT_CMD_DIV(paramValue, registers, opts)                                                     \
    if (opts > 0)                                                                                      \
    {                                                                                                  \
        printf("ACCUM / REG(%i)-> ACCUM = %f * %f = %f\n",                                             \
               paramValue, registers[0], registers[paramValue], registers[0] / registers[paramValue]); \
    }

#define PRINT_CMD_COS(paramValue, registers, opts)                              \
    if (opts > 0)                                                               \
    {                                                                           \
        printf("COS( REG(%i) )-> ACCUM = cos(%f) = %f\n",                       \
               paramValue, registers[paramValue], cosf(registers[paramValue])); \
    }

#define PRINT_CMD_SIN(paramValue, registers, opts)                              \
    if (opts > 0)                                                               \
    {                                                                           \
        printf("SIN( REG(%i) )-> ACCUM = sin(%f) = %f\n",                       \
               paramValue, registers[paramValue], sinf(registers[paramValue])); \
    }
#else
#define PRINT_COMMAND(cmd, paramValue, opts)
#define PRINT_ACCUM_TO_REG(REG, ACCUM, opts)
#define PRINT_REG_TO_ACCUM(REG, ACCUM, opts)
#define PRINT_CMD_ADD(paramValue, registers, opts)
#define PRINT_CMD_SUB(paramValue, registers, opts)
#define PRINT_CMD_MUL(paramValue, registers, opts)
#define PRINT_CMD_DIV(paramValue, registers, opts)
#define PRINT_CMD_COS(paramValue, registers, opts)
#define PRINT_CMD_SIN(paramValue, registers, opts)
#endif

#endif