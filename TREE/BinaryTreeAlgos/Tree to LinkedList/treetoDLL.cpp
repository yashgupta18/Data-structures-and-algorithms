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

void treeToDll(Node* root, Node* &head, Node* &tail){
	if(root==NULL) return;
	treeToDll(root->left, head, tail);

	if(head==NULL){
		head=root;
		tail=root;
	}
	else{
		root->left=tail;
		tail->right=root;
		tail=root;
	}
	treeToDll(root->right, head, tail);
}

void printList(Node* head){
	while(head!=NULL){
		cout<<head->data<<" "<<"->"<<" ";
		head=head->right;
	}
}

void inorder(Node* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	Node *head=NULL;
	Node *tail=NULL;
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"INORDER"<<endl;
	inorder(root);
	cout<<endl;
	treeToDll(root,head, tail);

	cout<<"DOUBLE LINKED LIST"<<endl;
	printList(head);
}




