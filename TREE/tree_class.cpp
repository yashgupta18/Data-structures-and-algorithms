#include<iostream>
using namespace std;
#define SPACE 10
class TreeNode{
public:
	int value;
	TreeNode* left;
	TreeNode* right;

	//consructors
	TreeNode(){
		value=0;
		left=NULL;
		right=NULL;
	}

	TreeNode(int v){
		value=v;
		left=NULL;
		right=NULL;
	}
};

class BST{
public:
	TreeNode *root;
	BST(){
		root=NULL;
	}
	bool isTreeEmpty(){
		if(root==NULL){
			return true;
		}
		else{
			return false;
		}
	}
// };

void insertNode(TreeNode *new_node){
	if(root==NULL){
		root=new_node;
		cout<<"Value inserted as root node"<<endl;
	}

	else{
		TreeNode *temp=root;
		while(temp!=NULL){
			if(new_node->value==temp->value){
				cout<<"Value already exits."<<"Insert another Value"<<endl;
				return;
			}

			else if(new_node->value<(temp->value) && (temp->left==NULL)){
				temp->left=new_node;
				cout<<"Value Inserted to left"<<endl;
				break;
			}

			else if(new_node->value<(temp->value)){
				temp=temp->left;
			}

			else if(new_node->value>(temp->value) && (temp->right==NULL)){
				temp->right=new_node;
				cout<<"Value Inserted to right"<<endl;
				break;
			}

			else if(new_node->value>(temp->value)){
				temp=temp->right;
			}
		}
	}
}

void print2D(TreeNode *r, int space){
	if(r==NULL)
		return;

	space+=SPACE;  //increase dist btw levels
	print2D(r->right, SPACE); //process right child first
	cout<<endl;

	for (int i = SPACE; i < space; ++i)
		cout<<" ";

	cout<<r->value<<"\n";
	print2D(r->left, space); //process left child
}
};


int main(){

	int option,val;

	BST obj;
	BST print2D;
	

	do{

		cout<<"Choose Operator"<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST values"<<endl;
		cout<<"5. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		cout<<"Enter here:";
		cin>>option;


		//heap allocation
		TreeNode *new_node=new TreeNode();

		switch(option){
			case 0:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter Value to insert in BST: ";
				cin>>val;
				new_node->value=val;
				obj.insertNode(new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH"<<endl;
				break;
			case 3:
				cout<<"DELETE"<<endl;
				break;
			case 4:
				cout<<"PRINT"<<endl;
				obj.print2D(obj.root, 5);
				break;
			case 5:
				cout<<"CLEAR"<<endl;
				break;
			case 6:
				cout<<"EXIT"<<endl;
				break;					


		}
	}while(option!=0);

	return 0;
}



































