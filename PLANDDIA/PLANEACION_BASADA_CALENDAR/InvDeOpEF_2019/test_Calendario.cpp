/** test_Calendario.cpp
 */ 
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
//#define NDEBUG
#include <assert.h>
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
int anio = 2019;
Calendario *Cal_Greg;   /*Calendario Gregoriano*/

/** 2019.10.20 for backward compatibility, define USING_ARREGLO:
 * see the lines
 * extern string ARREGLO[][7];  (*in file ../CommonFiles/Dia.cpp*) 
 * extern string MONTH[];       (*in file ../CommonFiles/Dia.cpp*) 
 * and the definitions of string ARREGLO[][7] and string MONTH[]
 * at the file InVDOps_AD2019.cpp
 * 2019.10.20 For backward compatibility, define USING_ARREGLO
 * at command in the make file (for a potential new target made in 
 * this same file.
 */
#ifdef USING_ARREGLO   
string MONTH[] = { "string MONTH[]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre" };
#endif /*USING_ARREGLO*/
static char MES[][32]={"static char MES[][32]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre"
};

int main(int argc,char *argv[])
{
  Cal_Greg=new Calendario();    /*Calendario Gregoriano*/
#ifndef NDEBUG
  Fecha f(1,12,2019); /* 1 de diciembre de 2019 */
  printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(&f)
                              ,f.d
                              ,MES[f.m]
                              ,2019);
  int i;
  for(i=1;i<=31;i++){
    f.d=i;
    printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(&f)
                                     ,f.d
                                     ,MES[f.m]
                                     ,2019);
  }
#endif /*NDEBUG*/

  Calendario *Cal2019 = new Calendario(2019);
#ifndef CAL_GREGORIANO
  Fecha f1(16, 8); /*Lunes 16 de septiembre de 2019 */
  Fecha f2(20, 11); /*Viernes 20 de diciembre de 2019 */
#else
  Fecha f1(16, 9); /*Lunes 16 de septiembre de 2019 */
  Fecha f2(20, 12); /*Viernes 20 de diciembre de 2019 */
#endif /*CAL_GREGORIANO*/
  /*vector de dias de la semana en que hay clases de la UA correspondiente*/
  vector<string> vdd;   
  /*Se indican los d\'ias de la semana que hay clases*/
  vdd.push_back("Lunes");
  vdd.push_back("Viernes");
  /*vector con las Fechas entre f1 y f2 correspondientes a 
   los dias en el vector vdd */
  vector<Fecha*> VDF = Cal2019->get_Fechas(&f1, &f2, vdd); 
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
#ifndef CAL_GREGORIANO
  vdnl.push_back(new Dia(new Fecha(1,10))); /*Viernes 1 de noviembre de 2019*/
  vdnl.push_back(new Dia(new Fecha(18,10)));  /*Lunes 19 de noviembre de 2019*/
  vdnl.push_back(new Dia(new Fecha(12,11)));  /*Jueves 12 de diciembre de 2019*/
#else
  vdnl.push_back(new Dia(new Fecha(16,9)));   /*Lunes 16 de septiembre de 2019*/
  vdnl.push_back(new Dia(new Fecha(1,11)));   /*Viernes 1 de noviembre de 2019*/
  vdnl.push_back(new Dia(new Fecha(18,11)));  /*Lunes 18 de noviembre de 2019*/
  vdnl.push_back(new Dia(new Fecha(12,12)));  /*Jueves 12 de diciembre de 2019*/
#endif /*CAL_GREGORIANO*/
/*Ahora usando el vector de Fechas VDF y el vector de Dias no 
 laborables vdnl, construir un vector de Dias laborables (los dias de 
 clase para los que se planificar\'an actividades) este vector de Dias 
 laborables se obtendra pasando un mensaje al objeto de clase 
 Calendario*/
  /*obtener Vector De Dias de Clase,*/
  vector<Dia*> VDDC = Cal2019->get_Dias_DC(VDF,vdnl); 
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for (unsigned int i = 0; i < VDDC.size(); i++) {
#ifndef CAL_GREGORIANO
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Lunes")
#else
    if(Cal_Greg->get_day_name(VDDC[i]->f) == "Lunes")
#endif /*CAL_GREGORIANO*/
      VDDC[i]->set_TDT(2.0);
#ifndef CAL_GREGORIANO
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Viernes")
#else
    if(Cal_Greg->get_day_name(VDDC[i]->f) == "Viernes")
#endif /*CAL_GREGORIANO*/
      VDDC[i]->set_TDT(1.0);
  }
#ifndef NDEBUG
  for(i=0;i<VDDC.size();i++){
    printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(VDDC[i]->f)
                                     ,VDDC[i]->f->d
                                     ,MES[VDDC[i]->f->m]
                                     ,2019);
  }
#endif /*NDEBUG*/
assert(1==0);

  delete Cal2019;
  delete Cal_Greg;
  return 0;
}//end main()


