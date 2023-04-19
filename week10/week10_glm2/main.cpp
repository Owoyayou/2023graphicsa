///下載source.zip > glm.h > 複製 > 放到week10_glm目錄裡
///glm.c改檔名glm.cpp放在week10_glm目錄裡
///把glm.cpp加到專案裡
///把模型檔 data裡的模型 > 複製 > 放到freeglut > bin
///Build log最後一行會說它在哪裡(in C:\User\...\freeglut\bin)

#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel=NULL;///有一個模型的指標，先是空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL){   ///複製source > transformation.c > 159行至167行
        pmodel=glmReadOBJ("Al.obj");
		glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }

    glmDraw(pmodel,GLM_MATERIAL);
   // glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10");

    glutDisplayFunc(display);
    glutMainLoop();
}
