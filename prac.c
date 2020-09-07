#include <iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std; 
  

struct node{
  int data;
  struct node *left, *right;
};

struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 


void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
}


struct node* insert(node* root, int key){
  if(root==NULL) return newNode(key);

  if (root->data<key)
  {
    root->right=insert(root->right, key);
  }

  else
  {
    root->left=insert(root->left, key);
  }

  return root;
}
 
struct node* getMinValue(node* root){
  struct node* current=root;
  while(current && current->left){
    current=current->left;
  }

  return current;
} 


struct node* deleteNode(node* root, int key){

  if(root==NULL) return root;

  if (root->data<key)
  {
    root->left=deleteNode(root->left, key);
    
  }

  else if(root->data>key){
    root->right=deleteNode(root->right, key);
  }

  else{
    //if 1 child or no child
    if (root->left==NULL )
    {
      struct node* temp=root->left;
      free(root);
      return temp;
    }

    if (root->right==NULL)
    {
      struct node* temp=root->right;
      free(root);
      return temp;
    }

    struct node* temp=getMinValue(root->right);

    root->data=temp->data;
    root->right=deleteNode(root->right, temp->data);
  }

  return root;
}

int minimumBST(struct node* root){
  // if (root==NULL) return NULL;
  struct node* current=root;
  while(current->left!=NULL){
    current=current->left;
  }

  return current->data;
}

int countBSTRange(node* current, int r1, int r2){
  if (current==NULL) return 0;

  if(r1<=current->data && current->data<=r2) return 1+countBSTRange(current->left, r1,r2)+countBSTRange(current->right, r1,r2);

  if(r1<=current->data && r2>current->data){
    return 1+ countBSTRange(current->left, r1,r2);
  }

  if(r1>current->data && r2<=current->data) return 1+countBSTRange(current->right, r1,r2);

  else return 0;
}

void addAllUpUtil(node* root, int *sum){

  if(root==NULL) return;
  
  addAllUpUtil(root->right, sum);
  *sum=*sum+root->data;
  root->data=*sum;
  addAllUpUtil(root->left, sum);
}

void addAllUp(struct node* root){
  int sum=0;
  addAllUpUtil(root,&sum);
  // return sum;
}
 
// Driver program 
int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 50); 
    root =insert(root, 30); 
    root =insert(root, 20); 
    root =insert(root, 40); 
    root =insert(root, 70); 
    root =insert(root, 60); 
    root =insert(root, 80); 
   
    // print inoder traversal of the BST 
    // cout<<"Before Deletion"<<endl;
    // inorder(root); 
    // root=deleteNode(root, 60);
    // cout<<"After Deletion"<<endl;
    // inorder(root);

   
   // int r1=30;
   // int r2=70;
   // cout<<countBSTRange(root,r1,r2);

  // int sum=0;
   addAllUp(root);
   inorder(root);
    

    return 0; 
} 