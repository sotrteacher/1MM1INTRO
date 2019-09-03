#include <stdio.h>

void print_int_bin(int var)
{
  int tam=sizeof(int),i;
  for(i=8*tam-1;i>=0;i--){
    printf("%d",(var>>i)&0x1);
  }
}

