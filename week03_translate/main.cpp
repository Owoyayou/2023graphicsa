#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef(X, Y, 0);///只有這行還不夠
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣


    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.456, 0.256);
        glVertex2f(-0.492, 0.320);
        glVertex2f(-0.508, 0.388);
        glVertex2f(-0.544, 0.520);
        glVertex2f(-0.556, 0.628);
        glVertex2f(-0.560, 0.716);
        glVertex2f(-0.508, 0.764);
        glVertex2f(-0.424, 0.764);
        glVertex2f(-0.384, 0.668);
        glVertex2f(-0.356, 0.552);
        glVertex2f(-0.328, 0.452);
        glVertex2f(-0.288, 0.348);
        glVertex2f(-0.296, 0.272);
        glVertex2f(-0.356, 0.236);
        glVertex2f(-0.408, 0.260);
        glVertex2f(-0.428, 0.288);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.228, 0.372);
        glVertex2f(0.240, 0.456);
        glVertex2f(0.284, 0.572);
        glVertex2f(0.328, 0.724);
        glVertex2f(0.368, 0.784);
        glVertex2f(0.440, 0.784);
        glVertex2f(0.492, 0.652);
        glVertex2f(0.488, 0.576);
        glVertex2f(0.480, 0.496);
        glVertex2f(0.464, 0.416);
        glVertex2f(0.448, 0.352);
        glVertex2f(0.420, 0.280);
    glEnd();

    glBegin(GL_POLYGON);
            glVertex2f(-0.136, -0.408);
    glVertex2f(-0.188, -0.388);
    glVertex2f(-0.256, -0.368);
    glVertex2f(-0.320, -0.340);
    glVertex2f(-0.396, -0.304);
    glVertex2f(-0.448, -0.260);
    glVertex2f(-0.504, -0.176);
    glVertex2f(-0.532, -0.076);
    glVertex2f(-0.544, 0.064);
    glVertex2f(-0.500, 0.184);
    glVertex2f(-0.420, 0.308);
    glVertex2f(-0.312, 0.352);
    glVertex2f(-0.128, 0.392);
    glVertex2f(0.136, 0.404);
    glVertex2f(0.296, 0.364);
    glVertex2f(0.460, 0.304);
    glVertex2f(0.544, 0.200);
    glVertex2f(0.572, 0.096);
    glVertex2f(0.584, -0.020);
    glVertex2f(0.568, -0.136);
    glVertex2f(0.532, -0.204);
    glVertex2f(0.448, -0.272);
    glVertex2f(0.364, -0.312);
    glVertex2f(0.256, -0.344);
    glVertex2f(0.136, -0.364);
    glVertex2f(0.036, -0.376);
    glVertex2f(-0.040, -0.384);

    glEnd();


    glutSwapBuffers();
}

void mouse (int buttom, int state, int x, int y)
{
    float X=  (x-250)/250.0;
    float Y= -(y-250)/250.0;
    if(state==GLUT_DOWN){///只有按下mouse,才印出程式,等下需剪下貼上
        printf("    glVertex2f(%.3f, %.3f);\n",X,Y);
    }
}


int main(int argc,char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(500,500);///step03

    glutCreateWindow("week03");
    glutDisplayFunc(display);

    glutMouseFunc(mouse);

    glutMainLoop();

}
