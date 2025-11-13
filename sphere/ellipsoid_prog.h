#ifndef __PASULI_ELLIPSOID_PROG__
#define __PASULI_ELLIPSOID_PROG__

//#include "../pasuli_cfg.h"
//#include "../pasuli_defs.h"
#include "../interpreter/interpreter_commands.h"

#define ELLIPSOID_PROG \
	COMMAND(CMD_SETUP_START, CMD_SETUP_INIT),\
	COMMAND_COMMENT("load r") \
    CMD_SETUP_LOAD_PARAMS(1), \
	COMMAND_COMMENT("set  param regs: 2(theta), 3(phi)") \
    CMD_SETUP_SET_PARAM_REGS(REG(2)), \
    COMMAND_COMMENT("set result regs 5(x), 6(y), 7(z)") \
    CMD_SETUP_SET_RESULT_REGS(REG(5)), \
    COMMAND(CMD_SETUP_END, CMD_SETUP_INIT), \
    COMMAND(CMD_SETUP_START, CMD_SETUP_U), \
    COMMAND(CMD_COS, REG(2)), \
    COMMAND(CMD_MUL_BY_REG, REG(1)),\
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(7)),\
    COMMAND(CMD_SIN, REG(2)),\
    COMMAND(CMD_MUL_BY_REG, REG(1)), \
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(4)), \
    COMMAND(CMD_SETUP_END, CMD_SETUP_U), \
    COMMAND(CMD_SETUP_START, CMD_SETUP_V), \
    COMMAND(CMD_COS, REG(3)), \
    COMMAND(CMD_MUL_BY_REG, REG(4)), \
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(5)), \
    COMMAND(CMD_SIN, REG(3)),\
    COMMAND(CMD_MUL_BY_REG, REG(4)),\
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(6)),\
    COMMAND(CMD_SETUP_END, CMD_SETUP_V)

#define ELLIPSOID_PROG_SIZE 21

#endif
