#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int data;
	struct node* right;
	struct node* left;
	int ascii;
  char* code;
}node;

int hgt;

int mx(int a,int b){ //return maximum
  if(a>b){
    return a;
  }else{
    return b;
  }
}

int height(node* root){ // return height of the tree
  if(root==NULL)return 0;
  return mx(1+height(root->left),1+height(root->right));
}

void allcode(node* root){  // malloc size to code in node
    if(root==NULL)return;
    if(root->ascii!=-1)
      root->code=malloc(hgt*sizeof(char));
    allcode(root->left);
    allcode(root->right);
  }

void AssignCodes(node* root,char* tmp,int i){ // generate and assigne code after huffman tree is generated
    if(root==NULL)return;
    if( root->left==NULL && root->right == NULL){
		  printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s\n",root,root->left,root->data,root->right,root->ascii,root->code);
      printf(" %s\n",tmp);
      tmp[i]=0;
      strcpy(root->code,tmp);
    }
    if(root->right){
      tmp[i]='1';
      printf("%s\n",tmp);
      AssignCodes(root->right,tmp,i+1);
    }
    if(root->left){
      tmp[i]='0';
      printf("%s\n",tmp);
      AssignCodes(root->left,tmp,i+1);
    }
    tmp[i]=0;
    
  }

void initbst(node* root,int data,int ascii){
	root->left = NULL;
	root->right = NULL;
	root->data=data;
	root->ascii=ascii;
	printf("%p \t",root);
	printf(" Initiating Bst %d %d\n",root->data,root->ascii);
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
	//printf("Removed Item : %d\n", a[j]);
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
		printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s \n",root,root->left,root->data,root->right,root->ascii,root->code);
		traverseTree(root->left);
		traverseTree(root->right);
	}
}
void psiofcd(node *root){
  if(root==NULL)return;
  if(root->ascii != -1)
		printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s  len-> %ld\n",root,root->left,root->data,root->right,root->ascii,root->code,strlen(root->code));
psiofcd(root->left);
psiofcd(root->right);
}
int main(){
  int map[10][2]={ {97,10},{98,101},{99,11},{100,102},{103,9},{105,10},{107,101},{106,11},{109,102},{111,7}};	
  //int map[][2]={{'l', 4238},{ 'o', 3093},{ 'r', 4847},{ 'e', 9365},{ 'm', 3846},{ ' ', 14417},{ 'i', 8416},{ 'p', 2011},{ 's', 7320},{ 'u', 7239},{ 'd', 2457},{ 't', 7017},{ 'a', 6886},{ ',', 4},{ 'c', 3381},{ 'n', 5004},{ 'g', 1199},{ 'b', 894},{ 'q', 1248},{ '.', 1939},{ 'v', 1497},{ 'f', 609},{ 'h', 447},{'\n', 264}, {'j', 46}};
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
	int k = n;
	while(1){
		if(k>1){
			heapNode(sta, k);
			heapNode(sta,k-1);
			// as we are going to combine two nodes into a single node for that we will create two different nodes assign them vlaues of minimun and second minimum and then combine them into a 2nd minimum.
			node *tmp1;
			node *tmp2;
			tmp1=malloc(sizeof(node));
			tmp2=malloc(sizeof(node));
			*tmp1=sta[k-1];
			*tmp2=sta[k-2];
			combNode(tmp1,tmp2,&sta[k-2]);
			node* root = &sta[k-2];
			k--;
		}
		else{
			break;
		}
	}
	printf("\n traversal Result\n");
	traverseTree(&sta[0]);
  hgt=height(sta);
  i=0;
  allcode(sta); // allocate memory to code in struct ndoe
  char tempStr[hgt]; 
  AssignCodes(sta,tempStr,0);  //generate code from huffman Tree 
	traverseTree(&sta[0]);       // traverseTree Again
  printf("length\n");
  psiofcd(sta);                 // print lenght of codes genrated
return 0;
}
