#include <iostream> 
#include <sstream>
#include <vector>
#include <string.h>

using namespace std; 


int rotateWords(string words,int k)
{
    int n=words.length();
    vector<string> rotateWords;
    vector<string> actualWord;
    
    stringstream check1(words); 
    string intermediate; 
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) 
    { 
        rotateWords.push_back(intermediate); 
        actualWord.push_back(intermediate); 
    } 

    int count=0;
    for(int i=1;i<=k;i++)
    {   //using this loop for ratotaion of character in each word
       for (int j = 0; j < rotateWords.size(); j++) 
       {
          //rotating character of each word
          rotateWords[j]= rotateWords[j].substr(1)+rotateWords[j].at(0);
          // count++;
       }
    }

    for (int i = 0; i < rotateWords.size(); i++) 
    {
        //using this loop for actual word
        for (int j = 0; j < actualWord.size(); j++) 
        {
           //comparing rotated words with actual words
           if(rotateWords[i]==actualWord[j])
            //increment the counter if found same word after rotation
            count++;
        }
    }

    return count;


}

int main() 
{
        cout<<rotateWords("adaada",3)<<endl;//1
        cout<<rotateWords("loHel endFri", 3)<<endl;//0
        cout<<rotateWords("Hello dFrien", 5)<<endl;//1

        return 0;
    }