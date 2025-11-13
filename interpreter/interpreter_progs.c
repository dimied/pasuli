
#include "interpreter_progs.h"
#include "interpreter.h"

/*
reg1 = r
reg2 = theta
reg3 = phi

reg4 = rsin
reg5 = x
reg6 = y
reg7 = z

sin theta (reg2)  => accum
mul by r (reg1) => accum
save accum to rsin (reg4)

cos phi ( reg3) => accum
mul by rsin (reg4) => accum
save to x (reg5)

sin phi (reg3) => accum
mul by rsin (reg4) => accum
save to y (reg6)

cos theta (reg2) => accum
mul by r (reg1) => accum
save to z (reg7)
*/

unsigned char circleProgs[CIRCLE_PROG_BYTES] = {
    SPHERE_PROG

};
#if 0
    COMMAND(CMD_SETUP_START, CMD_SETUP_INIT),
    // load r
    CMD_SETUP_LOAD_PARAMS(1),
    // set  param regs: 2(theta), 3(phi)
    CMD_SETUP_SET_PARAM_REGS(REG(2)),
    // set result regs 5(x), 6(y), 7(z)
    CMD_SETUP_SET_RESULT_REGS(REG(5)),
    COMMAND(CMD_SETUP_END, CMD_SETUP_INIT),
    ////
    COMMAND(CMD_SETUP_START, CMD_SETUP_U),
    // z = r*cos()
    COMMAND(CMD_COS, REG(2)),
    COMMAND(CMD_MUL_BY_REG, REG(1)),
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(7)),
    // r*sin()
    COMMAND(CMD_SIN, REG(2)),
    COMMAND(CMD_MUL_BY_REG, REG(1)),
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(4)),
    COMMAND(CMD_SETUP_END, CMD_SETUP_U),
    //
    //
    COMMAND(CMD_SETUP_START, CMD_SETUP_V),
    // x
    COMMAND(CMD_COS, REG(3)),
    COMMAND(CMD_MUL_BY_REG, REG(4)),
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(5)),
    // y
    COMMAND(CMD_SIN, REG(3)),
    COMMAND(CMD_MUL_BY_REG, REG(4)),
    COMMAND(CMD_SAVE_ACCUM_TO_REG, REG(6)),
    COMMAND(CMD_SETUP_END, CMD_SETUP_V)
#endif