#include<stdio.h>
#include<stdlib.h>
#include"huffMan.c"
#include<stdbool.h>

void strToByte(char *str,unsigned char* a,unsigned char* b){
    printf("str-> %s\n",str);
    *a=0;
    *b=0;
    int indForstr = 0;
    unsigned char toOrr = 128;
    bool fora=true;
    while(indForstr < strlen(str)){
        if((str[indForstr])=='1' && fora ){
            *a = *a | toOrr;
            pbin(*a);
        }
        else if((str[indForstr])=='1'){
            *b = *b | toOrr;
            pbin(*b);
        }
        toOrr = toOrr >> 1;
        indForstr ++;
        printf("indForstr-> %d\n",indForstr);
        if(toOrr == 0 && fora){
            fora = false;
            toOrr = 128;
            printf("shift\n");
        }
        else if(toOrr == 0){
            return;
        }
    }
}


int main(){
    
    int **map=malloc(sizeof(int*)*100);
    int size=100;
    for(int i=0;i<size;i++){
        map[i]=malloc(sizeof(int)*2);
    }
    int n=0;
    FILE* ff= fopen("test.txt","r");
    int ch;
    while(1){
        ch=fgetc(ff);
        if(ch<0)break;
        if(ifinmapUpdate(map,n,ch)==0){
            insert(map,&n,ch,1);
        }
    }
    print2d(map,n);
    fclose(ff);

//*/
    // creating array of 
    node* sta;
	sta=malloc(n*sizeof(node));
	
    int i=0,k;

	// this will create node for every element in map;
	while(i<n){
		initbst(&sta[i],map[i][1],map[i][0]);
		i++;
	}
    
    //Creating tree from above structure array
    CreateTree(sta,n);

    // calculating height of tree.
    int hgt=height(sta);

    // allocate memory to code in struct ndoe
    allcode(sta,hgt); 
     
    //generate code from huffman Tree 
    char tempStr[hgt];
    AssignCodes(sta,tempStr,0);

    //traverseTree(&sta[0]);       // traverseTree Again
    //printf("length\n"); 
    // print lenght of codes genrated
    psiofcd(sta);                
    printf("bitsrequired %d \n",countofbit(sta));

    
    // Creating code and ascii array
    node *root=sta;
    ascicode codeArray[n];
    createCodeAndAsciiArray(root,codeArray,hgt);
    printf("----------------------------------\n");
    
    // sort ascii_code array
    i=0;
    asciiCodeSort(codeArray,n);
    while(i<n){
        printf("%d %s data of asciiArray\n",codeArray[i].ascii,codeArray[i].code);
        i++;
    }
    
    //printf("%s asciSearchFunction\n",searchAndReturnCode(codeArray,n,'a'));
    
    //Test Code Starts from here.
    /*
    FILE* f;
    char * FileName = malloc(sizeof(char)*20);
    if(argc<2){
        printf("Enter File Name You Want to Compress \n");  
        scanf("%s",FileName);
    }
    else{ 
        printf("You ahve entered file named as %s\n",argv[1]);
        strcpy(fileName,argv[1]);
    }
    f=fopen(fileName,"r");
    if(f==NULL){
        printf("")
    }
    */
    FILE* f1= fopen("test.txt","r");
    FILE* f=fopen("Compressed.dat","wb");
    unsigned char tmp;

    // perfectly Working Compression Code 
    
    i=0,k=0;
    int j=8;
    tmp=0;
    unsigned char tmp2=0;
    char* tmpcode;
    tmpcode = malloc(sizeof(char)*hgt);
    int flag=1;
    int tmp3;
    unsigned char ascitmp;
    unsigned char toput;
    //  Putting MAP table into the file
    toput=n;
    fwrite(&toput,sizeof(toput),1,f);
    toput=codeArray[0].ascii;
    fwrite(&toput,sizeof(toput),1,f);
    i=0;
    // i for code array
    // j for byte and 
    // k for char string
    tmp=0;
    bool isasci = false;
    
    while(i<n){
        if(isasci){
            toput = codeArray[i].ascii;
            fwrite(&toput,sizeof(toput),1,f);
            pbin(toput);
            isasci=false;
        }
        else{
            strcpy(tmpcode,codeArray[i].code);
            strToByte(tmpcode,&tmp,&toput);
            fwrite(&tmp,sizeof(tmp),1,f);
            fwrite(&toput,sizeof(toput),1,f);
            pbin(tmp);
            pbin(toput);
            printf("\n");
            i++;
            isasci=true;
        }
    }
    tmp3=fgetc(f1);
    printf("\n %c \n\n",tmp3);
    strcpy(tmpcode,searchAndReturnCode(codeArray,n,tmp3));
    flag =1;
    i=0;
    k=0;
    tmp2=0;
    j=8;
    while(flag){
        if(j>0 && k<strlen(tmpcode)){
            tmp2=tmpcode[k]-'0';
            tmp=tmp|tmp2;
            j--;
            k++;
        }
        if(k==strlen(tmpcode)){
            tmp3=fgetc(f1);
            if(tmp3==EOF)flag=0;
            else{
            strcpy(tmpcode,searchAndReturnCode(codeArray,n,tmp3));
            k=0;
            }
        }
        if(j==0 || flag==0 ){
            if(flag==0){
                tmp=tmp<< j;
                }
            fwrite(&tmp,sizeof(tmp),1,f);
            j=8;
            tmp=0;
        }
        tmp=tmp<<1;
  }
fclose(f);
return 0;
}
