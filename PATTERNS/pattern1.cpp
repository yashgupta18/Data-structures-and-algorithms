#include <iostream> 
using namespace std; 
  
void halftriangleUp(int n){
	for (int i = 1; i <=5; ++i)
   {
      for (int j = 1; j <=i ; ++j)
      {
      	cout<<"*"<<" ";
      }
      cout<<endl;
   }
  cout<<endl;
  return;
}

void halftriangleDown(int n){
	for (int i = 5; i >=1; --i)
   {
      for (int j = i; j>= 1 ; --j)
      {
      	cout<<"*"<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
   return;
}

void halftrianglerightup(int n){
	for (int i = 1; i <=n; ++i)
   	{
      	for (int j = n-i; j>0 ; --j)
      	{
      		cout<<" ";
      	}
      	
      	for (int k = 1; k <= i; ++k)
      	{
      		cout<<"*";
      	}

    	cout<<endl;

   	}
   	cout<<endl;
   	return;
}

void halftrianglerightdown(int n){
	for (int i = n; i >=1; --i)
   	{
      	for (int j = n-i; j>0 ; --j)
      	{
      		cout<<" ";
      	}
      	
      	for (int k = i; k >= 1; --k)
      	{
      		cout<<"*";
      	}

    	cout<<endl;

   	}
   	return;
}

// Driver Code 
int main() 
{

   int n=5;
   halftriangleUp(n);
   halftriangleDown(n);
   halftrianglerightup(n);
   halftrianglerightdown(n);

   return 0;
}