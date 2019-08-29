/*main.c*/
#include <stdio.h>

int num,den;
int mcd(int,int);
void simplificar(int f[2]);

int main(void){
  int result=printf("mcd(32,132)=%d\n",mcd(32,132));
  printf("mcd(8,64)=%d\n",mcd(8,64));
  printf("mcd(65,2048)=%d\n",mcd(65,2048));

  int m=mcd(32,132);
  int arr[]={32,132};
  simplificar(arr);
  printf("32/132=%d/%d\n",arr[0],arr[1]);
  return result;
}/*end main()*/

