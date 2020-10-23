#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std; 
  
// Driver Code 
int main() 
{ 
   int i=10;
   int *p=&i;

   // cout<<i<<endl;
   // cout<<*&i<<endl;
   // cout<<*p<<endl;
   // cout<<&*p<<endl;
   // cout<<p<<endl;
   // cout<<*&p<<endl;
   // // cout<<*i;
   // cout<<&i<<endl;
   // cout<<&p<<endl;

   int arr[3]={8,9,10};
   int *arrptr=arr;
   cout<<*arr<<endl;
   cout<<&arrptr<<endl;
   cout<<(*arr)++<<endl;


   return 0;
}