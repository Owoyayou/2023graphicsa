///week11-1_keyboard 學習自GLUT專案的範例
#include <GL/glut.h>
void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard (unsigned char key, int x, int y)
{
    if(key==27) exit(0);
}   ///ESC就會結束
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");


    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///step01-1

    glutMainLoop();
}
