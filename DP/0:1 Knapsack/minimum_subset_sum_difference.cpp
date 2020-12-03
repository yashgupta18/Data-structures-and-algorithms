#include<iostream>
#include<vector>
using namespace std;


void min_subset_sum_diff(int arr[], int n) 
{ 
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum=sum+arr[i];
    }
    int i, j; 
    int t[n + 1][(sum/2)+1]; 
    
    for (int i = 0; i <= n; i++) 
        t[i][0] = true; 

    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i < (sum/2)+1; i++) 
        t[0][i] = false; 
    //for understanding
    for (i = 1; i <= n; i++) { 
        for (j = 1; j < (sum/2)+1; j++) { 
            t[i][j]=0;
        } 
    }

    cout<<"Before DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j < (sum/2)+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    
    for (int i = 1; i < n+1; i++) { 
        for (int j = 1; j < (sum/2)+1; j++) { 
            if(arr[i-1]<=j){
                //first check if block can be filled without current no. OR it with if it can be filled with current no and remaining sum be filled from above
                t[i][j]=( t[i-1][j-arr[i-1]] || t[i-1][j] );
            }
            else{
                //just use the above value from table
                t[i][j]= t[i-1][j];
            }

        } 
    }
    cout<<endl;

    // for understanding
    cout<<"After DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j < (sum/2)+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    int diff=INT_MAX;
    for (int i = (sum/2); i >=0; --i)
    {
        //check if a subset for a particular sum exists which is closest to sum/2
       if(t[n][i]==1){
            diff=sum-2*i;
            break;
        }
    }

    cout<<"Minimum Difference of 2 subsets sum =" <<diff;

    //For detailed explaination use vector to insert the tru element index. choose the max in vector.max is left part sum.
    // vector<int> v;

    // for (int i = 0; i < (sum/2)+1; ++i)
    // {   
    //     // cout<<t[n][i];
    //     if(t[n][i]==1){
    //         v.push_back(i);
    //     }
    // }

    // cout<<"Elements in vector"<<endl;
    // for (int i = 0; i < v.size(); ++i)
    // {   
    //     cout<<v[i]<<" ";

    // }

    // int first_partition_sum=*max_element(v.begin(), v.end());
    // cout<<endl<<"Max in vector: "<<first_partition_sum<<endl;
    // int second_partition_sum=sum - first_partition_sum;
    // int minimum_diff= abs(second_partition_sum - first_partition_sum);
    // cout<<"Minimum Difference of 2 subsets sum =" << minimum_diff<<endl;

    return;
}

int main(){
    int arr[] ={ 1,6,5,11 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    min_subset_sum_diff(arr,n);
}