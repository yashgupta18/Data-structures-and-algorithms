#include <iostream> 
using namespace std; 
  
class A { 
public:
    static int x; 
    A(){
        // x++;
    }
    ~A(){
        // x--;
    }

    //to count only heap variables we use operator overloading
    void* operator new(size_t sz){
        x++;
    }

    // void* operator delete(size_t sp){
    //     x--;
    // }

}; 
  
int A::x=0;

int main() 
{ 
    A a,b; //local variables in HEAP
    A c,d,e;


    //DYNAMIC-> created in HEAP
    //using malloc
    // A* ptr=(A*)malloc(sizeof(A)); //doesn't invoke constructor

    //
    A* ptr=new A();
    A* ptr2=new A();
    
    //delete OBJECT
    // free(ptr); // doesn't invoke destructor
    // delete ptr; // invokes destructor



    cout<<A::x<<endl;

    return 0;
} 


