#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 


//make 2 arr to store max of left and right of current index

int sortCompare(string a, string b){
    string ab=a.append(b);
    string ba=b.append(a);
    if(ab.compare(ba)>0) return 1;
    else return 0;
}

void largestNumber(vector<string> arr){
    sort(arr.begin(),arr.end(), sortCompare);
    string ans="";
    for (int i = 0; i < arr.size(); ++i)
    {
        ans=ans.append(arr[i]);
    }
    cout<<ans;
    return;
}

// Driver Code
int main()
{
   vector<string> arr;
    // output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    largestNumber(arr);
    return 0;
}



