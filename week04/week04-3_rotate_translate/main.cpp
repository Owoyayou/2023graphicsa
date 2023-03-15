///copy程式week04-1_rotate

#include <GL/glut.h>
float angle=0;///step02-1宣告global全域變數angle
void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();
        glTranslatef(0.6,0,0);///step03-2
        glRotatef(angle,0,1,0);///旋轉angle角度
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();

    glPushMatrix();
        glRotatef(angle,0,1,0);///旋轉angle角度
        glTranslatef(0.6,0,0);///step03-2
        glColor3f(1,0,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;///把角度++
}
int main(int argc,char *argv[])
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week04");


    glutDisplayFunc(display);
    glutIdleFunc(display);///重畫畫面
    glutMainLoop();

}
