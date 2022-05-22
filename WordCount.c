#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void main(int argc,char *argv[]){
    char c;
 int bufferlen;
 int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
 int charCount=0;
 int wordCount=0;
 int lineCount=0;

    FILE* fp;        //文件指针
    
    char buffer[MAX_LINE] ;        //缓冲区
    int len ;    //行字符个数
    int i;
    fp = fopen(argv[2],"r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
    //读取文件内容
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
    //输出
    if(strcmp(argv[1],"-c")==0)
     printf("\t 总字符数为 %d \n \n",charCount);
    else
    printf("\n\t 总单词数为 %d \n \n",wordCount);
    
}

