#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A={21,2,53,3};
    cout << A[1] << endl;
    cout<<"helllo yash"<<endl;
    sort(A.begin(), A.end());

    bool present=binary_search(A.begin(), A.end(), 3); //true
    present=binary_search(A.begin(),A.end(), 4); //false
    // cout<< present;
    A.push_back(100);
    present=binary_search(A.begin(),A.end(), 100); //true

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);

    A.push_back(123);
    //21,2,53,3,100,100,100,100,1000,123

    vector<int>::iterator it=lower_bound(A.begin(), A.end(), 100); //>=
    vector<int>::iterator it2=upper_bound(A.begin(), A.end(), 100); //>

    cout<< *it<< " " << *it2 << endl;
    cout << it2-it << endl; //4

    return 0;
} 