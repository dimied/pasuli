
#include <stdio.h>
#include "pasuli_mesh_util.h"

void printMemoryUsage(PaSuLiMesh *pMeshes, int numMeshes)
{
    size_t memoryAllocated = 0;

    for (size_t idx = 0; idx < numMeshes; idx++)
    {
        memoryAllocated += pMeshes[idx].numObjects * sizeof(PaSuLiObject);
        memoryAllocated += pMeshes[idx].numIndices * sizeof(unsigned int);
    }

    size_t inKB = (memoryAllocated + 1024) / 1024;
    size_t inMB = inKB / 1024;

    printf("Memory allocated bytes/KB/MB = %ld / %ld / %ld \n\n",
           memoryAllocated,
           inKB,
           inMB);
}