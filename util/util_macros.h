#ifndef __UTIL_MACROS__
#define __UTIL_MACROS__

#define TIME_MILLI(V) (V.tv_sec * 1000 + V.tv_usec / 1000)
#define TIME_MICRO(V) (V.tv_sec * 1000 * 1000 + V.tv_usec)

#endif