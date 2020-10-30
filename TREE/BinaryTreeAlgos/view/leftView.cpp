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

//Method 1
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
				cout<<temp->data<<" ";
				isFirst=false;
			}
			
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		
		}
	}
	return;
}

//Method 2
int leftviewUtil(Node* root, int level, int &maxLevel){
	if(root==NULL) return 0;
	if(maxLevel<level){
		cout<<root->data<<" ";
		maxLevel=level;
	}
	leftviewUtil(root->left, level+1, maxLevel);
	leftviewUtil(root->right, level+1, maxLevel);
	return 0;
}


void leftview(Node* root){
	if(root==NULL) return;
	int maxLevel=0;
	leftviewUtil(root, 1, maxLevel);
}


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->right=newNode(4);
	root->right->left=newNode(5);
	root->right->right=newNode(6);
	root->right->left->left=newNode(7);
	
	cout<<"Method 1"<<endl;
	levelorder(root);	
	cout<<endl;
	cout<<"Method 2"<<endl;
	leftview(root);
	cout<<endl;

	return 0;
}