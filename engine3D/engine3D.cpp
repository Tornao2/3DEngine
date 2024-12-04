#include "Gl/glut.h"

void resize(int width, int height) {

   // avoid div-by-zero
   if (height == 0) {
      height = 1;
   }

   // calculate the aspect ratio
   float ratio = width * 1.0 / height;

   // put opengl into projection matrix mode
   glMatrixMode(GL_PROJECTION);

   // reset the matrix
   glLoadIdentity();
   // set the viewport
   glViewport(0, 0, width, height);
   // set the perspective
   gluPerspective(45.0f, ratio, 0.1f, 100.0f);

   // put opengl back into modelview mode
   glMatrixMode(GL_MODELVIEW);

}

void render(void) {

   // just clear the buffers for now
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // flip the buffers
   glutSwapBuffers();

}


int main(int argc, char *argv[]) {

   // initialize glut
   glutInit(&argc, argv);

   // setup a depth buffer, double buffer and rgba mode
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

   // set the windows initial position and size
   glutInitWindowPosition(50, 50);
   glutInitWindowSize(320, 240);

   // create the window
   glutCreateWindow("Test Glut Program");

   // register the callbacks to glut
   glutDisplayFunc(render);
   glutReshapeFunc(resize);
   glutIdleFunc(render);

   // run the program
   glutMainLoop();

   return 0;
   
}