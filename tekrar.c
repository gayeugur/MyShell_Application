#include<stdio.h>

#include<stdlib.h>

int isParameterDigit(char * inp);

int main(int argc, char * arguments[]) {
  int i;

  if (isParameterDigit(arguments[1]) == 0) { 
    printf(
  } else {
    for (i = 0; i < atoi(arguments[1]); i++) {
      printf("%s", arguments[0]);
      printf("\n");
    }
  }
  return 0;

}

int isParameterDigit(char * inp) {

  int index = 0;

  while (inp[index] != '\0') {
    if (isdigit(inp[index]) == 0) { 
      return 0;
      break;
    }
    index++;
  }
  return 1;
}
