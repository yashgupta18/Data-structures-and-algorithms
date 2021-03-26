#include <iostream>
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
using namespace std; 

class address{
    int x,y;
public:
    void call(int &a, int &b){
        x=a;
        a=a+3*2;
        y=b;
        cout<<a<<" "<<b;
    }
};

int main(){
	
   int x=32;
   int y=x;
   address we;
   we.call(x,y);
   
    return 0;



}












