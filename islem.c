#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int e;
    char *temp[3]; 
    temp[0] = argv[2]; //Kullanıcıdan aldığım sayı değerlerinin birincisini atadım.
    temp[1] = argv[3]; //Kullanıcıdan aldığım sayı değerlerinin ikincisini atadım.
    temp[2] = NULL; //exec hatası almamak için son elemanı NULL olarak tanımladım.
    
    e = execv(argv[1],temp);//Proses içinde topla.c veya cıkar.c yi çalıştırmak için exec kullandım 
    return 0;            //aldığım parametre topla veya cıkar olmasına göre topla.c yi ya da cıkar.c yi çalıştırdım
} 
