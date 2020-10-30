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

vector<int> zigzagTraversal(Node* root, vector<int> &v){
	if(root==NULL) return v;
	 stack<Node*> s1;
	 stack<Node*> s2;

	 s1.push(root);
	 while(!s1.empty() || !s2.empty()){

	 	while(!s1.empty()){
	 		Node* top1=s1.top();
	 		v.push_back(top1->data);
			// cout<<top1->data;
			if(top1->right) s2.push(top1->right);
	 		if(top1->left)	s2.push(top1->left);	
			s1.pop();
	 	}
	 	// cout<<endl;
	 	
	 	while(!s2.empty()){
	 		Node* top2=s2.top();
			// cout<<top2->data;
			v.push_back(top2->data);
			if(top2->left)	s1.push(top2->left);
			if(top2->right) s1.push(top2->right);
			s2.pop();
	 	}

	 	// cout<<endl;
	 }
	 return v;
}

int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);

	vector<int> v;
	zigzagTraversal(root,v);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}