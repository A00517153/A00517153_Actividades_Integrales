#ifndef LOGS_H
#define LOGS_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;


def int setMonth(string month){
	if(month="Jan"){return 1;}
	if(month="Feb"){return 2;}
	if(month="Mar"){return 1;}
	if(month="Apr"){return 2;}
	if(month="May"){return 1;}
	if(month="Jun"){return 2;}
	if(month="Jul"){return 1;}
	if(month="Aug"){return 2;}
	if(month="Sep"){return 1;}
	if(month="Oct"){return 2;}
	if(month="Nov"){return 1;}
	if(month="Dec"){return 2;}
}

class logs {
	private:
		int *date=new int[5];
		int *ip= new int[5];
		string fail;
	public:
		logs(string);
		~logs();
		int getDate(int)const;
		int getIp(int)const;
		string getFail()const;
		string toString()const;
};

logs::logs(string log){
	stringstream aux1,aux2;
	string aux3;
	aux1<<log;
	getline(aux1,date[0],' ');
	getline(aux1,date[1],' ');
	getline(aux1,date[2],':');
	getline(aux1,date[3],':');
	getline(aux1,date[4],':');
	
}





#endif
