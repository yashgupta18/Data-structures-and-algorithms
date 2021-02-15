#include <iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std; 
  

struct Node{
  int data;
  struct Node *next;
};

struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->next = NULL; 
    return temp; 
} 

void traverse(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}


Node* NthNodeFromBack(Node* head, int n){
	Node* slow=head;
    Node* fast=head;

    for (int i = 1; i <= n; ++i)
    {
        /* code */
        fast=fast->next;
    }

    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    //delete nth element from back
    slow->next=slow->next->next;

    return head;

}

int main(){
	Node *head= newNode(1);
	head->next=newNode(2);
	head->next->next=newNode(3);
	head->next->next->next=newNode(4);
	head->next->next->next->next=newNode(5);
	head->next->next->next->next->next=newNode(6);
	head->next->next->next->next->next->next=newNode(7);
	head->next->next->next->next->next->next->next=newNode(8);

	head=NthNodeFromBack(head, 4);
    // cout<<temp->data;
	traverse(head);
	// int k=3;
	// cout<<"Before Reverse"<<endl;
	// traverse(head);
	// cout<<endl;
	// head=kreverse(head,k);
	// cout<<"After Reverse"<<endl;
	// traverse(head);

}