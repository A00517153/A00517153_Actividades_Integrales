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
const string database="mylog.log";

int main(){
    logs list;
    string line;

    ifstream myfile(database);
    if(myfile.is_open()){
        cout<<"Logfile open succesfully!\n\n";
        getline(myfile,line);
        getline(myfile,line);

        while(getline(myfile,line)){
            list.add(line);
        }
        myfile.close();
        cout<<list.toString()<<endl;
        list.sort(1);
        cout<<list.toString()<<endl;


    }else{
        cout<<"Logfile couldn't open!\n\n";
    }

}