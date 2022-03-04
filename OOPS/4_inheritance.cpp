#include <iostream>  
using namespace std;  

class AbstractEmployee{

  virtual void askForPromotion()=0;
};


class Employee:AbstractEmployee {  
  private:    
    string Company; //data member(also instance variable)  
    int Age;  
protected:
  //accessible in derived class
    string Name; //data member (also instance variable)      

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

//Developer is inheriting Employee class
//using publc before Employee allows us to access virtual fn in Developer class 
class Developer:public Employee{
public:
    string favProgLang;
    //pass properties of Employee class to it's constructor
    Developer(string name, string company, int age, string favLang):Employee(name, company, age){
        favProgLang=favLang;
    }

    void showRes(){
        cout<<Name<<" "<<getAge()<<" "<<getCompany()<<" "<<favProgLang<<endl;
    }
};

class Teacher: public Employee{
public:
    string Subject;
    //call Employee constructor for common variables and own Constructor Teacher for this class handles it's own variable
    Teacher(string name, string company, int age, string subject):Employee(name, company, age){
        Subject=subject;
    }
    void preparedLesson(){
        cout<<Name<<" "<<Subject<<endl;
    }
};


int main(void) {  
    Employee e1 =Employee("Yash", "Google", 22); //creating an object of Employee   
    Employee e2=Employee("Varad", "optifcal", 41); //creating an object of Employee  
    
    Developer d=Developer("Ishan", "vimana", 23, "Python");
    d.showRes();
    d.askForPromotion();

    Teacher t=Teacher("rahul", "DAV", 40, "English");
    t.preparedLesson();
    t.askForPromotion();
    return 0;  
}  