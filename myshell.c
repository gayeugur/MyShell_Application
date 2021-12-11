#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void command(char *input,char *inp[]);

int main(int argc, char *argv[],char ** envp){
while(1){
	char *input = (char*) malloc((100) * sizeof(char *)); //input dizisi için bellekten yer ayrımı yaptım.
	char *temp = (char*) malloc((100) * sizeof(char *));//temp dizisi için bellekten yer ayrımı yaptım.
	char **inp = ((char **) malloc (100*sizeof(char**)));//inp iki boyutlu dizisi için de malloc kullandım.
	int i=0, size=0; //Değişken tanımlamalarını yaptım.
		printf("myshell>>");
		gets(input,100,stdin); //Kullanıcıdan input aldım.
		
		temp =strtok(input, " "); //Aldığım inputu boşluklara göre böldüm.
 		while (temp != NULL) { //Temp değeri Null değilse aldığım inputu parçalayarak inp çift boyutlu matrise atadım.
    			inp[i]=temp;
        		temp = strtok(NULL," "); //While da devam edeceği için boşluğa göre parçalama işlemine devam ettim.
        		i++; //indexi arttırdım.
			size++; //Değişken uzunluğunu belirleyeceğim için her bölmede size'ı arttırdım.
    		}
    		inp[size]=NULL; //exec hatası almamak için son elemana NULL değerini atadım.
		//pipe(inp);	
		if(size<5){ //alınan input size 5 den küçükse command fonksiyonunu aldığım
			command(input,inp); //inp ile fonksiyonu çağırdım.
		}
		else{ //inputun size ı 5 den büyükse ya da eşitse
			int operator=0; 
			for(int i=0; i<size; i++){ //İnput uzunluğu kadar tüm elemanları dönerek
				if(strcmp(inp[i],"|")==0){ //her bir elemanın | elemanına eşit olup olmadığını kontrol ettim
					operator=i; //Bulduğum indexi operator değişkenine atadım.
				}
			}
			char * first[operator]; //operator buyukluğunde dizi tanımladım 
			for(int j=0; j<operator; j++){ //Her bir elemanı yukarıda tanımlamış olduğum 
				first[j]=inp[j]; //first matrisine atadım.
			}
			first[operator]=NULL;  //exec hatası almamak için son elemana NULL değerini atadım.
			command(input,first);//Oluşturduğum first matrisiyle fonksiyonu çağırdım.
		
			char *second[size-operator]; // | sonraki elemanları alabilmek için bir değişken tanımladım.
			int c=0;
			for(int j=operator+1; j<size; j++){ //operatorden sonraki elemandan baslayarak sırasıyla tum elemanları
				second[c]=inp[j]; //second değişkenine atadım.
				c++;
			}
			if(strcmp(second[0],"tekrar")==0){ //Eğer bu değişkenin ilk parametresi tekrar ise 
				second[3]=NULL; //4.elemanına NULL değerini atadım.
			}
			second[size-operator]=NULL;//exec hatası almamak için son elemana NULL değerini atadım.
			command(input,second); //Oluşturduğum second matrisiyle fonksiyonu çağırdım.
		}
	free(input); //Her bir input alımında dizinin üstüne yazılmaması için diziyi boşalttım.
   }
}

void command(char *input,char *inp[]){
	if(strcmp(input,"exit")==0){ //Alınan input değeri exit ise program sonlandırılır.
		exit(0);
	}
	else if(strcmp(input,"bash")==0){//Alınan input değeri bash ise bash program çalışır.
  		system("/bin/bash");
  					 		
  		
  	}
  	else if(strcmp(inp[0],"cat")==0){//Alınan input değeri cat ise formata uygun yazdırma işlemi yapılır.
  		printf("cat:%s\n",inp[1]);
  	}
  	else if(strcmp(inp[0],"tekrar")==0){ //Alınan input değeri tekrar ise tekrar program çalışır.
  		if(inp[1]==NULL || inp[2]==NULL || inp[3] !=NULL){ //Alınan input değerinin 1.veya 2.parametresi null ise 
  			printf("Yanlış bir komut girdiniz \n"); //veya 3.parametresi Null değilse parametre hatası meydana gelir.
  		}else{
  			int e,f; //fork ve execte kullanacağım değişkenleri tanımladım.
  			f = fork(); //Çalışan processin kopyasını oluşturmak için fork işlemini gerçekleştirdim.
            		if(f == 0){  //Child proses ise
                		e = execv("tekrar",inp); //Ayrı programı çalıştırmak için execv kullandım.
                		perror("execv failed \n");
            		}	
  		}
  	}
  	else if(strcmp(inp[0],"islem")==0){//Alınan input değeri islem ise;
  		int f,e;
  		f = fork(); //Yukarıdakine benzer amaçla fork gerçekleştirdim.
            	if(f == 0){ //Child proseste ise islem.c yi çalıştırabilmek için gerekli 
                	e = execv("islem",inp); //parametreleri verdim.
                	perror("execv failed \n");
            	}else{
                	wait(&e); //Execv işleminin bitmesini beklemek için wait komutunu ekledim.
            	}  	
  	}
  	else if(strcmp(inp[0],"ls")==0){//Alınan input değeri ls ise 
    		system("/bin/ls");// sistemde geçerli olan ls komutunu çağırdım.
   	}
  	else if (strcmp(inp[0],"clear")==0){ //Alınan input değeri clear ise 
        	system("clear"); //sistemdeki clear komutunu çağırdım.
    	}
  	else{ //Yanlış veya hatalı komut girildiğinde ise bu bilgiyi yazdırdım.
  		printf("Yanlış bir komut girdiniz \n");
  	}
}
