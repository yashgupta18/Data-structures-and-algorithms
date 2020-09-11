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

struct node* normal_to_BSR_util(vector<node*> v, int start,int end){
  if(start>end) return NULL;
  int mid=(start+end)/2;
  

  node* root=v[mid];
  root->left=normal_to_BSR_util(v,start, mid-1);
  root->right=normal_to_BSR_util(v,mid+1, end);
  return root; 
}

struct node* normal_to_BSR(node* root){
  vector<node*> v;
  store_normal(root, v);
  int n = v.size();
  return normal_to_BSR_util(v,0, n-1);
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

int find_sum(node* root, int sum){
  if(root==NULL) return 0;

  node* top1;
  node* top2;
  stack<node*> s1;
  stack<node*> s2;

  node* root1=root;
  node* root2=root;

  while(1){

    while(root1!=NULL){
      s1.push(root1);
      root1=root1->left;
    }

    while(root2!=NULL){
      s2.push(root2);
      root2=root2->right;
    }

    if (s1.empty() || s2.empty()) break; 

    top1=s1.top();
    top2=s2.top();

    //to check overlapping
    if(top1->data >= top2->data) return 0;

    if(top1->data + top2->data ==sum){
      cout<<"Elements are: "<<top1->data <<"and "<< top2->data<<endl;
      //return if only one pair reqd
      // return 1;

      //for all possible pairs
      s1.pop();
      s2.pop();
      root1=top1->right;
      root2=top2->left;
    }

    else if(top1->data + top2->data > sum){
      s2.pop();
      //point root2 to left of new top2 
      root2=top2->left;
    }
    else{
      s1.pop();
      //point root1 to right of new top1
      root1=top1->right;
    }
  }
  return 0;
}


int BST_check_util(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        BST_check_util(node->left, min, node->data) && // Allow only distinct values  
        BST_check_util(node->right, node->data, max); // Allow only distinct values  
}  


int BST_check(node* root){
  return BST_check_util(root, INT_MIN,INT_MAX);
}

void correct_swapped_nodes_util(struct node* root,node* &first, node* &middle, node* &last, node* &prev){
  if(root){

    correct_swapped_nodes_util(root->left,first,middle,last,prev);

    if(prev && root->data < prev->data){
      if(!first){
        first=prev;
        middle=root;
      }else{
        last=root;
      }
    }
    prev=root;
    correct_swapped_nodes_util(root->right,first,middle,last, prev);
  }
  
}
  
void correct_swapped_nodes(struct node* root){
  node* prev, *first,*last, *middle;
  first=middle=last=prev=NULL;
  correct_swapped_nodes_util(root, first, middle, last, prev);

  if(first && last){
    swap(first->data, last->data);
  }else{
    swap(first->data, middle->data);
  }
}

void morris_inorder(node* root){
  node* current, *pre;
  if(root==NULL) return;
  current=root;
  while(current!=NULL){
    if(current->left==NULL){
      cout<<current->data;
      current=current->right;
    }else{
      //go to the rightmost of left subtree
      pre=current->left;
      while(pre->right!=NULL && pre->right != current){
        pre=pre->right;
      }
      if(pre->right==NULL){
        //make right of righmost point to current(i.e root) if right is NULL
        pre->right=current;
        //repeat same for left of current
        current=current->left;
      }else{
        //if right is not NULL means we already traversed it so make it back to NULL
        pre->right=NULL;
        cout<<current->data;
        current=current->right;
      }
    }
    }
}


int ksmall_BST(node* root, int k){
  int count=0;
  int ksmall=INT_MIN;
  node* current=root;
  while(current!=NULL){
    if(current->left==NULL){
      count++;
      if(count==k){
        ksmall = current->data; 
        
      }
      current=current->right;
    }else{
      node* pre=current->left;
      while(pre->right!=NULL && pre->right!=current){
        pre=pre->right;
      }
      if(pre->right==NULL){
        pre->right=current;
        current=current->left;
      }else{
        pre->right=NULL;
        count++;
         if(count==k){
          ksmall = current->data;
          
        }
        current=current->right;
      }
    }
  }
  return ksmall;
}


// int find_median(node* root){
//   if(root==NULL) return root;

// }


int num_of_BST(int n){
//   dp -> options_per_tree_size
// i -> current_tree_size
// j -> current_root
  int v[n + 1]; 
    fill_n(v, n + 1, 0); 
  
    // Base case 
    v[0] = 1; 
    v[1] = 1; 

  for (int i = 2; i <= n; i++) { 
        for (int j = 1; j <= i; j++) { 
            // n-i in right * i-1 in left 
            v[i] = v[i] + (v[i - j] * v[j - 1]); 
        } 
    } 
  return v[n];
}

// Driver program 
int main() 
{ 
    /*      BST
                  50 
               /     \ 
              30      70 
             /  \    /  \ 
           20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);


   
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
    // inorder(root);

    // //find if sum exists
    // int sum=90;
    // find_sum(root, sum);

    // //check if Tree is BST
    // if(BST_check(root)){
    //   cout<<"True";
    // }else{
    //   cout<<"False";
    // }

    // //nodes swapped in BST
    // struct node *root = newNode(6); 
    // root->left        = newNode(10); 
    // root->right       = newNode(2); 
    // root->left->left  = newNode(1); 
    // root->left->right = newNode(3); 
    // root->right->right = newNode(12); 
    // root->right->left = newNode(7); 
    // cout<<"Before"<<endl;
    // inorder(root);
    // correct_swapped_nodes(root);
    // cout<<"After"<<endl;
    // inorder(root);


    // //median of BST
    // find_median(root);

    // //morris inorder traversal
    // morris_inorder(root);

    // //kth smallest in BST(using O(1) space
    // int k=3;
    // int smallest=ksmall_BST(root,k);
    // cout<<smallest;

    //No. of trees from 1-N numbers
    int n = 3; 
    cout << "Number of structurally Unique BST with " <<  
    n << " keys are : " << num_of_BST(n) << "\n"; 

    return 0; 
}



