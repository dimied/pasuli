
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pasuli_mesh.h"
#include "../util/pasuli_approx.h"

char *pErrors[] = {
    "Failed to allocate memory for objects",
    "Failed to allocate memory for faces",
    "Invalid sampling value for u or v"};

char *getMeshError(int error)
{
    if ((error <= 0) || (error > sizeof(pErrors) / sizeof(char *)))
    {
        return 0;
    }

    return pErrors[error - 1];
}

void clearMesh(PaSuLiMesh *pMesh)
{
#if (PASULI_MESH_NULL_POINTER_CHECK != 0)
    if (pMesh == 0)
    {
        return;
    }
#endif
    memset(pMesh, 0, sizeof(PaSuLiMesh));
}

int createTriangleMesh(PaSuLiMesh *pMesh)
{
#if (PASULI_MESH_NULL_POINTER_CHECK != 0)
    if (pMesh == 0)
    {
        return -1;
    }
#endif
    unsigned int numUvalues = pMesh->uSampling;
    unsigned int numVvalues = pMesh->vSampling;
    double uStart = pMesh->uStart;
    double uEnd = pMesh->uEnd;
    double vStart = pMesh->vStart;
    double vEnd = pMesh->vEnd;
    double *pConstants = pMesh->pConstants;

    if ((numUvalues <= 0) || (numVvalues <= 0))
    {
        return PASULI_MESH_ERROR_INVALID_SAMPLING;
    }

    unsigned int numObjects = numUvalues * numVvalues;

    double uDiff = uEnd - uStart;
    double vDiff = vEnd - vStart;

    size_t memSize = numObjects * sizeof(PaSuLiObject);
    parsurFunc pCurrentFunc = pMesh->pSurfaceFunction;

    PaSuLiObject *pObjects = malloc(memSize);

    if (pObjects == 0)
    {
        return PASULI_MESH_ERROR_OBJECT_ALLOCATION;
    }
    memset(pObjects, 0, memSize);

    size_t numAllTriangles = (numUvalues - 1) * (numVvalues - 1) * 2;

    memSize = numAllTriangles * sizeof(unsigned int) * 3;
    // 3 vertices per triangle
    unsigned int *pTriangleIndices = malloc(memSize);

    if (pTriangleIndices == 0)
    {
        free(pObjects);
        pObjects = 0;
        return PASULI_MESH_ERROR_MESH_ALLOCATION;
    }
    memset(pObjects, 0, memSize);

    pMesh->numObjects = numObjects;
    pMesh->numFaces = numAllTriangles;
    pMesh->numIndices = numAllTriangles*3;
    pMesh->pObjects = pObjects;
    pMesh->pIndices = pTriangleIndices;

    PaSuLiObject *pCurrentObjects = pObjects;

    int approximateNormal = pMesh->options && PASULI_MESH_OPTIONS_APPROXIMATE_NORMAL;

    int k = 0;
    // create vertices
    for (int i = 0; i < numUvalues; i++)
    {
        float uValue = (i < numUvalues - 1)
                           ? uStart + uDiff * i / (numUvalues - 1)
                           : uEnd;

        for (int j = 0; j < numVvalues; j++)
        {
            float vValue = (j < numVvalues - 1)
                               ? vStart + vDiff * j / (numVvalues - 1)
                               : vEnd;

            pCurrentFunc(uValue, vValue, pConstants, pCurrentObjects);

            if (approximateNormal > 0)
            {
                approximatePaSuLi(
                    PASULI_APPROXIMATE_N,
                    uValue,
                    vValue,
                    pConstants,
                    pCurrentObjects,
                    pCurrentFunc);
            }

            // Normalize
            double normalLength = pCurrentObjects->n[0] * pCurrentObjects->n[0];
            normalLength += pCurrentObjects->n[1] * pCurrentObjects->n[1];
            normalLength += pCurrentObjects->n[2] * pCurrentObjects->n[2];
            normalLength = sqrt(normalLength);

            if (normalLength > 0)
            {
                pCurrentObjects->n[0] /= normalLength;
                pCurrentObjects->n[1] /= normalLength;
                pCurrentObjects->n[2] /= normalLength;
            }

            /*
      if (verbose > 0)
      {
        printf("V|%d| @ (%x,%x) = (%.2lf, %.2lf) => (%.2lf, %.2lf, %.2lf)\n",
               k, i, j,
               uValue, vValue,
               pCurrentObjects->pos[0],
               pCurrentObjects->pos[1],
               pCurrentObjects->pos[2]);
      }
      */
            k++;

            pCurrentObjects++;
        }
    }

    pCurrentObjects = pObjects;
    unsigned int *pCurrentFaces = pTriangleIndices;
    unsigned int numFacesDone = 0;

    // Set values for triangles

    for (int i = 0; i < numUvalues - 1; i++)
    {
        unsigned int forCurrentI = (i * numVvalues);
        unsigned int forNextI = ((i + 1) * numVvalues);

        for (int j = 0; j < numVvalues - 1; j++)
        {
            unsigned int verticeIdx1 = forCurrentI + j;
            unsigned int verticeIdx2 = forCurrentI + j + 1;
            unsigned int verticeIdx3 = forNextI + j;
            unsigned int verticeIdx4 = forNextI + j + 1;

            /*
      if (verbose > 0)
      {
        printTriangleInformationToConsole(
            verticeIdx1,
            verticeIdx2,
            verticeIdx3,
            pObjects);

        printTriangleInformationToConsole(
            verticeIdx3,
            verticeIdx2,
            verticeIdx4,
            pObjects);
      }
      */

            // 1.st triangle
            *pCurrentFaces = verticeIdx1;
            pCurrentFaces++;
            *pCurrentFaces = verticeIdx2;
            pCurrentFaces++;
            *pCurrentFaces = verticeIdx3;
            pCurrentFaces++;

            // 2.end triangle
            *pCurrentFaces = verticeIdx3;
            pCurrentFaces++;
            *pCurrentFaces = verticeIdx2;
            pCurrentFaces++;
            *pCurrentFaces = verticeIdx4;
            pCurrentFaces++;

            numFacesDone += 6;
        }
    }
    /*
  printf("#Faces = %d | Expected = %d\n",
         numFacesDone,
         numAllTriangles * 3);
         */

    return 0;
}

void releaseMesh(PaSuLiMesh *pMesh)
{
#if (PASULI_MESH_NULL_POINTER_CHECK != 0)
    if (pMesh == 0)
    {
        return;
    }
#endif
    if (pMesh->pObjects != 0)
    {
        free(pMesh->pObjects);
        pMesh->pObjects = 0;
    }

    if (pMesh->pIndices != 0)
    {
        free(pMesh->pIndices);
        pMesh->pIndices = 0;
    }
}