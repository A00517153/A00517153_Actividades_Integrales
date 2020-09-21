#ifndef LOGS_H
#define LOGS_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class logs {
	private:
		int date[5];
		int ip[5];
		string logText;
	public:
    logs();
    logs(int[5],int[5],string);
		logs(string);
		int getDate(int)const;
		int getIp(int)const;
		string getLogText()const;
		string toString();
    int setMonth(string);
    string getMonth(int);
};

logs::logs(){
  //Empty constructor.
}

logs::logs(int d[5], int i[5], string t){
  for(int is=0;is<5;is++){
    date[is]=d[is];
    ip[is]=i[is];
  }
  logText=t;
}

logs::logs(string log){
	stringstream aux1(log);
	string auxstr;

	getline(aux1,auxstr,' ');
  date[0]=setMonth(auxstr);
	getline(aux1,auxstr,' ');
  date[1]=stoi(auxstr);
	getline(aux1,auxstr,':');
  date[2]=stoi(auxstr);
	getline(aux1,auxstr,':');
  date[3]=stoi(auxstr);
	getline(aux1,auxstr,' ');
  date[4]=stoi(auxstr);

  getline(aux1,auxstr,'.');
  ip[0]=stoi(auxstr);
  getline(aux1,auxstr,'.');
  ip[1]=stoi(auxstr);
  getline(aux1,auxstr,'.');
  ip[2]=stoi(auxstr);
  getline(aux1,auxstr,':');
  ip[3]=stoi(auxstr);
  getline(aux1,auxstr,' ');
  ip[4]=stoi(auxstr);

  getline(aux1,logText,'\n');
}

int logs::getDate(int x)const{return date[x];}

int logs::getIp(int x)const{return ip[x];}

string logs::getLogText()const{return logText;}

string logs::toString(){
  stringstream aux;
  aux<<getMonth(date[0])<<date[1]<<" "<<date[2]<<":"<<date[3]<<":"<<date[4]<<" ";
  aux<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<" ";
  aux<<logText<<"\n";
  return aux.str();
}

int logs::setMonth(string month){
	if(month=="Jan"){return 1;}
	if(month=="Feb"){return 2;}
	if(month=="Mar"){return 3;}
	if(month=="Apr"){return 4;}
	if(month=="May"){return 5;}
	if(month=="Jun"){return 6;}
	if(month=="Jul"){return 7;}
	if(month=="Aug"){return 8;}
	if(month=="Sep"){return 9;}
	if(month=="Oct"){return 10;}
	if(month=="Nov"){return 11;}
	if(month=="Dec"){return 12;}
  else{return 0;}
};

string logs::getMonth(int month){
  switch(month){
    case 1: return "Jan ";
    case 2: return "Feb ";
    case 3: return "Mar ";
    case 4: return "Apr ";
    case 5: return "May ";
    case 6: return "Jun ";
    case 7: return "Jul ";
    case 8: return "Aug ";
    case 9: return "Sep ";
    case 10:return "Oct "; 
    case 11:return "Nov ";
    case 12:return "Dec ";
    default: return "N/D ";
  }
};


#endif
