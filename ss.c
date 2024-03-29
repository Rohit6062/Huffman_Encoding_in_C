#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* right;
struct node* left;
int ascii;
}node;

void p(node* root){
	printf("%d %p %p %d\n",root->data,root->left,root->right,root->ascii);
}

void initbst(node* root,int data,int ascii){
	root->left = NULL;
	root->right = NULL;
	root->data=data;
	root->ascii=ascii;
	printf("%d %d\n",root->data,root->ascii);
}

void swapNode(node *a, node *b){
	node temp = *a;
	*a = *b;
	*b = temp;
}

void heapifyNode(node **a, int n, int i){
	int smallest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && a[left]->data < a[smallest]->data){
		smallest = left;
	}
	if(right < n && a[right]->data <a[smallest]->data){
		smallest = right;
	}
	if(smallest != i){
		swapNode(a[smallest], a[i]);
		heapifyNode(a, n, smallest);
	}
}

void heapNode(node **a, int n){
	printf("In HeapNode function widt %d \n",n);
	int j = n - 1;
	for(int i = n/2 - 1; i >=0; i--){
		heapifyNode(a, n, i);
	}
	if(j>=0){
	swapNode(a[0], a[j]);
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
	if(root==NULL)	return;
	printf("left-> %p data-> %d right->%p ascii-> %d\n",root->left,root->data,root->right,root->ascii);
	if(root->left){
		traverseTree(root->left);
	}
	if(root->right){
		traverseTree(root->right);
	}

}





int main(){
	int map[10][2]={ {97,10},{98,101},{99,11},{100,102},{103,9},{105,10},{107,101},{106,11},{109,102},{111,7}};	
	int n=sizeof(map)/sizeof(map[0]);
	node *sta[n];
	int i=0;
	while(i<n){
		sta[i]=malloc(sizeof(node*));
		sta[i]->data=map[i][1];
		sta[i]->ascii = map[i][0];
		sta[i]->left = NULL;
		sta[i]->right = NULL;
		i++;
	}
	i=0;
	int k=n;
	
	/// this is for testing if our heafify is working properly or not
	while(i < n){
		heapNode(sta, k);
		k--;
		node *root = sta[k];
		printf("own %p left-> %p data-> %d right->%p ascii-> %d\n",root,root->left,root->data,root->right,root->ascii);
		i++;
	}
/*	
	i=0;
	k=n;
	while(i<n){
		if(k>1){
			heapNode(sta, k);
			heapNode(sta,k-1);
			node temp;
			combNode(&sta[k-1],&sta[k-2],&temp);
			sta[k-2] = temp;
			k--;
		}
		else{
			break;
		}
	}
	node *root = &sta[0];	
	printf("own %p left-> %p data-> %d right->%p ascii-> %d\n",root,root->left,root->data,root->right,root->ascii);

	//traverseTree(&sta[0]);
*/
	return 0;
}
