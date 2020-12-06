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


void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	for(auto i:root->child){
		preorder(i);
	}
}

void postorder(Node* root){
	if(root==NULL) return;
	
	for(auto i:root->child){
		postorder(i);
	}

	cout<<root->data<<" ";
}

int main(){
	Node *root = newNode(10); 
    (root->child).push_back(newNode(2)); 
    (root->child).push_back(newNode(34)); 
    (root->child).push_back(newNode(56)); 
    (root->child).push_back(newNode(100)); 
    (root->child[0]->child).push_back(newNode(77)); 
    (root->child[0]->child).push_back(newNode(88)); 
    (root->child[2]->child).push_back(newNode(1)); 
    (root->child[3]->child).push_back(newNode(7)); 
    (root->child[3]->child).push_back(newNode(8)); 
    (root->child[3]->child).push_back(newNode(9)); 

    cout<<"Preorder=";
    preorder(root);
    cout<<endl;
    cout<<"Postorder=";
    postorder(root);
}














