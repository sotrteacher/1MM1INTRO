/*main.c*/
#include <stdio.h>

int num,den;
int mcd(int,int);

int main(void){
  int result=printf("mcd(32,132)=%d\n",mcd(32,132));
  printf("mcd(8,64)=%d\n",mcd(8,64));
  printf("mcd(65,2048)=%d\n",mcd(65,2048));
  return result;
}/*end main()*/

