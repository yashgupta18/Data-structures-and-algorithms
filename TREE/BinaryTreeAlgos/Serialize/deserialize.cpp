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

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* deserialize(vector<int> v, int &curr){
	if(v[curr]==-1){
		curr++;
		return NULL;
	}
	Node* root = newNode(v[curr]);
	cout<<root->data;
	curr++;
	root->left=deserialize(v, curr);
	root->right=deserialize(v,curr);

}


int main(){
	vector<int> v;
	// string s[15]={"1","2","4","-1","-1","5","-1","-1","3","6","-1","-1","7","-1","-1"};
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(5);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(7);
	v.push_back(-1);
	v.push_back(-1);
	
	int curr=0;
	Node* root=deserialize(v, curr);
	// cout<<root;
	// inorder(root);
}




