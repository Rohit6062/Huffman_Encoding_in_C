#include<stdio.h>
#include<stdlib.h>
#include"huffMan.c"
#include<stdbool.h>
#include<unistd.h>

int shifthelp(int x,int y,int ans){
    if(x==y){ 
        return ans;
    }
    else{
        return shifthelp(x,y/2,ans++);
    }
} 

bool strcmp2(char *st1, char *st2){
    int n=strlen(st1);
    int m=strlen(st2);
    int i=0;
    while(1){
        if(i>=n || i>=m){
            return true;
        }
        else if(st1[i]!=st2[i]){
            return false;
        }

    }
}

unsigned char sea3rchAscii(ascicode* a, int n, char * str){
    unsigned char res = 0;//=malloc(sizeof(result));
    for(int i=0;i<n;i++){
        if(strcmp2(str,a[i].code)==true){
            res=(char)a[i].ascii;
            return res;
        }
    }
    return res;
}


int main(){
    FILE* bfile=fopen("Compressed.dat","rb");
    unsigned char read;
    unsigned char tmp;
    unsigned char tmp2;
    bool isasci=true;
    int n;
    int hgt=16;
    read=fgetc(bfile);
    n=read;

    ascicode codeArray[n];
    int j=0,i=0;
    tmp2=0;
    int ind=0,ind2=0; //index for string 
    
    char *str;
    str=malloc(hgt*sizeof(char));
    initastmp(str,hgt);
    unsigned char tmp4=128;
    printf("everything is fine till here\n");
    FILE *out=fopen("decompress.txt","w");
    int xx=0;
    unsigned char mm;
    printf("everything is fine till here\n");
    
    while(i<n){
        if(isasci){
            read=fgetc(bfile);
            codeArray[i].ascii = read;
            isasci =false;
        }
        else{
            read = fgetc(bfile);
            
        }
    }


    fread(&tmp,sizeof(tmp),1,bfile);
    while(1){
        xx=fread(&tmp,sizeof(tmp),1,bfile);
        if(xx<1)break;
        while(1){
            printf("inside while\n");
            tmp2= tmp & tmp4;
            pbin(tmp2);
            if(tmp2!=0){
                str[i]='1';
            }
            else{
                str[i]='0';
            }
            printf("%s\n",str);
            i++;
            if(sea3rchAscii(codeArray,n,str)!=0){
                    mm=sea3rchAscii(codeArray,n,str);
                    fwrite(&mm,sizeof(mm),1,out);
                    printf("%c",mm);
                    sleep(5);
                    tmp2=0;
                    initastmp(str,hgt);
                    i=0;
                    ind2=0;
            }
            tmp4=tmp4>>1;
            if(tmp4==0){
                tmp4=128;
                break;
            }
    }
  }
  fclose(bfile);
    return 0;
}
