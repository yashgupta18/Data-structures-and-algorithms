#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int tc;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        if(k==0){
            cout<<n<<endl;
        }else{
            cout<<n%k<<endl;
        }
    }
    return 0;
}
