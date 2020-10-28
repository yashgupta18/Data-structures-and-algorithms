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


void method1(Node* root){
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

void preorder(Node* root, map<int, vector<int> > &mp, int key){
	if(root==NULL) return;
	mp[key].push_back(root->data);
	preorder(root->right, mp, key);
	preorder(root->left, mp, key+1);
}

void method2(Node* root){
	map<int, vector<int> > mp;
	preorder(root, mp, 0);

	for (auto itr:mp){
		//loop over vector in map
		for (int i=0; i<itr.second.size(); ++i){
			cout<<itr.second[i]<<" ";
		}	
		cout<<endl;
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
	cout<<"METHOD 1="<<endl;
	method1(root);
	cout<<endl;
	cout<<"METHOD 2="<<endl;
	method2(root);
	cout<<endl;
}