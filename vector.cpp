// #include "stdafx.h"
#include <iostream>

#include <vector>
// #include<bits/stdc++.h>
using namespace std;

int main()
{
	// int a[4]={ {6,8}, {1,9}, {2,4}, {4,7} };
    // int a[4]={4,7,3,7};
    // vector<int> intList(a,a+4);

    vector<int> intList;

    intList.push_back(8);
    intList.push_back(67);
    intList.push_back(34);
    intList.push_back(69);
    // cout<<intList.end()<<endl;
    // cout<<intList.back()<<endl;

    //iterator
    // vector<int>::iterator it= intList.begin();
    // cout<<*(it)<<endl;

    // for (int i = 0; i < intList.size(); ++i)
    // {
        
    //     cout<<intList[i]<<endl;
    // }

    for(auto it:intList){
        cout<<it<<endl;
    }

    // int n = 2; 
    // int m = 7; 
  
    // // Create a vector containing n 
    // //vectors of size m.  
    // vector<vector<int> > vec( n , vector<int> (m, 0));  
  
    // for (int i = 0; i < n; i++) { 
    //     for (int j = 0; j < m; j++){ 
    //         cout<< vec[i][j]<< " "; 
    //     } 
    //     cout<< "\n"; 
    // } 
  
return 0; 
} 