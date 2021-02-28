
#include <GL/gl.h>
#include "pasuli_mesh_opengl.h"

void renderTriangle(unsigned int pointIdx1,
                    unsigned int pointIdx2,
                    unsigned int pointIdx3,
                    int options,
                    PaSuLiObject *pObjects)
{
    PaSuLiObject *pCurrentObject = &pObjects[pointIdx1];

    int useNormal = options & PASULI_MESH_OPENGL_NORMAL;

    if (options & PASULI_MESH_OPENGL_FILL)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    glBegin(GL_TRIANGLES);

    if (useNormal > 0)
    {
        glNormal3dv(&pCurrentObject->n[0]);
    }

    glColor3f(0.0, 0.0, 1.0); /* blue */

    glVertex3dv(&pCurrentObject->pos[0]);

    pCurrentObject = &pObjects[pointIdx2];

    if (useNormal > 0)
    {
        glNormal3dv(&pCurrentObject->n[0]);
    }
    glColor3f(0.0, 1.0, 0.0); /* green */

    glVertex3dv(&pCurrentObject->pos[0]);

    pCurrentObject = &pObjects[pointIdx3];

    if (useNormal > 0)
    {
        glNormal3dv(&pCurrentObject->n[0]);
    }
    glColor3f(1.0, 0.0, 0.0); /* red */

    glVertex3dv(&pCurrentObject->pos[0]);

    pCurrentObject = &pObjects[pointIdx1];

    if (useNormal > 0)
    {
        glNormal3dv(&pCurrentObject->n[0]);
    }
    glColor3f(0.0, 0.0, 1.0); /* blue */

    glVertex3dv(&pCurrentObject->pos[0]);

    glEnd();
}

void renderMesh(PaSuLiMesh *pMesh, int options)
{
    if (pMesh == 0)
    {
        return;
    }
    //PaSuLiObject *pCurrentObject;
    
    unsigned int partialStep = 2;
    unsigned int numAllTriangles = pMesh->numFaces;
    unsigned int *pTriangleIndices = pMesh->pIndices;
    PaSuLiObject *pObjects = pMesh->pObjects;

    if (pObjects == 0 || pTriangleIndices == 0)
    {
        return;
    }

    int partial = options & PASULI_MESH_OPENGL_PARTIAL;
    int showNormal = options & PASULI_MESH_OPENGL_NORMAL;
    int showLines = options & PASULI_MESH_OPENGL_LINES_FROM_ORIGIN;

    unsigned int *pSomeFace;

    for (unsigned int i = 0; i < numAllTriangles; i++)
    {
        if (partial > 0 && i % partialStep == 0)
        {
            continue;
        }

        pSomeFace = pTriangleIndices + i * 3;
        unsigned int pointIdx1 = pSomeFace[2];
        unsigned int pointIdx2 = pSomeFace[1];
        unsigned int pointIdx3 = pSomeFace[0];

        renderTriangle(pointIdx1, pointIdx2, pointIdx3, options, pObjects);

        PaSuLiObject *pCurrentObject1 = &pObjects[pointIdx1];
        PaSuLiObject *pCurrentObject2 = &pObjects[pointIdx2];
        PaSuLiObject *pCurrentObject3 = &pObjects[pointIdx3];

        if (showNormal > 0)
        {
            glLineWidth(4);

            // "Inside"
            glBegin(GL_LINES);

            /* blue */
            glColor3f(0.0, 0.0, 1.0);
            glVertex3dv(&pCurrentObject1->pos[0]);
            glVertex3d(
                pCurrentObject1->pos[0] + pCurrentObject1->n[0],
                pCurrentObject1->pos[1] + pCurrentObject1->n[1],
                pCurrentObject1->pos[2] + pCurrentObject1->n[2]);

            glVertex3dv(&pCurrentObject2->pos[0]);
            glVertex3d(
                pCurrentObject2->pos[0] + pCurrentObject2->n[0],
                pCurrentObject2->pos[1] + pCurrentObject2->n[1],
                pCurrentObject2->pos[2] + pCurrentObject2->n[2]);

            glVertex3dv(&pCurrentObject3->pos[0]);
            glVertex3d(
                pCurrentObject3->pos[0] + pCurrentObject3->n[0],
                pCurrentObject3->pos[1] + pCurrentObject3->n[1],
                pCurrentObject3->pos[2] + pCurrentObject3->n[2]);

            glEnd();
        }

        if (showLines > 0)
        {

            glLineWidth(4);

            // "Inside"
            glBegin(GL_LINES);

            /* blue */
            glColor3f(0.0, 1.0, 0.0);
            glVertex3dv(&pCurrentObject1->pos[0]);
            glVertex3d(0, 0, 0);

            glVertex3dv(&pCurrentObject2->pos[0]);
            glVertex3d(0, 0, 0);

            glVertex3dv(&pCurrentObject3->pos[0]);
            glVertex3d(0, 0, 0);

            glEnd();

            float scale = 2;

            // "Outside"
            glBegin(GL_LINES);

            /* blue */
            glColor3f(.80, 1.0, 0.0);

            glVertex3dv(&pCurrentObject1->pos[0]);
            glVertex3d(pCurrentObject1->pos[0] * scale,
                       pCurrentObject1->pos[1] * scale,
                       pCurrentObject1->pos[2] * scale);

            glVertex3dv(&pCurrentObject2->pos[0]);
            glVertex3d(pCurrentObject2->pos[0] * scale,
                       pCurrentObject2->pos[1] * scale,
                       pCurrentObject2->pos[2] * scale);

            glVertex3dv(&pCurrentObject3->pos[0]);
            glVertex3d(pCurrentObject3->pos[0] * scale,
                       pCurrentObject3->pos[1] * scale,
                       pCurrentObject3->pos[2] * scale);

            glEnd();
        }
    }
}
