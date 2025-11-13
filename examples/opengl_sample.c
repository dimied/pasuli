
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <mcheck.h>
#include "glut_helpers.h"
//
#include "../pasuli_defs.h"
//#include "../util/pasuli_approx.h"
#include "../torus/torus.h"
//#include "../torus/umbillic_torus.h"
//#include "../torus/wave_torus.h"
//#include "../splines/splines.h"

#include "pasuli_mesh.h"
#include "pasuli_mesh_opengl.h"
#include "pasuli_mesh_util.h"

extern double gRot[3];

PaSuLiMesh mesh;

int meshOptions = 0;

unsigned int numAllObject = 0;
unsigned int numAllTriangles = 0;
unsigned int memoryAllocated = 0;

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

double torusConstants[] = {4, 2};
double waveTorusConstants[] = {1.5, 0.5, 1, 1};

void drawGeometry(void)
{
  renderMesh(&mesh, meshOptions);
  }

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glMatrixMode (GL_MODELVIEW);
  //glLoadIdentity ();

  glRotatef(gRot[0], 1.0, 0.0, 0.0);
  glRotatef(gRot[1], 0.0, 1.0, 0.0);

  drawAxes();

  drawGeometry();

  glutSwapBuffers();
}

int sizes[][2] = {
    {1024, 768},
    {1280, 720},
    {1600, 900}};


int main(int argc, char **argv)
{
  mtrace();

  clearMesh(&mesh);
  mesh.options = 0;// PASULI_MESH_OPTIONS_APPROXIMATE_NORMAL;
  mesh.uStart = -M_PI;
  mesh.uEnd = M_PI;
  mesh.vStart = -M_PI;
  mesh.vEnd = M_PI;
  mesh.uSampling = 40;
  mesh.vSampling = 40;
  mesh.pConstants = torusConstants;
  mesh.pSurfaceFunction = &Torus;

  int error = createTriangleMesh(&mesh);
  printf("Mesh error %d\n\n", error);

  showMeshInfo(&mesh);
  meshOptions = 0;//PASULI_MESH_OPENGL_NORMAL;//PASULI_MESH_OPENGL_SURFACES_DEFAULT;

  printMemoryUsage(&mesh, 1);
  glutInit(&argc, argv);

  int sizeIdx = 2;
  int width = sizes[sizeIdx][0];
  int height = sizes[sizeIdx][1];

  glutInitWindowSize(width, height);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutCreateWindow("Example");

  glutDisplayFunc(display);

  glutMotionFunc(glutMotion);

  glutMouseFunc(glutMouse);

  init();

  glutMainLoop();

  releaseMesh(&mesh);

  return 0;
}
