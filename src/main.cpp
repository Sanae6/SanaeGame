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

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    while(!window.closed()){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex2d(0.5,0.5);//top right
        glColor3f(1.0,1.0,0.0);
        glVertex2d(-0.5,-0.5);//bottom left
        glColor3f(0.0,0.0,1.0);
        glVertex2d(-0.5,0.5);//top left
        glColor3f(1.0,0.0,0.0);
        glVertex2d(0.5,0.5);//top right
        glColor3f(0.0,1.0,0.0);
        glVertex2d(0.5,-0.5);//bottom right
        glColor3f(1.0,1.0,0.0);
        glVertex2d(-0.5,-0.5);//bottom left
        glEnd();
        glfwSwapBuffers(window.getwin());
    }

    log("Frick Yes");
    glfwTerminate();
    return 0;
}
