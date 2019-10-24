/*Alumno.cpp*/
#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <string>
/**
using std::cout;
using std::endl;
using std::string;
using std::ostream;
*/
using namespace std;
#include "Alumno.h"
//extern string OPYE[][6];
int Alumno::NDL=0;
ostream& operator<<(ostream& out,Alumno& a){
  out<<a.ndl<<" "<<a.firstname<<" "<<a.lastname;
  return out;
}

//void Antonio_de_Jesus_Alcantar_Rocha::opye(void){
//  class A{
//  public: 
//    A(){
//      cout<<"A::A()"<<endl;
//    }
//  };
//  class B:public A{
//  public: 
//    B(){
//    cout<<"B::B()"<<endl;
//    }
//  };
//  class C{
//    public:
//    C(){cout<<"C::C()"<<endl;}
//	class D{
//      public:
//      D(){cout<<"D::D()"<<endl;}
//	};
	
//    C(int){cout<<"C::C(int)"<<endl;}
//    //class C; 
//    //class E:public C{
//    //  public: E(){cout<<"D::D()"<<endl;}
//	//};
//  };
//  B b;
//  cout<<endl;
//  C c;
//  cout<<endl;
//  C::D cd;
//  cout<<OPYE[1][2]<<endl;
//}
//void Jose_Raul_Bautista_Contreras::opye(void){
//  cout<<OPYE[1][3]<<endl;
//}
//void Juan_Ivan_Cristobal_Rojo::opye(void){
//  cout<<OPYE[1][4]<<endl;
//}
//void Maria_Fernanda_Liy_Delgado::opye(void){
//  cout<<OPYE[1][5]<<endl;
//}
//void Zaira_Alejandra_Najera_Medina::opye(void){
//  cout<<OPYE[2][1]<<endl;
//}
//void Luis_Ricardo_Rivera_Hernandez::opye(void){
//  cout<<OPYE[2][2]<<endl;
//}
//void Aldo_Rodriguez_Hernandez::opye(void){
//  cout<<OPYE[1][2]<<endl;
//}
//void Antonio_Santiago_Santiago::opye(void){
//  cout<<OPYE[3][1]<<endl;
//}
