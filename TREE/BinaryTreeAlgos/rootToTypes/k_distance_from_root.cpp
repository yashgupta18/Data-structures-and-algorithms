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


void K_distance_root(Node* root, int k, vector<int> &v){
	if(root==NULL) return;
	if(k==0){
		v.push_back(root->data);
		return;
	}

	K_distance_root(root->left, k-1, v);
	K_distance_root(root->right, k-1, v);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	int k=1;
	vector<int> v;
	K_distance_root(root,k, v);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}




