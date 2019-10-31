#include <iostream>
#include <vector>
using namespace std;
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
int anio=2020;
Calendario *Cal_Greg;   /*Calendario Gregoriano*/
char MES[][32]={"static char MES[][32]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre"
};

int main(){
  Fecha F(1,1,2020);
  printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(&F)
                              ,F.d
                              ,MES[F.m]
                              ,2020);
  int i;
  for(i=1;i<=31;i++){
    F.d=i;
    printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(&F)
                                     ,F.d
                                     ,MES[F.m]
                                     ,2020);
  }
  
  return 0;
}

