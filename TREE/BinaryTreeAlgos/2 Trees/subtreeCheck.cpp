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

	return identicalCheck(rootOne->left, rootTwo->left) && identicalCheck(rootOne->right, rootTwo->right);
}

bool subtreeCheck(Node* rootOne, Node* rootTwo){
	if(rootOne==NULL) return false;
	queue<Node*> q;
	q.push(rootOne);
	
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->data==rootTwo->data){
			//call identical check
			if(identicalCheck(temp, rootTwo)==true){
				return true;
			}
		}
		else{
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return false;
}


int main(){
	Node *rootOne= newNode(1);
	rootOne->left=newNode(2);
	rootOne->right=newNode(3);
	rootOne->left->left=newNode(4);
	rootOne->left->right=newNode(5);
	rootOne->right->left=newNode(6);
	rootOne->right->right=newNode(7);
	
	Node *rootTwo= newNode(3);
	rootTwo->left=newNode(6);
	rootTwo->right=newNode(7);

	bool ans=subtreeCheck(rootOne, rootTwo);
	cout<<ans;
	cout<<endl;
}

