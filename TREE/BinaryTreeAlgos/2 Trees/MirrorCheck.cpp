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

bool identicalCheck(Node* rootOne, Node* rootTwo){
	if(rootOne==NULL && rootTwo==NULL) return true;
	if(rootOne==NULL || rootTwo==NULL) return false;
	if(rootOne->data!= rootTwo->data) return false;

	return identicalCheck(rootOne->left, rootTwo->right) && identicalCheck(rootOne->right, rootTwo->left);
}

int main(){
	Node *rootOne= newNode(1);
	rootOne->left=newNode(2);
	rootOne->right=newNode(3);
	rootOne->left->left=newNode(4);
	rootOne->left->right=newNode(5);
	rootOne->right->left=newNode(6);
	rootOne->right->right=newNode(7);
	
	Node *rootTwo= newNode(1);
	rootTwo->left=newNode(3);
	rootTwo->right=newNode(2);
	rootTwo->left->left=newNode(7);
	rootTwo->left->right=newNode(6);
	rootTwo->right->left=newNode(5);
	rootTwo->right->right=newNode(4);

	bool ans=identicalCheck(rootOne, rootTwo);
	cout<<ans;
	cout<<endl;
}

