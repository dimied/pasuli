#ifndef __CODE_INTEPRETER_CONFIG__
#define __CODE_INTEPRETER_CONFIG__

#define PARSE_CODE_TEXT 1

#define PARSE_CODE_VERBOSE 0

#define PARSE_CODE_MEMCPY 0

#define PARSE_CODE_PTR_CHECK 0

#define PARSE_CODE_ZERO_CLAMP 0

#define PARSE_CODE_CUSTOM_STEP_U 0

#define PARSE_CODE_CUSTOM_STEP_V 0


////
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

#endif