#include "MouseHandler.h"

//DEBUGGING
#include <iostream>
//DEBUGGING
void MouseHandler::handleMouse(int button, int state, int x, int y) {
    //DEBUGGING
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
        printf("3");
    //DEBUGGING
}