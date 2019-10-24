/** test_intervalos.c
 */ 
#include <stdio.h>
#include <string.h>
//#define NDEBUG
#include <assert.h>
#include <stdlib.h>
#include <time.h>    /*time_t time(),tm localtime()*/
#include "intervalos.h"
#include "gettingdate.h"
extern char day_name[][32];
extern char month_name[][32];

int main(int argc,char *argv[])
{
  int n=2;
  unsigned int mindex,dindex; /*mONTH index,dAY index*/
  time_t now=time(0);
  tm *ltm=localtime(&now);
  struct fecha f1;
  f1.d=get_day(ltm);
  f1.m=get_month(ltm);
  f1.a=get_year(ltm);
  mindex=f1.m;
  dindex=calc_day_name(&f1);
  printf("M\\'exico, %s %d de %s de %d\n",
         day_name[dindex],f1.d,month_name[mindex],f1.a);
  struct disponibilidad Ddf1;
  Ddf1.cant_de_interv=n;
  Ddf1.intervPt=(struct intervalo*)malloc( 
n*sizeof(struct intervalo));
  strcpy(Ddf1.intervPt->inicio,"14:35");
  strcpy(Ddf1.intervPt->final,"15:20"); 
  strcpy((Ddf1.intervPt+1)->inicio,"15:30");
  strcpy((Ddf1.intervPt+1)->final,"15:55"); 
  struct intervalos_en_la_fecha Inf1;
  Inf1.F=f1;
  Inf1.D=Ddf1;
void print_intervalos_en_la_fecha(struct 
intervalos_en_la_fecha *);
  print_intervalos_en_la_fecha(&Inf1);
  
  return 0;
}/*end main()*/

