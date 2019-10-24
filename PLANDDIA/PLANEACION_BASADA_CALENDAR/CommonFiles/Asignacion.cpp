//Asignacion.cpp
#ifdef VISUAL_STUDIO_2017
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <ostream>
#include <vector>
#include <string>
/**
using std::endl;
using std::ostream;
using std::string;
using std::vector;
*/
using namespace std;
#include "Asignacion.h"
#include "Actividad.h"
#include "Alumno.h"
int Asignacion::NDA=0;
ostream& operator<<(ostream& out,Asignacion& a){
  out<<"\t"<<a.TA<<"h\t[Tema "<<a.Act->nombre<<"]"<<endl;
//  2019.10.14.08.42
//  for(unsigned int i=0;i<a.AR.size();i++)
//    out<<"\t\t"<<*(a.AR[i])<<endl;
  return out;
}
