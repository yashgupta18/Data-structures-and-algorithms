#include <cmath> 
#include <iostream> 
#include <vector> 
#include<sstream>

using namespace std; 
  
int secondHighest(string s) {
        stringstream ss;    
        ss << s; 
        string temp; 
        int found; 
        int max1,max2;
        while (!ss.eof()) { 

            /* extracting word by word from stream */
            ss >> temp; 

            /* Checking the given word is integer or not */
            if (stringstream(temp) >> found){
                cout<<found<<endl;
                if(found>max1){
                    max2=max1;
                    max1=found;
                }
            } 
                
            /* To save from space at the end of string */
            temp = ""; 
        }
        // if()
        return max2;
    }
  
// Driven program to test 
int main() 
{ 
    cout<<secondHighest("hell 12dsj34");
  
    // cout<<ans;
    return 0; 
} 