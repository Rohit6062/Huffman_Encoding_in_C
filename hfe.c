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
	root->left = NULL;
	root->right = NULL;
	root->data=data;
	root->ascii=ascii;
	printf("Initiating Bst %d %d\n",root->data,root->ascii);
}

void swapNode(node *a, node *b){
	node temp = *a;
	*a = *b;
	*b = temp;
}

void heapifyNode(node *a, int n, int i){
	int smallest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && a[left].data < a[smallest].data){
		smallest = left;
	}
	if(right < n && a[right].data <a[smallest].data){
		smallest = right;
	}
	if(smallest != i){
		swapNode(&a[smallest], &a[i]);
		heapifyNode(a, n, smallest);
	}
}

void heapNode(node *a, int n){
	int j = n - 1;
	for(int i = n/2 - 1; i >=0; i--){
		heapifyNode(a, n, i);
	}
	if(j>=0){
	swapNode(&a[0], &a[j]);
	heapifyNode(a, j, 0);
	printf("Removed Item : %d\n", a[j]);
	}
}	

void combNode(node* left,node * right,node* tmp){
	tmp->data=left->data+right->data;
	tmp->left=left;
	tmp->right=right;
	tmp->ascii=-1;
}

void traverseTree(node *root)
{
	if(root!=NULL){
		printf("own %p left-> %p data-> %d right->%p ascii-> %d\n",root,root->left,root->data,root->right,root->ascii);
		traverseTree(root->left);
		traverseTree(root->right);
	}
}

int main(){
    int map[10][2]={ {97,10},{98,101},{99,11},{100,102},{103,9},{105,10},{107,101},{106,11},{109,102},{111,7}};	
	int n=sizeof(map)/sizeof(map[0]);
	printf("%d\n",n);
	node* sta;
	sta=malloc(n*sizeof(node));
	int i=0;

	// this will create node for every element in map;
	while(i<n){
		initbst(&sta[i],map[i][1],map[i][0]);
		i++;
	}
	i = 0;
	int k=n;
	while(i < 0){
		heapNode(sta, k);
		k--;
		node *root = &sta[k];
		printf("own %p left-> %p data-> %d right->%p ascii-> %d\n",root,root->left,root->data,root->right,root->ascii);
		i++;
	}
	k = n;
	while(1){
		if(k>1){
			heapNode(sta, k);
			heapNode(sta,k-1);
			// as we are going to combine two nodes into a single node for that we will create two different nodes assign them vlaues of minimun and second minimum and then combine them into a 2nd minimum.
			node *tmp1;
			node *tmp2;
			tmp1=malloc(sizeof(node*));
			tmp2=malloc(sizeof(node*));
			*tmp1=sta[k-1];
			*tmp2=sta[k-2];
			sta=realloc(sta,k*sizeof(node));
			combNode(tmp1,tmp2,&sta[k-2]);
			k--;
			node* root = &sta[k-2];
			printf("Main While own %p left-> %p data-> %d right->%p ascii-> %d\n",root,root->left,root->data,root->right,root->ascii);
		}
		else{
			break;
		}
	}
	printf("\n traversal Result\n");
	traverseTree(&sta[0]);

return 0;
}

