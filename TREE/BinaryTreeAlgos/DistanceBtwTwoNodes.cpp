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


Node* lca(Node* root, int a, int b){
	if(!root) return NULL;

	//if root is one of a or b
	if(root->data == a || root->data==b) return root;

	Node* l=lca(root->left, a, b);
	Node* r=lca(root->right, a, b);
		
	// if l and r both return something then root is ans
	if(l && r) return root;

	// if only l returns
	if(l) return l;

	//if only r returns
	if(r) return r;
	
	//if a or b doesnt exists 
	return NULL;
}

int dist(Node* root, int node, int level){
	if(root==NULL) return -1;
	if(root->data==node) return level;

	int l= dist(root->left, node, level+1);
	if(l==-1){
		return dist(root->right, node, level+1);
	}
	return l;
}



int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	Node* LCA= lca(root,2,3);
	int totalDist= dist(LCA, 2,0) + dist(LCA, 3, 0);
	cout<<"Ans="<<totalDist<<endl;
}




