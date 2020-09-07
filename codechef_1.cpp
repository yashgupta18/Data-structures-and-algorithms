// #include<bits/stdc++.h>
// using namespace std;
// #define ll long
#include <iostream>
using namespace std;
// #define ll long
int main(){
  int T;
  scanf("%d",&T);
  // cin>>T;
  while(T--)
  {
    int T,N,K,w[N];
    scanf("%d%d",&N,&K);
  // scanf("",&K);
  // cin>>N>>K;
    for (int i =0 ; i < N; ++i)
    {
    scanf("%d",&w[i]);
    // cin>>w[i];
    }
    
    if(N==0){
      printf("-1");
    // cout<<-1;
    }

    int round=0;
    int sum=0;
  // while(j>0){
    for (int i = 0; i < N; ++i)
    {
    sum=sum+w[i];
    if (w[i]>K)
    {
      round=-1;
      break;
    }

    else if (w[i]<=K)
    {
      sum=sum+w[i];
      if (sum>=K)
      {
        round=round+1;
        sum=0;
        if (i==N)
      {
        round=round+1;
      }
      }
    }
  }
  cout<<"\n";
  cout<<round;
}
  return 0;
}

// Input
// 4
// 1 1 
// 2
// 2 4
// 1 1
// 3 6
// 3 4 2
// 3 6
// 3 4 3
