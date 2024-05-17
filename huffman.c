#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<string.h>

typedef struct node{
    int occurence;
    unsigned char ascii;
    struct node* right;
    struct node* left;
}node;

typedef struct asciicode{
    unsigned char ascii;
    char size;
    int code;
}asciicode;


void print2dArray(int** a,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int log_2(int data){
    int output=0;
    while(data>0){
        output++;
        data = data / 2;
    }
    return output;
}

int mx(int a,int b){
    return  a>b ? a : b;
}

node* createNode(node* tmp, unsigned char ascii, int occurence){
    tmp->ascii = ascii;
    tmp->right = NULL;
    tmp->left  = NULL;
    tmp->occurence=occurence;
}

void swapNode(node* a,node* b){
    node tmp = *a;
    *a = *b;
    *b = tmp;
}

void combNode(node* left,node * right,node* tmp){  // combine and create new node
	tmp->occurence=left->occurence+right->occurence;
	tmp->left=left;
	tmp->right=right;
	tmp->ascii=255;
}
void heapifyNode(node *a, int n, int i){
	int smallest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && a[left].occurence < a[smallest].occurence){
		smallest = left;
	}
	if(right < n && a[right].occurence <a[smallest].occurence){
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
	}
}	

void traverseTree(node *root)  //traverse binary tree
    {
	if(root!=NULL){
		printf(" own %p left-> %p occurence-> %d right->%p ascii-> %d \n",root,root->left,root->occurence,root->right,root->ascii);
		traverseTree(root->left);
		traverseTree(root->right);
	}
}
void asciiCodeSort(asciicode* a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].ascii>a[j+1].ascii){
                asciicode tmp;
                tmp.ascii=a[j].ascii;
                tmp.code=a[j].code;
                tmp.size=a[j].size;
                a[j].ascii=a[j+1].ascii;
                a[j].code=a[j+1].code;
                a[j].size=a[j+1].size;
                a[j+1].ascii=tmp.ascii;
                a[j+1].code=tmp.code;
                a[j+1].size=tmp.size;
            }
        }
    }
}

void searchAndReturnCode(asciicode* a,int n,unsigned char asciiToFind,int* code,char* size){
    if(n<=0 && a[0].ascii != asciiToFind){
        printf("!!!!Something wrong with this ascii\n");
        exit(0);
    }
    int mid=n/2;
    if(a[mid].ascii>asciiToFind){
        searchAndReturnCode(a,mid,asciiToFind,code,size);
    }
    else if(a[mid].ascii<asciiToFind){
        searchAndReturnCode(&a[mid],n-mid,asciiToFind,code,size);
    }
    else {
       // printf("returning Code from searchAndReturnCode %c for %s\n",a[mid].ascii,a[mid].code);
        *code=a[mid].code;
        *size=a[mid].size;
       // printf("a[mid].ascii = %d a.[mid].code = %d a[mid].size = %d\n",a[mid].ascii,a[mid].code, a[mid].size);
    }
}
unsigned char searchAscii(asciicode* a, int n, int data){
    unsigned char res = 0;//=malloc(sizeof(result));
    for(int i=0;i<n;i++){
        if(data == a[i].code){
            res = a[i].ascii;
            return res;
        }
    }
    return res;
}

void CreateTree(node *sta, int size){ // structure array
    int k=size;
    while(1){
		if(k>1){
			heapNode(sta, k );
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
}

void print2DAVL(node* root, int space, int count){
    if(root==NULL)return;
    space += count;
    print2DAVL(root->right,space,count);
    for(int i=count;i<space;i++){
        printf(" ");
    }
    printf("(%d %d)\n",root->ascii,root->occurence);
    print2DAVL(root->left,space,count);
}
// print complete node tree
void pavl(node *root){
    print2DAVL(root,0,5);
}

int ind=0;
void generateCodes(node* root,asciicode* a,int data,char size){
    if(root!=NULL){
		//printf(" own %p left-> %p occurence-> %d right->%p ascii-> %d code-> %d \n",root,root->left,root->occurence,root->right,root->ascii,root->code);
        if(root->right == NULL && root->left == NULL){
            a[ind].ascii=root->ascii;
            a[ind].code = data;
            a[ind].size=size;
            ind++;
        }
        data = data << 1;
		generateCodes(root->left,a,data,size+1);
        data = data | 1;
		generateCodes(root->right,a,data,size+1);
	}
}

void storeTree(FILE* f, node* root){
    unsigned char wrt;
    wrt = root->ascii;
    fwrite(&wrt,sizeof(wrt),1,f);
    if(root->left){
        storeTree(f,root->left);
        storeTree(f,root->right);
    }
}
//node* createNode(node* tmp,unsigned char ascii,int occurence){
node* extractTree(FILE* f,node* root){
    unsigned char tmp;
    fread(&tmp,sizeof(tmp),1,f);
    node* nd = malloc(sizeof(node));
    createNode(nd,tmp,0);
    if(tmp == 255){
        nd->left = extractTree(f,nd->left);    
        nd->right = extractTree(f,nd->right);    
    }
    return nd;
}
void asciiCodeSortBySize(asciicode* a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].size>a[j+1].size){
                asciicode tmp;
                tmp.ascii=a[j].ascii;
                tmp.code=a[j].code;
                tmp.size=a[j].size;
                a[j].ascii=a[j+1].ascii;
                a[j].code=a[j+1].code;
                a[j].size=a[j+1].size;
                a[j+1].ascii=tmp.ascii;
                a[j+1].code=tmp.code;
                a[j+1].size=tmp.size;
            }
        }
    }
}

char searchCode(asciicode* a,int n,int data,int size,unsigned char* output){
    char result=0;
    for(int i=0;i<n;i++){
        if(a[i].size>size)break;
        if(a[i].size == size && a[i].code == data){
            *output = a[i].ascii;
            result = 1;
            break;
        } 
    }
    return result;
}
