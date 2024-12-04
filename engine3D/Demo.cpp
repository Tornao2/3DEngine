#include "Engine.h"

int main(int argc, char* argv[]) {
    Renderer renderer(Color { 0.5, 0.5, 0.5, 1 }, true, false);
    DisplayManager displayManager(640, 480, false, true, "3DEngine");
    Engine engine(&argc, argv, renderer, displayManager, 60, true, true);
    return 0;
}