
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "glut_helpers.h"

double gRot[3] = {0.0, 0.0, 0.0};

GLfloat light_diffuse[] = {.7, 0.0, 0.5, 1.0};
// Infinite light position
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

float lmodel_twoside[] = {GL_TRUE};
float lmodel_oneside[] = {GL_FALSE};

/* enumerations for the mouse buttons */
enum MouseState
{
  UP = 1,
  DOWN,
};

enum MouseMode
{
  ROTATE = 1,
  MOVE
};

unsigned int mouseRotateState = UP;
int oldMouseRotateX = 0;
int oldMouseRotateY = 0;
int oldMouseTranslateX = 0;
int oldMouseTranslateY = 0;
int mouseMode = ROTATE;

void init()
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
  //glRotatef(-45, 1.0, 0.0, 0.0);
  //glRotatef(-20, 0.0, 0.0, 1.0);
  //glRotatef(-15, 0.0, 1.0, 0.0);
}

/**
* Called when some mouse button is clicked.
*/
void glutMouse(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
      if (mouseMode == 0)
      {
        mouseMode = ROTATE;
        oldMouseRotateX = x;
        oldMouseRotateY = y;
        mouseRotateState = DOWN;
        //printf("Left mouse down @ (%d,%d)\n", x, y);
      }

      break;
    case GLUT_RIGHT_BUTTON:
      if (mouseMode == 0)
      {
        mouseMode = MOVE;
        oldMouseTranslateX = x;
        oldMouseTranslateY = y;
      }

      break;
    }
  }
  else if (state == GLUT_UP)
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
      mouseRotateState = UP;
      //printf("Left mouse up @ (%d,%d)\n", x, y);
      mouseMode = 0;
      break;
    case GLUT_RIGHT_BUTTON:
      mouseMode = 0;
      break;
    }
}
/*
Clamps the rotation to -360 to 360
*/
void clampAnglesTo360(double *triple)
{
  for (int i = 0; i < 3; i++)
  {
    if (triple[i] > 360 || triple[i] < -360)
    {
      triple[i] = 0;
      continue;
      double times = ceil(fabs(triple[i] / 360.0));

      if (triple[i] < 0)
      {
        triple[i] += times * 360;
      }
      else
      {
        triple[i] -= times * 360;
      }
    }
  }
}

double mouseRotationSensitivity = 0.005;
/**
* Called when the mouse moves in the window. 
*/
void glutMotion(int x, int y)
{
  if (mouseMode == ROTATE && mouseRotateState == DOWN)
  {
    gRot[0] -= ((oldMouseRotateX - x) * 180.0f * mouseRotationSensitivity) / 100.0f;
    gRot[1] -= ((oldMouseRotateY - y) * 180.0f * mouseRotationSensitivity) / 100.0f;

    clampAnglesTo360(gRot);

    glutPostRedisplay();

    oldMouseRotateX = x;
    oldMouseRotateY = y;
  }
}


void drawAxes()
 {
  double scale = 5;
  double offset = 0.25;

  glBegin(GL_LINES);
  glColor3f(0.0, 1.0, 0.0);

  glVertex3d(0, 0, 0);
  glVertex3d(scale, 0, 0);

  // X symbol
  glVertex3d(offset + scale - 0.25, 0.25, 0);
  glVertex3d(offset + scale + 0.25, -0.25, 0);
  glVertex3d(offset + scale - 0.25, -0.25, 0);
  glVertex3d(offset + scale + 0.25, 0.25, 0);

  glVertex3d(0, 0, 0);
  glVertex3d(0, scale, 0);

  // Y symbol
  glVertex3d(-0.25, 3 * offset + scale, 0);
  glVertex3d(0, 2 * offset + scale, 0);
  glVertex3d(0.25, 3 * offset + scale, 0);
  glVertex3d(0, 2 * offset + scale, 0);
  glVertex3d(0, 2 * offset + scale, 0);
  glVertex3d(0, offset + scale, 0);

  glVertex3d(0, 0, 0);
  glVertex3d(0, 0, scale);
  glEnd();
}