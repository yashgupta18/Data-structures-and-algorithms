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

void changeToBST(Node* root, vector<int> v, int &ptr){
	if(root==NULL) return;

	changeToBST(root->left ,v, ptr);
	
	root->data=v[ptr];
	ptr++;

	changeToBST(root->right, v, ptr);
}

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

void pushToVector(Node* root, vector<int> &v){
	if(root==NULL) return;
	pushToVector(root->left ,v);
	v.push_back(root->data);
	pushToVector(root->right, v);
}

void BtToBST(Node* root){
	vector<int> v;
	pushToVector(root, v);
	sort(v.begin(), v.end());
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout<<v[i]<<endl;
	// }

	int ptr=0;
	changeToBST(root,v,ptr);
}



int main(){
	Node *root= newNode(21);
	root->left=newNode(32);
	root->right=newNode(1);
	root->left->right=newNode(34);
	root->right->left=newNode(5);
	root->right->right=newNode(11);
	root->right->left->left=newNode(17);
	
	BtToBST(root);
	inorder(root);
	return 0;
}