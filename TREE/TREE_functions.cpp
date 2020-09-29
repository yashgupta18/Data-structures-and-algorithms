#include <iostream>
#include <fstream>

#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#define MARKER -1 

// #include<Math>


using namespace std;


struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 


void printPreorder(struct Node* node){
	if (node==NULL)
	{
		return;
	}
	cout<<node->data;
	printPreorder(node->left);
	printPreorder(node->right);
}

void printInorder(struct Node* node){
	if (node==NULL)
	{
		return;
	}
	
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

void printPostorder(struct Node* node){
	if (node==NULL)
	{
		return;
	}
	
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<node->data;
}

void printLevelOrder(struct Node* node){
	if (node==NULL) return;

	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		Node *current=q.front();
		cout<<current->data;
		if (current->left!=NULL) q.push(current->left);
		if (current->right!=NULL) q.push(current->right);
		q.pop();
	}
}

int height(struct Node* node){
	
	if (node==NULL)
	{
		return 0;
	}
	int lheight=height(node->left);
	int rheight=height(node->right);

	return max(lheight,rheight)+1;	
}

int noOfLeafNodes(struct Node* node){
	
	if (node==NULL) return 0;
	else if(node->left==NULL && node->right==NULL) return 1;

	else 
		return noOfLeafNodes(node->left)+noOfLeafNodes(node->right);	
}

int childrenSumProp(struct Node* node){
	
	if (node==NULL) return 0;
	else if(node->left==NULL && node->right==NULL) return 1;

	else 
		if((node->left->data + node->right->data)==node->data)
			return 1;
		else
			return 0;
}

void mirrorTree(struct Node* node){
	
	if (node==NULL) return ;

	mirrorTree(node->left);
	mirrorTree(node->right);
	Node *temp=node->right;
	node->right=node->left;
	node->left=temp;
}

int balanced(struct Node* node){
	
	if (node==NULL)
	{
		return 0;
	}

	if (node->left==NULL || node->right==NULL)
	{
		return 1;
	}

	int lh=balanced(node->left);
	int rh=balanced(node->right);


	if(lh==-1 || rh==-1) return -1;
	if(abs(lh-rh)>1) return -1;
	else return max(lh,rh)+1;	
}


// int LCA(struct Node* node, int m,int n){
// 	if (node==NULL) return 0;
	
// 	if(node->data==m || node->data==n) return 0;

// 	int l=LCA(node->left, m, n);
// 	int r=LCA(node->right, m, n);

// 	if(r==NULL && l==NULL) return NULL;
// 	if(r!=NULL && l!=NULL) return node;

// 	return l!=NULL ? l : r;
// }

// int diameter(struct Node* node, int& res){
// 	if (node==NULL) return 0;
	
// 	int l=diameter(node->left, res);
// 	int r=diameter(node->right, res);

// 	int temp=max(l,r)+1;
// 	int ans=max(temp, l+r+1);
// 	res=max(res,temp);
// 	return temp;
// }

// int maxPathSum(struct Node* node, int &res){
// 	if (node==NULL) return 0;
	
// 	int l=maxPathSum(node->left, res);
// 	int r=maxPathSum(node->right, res);

// 	int temp=max(max(l,r)+node->data, node->data);
// 	int ans=max(temp, l+r+node->data);
// 	res=max(res,ans);
// 	return temp;
// }

// int maxPathSumLeaftoLeaf(struct Node* node, int &res){
// 	if (node==NULL) return 0;
// 	if (node->right==NULL && node->left==NULL) return node->data;
	
// 	int l=maxPathSumLeaftoLeaf(node->left, res);
// 	int r=maxPathSumLeaftoLeaf(node->right, res);

// 	int temp=max(l,r)+node->data;
// 	int ans=max(temp, l+r+node->data);
// 	res=max(ans,res);
// 	return temp;
// }

// int leftViewUtil(struct Node* node, int level, vector<int>& view){
// 	vector<int> levels(0);
// 	if (node==NULL) return 0;
// 	if (view.size()==level)
// 	{
// 		 view.push_back(node->data);
// 	}
// 	leftViewUtil(node->left, level+1,view);
// 	leftViewUtil(node->right, level+1,view);
// }

// void leftView(struct Node* node){
// 	vector<int> view;
// 	leftViewUtil(node,0,view);
// 	for (int i = 0; i < view.size(); ++i)
// 	{
// 		cout<<view[i]<<endl;
// 	}
// 	return;
// }

// int rightViewUtil(struct Node* node, int level, vector<int>& view){
// 	vector<int> levels(0);
// 	if (node==NULL) return 0;
// 	if (view.size()==level)
// 	{
// 		 view.push_back(node->data);
// 	}
// 	rightViewUtil(node->right, level+1,view);
// 	rightViewUtil(node->left, level+1,view);
// }

// void rightView(struct Node* node){
// 	vector<int> view;
// 	rightViewUtil(node,0,view);
// 	for (int i = 0; i < view.size(); ++i)
// 	{
// 		cout<<view[i]<<endl;
// 	}
// 	return;
// }

// void levelTraversal(struct Node* node){
// 	if (node==NULL) return ;
// 	queue<Node*> q;
// 	q.push(node);
// 	q.push(NULL);
// 	while(q.size()>1){
// 		Node* current=q.front();
// 		q.pop();
// 		if (current==NULL)
// 		{
// 			q.push(NULL);
			
// 			cout<<'\n';
// 		}
// 		else{
// 		if(current->left) q.push( current->left);
// 		if(current->right) q.push(current->right);
// 		cout<<current->data<<" ";
// 		}
// 	}
// 	return;	
// }

// int search(int arr[], int value, int n){
// 	int i;
// 	for (i = 0; i < n; ++i)
// 	{
// 		if (arr[i]==value)
// 		{
// 			break;
// 		}
// 	}
// 	return i;
// }

void zigzag(struct Node* node){
	if (node==NULL)
	{
		return;
	}
	stack<Node*> s1;
	stack<Node*> s2;
	s1.push(node);
	// cout<<"Done";
	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
			struct Node* current=s1.top();
			s1.pop();
			cout<<current->data<<endl;
			if(current->left!=NULL) s2.push(current->left);
			if(current->right!=NULL) s2.push(current->right);
		}

		while(!s2.empty()){
			struct Node* current2=s2.top();
			s2.pop();
			cout<<current2->data<<endl;
			if(current2->right!=NULL) s1.push(current2->right);
			if(current2->left!=NULL) s1.push(current2->left);
		}
	}
}


void serialize(Node* root,FILE *fp){
	if (root==NULL) {
		fprintf(fp, "%d ", MARKER);
		return ;
	}

	fprintf(fp, "%d ", root->data);
	serialize(root->left,fp);
	serialize(root->right,fp);

}

void deserialize(Node* &root,FILE *fp){
	int val;
	if (!fscanf(fp, "%d", &val) || val==MARKER){
		return;
	}

	root=new Node(val);
	deserialize(root->left,fp);
	deserialize(root->right,fp);
}

Node* BSTtoDoubleLL(Node* node,Node* &head,Node* &tail){

	if (node==NULL) return 0;
	
	if (node->left==NULL && node->left==NULL)
	{
		if(head==NULL) 
			head=node;
		else{
				node->left=tail;
				tail->right=node;
			}
		tail=node;
		return 0;
	}

	node->left=BSTtoDoubleLL(node->left, head, tail);
	node->right=BSTtoDoubleLL(node->right, head, tail);
	return node;
}

void printList(Node *head)  
{  
    while (head)  
    {  
        cout<<head->data<<" ";  
        head = head->right;  
    }  
} 

void printListCLL(Node *head)  
{  
	cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do
    { 
        cout << itr->data <<" "; 
        itr = itr->right; 
    } while (head!=itr); 
    cout << "\n"; 
}

void TreetoDLL(Node* root, Node* &head, Node* &tail){
	if(root==NULL) return;
	TreetoDLL(root->left, head,tail);
	if (head==NULL)
	{
		head=root;
	}
	else{
		root->left=tail;
		tail->right=root;
	}
	tail=root;
	TreetoDLL(root->right, head,tail);
}

void TreetoCircularLL(Node* root, Node* &head, Node* &tail){
	if(root==NULL) return;
	TreetoDLL(root->left, head,tail);
	TreetoDLL(root->right, head,tail);
	if (head==NULL)
	{
		head=root;
	}
	else{
		root->left=tail;

		tail->right=root;
	}
	tail=root;

	tail->right=head;
	// root->right=head;
	
}
//main
int main() 
{ 
	Node* head=NULL;
	Node* tail=NULL;
    struct Node *root = new Node(12); 
   	root->left = new Node(10); 
   	root->left->right = new Node(3);  
    root->right = new Node(30); 
    root->right->left = new Node(25); 
    root->right->right = new Node(40); 
    // root->left->left->left = new Node(8); 
  	

  	// cout << "\nLevelorder traversal of binary tree is \n"; 
   //  printLevelOrder(root); 

   //  cout << "\nPreorder traversal of binary tree is \n"; 
   //  printPreorder(root); 
  
    // cout << "\nInorder traversal of binary tree is \n"; 
    // printInorder(root);  
  
   //  cout << "\nPostorder traversal of binary tree is \n"; 
   //  printPostorder(root); 

    // cout << "\nHeight of binary tree is \n"; 
    // cout<<height(root); 

    // cout << "\nNumber of Nodes of binary tree is \n"; 
    // cout<<noOfLeafNodes(root); 

  	// cout << "\nNumber of Nodes of binary tree is \n"; 
   //  cout<<childrenSumProp(root); 

    // mirrorTree(root); 

    // cout << "\nNumber of Nodes of binary tree is \n"; 
    // cout<<childrenSumProp(root);
  	
  	// cout << "\nBalance binary tree is \n"; 
   //  cout<<balanced(root); 

    // cout << "\nLCA: \n"; 
    // cout<<LCA(root, 4,5); 

    // int res=INT_MIN;
    // cout<<diameter(root,res); 

    // int res1=INT_MIN;
    // cout<<maxPathSum(root,res1)<<endl; 

    // int res=INT_MIN;
    // cout<<maxPathSumLeaftoLeaf(root,res); 

    // cout << "\nNumber of Nodes of binary tree is \n"; 
    // leftView(root);

    // cout << "\nNumber of Nodes of binary tree is \n"; 
    // rightView(root);

    // cout << "\nLevele order traversal \n"; 
    // levelTraversal(root);

	//
    // int inorder[]={ 'D', 'B', 'E', 'A', 'F', 'C' };
    // int preorder[]={ 'A', 'B', 'D', 'E', 'C', 'F' };  
    // int n=sizeof(inorder)/sizeof(inorder[0]); 
    // Node* root = buildTree(inorder, postorder, n);
    // printInorder(root);

    // cout<<"Zig Zag Traversal"<<endl;
    // zigzag(root);

  //   //serialize deserialize
  //   cout<<"SERIALIZE"<<endl;
  //   FILE *fp=fopen("tree.txt", "w");
  //   if (fp==NULL)
  //   {
  //   	cout<<"Could not open the file";
  //   	return 0;
  //   }
  //   serialize(root,fp);
  //   fclose(fp);

  //   Node *root1 = NULL; 
  //   fp = fopen("tree.txt", "r"); 
  //   deserialize(root1,fp);
 	
 	// printf("Inorder Traversal of the tree constructed from file:\n"); 
  //   printInorder(root1);

    // TREE leaves to LINKEDLIST
    // cout << "Inorder Trvaersal of given Tree is:\n";  
    // printInorder(root);  
    // BSTtoDoubleLL(root, head, tail);
    // cout << "\nExtracted Double Linked list is:\n";  
    // printList(head);  
    // cout << "\nInorder traversal of modified tree is:\n";  
    // printInorder(root); 

    // //Tree to Doubly LL
    // cout << "Inorder Trvaersal of given Tree is:\n";  
    // printInorder(root);  
    // TreetoDLL(root, head, tail);
    // cout << "\nExtracted Double Linked list is:\n";  
    // printList(head);  
  	
    //Tree to Circular LL
    cout << "Inorder Trvaersal of given Tree is:\n";  
    printInorder(root);  
    TreetoCircularLL(root, head, tail);
    cout << "\nExtracted Double Linked list is:\n";  
    printListCLL(head);

    return 0; 

} 