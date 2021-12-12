#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *temp[4]; 
    temp[0] = argv[1]; //Kullanıcıdan aldığım topla/cikar değerini atadım.
    temp[1] = argv[2]; //Kullanıcıdan aldığım sayı değerlerinin birincisini atadım.
    temp[2] = argv[3]; //Kullanıcıdan aldığım sayı değerlerinin ikincisini atadım.
    temp[3]=NULL;//exec hatası almamak için son elemanı NULL olarak tanımladım.
    
    int f,e;
    f=fork();
    if(f==0){
    	e = execv(argv[0],temp);//Proses içinde topla.c veya cıkar.c yi çalıştırmak için exec kullandım 
    }else{
    	wait(&e); //Child prosesin tamamlanmasını bekledim.
    }

    
    return 0;            
} 
