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


void buildTree(int l, int r, int arr[],int segArr[], int pos){
	if(l==r){
		segArr[pos]=arr[l];
		return;
	} 

	int mid=l+((r-l)/2);
	buildTree(l,mid, arr,segArr,(2*pos)+1 );
	buildTree(mid+1,r, arr,segArr,(2*pos)+2 );
	segArr[pos]=segArr[(2*pos)+1] + segArr[(2*pos)+2];
}

int getSum(int l, int r, int ql, int qr,int segArr[], int pos){
	if(ql>r ||qr<l) return 0;

	if(l>=ql && r<=qr) return segArr[pos];
	
	int mid=(l+r)/2;
	return getSum(l, mid, ql, qr, segArr, (2*pos)+1) + getSum(mid+1, r, ql, qr, segArr, (2*pos)+2);
}


int main(){
	// Node *root= newNode(1);
	// root->left=newNode(2);
	// root->right=newNode(3);
	// root->left->right=newNode(4);
	// root->right->left=newNode(5);
	// root->right->right=newNode(6);
	// root->right->left->left=newNode(7);
	
	int arr[]= {1,3,-2,8,-7};
	int n=sizeof(arr)/sizeof(arr[0]);
	int segArr[4*n];
	buildTree(0,n-1, arr,segArr, 0);
	int n2=sizeof(segArr)/sizeof(segArr[0]);
	for (int i = 0; i <= 9; ++i)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 9; ++i)
	{
		// cout<<segArr[i]<<" ";
	}

	int ans=getSum(0,n-1, 1,3, segArr, 0);
	cout<<ans;
	return 0;

}