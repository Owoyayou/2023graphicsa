#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(0,1,0);///green body
    glPushMatrix();
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25,0.25,0);///(3)把東西掛到右上角
            glRotatef(angle,0,0,1);   ///(2)旋轉
            glTranslatef(0.25,0.25,0);///(1)把旋轉中心放到中心
            //glTranslatef(0.5,0.5,0);
            glColor3f(1,0,0);///red arm
            glutSolidCube(0.5);
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
