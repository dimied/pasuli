
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

char* pYes = "yes";
char* pNo = "no";

void showMeshInfo(PaSuLiMesh *pMesh)
{
  if (pMesh == 0)
  {
    return;
  }
  printf("Mesh-ID:%d\n", pMesh->meshID);
  printf("Surface-ID:%d\n", pMesh->surfaceID);
  printf("Options:%d\n", pMesh->options);
  printf("u:from:%.2lf\n", pMesh->uStart);
  printf("u:to:%.2lf\n", pMesh->uEnd);
  printf("v:from:%.2lf\n", pMesh->vStart);
  printf("v:to:%.2lf\n", pMesh->vEnd);
  printf("u:sampling:%d\n", pMesh->uSampling);
  printf("v:sampling:%d\n", pMesh->vSampling);
  printf("#objects:%d\n", pMesh->numObjects);
  printf("#faces:%d\n", pMesh->numFaces);
  printf("#faces:indices:%d\n", pMesh->numIndices);
  char* pStr = pMesh->pObjects != 0 ? pYes : pNo;
  printf("objects:data:%s\n", pStr);
  pStr = pMesh->pIndices != 0 ? pYes : pNo;
  printf("indices:data:%s\n", pStr);
}