#include <stdio.h>
#include <stdlib.h>  /*exit(),atoi()*/

/**Imprime un entero en binario */
void print_int_bin(int);

int main(int argc,char *argv[])
{
  int intVar;
  if(argc<2){
    printf("Forma de uso %s <valor entero>\n",argv[0]);
    exit(1);
  }
  intVar=atoi(argv[1]);
  print_int_bin(intVar);
  
  return 0;
}/*end main()*/

