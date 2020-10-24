#include <iostream>
#include <queue> 
#include <unordered_map> 
#include <math.h> 
using namespace std; 
typedef pair<int, pair<int, int> > ppi;

void k_closest_to_origin(int x[], int y[], int n, int k){
   priority_queue<ppi,vector<ppi>,greater<ppi> > min_heap;

   // priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > min_heap;   

   for (int i = 0; i < n; ++i)
   {
      int X= pow((x[i]-0), 2);
         int Y= pow((y[i]-0), 2);
         float eucl_dist= sqrt(X+Y);
         // min_heap.push(make_pair(eucl_dist,x[i]));
         min_heap.push(make_pair(eucl_dist,make_pair(x[i],y[i])));
         if(min_heap.size()>k){
            min_heap.pop();
         }
   }

   cout<<"X"<<'\t'<<"Y"<<endl;
   while(!min_heap.empty()){
      cout<<min_heap.top().second.first<<"\t"<<min_heap.top().second.second<<endl;
      min_heap.pop();
   }
   return;
}


int main(){

   // x coordinate of points 
    int x[] = { 1, -2 , 5, 0}; 
    // y coordinate of points 
    int y[] = { 3, 2, 8, 1};

   int n=sizeof(x)/sizeof(x[0]);
   int k=2;
   k_closest_to_origin(x,y,n,k);

   return 0;
}