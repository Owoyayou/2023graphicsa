///切換不同關節，改變不同角度
///int angle[20];angle[0] angle[1]...用他們來旋轉
///motion()時，用angle[ID]來改
///week15把angle存檔's'   播放動畫'r'
///week12_5_TRT_keyboard
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;///這邊改成我自己的檔案名稱，回家用
GLMmodel * lowarmR = NULL;///++
int show[4]={1,1,1,1};
int ID=3;///0:頭 1:身體 2:上手臂 3:下手臂 ///week14
FILE*fout=NULL;
FILE*fin=NULL;
float angle[20]={};
float teapotX=0,teapotY=0;

void keyboard(unsigned char key,int x,int y){
    if(key=='0') ID=0; //show[0]=!show[0];
    if(key=='1') ID=1; //show[1]=!show[1];
    if(key=='2') ID=2; //show[2]=!show[2];
    if(key=='3') ID=3; //show[3]=!show[3];
    if(key=='s') {
        if (fout==NULL)fout=fopen("motion.txt","w");///week15_step03寫檔案
        for(int i=0;i<20;i++){
            fprintf(fout,"%.2f ",anlge[i]);///%.2f 有空格
        }
        fprintf(fout,"\n");
    }else if(key=='r'){
        if(fin==NULL) fin=fopen("motion.txt","r");
        for(int i=0;i<20;i++){
            fprintf(fin,"%f",&anlge[i]);
        }
        glutPostRedisplay();
    }




    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);///week13
        if(body==NULL){
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/right_arm.obj");
            lowarmR=glmReadOBJ("model/right_hand.obj");///改黨名

        }
        if(ID==0) glColor3f(1,0,0);///選定 設紅色
        else glColor3f(1,1,1);///沒選定 設白色
        if(show[0]) glmDraw(head,GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///選定 設紅色
        else glColor3f(1,1,1);///沒選定 設白色
        if(show[1]) glmDraw(body,GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);///week14
            glRotatef(angle[2],0,0,1);
            glTranslatef(1.200000,-0.453333,0);

            if(ID==2) glColor3f(1,0,0);///選定 設紅色
            else glColor3f(1,1,1);///沒選定 設白色
            if(show[2])glmDraw(uparmR,GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(teapotX,teapotY,0);///week14
                glRotatef(angle[3],0,0,1);
                glTranslatef(1.200000,-0.453333,0);

                if(ID==3) glColor3f(1,0,0);///選定 設紅色
                else glColor3f(1,1,1);///沒選定 設白色
                if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glColor3f(0,1,0);///放個小茶壺在正中心當成參考點
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}

int oldX=0,oldY=0;
void motion(int x,int y){
    teapotX+=(x-oldX)/150.0;
    teapotY+=(x-oldY)/150.0;
    angle[ID]+=(x-oldX);
    oldX=x;
    oldY=y;
    //angle=x;///week14
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button,int state,int x,int y){
    if(state==GLUT_DOWN){
        teapotX=(x-150)/150.0;
        teapotY=(150-y)/150.0;
        if(fout==NULL)fout=fopen("file4.txt","w");
        fprintf(fout,"%f %f\n",teapotX,teapotY);
    }
    display();
}
//全選 > Edit > Comment
//void keyboard(unsigned char key,int x,int y){
//    if(fin==NULL){
//        fclose(fout);
//        fin=fopen("file4.txt","r");
//    }
//    fscanf(fin,"%f %f",&teapotX,&teapotY);
//    display();
//}


int main(int argc,char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");///這裡上禮拜也有問題

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);///week13
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
