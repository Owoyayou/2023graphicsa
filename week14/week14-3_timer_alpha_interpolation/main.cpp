///week14-2_timer_play用鍵盤播放
#include <GL/glut.h>
float angle=0,oldAngle=0,newAngle=0;///宣告變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t) ///timer函式 做對應動作
{
    if(t<100)glutTimerFunc(50,timer,t+1);///在100之內，設定下一個鬧鐘
    float alpha = t/100.0;///alpha介於0.00~1.00之間
    angle += 90;///增加90度
    glutPostRedisplay();///重畫畫面
}
void motion(int x,int y)
{
    angle=0;
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle=x;///按下去
    if(state==GLUT_UP) newAngle=x;///放開來
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
    glutMouseFunc(mouse);///按下去表示起點
    glutMotionFunc(motion);///當mouse在motion時，即時更新畫面
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
