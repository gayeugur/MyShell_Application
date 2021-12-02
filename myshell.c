#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void command(char *temp,char *input,int index);
void tekrar(char *temp);
int parametreleriParcala(char *input,char *temp);
int length(char* input);

int main(int argc, char *argv[],char ** envp)
{
	int index=0;
	while(1){
	printf("myshell>>");
	char *input;
	input = (char*) malloc((100) * sizeof(char *));
	 char *temp;
  	temp = (char*) malloc((100) * sizeof(char *)); 
    	gets(input,100,stdin);
	printf("%s",input);
	index=index+length(input);
	printf("%d",index);
	command(temp,input,index);
	}
    return 0;  
}

void command(char *temp,char *input,int index){
  
	if(strcmp(input,"exit")==0){
		printf("Cikis yapılıyor...\n");
		exit(0);
	}
  	else if(strcmp(input,"bash")==0){
  		printf("Bash baslıyor...\n");
  	}
  	else if(strcmp(input,"tekrar")==0){
  		printf("tekrar baslıyor...\n");
  		
  		parametreleriParcala(input,temp);	
  		if(strcmp(temp[0],"tekrar")==0){
  			tekrar(temp);
  		}
  	}else{
  		printf("Yanlıs komut yazdınız...\n");
  	
  	}
}
int parametreleriParcala(char *input,char *temp){
 	temp =strtok(input, " ");
 	while (temp != NULL) {
        	printf("%s", temp);
        	temp = strtok(NULL, " ");
    }
	return 0;
}



int length(char* input){
	int i = 0;
    	while(input[i] != '\0'){
     		i++;
     	}
    	return i;
}

void tekrar(char *temp){
	int f,e,status;
	f=fork();
	printf("a");
	if(temp[0] || temp[1]){
		printf("hatalı giriş yapıldı");
	}else{
	printf("b");
		if(f==0){
			e=execve("tekrar",temp,NULL);
		}else if(f<0){
			printf("error");
		}else{
			status = wait(&status);
		}
	}

}











