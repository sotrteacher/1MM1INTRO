/** ctors.c
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NDEBUG
#include <assert.h>

#include <iostream>
#include <fstream>
using namespace std;

extern unsigned int cantidad_de_reactivos_usados;
/*must point to cantidad_de_reactivos_usados unsigned int*/
extern unsigned int *reactivos_usados;
extern bool modificado;
extern char *File_Name1;
extern char REACTIVO[NUMDREAC][LONGDREAC];

/** Inicializa las variables globales 
 * File_Name1, cantidad_de_reactivos_usados, reactivos_usados, 
 * y modificado.
 */
//void run_ctor()
void run_ctor(char *file_name1)
{
  //cantidad_de_reactivos_usados=0;
  //reactivos_usados=NULL;
  string line;
  int ca=0;            /* comma amount */
  int i=0,j;
  char *token;
  char str1[512];
  char str2[512];
  unsigned int cantidad_de_indices_de_react_guardados;
  File_Name1=file_name1;
  //ifstream in(File_Name1.c_str());
  ifstream in(file_name1);
  if(in){
    getline(in,line);
    cantidad_de_reactivos_usados=atoi(&line[0]);
    if(cantidad_de_reactivos_usados){
      getline(in,line);
      for(j=0;j<line.size();j++){
        str1[j]=line[j];
      }
      str1[j]='\0';
      token=strtok(str1,",");
      while(token!=NULL){
        ca++;
        token=strtok(NULL,",");
      }
      cantidad_de_indices_de_react_guardados=ca;
      assert(cantidad_de_reactivos_usados==cantidad_de_indices_de_react_guardados);
      //TurnosAnteriores=new int[CantidadDTurnosAnteriores];
      reactivos_usados=(unsigned int *)malloc(cantidad_de_reactivos_usados*sizeof(unsigned int));
      for(j=0;j<line.size();j++){
        str2[j]=line[j];
      }
      str2[j]='\0';
      token=strtok(str2,",");
      while(token!=NULL){
        reactivos_usados[i++]=atoi(token);
        token=strtok(NULL,",");
      }
    }
    in.close();
  }
  
  modificado=false;
}/*end run_ctor(char *file_name1)*/

unsigned int init_REACTIVO()
{
  unsigned int i,j=0;
  FILE *fent;
  int car,res=0;
  char nombre_de_archivo[1024];
  
  for(i=0;i<NUMDREAC;i++){
    sprintf(nombre_de_archivo,"./reactivos/reactivo%d.txt",i+1);
#ifndef NDEBUG
    printf("Abriendo %s\n",nombre_de_archivo);
#endif
    /**Apertura del i-esimo archivo de entrada*/
    fent=fopen(nombre_de_archivo,"r");
    if(fent==NULL){
      fprintf(stderr,"Error abriendo %s\n",nombre_de_archivo);
      return i;
    }
    while((car=fgetc(fent))!=EOF){
      REACTIVO[i][j++]=car;
    }
    j=0;
    /**Cierre del i-esimo archivo*/ 
    fclose(fent);
#ifndef NDEBUG
    printf("%s\n",REACTIVO[i]);
#endif
  }/*end for()*/
  return i;
}/*end init_REACTIVO()*/

