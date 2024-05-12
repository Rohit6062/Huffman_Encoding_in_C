#include<stdio.h>
#include<stdlib.h>
#include"huffMan.c"
#include<unistd.h>
int main(){
    FILE* f=fopen("Compressed.dat","rb");
    int tmp;
    while(1){
        tmp=fgetc(f);
        if(tmp==EOF)break;
        pbin(tmp);
        sleep(5);
    }
    return 0;
}
