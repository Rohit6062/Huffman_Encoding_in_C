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
	root->data=data;
	root->ascii=ascii;
	printf("%d %d\n",root->data,root->ascii);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swapNode(node *a, node *b){
	node temp = *a;
	*a = *b;
	*b = temp;
}


void heapify(int *a, int n, int i){
	int smallest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && a[left] < a[smallest]){
		smallest = left;
	}
	if(right < n && a[right] <a[smallest]){
		smallest = right;
	}
	if(smallest != i){
		swap(&a[smallest], &a[i]);
		heapify(a, n, smallest);
	}
}

void heap(int *a, int n){
	printf("In Heap function \n");
	int j = n - 1;
	for(int i = n/2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}
	swap(&a[0], &a[j]);
	heapify(a, j, 0);
	printf("Removed Item : %d\n", a[j]);
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

	printf("In HeapNode function widt %d \n",n);
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
}

void traverseTree(node *root)
{
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
	printf("%d\n",n);
	node sta[n];
	int i=0;

	// this will create node for every element in map;
	while(i<n){
		initbst(&sta[i],map[i][1],map[i][0]);
	//	printf("maiin %d\n",sta[i].data);
		i++;
	}


	//heapNode(sta, 10);
	//printf("%d at main return of heapNOde \n",sta[n-1].data);	
	//heapNode(sta, 9);
	//printf("%d at main return of heapNOde \n",sta[n-2].data);	
	//combNode(&sta[n-1],&sta[n-2],&sta[n-2]);
	//printf("%d after combination left -> %d \n",sta[n-2].data,sta[n-2].left->data);	

	// minimum will be in n-1 position of struct array
	//  second mim will be in n-2 position 
	//  and combine will be n-2 position
	//  heapNode will return minimum node at last position
	i=0;
	int k=n;
	while(i<n){
		if(k>0){
			heapNode(sta, k);
			heapNode(sta,k-1);
			combNode(&sta[k-1],&sta[k-2],&sta[k-2]);
			k--;
		}
		else{
			break;
		}
	}
	traverseTree(&sta[0]);


return 0;
}

