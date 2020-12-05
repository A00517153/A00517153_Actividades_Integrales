#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include "logs.h"
//#include "archivo.h"

using namespace std;
//archivos de datos
const string database="mylog.log";
const string logexample="2020 10 01 07:22:46,450.25.888.72:5978,A";

int main(){
    logs list; //almacen datos
    string auxa,auxb,emptStr; //variables auxiliares

    fstream myfile(database); //abir base de datos
    if(myfile.is_open()){ //leer archivo
        cout<<"Logfile open succesfully!\n\n";
        while(getline(myfile,auxa)){
            if(auxa.size()>=logexample.size()){
                list.add(auxa); //almacenar las entradas en su lista
            }
        }
        myfile.close(); //cerrar archivo
        list.sort(0);
        string dateformat="1999 12 31";
        string dateformat2="2020 07 16 03:38:22";
        string ipformat="99.99.999.99:9999";
        auxa=auxb=emptStr;
        while(true){
            //Busqueda de datos por rango de fechas
            cout<<"Ingrese la fecha inicial (Formato '"<<dateformat<<"'): ";
            getline(cin,auxa);
            cout<<"Ingrese la fecha final (Formato '"<<dateformat<<"'): ";
            getline(cin,auxb);
            if(auxa<=auxb){
                if(auxa!=emptStr && auxb!=emptStr){
                    emptStr=auxb[auxb.size()-1]+1;
                    auxb.replace(auxb.size()-1,1,emptStr);
                    cout<<list.range(auxa,auxb,0);
                    break;
                }else{cout<<"\nIntente otra vez una busqueda valida...\n\n";}
            }else{cout<<"\nIntente otra vez una busqueda valida...\n\n";}
        }
        auxa=auxb=emptStr;
        while(true){
            //Busqueda de datos por rango de IPs
            cout<<"Ingrese la IP inicial (Formato '"<<ipformat<<"'): ";
            getline(cin,auxa);
            cout<<"Ingrese la IP final (Formato '"<<ipformat<<"'): ";
            getline(cin,auxb);
            if(auxa<=auxb){
                if(auxa!=emptStr && auxb!=emptStr){
                    emptStr=auxb[auxb.size()-1]+1;
                    auxb.replace(auxb.size()-1,1,emptStr);
                    cout<<list.range(auxa,auxb,1);
                    break;
                }else{cout<<"\nIntente otra vez una busqueda valida...\n\n";}
            }else{cout<<"\nIntente otra vez una busqueda valida...\n\n";}
        }
        //Capacidad de agregar nuevas entradas
        cout<<"¿Desea agregar una o varias entradas al registro?:\n\t1. Si\n\t0. No\n";
        cin>>auxa;
        if(auxa=="1"){
            cout<<"¿Cuantas entradas desea agregar?: ";
            cin>>auxa;
            int n=stoi(auxa);
            if(n>0){
                for(int i=0;i<n;++i){
                    while(true){
                        cout<<"Favor de ingresar la fecha en el formato '"<<dateformat2<<"': ";
                        getline(cin,auxa);
                        if(auxa.size()==dateformat2.size()){
                            stringstream auxc;
                            auxc<<auxa;
                            cout<<"Favor de ingrsar la Ip en el formato '"<<ipformat<<"': ";
                            getline(cin,auxa);
                            if(auxa.size()==ipformat.size()){
                                auxc<<","<<auxa;
                                cout<<"Favor de ingrsar la informacion de registro: ";
                                getline(cin,auxa);
                                auxc<<","<<auxa;
                                list.add(auxc.str());
                                break;
                            }
                        }
                        cout<<"\nFavor de ingresar una entrada valida.\n\n";
                    }
                }
            }
        }

        ofstream myfile(database);
            if(myfile.is_open()){
                myfile<<list.toFile();
                myfile.close();
            }
    }else{cout<<"Logfile couldn't open!\n\n";}

}