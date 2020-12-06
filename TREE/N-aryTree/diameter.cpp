#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std; 

struct Node 
{
   int data; 
   vector<Node*>child; 
}; 

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    return temp; 
} 


int height(Node* root, int &d){
    if(!root) return 0;
    int max1=0, max2=0;

    for(auto i:root->child){
        int temp=height(i,d);
        if(temp>max1){
            max2=max1;
            max1=temp;
        }
        else{
            max2=temp;
        }
    }
    if(1+max1+max2>d){
        d=1+max1+max2;
    }
    return 1+max1;
}

int diameter(Node* root){
    int d=0;
    height(root, d);
    return d;
}
int main(){
    Node *root = newNode(1); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(3)); 
    (root->child).push_back(newNode(4)); 
    (root->child).push_back(newNode(5)); 
    (root->child[0]->child).push_back(newNode(6)); 
    (root->child[0]->child).push_back(newNode(7)); 
    (root->child[2]->child).push_back(newNode(8)); 
    (root->child[3]->child).push_back(newNode(9)); 
    (root->child[3]->child).push_back(newNode(10)); 
    (root->child[3]->child).push_back(newNode(11)); 

    cout<<"Height=";
    int ans=diameter(root);
    cout<<ans;
    cout<<endl;
}














