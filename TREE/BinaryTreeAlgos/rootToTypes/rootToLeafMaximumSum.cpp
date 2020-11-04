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


void RootToLeafSum(Node* root, int &max_sum, int curr_sum){
	if(root==NULL) return;
	curr_sum=curr_sum+root->data;
	
	if(!root->left && !root->right){
		if(curr_sum> max_sum){
			max_sum=curr_sum;
		}
	}
	RootToLeafSum(root->left, max_sum, curr_sum);
	RootToLeafSum(root->right,max_sum, curr_sum);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	// root->right->right=newNode(7);
	int max_sum=INT_MIN;
	int curr_sum=0;
	RootToLeafSum(root,max_sum,curr_sum);
	cout<<max_sum;
	cout<<endl;
}




