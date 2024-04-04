#include<stdio.h>
int main(){
	FILE* f= fopen("config","r");
	int x;
	while(1){
		x= fgetc(f);
		if(x<0)break;
		printf("%d\n",x);
	}
return 0;
}
