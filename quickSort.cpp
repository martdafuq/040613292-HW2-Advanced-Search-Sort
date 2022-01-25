#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int partition(int A[], int begin, int end){
	int pivot = A[end];
	//cout << "\n pivot is " << A[end-1] << endl;
	int i = (begin-1);
	for(int j=begin; j<=end-1; j++){
		if(A[j]<pivot){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[end]);
	return (i+1);
}

void quickSort(int A[], int begin, int end){
	int p;
	if(end>begin){
		p = partition(A, begin, end);
		quickSort(A, begin, p-1);
		quickSort(A, p+1, end);
	}
}

int median(int A[], int begin, int end){
	int first = begin;
	int last = end;
	int mid = (begin + end) / 2;
	cout << "\nfirst " << A[begin] << endl;
	cout << "last " << A[end-1] << endl;
	cout << "mid " << A[mid] << endl;
	if((A[mid]<A[begin] && A[begin]<A[end-1]) || (A[mid]>A[begin] && A[begin]>A[end-1])){
		cout << "condition 1 move first element to last" << endl;
		swap(A[begin],A[end-1]);
		for(int i=0; i<end; i++){
		cout << A[i] << " ";
		}
	}
	else if((A[begin]<A[mid] && A[mid]<A[end-1]) || (A[begin]>A[mid] && A[mid]>A[end-1])){
		cout << "condition 2 move mid element to last" << endl;
		swap(A[mid],A[end-1]);
		for(int i=0; i<end; i++){
		cout << A[i] << " ";
		}
	}
	else{
		cout << "condition 3 last element is median of three" << endl;
		for(int i=0; i<end; i++){
		cout << A[i] << " ";
		}
	}
	quickSort(A, first, last);
}

int main(int argc, char** argv) {
	int n=20;
	int k=0;
	int arr[n];
	srand(time(0));
	cout << "Array is\n";
	for(int i=0; i<n; i++){
		arr[i]=rand() %100+1;
		cout << arr[i] << " ";
	}
	
	median(arr, 0, n);
	//quickSort(arr, 0, n);
	
	cout << "\nSorted array is \n";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
