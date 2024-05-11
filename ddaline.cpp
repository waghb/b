#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void plotpixel(int x,int y){
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void dda(int x1, int y1, int x2, int y2){
    int dx = x2-x1;
    int dy = y2-y1;

    float steps = max(abs(dx), abs(dy));
    float incx = dx/steps;
    float incy = dy/steps;
    float x=x1, y=y1;
    
    for(int i=0; i<steps; i++){
        plotpixel(x,y);
        x += incx;
        y += incy;
    }
    glEnd();
    glFlush();
}

void display(){
    //mountain
    dda(-200, -100, -100, 0);
    dda(-100, 0, 0, -100);
    dda(0, -100, 100, 100);
    dda(100, 100, 200, -100);

    // inner container
    dda(-200, 200, 200, 200);
    dda(200, 200, 200, -100);
    dda(200, -100, -200, -100);
    dda(-200, -100, -200, 200);

    // outer container
    dda(-220, 220, 220, 220);
    dda(220, 220, 220, -120);
    dda(220, -120, 50, -120);
    dda(-50, -120, -220, -120);
    dda(-220, -120, -220, 220);

    // holder
    dda(50, -120, 80, -150);
    dda(80, -150, -80, -150);
    dda(-80, -150, -50, -120);


}



void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 1 - monitor(DDA)");

    init();

    glutDisplayFunc(display);
 
    glutMainLoop();

    return 0;
}

