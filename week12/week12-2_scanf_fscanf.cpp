#include <stdio.h>
int main(){
    ///檔案指標fout=開檔案("檔名","用什麼模式")
    FILE*fin=fopen("file.txt","r");

    char line[100];
    fscanf(fin,"%s",line);
    printf("從file.txt讀到了:%s\n",line);

    fscanf(fin,"%s",line);
    printf("從file.txt讀到了:%s\n",line);
}
