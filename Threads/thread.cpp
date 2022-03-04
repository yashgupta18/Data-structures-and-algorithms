#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;


ull oddSum=0;
ull eveSum=0;

void findEven(ull start, ull end){
    for (ull i = start; i < end; ++i)
    {
        /* code */
        if((i & 1)==0){
            oddSum+=i;
        }
    }
}   

void findOdd(ull start, ull end){
    for (ull i = start; i < end; ++i)
    {
        /* code */
        if((i & 1)==1){
            eveSum+=i;
        }
    }
}   

int main()
{

    
    ull start=0, endd=1900000000;
    // clock_t begin = clock();
    std::thread t1(findOdd, start, end);
    std::thread t2(findEven, start, end);

    t1.join();
    t2.join();

    // findOdd(start, endd);
    // findEven(start, endd);

    // #ifndef ONLINE_JUDGE 
    //   clock_t end = clock();
    //   cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // #endif 
    cout<<oddSum<<endl;
    cout<<eveSum<<endl;
    return 0;
    
}


 