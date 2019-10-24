//Calendario.h
#ifndef CALENDARIO_H
#define CALENDARIO_H

#ifdef MAIN_MODULE_PRUEBA
#define EXTERN
#else
#define EXTERN	extern
#endif /*MAIN_MODULE_PRUEBA*/

#ifndef MAIN_MODULE_PRUEBA
EXTERN string ARREGLO[][7];
EXTERN int TamDMes[];
#endif

typedef
struct SetDIntType{
  int n;
  int *intPt;
  SetDIntType():n(0),intPt(NULL){ }
  bool operator==(SetDIntType &sdit)const{
    bool tmp0=true;
    bool tmp1=(n==sdit.n);
    for(int i=0;i<n;i++){
      if(*(intPt+i)!=*(sdit.intPt+i)){
        tmp0=false;
        break;
      }
    }
    return (tmp0 && tmp1);
  }
}SetDIntType;
//typedef struct SetDInt SetDIntType;


struct Fecha;
class Dia;
class Actividad;
class Alumno;
class Calendario{
public:
  void mostrar_fechas(string dia,string mes);
  Calendario(int year):numdanio(year){ }
  Calendario():numdanio(0){ }
  int get_anio(){
    return numdanio;
  }
  //...
  /**
   Obtiene los numeros de dia de las fechas de los 
   dias d en el mes m.
   */
  SetDIntType* obtener_nums_ddia(string d,string m);
  void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);

  /**
   Obtiene el indice correspondiente al mes month. 
   Si month="enero", debe devolver 0, 
   Si month="febrero", debe devolver 1, 
   Si month="marzo", debe devolver 2, 
   etc.
   */
  int index_delmes(string month);

  /**
   Devuelve el numero de dia de la primera fecha 
   del mes con indice i (devuelto por 
   index_delmes(string month)), en la que el dia 
   es el string day.
   */
  int primera_fecha_delmes(string day,int i);

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
  void fill_SDIT(int i,int j,SetDIntType* r);

  bool esta_incluido(string d,vector<string> dias);
  bool esta_incluido(Fecha*,vector<Dia*>);
  bool esta_incluido(Fecha*,vector<Fecha*>);
  /**
   Calcula la cantidad de dias desde la fecha inicial fi 
   hasta la fecha final ff.
   @pre: ff debe ser posterior a fi.
  */
  int cant_dFechas(Fecha *fi,Fecha *ff,vector<string> dias);

  /**
   Obtiene un vector de Fechas en el periodo con los dias 
   de la semana indicado en el vector dias.
  */
  vector<Fecha*> get_Fechas(Fecha *fi,Fecha *ff,vector<string> dias);
  /**
   Obtiene un vector con los Dias de Clase. Con este vector se procedera
   a colocar los temas del curso.
  */
  vector<Dia*> get_Dias_DC(vector<Fecha*> vdf,vector<Dia*> dnl);

  /**
   Antes de usar este metodo se debe usar get_Dias_DC y se debe 
   usar ObjetoDia.set_TDT(#).
  */
  void planear(vector<Dia*> vddc,vector<Actividad*> act);
  //void planear(vector<Dia*> DIA,vector<Actividad*> ACT,vector<Alumno*> Alum);
  
  /** Devuelve el nombre del dia ("lunes","martes","mi\\'ercoles",
   * "jueves","viernes","s\\'abado","domingo") correspondiente a la 
   * fecha a la que apunta f_Pt.
   */ 
#ifdef USAR_STRING
  std::string get_day_name(Fecha *f_Pt);
#else
  char *get_day_name(Fecha *f_Pt);
#endif

  int numdanio;  //numero de anio
};//end class Calendario
#endif /*CALENDARIO_H*/
