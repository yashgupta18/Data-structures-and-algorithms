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


void levelorder(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	bool isFirst=true;
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp==NULL){
			if(q.size()==0) return;
			else{
				q.push(NULL);
				isFirst=true;
			}
		}
		else{
			if(isFirst){
				cout<<temp->data<<endl;
				isFirst=false;
			}
			if(temp->right) q.push(temp->right);
			if(temp->left) q.push(temp->left);	
		}
	}

	return;
}



int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->right=newNode(4);
	root->right->left=newNode(5);
	root->right->right=newNode(6);
	root->right->left->left=newNode(7);
	
	levelorder(root);	
	cout<<endl;
}