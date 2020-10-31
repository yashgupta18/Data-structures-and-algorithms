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
	queue<pair<Node*, int> > q;
	map<int, int> mp;
	q.push(make_pair(root, 0));
	// mp[0]=root;
	
	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();
		Node* node=temp.first;
		int key=temp.second;
		if(mp.find(key)==mp.end()){
			mp[key]=node->data;
		};

		if(node->left) q.push(make_pair(node->left, key-1));
		if(node->right) q.push(make_pair(node->right, key+1));
	}

	for(auto i:mp){
		cout<<i.second ;
	}

	return;
}

 
int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	cout<<"Method 1"<<endl;
	levelorder(root);	
	cout<<endl;
	

	return 0;
}