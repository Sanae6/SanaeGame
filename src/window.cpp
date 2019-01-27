#include <GLFW/glfw3.h>
#include "window.hh"
using namespace std;

Window::Window(int width, int height, const char* title){
    glfwWindowHint(GLFW_VISIBLE,GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
    win = glfwCreateWindow(width,height,title,NULL,NULL);
    glfwMakeContextCurrent(win);
};
GLFWwindow* Window::getwin(){
    return win;
};
bool Window::closed(){
    return glfwWindowShouldClose(win);
}
