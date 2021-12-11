#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *inp[]){
    int num = atoi(inp[2]); //Kullanıcıdan aldığım adet parametresini int çevirerek num değişkenine atadım.
    for(int i=0; i<num; i++){ //Num adeti kadar dönerek kaç kez yazdırılması isteniyorsa printf ile inp[1]
        printf("%s \n",inp[1]); //olan değeri yazdırdım (tekrar fatih 3 durumunda yazdırılmak istenen değer fatih)
    }
    return 0;
}
