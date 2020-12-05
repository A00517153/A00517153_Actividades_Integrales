#ifndef log_H
#define log_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class log{
    private:
        string date, ip, logtext;
    public:
        log();
        log(string);
        string toString();
        string toFile();
        string getDate(){return date;}
        string getIp(){return ip;}
        string getLog(){return logtext;}
};

log::log(){}

log::log(string data){
    stringstream aux(data);
    string auxstr;
    getline(aux,auxstr,',');
    date=auxstr;
    getline(aux,auxstr,',');
    ip=auxstr;
    getline(aux,auxstr);
    logtext=auxstr;
}

string log::toString(){
    stringstream aux;
    aux<<date<<" "<<ip<<" "<<logtext<<"\n";
    return aux.str();
}

string log::toFile(){
    stringstream aux;
    aux<<date<<","<<ip<<","<<logtext<<"\n";
    return aux.str();
}

class logSorts{
    private:
        void swap(vector<log>&,int,int);
        void copyArray(vector<log>&,vector<log>&,int,int);
        void mergeArray(vector<log>&,vector<log>&,int,int,int,int);
        void mergeSplit(vector<log>&,vector<log>&,int,int,int);
    public:
        void ordenaMerge(vector<log>&,int);
        int busqBinaria(vector<log>&,string,int);
};

void logSorts::swap(vector<log> &v, int i, int j) {
	log aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void logSorts::copyArray(vector<log> &A, vector<log> &B, int low, int high){
  for (int i=low;i<=high;i++){
    A[i]=B[i];
  }
}

void logSorts::mergeArray(vector<log> &A, vector<log> &B, int low, int mid, int high, int stype){
  int i=low,j=mid+1,k=low;
    if(stype==0){
        while (i<=mid && j<=high){
            if (A[i].getDate()<A[j].getDate()){
                B[k]=A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
                k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
    }else if(stype==1){
        while (i<=mid && j<=high){
            if (A[i].getIp()<A[j].getIp()){
                B[k]=A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
                k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
    }else{
        while (i<=mid && j<=high){
            if (A[i].getLog()<A[j].getLog()){
                B[k]=A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
                k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
    }
}

void logSorts::mergeSplit(vector<log> &A, vector<log> &B, int low, int high, int stype){
  int mid;
  if ((high-low)<1){
    return;
  }
  mid=(high+low)/2;
  mergeSplit(A,B,low,mid,stype);
  mergeSplit(A,B,mid+1,high,stype);
  mergeArray(A,B,low,mid,high,stype);
  copyArray(A,B,low,high);
}

void logSorts::ordenaMerge(vector<log> &v,int stype){
  vector<log> aux(v.size());

  mergeSplit(v,aux,0,v.size()-1,stype);
}

int logSorts::busqBinaria(vector<log> &v, string n,int stype){
  int low=0, mid, high=v.size()-1;
    if(stype==0){
        while (low < high){
            mid=(low+high)/2;
            if (n==v[mid].getDate()){
                return mid;
            } else if (n<v[mid].getDate()){
                high=mid-1;
            } else if (n>v[mid].getDate()){
            low=mid+1;
            }
        }
    }else if(stype==1){
        while (low < high){
            mid=(low+high)/2;
            if (n==v[mid].getIp()){
                return mid;
            } else if (n<v[mid].getIp()){
                high=mid-1;
            } else if (n>v[mid].getIp()){
            low=mid+1;
            }
        }
    }else if(stype==2){
        while (low < high){
            mid=(low+high)/2;
            if (n==v[mid].getLog()){
                return mid;
            } else if (n<v[mid].getLog()){
                high=mid-1;
            } else if (n>v[mid].getLog()){
            low=mid+1;
            }
        }
    }
    return -1;
}


class logs{
    private:
        logSorts sorts;
        vector<log> list;
    public:
        logs();
        void add(string);
        void sort(int);
        string range(string, string,int);
        string toString();
        string toFile();
};

logs::logs(){

}

void logs::add(string l){
    list.push_back(l);
}

void logs::sort(int stype){
    sorts.ordenaMerge(list,stype);
}

string logs::range(string min, string max, int stype){
    int i=sorts.busqBinaria(list,min,stype);
    int j=sorts.busqBinaria(list,max,stype);
    stringstream aux;
    for(;i<=j;++i){
        aux<<list[i].toString();
    }
    return aux.str();
}

string logs::toString(){
    stringstream aux;
    for(unsigned i=0;i<list.size();i++){
        aux<<list[i].toString();
    }
    return aux.str();
}

string logs::toFile(){
    stringstream aux;
    for(unsigned i=0;i<list.size();i++){
        aux<<list[i].toFile();
    }
    return aux.str();
}





#endif
