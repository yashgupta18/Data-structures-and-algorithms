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


void succPred(Node* root,  Node*& pred, Node*& succ, int key){
	if(root==NULL) return;

	if(root->data == key){
		if(root->left!=NULL){
			Node* temp= root->left;
			while(temp->right){
				temp=temp->right;
			}
			pred=temp;
		}
		if(root->right!=NULL){
			Node* temp= root->right;
			while(temp->left){
				temp=temp->left;
			}
			succ=temp;
		}
		return;
	}

	if(root->data < key){
		succ=root;
		succPred(root->left, pred, succ, key);
	}
	if(root->data > key){
		pred=root;
		succPred(root->right, pred, succ, key);
	}
	
}


int main(){
	Node *root= newNode(20);
	root->left=newNode(15);
	root->right=newNode(25);
	root->left->left=newNode(2);
	root->left->right=newNode(17);
	root->right->left=newNode(22);
	root->right->right=newNode(30);
	Node *pred=NULL; 
	Node *succ=NULL;
	succPred(root, pred, succ, 30);
	if (pred != NULL) 
      cout << "Predecessor is " << pred->data << endl; 
    else
      cout << "No Predecessor"; 
  
    if (succ != NULL) 
      cout << "Successor is " << succ->data; 
    else
      cout << "No Successor"; 
}




