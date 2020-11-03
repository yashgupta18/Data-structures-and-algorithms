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


vector<vector<int> > RootToLeafPathUtil(Node* root, vector<vector<int> > &v, vector<int> &current_path){
	if (root->left == NULL && root->right == NULL) {
        v.push_back(current_path);
    }

	if (root->left != NULL)
            RootToLeafPathUtil(root->left, v, current_path);
        
    if (root->right != NULL)
        RootToLeafPathUtil(root->right, v, current_path);
	
	
	
	
}


vector<vector<int> > RootToLeafPath(Node* root){
	vector<vector<int> > v;
	vector<int> current_path;
	RootToLeafPathUtil(root, v, current_path);
	
	return v;
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	RootToLeafPath(root);
	cout<<endl;
}