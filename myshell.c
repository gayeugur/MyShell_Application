#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void command(char *input,char *inp[]);

int main(int argc, char *argv[],char ** envp)
{
	char *input;
	input = (char*) malloc((100) * sizeof(char *));
	char *temp= (char*) malloc((100) * sizeof(char *));
	char *inp[4];
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
		printf("------------------------ \n");
		printf("inp[0]  --->%s\n",inp[0]);
		printf("inp[1]  --->%s\n",inp[1]);
		printf("inp[2]  --->%s\n",inp[2]);
		
		
		command(input,inp);

    }
}


void command(char *input,char *inp[]){
	if(strcmp(input,"exit")==0){
		printf("Cikis yapılıyor...\n");
		exit(0);
	}
	else if(strcmp(input,"bash")==0){
  		printf("Bash baslıyor...\n");
  		 		
  		
  	}
  	else if(strcmp(inp[0],"tekrar")==0){
  		printf("tekrar baslıyor...\n");
  		if(inp[1]==NULL || inp[2]==NULL){
  		printf("hata...\n");
  		}
  		
  		int e,f;
  		f = fork(); 
            		if(f == 0){ 
                		e = execv("tekrar",inp);
                		perror("execv failed \n");
            }
            else{
             //   wait(&e); 
            }	
  		
  	}
  	else if(strcmp(inp[0],"islem")==0){
  	int f,e;
  	printf("islem baslıyor...\n");
  	
  	f = fork(); //Fork yapıyoruz.
            if(f == 0){ //Child process ile exec fonksiyonunu çağırıyoruz.
                e = execv("islem",inp);
                perror("execv failed \n");
                
            }
            else{
                wait(&e); //Child processin işi bitene kadar ana processi bekliyoruz.
            }
  	
  	
  	
  	}
  	
  	else{
  		printf("Yanlış bir komut girdiniz \n");
  	
  	}
}









