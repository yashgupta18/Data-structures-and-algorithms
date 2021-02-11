#include <iostream>
#include <queue>
using namespace std;

int minHeight(int inOrder[], int levelOrder[], int n)
{
    int i=1;
    queue<int>q1,q2;
    q1.push(levelOrder[0]);
    int k = 1,height = 0;
    while(!q1.empty() || !q2.empty()){
        if(!q1.empty()) height++;
        while(!q1.empty()){
            int val = q1.front();
            for(int i = 0;i<n;++i){
                if(inOrder[i] == val) break;
            }
            if(i>0 && inOrder[i-1] !=-1 && k<n)
                q2.push(levelOrder[k++]);
            if(i<n-1 && inOrder[i+1] !=-1 && k<n)
                q2.push(levelOrder[k++]);
            inOrder[i] = -1;
            q1.pop();
        }
        if(!q2.empty()) height++;
        while(!q2.empty()){
            int val = q2.front();
            for(int i = 0;i<n;++i){
                if(inOrder[i] == val) break;
            }
            if(i>0 && inOrder[i-1] !=-1 && k<n)
                q1.push(levelOrder[k++]);
            if(i<n-1 && inOrder[i+1] !=-1 && k<n)
                q1.push(levelOrder[k++]);
            inOrder[i] = -1;
            q2.pop();
        }
    }
 return height;
}

int main()
{
    int inOrder[] = {4,2,5,1,6,3,7}; //input1
    int levelOrder[] = {1,2,3,4,5,6,7}; //input2
    int n=sizeof(inOrder)/sizeof(int); ////input3
    cout<<minHeight(inOrder, levelOrder, n)<<endl;

    return 0;
}