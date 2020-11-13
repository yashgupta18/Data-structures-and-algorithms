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

int findInorder(int inorder[], int num, int s, int e){
	for (int i = s; i <= e; ++i)
	{
		if(inorder[i]==num){
			return i;
		}
	}
}

Node* constructTree(int preorder[], int inorder[], int &start, int s, int e){
	if(s>e) return NULL;

	Node* root = newNode(preorder[start]);
	int mid=findInorder(inorder, preorder[start], s,e);
	start++;
	root->left= constructTree(preorder, inorder, start, s, mid-1);
	root->right= constructTree(preorder, inorder, start, mid+1, e);
	return root;
}

int main(){
	int preorder[6]={1,2,4,5,3,7};
	int inorder[6]={4,2,5,1,3,7};
	int start=0;
	Node* tree=constructTree(preorder, inorder, start, 0, 5);
	inorderPrint(tree);

	return 0;
}