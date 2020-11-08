#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
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


void sumtree(Node* root, bool &ans){
	if(!root) return;
	if(!root->left && !root->right) return ;
	if(root->left && root->right){
		//if node not a sum of L and R return false
		if(root->left->data + root->right->data != root->data){
			ans=false;
			return;
		}
		sumtree(root->left, ans);
		sumtree(root->right, ans);		
	}
}


int main(){
	Node *root= newNode(10);
	// root->left=newNode(6);
	// root->right=newNode(4);
	// root->left->left=newNode(3);
	// root->left->right=newNode(3);
	// root->right->left=newNode(1);
	// root->right->right=newNode(3);

	bool ans=true;
	sumtree(root, ans);
	cout<<"Ans="<<ans<<endl;
}




