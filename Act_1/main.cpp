#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "logs.h"
#include "sorts.h"

using namespace std;
const string filename="mylog.log";
const bool shorttest=true; //true for test with only 100 entries, false to check all entries in log file.

template<class T>
void menu(vector<T> &l, Sorts<T> &s){
  int temp[5]={0,0,0,0,0};
  vector<logs> d;
  d.resize(2);
  do{
    cout<<"Enter the option that you want to work with...\n";
    cout<<"\t0.- Exit program.\n\t1.- Display full log list.\n";
    cout<<"\t2.- Sort log list by date.\n\t3.- Display logs between certain dates.\n";

    cout<<"Please enter selection: ";
    cin>>temp[0];
    switch(temp[0]){
      case 0: cout<<"\n\n";break;
      case 1:
        cout<<"\n\n";
        temp[1]=0;
        for(int i=0;i<l.size();i++){
          cout<<l[i].toString();
          temp[1]++;
        }
        cout<<"\nDisplayed "<<temp[1]<<" entries.\n\n";
        break;
      case 2:
        s.mergeSort(l,0);
        cout<<"\n\nLog list sorted by date.\n\n";
        break;
      case 3:
        cout<<"\n\nEnter the number of the lower limit month:\t";
        cin>>temp[0];
        cout<<"Enter the number of the lower limit day:\t";
        cin>>temp[1];
        d[0]=logs(temp,temp,"");

        cout<<"Enter the number of the upper limit month\t";
        cin>>temp[0];
        cout<<"Enter the number of the upper limit day:\t";
        cin>>temp[1];
        d[1]=logs(temp,temp,"");

        cout<<"\n\n";
        temp[1]=0;
        for(int i=0;i<l.size();i++){
          if(s.compareDate(d[0],l[i],0) && s.compareDate(l[i],d[1],0)){
            cout<<l[i].toString();
            temp[1]++;
          }
        }
        cout<<"\nDisplayed "<<temp[1]<<" entries that satisfy that condition.\n\n";
        break;
      default: 
      cout<<"\n\nPlease Enter a valid option...\n\n";
    }
  }while(temp[0]!=0);
  
  //TEST
}

int main (){

  string line;
  vector<logs>loglist;
  Sorts<logs> sort;
  ifstream myfile(filename);
  if (myfile.is_open())
  {
    cout<<"Log file open succesfully!\n\n";
    while (getline(myfile,line)){
      if(loglist.size()>99&&shorttest){break;}
      loglist.insert(loglist.begin(), logs(line));
    }
    myfile.close();
    cout<<"Loaded "<<loglist.size()<<" entries!\n\n";
    menu(loglist,sort);

  } else cout << "Unable to open file... \nMake sure the file '"<<filename<<"' is in the correct folder... \n";

  cout<<"Exiting Program..."<<endl;
}
