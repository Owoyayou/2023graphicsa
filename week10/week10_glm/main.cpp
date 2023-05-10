///�U��source.zip > glm.h > �ƻs > ���week10_glm�ؿ���
///glm.c���ɦWglm.cpp��bweek10_glm�ؿ���
///��glm.cpp�[��M�׸�
///��ҫ��� data�̪��ҫ� > �ƻs > ���freeglut > bin
///Build log�̫�@��|�����b����(in C:\User\...\freeglut\bin)

#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel=NULL;///���@�Ӽҫ������СA���O�Ū�
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL){   ///�ƻssource > transformation.c > 159���167��
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
