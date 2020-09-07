#include <iostream>
#include <vector>
using namespace std;


int bits(int arr[][],int x1,int y1,int x2,int y2){
    for (int i = x1; i < x2; ++i)
    {
        for (int j = y1; j < y2; ++i){
            if(arr[i][j]==1){
                arr[i][j]=0;
            }
            arr[i][j]=1;
         }   
    }
}

int main() 
{ 
    int T,N,M,Q ,arr[N][M],x1,y1,x2,y2;
    vector <int> v;
    arr[M][N];
    cin>>T;
   
        cin>>N;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin>>arr[i][j];
            }
        }

        for (int i = 0; i < N; ++i){
             for (int j = 0; j < M; ++j){
                cin<<i<<j;
             }
            
        }
        // cout<<v[2];
        cin>>Q;

         for (int i = 0; i < Q; ++i){
            for (int j = 0; j < 4; ++j)
            {
               cin<<x1<< y1<< x2<<y2;
               bits(arr[N][M],x1,y1,x2,y2);
            }
        }
        // cout<<count;
        // bits(v,N);
        
    
  
    return 0; 
} 