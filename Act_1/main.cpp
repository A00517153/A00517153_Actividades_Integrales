#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "logs.h"
#include "sorts.h"

using namespace std;

int main (){
  string TESTTEXT("Aug 28 23:07:49 897.53.984.6:6710 Failed password for root");
	logs testlog(TESTTEXT);
  cout<<"T.- "<<testlog.toString();


  string line;
  vector<logs>loglist;
  Sorts<logs> sort;
  fstream myfile("bitacora.txt");
  if (myfile.is_open())
  {
    while (getline(myfile,line)&&loglist.size()<8){
      loglist.insert(loglist.begin(), logs(line));
    }
    myfile.close();
  } else cout << "Unable to open file\n";

  cout<<"lsz: "<<loglist.size()<<endl;

  for(int i=0;i<loglist.size();i++){
    cout<<i<<".- "<<loglist[i].toString();
  }

  cout<<"\n\n";
  sort.mergeSort(loglist,0);
  for(int i=0;i<loglist.size();i++){
    cout<<i<<".- "<<loglist[i].toString();
  }

  cout<<"\n\n";
  sort.mergeSort(loglist,1);
  for(int i=0;i<loglist.size();i++){
    cout<<i<<".- "<<loglist[i].toString();
  }

  cout<<"\n\n";
  sort.mergeSort(loglist,2);
  for(int i=0;i<loglist.size();i++){
    cout<<i<<".- "<<loglist[i].toString();
  }

  cout<<"\n\n";
  sort.mergeSort(loglist,3);
  for(int i=0;i<loglist.size();i++){
    cout<<i<<".- "<<loglist[i].toString();
  }


}
