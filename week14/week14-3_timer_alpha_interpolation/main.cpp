///week14-2_timer_play����L����
#include <GL/glut.h>
float angle=0,oldAngle=0,newAngle=0;///�ŧi�ܼ�
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t) ///timer�禡 �������ʧ@
{
    if(t<100)glutTimerFunc(50,timer,t+1);///�b100�����A�]�w�U�@�Ӿx��
    float alpha = t/100.0;///alpha����0.00~1.00����
    angle += 90;///�W�[90��
    glutPostRedisplay();///���e�e��
}
void motion(int x,int y)
{
    angle=0;
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle=x;///���U�h
    if(state==GLUT_UP) newAngle=x;///��}��
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    glutTimerFunc(0,timer,0);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///���U�h��ܰ_�I
    glutMotionFunc(motion);///��mouse�bmotion�ɡA�Y�ɧ�s�e��
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
