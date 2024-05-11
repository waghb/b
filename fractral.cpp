#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

int n; // Global variable for the number of iterations
float max_x = 360.0, max_y = 270.0; // Maximum coordinates reached by the Koch curve



// Converting the degree angle to radian
float ang(float d)
{
    return (float)d * 3.14159265358979323846 / 180;
}

void draw_koch(float xa, float ya, float xb, float yb, int n)
{
    float xc, xd, yc, yd, midx, midy;

    // C and D points trisect the A-B line
    xc = (2 * xa + xb) / 3;
    yc = (2 * ya + yb) / 3;
    xd = (2 * xb + xa) / 3;
    yd = (2 * yb + ya) / 3;

    // (Mid) point is made by the curve continuation of C and D
    midx = xc + ((xd - xc) * cos(ang(60))) + ((yd - yc) * sin(ang(60)));
    midy = yc - ((xd - xc) * sin(ang(60))) + ((yd - yc) * cos(ang(60)));

    if (n > 0)
    {
        draw_koch(xa, ya, xc, yc, n - 1);
        draw_koch(xc, yc, midx, midy, n - 1);
        draw_koch(midx, midy, xd, yd, n - 1);
        draw_koch(xd, yd, xb, yb, n - 1);
    }

    else
    {
        glVertex2f(xa, ya);
        // glVertex2f(xc, yc);

        // glVertex2f(xc, yc);
        // glVertex2f(midx, midy);

        // glVertex2f(midx, midy);
        // glVertex2f(xd, yd);

        // glVertex2f(xd, yd);
        glVertex2f(xb, yb);

        // Update max_x and max_y if necessary
        if (xa < -max_x)
            max_x = -xa;
        if (xb > max_x)
            max_x = xb;
        if (ya < -max_y)
            max_y = -ya;
        if (yb > max_y)
            max_y = yb;
    }
}

void draw()
{
    glBegin(GL_LINES);
    draw_koch(0, -200, 173.40, 100, n);
    draw_koch(173.40, 100, -173.40, 100, n);
    draw_koch(-173.40, 100, 0, -200, n);
    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-max_x, max_x, -max_y, max_y);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(-max_x, max_x, -max_y, max_y);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    glutPostRedisplay(); 
}
int main(int argc, char **argv)
{
    cout << "\n[Koch Curve]" << endl;
    cout << "Enter the number of iterations (n): ";
    cin >> n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(720, 540);
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(draw);
    init();
    glutMainLoop();
    return 0;
}