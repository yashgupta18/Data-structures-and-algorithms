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

void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        
        printf("%d \n", root->data); 
        inorder(root->left); 
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
 
void inorder_predecessor_successor(struct node* root,struct node* &pre,struct node* &suc,int key){
  if (root==NULL) return;

  if(root->data==key){

    if (root->left!=NULL)
    {
      node* current=root->left;
    //right most of left subtree
      while(current->right!=NULL){
        current=current->right;
      } 
      pre=current;
    }
    
    if (root->right!=NULL)
    {
      node* temp=root->right;
    //right most of left subtree
      while(temp->left!=NULL){
        temp=temp->left;
      } 
      suc=temp;
    }
    return;
  } 

  if(root->data>key){
    suc=root;
    inorder_predecessor_successor(root->left, pre,suc,key);
  }

  else{
    pre=root;
    inorder_predecessor_successor(root->right, pre,suc,key);
  } 
}


void maxDiffUtil(struct node *ptr, int k, int &min_diff, 
                                      int &min_diff_key) 
{ 
    if (ptr == NULL) 
        return ; 
  
    // If k itself is present 
    if (ptr->data == k) 
    { 
        min_diff_key = k; 
        return; 
    } 
  
    // update min_diff and min_diff_key by checking 
    // current node value 
    if (min_diff > abs(ptr->data - k)) 
    { 
        min_diff = abs(ptr->data - k); 
        min_diff_key = ptr->data; 
    } 
  
    // if k is less than ptr->key then move in 
    // left subtree else in right subtree 
    if (k < ptr->data) 
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key); 
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key); 
} 

int maxDiff(node *root, int k) 
{ 
    // Initialize minimum difference 
    int min_diff = INT_MAX, min_diff_key = -1; 
  
    // Find value of min_diff_key (Closest key 
    // in tree with k) 
    maxDiffUtil(root, k, min_diff, min_diff_key); 
    return min_diff_key; 
}

struct node* LCA(node* root, node* &a, node* &b){

  if(root==NULL) return NULL;

  if(root==a || root==b) return root;

  node* left=LCA(root->left, a,b);
  node* right=LCA(root->right, a,b);

  if(left!=NULL && right!=NULL) return root;

  else
    return (left ? left: right);
}

struct node* BST_level_order_util(node *root , int data)  
{ 
     if(root==NULL){     
        root = newNode(data); 
        return root; 
     } 
     if(data <= root->data){ 
      root->left = BST_level_order_util(root->left, data);
     } 
     else{
      root->right = BST_level_order_util(root->right, data); 
     }
     return root;      
} 

struct node* BST_level_order(int arr[], int n){
  if(n==0) return NULL;
  
  node* root =NULL;
  for (int i = 0; i < n; ++i)
  {
    root=BST_level_order_util(root, arr[i]);
  }
  return root;
}

void store_normal(node* root, vector<node*> &v){
  if(root==NULL) return;

  store_normal(root->left, v);
  v.push_back(root);
  store_normal(root->right,v);
}

struct node* normal_to_BSR(vector<node*> v, int start,int end){
  if(start>end) return NULL;
  int mid=(start+end)/2;
  

  node* root=v[mid];
  root->left=normal_to_BSR(v,start, mid-1);
  root->right=normal_to_BSR(v,mid+1, end);
  

  return root; 

}

struct node* normal_to_BSR(node* root){
  vector<node*> v;
  store_normal(root, v);
  int n = v.size();
  return normal_to_BSR(v,0, n-1);
}


bool search_tree(node* root, int diff){
  if(root==NULL) 
    return false;

  else if(root->data>diff) 
    return search_tree(root->left, diff);

  else if(root->data<diff) 
    return search_tree(root->right, diff);

  else
    return true;
}

void find_sum( node* root, node* node, int sum){
  if(root==NULL) return;
  find_sum(root, node->left, sum);
  int diff= sum - (node->data);
  if((node->data) < diff){
    if(search_tree(root, diff) == true){
      cout<<"Element found are"<<node->data<<"And"<<diff;
    }
}
  find_sum(root, node->right, sum);
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
   // addAllUp(root);
   // inorder(root);

    //inorder predecessor successor
    // int key=50;
    // node* pre=NULL;
    // node* suc=NULL;
    // cout<<"Root="<<root->data<<endl;
    //  cout<<"Key="<<key<<endl;
    // inorder_predecessor_successor(root,pre,suc,key);
    // if(pre!=NULL) cout<<"Pre= "<< pre->data<<endl;  
    // else cout<<"No Pre"<<endl;
    // if(suc!=NULL) cout<<"SUC= "<< suc->data<<endl; 
    // else cout<<"No SUC"<<endl;   


    // //closest to key in BST
    // int k = 77; 
    // cout << maxDiff(root, k);

    // // LCA of 2 elements
    // node* a=root->left->left;
    // node* b=root->left;
    // cout<<"a before: "<<a->data<<endl;
    // cout<<"b before: "<<b->data<<endl;

    // node* res=LCA(root, a,b);
    // cout<<"Result="<<res->data;


    // //BST from level order
    // int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    // int n=sizeof(arr)/sizeof(arr[0]);
  
    // node* root=BST_level_order(arr, n);
    // inorder(root);

    // //normal to balanced tree
    // struct node* root = newNode(10); 
    // root->left = newNode(8); 
    // root->left->left = newNode(7); 
    // root->left->left->left = newNode(6); 
    // root->left->left->left->left = newNode(5); 
    // root= normal_to_BSR(root);
    // preorder(root);

    //find if sum exists
    int sum=90;
    find_sum(root,root, sum);
    return 0; 
}



