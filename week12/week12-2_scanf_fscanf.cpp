#include <stdio.h>
int main(){
    ///�ɮ׫���fout=�}�ɮ�("�ɦW","�Τ���Ҧ�")
    FILE*fin=fopen("file.txt","r");

    char line[100];
    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F:%s\n",line);

    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F:%s\n",line);
}
