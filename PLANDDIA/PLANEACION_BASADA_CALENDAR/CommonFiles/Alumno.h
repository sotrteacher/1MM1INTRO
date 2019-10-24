#ifndef ALUMNO_H
#define ALUMNO_H
#define hazcad(s)  #s
#define CLASSAL(fn,ln)  class fn##_##ln : public Alumno{\
public:\
  fn##_##ln (string firstn,string lastn):Alumno(firstn,lastn){ }\
  void opye(void);\
}

class Alumno{
public:
static int NDL;
  int ndl;          /*numero de lista*/
  string firstname;
  string lastname;
  Alumno(string firstn,string lastn):firstname(firstn),lastname(lastn){NDL++;ndl=NDL;}
  virtual void opye(void){ }
friend ostream& operator<<(ostream& out,Alumno& a);
};//end class Alumno

CLASSAL(Antonio_de_Jesus,Alcantar_Rocha);
CLASSAL(Jose_Raul,Bautista_Contreras);
CLASSAL(Juan_Ivan,Cristobal_Rojo);
CLASSAL(Maria_Fernanda,Liy_Delgado);
CLASSAL(Zaira_Alejandra,Najera_Medina);
CLASSAL(Luis_Ricardo,Rivera_Hernandez);
CLASSAL(Aldo,Rodriguez_Hernandez);
CLASSAL(Antonio,Santiago_Santiago);
#endif /*ALUMNO_H*/
