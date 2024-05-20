#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct rotation{
    int index;
    char* suffix;
}rotation;

int mod(int x, int y){
    if(x < y)return x;
    return mod(x-y,y);
}
int cmpfunc(const void* x, const void* y)
{
    rotation * rx = (rotation* )x;
    rotation * ry = (rotation* )y;
    return strcmp(rx->suffix,ry->suffix);
}

void bsort(rotation* a, int n){ 
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if( *(a[j].suffix) > *(a[j+1].suffix) ){
                rotation tmp;
                tmp.suffix=a[j].suffix;
                tmp.index=a[j].index;
                a[j].suffix=a[j+1].suffix;
                a[j].index=a[j+1].index;
                a[j+1].suffix=tmp.suffix;
                a[j+1].index=tmp.index;
            }
        }
    }
}


int charCmp(const void* a,const void* b){
    return (*(char*)a - *(char*)b);
}

int* computeSuffixArray(char* input_txt, int txt_len){
    rotation suff[txt_len];
    for(int i=0;i<txt_len;i++){
        suff[i].index = i;
        suff[i].suffix = (input_txt+i);
    }
    qsort(suff,txt_len,sizeof(rotation),cmpfunc);
    int* suffix_arr = malloc(sizeof(int)*txt_len);
    for(int i=0;i<txt_len;i++)
        suffix_arr[i]=suff[i].index;
    return suffix_arr;
}

void pa(int*a , int n){
    for(int i=0;i<n;i++){
        printf("a[i] = %d\n", a[i]);
    }
}

char* findLastChar(char* input_txt, int* suffix_arr, int n){
    char* bwt_arr = (char*) malloc(sizeof(char)*n);
    int i;
    for(i=0;i<n;i++){
        bwt_arr[i] = input_txt[mod(suffix_arr[i]+n-1,n)];
    }
    bwt_arr[i]='\0';
    return bwt_arr;
}

char* calculateOrg(char* input_txt, int n){
    rotation* sortedArr = malloc(sizeof(rotation)*n);
    int* input = malloc(sizeof(int)*n);
    char* output = malloc(sizeof(char)*n);
    for(int i=0;i<n;i++){
        sortedArr[i].index = i;
        sortedArr[i].suffix = input_txt+i;
    }
    bsort(sortedArr,n);
    for(int i=0;i<n;i++){
        input[sortedArr[i].index] =i;
    }
    pa(input,n);
    int k = sortedArr[0].index;
    printf("k = %d\n", k);
    for(int i=n-1;i>=0;i--){
        output[i]= input_txt[k];
        printf("k = %d\n", k);
        k = input[k];
    }
    printf("output = %s\n", output);
}

int main(){
    //char input_txt[] = "this_is_some_text_which_is_significantly_long$";
    //char input_txt[] = "rohit";
    //    printf("%p\n",input_txt);
    int i=0;
    int k=0;
    
    FILE* f = fopen("data.txt","r");
    char* input_txt = malloc(sizeof(char)); 
    while(1){
        k=getc(f);
        if(k==EOF){
            input_txt[i]=0;
            break;
        }
        //if(k==32) k = 95; 
        //if(k==10) k = 37; 
        input_txt[i]=k;
        i++;
       input_txt = realloc(input_txt, sizeof(char)*i+1);
    }
    int txt_len = strlen(input_txt);
    int* suffix_arr = computeSuffixArray(input_txt,txt_len);
    char* bwt_arr = findLastChar(input_txt,suffix_arr,txt_len);
    unsigned char ch = bwt_arr[0];
    printf("input_txt = %s\n", input_txt);
    printf("Burrows - Wheeler Transformation : %s\n", bwt_arr);
    calculateOrg(bwt_arr,txt_len);
    return 0;
}
