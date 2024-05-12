#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void print2d(int ** a, int n){
    for(int i=0;i<n;i++){
        printf("%d %d \n",a[i][0],a[i][1]);
    }
}

void insert(int ** a , int* n , int d1, int d2){
    a[*n][0]=d1;
    a[*n][1]=d2;
    *n=*n+1;
}

// check if given character is already found or not
bool ifinmapUpdate( int **map, int n, int ascii){
    for(int i=0;i<n;i++){
        if(map[i][0]==ascii){
            map[i][1]=map[i][1]+1;
            return true;
        }
    }
    return false;
} 



int main(){
    int **map=malloc(sizeof(int*)*100);
    int size=100;
    for(int i=0;i<size;i++){
        map[i]=malloc(sizeof(int)*2);
    }
    int len=0;
    FILE* f= fopen("test.txt","r");
    int ch;
    while(1){
        ch=fgetc(f);
        if(ch<0)break;
        if(ch=='u')
        printf("%c",ch);
        if(ifinmapUpdate(map,len,ch)==0){
            insert(map,&len,ch,1);
        }
    }
    print2d(map,len);
    fclose(f);
    return 0;
}
