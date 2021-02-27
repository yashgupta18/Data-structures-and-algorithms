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


int divide(int dividend, int divisor) {
    int sign=1;
    int signD=1;
    int divid=dividend;
    int divis=divisor;
    if(divid<0){
    	sign=-1;
    	divid*=-1;
    }
    if(divis<0){
    	signD=-1;
    	divis*=-1;
    }
    int q=0;
    if(divis==1){
    	double result=divid*sign*signD;
    	if(result>INT_MAX || result<INT_MIN){
    		return INT_MAX;
    	}

    	return result;
    }

    while(divid>=divis){
    	divid=divid-divis;
    	q++;
    }
    return q*signD*sign;
}

int main(){
	cout<<divide(1, 1);
	return 0;
}














