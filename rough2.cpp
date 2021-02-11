#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<utility>

#include<map>
using namespace std; 


struct Node{
  int data;
  Node *left, *right;
};
struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

vector<int> find(int inorder[], int n1, int n2){
    vector<int> v;
    // cout<<"n1="<<n1<<endl;
    // cout<<"n2="<<n2<<endl;
    for (int i = n1; i < n2; ++i)
    {
        // cout<<i<<" ";
        v.push_back(inorder[i]);
    }

    return v;
}

Node* constructTree(int levelorder[], int inorder[], unordered_map<int,int> mp, int n){
    if(n==0) return NULL;

    Node* root = newNode(levelorder[0]);

    int mid = mp[levelorder[0]];

    vector<int> left=find(inorder, 0, mid);
    vector<int> right=find(inorder, mid+1, n);

    vector<int> vectorLeft; 
    for (int i = 0; i <left.size(); ++i)
    {
        vectorLeft.push_back(left[i]);
    }

    vector<int> vectorRight;
    for (int i = 0; i < right.size(); ++i)
    {
        vectorRight.push_back(right[i]);
    }

    for (int i = 0; i < vectorLeft.size(); ++i)
    {
        cout<<vectorLeft[i]<<" ";
    }
    cout<<endl;


    // root->left=constructTree(left,vectorLeft,mp);
    // root->right=constructTree(right, vectorRight, mp);
    return root;
}


int treeHeight(Node* root){
    if(root==NULL) return 0;
    return 1+min(treeHeight(root->left)+1, treeHeight(root->right)+1);
}


int main() 
{ 
    int inorder[] = { 4,2,5,1,6,3,7 }; 
    int levelorder[] = { 1,2,3,4,5,6,7 }; 
    int n = sizeof(inorder) / sizeof(inorder[0]); 

    unordered_map<int,int> mp;
    for (int i = 0; i < 6; ++i)
    {
        mp[inorder[i]]=i;
    }
    int start=0;
    Node* root=constructTree(levelorder, inorder, mp, n);
    // cout<<treeHeight(root);  
    cout<<abs(log2(n)+1);
    return 0; 
} 