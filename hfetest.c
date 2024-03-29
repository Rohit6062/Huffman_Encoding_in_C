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
int hgt;
void initastmp(char* tmp,int n){
  int i=0;
  while(i<n){
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
		 // printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s\n",root,root->left,root->data,root->right,root->ascii,root->code);
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
void createCodeAndAsciiArray(node* root,ascicode* a){
    if(root!=NULL){
		//printf(" own %p left-> %p data-> %d right->%p ascii-> %d code-> %s \n",root,root->left,root->data,root->right,root->ascii,root->code);
        if(root->ascii != -1){
        (a[p]).ascii=root->ascii;
        a[p].code=malloc(sizeof(char)*8);
        strcpy(a[p].code,root->code);
        //printf("copied successfull\n");
            p++;
        }
		createCodeAndAsciiArray(root->left,a);
		createCodeAndAsciiArray(root->right,a);
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

char* searchAndReturnCode(ascicode* a,int n,int asciiToFind){
    printf("n = %d\n", asciiToFind);
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

int main(){
//  int map[10][2]={ {97,10},{98,101},{99,11},{100,102},{103,9},{105,10},{107,101},{106,11},{109,102},{111,7}};	
  int map[][2]={{'l', 4238},{ 'o', 3093},{ 'r', 4847},{ 'e', 9365},{ 'm', 3846},{ ' ', 14417},{ 'i', 8416},{ 'p', 2011},{ 's', 7320},{ 'u', 7239},{ 'd', 2457},{ 't', 7017},{ 'a', 6886},{ ',', 4},{ 'c', 3381},{ 'n', 5004},{ 'g', 1199},{ 'b', 894},{ 'q', 1248},{ '.', 1939},{ 'v', 1497},{ 'f', 609},{ 'h', 447},{'\n', 264}, {'j', 46}};
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
	//traverseTree(&sta[0]);
    hgt=height(sta);
    i=0;
    allcode(sta); // allocate memory to code in struct ndoe
    char tempStr[hgt]; 
    AssignCodes(sta,tempStr,0);  //generate code from huffman Tree 
    //traverseTree(&sta[0]);       // traverseTree Again
    printf("length\n");
    psiofcd(sta);                 // print lenght of codes genrated
    printf("bitsrequired %d \n",countofbit(sta));
    
    node *root=sta;
    ascicode codeArray[n];
    createCodeAndAsciiArray(root,codeArray);
    printf("----------------------------------\n");
    i=0;
    
    asciiCodeSort(codeArray,n);
    while(i<n){
        printf("%d %s data of asciiArray\n",codeArray[i].ascii,codeArray[i].code);
        i++;
    }
    i=0;
    //printf("%s asciSearchFunction\n",searchAndReturnCode(codeArray,n,'a'));
    // Test Code Starts from here. 

  //  FILE* f=fopen("test.dat","wb");
    FILE* f1=fopen("test.txt","r");
    unsigned char tmp;
    while(0){
        tmp=fgetc(f1);
        if(tmp==EOF)break;
        printf("%c \n",tmp);
    }
  
    // perfectly Working Compression Code 
    i=0,k=0;
    int j=8;
    tmp=0;
    unsigned char tmp2=0;
    char* tmpcode;
    tmpcode = malloc(sizeof(char)*8);
    int flag=1;
    int tmp3;
    tmp3=fgetc(f1);
    printf("\n %c \n\n",tmp3);
    strcpy(tmpcode,searchAndReturnCode(codeArray,n,tmp3));
    /*
    while(flag){
        if(j>0 && k<strlen(tmpcode)){
            tmp2=tmpcode[k]-'0';
            printf("tmp2 = %d \n", tmp2);
            tmp=tmp|tmp2;
            pbin(tmp);
            pbin(tmp);
            j--;
            printf("j = %d\n", j);
            k++;
        }
        if(k==strlen(tmpcode)){
            tmp3=fgetc(f1);
            printf("character fget %c\n",tmp3);
            if(tmp3==EOF)flag=0;
            else{
            strcpy(tmpcode,searchAndReturnCode(codeArray,n,tmp3));
            k=0;
            }
        }
        if(j==0 || flag==0 ){
            if(flag==0){
                printf("for i = 5 tmp -> %d j->%d \n",tmp,j);
                tmp=tmp<< j;
                }
            printf("\ntmp -> ");
            pbin(tmp);
            fwrite(&tmp,sizeof(tmp),1,f);
            printf("\n\n Writing in File \n\n");
            j=8;
            tmp=0;
        }
        tmp=tmp<<1;
        //int mmmmm;
        //printf("\nYou want to go forward\n\n");
        //scanf("%d",&mmmmm);
  }
  fclose(f);

    */
   // /*
   // fclose(f);
    FILE* f=fopen("test.dat","rb");
    j=7;
    tmp2=0;
    int ind=0,ind2=0; //index for string 
    char *str;
    str=malloc(hgt*sizeof(char));
    initastmp(str,hgt);
    unsigned char tmp4=128;
    printf("everything is fine till here\n");
    FILE *out=fopen("decompress.txt","a");
    int xx=0;
    unsigned char mm;
    while(1){
        xx=fread(&tmp,sizeof(tmp),1,f);
        if(xx<1)break;
        //free(k);
        //printf("-----------------------------\n");
       // printf("tmp-> ");
        //pbin(tmp);
        tmp4=128;
        while(1){
            tmp2= tmp & tmp4;
            //printf("printing tmp2\n");
            //pbin(tmp2);
            if(tmp2!=0){
                str[i]='1';
            }
            else{
                str[i]='0';
            }
            //sleep(1);
            //printf("str-> %s *************\n",str); 
            //sleep(0.5);
            i++;
            if(searchAscii(codeArray,n,str)!=0){
                    mm=searchAscii(codeArray,n,str);
        //            printf("\n\t--> %c <-- \n",mm);
                    fwrite(&mm,sizeof(mm),1,out);
                    //printf("\n\n Writing in File \n\n");
                    tmp2=0;
                    initastmp(str,hgt);
                    i=0;
                    ind2=0;
                    //tmp4=tmp4>>1;
                    //break;
            }
            tmp4=tmp4>>1;
         //   printf("tmp4->");
         //   pbin(tmp4);
            if(tmp4==0){
                break;
            }
    //  printf("tmp2 = %d\n", tmp2);
    }
   // printf("tmp = %d\n", tmp);
  //  printf("k = %d\n", k);
  }
  fclose(f);
//*/
    return 0;
}
