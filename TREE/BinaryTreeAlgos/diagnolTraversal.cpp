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


void verticalTraversal(Node* root, vector<int> v){
	if(root==NULL) return;

	queue<pair<Node*, int> > q;
	map<int, vector<int> > mp;
	q.push(make_pair(root, 0));

	while(!q.empty()){
		pair<Node*, int> front= q.front();
		q.pop();
		//store node* int temp
		Node* temp=front.first;
		//store vertical level index in key
		int key=front.second;
		mp[key].push_back(temp->data);
		if(temp->left) q.push(make_pair(temp->left, key+1));
		if(temp->right) q.push(make_pair(temp->right, key));
	}

	for (auto itr:mp){
		//loop over vector in map
		for (int i=0; i<itr.second.size(); ++i){
			cout<<itr.second[i]<<" ";
		}	
		cout<<endl;
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

	vector<int> v;
	verticalTraversal(root, v);
	cout<<endl;
}