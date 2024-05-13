#include"huffman.c"
int main(int argc,char* argv[])
{ 
    int *map=malloc(sizeof(int)*255);
    unsigned char size=255;
    int n=0;
    FILE* fileToRead;
    FILE * fileToWrite ;
    char* strI=malloc(sizeof(char)*30);
    char* strO=malloc(sizeof(char)*30);    
    strcpy(strO,"compressed.dat");
    if(argc>2){
        strcpy(strO,argv[2]);
        strcpy(strI,argv[1]);
    }
    else if(argc>1){
        strcpy(strI,argv[1]);
    }
    else{
        printf("Enter Full File Name: \n");
        scanf("%s",strI);
    }
    fileToRead = fopen(strI,"r");
    fileToWrite = fopen(strO,"wb");
    if(fileToRead == NULL){
        printf("Failed To Open File\n");
        exit(0);
    }
    if(fileToWrite == NULL){
        printf("Failed To Open File\n");
        exit(0);
    }
    int ch;
    while(1){
        ch=fgetc(fileToRead);
        if(ch<0)break;
        map[ch]++;
    }
    for(int i=0;i<size;i++){
        if(map[i]!=0){
            n++;
        }
    }
    fclose(fileToRead);
    fileToRead= NULL;
    // creating array of 
    node* sta;
	sta=malloc(n*sizeof(node));
	
    int i=0,k=0;

	// this will create node for every element in map;
    while(i<size){
        if(map[i]!=0){
            createNode(sta+k,i,map[i]);
            k++;
        }
        i++;
    }
    
    //Creating tree from above structure array
    CreateTree(sta,n);
    asciicode* codeArray = malloc(sizeof(asciicode)*n); 
    generateCodes(sta,codeArray,0,0);
    asciiCodeSort(codeArray,n); 
    fileToRead=fopen(strI,"r");
    unsigned char wrt=n;
    fwrite(&wrt,sizeof(wrt),1,fileToWrite);
    storeTree(fileToWrite,sta);
    int code=0;
    char bytesize= 8;
    size=0;
    while(1){
        ch=fgetc(fileToRead);
        if(ch==EOF)break;
        searchAndReturnCode(codeArray,n,(unsigned char)ch,&code,&size);
        while(size>0){
            if(size <= bytesize){
                bytesize = bytesize - size;
                wrt = (wrt << size) | ((255 >> bytesize) & (char) code);
                size = 0;
            }
            else{
                wrt = (wrt << bytesize) | (code >> (size - bytesize));
                size = size - bytesize;
                bytesize = 0;
            }
            if(bytesize == 0){
                fwrite(&wrt,sizeof(wrt),1,fileToWrite);
                wrt = 0;
                bytesize = 8;
            }
        }
    }
    if(bytesize != 8){
        wrt = wrt << bytesize;
        fwrite(&wrt,sizeof(wrt),1,fileToWrite);
    }
    fclose(fileToRead);
    fclose(fileToWrite);
    printf("Done!\n");
    return 0;
}
