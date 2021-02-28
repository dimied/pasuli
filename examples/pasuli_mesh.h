#ifndef __PASULI_MESH__
#define __PASULI_MESH__

#include "../pasuli_defs.h"

#ifndef PASULI_MESH_NULL_POINTER_CHECK
#define PASULI_MESH_NULL_POINTER_CHECK 1
#endif

#define PASULI_MESH_ERROR_OBJECT_ALLOCATION 1
#define PASULI_MESH_ERROR_MESH_ALLOCATION 2
#define PASULI_MESH_ERROR_INVALID_SAMPLING 3

#define PASULI_MESH_OPTIONS_APPROXIMATE_NORMAL 1

typedef struct _PaSuLiMesh {
    unsigned short meshID;
    unsigned char surfaceID;
    unsigned char options;
    //
    double uStart;
    double uEnd;
    double vStart;
    double vEnd;
    //
    unsigned int uSampling;
    unsigned int vSampling;
    // Alternative to surfaceID
    parsurFunc pSurfaceFunction;
    // External
    double *pConstants;
    // Internal
    PaSuLiObject *pObjects;
    unsigned int numObjects;
    // Internal
    unsigned int *pIndices;
    unsigned int numFaces;
    unsigned int numIndices;
} PaSuLiMesh;

void clearMesh(PaSuLiMesh* pMesh);

int createTriangleMesh(PaSuLiMesh* pMesh);

char* getMeshError(int error);

void releaseMesh(PaSuLiMesh* pMesh);

#endif