// Proyecto_Calendario_Planeacion1.cpp: define el punto de 
// entrada de la aplicacin de consola.

#ifdef VISUAL_STUDIO_2017
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <iostream>
#include <vector>
#include <string>   /* out<<cadena, donde std::string cadena; */
#include <stdlib.h>  /*malloc()*/
#include <fstream>  /*ofstream*/
#include <windows.h> /*STARTUPINFO, PROCESS_INFORMATION*/
//#define NDEBUG
#include <assert.h>
/*
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;
*/
using namespace std;

//En Windows 7 de 64 bits, utilizar:
//#define PDFLATEX	"C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe"
//#define ACROBAT	"C:/Program Files (x86)/Adobe/Acrobat 10.0/Acrobat/Acrobat.exe"

//En Windows 7 de 32 bits, utilizar:
//#define PDFLATEX	"C:/Program Files/MiKTeX 2.9/miktex/bin/pdflatex.exe"
//#define ACROBAT  "C:/Program Files/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe"
//LPCWSTR PDFLATEX = L"C:/Program Files/MiKTeX 2.9/miktex/bin/pdflatex.exe";

//En Windows 10 de 64 bits, utilizar:
#ifdef VISUAL_STUDIO_2017
LPCWSTR PDFLATEX = L"C:/Program Files/MiKTeX 2.9/miktex/bin/x64/pdflatex.exe";
LPCWSTR ACROBAT = L"C:/Program Files (x86)/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe";
#else
#define PDFLATEX	"C:/Program Files (x86)/MiKTeX 2.9/miktex/bin/pdflatex.exe"
#define ACROBAT	"C:/Program Files (x86)/Adobe/Acrobat 10.0/Acrobat/Acrobat.exe"
#endif /*VISUAL_STUDIO_2017*/

#define INVESTIGACION_DE_OPERACIONES_COMP	/* COMPetencias */

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
VDA.push_back(new Actividad(name, duracion ## f ))

#ifdef INVESTIGACION_DE_OPERACIONES_COMP
#define PREFIX	"PlaneacionInvDeOpCOMP_"
#define VERSION	1
#define UNIDAD_DE_APRENDIZAJE    "INVESTIGACI\\'ON DE OPERACIONES"
#ifdef VISUAL_STUDIO_2017
TCHAR STR[] = _T("pdflatex.exe PlaneacionInvDeOpCOMP_1.tex");
TCHAR STR1[] = _T("AcroRd32.exe PlaneacionInvDeOpCOMP_1.pdf");
#else
char STR[]="pdflatex.exe PlaneacionInvDeOpCOMP_2.tex";
char STR1[]="AcroRd32.exe PlaneacionInvDeOpCOMP_2.pdf";
#endif /*VISUAL_STUDIO_2017*/
#endif /* INVESTIGACION_DE_OPERACIONES_COMP */

#define NUM_INIC_DE_DIA_PLANEADO      1
/*
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector; 
*/

#include "..\CommonFiles\Calendario.h"
#include "..\CommonFiles\Fecha.h"
#include "..\CommonFiles\Dia.h"
#include "..\CommonFiles\Actividad.h"
#include "..\CommonFiles\Asignacion.h"
#include "..\CommonFiles\AdA.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int anio = 2019;

///* A\~no 2018*/
//string ARREGLO[][7] = {
//{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*enero*/
//{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*febrero*/
//{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*marzo*/
//{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*abril*/
//{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo" }, /*mayo*/
//{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*junio*/
//{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*julio*/
//{ "Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes" }, /*agosto*/
//{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }, /*septiembre*/
//{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*octubre*/
//{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*noviembre*/
//{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }  /*diciembre*/
//};

static string MONTH[] = { 
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre" 
};

SetDIntType* obtener_nums_ddia(string d, string m);
//void print_SetDIntYFecha(string d, string m, SetDIntType* SDI);
int index_delmes(string month);
int primera_fecha_delmes(string day, int i);
void fill_SDIT(int i, int j, SetDIntType* r);
void suma_de_horas(vector<Actividad*>);
//void alumno_init(vector<Alumno*>& alumno);
void print_alumnos(vector<Alumno*>);

int main(int argc, char** argv) {
	int intPlanDDiaNum = NUM_INIC_DE_DIA_PLANEADO;

	Calendario *Cal2019 = new Calendario(2019);
	vector<string> vdd;         /*vector de dias*/
								/*los dias que hay clase*/
#ifdef INVESTIGACION_DE_OPERACIONES_COMP
#ifndef CAL_GREGORIANO
	Fecha f1(16, 8); /*Lunes 16 de septiembre de 2019 */
	Fecha f2(20, 11); /*Viernes 20 de diciembre de 2019 */
#else
	Fecha f1(16, 9); /*Lunes 16 de septiembre de 2019 */
	Fecha f2(20, 12); /*Viernes 20 de diciembre de 2019 */
#endif /*CAL_GREGORIANO*/
        /*Se indican los d\'ias de la semana que hay clases*/
	vdd.push_back("Lunes");
	vdd.push_back("Viernes");
#endif /* INVESTIGACION_DE_OPERACIONES_COMP */
	/*vector con las Fechas entre f1 y f2 correspondientes a 
	 los dias en el vector vdd */
	vector<Fecha*> VDF = Cal2019->get_Fechas(&f1, &f2, vdd); 
															 
	/*construir un vector de apuntadores a Dias no laborables*/
	vector<Dia*> vdnl;
	vdnl.push_back(new Dia(new Fecha(1,10))); /*Viernes 1 de noviembre de 2019*/
	vdnl.push_back(new Dia(new Fecha(18,10)));  /*Lunes 19 de noviembre de 2019*/
        vdnl.push_back(new Dia(new Fecha(12,11)));  /*Jueves 12 de diciembre de 2019*/
//vdnl.push_back(new Dia(new Fecha(24,2)));      /*Jueves 24 de marzo de 2016*/
//vdnl.push_back(new Dia(new Fecha(24,2)));      /*Viernes 25 de marzo de 2016*/
//vdnl.push_back(new Dia(new Fecha(2,4)));       /*Lunes 2 de mayo de 2016*/
//vdnl.push_back(new Dia(new Fecha(5,4)));       /*Jueves 5 de mayo de 2016*/

/*Ahora usando el vector de Fechas VDF y el vector de Dias no 
 laborables vdnl, construir un vector de Dias laborables (los dias de 
 clase para los que se planificar\'an actividades) este vector de Dias 
 laborables se obtendra pasando un mensaje al objeto de clase 
 Calendario*/
	/*obtener Vector De Dias de Clase,*/
	vector<Dia*> VDDC = Cal2019->get_Dias_DC(VDF,vdnl); 

	/*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
	for (unsigned int i = 0; i < VDDC.size(); i++) {
#ifdef INVESTIGACION_DE_OPERACIONES_COMP
		if (ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Lunes")
			VDDC[i]->set_TDT(2.0);
		if (ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d % 7] == "Viernes")
			VDDC[i]->set_TDT(1.0);
#endif /* INVESTIGACION_DE_OPERACIONES_COMP */
	}

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
	NACT("III.C RESOLUCI\\'ON DE PROBLEMAS LI\\-NEA\\-LES",3.0);
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
	//Cal2016->planear(VDDC,VDA,Alum);

	/*Finalmente se imprime en pantalla los dias a planear con las 
	actividades correspondientes por dia de clase entre las fechas 
	f1 y f2.*/
	cout << "Los dias a planificar son:" << endl;
#ifndef NDEBUG
	cout << *VDDC[0] << endl;
#endif
	for (unsigned int i = 0; i<VDDC.size(); i++) {
		cout << *VDDC[i] << endl;
	}
//assert(1==0);
	suma_de_horas(VDA);

	///////////////////////////////////////////////////////////////
	/* Creaci\'on del archivo LaTeX */
	char str[128];//,str1[128];
	string dest_name, string_day_name;
	///** 2018.08.16
#ifdef VISUAL_STUDIO_2017
	sprintf_s(str, "%s%d.tex", PREFIX, VERSION);
#else
        sprintf(str,"%s%d.tex",PREFIX,VERSION);
#endif /*VISUAL_STUDIO_2017*/
	//*/

	dest_name = string(str);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ofstream out(dest_name.c_str());
	out << "\\documentclass[landscape]{article}" << endl;
	out << "\\usepackage[lmargin=1.73cm,rmargin=1.73cm,top=1.9cm,bottom=2.54cm]{geometry}" << endl;
	out << "\\pagestyle{empty}" << endl;	/*Para que \LaTeX no ponga numeros de p\'agina*/
	out << "\\begin{document}" << endl;
	out << "{\\large" << endl;
	for (unsigned int j = 0; j < VDDC.size(); j++) {
		out << "\\begin{center}" << endl;
		out << "{\\bf " << endl;
		out << UNIDAD_DE_APRENDIZAJE << endl;
		out << "}" << endl;
		out << "\\ \\\\" << endl;
		out << "\\ \\\\" << endl;
		out << "Planeaci\\'on del d\\'ia n\\'umero \\underline{"
			<< "\\hspace{0.5cm}" << intPlanDDiaNum << "\\hspace{0.5cm}}" << endl;
		out << "\\ \\\\" << endl;
		out << "\\ \\\\" << endl;
		out << "\\begin{tabular}{|p{11cm}|p{8cm}|}\\hline" << endl;
		out << "{\\bf TEMA DEL PROGRAMA}&{\\bf ACTIVIDADES DE APRENDIZAJE}\\\\\\hline" << endl;
	
		for (unsigned int i = 0; i < VDDC[j]->A.size(); i++) {
			out << *(VDDC[j]->A[i]) << "&"<<VDDC[j]->A[i]->Act->ACT_DE_APR<<"\\\\" << endl;
		}
	
		out << "\\hline" << endl;
		out << "\\end{tabular}" << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		string_day_name = ARREGLO[VDDC[j]->f->m][(VDDC[j]->f->d) % 7];
		out << string_day_name
			<< " \\underline{\\hspace{0.5cm}" << VDDC[j]->f->d << "\\hspace{0.5cm}} de "
			<< " \\underline{\\hspace{0.5cm}"
			<< MONTH[VDDC[j]->f->m] << "\\hspace{0.5cm}} de " << anio << "." << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		out << "Elabor\\'o:" << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		out << "\\ \\\\" << endl; out << "\\ \\\\" << endl;
		out << "{\\bf ING. LAMBERTO MAZA CASAS}" << endl;
		out << "\\end{center}" << endl;
		out << "\\eject" << endl;
		intPlanDDiaNum++;
	}
	out << "}" << endl;/*cierra la llave del {\large */
	out << "\\end{document}" << endl;
	out.close();

	///////////////////////////////////////////////////////////////
	/* Compilaci\'on del archivo LaTeX */
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
#ifdef VISUAL_STUDIO_2017
	sprintf_s(str, "pdflatex.exe ./%s%d.tex", PREFIX, VERSION);
#else
	sprintf(str,"pdflatex.exe ./%s%d.tex",PREFIX,VERSION);
#endif /*VISUAL_STUDIO_2017*/
	string msg = string(str);
	//V\'ease cambios (remplazo de las macros PDFLATEX y la variable STR).
	if (!CreateProcess(PDFLATEX, STR, 0, 0, 0, 0, 0, 0, &si, &pi)) {
		//Could not start process;
		///** 2018.08.16
		cerr << "Could not start process: " << msg << endl;
		//*/
		system("PAUSE");
		return -1;
	}
	CloseHandle(pi.hThread);
	// wait for the child program to terminate
	WaitForSingleObject(pi.hProcess, INFINITE);
	///////////////////////////////////////////////////////////////
	/*Se muestra el archivo pdf usando Acrobat Reader*/
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
#ifdef VISUAL_STUDIO_2017
	sprintf_s(str, "AcroRd32.exe ./%s%d.pdf", PREFIX, VERSION);
#else
	sprintf(str, "AcroRd32.exe ./%s%d.pdf", PREFIX, VERSION);
#endif /*VISUAL_STUDIO_2017*/
	msg = string(str);
	if (!CreateProcess(ACROBAT, STR1, 0, 0, 0, 0, 0, 0, &si, &pi)) {
		//Could not start process;
		cerr << "Could not start process: " << msg << endl;
		system("PAUSE");
		return -1;
	}
	CloseHandle(pi.hThread);
	// wait for the child program to terminate
	WaitForSingleObject(pi.hProcess, INFINITE);
	///////////////////////////////////////////////////////////////
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}//end main()

/**
Obtiene los numeros de dia de las fechas de los
dias d en el mes m.
*/
SetDIntType* obtener_nums_ddia(string d, string m) {
	SetDIntType* r = (SetDIntType*)malloc(sizeof(SetDIntType));
	int i, j;  /* i: index del mes en el arreglo ARREGLO*/
	i = index_delmes(m);
	if (i >= 0 && i<12) {
		j = primera_fecha_delmes(d, i);
	}
	fill_SDIT(i, j, r);
	return r;
}


/**
Obtiene el indice correspondiente al mes month.
Si month="enero", debe devolver 0,
Si month="febrero", debe devolver 1,
Si month="marzo", debe devolver 2,
etc.
*/
int index_delmes(string month) {
	for (int i = 0; i<12; i++) {
		if (month == MONTH[i])
			return i;
	}
	return -1;/*no se encontro la cadena*/
}

/**
Devuelve el numero de dia de la primera fecha
del mes con indice i (devuelto por
index_delmes(string month)), en la que el dia
es el string day.
*/
int primera_fecha_delmes(string day, int i) {
	if (ARREGLO[i][0] == day) return 7;
	if (ARREGLO[i][1] == day) return 1;
	if (ARREGLO[i][2] == day) return 2;
	if (ARREGLO[i][3] == day) return 3;
	if (ARREGLO[i][4] == day) return 4;
	if (ARREGLO[i][5] == day) return 5;
	if (ARREGLO[i][6] == day) return 6;
	return -1;/*nunca deber\'ia llegarse aqui*/
}

/*Cantidades de dias de los meses del anio (No v\'alido para anios bisiestos)*/
int TamDMes[] = {
	31,/*enero*/
	28,/*febrero*/
	31,/*marzo*/
	30,/*abril*/
	31,/*mayo*/
	30,/*junio*/
	31,/*julio*/
	31,/*agosto*/
	30,/*septiembre*/
	31,/*octubre*/
	30,/*noviembre*/
	31 /*diciembre*/
};

/**
Cumplimenta el SetDIntType al que apunta el apuntador r.
Esto es, despues de llamar a este metodo, r->n contendra
la cantidad de veces que se presenta el dia de la semana
correspondiente a la fecha j (j es un int que corresponde
al primer lunes, martes, miercoles etc.
j\in{1,2,3,4,5,6,7}), en el mes con indice i. Mientras que
el apuntador r->intPt apuntara a los numeros de dia en las
fechas tales que el dia coincide con el dia de la fecha j
del mes con indice i.
@param i: index del mes; 0 enero, 1 febrero, 2 marzo, etc.
@param j: primera fecha del mes correspondiente al dia de
la semana cuyas fechas que estamos buscando.
@param r: Conjunto de enteros.
*/
void fill_SDIT(int i, int j, SetDIntType* r) {
	int cnt = 1, k = j;
	while ((k = k + 7) <= TamDMes[i])cnt++;
	r->n = cnt;
	k = j;
	r->intPt = (int*)malloc((r->n) * sizeof(int));
	for (int m = 0; m<r->n; m++) {
		*(r->intPt + m) = k;
		k += 7;
	}
}

void suma_de_horas(vector<Actividad*> vda) {
	float sum = 0;
	for (unsigned int i = 0; i<vda.size(); i++) {
		sum += vda[i]->TRT;
	}
	cout << "Total de horas=" << sum << endl;
}
