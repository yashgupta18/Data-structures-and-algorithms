#include<iostream>
#include<vector>
using namespace std;

    void findNumber(int sum,int digits){
    if(sum==0){
    	if(digits>0) {
    		cout<<"Not possible";
    		return;
    	}
    }else if(sum>9*digits){
    	cout<<"Not possible";
    	return;	
    } 

  	int res[digits];
  	for (int i = 0; i < digits; ++i)
  	{
  		if(sum>=9){
  			res[i]=9;
  			sum=sum-9;
  		}else{
  			res[i]=sum;
  			sum=0;
  		}
  	}
	
	cout << "Largest number is "; 
    for (int i=0; i<digits; i++) 
        cout << res[i]; 
	return;
}

int main(){
	int sum=55;
	int digits=9;
    findNumber(sum,digits); 
	return 0;
}