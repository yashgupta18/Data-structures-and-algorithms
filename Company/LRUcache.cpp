#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <list> 
#include <iterator> 
#include<string>
using namespace std; 
// https://www.geeksforgeeks.org/lru-cache-implementation/
 
void addLRU(int num, unordered_map<int, list<int>::iterator> &mp, list<int> &li){
    int maxSize=4;
    if(mp.find(num)==mp.end()){
        if(li.size()==maxSize){
            int last=li.back();
            li.pop_back();
            mp.erase(last);
        }
    }
    else{
        li.erase(mp[num]);
    }
    li.push_front(num);
    mp[num]=li.begin();
}

void display(list<int> li,unordered_map<int, list<int>::iterator> mp){
    for(auto it:li) 
        cout << it<<endl; 
}

int main()
{

    unordered_map<int, list<int>::iterator> mp;
    list<int> li;
   
    addLRU(1,mp,li);
    addLRU(2,mp,li);
    addLRU(3,mp,li);
    addLRU(1,mp,li);
    addLRU(4,mp,li);
    addLRU(5,mp,li);

    display(li,mp);
    return 0;
}