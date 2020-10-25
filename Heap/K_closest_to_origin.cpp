#include <iostream>
#include <queue> 
#include <unordered_map> 
#include <math.h> 
using namespace std; 
typedef pair<int, pair<int, int> > ppi;

void k_closest_to_origin(int x[], int y[], int n, int k){
   priority_queue<ppi> max_heap;
   // priority_queue<pair<int, pair<int, int> >,vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > min_heap;   

   for (int i = 0; i < n; ++i)
   {
      int X= pow((x[i]-0), 2);
         int Y= pow((y[i]-0), 2);
         float eucl_dist= sqrt(X+Y);
         
         //push eucl dist and pair of coordinates 
         max_heap.push(make_pair(eucl_dist,make_pair(x[i],y[i])));
         if(max_heap.size()>k){
            max_heap.pop();
         }
   }

   cout<<"X"<<'\t'<<"Y"<<"\t"<<"Distance"<<endl;
   while(!max_heap.empty()){
      cout<<max_heap.top().second.first<<"\t"<<max_heap.top().second.second<<"\t"<<max_heap.top().first<<endl;
      max_heap.pop();
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