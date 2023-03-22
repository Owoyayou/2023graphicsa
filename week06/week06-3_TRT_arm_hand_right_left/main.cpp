#include <GL/glut.h>
float angle=0;
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///�k���u
        glTranslatef(0.25,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);

        drawHand();

        glPushMatrix();///�k��y
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            drawHand();
        glPopMatrix();

    glPopMatrix();


        glPushMatrix();///�����u
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);

        drawHand();

        glPushMatrix();///����y
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);
            drawHand();
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc,char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week05");


    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

}
