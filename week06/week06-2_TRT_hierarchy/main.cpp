///改week06-1
///很多不同的連結狀況，手臂會帶手肘移動


#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glutSolidTeapot(0.3);///step02-1 body

        glPushMatrix();///右手臂
            glTranslatef(0.50,0.13,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.46,-0.05,0);
            glutSolidTeapot(0.3);



        glPushMatrix();///右手肘
            glTranslatef(0.50,0.13,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.46,-0.05,0);
            glutSolidTeapot(0.3);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc,char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week06");


    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();

}
