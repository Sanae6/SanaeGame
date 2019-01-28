#include <iostream>
#include <string>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <GL/gl.h>

int WIDTH = 800;
int HEIGHT = 800;
const char* TITLE = "Minecraft";
int FPS = 60;

#include "window.hh"
#include "scene.hh"
#include "game.hh"
using namespace std;

void log(std::string text){
    cout << text << endl;
}

int time_delta = 1000/FPS;
//Scene* state;
Window window;
struct Game{
    //
    Game();
    void render();
    void update();
    void loop();
};

Game::Game(){
    if (!glfwInit()){
        log("Could not start GL");
        throw exception();
    }
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    Window wndow(WIDTH,HEIGHT,TITLE);
    window = wndow;
    glfwMakeContextCurrent(window.win);
    glfwShowWindow(window.win);
    if (window.win == 0){
        log("Window didn't create :pensive:");
        glfwTerminate();
        exit(1);
    }
    //scene = GameScene()
}

int main()
{
    Game game();

    while(!window.closed()){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        game.loop();
        // White side - BACK
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0, 1.0 );
        glVertex3f(  0.5, -0.5, 0.5 );
        glVertex3f(  0.5,  0.5, 0.5 );
        glVertex3f( -0.5,  0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();

        // Purple side - RIGHT
        glBegin(GL_POLYGON);
        glColor3f(  1.0,  0.0,  1.0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5,  0.5, -0.5 );
        glVertex3f( 0.5,  0.5,  0.5 );
        glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();

        // Green side - LEFT
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  1.0,  0.0 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        // Blue side - TOP
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.5,  0.5,  0.5 );
        glVertex3f(  0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();

        // Red side - BOTTOM
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  0.0,  0.0 );
        glVertex3f(  0.5, -0.5, -0.5 );
        glVertex3f(  0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        glFlush();
        glfwSwapBuffers(window.win);
    }

    log("Frick Yes");
    glfwTerminate();
    return 0;
}
