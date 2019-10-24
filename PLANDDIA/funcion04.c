/**
 * originalmente funcion04.c
 */
#include <stdio.h>
#include "intervalos.h"
#define DISC04
#ifdef DISC04
/**
 * Determina el nombre del d\'ia a partir de una fecha.
 * Devuelve:
 * 0 si la fecha es lunes,
 * 1 si la fecha es martes,
 * 2 si la fecha es mi\'ercoles,
 * 3 si la fecha es jueves,
 * 4 si la fecha es viernes,
 * 5 si la fecha es s\'abado,
 * 6 si la fecha es domingo.
 */
/*Stub*/
unsigned int calc_day_name(struct fecha *fechaPt)
{
  unsigned int result;
  int day,month;
  /*fecha del primer lunes de cada mes*/
  unsigned int magic_number2019[]={0,
    7,/*enero*/
    4,/*febrero*/
    4,/*marzo*/
    1,/*abril*/
    6,/*mayo*/
    3,/*junio*/
    1,/*julio*/
    5,/*agosto*/
    2,/*septiembre*/
    7,/*octubre*/
    4,/*noviembre*/
    2/*diciembre*/};
  day=fechaPt->d;month=fechaPt->m;
  result=(7+day-magic_number2019[month])%7;
  return result;
}
#else
unsigned int calc_day_name(struct fecha *fechaPt)
{
  //WRITE YOUR CODE HERE
}
#endif


