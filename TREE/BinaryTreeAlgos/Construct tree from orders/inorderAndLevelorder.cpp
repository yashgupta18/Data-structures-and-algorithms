#include <iostream>
#include<vector>
#include<unordered_map>
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

void inorderPrint(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	inorderPrint(root->left);
	inorderPrint(root->right);
}


vector<int> find(vector<int> inorder, int n1, int n2){
	vector<int> v;
	for (int i = n1; i < n2; ++i)
	{
		v.push_back(inorder[i]);
	}

	return v;
}



Node* constructTree(vector<int> levelorder, vector<int> inorder, unordered_map<int,int> mp){
	if(levelorder.size()==0) return NULL;

	Node* root = newNode(levelorder[0]);

	int mid = mp[levelorder[0]];

	vector<int> left=find(inorder, 0, mid-1);
	vector<int> right=find(inorder, mid+1, inorder.size()-1);

	vector<int> vectorLeft; 
	vectorLeft.insert(vectorLeft.begin(), vectorLeft.begin(), vectorLeft.begin()+mid-1);


	vector<int> vectorRight;
	vectorRight.insert(vectorRight.begin(), vectorRight.begin()+mid+1, vectorRight.end());


	root->left=constructTree(left,vectorLeft,mp);
	root->right=constructTree(right, vectorRight, mp);
	return root;
}

int main(){
	vector<int> levelorder;
	levelorder.push_back(1);
	levelorder.push_back(2);
	levelorder.push_back(3);
	levelorder.push_back(4);
	levelorder.push_back(5);
	levelorder.push_back(6);

	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(6);	
		
	unordered_map<int,int> mp;
	for (int i = 0; i < 6; ++i)
	{
		mp[inorder[i]]=i;
	}
	int start=0;
	Node* tree=constructTree(levelorder, inorder, mp);
	inorderPrint(tree);

	return 0;
}