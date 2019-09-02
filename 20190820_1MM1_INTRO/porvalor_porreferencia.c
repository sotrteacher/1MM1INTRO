/*porvalor_porreferencia.c*/
#include <stdio.h>
#include "mostrar.h"
//void mostrar(float valor1,valor2); /*revisar en libro de Zhirkov*/
/* Hola a tod@s, como les coment\'e que lo har\'ia, revis\'e el 
 * libro Low Level Programming de Igor Zhirkov, en busca de una 
 * forma de poder declarar la lista de par\'ametros de la funci\'on
 * como se intent\'o hoy 2019.08.30, pero no encontr\'e en ese 
 * libro ninguna funci\'on en la que se declara la lista de 
 * par\'ametros de esta forma:
 * void mostrar(float valor1,valor2)
 * As\'i que tengo la impresi\'on de que al d\'ia de hoy esto no 
 * est\'a permitido en lenguaje C en ninguna versi\'on del standar 
 * de C. Pero hago \'enfasis en esto: solo "tengo la impresi\'on", 
 * por el momento no puedo asegurar que mi impresi\'on sea 100% 
 * correcta. En todo caso, si alguno de ustedes logra recompilar 
 * este archivo utilizando void mostrar(float valor1,valor2) en 
 * lugar de void mostrar(float valor1,float valor2) apreciar\'ia 
 * mucho que me avisaran para tratar de aclarar el asunto.
 * */
void mostrar(float valor1,float valor2);

/*paso de argumentos por valor*/
void intercambiar(float A,float B)
{
  float tmp;
  tmp=A;
  A=B;
  B=tmp;
  mostrar1(A,B);
}

/*paso de argumentos por referencia*/
void intercambiar1(float *A,float *B)
{
  float tmp;
  tmp=*A;
  *A=*B;
  *B=tmp;
  mostrar1(*A,*B);
}


int main(int argc,char *argv[])
{
  float x,y;
  x=1.4142;
  y=3.1416;
  printf("\nmain:\n");
  mostrar1(x,y);
  printf("\n/***********************************************/\n");
  printf("\n");
  printf("intercambiar:\n");
  intercambiar(x,y);/*paso de argumentos por valor*/
  printf("\nmain:\n");
  mostrar1(x,y);
  printf("\n/***********************************************/\n");
  printf("\n");
  printf("intercambiar1:\n");
  intercambiar1(&x,&y);/*paso de argumentos por referencia*/
  printf("\nmain:\n");
  mostrar1(x,y);
  printf("\n/***********************************************/\n");
  return 0;
}/*end main()*/

void mostrar(float valor1,float valor2)
{
  printf("%10s%10.4f%10s%10.4f",
         "valor1 =",valor1,"valor2 =",valor2);
}

void print_float(float f)
{
  printf("%10.4f",f);
}
