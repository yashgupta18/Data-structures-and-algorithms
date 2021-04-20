#include <iostream>  
using namespace std;  
class Employee {  
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
};  
int main(void) {  
    Employee e1 =Employee("Yash", "Google", 22); //creating an object of Employee   
    e1.setAge(30);
    Employee e2=Employee("Varad", "optifcal", 21); //creating an object of Employee  
    e1.display();    
    e2.display();    

    cout<<"GETTERS AND SETTERS"<<endl;
    cout<<e1.getName()<<" is "<<e1.getAge()<<" yrs old"<<endl;
    return 0;  
}  