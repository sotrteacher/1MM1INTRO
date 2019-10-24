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
extern int anio;
/**2019.10.20 For backward compatibility, define USING_ARREGLO
 * at command in the make file.
 */ 
ostream& operator<<(ostream& out,Dia& D){
#ifdef USING_ARREGLO   
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<anio<<endl;
#else
  Calendario *Cal_Greg=new Calendario();
#ifndef NDEBUG
  printf("%s",Cal_Greg->get_day_name(D.f));
  printf(" %d ",D.f->d);
  printf(" %s ",D.f->d);
#endif 
assert(1==0);
  printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(D.f)
                              ,D.f->d
                              ,MONTH[D.f->m].c_str()
                              ,anio);
  delete Cal_Greg;
#endif /*USING_ARREGLO*/
  for(unsigned int i=0;i<D.A.size();i++){
    out<<*(D.A[i])<<endl;
  }
  return out;
}

void Dia::set_TDT(float tdt){
  TD=TDT=tdt;
}
