#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut_ext.h>



#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define PI 3.14159265358979323846

float angle = 0.0, yAngle = 0.0;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float x = 14.0f, z = -7.5f;
float roll = 0.0f;
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;


class Window {
public:
    void drawWindow1() {
        // Window 1
        glColor3f(0.6f, 0.7333f, 1.0f); // light blue outside
        glBegin(GL_QUADS);
        glVertex3f(-9.99f, 2.0f, 6.0f);
        glVertex3f(-9.99f, 5.0f, 6.0f);
        glVertex3f(-9.99f, 5.0f, 2.0f);
        glVertex3f(-9.99f, 2.0f, 2.0f);
        glEnd();

        glColor3f(0.149f, 0.149f, 0.149f);
        glLineWidth(10.0f);
        glBegin(GL_LINES);
        // Left
        glVertex3f(-9.98f, 2.0f, 6.0f);
        glVertex3f(-9.98f, 5.0f, 6.0f);
        // Top
        glVertex3f(-9.98f, 5.0f, 6.0f);
        glVertex3f(-9.98f, 5.0f, 2.0f);
        // Right
        glVertex3f(-9.98f, 2.0f, 2.0f);
        glVertex3f(-9.98f, 5.0f, 2.0f);
        // Bottom
        glVertex3f(-9.98f, 2.0f, 6.0f);
        glVertex3f(-9.98f, 2.0f, 2.0f);
        glEnd();

        // Cross
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex3f(-9.98f, 2.0f, 4.0f);
        glVertex3f(-9.98f, 5.0f, 4.0f);

        glVertex3f(-9.98f, 3.5f, 6.0f);
        glVertex3f(-9.98f, 3.5f, 2.0f);
        glEnd();
    }

    void drawWindow2() {
        // Window 2 by whiteboard 
        glColor3f(0.6f, 0.7333f, 1.0f);
        glBegin(GL_QUADS);
        glVertex3f(-9.99f, 2.0f, -6.0f);
        glVertex3f(-9.99f, 5.0f, -6.0f);
        glVertex3f(-9.99f, 5.0f, -2.0f);
        glVertex3f(-9.99f, 2.0f, -2.0f);
        glEnd();

        glColor3f(0.149f, 0.149f, 0.149f);
        glLineWidth(10.0f);
        glBegin(GL_LINES);
        // Left
        glVertex3f(-9.98f, 2.0f, -6.0f);
        glVertex3f(-9.98f, 5.0f, -6.0f);
        // Top
        glVertex3f(-9.98f, 5.0f, -6.0f);
        glVertex3f(-9.98f, 5.0f, -2.0f);
        // Right
        glVertex3f(-9.98f, 2.0f, -2.0f);
        glVertex3f(-9.98f, 5.0f, -2.0f);
        // Bottom
        glVertex3f(-9.98f, 2.0f, -6.0f);
        glVertex3f(-9.98f, 2.0f, -2.0f);
        glEnd();

        // Cross
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex3f(-9.98f, 2.0f, -4.0f);
        glVertex3f(-9.98f, 5.0f, -4.0f);

        glVertex3f(-9.98f, 3.5f, -6.0f);
        glVertex3f(-9.98f, 3.5f, -2.0f);
        glEnd();

    }

    void drawWindowSill() {
        glColor3f(0.149f, 0.149f, 0.149f);
        glBegin(GL_QUADS);
        glVertex3f(-9.99f, 2.0f, -6.0f);
        glVertex3f(-9.99f, 2.0f, -2.0f);
        glVertex3f(-9.5f, 2.0f, -2.0f);
        glVertex3f(-9.5f, 2.0f, -6.0f);

        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex3f(-9.5f, 2.0f, -6.0f);
        glVertex3f(-9.5f, 2.0f, -2.0f);
        glVertex3f(-9.5f, 1.8f, -2.0f);
        glVertex3f(-9.5f, 1.8f, -6.0f);

        glColor3f(0.24f, 0.24f, 0.24f);
        glVertex3f(-9.99f, 2.0f, -6.0f);
        glVertex3f(-9.5f, 2.0f, -6.0f);
        glVertex3f(-9.5f, 1.8f, -6.0f);
        glVertex3f(-9.99f, 1.8f, -6.0f);

        glVertex3f(-9.99f, 2.0f, -2.0f);
        glVertex3f(-9.5f, 2.0f, -2.0f);
        glVertex3f(-9.5f, 1.8f, -2.0f);
        glVertex3f(-9.99f, 1.8f, -2.0f);
        glEnd();
    }
};

class Table {
public:
    void drawTable() {

        // glTranslatef(0.0f, 0.0f, -14.0f);


        glBegin(GL_QUADS);

        //Front
        //
        //glColor3f(.6, .2, 0);
       // glColor3f(0.2f, 0.2f, 0.2f); //dark grey
       // glColor3f(0.3f, 0.3f, 0.3f); //grey table top
       // glColor3f(0.4824f, 0.2471f, 0.0f); // chocolate brown
        //glColor3f(0.8f, 0.8f, 0.8f); // light grey
        //glColor3f(0.5f, 0.5f, 0.5f); //medium grey
        glColor3f(0.3f, 0.3f, 0.3f);//dark grey


        glVertex3f(-10.0f, -0.2f, 2.0f);
        glVertex3f(10.0f, -0.2f, 2.0f);
        glVertex3f(10.0f, 0.2f, 2.0f);
        glVertex3f(-10.0f, 0.2f, 2.0f);

        //Back
        //;
        glVertex3f(-10.0f, -0.2f, -2.0f);
        glVertex3f(-10.0f, 0.2f, -2.0f);
        glVertex3f(10.0f, 0.2f, -2.0f);
        glVertex3f(10.0f, -0.2f, -2.0f);

        //Right
        //
        glVertex3f(10.0f, -0.2f, -2.0f);
        glVertex3f(10.0f, 0.2f, -2.0f);
        glVertex3f(10.0f, 0.2f, 2.0f);
        glVertex3f(10.0f, -0.2f, 2.0f);


        //Left
        ;
        glVertex3f(-10.0f, -0.2f, -2.0f);
        glVertex3f(-10.0f, -0.2f, 2.0f);
        glVertex3f(-10.0f, 0.2f, 2.0f);
        glVertex3f(-10.0f, 0.2f, -2.0f);

        //top
        //

        glVertex3f(10.0f, 0.2f, 2.0f);
        glVertex3f(-10.0f, 0.2f, 2.0f);
        glVertex3f(-10.0f, 0.2f, -2.0f);
        glVertex3f(10.0f, 0.2f, -2.0f);

        //bottom
        ;

        glVertex3f(10.0f, -0.2f, 2.0f);
        glVertex3f(-10.0f, -0.2f, 2.0f);
        glVertex3f(-10.0f, -0.2f, -2.0f);
        glVertex3f(10.0f, -0.2f, -2.0f);

        //table front leg
        //front    
      // glColor3f(0.1f, 0.1f, 0.1f); // light black  
        glColor3f(0.1f, 0.1f, 0.1f);

        glVertex3f(9.8f, -0.2f, 1.6f);
        glVertex3f(9.4f, -0.2f, 1.6f);
        glVertex3f(9.4f, -3.0f, 1.6f);
        glVertex3f(9.8f, -3.0f, 1.6f);
        //back
        glVertex3f(9.8f, -0.2f, 1.2f);
        glVertex3f(9.4f, -0.2f, 1.2f);
        glVertex3f(9.4f, -3.0f, 1.2f);
        glVertex3f(9.8f, -3.0f, 1.2f);
        //right
        glVertex3f(9.8f, -0.2f, 1.6f);
        glVertex3f(9.8f, -0.2f, 1.2f);
        glVertex3f(9.8f, -3.0f, 1.2f);
        glVertex3f(9.8f, -3.0f, 1.6f);
        //left
        glVertex3f(9.4f, -0.2f, 1.6f);
        glVertex3f(9.4f, -0.2f, 1.2f);
        glVertex3f(9.4f, -3.0f, 1.2f);
        glVertex3f(9.4f, -3.0f, 1.6f);
        //back leg back
        //front
        glVertex3f(9.8f, -0.2f, -1.2f);
        glVertex3f(9.4f, -0.2f, -1.2f);
        glVertex3f(9.4f, -3.0f, -1.2f);
        glVertex3f(9.8f, -3.0f, -1.2f);
        //back
        glVertex3f(9.8f, -0.2f, -1.6f);
        glVertex3f(9.4f, -0.2f, -1.6f);
        glVertex3f(9.4f, -3.0f, -1.6f);
        glVertex3f(9.8f, -3.0f, -1.6f);
        //right
        glVertex3f(9.8f, -0.2f, -1.6f);
        glVertex3f(9.8f, -0.2f, -1.2f);
        glVertex3f(9.8f, -3.0f, -1.2f);
        glVertex3f(9.8f, -3.0f, -1.6f);
        //left
        glVertex3f(9.4f, -0.2f, -1.6f);
        glVertex3f(9.4f, -0.2f, -1.2f);
        glVertex3f(9.4f, -3.0f, -1.2f);
        glVertex3f(9.4f, -3.0f, -1.6f);
        //leg left front
        glVertex3f(-9.8f, -0.2f, 1.6f);
        glVertex3f(-9.4f, -0.2f, 1.6f);
        glVertex3f(-9.4f, -3.0f, 1.6f);
        glVertex3f(-9.8f, -3.0f, 1.6f);
        //back
        glVertex3f(-9.8f, -0.2f, 1.2f);
        glVertex3f(-9.4f, -0.2f, 1.2f);
        glVertex3f(-9.4f, -3.0f, 1.2f);
        glVertex3f(-9.8f, -3.0f, 1.2f);
        //right
        glVertex3f(-9.8f, -0.2f, 1.6f);
        glVertex3f(-9.8f, -0.2f, 1.2f);
        glVertex3f(-9.8f, -3.0f, 1.2f);
        glVertex3f(-9.8f, -3.0f, 1.6f);
        //left
        ;
        glVertex3f(-9.4f, -0.2f, 1.6f);
        glVertex3f(-9.4f, -0.2f, 1.2f);
        glVertex3f(-9.4f, -3.0f, 1.2f);
        glVertex3f(-9.4f, -3.0f, 1.6f);
        //left leg back front
        //front
        ;
        //glColor3f(1,1,1);
        glVertex3f(-9.8f, -0.2f, -1.2f);
        glVertex3f(-9.4f, -0.2f, -1.2f);
        glVertex3f(-9.4f, -3.0f, -1.2f);
        glVertex3f(-9.8f, -3.0f, -1.2f);
        //back
        ;
        glVertex3f(-9.8f, -0.2f, -1.6f);
        glVertex3f(-9.4f, -0.2f, -1.6f);
        glVertex3f(-9.4f, -3.0f, -1.6f);
        glVertex3f(-9.8f, -3.0f, -1.6f);
        //right
        glVertex3f(-9.8f, -0.2f, -1.6f);
        glVertex3f(-9.8f, -0.2f, -1.2f);
        glVertex3f(-9.8f, -3.0f, -1.2f);
        glVertex3f(-9.8f, -3.0f, -1.6f);
        //left
        glVertex3f(-9.4f, -0.2f, -1.6f);
        glVertex3f(-9.4f, -0.2f, -1.2f);
        glVertex3f(-9.4f, -3.0f, -1.2f);
        glVertex3f(-9.4f, -3.0f, -1.6f);

        glEnd();
    }
};

class Chair {
public:
    void drawChair() {

        //legs of chair
        //glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
        glColor3f(0.2f, 0.2f, 0.2f); //grey
        glBegin(GL_QUADS);

        //Front
        //
        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);

        //Right
        //
        glVertex3f(2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(2.0f, -0.2f, 2.0f);

        //Back
        //;
        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);

        //Left
        ;
        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);

        //top
        //

        glVertex3f(2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, 2.0f);
        glVertex3f(-2.0f, 0.2f, -2.0f);
        glVertex3f(2.0f, 0.2f, -2.0f);

        //bottom
        ;

        glVertex3f(2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, -0.2f, 2.0f);
        glVertex3f(-2.0f, -0.2f, -2.0f);
        glVertex3f(2.0f, -0.2f, -2.0f);

        //table front leg
        //front
        //

        glVertex3f(1.8f, -0.2f, 1.6f);
        glVertex3f(1.4f, -0.2f, 1.6f);
        glVertex3f(1.4f, -3.0f, 1.6f);
        glVertex3f(1.8f, -3.0f, 1.6f);

        //back
        //;

        glVertex3f(1.8f, -0.2f, 1.2f);
        glVertex3f(1.4f, -0.2f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.2f);

        //right
        //

        glVertex3f(1.8f, -0.2f, 1.6f);
        glVertex3f(1.8f, -0.2f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.2f);
        glVertex3f(1.8f, -3.0f, 1.6f);

        //left
        //;

        glVertex3f(1.4f, -0.2f, 1.6f);
        glVertex3f(1.4f, -0.2f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.2f);
        glVertex3f(1.4f, -3.0f, 1.6f);

        //back leg back
        //front
        //;

        glVertex3f(1.8f, -0.2f, -1.2f);
        glVertex3f(1.4f, -0.2f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.2f);

        //back
        //;

        glVertex3f(1.8f, -0.2f, -1.6f);
        glVertex3f(1.4f, -0.2f, -1.6f);
        glVertex3f(1.4f, -3.0f, -1.6f);
        glVertex3f(1.8f, -3.0f, -1.6f);

        //right
        //

        glVertex3f(1.8f, -0.2f, -1.6f);
        glVertex3f(1.8f, -0.2f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.2f);
        glVertex3f(1.8f, -3.0f, -1.6f);

        //left
        //

        glVertex3f(1.4f, -0.2f, -1.6f);
        glVertex3f(1.4f, -0.2f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.2f);
        glVertex3f(1.4f, -3.0f, -1.6f);

        //leg left front
        //

        glVertex3f(-1.8f, -0.2f, 1.6f);
        glVertex3f(-1.4f, -0.2f, 1.6f);
        glVertex3f(-1.4f, -3.0f, 1.6f);
        glVertex3f(-1.8f, -3.0f, 1.6f);

        //back
        //;

        glVertex3f(-1.8f, -0.2f, 1.2f);
        glVertex3f(-1.4f, -0.2f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.2f);

        //right


        glVertex3f(-1.8f, -0.2f, 1.6f);
        glVertex3f(-1.8f, -0.2f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.2f);
        glVertex3f(-1.8f, -3.0f, 1.6f);

        //left
        ;

        glVertex3f(-1.4f, -0.2f, 1.6f);
        glVertex3f(-1.4f, -0.2f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.2f);
        glVertex3f(-1.4f, -3.0f, 1.6f);

        //left leg back front

        //front
        ;

        glVertex3f(-1.8f, -0.2f, -1.2f);
        glVertex3f(-1.4f, -0.2f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.2f);

        //back
        ;

        glVertex3f(-1.8f, -0.2f, -1.6f);
        glVertex3f(-1.4f, -0.2f, -1.6f);
        glVertex3f(-1.4f, -3.0f, -1.6f);
        glVertex3f(-1.8f, -3.0f, -1.6f);

        //right


        glVertex3f(-1.8f, -0.2f, -1.6f);
        glVertex3f(-1.8f, -0.2f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.2f);
        glVertex3f(-1.8f, -3.0f, -1.6f);

        //left


        glVertex3f(-1.4f, -0.2f, -1.6f);
        glVertex3f(-1.4f, -0.2f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.2f);
        glVertex3f(-1.4f, -3.0f, -1.6f);

        //chair back
        //front


        //back of chair 
        //glColor3f(0.0f, 0.0f, 0.0f);//Black
        //glColor3f(0.902, 0.902, 0);
        glColor3f(0.0f, 0.5f, 0.5f);//teal

        glVertex3f(-1.8f, 1.2f, -1.8f);
        glVertex3f(1.8f, 1.2f, -1.8f);
        glVertex3f(1.8f, 3.5f, -1.8f);
        glVertex3f(-1.8f, 3.5f, -1.8f);

        glVertex3f(-1.8f, 1.2f, -0.6f);
        glVertex3f(1.8f, 1.2f, -0.6f);
        glVertex3f(1.8f, 3.5f, -0.6f);
        glVertex3f(-1.8f, 3.5f, -0.6f);

        //left and right of chair
        //glColor3f(1, 1, 0.4);
        //glColor3f(0.0f, 0.0f, 0.0f);//Black
        glColor3f(0.0f, 0.6f, 0.6f); //1 shade lighter

        glVertex3f(-1.8f, 1.2f, -1.80f);
        glVertex3f(-1.8f, 1.2f, -0.6f);
        glVertex3f(-1.8f, 3.5f, -0.6f);
        glVertex3f(-1.8f, 3.5f, -1.8f);

        glVertex3f(1.8f, 1.2f, -1.80f);
        glVertex3f(1.8f, 1.2f, -0.6f);
        glVertex3f(1.8f, 3.5f, -0.6f);
        glVertex3f(1.8f, 3.5f, -1.8f);

        //chair upper top 
       // glColor3f(1, 1, 0);
        //glColor3f(0.0f, 0.0f, 0.0f);//Black
        glColor3f(0.0f, 0.3f, 0.3f); //2 shades lighter

        glVertex3f(-1.8f, 3.5f, -1.80f);
        glVertex3f(-1.8f, 3.5f, -0.6f);
        glVertex3f(1.8f, 3.5f, -0.6f);
        glVertex3f(1.8f, 3.5f, -1.8f);

        glVertex3f(-1.8f, 1.2f, -1.80f);
        glVertex3f(-1.8f, 1.2f, -0.6f);
        glVertex3f(1.8f, 1.2f, -0.6f);
        glVertex3f(1.8f, 1.2f, -1.8f);

        // stand thing holder-------
        //glColor3f(0.2, 0.2, 0.0);
        //glColor3f(0.0f, 0.0f, 0.0f);//Black
        glColor3f(0.7f, 0.7f, 0.7f); //light grey

        //side walls
        glVertex3f(-1.2f, 1.2f, -1.20f);
        glVertex3f(-1.2f, 1.2f, -0.6f);
        glVertex3f(-1.2f, .2f, -0.6f);
        glVertex3f(-1.2f, .2f, -1.2f);
        glVertex3f(-.8f, 1.2f, -1.20f);
        glVertex3f(-.8f, 1.2f, -0.6f);
        glVertex3f(-.8f, .2f, -0.6f);
        glVertex3f(-.8f, .2f, -1.2f);

        //front walls and back walls
        glVertex3f(-1.2f, 1.2f, -1.2f);
        glVertex3f(-0.8f, 1.2f, -1.2f);
        glVertex3f(-0.8f, .2f, -1.2f);
        glVertex3f(-1.2f, .2f, -1.2f);

        glVertex3f(-1.2f, 1.2f, -0.6f);
        glVertex3f(-0.8f, 1.2f, -0.6f);
        glVertex3f(-0.8f, .2f, -0.6f);
        glVertex3f(-1.2f, .2f, -0.6f);

        //side walls
        glVertex3f(1.2f, 1.2f, -1.20f);
        glVertex3f(1.2f, 1.2f, -0.6f);
        glVertex3f(1.2f, .2f, -0.6f);
        glVertex3f(1.2f, .2f, -1.2f);

        glVertex3f(.8f, 1.2f, -1.20f);
        glVertex3f(.8f, 1.2f, -0.6f);
        glVertex3f(.8f, .2f, -0.6f);
        glVertex3f(.8f, .2f, -1.2f);

        //front walls and back walls stand thing holder---
        //glColor3f(0.2, 0.2, 0.0);
       //glColor3f(0.0f, 0.0f, 0.0f);//Black
        glColor3f(0.7f, 0.7f, 0.7f); //light grey

        glVertex3f(1.2f, 1.2f, -1.2f);
        glVertex3f(0.8f, 1.2f, -1.2f);
        glVertex3f(0.8f, .2f, -1.2f);
        glVertex3f(1.2f, .2f, -1.2f);

        glVertex3f(1.2f, 1.2f, -0.6f);
        glVertex3f(0.8f, 1.2f, -0.6f);
        glVertex3f(0.8f, .2f, -0.6f);
        glVertex3f(1.2f, .2f, -0.6f);

        //glVertex3f()

        glEnd();

    }


};


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, 2.5f, z, x + lx, 2.5f + ly, z + lz, roll + 0.0f, 2.5f, 0.0f);


    // Draw floor
    glColor3f(0.9f, 0.9f, 0.9f); // off white

    glBegin(GL_QUADS);
    glVertex3f(-10.0f, 0.0f, -10.0f);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glEnd();

    // Wall with white board
    glColor3f(0.4f, 0.8f, 0.8f); //dark teal
    glBegin(GL_QUADS);
    glVertex3f(-10.0f, 0.0f, -10.0f);
    glVertex3f(-10.0f, 7.0f, -10.0f);
    glVertex3f(10.0f, 7.0f, -10.0f);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glEnd();

    //left inside wall
    glColor3f(0.6f, 0.9f, 0.9f); // light teal
    glBegin(GL_QUADS);
    glVertex3f(-10.0f, 0.0f, -10.0f);
    glVertex3f(-10.0f, 7.0f, -10.0f);
    glVertex3f(-10.0f, 7.0f, 10.0f);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glEnd();

    //right wall with door
    glColor3f(0.6f, 0.9f, 0.9f); // light teal
    glBegin(GL_QUADS);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glVertex3f(10.0f, 7.0f, -10.0f);
    glVertex3f(10.0f, 7.0f, -9.0f);
    glVertex3f(10.0f, 0.0f, -9.0f);
    glEnd();

    glColor3f(0.6f, 0.9f, 0.9f); // light teal
    glBegin(GL_QUADS);
    glVertex3f(10.0f, 0.0f, -6.0f);
    glVertex3f(10.0f, 7.0f, -6.0f);
    glVertex3f(10.0f, 7.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glEnd();

    glColor3f(0.6f, 0.9f, 0.9f); // light teal
    glBegin(GL_QUADS);
    glVertex3f(10.0f, 5.0f, -9.0f);
    glVertex3f(10.0f, 7.0f, -9.0f);
    glVertex3f(10.0f, 7.0f, -6.0f);
    glVertex3f(10.0f, 5.0f, -6.0f);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f); //dark grey
    glLineWidth(30.0f);
    glBegin(GL_LINES);
    glVertex3f(10.0f, 5.0f, -8.98f);
    glVertex3f(10.0f, 0.0f, -8.98f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(10.0f, 5.0f, -6.02f);
    glVertex3f(10.0f, 0.0f, -6.02f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(10.0f, 5.0f, -9.0f);
    glVertex3f(10.0f, 5.0f, -6.0f);
    glEnd();



    //back wall 
    glColor3f(0.5f, 0.5f, 0.5f); //medium grey
    glBegin(GL_QUADS);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glVertex3f(-10.0f, 7.0f, 10.0f);
    glVertex3f(10.0f, 7.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glEnd();


    // Ceiling
    glColor3f(0.95f, 0.95f, 0.95f);
    glBegin(GL_QUADS);
    glVertex3f(-10.0f, 7.0f, -10.0f);
    glVertex3f(10.0f, 7.0f, -10.0f);
    glVertex3f(10.0f, 7.0f, 10.0f);
    glVertex3f(-10.0f, 7.0f, 10.0f);
    glEnd();


    // Draw student tables
    Table studentTable[4][4];
    for (int i = -3; i <= 3; i += 2) {
        glPushMatrix();
        glTranslatef(5.5 + 0.3f, 1.2f, i * 2.0 + 1.2f);
        glScalef(0.4f, 0.4f, 0.4f);
        // glRotatef(180.0, 0.0, 1.0, 0.0);
        studentTable[0][0].drawTable();
        glPopMatrix();
    }
    for (int i = -3; i <= 3; i += 2) {
        glPushMatrix();
        glTranslatef(-6.25 + 0.3f, 1.2f, i * 2.0 + 1.2f);
        glScalef(0.4f, 0.4f, 0.4f);
        // glRotatef(180.0, 0.0, 1.0, 0.0);
        studentTable[0][0].drawTable();
        glPopMatrix();
    }

    //Draw student chairs
    //Left side
    Chair studentChair;
    int a = -7;
    for (int i = 8; i <= 14; i += 2) {
        a = a + 4;
        for (int i = 2; i <= 8; i += 2) {
            glPushMatrix();
            glTranslatef(i * 1 + 1.1f + 0.3f, 0.8f, a);
            glScalef(0.25f, 0.25f, 0.25f);
            glRotatef(180.0, 0.0, 1.0, 0.0);
            studentChair.drawChair();
            glPopMatrix();
        }
    }
    //Right side
    int b = -7.5;
    for (int i = 0; i <= 6; i += 2) {
        b = b + 4;
        for (int i = -8; i <= -2; i += 2) {
            glPushMatrix();
            glTranslatef(i * 1 - 1.2f + 0.3f, 0.8f, b);
            glScalef(0.25f, 0.25f, 0.25f);
            glRotatef(180.0, 0.0, 1.0, 0.0);
            studentChair.drawChair();
            glPopMatrix();
        }
    }


    // Create an instance of the Window class
    Window window;
    // Call the window drawing functions
    window.drawWindow1();
    window.drawWindowSill();
    window.drawWindow2();
    window.drawWindowSill();

    // Draw blackboard
    //(0.4f, 0.2f, 0.0f);
    glColor3f(0.2f, 0.2f, 0.2f); //grey
    //glColor3f(0.0f, 0.0f, 0.0f); //black

    glBegin(GL_QUADS);
    glVertex3f(-6.0f, 2.0f, -9.99f);
    glVertex3f(-6.0f, 5.5f, -9.99f);
    glVertex3f(6.0f, 5.5f, -9.99f);
    glVertex3f(6.0f, 2.0f, -9.99f);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);// white

    // glColor3f(0.149f, 0.149f, 0.149f);
    glBegin(GL_QUADS);
    glVertex3f(-5.8f, 2.2f, -9.98f);
    glVertex3f(-5.8f, 5.3f, -9.98f);
    glVertex3f(5.8f, 5.3f, -9.98f);
    glVertex3f(5.8f, 2.2f, -9.98f);
    glEnd();

    //Floor pattern
    glColor3f(0.149f, 0.149f, 0.149f);
    glLineWidth(3.0f);
    for (int i = 0; i < 20; i += 2)
    {
        glBegin(GL_LINES);
        glVertex3f(-10.0f + i, 0.001f, -10.01f);
        glVertex3f(-10.0f + i, 0.001f, 10.01f);
        glEnd();
    }
    for (int i = 0; i < 20; i += 2)
    {
        glBegin(GL_LINES);
        glVertex3f(-10.0f, 0.001f, -10.01f + i);
        glVertex3f(10.0f, 0.001f, -10.01f + i);
        glEnd();
    }



    // Draw a 3D line from the window to the floor
    glLineWidth(9.f); // Set the line width
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.5f); //yellow
    // window part
    glVertex3f(-9.99f, 3.45f, -2.1f); 
    // stays the same== floor
    glVertex3f(0.0f, -1.05f, -10.0f); 
    // window part
    glVertex3f(-9.99f, 3.45f, -2.2f);
    // stays the same== floor
    glVertex3f(0.0f, -1.1f, -10.1f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.15f, -10.2f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.15f, -10.3f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.15f, -10.4f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.15f, -10.5f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.2f, -10.6f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.25f, -10.7f);
    // window part
    glVertex3f(-9.99f, 3.45f, -2.15f);
    // stays the same== floor
    glVertex3f(0.0f, -1.3f, -10.8f);

    glEnd();







    glutSwapBuffers();
}


void processSpecialKeys(int key, int xx, int yy) {
    float fraction = 0.1f;
    switch (key) {
    case GLUT_KEY_LEFT:
        x += sin(angle - PI / 2.0) * fraction;
        z += -cos(angle - PI / 2.0) * fraction;
        break;
    case GLUT_KEY_RIGHT:
        x += sin(PI / 2.0 + angle) * fraction;
        z += -cos(PI / 2.0 + angle) * fraction;
        break;
    case GLUT_KEY_UP:
        x += lx * fraction;
        z += lz * fraction;
        break;
    case GLUT_KEY_DOWN:
        x -= lx * fraction;
        z -= lz * fraction;
        break;
    }
}

void processNormalKeys(unsigned char key, int xx, int yy) {
    float fraction = 0.1f;
    if (key == 'w') {
        x += lx * fraction;
        z += lz * fraction;
    }
    else if (key == 'a') {
        x += sin(angle - PI / 2.0) * fraction;
        z += -cos(angle - PI / 2.0) * fraction;
    }
    else if (key == 's') {
        x -= lx * fraction;
        z -= lz * fraction;
    }
    else if (key == 'd') {
        x += sin(PI / 2.0 + angle) * fraction;
        z += -cos(PI / 2.0 + angle) * fraction;
    }
    else if (key == 'x') {
        roll += 0.5f;
    }
    else if (key == 'z') {
        roll -= 0.5f;
    }
    if (key == 27) // Esc key
        exit(0);
}

void processMouseMovement(int xx, int yy) {
    mouseX = (float)(halfWidth - xx) / halfWidth;
    mouseY = (float)(halfHeight - yy) / halfHeight;
    angle -= (0.005f * mouseX);
    lx = sin(angle);
    lz = -cos(angle);
    if (abs(yAngle) < (PI / 2)) {
        yAngle += (0.005f * mouseY);
    }
    ly = sin(yAngle);
}

void changeSize(int w, int h) {
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    halfWidth = (float)(w / 2.0);
    halfHeight = (float)(h / 2.0);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Classroom");

    glutDisplayFunc(renderScene);

    glutReshapeFunc(changeSize);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(processMouseMovement);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 1;
}




 

