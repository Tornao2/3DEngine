#include "Engine.h"

int main(int argc, char* argv[]) {
    Renderer renderer;
    DisplayManager displayManager(640, 480, true);
    Engine engine(&argc, argv, renderer, displayManager);
    return 0;
}