#include<stdio.h>
#include<stdlib.h>

int** build(int **a){
    a=malloc(sizeof(int*));
    a[0]=malloc(sizeof(int)*2);
    return a;
}

void pa(int ** a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void insert(int **a,int* n,char ascii){
    printf("%d\n",*n);
    a=realloc(a, sizeof(int*)*(*n+1));
    a[*n]=malloc(sizeof(int)*2);
    a[*n][0]=ascii;
    a[*n][1]=1;
    *n=*n+1;
}

int main(){
    int **map=build(map);
    map[0][0]='a';
    map[0][1]=1;
    int n=1;
    insert(map,&n,97);
    insert(map,&n,97);
    pa(map,n);

    return 0;
}
