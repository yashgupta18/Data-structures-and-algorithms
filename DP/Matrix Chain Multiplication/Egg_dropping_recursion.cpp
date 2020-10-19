#include<iostream>

using namespace std;


int solve(int eggs, int floors){
	if(eggs==1) return floors;
	if(floors==0 || floors==1) return floors;

	int mn=INT_MAX;

	for (int k = 1; k <= floors; ++k)
	{
		//finds maximum number of attempts out of each case to give worst case;
		int temp = 1 + max( 
							// **If egg breaks** 
							//k-1 means decrease no if floors by 1
							solve(eggs-1, k-1),

							// **If egg doesnt break**
							//floors-k means no of floors to check(remaining) above is (total floors - current floor)
							solve(eggs, floors-k));

		//select min number of attempts out of all worst cases. it means best of all worst cases.
		mn=min(mn, temp);
	}
	return mn;
}

int main(){
	int eggs=2;
	int floors=10;
	

	cout<<endl<<"Minimum number of trials in worst case is: "<<solve(eggs, floors)<<endl;
}




