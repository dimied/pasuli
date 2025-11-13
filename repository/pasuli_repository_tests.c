#include "pasuli_repository.h"
#include "pasuli_repository_tests.h"
#include "../pasuli_const.h"

#if(COMPILE_PASULI_REPOSITORY_TESTS != 0)

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern PaSuLiRepositoryItem repositoryItems[];
extern unsigned int numberOfPasuliRepositoryItems;

extern unsigned char id_and_constants[][3];
extern unsigned short id_and_constants_entries;

extern PaSuLiTextDescType parsur_desc_array[];
extern unsigned short number_of_entries_in_pasuli_surface_desc_array;

void testImplementationPointers()
{
    if(numberOfPasuliRepositoryItems == 0) {
        return;
    }
    
    unsigned char *pStates = malloc(256);
    memset(pStates, 0, 256);

    for (size_t i = 0; i < numberOfPasuliRepositoryItems; i++)
    {
        unsigned char funcID = repositoryItems[i].id;

        if (pStates[funcID] > 0)
        {
            printf("Function already pointed to at index = %ld\n", i);
        }

        if (repositoryItems[i].pFunc != 0)
        {
            pStates[funcID] += 1;
        }
    }

    for (size_t i = 0; i < numberOfPasuliRepositoryItems; i++)
    {
        parsurFunc pFunc = repositoryItems[i].pFunc;
        unsigned char ID = repositoryItems[i].id;

// Disable warning, 
// we know that we won't access data out of array bounds
// But GCC doesn't get it right.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
        for (size_t j = i + 1; j < numberOfPasuliRepositoryItems; j++)
        {
            parsurFunc pFunc2 = repositoryItems[j].pFunc;
            if (pFunc == pFunc2)
            {
                printf("Function pointer already in use. ID=%d.First occurence @%ld, second @%ld\n", ID, i, j);
            }
        }
#pragma GCC diagnostic pop
    }

#if 1
    for (int idx = 1; idx < NUMB_OF_SURFACES; idx++)
    {
        if (pStates[idx] == 0)
        {
            printf("No function pointer for surface ID = %d\n", idx);
        }
    }
#endif

    free(pStates);
}

void testDefaultConstants()
{
	size_t numberOf = 256;

	unsigned char *pStates = malloc(numberOf);

	memset(pStates, 0, numberOf);

	for (int idx = 0; idx < id_and_constants_entries; idx++)
	{
		int id = id_and_constants[idx][0];

		if (((id <= 0) || (id > 255)))
		{
			printf("Invalid surface at index %d, value %d", idx, id);
			continue;
		}
		if (pStates[id] > 0)
		{
			printf("Constants already defined for surface %d", id);
		}
		pStates[id] += 1;
	}

	for (int idx = 1; idx < NUMB_OF_SURFACES; idx++)
	{
		if (pStates[idx] == 0)
		{
			printf("Constants not yet defined for surface %d\n", idx);
		}
	}

	free(pStates);
}

void testDescriptionPointers()
{
	//const size_t numberOfEntries = sizeof(parsur_desc_array) / sizeof(PaSuLiTextDescType);

	size_t numberOf = 256;

	unsigned char *pStates = malloc(numberOf);
	char **pTexts = malloc(numberOf * sizeof(unsigned char *));

	memset(pStates, 0, numberOf);
	memset(pTexts, 0, numberOf * sizeof(unsigned char *));

	printf("#descriptions = %d\n", number_of_entries_in_pasuli_surface_desc_array);

	for (size_t idx = 0; idx < number_of_entries_in_pasuli_surface_desc_array; idx++)
	{
		int id = parsur_desc_array[idx].ID;

		if (pStates[id] > 0)
		{
			printf("Already defined for ID=%d, found new at %ld|Name: %s\n",
				   id,
				   idx,
				   parsur_desc_array[idx].pszName);
		}
		pStates[id] += 1;

		if (pTexts[id] != 0)
		{
			printf("Text for ID=%d already defined as \n%s\n", id, pTexts[id]);
		}
		if (parsur_desc_array[idx].pszDesc == 0)
		{
			printf("Found invalid text pointer @index=%ld", idx);
		}
		else
		{
			char *pszText = *parsur_desc_array[idx].pszDesc;
			if (pszText == 0)
			{
				printf("Found invalid text pointer value @index=%ld", idx);
			}
			else
			{
				pTexts[id] = pszText;
			}
		}
	}

	// Compare texts
	for (size_t idxForText = 0; idxForText < number_of_entries_in_pasuli_surface_desc_array; idxForText++)
	{
		char *pText1 = *parsur_desc_array[idxForText].pszDesc;
		for (size_t idxForText2 = 0; idxForText2 < idxForText; idxForText2++)
		{
			char *pText2 = *parsur_desc_array[idxForText2].pszDesc;
			if (pText1 != 0 && pText2 != 0)
			{
				int compareResult = strcmp(pText1, pText2);
				if (compareResult == 0)
				{
					printf("Same descriptions @indices %ld and %ld with names\
					'%s' and '%s'\n",
						   idxForText,
						   idxForText2,
						   parsur_desc_array[idxForText].pszName,
						   parsur_desc_array[idxForText2].pszName);
				}
			}
		}
	}

	free(pStates);
	free(pTexts);
}

#endif