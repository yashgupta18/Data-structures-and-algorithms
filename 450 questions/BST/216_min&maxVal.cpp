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


void findVal(Node* root, int &min, int &max){
	if(root==NULL) return;
	if(root->data > max){
		max=root->data;
	}

	if(root->data<min){
		min=root->data;
	}
	findVal(root->left, min, max);
	findVal(root->right, min, max);
}


int main(){
	Node *root= newNode(20);
	root->left=newNode(15);
	root->right=newNode(25);
	root->left->left=newNode(2);
	root->left->right=newNode(17);
	root->right->left=newNode(22);
	root->right->right=newNode(30);
	int min=INT_MAX, max=INT_MIN;
	findVal(root, min,max);
	cout<<"Min="<<min<<" "<<"Max="<<max;
}




