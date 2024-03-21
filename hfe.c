#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* right;
struct node* left;
int ascii;
}node;

void initbst(node* root,int data,int ascii){
//	root = malloc(sizeof(node*));
	root->data=data;
	root->ascii=ascii;
	printf("%d %d\n",root->data,root->ascii);
}

//void (node* root,int data,int ascii){
	
//}//

void min2(node** a,int n){
	node *ans[2];	
	printf("In mn2 %p\n",a[0]);
	int i=0,j;
	int mn=a[0]->data;
	int mn2=INT_MAX;
	while(i<n){
		if(a[i]->data<mn){
			ans[0]=a[i];
			mn=a[i]->data;
			j=i;
		}
		i++;
	}
	i=0;
	while(i<n){
		if(a[i]->data<mn2 && i!=j){
			ans[1]=a[i];
			mn2=a[i]->data;
		}
		i++;
	}
	printf("mn2 %d %d\n",ans[0]->data,ans[1]->data);
}


int main(){
	int map[10][2]={ {97,10},{98,101},{99,11},{100,102},{103,7},{105,10},{107,101},{106,11},{109,102},{111,7}};	
	
	int n=sizeof(map)/sizeof(map[0]);
	
	printf("%d\n",n);
	
	int pq[]={10,101,11,102,7,10,101,11,102,7};
	
	node *sta[n];
	
	//sta=malloc(n*sizeof(node*));

	int i=0;
	while(i<n){
		initbst(sta[i],map[i][0],map[i][1]);
		
		printf("maiin %d\n",sta[i]->data);
		i++;
	}
	
	min2(sta,n);

return 0;
}
