#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
#define MUL(a,b) a*b
using namespace std; 

int main() 
{ 
    // int a=3, b=2;
    // cout<<MUL(a+2, b);

    static int a[]={0,1,2,3,4};
    static int *p[]={a, a+1, a+2, a+3, a+4};

    // for (int i = 0; i < 5; ++i)
    // {
    //      code 
    //     cout<<*p[i]<<" ";
    // }
    // cout<<endl;

    int **ptr=p;
    **ptr++;

    cout<<**ptr<<" ";
    cout<<endl;
    cout<<ptr-p<<" "<<*ptr-a<<" "<<**ptr;
    **(++ptr);
    cout<<endl;
    cout<<ptr-p<<" "<<*ptr-a<<" "<<**ptr;
    ++(**ptr);
    cout<<endl;
    cout<<ptr-p<<" "<<*ptr-a<<" "<<**ptr;
    return 0; 
} 







