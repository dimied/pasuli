
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
//
#include "pasuli_defs.h"
#include "pasuli_approx.h"

GLfloat light_diffuse[] = {.7, 0.0, 0.5, 1.0};
// Infinite light position
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

PaSuLiObject *pObjects = 0;
unsigned int *pTriangleIndices = 0;

int count = 0;

float uStart = -2;
float uEnd = 2;
float vStart = -2;
float vEnd = 2;

int partial = 0;
int useNormal = 1;
int showLines = 0;

int numUvalues = 20;
int numVvalues = 20;
unsigned int numAllObject = 0;
unsigned int numAllTriangles = 0;
unsigned int memoryAllocated = 0;

static float lmodel_twoside[] = {GL_TRUE};
static float lmodel_oneside[] = {GL_FALSE};

void printTriangleInformationToConsole(
    unsigned int verticeIdx1,
    unsigned int verticeIdx2,
    unsigned int verticeIdx3,
    PaSuLiObject *pSomeObjects)
{
  printf("T @ (%d,%d,%d) = \n\
      (%.2lf, %.2lf, %.2lf) - (%.2lf, %.2lf, %.2lf) - (%.2lf, %.2lf, %.2lf) \n",
         verticeIdx1,
         verticeIdx2,
         verticeIdx3,
         pSomeObjects[verticeIdx1].pos[0],
         pSomeObjects[verticeIdx1].pos[1],
         pSomeObjects[verticeIdx1].pos[2],

         pSomeObjects[verticeIdx2].pos[0],
         pSomeObjects[verticeIdx2].pos[1],
         pSomeObjects[verticeIdx2].pos[2],

         pSomeObjects[verticeIdx3].pos[0],
         pSomeObjects[verticeIdx3].pos[1],
         pSomeObjects[verticeIdx3].pos[2]);
}

void releaseMemory()
{
  if (pObjects != 0)
  {
    free(pObjects);
  }

  if (pTriangleIndices != 0)
  {
    free(pTriangleIndices);
  }
}

#include "torus/umbillictorus.h"
#include "torus/torus.h"

double constants[] = {4, 2.5};

void initGeometry(int verbose)
{
  uStart = -M_PI;
  uEnd = M_PI;
  vStart = -M_PI;
  vEnd = M_PI;

  float uDiff = uEnd - uStart;
  float vDiff = vEnd - vStart;

  unsigned int numObjects = numUvalues * numVvalues;
  numAllObject = numObjects;
  size_t memSize = numObjects * sizeof(PaSuLiObject);

  parsurFunc pCurrentFunc = &UmbillicTorus;

  pCurrentFunc = &Torus;

  pObjects = malloc(memSize);

  if (pObjects == 0)
  {
    printf("Failed to allocate memory for objects");
    return;
  }

  memoryAllocated += memSize;

  numAllTriangles = (numUvalues - 1) * (numVvalues - 1) * 2;

  memSize = numAllTriangles * sizeof(unsigned int) * 3;
  // 3 vertices per triangle
  pTriangleIndices = malloc(memSize);

  if (pTriangleIndices == 0)
  {
    free(pObjects);
    pObjects = 0;
    memoryAllocated = 0;
    printf("Failed to allocate memory for faces");
    return;
  }

  memoryAllocated += memSize;

  PaSuLiObject *pCurrentObjects = pObjects;
  unsigned int *pCurrentFaces = pTriangleIndices;

  for (unsigned int i = 0; i < numObjects; i++)
  {
    pCurrentObjects->pos[0] = 0;
    pCurrentObjects->pos[1] = 0;
    pCurrentObjects->pos[2] = 0;

    pCurrentObjects->n[0] = 0;
    pCurrentObjects->n[1] = 0;
    pCurrentObjects->n[2] = -1;

    pCurrentObjects++;
  }

  for (unsigned int i = 0; i < numAllTriangles * 3; i++)
  {
    pCurrentFaces = 0;
    pCurrentFaces++;
  }

  pCurrentObjects = pObjects;

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

      pCurrentObjects->pos[0] = uValue;
      pCurrentObjects->pos[1] = vValue;

      pCurrentFunc(uValue, vValue, constants, pCurrentObjects);

      approximatePaSuLi(
          PASULI_APPROXIMATE_N,
          uValue,
          vValue,
          constants,
          pCurrentObjects,
          pCurrentFunc);

      if (verbose > 0)
      {
        printf("V @ (%x,%x) = (%.2lf, %.2lf, 0)\n", i, j, uValue, vValue);
      }

      pCurrentObjects++;
    }
  }

  pCurrentObjects = pObjects;
  pCurrentFaces = pTriangleIndices;
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
  printf("#Faces = %d | Expected = %d\n",
         numFacesDone,
         numAllTriangles * 3);
}

void renderSurface(unsigned int pointIdx1,
                   unsigned int pointIdx2,
                   unsigned int pointIdx3,
                   int fill)
{
  PaSuLiObject *pCurrentObject = &pObjects[pointIdx1];

  if (fill > 0)
  {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  } else {
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
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

void drawGeometry(void)
{
  PaSuLiObject *pCurrentObject;

  for (unsigned int i = 0; i < numAllTriangles; i++)
  {
    if (partial > 0 && i % 2 == 0)
    {
      continue;
    }

    unsigned int *pSomeFace = pTriangleIndices + i * 3;
    unsigned int pointIdx1 = pSomeFace[2];
    unsigned int pointIdx2 = pSomeFace[1];
    unsigned int pointIdx3 = pSomeFace[0];

    //renderSurface(pointIdx1, pointIdx2, pointIdx3, 1);

    renderSurface(pointIdx1, pointIdx2, pointIdx3, 0);

    if (showLines > 0)
    {
      PaSuLiObject *pCurrentObject1 = &pObjects[pointIdx1];
      PaSuLiObject *pCurrentObject2 = &pObjects[pointIdx2];
      PaSuLiObject *pCurrentObject3 = &pObjects[pointIdx3];

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

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawGeometry();
  glutSwapBuffers();
}

void init(void)
{
  // Single OpenGL light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  // Depth buffering to eliminate hidden surfaces
  glEnable(GL_DEPTH_TEST);

  glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective(/* field of view in degree */ 60.0,
                 /* aspect ratio */ 1.0,
                 /* Z near */ 1.0, /* Z far */ 50.0);

  glMatrixMode(GL_MODELVIEW);
  gluLookAt(.0, .0, 16.0,  /* eye is at (0,0,-7) */
            0.0, 0.0, 0.0, /* center is at (0,0,0) */
            0.0, 1.0, 0.); /* up is in positive Y direction */

  //glTranslatef(0.0, 0.0, -1.0);
  //glRotatef(45, 1.0, 0.0, 0.0);
  //glRotatef(-20, 0.0, 0.0, 1.0);
}

int sizes[][2] = {
    {1024, 768},
    {1280, 720},
    {1600, 900}};

int main(int argc, char **argv)
{
  initGeometry(1);

  unsigned int inKB = (memoryAllocated + 1024) / 1024;
  unsigned int inMB = inKB / 1024;

  printf("Memory allocated bytes/KB/MB = %d / %d / %d \n\n",
         memoryAllocated,
         inKB,
         inMB);

  glutInit(&argc, argv);

  int sizeIdx = 2;
  int width = sizes[sizeIdx][0];
  int height = sizes[sizeIdx][1];

  glutInitWindowSize(width, height);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutCreateWindow("Example");

  glutDisplayFunc(display);

  init();

  glutMainLoop();

  releaseMemory();

  return 0;
}
