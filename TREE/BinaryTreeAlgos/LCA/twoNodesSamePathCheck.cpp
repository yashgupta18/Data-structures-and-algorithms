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


Node* LCA(Node* root, int a, int b, bool &flag){
	if(!root) return NULL;

	//if root is one of a or b
	if(root->data == a || root->data==b) return root;

	Node* l=LCA(root->left, a, b, flag);
	Node* r=LCA(root->right, a, b, flag);
		
	// if l and r both return something then root is ans
	if(l && r) {
		flag=false;
		return root;
	}
	// if only l returns
	if(l) return l;

	//if only r returns
	if(r) return r;
	
	//if a or b doesnt exists 
	return NULL;
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	bool flag= true;
	Node* ans= LCA(root,2,4,flag);
	cout<<"Ans="<<flag<<endl;
}




