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


Node* reverse(Node* head){
	Node* curr=head;
	Node* next=NULL;
	Node* prev=NULL;
	while(curr!=NULL){
		// store next
		next=curr->next;
		// reverse curr
		curr->next=prev;

		// move pointers by one
		prev=curr;
		curr=next;
	}
	head=prev;
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

	head=reverse(head);
 
	traverse(head);
	// int k=3;
	// cout<<"Before Reverse"<<endl;
	// traverse(head);
	// cout<<endl;
	// head=kreverse(head,k);
	// cout<<"After Reverse"<<endl;
	// traverse(head);

}