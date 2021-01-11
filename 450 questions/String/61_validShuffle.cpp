#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;


bool validShuffleCheck(string str1, string str2, string combo){
	int i=0, j=0, k=0;
	int m=str1.length(), n=str2.length(), p=combo.length();
	while(k!=p){
		if(i<m && str1[i]==combo[k]){
			i++;
		}else if(j<n && str2[j]==combo[k]){
			j++;
		}
		else{
			return false;
		}
		k++;
	}
	return true;
}


int main()
{

 // Check if a string is a valid shuffle of two other strings
   string str1 = "XY", str2 = "12"; 
   //  Y12X is not a valid shuffle as X&Y are not in same order
   string combo= "X12Y";
   if (validShuffleCheck(str1, str2, combo)) 
     printf("Strings are valid shuffle of each other"); 
   else
      printf("Strings are not valid shuffle of each other"); 
   return 0; 
} 
