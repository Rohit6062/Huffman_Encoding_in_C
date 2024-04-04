#include<stdio.h>
void ss(int x){
	if(x%4 >1){
		if(x%4 ==2){	
			printf("%d\n",(x/4)*3+1);
			printf("%d\n",(x/4)*3+2);
		}else{
			printf("%d\n",(x/4)*3+2);
			printf("%d\n",(x/4)*3+3);
		}	
	}
	else{
		printf("%d\n",(x/4)*3+(x%4));
	}
}
int main(){
int map[][2]={{'a','1'},{'k','2'},{'m','3'},{'i','4'},{'t','5'}};
      <:q

int n;
scanf("%d",&n);
ss(n);
return 0;
}




//(k/4)*3+(k%4)
//
//
//
//
//
