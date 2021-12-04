#include <stdio.h>
#include <stdlib.h>

int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("yanlis parametre girdiniz\n");
            break;
         }
 }
 return number;
}

int main(int argc, char *inp[])
{
    int count = strtoint(inp[2]);
    for(int i=0;i<count;i++){
        printf("%s\n",inp[1]);
    }
    return 0;
}
