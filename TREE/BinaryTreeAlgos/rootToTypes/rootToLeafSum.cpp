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


void RootToLeafSum(Node* root, int curr_sum, int sum, bool &isFound){
	if(root==NULL) return;
	curr_sum=curr_sum+root->data;
	if(!root->left && !root->right && curr_sum==sum){
		isFound=true;
	}
	RootToLeafSum(root->left, curr_sum,sum, isFound);
	RootToLeafSum(root->right, curr_sum,sum, isFound);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	int curr_sum=0;
	int sum=11;
	bool isFound=false;
	RootToLeafSum(root,curr_sum,sum, isFound);
	if(isFound){
		cout<<"Sum Path exists";
	}
	else{
		cout<<"No Sum Path exists";
	}
	cout<<endl;
}




