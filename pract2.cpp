#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
   int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin>>matrix[i];
    }

    cout<<matrix[0].length();
   string sol[n][m];
    // for(int i=0; i<n; i++){
    //     int l=matrix[i].length();
    //     for(int j=0; j<l; j++){
    //         sol[i][j]=matrix[j];
    //     }
    // }
    
    for (int i=0; i<n; i++) 
    { 
         string newString=matrix[i];
         int l=matrix[i].length();
        for (int j=0; j<l; j++) 
        { 
            sol[i][j]=newString[j];
            // cout<<newString[i]<<" ";
        } 
        cout<<endl;
    } 


    for (int i = 0; i < n; ++i)
    {
       /* code */
      for (int j = 0; j < n; ++j)
      {
         /* code */
         cout<<sol[i][j]<<" ";
      }
      cout<<endl;
    }











 string sol[n][m];
    for (int i=0; i<n; i++) 
    { 
         string newString=matrix[i];
         int l=matrix[i].length();
        for (int j=0; j<l; j++) 
        { 
            sol[i][j]=newString[j];
            // cout<<newString[i]<<" ";
        } 
        cout<<endl;
    } 


    

    return 0;
}