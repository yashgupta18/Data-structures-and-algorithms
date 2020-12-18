#include<iostream> 
using namespace std; 
  
class A 
{ 
public:
   void fun(){
   	cout<<"In class A";
   }
}; 

class B: public virtual A
{ 
    
}; 

class C: public virtual A
{
	
};

class D:public B, public C{

};

int main(void) 
{ 
    D object; 
    object.fun();
    return 0; 
} 