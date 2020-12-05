#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
// #define V 5
using namespace std;



int main(){
	int a[5]={1,2,3,4,5};
	int i,j,k=1,m;
	i=++a[1];
	j=a[1]++;
	m=a[i++];

	cout<<i<<j<<m;
}

// int Coindeterminer(int coinsArr[],int num) 
// { 
// 	 int n=sizeof(coinsArr)/sizeof(coinsArr[0]); 
// 	 if(num<5) return num; 
// 	 int count=num/11; 
// 	if((num%11)%2==0){ 
// 	 	return count+2; 
// 	}
// 	else{
// 	 	return count+1; 	 	}
// 	}

// int main(){
// 	int coinsArr[]={1,5,7,9,11};
// 	int num=22;
// 	cout<<Coindeterminer(coinsArr, num);
// }