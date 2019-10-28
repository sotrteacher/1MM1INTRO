/** test_Calendario.cpp
 */ 
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>  /*strcmp()*/
#define NDEBUG
#include <assert.h>
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
#include "../CommonFiles/Actividad.h"
#include "../CommonFiles/Asignacion.h"
#include "../CommonFiles/AdA.h"
#define INVESTIGACION_DE_OPERACIONES_COMP	/* COMPetencias */

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
VDA.push_back(new Actividad(name, duracion ## f ))


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
//static char MES[][32]={"static char MES[][32]",
char MES[][32]={"static char MES[][32]",
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
#ifndef NDEBUG
  /*Los siguientes dias deberian ser solamente Lunes y Martes (en este
   *caso que se trata del semestre Agosto-Diciembre de 2019 y Enero-Febrero de 
   *2020)*/
   for(int i=0;i<VDF.size();i++){
     printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(VDF[i])
                     ,VDF[i]->d
                     ,MES[VDF[i]->m]
                     ,VDF[i]->a);
   }
#endif /*NDEBUG*/
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
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Lunes"){
#else
    //if(Cal_Greg->get_day_name(VDDC[i]->f) == "Lunes"){
    if(!strcmp(Cal_Greg->get_day_name(VDDC[i]->f),"Lunes")){
#endif /*CAL_GREGORIANO*/
      VDDC[i]->set_TDT(2.0);
      assert(VDDC[i]->TDT==2.0);
#ifndef NDEBUG
      printf("VDDC[i]->TDT=%2.1f\n",VDDC[i]->TDT);
#endif /*NDEBUG*/
    }
#ifndef CAL_GREGORIANO
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Viernes"){
#else
    //if(Cal_Greg->get_day_name(VDDC[i]->f) == "Viernes"){
    if(!strcmp(Cal_Greg->get_day_name(VDDC[i]->f),"Viernes")){
#endif /*CAL_GREGORIANO*/
      VDDC[i]->set_TDT(1.0);
#ifndef NDEBUG
      printf("VDDC[i]->TDT=%2.1f\n",VDDC[i]->TDT);
#endif /*NDEBUG*/
    }
  }
#ifndef NDEBUG
  for(i=0;i<VDDC.size();i++){
    printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(VDDC[i]->f)
                                     ,VDDC[i]->f->d
                                     ,MES[VDDC[i]->f->m]
                                     ,2019);
  }
#endif /*NDEBUG*/
  /*Se necesita crear las actividades/temas a asignar en los
  dias de clase disponibles. Se usa usa constructor de Actividad
  pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
  vector<Actividad*> VDA;
#ifdef INVESTIGACION_DE_OPERACIONES_COMP
	NACT("0.0 Presentaci\\'on del curso",0.25);
	NACT("Unidad I INTRODUCCI\\'ON", 0.25);
	NACT("I.A ORIGEN Y APLICACI\\'ON DE LA INVESTIGACI\\'ON DE OPERACIONES",0.25);
	NACT("I.B MODELOS DE LA INVESTIGACI\\'ON DE OPERACIONES",0.25);
	NACT("I.C MODELOS RELEVANTES DE LA PROGRAMACION MATEM\\'ATICA",1.0);
	NACT("I.D SITUACIONES REALES DE APLICACI\\'ON DE LA INVESTIGACI\\'ON DE OPERACIONES",1.0);
	NACT("Unidad 2 PROBLEMAS DE PROGRAMACI\\'ON MATEM\\'ATICA",0.25);
	NACT("II.A MODELOS DE PROGRAMACI\\'ON LI\\-NEAL",0.75);
	NACT("II.B M\\'ETODO GR\\'AFICO",2.0);
	NACT("Unidad III SOLUCI\\'ON DE PROBLEMAS LI\\-NEA\\-LES",0.25);
	NACT("III.A M\\'ETODO SIMPLEX",1.75);
	NACT("III.B USO DE VARIABLES ARTIFICIALES EN EL M\\'ETODO SIMPLEX",1.0);
	NACT("III.C RESOLUCI\\'ON DE PROBLEMAS LI\\-NEA\\-LES",1.0);
	NACT("PRIMER EXAMEN PARCIAL",2.0);
	NACT("REVISI\\'ON DE LA PRIMERA EVALUACI\\'ON PARCIAL",1.0);
	//NACT("III.C RESOLUCI\\'ON DE PROBLEMAS LI\\-NEA\\-LES", 3.0);
	NACT("Unidad IV SENSIBILIDAD Y DUALIDAD",0.25);
	NACT("IV.A PROBLEMA DUAL Y SU RELACI\\'ON CON EL PRIMAL",0.75);
	NACT("IV.B M\\'ETODO SIMPLEX DUAL",1.0);
	NACT("IV.C AN\\'ALISIS DE SENSIBILIDAD A UNA SOLUCI\\'ON DADA",4.0);
	NACT("Unidad V METODOLOG\\'IA PARA PROBLEMAS CON REDES",0.25);
	NACT("V.A CONCEPTO DE REDES",0.75);
	NACT("V.B PROBLEMAS CON REDES",1.0);
	NACT("V.C PROBLEMAS DE TRANSBORDO",2.0);
	NACT("V.D RESOLUCI\\'ON DE PROBLEMAS DE TRANSPORTE",2.0);
	NACT("SEGUNDA EVALUACI\\'ON PARCIAL",2.0);
	NACT("REVISI\\'ON DE LA SEGUNDA EVALUACI\\'ON PARCIAL", 1.0);
	NACT("V.E RESOLUCI\\'ON DE PROBLEMAS (M\\'ETODO DE VOGEL)",0.5);
	NACT("V.F PROBLEMAS DE ASIGNACI\\'ON",2.0);
	NACT("V.G M\\'ETODO DE VOGEL",2.0);
	NACT("V.H M\\'ETODO HUNGARO",2.0);
	NACT("V.I RESOLUCI\\'ON DE PROBLEMAS POR LA RUTA M\\'AS CORTA",1.5);
	//NACT("V.I RESOLUCI\\'ON DE PROBLEMAS POR LA RUTA M\\'AS CORTA",0.5);
	NACT("V.J RESOLUCI\\'ON DE PROBLEMAS POR LA RUTA M\\'AS LARGA",1.0);
	//NACT("V.K FORMULADO DE PROBLEMAS POR FLUJO M\\'AXIMO",2.0);
	//NACT("V.L PLANTEAMIENTO DE PROBLEMAS",1.5);
	//NACT("TERCERA EVALUACI\\'ON PARCIAL",2.0);
	//NACT("REVISI\\'ON DE LA TERCERA EVALUACI\\'ON PARCIAL", 1.0);
	//NACT("EVALUACI\\'ON FINAL ORDINARIA",2.0);
#endif /* INVESTIGACION_DE_OPERACIONES_COMP */

	/*Por ultimo se hace la planeacion pasando el vector de dias de 
	clase y el vector de actividades*/
	Cal2019->planear(VDDC, VDA);

	/*Finalmente se imprime en pantalla los dias a planear con las 
	actividades correspondientes por dia de clase entre las fechas 
	f1 y f2.*/
	cout << "Los dias a planificar son:" << endl;
#ifndef NDEBUG
	cout << *VDDC[0] << endl;
#endif
  assert(VDDC.size()<=40);
	for (unsigned int i = 0; i<VDDC.size(); i++) {
		cout << *VDDC[i] << endl;
	}
assert(1==0);

  delete Cal2019;
  delete Cal_Greg;
  return 0;
}//end main()


