/** 2016640238.c
 * originalmente funcion00.c
 */
#include <stdio.h>
#include "intervalos.h"
#define DISC00

#ifdef DISC00
/*Stub*/
void
print_intervalos_en_la_fecha(struct 
intervalos_en_la_fecha *p){
  if(p->D.cant_de_interv){
    printf("%s\t%s\n",p->D.intervPt->inicio,
           p->D.intervPt->final);
  }
}
#else
void
print_intervalos_en_la_fecha(struct 
intervalos_en_la_fecha *p){
  printf("Primer intento!\n");
  //WRITE YOUR CODE HERE
}

#endif /*DISC2016640238*/

