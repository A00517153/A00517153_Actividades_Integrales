#ifndef SORTS_H
#define SORTS_H

#include <vector>

using namespace std;

template <class T>
class Sorts{
	private:
		void swap(vector<T>&,int,int);
		void copyArray(vector<T>&,vector<T>&,int,int);
		void mergeArray(vector<T>&,vector<T>&,int,int,int);
		void mergeSplit(vector<T>&,vector<T>&;int,int);
	public:
		void mergeSort(vector<T>&);
		
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
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high){
	int i=low,j=mid+1,k=low;
	
	while (i<=mid && j<=high){
		if (A[i]<A[j]){
			B[k]=A[i];
			i++;
		} else {
			B[k]=A[j];
			j++;
		}
		k++
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

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high){
	if((high-low)<1){
		return;
	}
	int mid=(high+low)/2;
	mergeSplit(A,B,low,mid);
	mergeSplit(A,B,mid+1,high);
	mergeArray(A,B,low,mid,high);
	copyArray(A,B,low,high);
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &v){
	vector<T> aux(v.size());
	mergeSplit(v,aux,0,v.size()-1);
}


#endif
