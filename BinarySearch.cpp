#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

int binarySearch(int A[], int low, int high, int k){
	if(high>=low){
		int mid=low+(high-low)/2;
		if(A[mid]==k){
			return mid;
		}
		if(A[mid]>k){
			return binarySearch(A, low, mid-1, k);
		}
		return binarySearch(A, mid+1, high, k);
	}
	return -1;
}

int main(int argc, char** argv) {
	int n=20;
	int k=0;
	int arr[n];
	srand(time(0));
	for(int i=0; i<n; i++){
		arr[i]=rand() %100+1;
	}
	
	sort(arr, arr + n);
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl << "Input Number you want to search " << endl;
	cin >> k;
	int result = binarySearch(arr, 0, 20, k);
	if(result != -1)
		cout << "Element found at index " << result;
	else
		cout << "Element not found.";
	return 0;
}
