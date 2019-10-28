#ifdef VISUAL_STUDIO_2017
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#define NDEBUG
#include <assert.h>
/*
using std::string;
using std::ostream;
using std::vector;
using std::endl;
*/
using namespace std;
#include "Fecha.h"
#include "Dia.h"
#include "Asignacion.h"
#include "Calendario.h"         /*2019.10.20*/
extern string ARREGLO[][7];
extern string MONTH[];
extern char MES[][32];
extern int anio;
/**2019.10.20 If it is necessary, for backward compatibility, 
 * define USING_ARREGLO at command in the make file.
 */ 
ostream& operator<<(ostream& out,Dia& D){
#ifdef USING_ARREGLO   
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<anio<<endl;
#else
  Calendario *Cal_Greg=new Calendario();
#ifndef NDEBUG
//  printf("%s: \n",__FILE__);
//assert(1==0);
//  cout<<__FILE__<<": "<<__LINE__+1<<":";
  printf("%s, line %d:D.f->d=%d, D.f->m=%d, D.f->a=%d\n",
         __FILE__,__LINE__,D.f->d,D.f->m,D.f->a);
  printf("\n%s, line %d, %s\n",__FILE__,__LINE__,Cal_Greg->get_day_name(D.f));
assert((D.f->m>=1)&&(D.f->m<=12));
assert((D.f->d>=1)&&(D.f->d<=31));
#endif /*NDEBUG*/
  printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(D.f)
                              ,D.f->d
                              ,MES[D.f->m]
                              ,anio);
  delete Cal_Greg;
#endif /*USING_ARREGLO*/
  for(unsigned int i=0;i<D.A.size();i++){
    out<<*(D.A[i])<<endl;
  }
//assert(1==0);
  return out;
}/*end ostream& operator<<(ostream& out,Dia& D)*/

void Dia::set_TDT(float tdt){
  TD=TDT=tdt;
}
