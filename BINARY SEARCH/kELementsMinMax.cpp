#include<iostream>
#include<vector>
#include<queue>

using namespace std;



// Place k elements such that minimum distance is maximized

// Given an array representing n positions along a straight line. Find k (where k <= n) elements from the array such that the maximum distance between any two (consecutive points among the k points) is maximized.

// https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/




int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int t;
    cout<<"Enter test case"<<endl;
    cin>>t;
    while(t>0){
        // solve();
        int N, X;
        cout<<"Enter N & X"<<endl;
        cin>>N>>X;
        int arr[N];
        for(int i=0; i<N; i++){
        	cout<<"Enter"<<i<<endl;
            cin>>arr[i];
        }
        cout<<"Arr";
        int res, i=0;
        vector<int> ans;
        priority_queue<int> pq;
        while(X<N){
            while(i<N && X-i>0){
                pq.push(arr[i]);
                i++;
            }
            
            if(pq.empty()) return -1;
            X+=pq.top();
            ans.push_back(pq.top());
            pq.pop();
            res++;
        }
        
        cout<<res<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }

        cout<<endl;
        t--;
    }
        return 0;
}