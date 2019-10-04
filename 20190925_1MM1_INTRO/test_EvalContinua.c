/** test_EvalContinua.c - Selecciona pseudoaleatoriamente
 * un reactivo de un banco de reactivos.
 */ 
#include <stdio.h>
#include <stdlib.h>
#define NDEBUG
#include <assert.h>
extern bool modificado;

int main(int argc,char *argv[])
{
  unsigned int indice_de_reactivo,reactivo_index,ret;
  if(argc<2){
    printf("FORMA DE USO:%s <file_index_reactivos_intro>\n",
            argv[0]);
    exit(1);
  }
void run_ctor(char *);
  run_ctor(argv[1]);
unsigned int init_REACTIVO();
   if((ret=init_REACTIVO())==NUMDREAC){
unsigned int siguiente_turno();
     if((reactivo_index=siguiente_turno())>0){
#ifndef NDEBUG
       printf("reactivo_index=%u\n",reactivo_index);
#endif
       indice_de_reactivo=reactivo_index-1;
int show_reactivo(unsigned int);
       show_reactivo(indice_de_reactivo);
void save_reactivos_asignados(unsigned int);
       if(modificado){
         save_reactivos_asignados(reactivo_index);
       }
     }else{ 
       printf("Reactivos YA asignados ...\n");
       return 0;
     }
   }else{
#ifndef NDEBUG
     printf("ret=%u\n",ret);
#endif
     return -1;
   }
}/*end main()*/

