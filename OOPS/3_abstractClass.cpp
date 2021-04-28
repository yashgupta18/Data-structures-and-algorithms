#include <iostream>  
using namespace std;  

class AbstractEmployee{

  virtual void askForPromotion()=0;
};

//Employee class uses AbstractEmployee so it needs to provide implementation of virtualFn
class Employee:AbstractEmployee {  
  private:
    string Name; //data member (also instance variable)      
    string Company; //data member(also instance variable)  
    int Age;  
   public:  

      void setName(string name){
        Name=name;
      }

      string getName(){
        return Name;
      }

      void setCompany(string company){
        Company=company;
      }

      string getCompany(){
        return Company;
      }

      void setAge(int age){
        Age=age;
      }

      int getAge(){
        return Age;
      }

      Employee(string name, string company, int age)    
      {    
          Name=name;
          Company=company;
          Age=age;
      }  
       
     void display()    
      {    
          cout<<Name<<"  "<<Company<<"  "<<Age<<endl;    
      }  

      //provide implementation of virtual fn 
      void askForPromotion(){
        if(Age>30){
          cout<<"You are Promoted"<<endl;
        }else{
          cout<<"No Promotion"<<endl;
        }
      }  
};  

int main(void) {  
    Employee e1 =Employee("Yash", "Google", 22); //creating an object of Employee   
    Employee e2=Employee("Varad", "optifcal", 41); //creating an object of Employee  
    e2.askForPromotion();
    return 0;  
}  