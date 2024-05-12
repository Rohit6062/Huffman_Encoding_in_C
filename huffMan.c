#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct node{
	int data;
	struct node* right;
	struct node* left;
	int ascii;
    char* code;
}node;

typedef struct ascicode{
    int ascii;
    char * code;
}ascicode;

//int hgt;

void print2d(int ** a, int n){
    for(int i=0;i<n;i++){
        printf("%d %d \n",a[i][0],a[i][1]);
    }
}

void insert(int ** a , int* n , int d1, int d2){
    a[*n][0]=d1;
    a[*n][1]=d2;
    *n=*n+1;
}

// check if given character is already found or not
bool ifinmapUpdate( int **map, int n, int ascii){
    for(int i=0;i<n;i++){
        if(map[i][0]==ascii){
            map[i][1]=map[i][1]+1;
            return true;
        }
    }
    return false;
} 


void initastmp(char* tmp,int n){
  int i=0;
  while(i<n){
    tmp[i]=0;
    i++;
  }
}

void pbin(int x){    //print bytr in bimary form
  char tmp[8]="00000000";printf("x = %d\n", x);
  int i=7;
  while(x>0){
    tmp[i]=x%2+'0';
    i--;
    x=x/2;
  }
  printf("%s\n",tmp);
}

int mx(int a,int b){   //return maximum
  if(a>b){
    return a;
  }else{
    return b;
  }
}

int height(node* root){   // return height of the tree
  if(root==NULL)return 0;
  return mx(1+height(root->left),1+height(root->right));
}

void allcode(node* root , int size){  // malloc size to code in node
    if(root==NULL)return;
    if(root->ascii!=-1)
      root->code=malloc(size*sizeof(char));
    allcode(root->left,size);
    allcode(root->right,size);
  }

void AssignCodes(node* root,char* tmp,int i){ // generate and assigne code after huffman tree is generated
    if(root==NULL)return;
    if( root->left==NULL && root->right == NULL){
		 // printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s\n",root,root->left,root->data,root->right,root->ascii,root->code);
      tmp[i]=0;
      strcpy(root->code,tmp);
    }
    if(root->right){
      tmp[i]='1';
      AssignCodes(root->right,tmp,i+1);
    }
    if(root->left){
      tmp[i]='0';
      AssignCodes(root->left,tmp,i+1);
    }
    tmp[i]=0;
    
  }

void initbst(node* root,int data,int ascii){  //initialize the bst tree
	root->left = NULL;
	root->right = NULL;
	root->data=data;
	root->ascii=ascii;
	printf("%p \t",root);
	printf(" Initiating Bst %d %d\n",root->data,root->ascii);
}

void swapNode(node *a, node *b){  //swap node
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

void combNode(node* left,node * right,node* tmp){  // combine and create new node
	tmp->data=left->data+right->data;
	tmp->left=left;
	tmp->right=right;
	tmp->ascii=-1;
}

void traverseTree(node *root)  //traverse binary tree
    {
	if(root!=NULL){
		printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s \n",root,root->left,root->data,root->right,root->ascii,root->code);
		traverseTree(root->left);
		traverseTree(root->right);
	}
}
//print size of code
void psiofcd(node *root){
    if(root==NULL)return;
    if(root->ascii != -1)
	    printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s  len-> %ld\n",root,root->left,root->data,root->right,root->ascii,root->code,strlen(root->code));
    psiofcd(root->left);
    psiofcd(root->right);
}

// count of bits required to store compressed data
int countofbit(node* root ){
  if(root==NULL)return 0;
  if(root->ascii!=-1){
  return root->data * strlen(root->code) + countofbit(root->left) + countofbit(root->right);
  }
  else{
    return countofbit(root->left)+countofbit(root->right);
  }
}
int p=0;

// creates Array of ascii and code for file compression
void createCodeAndAsciiArray(node* root,ascicode* a,int hgt){
    if(root!=NULL){
		//printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s \n",root,root->left,root->data,root->right,root->ascii,root->code);
        if(root->ascii != -1){
        (a[p]).ascii=root->ascii;
        a[p].code=malloc(sizeof(char)*hgt);
        strcpy(a[p].code,root->code);
        //printf("copied successfull\n");
            p++;
        }
		createCodeAndAsciiArray(root->left,a,hgt);
		createCodeAndAsciiArray(root->right,a,hgt);
	}
}

// sorting AsciiCodesArray by using bubble

void asciiCodeSort(ascicode* a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].ascii>a[j+1].ascii){
                ascicode tmp;
                tmp.code=malloc(sizeof(char)*8);
                tmp.ascii=a[j].ascii;
                strcpy(tmp.code,a[j].code);
                a[j].ascii=a[j+1].ascii;
                strcpy(a[j].code,a[j+1].code);
                a[j+1].ascii=tmp.ascii;
                strcpy(a[j+1].code,tmp.code); 
                free(tmp.code);
            }
        }
    }
}

//search for ascii and return code
char* searchAndReturnCode(ascicode* a,int n,int asciiToFind){
    if(n<=0 && a[0].ascii != asciiToFind){
        printf("!!!!Something wrong with this ascii\n");
        exit(0);
    }
    int mid=n/2;
    if(a[mid].ascii>asciiToFind){
        return searchAndReturnCode(a,mid,asciiToFind);
    }
    else if(a[mid].ascii<asciiToFind){
        return searchAndReturnCode(&a[mid],n-mid,asciiToFind);
    }
    else {
       // printf("returning Code from searchAndReturnCode %c for %s\n",a[mid].ascii,a[mid].code);
        return a[mid].code;
    }
}

//search for code and return ascii according to it

unsigned char searchAscii(ascicode* a, int n, char * str){
    unsigned char res = 0;//=malloc(sizeof(result));
    for(int i=0;i<n;i++){
        if(strcmp(str,a[i].code)==0){
            res=(char)a[i].ascii;
            return res;
        }
    }
    return res;
}


void CreateTree(node * sta, int size){ // structure array
    int k=size;
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
    printf("Tree successfully Created!\n");
}

