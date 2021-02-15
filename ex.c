
#include <stdio.h>     // printf
/*
#include <stddef.h>    // size_t
#include <stdint.h>    // uint8_t, uint32_t
#include <string.h>    // memcpy
#include <sys/mman.h>  // mmap, mprotect, munmap, MAP_FAILURE
*/

#include "pasuli_defs.h"
#include "pasuli_macros.h"
#include "pasuli_repository.h"

PaSuLiObject example;

int main() {

    /*
    printf("Start %.2lf \n", example.pos[0]);

    initConstAll(&example, 1);

    printf("Set... %.2lf \n", example.pos[0]);
    */

    printf("#functions = %d\n\n", numberOfPasuliRepositoryItems);

    double constants[10];

    findDefaultConstants(1, constants, 10);

    getImplementationState(1);

    return 0;
}