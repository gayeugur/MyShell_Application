#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void command(char *input,char *inp[]);

int main(int argc, char *argv[],char ** envp)
{
	char *input;
	input = (char*) malloc((100) * sizeof(char *));
	char *temp= (char*) malloc((100) * sizeof(char *));
	char **inp=((char **) malloc (100*sizeof(char**)));
	char *devide=(char*) malloc((100) * sizeof(char *));;
	int i=0, uzunluk=0,size=0;
	while(1){
		printf("myshell>>");
		gets(input,100,stdin);
		
		temp =strtok(input, " ");
 		while (temp != NULL) {
        	printf("%s \n", temp);
    		inp[i]=temp;
        	temp = strtok(NULL," ");
        	i++;
		size++;
    		}
    		printf("%d -- : \n",size);
    		inp[size]=NULL;
    		
    		printf("------------------------ \n");
		printf("inp[0]  --->%s\n",inp[0]);
		printf("inp[1]  --->%s\n",inp[1]);
		printf("inp[2]  --->%s\n",inp[2]);
		printf("inp[3]  --->%s\n",inp[3]);
		printf("inp[4]  --->%s\n",inp[4]);
		printf("inp[5]  --->%s\n",inp[5]);
		printf("inp[6]  --->%s\n",inp[6]);
		printf("%d: \n " ,len(input));
	if(size<5){
		char * dizi[5];
		for(int i=0; i<5; i++){
			dizi[i]=inp[i];
		}
		dizi[5]=NULL;
		command(input,inp);
	//command dizi ile çağrılır
	}
	else{
	int bol=0;
		for(int i=0; i<size; i++){
			if(strcmp(inp[i],"|")==0){
				bol=i;
				printf("bol: %d",bol);
			}
		}
		char * first[bol];
		for(int j=0; j<bol; j++){
		first[j]=inp[j];
		
		}
		first[bol]=NULL;
		command(input,first);
		printf("first[0]  --->%s\n",first[0]);
		printf("first[1]  --->%s\n",first[1]);
		printf("first[2]  --->%s\n",first[2]);
		
		char *second[size-bol];
		int c=0;
		for(int j=bol+1; j<size; j++){
			second[c]=inp[j];
			c++;
		
		}
		second[size-bol]=NULL;
		printf("second[0]  --->%s\n",second[0]);
		printf("second[1]  --->%s\n",second[1]);
		printf("second[2]  --->%s\n",second[2]);
		printf("second[3]  --->%s\n",second[3]);
		command(input,second);
	}
}
}
	

void command(char *input,char *inp[]){
	if(strcmp(input,"exit")==0){
		printf("Cikis yapılıyor...\n");
		exit(0);
	}
	else if(strcmp(input,"bash")==0){
  		printf("Bash baslıyor...\n");
  		system("/bin/bash");
  					 		
  		
  	}
  	else if(strcmp(inp[0],"cat")==0){
  		printf("cat:%s\n",inp[1]);
  	}
  	else if(strcmp(inp[0],"tekrar")==0){
  		printf("tekrar baslıyor...\n");
  		/*if(inp[1]==NULL || inp[2]==NULL){
  			printf("hata\n");
  		}*/
  		int e,f;
  		f = fork(); 
            		if(f == 0){ 
                		e = execv("tekrar",inp);
                		perror("execv failed \n");
            }
            else{
                wait(&e); 
            }	
  		
  	}
  	else if(strcmp(inp[0],"islem")==0){
  	int f,e;
  	printf("islem baslıyor...\n");
  	
  	f = fork(); 
            if(f == 0){ 
                e = execv("islem",inp);
                perror("execv failed \n");
                
            }
            else{
                wait(&e); 
            }
  	
  	
  	
  	}
  	else if(strcmp(inp[0],"ls")==0){
        
    	   system("/bin/ls");
        
    }
  	else if (strcmp(inp[0],"clear")==0){ 
        system("clear");
    }
  	
  	else{
  		printf("Yanlış bir komut girdiniz \n");
  	
  	}
}





