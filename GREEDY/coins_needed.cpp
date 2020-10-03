#include<iostream>
#include<vector>
using namespace std;


void findCoins(int money[], int sum, int n){
	sort(money, money+n);
	int pointr=n-1;
	int numofcoins=0;
	vector<int> res;
	while(sum>=0){
		if(sum==0) break;

		if(money[pointr]<=sum){
			numofcoins++;
			res.push_back(money[pointr]);
			sum=sum-money[pointr];
		}

		else{
			pointr--;
		}
	}
	cout<<"Num of coins="<<numofcoins<<endl;
	cout<<"Coins:";
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<"  ";
	}
}

int main() 
{ 
	int sum=11;
    int money[] =  { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(money) / sizeof(money[0]); 
    findCoins(money, sum, n); 
    return 0; 
} 