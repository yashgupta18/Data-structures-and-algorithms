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


void RootToLeafSum(Node* root, vector<int> &ans){
	// ansector<int> ;
	if(root==NULL) {
		ans.push_back(-1);
		return;
	}

	ans.push_back(root->data);

	RootToLeafSum(root->left,ans);
	RootToLeafSum(root->right, ans);
	// return v;
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	vector<int> ans;
	RootToLeafSum(root,ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<endl;
	}
}




