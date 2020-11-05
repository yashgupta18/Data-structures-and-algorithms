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


void K_distance_node(Node* root, map <Node*, Node*> &mp){
	if(root==NULL) return;
	// mp[root]=parent;
	// K_distance_node(root->left, root, mp);
	// K_distance_node(root->right, root, mp);

	queue<Node*> q;
	q.push(root);
 
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
 
		if(temp->left!=NULL) {
			mp[temp->left] = temp;
			q.push(temp->left);
		}
 
		if(temp->right != NULL) {
			mp[temp->right] = temp;
			q.push(temp->right);
		}
	}



}


void K_distance_root(Node* root, Node* target, int k){
	map<Node*, Node*> mp;
	K_distance_node(root, mp);

	queue<pair<Node*, int> > q;
	q.push(make_pair(target,k));
	map<Node*, int> vis;
	vis[target] = 1;
	while(!q.empty()) {
		Node* temp = q.front().first;
		int val = q.front().second;
		q.pop();
 
		if(val == 0) {
			cout<<temp->data<<" ";
			continue;
		}
 
 		// for left
		if(temp->left!=NULL && vis[temp->left]==0) {
			vis[temp->left] = 1;
			q.push(make_pair(temp->left, val-1));
		}
 		
 		// for right
		if(temp->right!=NULL && vis[temp->right]==0) {
			vis[temp->right] = 1;
			q.push(make_pair(temp->right, val-1));
		}
 
 		//for parent of temp.
		if(mp.find(temp)!=mp.end() && vis[mp[temp]]==0) {
			vis[mp[temp]] = 1;
			q.push(make_pair(mp[temp], val-1));
		}
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
	
	Node* target= root->left;
	K_distance_root(root, target,1);
	cout<<endl;
}




