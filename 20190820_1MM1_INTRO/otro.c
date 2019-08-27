/*otro.c*/
//#include <math.h> 
#include <stdio.h> /*printf()*/
#include <stdlib.h>/*abs()*/
/*#define PRELIMINAR*/

/** Obtiene el m.c.d. de una fracci\'on propia
 * en la que
 * @param n: es el numerador y
 * @param d: es el denominador.*/
int mcd(int n,int d)
{
  int N,D,R;
  N=abs(n);
  D=abs(d);
  R=D%N;
  if(!R) return N;
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
  D=N;
  N=R;
  R=D%N;
  if(!R) goto fin;
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
  D=N;
  N=R;
  R=D%N;
  if(!R) goto fin;
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
  D=N;
  N=R;
  R=D%N;
  if(!R) goto fin;
#ifdef PRELIMINAR
  printf("%d = %d(%d)+%d\n",D,D/N,N,R);
#endif /*PRELIMINAR*/
fin:
  return N;
}

