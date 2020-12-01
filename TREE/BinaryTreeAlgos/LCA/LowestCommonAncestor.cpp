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


Node* LCA(Node* root, int a, int b, bool &v1, bool &v2){
	// use of v1 and v2 to check both the nodes are present in tree

	if(!root) return NULL;

	//if root is one of a or b
	if(root->data == a ){
		v1=true;
		return root;
	}
	if(root->data==b){
		v2=true;
		return root;
	} 

	Node* l=LCA(root->left, a, b, v1,v2);
	Node* r=LCA(root->right, a, b, v1,v2);
		
	// if l and r both return something then root is ans
	if(l && r) return root;

	// if only l returns
	if(l) return l;

	//if only r returns
	if(r) return r;
	
	//if a or b doesnt exists 
	return NULL;
}

int findNode(Node* root, int k){
	if(root==NULL) return false;
	if(root->data==k || findNode(root->left, k) || findNode(root->right, k)){
		return true;
	}

	return false;
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	bool v1=false, v2=false;
	int val1=1, val2=4;

	Node* ans= LCA(root,val1,val2, v1,v2);

	if((v1&&v2) || (v1 && findNode(root, val1)) || (v2 && findNode(root, val2))){
		cout<<"Ans="<<ans->data<<endl;
	}else{
		cout<<"No ans";
	}
	
}




