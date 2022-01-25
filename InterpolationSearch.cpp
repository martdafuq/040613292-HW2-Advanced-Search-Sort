#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int interpolationSearch(int A[],int low, int high, int k){
	int pos;
	if(low<=high && k>=A[low] && k<=A[high]){
		pos=low+(((double)(high-low)/(A[high]-A[low]))*(k-A[low]));
		if(A[pos]==k)
			return pos;
		if(A[pos]<k)
			return interpolationSearch(A, pos+1, high, k);
		if(A[pos]>k)
			return interpolationSearch(A, low, pos-1, k);
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
	int result = interpolationSearch(arr, 0, n-1, k);
	if(result != -1)
		cout << "Element found at index " << result;
	else
		cout << "Element not found.";
	return 0;
}
