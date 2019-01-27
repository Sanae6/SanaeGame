#ifndef WINDOW_HH
#define WINDOW_HH
#include <GLFW/glfw3.h>
class Window{
    GLFWwindow* win;
public:
    Window(int width, int height, const char* title);
    bool closed();
    GLFWwindow* getwin();
};

#endif
