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


int height(Node* root){

    if(!root) return 0;
    int maxH=0;
    for(auto i:root->child){
        int temp=height(i);
        if(temp>maxH){
            maxH=temp;
        }
    }
    return maxH+1;
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
    int ans=height(root);
    cout<<ans;
    cout<<endl;
}














