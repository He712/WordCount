#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void main(int argc,char *argv[]){
    char c;
 int bufferlen;
 int isLastBlank = 0; // �ϸ��ַ��Ƿ��ǿո�(1��ʾ��  0��ʾ����)
 int charCount=0;
 int wordCount=0;
 int lineCount=0;

    FILE* fp;        //�ļ�ָ��
    
    char buffer[MAX_LINE] ;        //������
    int len ;    //���ַ�����
    int i;
    fp = fopen(argv[2],"r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
    //��ȡ�ļ�����
    while(! feof(fp)){
        while(fgets(buffer,1000,fp)!=NULL){
  bufferlen=strlen(buffer);
  for(i=0;i<bufferlen;i++){
   c=buffer[i];
   if(c==' ' || c=='\t'){
    if(isLastBlank==0){
     wordCount++;
    }
    isLastBlank=1;
   }else if(c!='\n'&&c!='\r'){
    charCount++;
    isLastBlank=0;
   }
 
  }
  if(isLastBlank==0)
   wordCount++;
  isLastBlank=1;
  lineCount++;
 }
}

    fclose(fp);
    //���
    if(strcmp(argv[1],"-c")==0)
     printf("\t ���ַ���Ϊ %d \n \n",charCount);
    else
    printf("\n\t �ܵ�����Ϊ %d \n \n",wordCount);
    
}

