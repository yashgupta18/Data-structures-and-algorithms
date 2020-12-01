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


void RootToLeafPathUtil(Node* root, vector<vector<int> > &v, vector<int> &current_path){
	if(!root) return ;

	current_path.push_back(root->data);

	if (root->left == NULL && root->right == NULL) {
        v.push_back(current_path);
    }

	RootToLeafPathUtil(root->left, v, current_path);

    RootToLeafPathUtil(root->right, v, current_path);
    //remove last element for recursion
    current_path.pop_back();
}


// vector<vector<int> > RootToLeafPath(Node* root){
// 	vector<vector<int> > v;
// 	vector<int> current_path;
// 	RootToLeafPathUtil(root, v, current_path);
// 	return v;
// }


int main(){
	Node *root= newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	//2 vectors
	// 1 for curr path
	// 1 for storing diff curr paths
	vector<vector<int> > v;
	vector<int> current_path;
	RootToLeafPathUtil(root, v, current_path);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<"Path"<<i+1<<endl;
		for (int j = 0; j< v[i].size(); ++j)
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}
}