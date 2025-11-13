
#include <stdio.h> // printf
#include "pasuli_defs.h"
#include "pasuli_macros.h"
#include "repository/pasuli_repository.h"
#include "repository/pasuli_repository_tests.h"

extern unsigned int numberOfPasuliRepositoryItems;
extern unsigned short number_of_implementation_state_entries;
extern unsigned short id_and_constants_entries;

int main()
{
    printf("#constants = %d\n", NUMB_OF_SURFACES);

    printf("#functions = %d\n", numberOfPasuliRepositoryItems);

    printf("#constants defined = %d\n", id_and_constants_entries);

    double constants[10];

    testDefaultConstants();

    testImplementationPointers();

    testDescriptionPointers();

    findDefaultConstants(1, constants, 10);

    printf("#implemented/checked = %d\n", number_of_implementation_state_entries);

    getImplementationState(1);

    return 0;
}