///week12_5_TRT_keyboard
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;///這邊改成我自己的檔案名稱，回家用
GLMmodel * lowarmR = NULL;///++
int show[4]={0,1,0,0};
void keyboard(){
    if(key=='0') show[0]=!show[0];
    if(key=='1') show[1]=!show[1];
    if(key=='2') show[2]=!show[2];
    if(key=='3') show[3]=!show[3];
}

FILE*fout=NULL;
FILE*fin=NULL;
float teapotX=0,teapotY=0;
float angle=0,angle2=0,angle3=0;//上禮拜我忘記打了
void display(){

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);///week13
        if(body==NULL){
            head=glmReadOBJ("model/head.obj");
            body=glmReadOBJ("model/body.obj");
            uparmR=glmReadOBJ("model/uparmR.obj");
            lowarmR=glmReadOBJ("model/lowarmR.obj");
        }
        if(show[0]) glmDraw(head,GLM_MATERIAL);
        if(show[1]) glmDraw(body,GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);

            if(show[2])glmDraw(uparmR,GLM_MATERIAL);
        glPopMatrix();
        if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
        if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);

    glPopMatrix();
    glutSwapBuffers();
}

int oldX=0,oldY=0;
void motion(int x,int y){
    teapotX+=(x-oldX)/150.0;
    teapotY+=(x-oldY)/150.0;
    oldX=x;
    oldY=y;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
    oldX=x;
    oldY=y;
    anlge=x;;
    display();
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
    glutCreateWindow("week12");///這裡上禮拜也有問題

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMouseFunc(motion);///week13
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
