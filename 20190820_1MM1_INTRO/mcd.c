/*mcd.c*/
#include <stdlib.h>/*abs()*/
#include <stdio.h>

static int mcd(int n,int d)
{
  int N,D,R;
  N=abs(n);D=abs(d);
  while((R=D%N)!=0){
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
    D=N;
    N=R;
  }
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
  return N;
}

/**Simplifica la fracci\'on con numerador
 * frac[0] y denominador frac[1]
 */ 
void simplificar(int frac[2]) 
{
  int intMCD=mcd(frac[0],frac[1]);
  frac[0]=frac[0]/intMCD;
  frac[1]=frac[1]/intMCD; 
}

