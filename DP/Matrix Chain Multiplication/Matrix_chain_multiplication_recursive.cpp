#include<iostream>
using namespace std;


int matrix_chain_mltiplication(int arr[], int i, int j){
	//base condition
	// it means arr only has one element or empty arr
	if(i>=j){
		return 0;
	}

	int min=INT_MAX;
	int temp;
	for (int k = i; k <=j-1 ; ++k)
	{
		// temp= sum of multiplying-- c1=A*b , c2= C*D, c3=(A*B) + (C*D)
		temp = matrix_chain_mltiplication(arr,i,k) + matrix_chain_mltiplication(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
		//if new temp value is less than old min than update min
		if(temp<min){
			min=temp;
		}
	}
	return min;
}


int main(){
	int arr[]={ 40, 20, 30, 10, 30 }; 
	int n= sizeof(arr)/sizeof(arr[0]);

	//OUTPUT Explaination
	// There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  	// Let the input 4 matrices be A, B, C and D.  The minimum number of 
  	// multiplications are obtained by putting parenthesis in following way
  	// (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
	cout<<matrix_chain_mltiplication(arr,1,n-1);
}