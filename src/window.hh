#ifndef WINDOW_HH
#define WINDOW_HH
#include <GLFW/glfw3.h>
struct Window{
    GLFWwindow* win;
    Window(int width, int height, const char* title);
    bool closed();
};

#endif
