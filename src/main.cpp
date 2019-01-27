#include <iostream>
#include <string>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "window.hh"

using namespace std;

void log(std::string text){
    cout << text << endl;
}

int main()
{
    if (!glfwInit()){
        log("GLFW Died lol");
        return 1;
    }
    Window window(800,600,"Epic");
    if (window.getwin() == 0){
        log("Window didn't create :pensive:");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window.getwin());

    glfwShowWindow(window.getwin());
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    while(!window.closed()){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        glfwSwapBuffers(window.getwin());
    }

    log("Frick Yes");
    glfwTerminate();
    return 0;
}
