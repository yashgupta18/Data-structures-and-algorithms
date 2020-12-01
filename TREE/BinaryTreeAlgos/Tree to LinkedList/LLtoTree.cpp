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

struct List{
  int data;
  List *next;
};

struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

struct List *newList(int item) 
{ 
    struct List *temp =  (struct List *)malloc(sizeof(struct List)); 
    temp->data = item; 
    temp->next = NULL; 
    return temp; 
}

void LLtoTree(List* head, vector<Node*> &v){
	// convert all LL nodes to tree nodes and also push them to vector
	while(head!=NULL){
		Node* temp = newNode(head->data);
		v.push_back(temp);
		head=head->next; 
	}

	// now just assign left and right of each node in vector
	int n=v.size();
	for (int i = 0; i < n/2; ++i)
	{
		if((2*i)+1 < n){
			v[i]->left = v[(2*i)+1];
		}

		if((2*i)+2<n){
			v[i]->right = v[(2*i)+2];
		}
	}
}

void printList(Node* head){
	while(head!=NULL){
		cout<<head->data<<" "<<"->"<<" ";
		head=head->right;
	}
}

void inorder(Node* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	List *head=newList(1);
	head->next=newList(2);
	head->next->next=newList(3);
	head->next->next->next=newList(4);
	
	vector<Node*> v;
	
	LLtoTree(head, v);
	inorder(v[0]);

}




