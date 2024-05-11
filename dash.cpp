#include<GL/glut.h>
#include<math.h>

void printpoint(float x,float y){
    glColor3f(1,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

int round_off(float x){
    return floor(x+0.5);
}
void dash(float x1,float y1,float x2,float y2){
    float x=x1,y=y1;
    float dx=x2-x1;
    float dy=y2-y1;
    int steps=abs(dx)>abs(dy)?dx:dy;
    float xi=dx/(float)steps;
    float yi=dy/(float)steps;

    printpoint(x,y);
    for(int i=0;i<steps;i++){
        x+=xi;
        y+=yi;
        if(i%10<5){
            printpoint(round_off(x),round_off(y));
        }

    }
    glFlush();
}

void dash_dot(float x1,float y1,float x2,float y2){
    float x=x1,y=y1;
    float dx=x2-x1;
    float dy=y2-y1;
    int steps=abs(dx)>abs(dy)?dx:dy;
    float xi=dx/(float)steps;
    float yi=dy/(float)steps;

    printpoint(x,y);
    int val=0;
    for(int i=0;i<steps;i++){
        x+=xi;
        y+=yi;
          if(val<10 ||(val>14 && val<17)){
                printpoint(x,y);
            }
            val++;
            if(val==20){
                val=0;
            }

    }
    glFlush();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
   dash_dot(100,300,500,300);
   dash(100,200,500,200);
    glFlush();
}

void init()
{
    glClearColor(1.0 ,1.0, 1.0, 0.0); // black

                // line size 2.0f
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(500, 0);
    glutCreateWindow("dash");
    init();

    // Register mouse function
   // glutMouseFunc(mouse);

    // Register display function
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}