
#include <stdio.h> // printf
#include "pasuli_defs.h"
#include "pasuli_macros.h"
#include "pasuli_repository.h"

//PaSuLiObject example;

int main()
{

    printf("#constants = %d\n\n", NUMB_OF_SURFACES);

    printf("#functions = %d\n\n", numberOfPasuliRepositoryItems);

    double constants[10];

    testDefaultConstants();

    testImplementationPointers();

    testDescriptionPointers();

    findDefaultConstants(1, constants, 10);

    getImplementationState(1);

    return 0;
}