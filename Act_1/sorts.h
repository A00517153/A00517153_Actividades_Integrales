#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include "logs.h"
using namespace std;


template <class T>
class Sorts{
	private:
		void swap(vector<T>&,int,int);
		void copyArray(vector<T>&,vector<T>&,int,int);
    bool compareDate(vector<T>&,int,int,int);
    bool compareIp(vector<T>&,int,int,int);
		void mergeArray(vector<T>&,vector<T>&,int,int,int,int);
		void mergeSplit(vector<T>&,vector<T>&,int,int,int);
    
	public:
		void mergeSort(vector<T>&,int);
		
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j){
	T aux=v[i];
	v[i]=v[j];
	v[j]=aux;
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high){
	for (int i=low;i<=high;i++){
		A[i]=B[i];
	}
}

template <class T>
bool Sorts<T>::compareDate(vector<T> &A, int i, int j, int z){
  if(z<4){
    if(A[i].getDate(z)!=A[j].getDate(z)){
      return (A[i].getDate(z)<A[j].getDate(z))? true : false;
    } else {
      return compareDate(A,i,j,z+1);
    }
  } else {return false;}
}

template <class T>
bool Sorts<T>::compareIp(vector<T> &A, int i, int j, int z){
  if(z<4){
    if(A[i].getIp(z)!=A[j].getIp(z)){
      return (A[i].getIp(z)<A[j].getIp(z))? true : false;
    } else {
      return compareIp(A,i,j,z+1);
    }
  } else {return false;}
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high, int sortType){
	int i=low,j=mid+1,k=low;
  switch(sortType){
    case 0:
      while (i<=mid && j<=high){
        if (compareDate(A,i,j,0)){
          B[k]=A[i];
          i++;
        } else {
          B[k]=A[j];
          j++;
        }
        k++;
      }
      if (i>mid){
        for (;j<=high;j++){
          B[k++]=A[j];
        }
      } else {
        for (;i<=mid;i++){
          B[k++]=A[i];
        }
      }
      break;
    case 1: 
      while (i<=mid && j<=high){
        if (compareIp(A,i,j,0)){
          B[k]=A[i];
          i++;
        } else {
          B[k]=A[j];
          j++;
        }
        k++;
      }
      if (i>mid){
        for (;j<=high;j++){
          B[k++]=A[j];
        }
      } else {
        for (;i<=mid;i++){
          B[k++]=A[i];
        }
      }
      break;
    default: 
      while (i<=mid && j<=high){
        if (A[i].getLogText()<A[j].getLogText()){
          B[k]=A[i];
          i++;
        } else {
          B[k]=A[j];
          j++;
        }
        k++;
      }
      if (i>mid){
        for (;j<=high;j++){
          B[k++]=A[j];
        }
      } else {
        for (;i<=mid;i++){
          B[k++]=A[i];
        }
      }
  }
}



template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high,int sortType){
	if((high-low)<1){
		return;
	}
	int mid=(high+low)/2;
	mergeSplit(A,B,low,mid,sortType);
	mergeSplit(A,B,mid+1,high,sortType);
	mergeArray(A,B,low,mid,high,sortType);
	copyArray(A,B,low,high);
}

template <class T>
void Sorts<T>::mergeSort(vector<T> &v,int sortType){
	vector<T> aux(v.size());
	mergeSplit(v,aux,0,v.size()-1,sortType);
}


#endif
