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
	bool isFirst=true;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		if(temp==NULL){
			if(q.empty()) return;
			else{
				q.push(NULL);
				isFirst=true;
			}
		}
		
		else{
			if(isFirst==true){
				cout<<temp->data;
				isFirst=false;
			}
			
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		
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