#include<iostream>
#include<GL/glut.h>
using namespace std;
int  xc,yc,x,r;

void plotPixel( int a,int b){
    glBegin(GL_POINTS);
    glVertex2i(a,b);
    glEnd();
    glFlush();
}

void draw(int xc,int yc,int x,int y){
    plotPixel(xc+x, yc+r);
    plotPixel(xc-x, yc+r);
    plotPixel(xc+x, yc-r);
    plotPixel(xc-x, yc-r);
    plotPixel(xc+r, yc+x);
    plotPixel(xc-r, yc+x);
    plotPixel(xc+r, yc-x);
    plotPixel(xc-r, yc-x);
}
void renderfunc(){
    x=0;
   
   
    int p=3-(2*r);
    while(x<=r){
    if(p<0){
        x++;
        p=p+(4*x)+6;

    }
    else{
        x++;
        r--;
        p=p+4*(x-r)+10;
    }
   draw(xc,yc,x,r);
    }

}



int main(int argc,char**argv){
   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(2000,200);
    glutCreateWindow("abc");
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,200,0,200);
    
    cout<<"enter x coordi of circle";
    cin>>xc;

    cout<<"enter y coordi of circle";
    cin>>yc;
    


    cout<<"enter radius betn 0 to 30";
    cin>>r;

    glutDisplayFunc(renderfunc);
    glutMainLoop();

}