#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num1 = atoi(argv[0]);//Kullanıcıdan alınan değeri int çevirerek sayı değerinin birincisini num1 e atadım.
    int num2 = atoi(argv[1]);//Kullanıcıdan alınan değeri int çevirerek sayı değerinin ikincisini num2 ye atadım.
    int sum = num1+num2;//Aldığım sayıların toplamını sum değişkenine atadım.
    printf("%d + %d = %d \n",num1,num2,sum);//Yazdırma işlemini gerçekleştirdim.
    return 0;
}
