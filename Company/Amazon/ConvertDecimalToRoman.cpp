#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 

// Converting Decimal Number lying between 1 to 3999 to Roman Numerals

// https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/

// SYMBOL       VALUE
// I             1
// IV            4
// V             5
// IX            9
// X             10
// XL            40
// L             50
// XC            90
// C             100
// CD            400
// D             500
// CM            900 
// M             1000       

void convertNum(int number){
    int i=12;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int temp=0;
    while(number>0){
        temp=number/num[i];
        number=number%num[i];
        while(temp>0){
            cout<<sym[i];
            temp--;
        }
        i--;
    }
}

// Driver Code
int main()
{
    int number=3459;
    convertNum(number);
    return 0;
}



