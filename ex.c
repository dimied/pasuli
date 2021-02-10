
#include <stdio.h>     // printf
/*
#include <stddef.h>    // size_t
#include <stdint.h>    // uint8_t, uint32_t
#include <math.h>
#include <stdio.h>     // printf
#include <string.h>    // memcpy
#include <sys/mman.h>  // mmap, mprotect, munmap, MAP_FAILURE
*/

#include "pasuli_defs.h"
#include "pasuli_macros.h"

PaSuLiObject example;

int main() {

    printf("Hello World \n");

    printf("Start %.2lf \n", example.pos[0]);

    initConstAll(&example, 1);
    
    printf("Set... %.2lf \n", example.pos[0]);

    return 0;
}