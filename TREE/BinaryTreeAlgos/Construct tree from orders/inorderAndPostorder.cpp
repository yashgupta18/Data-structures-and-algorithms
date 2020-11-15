#include <iostream>
#include<vector>
#include<unordered_map>
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

void inorderPrint(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	inorderPrint(root->left);
	inorderPrint(root->right);
}


Node* constructTree(int postorder[], unordered_map<int,int> mp, int &start, int s, int e){
	if(s>e) return NULL;

	Node* root=newNode(postorder[start]);
	int mid= mp[postorder[start]];
	start--;
	root->right= constructTree(postorder, mp, start, mid+1,e);
	root->left=constructTree(postorder, mp, start, s, mid-1);
	return root;
}

int main(){
	int postorder[6]={6,2,4,5,3,1};
	int inorder[6]={6,2,1,4,3,5};
	unordered_map<int,int> mp;
	for (int i = 0; i < 6; ++i)
	{
		mp[inorder[i]]=i;
	}
	int start=5;
	Node* tree=constructTree(postorder, mp, start, 0, 5);
	inorderPrint(tree);

	return 0;
}