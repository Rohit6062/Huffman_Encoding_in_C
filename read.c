#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* f= fopen("compress","r");
    int x;
    while(1){
        x=fgetc(f);
        if(x==EOF)break;
        printf("x = %d\n", x);
    }
    return 0;
}
