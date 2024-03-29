#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void initastmp(char* tmp){
  int i=0;
  while(i<8){
    tmp[i]=0;
    i++;
  }
}
void pbin(int x){
  char tmp[8]="00000000";printf("x = %d\n", x);
  int i=7;
  //x=abs(x);
  while(x>0){
    tmp[i]=x%2+'0';
    i--;
    x=x/2;
  }
  printf("%s\n",tmp);
}
int main(){
  FILE* f=fopen("test.dat","wb");
  char c[5]="rohit";
  char encoded[155];
  int a[10][2];
  unsigned char tmp;
  FILE* f1=fopen("test.txt","r");
    while(0){
      tmp=fgetc(f1);
      if(tmp==EOF)break;
      printf("%c \n",tmp);
  }
  char b[][8]={"10101","10111","111","1001","111111"};
  printf("%lu sizeof\n",sizeof(b));
  
  int i=0,j=8,k=0;
    
  /*while(j<sizeof(b)/sizeof(b[0])){
    k=0;
    while(k<strlen(b[i])){
      printf("b[i][k] = %d\n",b[i][k]-'0');
      k++;
    }
    i++;
  }*/
  tmp=0;
  unsigned char tmp2=0;
  while(i<5){
    if(j>0 && k<strlen(b[i])){
      tmp2=b[i][k]-'0';
      printf("tmp2 = %d for a[%d][%d] -> %d\n", tmp2,i,k,b[i][k]);
      tmp=tmp|tmp2;
      pbin(tmp);
      pbin(tmp);
      j--;
      printf("j = %d\n", j);
      k++;
    }
    if(k==strlen(b[i])){
      i++;
      k=0;
    }
    if(j==0 || i==5 ){
      if(i==5){
        printf("for i = 5 tmp -> %d j->%d \n",tmp,j);
        tmp=tmp<< j;
      }
      printf("\ntmp -> ");
      pbin(tmp);
      fwrite(&tmp,sizeof(tmp),1,f);
      j=8;
      tmp=0;
    }
      tmp=tmp<<1;
  }
  //fclose(f);
    /*
  FILE* f=fopen("test.dat","rb");
  j=7;
  tmp2=0;
  int ind=0,ind2=0; //index for string 
  char *str=malloc(8*sizeof(char));
  initastmp(str);
  unsigned char tmp3=128;
  while(1){
    int k=fread(&tmp,sizeof(tmp),1,f);
    if(k<1)break;
    printf("-----------------------------\n");
    printf("tmp-> ");
    pbin(tmp);
    tmp3=128;
    while(1){
      tmp2= tmp & tmp3;
      printf("printing tmp2\n");
      pbin(tmp2);
      if(tmp2!=0){
        str[i]='1';
      }
      else{
        str[i]='0';
      }
      printf("str-> %s *************\n",str); 
      i++;
      while(ind2<5){
         if(strcmp(str,b[ind2])==0){
          printf("%s = %s at index %d found\n",str,b[ind2],ind2);
          tmp2=0;
          initastmp(str);
          i=0;
          ind2=0;
          break;
        }else{
          ind2++;
        }
      }
      ind2=0;
      tmp3=tmp3>>1;
      printf("tmp3->");
      pbin(tmp3);
      if(tmp3==0){
        break;
      }
      //printf("tmp2 = %d\n", tmpi2);
    }
    */
    //printf("tmp = %d\n", tmp);
    //printf("k = %d\n", k);
  //}
  fclose(f);
  printf("%d",strcmp("10101","10101"));
  return 0;
}
