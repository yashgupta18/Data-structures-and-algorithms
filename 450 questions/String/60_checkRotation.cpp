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


bool areRotations(string str1, string str2){
	string temp= str1+str1;
	int j=0;
	if(temp.find(str2) != string::npos){
		return true;
	}
	return false;
}


int main()
{

//Q. A Program to check if strings are rotations of each other or not
 
   string str1 = "ABCD", str2 = "BCDA"; 
   if (areRotations(str1, str2)) 
     printf("Strings are rotations of each other"); 
   else
      printf("Strings are not rotations of each other"); 
   return 0; 
} 
