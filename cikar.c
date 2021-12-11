#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num1 = atoi(argv[0]); //Kullanıcıdan alınan değeri int çevirerek sayı değerinin birincisini num1 e atadım.
    int num2 = atoi(argv[1]); //Kullanıcıdan alınan değeri int çevirerek sayı değerinin ikincisini num2 e atadım.
    int minus = num1-num2; //Aldığım sayıların farkını minus değişkenine atadım.
    printf("%d - %d = %d \n",num1,num2,minus); //Yazdırma işlemini gerçekleştirdim.
    return 0;
}
