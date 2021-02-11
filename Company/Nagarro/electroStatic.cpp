

#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
using namespace std; 


int elctro(int input1[], char* input2){
  int sum=0;
  for(int i=0;i<input3;i++) {
   if(input2[i]=='P') {
    sum=sum+input1[i];
   }
   else if(input2[i]=='N') {
    sum=sum-input1[i];
   }
  }

  return abs((sum*100));

}