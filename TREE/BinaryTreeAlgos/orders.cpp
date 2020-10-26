#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
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

void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(Node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void levelorderLtoR(Node* root){
	if(root==NULL) return;

	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}

void levelorderRtoL(Node* root){
	if(root==NULL) return;

	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->right) q.push(temp->right);
		if(temp->left) q.push(temp->left);
	}
}

void levelorderLtoRdown(Node* root){
	if(root==NULL) return;

	queue<Node*> q;
	q.push(root);
	stack<int> s;
	while(!q.empty()){
		Node* temp = q.front();
		s.push(temp->data);
		// cout<<temp->data<<" ";
		q.pop();
		if(temp->right) q.push(temp->right);
		if(temp->left) q.push(temp->left);
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	preorder(root);
	cout<<endl;

	inorder(root);
	cout<<endl;

	postorder(root);
	cout<<endl;

	levelorderLtoR(root);
	cout<<endl;
	levelorderRtoL(root);
	cout<<endl;
	levelorderLtoRdown(root);
	cout<<endl;

	return 0;
}