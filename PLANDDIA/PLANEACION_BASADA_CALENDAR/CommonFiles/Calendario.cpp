#ifdef VISUAL_STUDIO_2017
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> /*malloc()*/
#define NDEBUG
#include <assert.h>
using std::string;
using std::cout;
using std::endl;
using std::vector;
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Asignacion.h"
//extern int NUMDALUMNOS;
extern int anio;
extern Calendario *Cal_Greg;   /*Calendario Gregoriano*/

/* A\~no 2019*/         /*2019.10.20*/
string ARREGLO[][7] = {
{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo"}, /*enero*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*febrero*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*marzo*/
{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*abril*/
{ "Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes" }, /*mayo*/
{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }, /*junio*/
{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*julio*/
{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*agosto*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*septiembre*/
{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo" }, /*octubre*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*noviembre*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }  /*diciembre*/
};

//#ifdef USING_ARREGLO
string MONTH[] = { "enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre" };
//#else
static char MES[][32]={"static char MES[][32]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre"
};
//#endif /*USING_ARREGLO*/

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}
int Calendario::index_delmes(string month){ 
  if(month=="enero")       return 0;
  if(month=="febrero")     return 1;
  if(month=="marzo")       return 2;
  if(month=="abril")       return 3;    
  if(month=="mayo")        return 4;
  if(month=="junio")       return 5;
  if(month=="julio")       return 6;
  if(month=="agosto")      return 7;
  if(month=="septiembre")  return 8;
  if(month=="octubre")     return 9;
  if(month=="noviembre")   return 10;
  if(month=="diciembre")   return 11;
  return -1; /*Para tratar de detectar alg\'un error*/
}/*end int Calendario::index_delmes(string month)*/

int Calendario::primera_fecha_delmes(string day,int i){
if(ARREGLO[i][0]==day) return 7;
if(ARREGLO[i][1]==day) return 1;
if(ARREGLO[i][2]==day) return 2;
if(ARREGLO[i][3]==day) return 3;
if(ARREGLO[i][4]==day) return 4;
if(ARREGLO[i][5]==day) return 5;
if(ARREGLO[i][6]==day) return 6;
return -1; /*Para tratar de detectar alg\'un error*/
}/*end int Calendario::primera_fecha_delmes(string day,int i)*/                                                 
                      
SetDIntType* Calendario::obtener_nums_ddia(string d, string m){
             SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
             int i,j; /* index de l mex es el arreglo*/
             i=index_delmes(m);
             if(i>=0 && i<12){
                     j=primera_fecha_delmes(d,i);
                     }
                     fill_SDIT(i,j,r);
                     return r; 
}
void Calendario::fill_SDIT(int i,int j,SetDIntType* r){
 int diasdmes;
 if (i==0)  diasdmes=31;
 if (i==1)  diasdmes=29;
 if (i==2)  diasdmes=31;
 if (i==3)  diasdmes=30;
 if (i==4)  diasdmes=31;
 if (i==5)  diasdmes=30;
 if (i==6)  diasdmes=31;
 if (i==7)  diasdmes=31;
 if (i==8)  diasdmes=30;
 if (i==9)  diasdmes=31;
 if (i==10) diasdmes=30;
 if (i==11) diasdmes=31;
 int cnt=0;
 for (int k=j; k<=diasdmes; k+=7)
 {
     r->intPt[cnt]=k;
     cnt++;
 }
 r->n=cnt-1;
}                                         

bool Calendario::esta_incluido(string d,vector<string> dias){
  bool ret=false;
  for(unsigned int i=0;i<dias.size();i++){
    if(d==dias[i]){
      ret=true;
      break;
    }
  }
  return ret;
}

bool Calendario::esta_incluido(Fecha* fPt,vector<Dia*> dnl){
  bool ret=false;
  for(unsigned int i=0;i<dnl.size();i++){
    if(*(dnl[i]->f)==*fPt){
      ret=true;
      break;
    }
  }
  return ret;
}

bool Calendario::esta_incluido(Fecha* fPt,vector<Fecha*> FDdnl){
  bool ret=false;
  for(unsigned int i=0;i<FDdnl.size();i++){
    if(*FDdnl[i]==*fPt){
      return true;
    }
  }
  return ret;
}

/**
 devuelve la cantidad de fechas entre fi y ff que corresponden a los 
 dias en el vector dias.
 */                                       
int Calendario::cant_dFechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  /*cantidades de dias de los meses (2016)*/
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      cnt++;
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    cnt++;
  }
  return cnt;
}

/**
 * @param fi:apuntador a fECHA iNICIAL
 * @param ff:apuntador a fECHA fINAL
 */ 
vector<Fecha*> Calendario::get_Fechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0; /*iNDICE del mES, iNDICE del dIA*/
  vector<Fecha*> vdf;
//  Calendario *Cal_Greg=new Calendario();   /*Calendario Gregoriano*/
  /** Cantidades de dias de los meses de los a\~nos:
   *  (2016--2016 fue bisiesto--,2017,2018,2019)
   */
#ifdef USING_ARREGLO
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
#else
int TamM[]={0,31,29,31,30,31,30,31,31,30,31,30,31};/*para a\~nos bisiestos*/
int Tamm[]={0,31,28,31,30,31,30,31,31,30,31,30,31};/*para a\~nos no bisiestos*/
#endif /*USING_ARREGLO*/
inic:
  if((im!=ff->m)||(id!=ff->d)){
#ifdef USING_ARREGLO
    if(esta_incluido(ARREGLO[im][id%7],dias)){
#else
    //if(esta_incluido(Cal_Greg->get_day_name(fi),dias)){
    if(esta_incluido(Cal_Greg->get_day_name(new Fecha(id,im)),dias)){
#ifndef NDEBUG
  printf("La fecha %s %d de %s de %d SI ESTA INCLUIDA!\n"
        ,Cal_Greg->get_day_name(fi)
        ,fi->d
        ,MES[fi->m]
        ,fi->a);
#endif /*NDEBUG*/
#endif /*USING_ARREGLO*/
      vdf.push_back(new Fecha(id,im));
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
#ifdef USING_ARREGLO
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
#else
    if(esta_incluido(Cal_Greg->get_day_name(ff),dias)){
#endif /*USING_ARREGLO*/
    vdf.push_back(new Fecha(ff->d,ff->m));
  }
  return vdf;
}/*end Calendario::get_Fechas()*/

/** Usando el vector de Fechas vdf y el vector de Dias no laborables 
 * dnl, construye un vector de Dias laborables (los dias de clase para 
 * los que se planificar\'an actividades) este vector de Dias laborables. 
 * @param vdf:vector de apuntadores a Fechas de los dias de la semana (VyG. 
 *            "Lunes" y "Viernes" ) que normalmente hay clase desde una 
 *            Fecha inicial hasta una Fecha final.
 * @param dnl:vector de apuntadores a Dias
 */
vector<Dia*> Calendario::get_Dias_DC(vector<Fecha*> vdf,vector<Dia*> dnl){
  vector<Dia*> vddc;
  for(unsigned int i=0;i<vdf.size();i++){
    if(!esta_incluido(vdf[i],dnl)){
      vddc.push_back(new Dia(vdf[i]));
    }
  }
  return vddc;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT){
  /*i para recorrer los dias y j para recorrer las actividades*/
  int i=0,j=0;
  assert(DIA[i]!=NULL);
  assert(ACT[j]!=NULL);
#ifndef NDEBUG
  printf("void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT)\n");
#ifndef USING_ARREGLO
  printf("i=%3d j=%3d: %s %d/%s/%d DIA[i]->TD=%5.2f ACT[j]->TR=%5.2f\n",
         i,j,Cal_Greg->get_day_name(DIA[i]->f),DIA[i]->f->d,MES[DIA[i]->f->m],
         DIA[i]->f->a,DIA[i]->TD,ACT[j]->TR);
#endif /*USING_ARREGLO*/
#endif /*NDEBUG*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
#ifndef NDEBUG
  printf("i=%3d j=%3d: DIA[i]->TD=%5.2f ACT[j]->TR=%5.2f\n",
         i,j,DIA[i]->TD,ACT[j]->TR);
#endif /*NDEBUG*/
    DIA[i]->TD-=ACT[j]->TR;
	if(ACT[j]->TR>0)
      DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR));
    j++;
	/** 2018.08.20*/
	if (DIA[i]->TD < 0.01) { DIA[i]->TD = 0; }
	/** */
    if(DIA[i]->TD==0)
      i++;
  }else{
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD));
    ACT[j]->TR-=DIA[i]->TD;
	/** 2018.08.20*/
	if (ACT[j]->TR < 0.01) { ACT[j]->TR = 0; }
	/** */
    i++;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}//end void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT)

//
//void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT,vector<Alumno*> Alum){
//  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
//  int k=0,nda;/*en nda el constructor de Asignacion colocara cuantas Asignaciones van.*/
//inicio:
//  if(ACT[j]->TR<=DIA[i]->TD){
//  	
//    DIA[i]->TD-=ACT[j]->TR;
//    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR,Alum[k],&nda));
//    j++;
//    if(DIA[i]->TD==0)
//      i++;
//  }else{
//    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD,Alum[k],&nda));
//    ACT[j]->TR-=DIA[i]->TD;
//    i++;
//  }
//  if(nda>=3){
//    k=(k+1)%NUMDALUMNOS;
//  }
//  if( !( (i==DIA.size())||(j==ACT.size()) ) )
//    goto inicio;
//}
//*/

/** Devuelve el nombre del dia ("lunes","martes","mi\\'ercoles",
 * "jueves","viernes","s\\'abado","domingo") correspondiente a la 
 * fecha a la que apunta f_Pt.
 * X=D+M+A+(1/4)A+S
 * D:es el n\'umero del d\'ia de la fecha
 * M:es el c\'odigo del mes
 * A:es el n\'umero del a\~no (dos d\'igitos)
 * (1/4)A: es la cuarta parte del a\~no (divisi\'on entera)
 * S:es el c\'odigo del siglo
 */ 
#ifdef USAR_STRING
static std::string day_name[]={
#else
static char day_name[][32]={
#endif
"Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado"
};
int Month_Code[]={
/*enero*/      0,
/*febrero*/    3,
/*marzo*/      3,
/*abril*/      6,
/*mayo*/       1,
/*junio*/      4,
/*julio*/      6,
/*agosto*/     2,
/*septiembre*/ 5,
/*octubre*/    0,
/*noviembre*/  3,
/*diciembre*/  5
};
//int Century_Code[]={
/*1600 - 1699:6,*/ 
/*1700 - 1799:4,*/ 
/*1800 - 1899:2,*/ 
/*1900 - 1999:0,*/ 
/*2000 - 2099:6, se repiten cada 400 a\~nos*/ 
//};
int Century_Code(int year)
{
  if((year>=1600)&&(year<=1699)){
    return 6;
  }else if((year>=1700)&&(year<=1799)){
    return 4;
  }else if((year>=1800)&&(year<=1899)){
    return 2;
  }else if((year>=1900)&&(year<=1999)){
    return 0;
  }else if((year>=2000)&&(year<=2099)){
    return 6;  /*se repiten cada 400 a\~nos*/ 
  }
}/*end Century_Code()*/

#ifdef USAR_STRING
std::string 
#else
char *
#endif
Calendario::get_day_name(Fecha *f_Pt)
{
#ifdef USAR_STRING
  std::string result=string(day_name[0]);
#else
  char *result=day_name[0];
#endif
  int X,/*n\'umero a calcular*/
      D,/*n\'umero del d\'ia de la fecha*/
      M,/*c\'odigo del mes*/
      A,/*n\'umero del a\~no (dos d\'igitos)*/
      /*(1/4)A, cuarta parte del a\~no (divisi\'on entera)*/
      S;/*c\'odigo del siglo*/
  f_Pt->a=anio;
  D=f_Pt->d;
  M=Month_Code[f_Pt->m-1];
  A=f_Pt->a%100;
  S=Century_Code(f_Pt->a);
  X=D+M+A+A/4+S;
  X=X%7;
  result=day_name[X];
  return result;
}


