#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void command(char *input,char *inp[]);
int len(char **input);
int main(int argc, char *argv[],char ** envp)
{
	char *input;
	input = (char*) malloc((100) * sizeof(char *));
	char *temp= (char*) malloc((100) * sizeof(char *));
	char *inp[4];
	char *devide=(char*) malloc((100) * sizeof(char *));;
	int i=0;
	while(1){
		printf("myshell>>");
		gets(input,100,stdin);
		
		temp =strtok(input, " ");
 		while (temp != NULL) {
        	printf("%s \n", temp);
    		inp[i]=temp;
        	temp = strtok(NULL," ");
        	i++;
		inp[4]=NULL;
    		}
    		/*	
		printf("------------------------ \n");
		printf("inp[0]  --->%s\n",inp[0]);
		printf("inp[1]  --->%s\n",inp[1]);
		printf("inp[2]  --->%s\n",inp[2]);
		printf("inp[3]  --->%s\n",inp[3]);
		printf("inp[4]  --->%s\n",inp[4]);
		
		if(len(input)>4){
		int count=0;
		while(strcmp(inp[count],"|")==-1){
			printf("inp[&d]  --->%s\n",count,inp[count]);
		}
		}	
    		printf("------------------------ \n");
		printf("devide[0]  --->%s\n",devide[0]);
		printf("devide[1]  --->%s\n",devide[1]);
		printf("devide[2]  --->%s\n",devide[2]);
		printf("devide[3]  --->%s\n",devide[3]);
		printf("devide[4]  --->%s\n",devide[4]);
		
		
		printf("| var");
			for(int j=0; j<len(inp); j++){
			printf("%d \n",j);
				printf("inp[%d]  --->---%s---\n",j,inp[j]);
				if(strcmp(inp[j],"|")==0){
				printf("| bulundu");
				}
			}
		}	*/
	
		
		command(input,inp);

    
}
}
int len(char **input){
    int size = 0;
    while(input[size]!=NULL){
        size++;
    }
    return size+1;
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




