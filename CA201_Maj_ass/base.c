#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct line{
    char* start;
    int len;
}line;

typedef struct page{
    line* start;
    int len;
}page;

page file;
line currLine;
FILE* f;
void checkPointer(void* ptr){
    if(ptr==NULL){
        printf("fail to allocate Memory\n");
        exit(0);
    }
}

void init(char * fileName){ 
    f=fopen(fileName,"w");
    checkPointer(f);
    
    currLine.start=(char*)malloc(sizeof(char)*2);
    currLine.len=2;
    checkPointer(currLine.start);

    file.start= (line*) malloc(sizeof(line*)*1);
    file.len = 1;
    checkPointer(file.start);
}

void viewLn(line ln){
    printf("this is view %s\n",ln.start);
}

void view(){
    for(int i=0;i<file.len-1;i++){
        viewLn(file.start[i]);
    }
}

void insertLine(line line){
    printf("line to insert %s\n",line.start);
    file.start[file.len-1]=line;
    file.len++;
    file.start = realloc(file.start,sizeof(line)*file.len);
}

void insertToLine(char *c){
    //printf("current char %c\n",*c);
    if(*c=='\0'){
        //printf("this is new Line\n");
        strcpy(currLine.start+currLine.len-2,c);
        insertLine(currLine);
        currLine.len=2;
        currLine.start=(char*)realloc(currLine.start,currLine.len);
    }
    else
    {
        strcpy(currLine.start+currLine.len-2,c);
        currLine.len++;
        currLine.start=(char*)realloc(currLine.start,currLine.len);
        checkPointer(currLine.start);
    }
}

int main(){
    init("text.txt"); 
    char tmp[]="something to unr";
    char tmp2[]="This is line two";

    for(int i=0;i<sizeof(tmp)/sizeof(tmp[0]);i++){
        insertToLine(&tmp[i]);
    }

    for(int i=0;i<sizeof(tmp2);i++){
        insertToLine(&tmp2[i]);
    }
    view();
    return 0;
}
