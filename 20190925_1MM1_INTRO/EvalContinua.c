#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

/*extern const unsigned int NUMDREAC;*/           /*NUMero De REACtivos*/
/*extern const unsigned int LONGDREAC;*/          /*LONGitud De REACTivo*/
const unsigned int NUMDREAC=52;           /*NUMero De REACtivos*/
const unsigned int LONGDREAC=2048;          /*LONGitud De REACTivo*/
extern char REACTIVO[NUMDREAC][LONGDREAC];
extern unsigned int cantidad_de_reactivos_usados;
/*must point to cantidad_de_reactivos_usados unsigned int*/
extern unsigned int *reactivos_usados;
extern bool modificado;
extern unsigned int reactivo_en_turno;

int show_reactivo(unsigned int index)
{
  if((index>=0)&&(index<NUMDREAC)){
    printf("%s\n",REACTIVO[index]);
  }else{
    return -1;
  }
  return 0;
}/*end show_reactivo(unsigned int index)*/

unsigned int siguiente_turno(){
  int candidato_a_ser_reactivo_en_turno;
  if(cantidad_de_reactivos_usados==NUMDREAC){
    modificado=false;
    return -1;
  }
  if((NUMDREAC-cantidad_de_reactivos_usados)==1){
unsigned int usar_NUMDREAC_buckets();
    candidato_a_ser_reactivo_en_turno=usar_NUMDREAC_buckets();
    goto actualizacion;
  }
  if(cantidad_de_reactivos_usados<NUMDREAC){
    srand(time(NULL));
    candidato_a_ser_reactivo_en_turno=1+rand()%NUMDREAC;
bool asignado(unsigned int);
    while(asignado(candidato_a_ser_reactivo_en_turno)){
      candidato_a_ser_reactivo_en_turno=1+rand()%NUMDREAC;
    }
    reactivo_en_turno=candidato_a_ser_reactivo_en_turno;
    assert(reactivo_en_turno<=NUMDREAC);
actualizacion:
void actualizar_reactivos_usados(unsigned int);
    actualizar_reactivos_usados(reactivo_en_turno);
  }
  return reactivo_en_turno;
}/*end siguiente_turno()*/

unsigned int usar_NUMDREAC_buckets()
{
  char bucket[NUMDREAC+1]={0};        /* buckets o cubetas a utilizar */
  int i;
  for(i=0;i<cantidad_de_reactivos_usados;i++){
    bucket[reactivos_usados[i]]=1;
  }
  for(i=1;i<NUMDREAC;i++){
    if(bucket[i]==0){
      return i;
    }
  }
  return -1;
}

void actualizar_reactivos_usados(unsigned int reactivo_en_uso)
{
  unsigned int i,*tmp=(unsigned int *)malloc(cantidad_de_reactivos_usados*sizeof(unsigned int));
  for(i=0;i<cantidad_de_reactivos_usados;i++){
    *(tmp+i)=reactivos_usados[i];
  }
  reactivos_usados=(unsigned int *)malloc(
                   (cantidad_de_reactivos_usados+1)*sizeof(unsigned int));
  for(i=0;i<cantidad_de_reactivos_usados;i++){
    reactivos_usados[i]=*(tmp+i);
  }
  reactivos_usados[cantidad_de_reactivos_usados]=reactivo_en_uso;
  cantidad_de_reactivos_usados++;
  modificado=true;
}

/** Devuelve true si candidato est\'a entre los reactivos usados.
 *  y devuelve false en caso contrario.
 *  @param candidato:debe ser un candidato_a_ser_reactivo_en_turno.
 */ 
bool asignado(unsigned int candidato)
{
  unsigned int i;
  for(i=0;i<cantidad_de_reactivos_usados;i++){
    if(*(reactivos_usados+i)==candidato){
      return true;
    }
  }
  return false;
}/*end bool asignado(unsigned int)*/

