#include <iostream>
using namespace std;
#define MAX 1000 

class Node { 
public:
	int data;
	Node *next;
	Node *prev;
};


void printList(Node* head_ref){
	Node* current=head_ref;
	Node* last;
	cout<<endl<<"Forward"<<endl;
	while(current!=NULL){
		cout<<current->data<<" ";
		last=current;
		current=current->next;
		
	}

	cout<<endl<<"Backward"<<endl;
	while(last!=NULL){
		cout<<last->data<<" ";
		last=last->prev;
	}

}

void addAtEnd(Node** head_ref, int value){
	Node* current=*head_ref;

	Node* newnode=new Node();
	newnode->data=value;
	newnode->next=NULL;

	if(*head_ref==NULL){
		newnode->prev=NULL;
		*head_ref=newnode;
		return;
	}
	while(current->next!=NULL){
		current=current->next;

	}

	current->next=newnode;
	newnode->prev=current;
	return;
}

void split(Node* head_ref,Node** head_ref1,Node** head_ref2){
	Node* slow=head_ref;
	Node* fast=head_ref;

	if(head_ref==NULL){
		return;
	}

	while(fast->next->next!=head_ref && fast->next!=head_ref){
		fast=fast->next->next;
		slow=slow->next;
	}
	if(fast->next->next==head_ref){
		fast=fast->next;
	}

	*head_ref1=head_ref;

	if(head_ref->next!=head_ref){
		*head_ref2=slow->next;
	}

	
	
	fast->next=slow->next;
	slow->next=head_ref;
	
}

int main(){

	Node* head=NULL;
	head=new Node();
	head->data=33;
	head->next=NULL;
	head->prev=NULL;
	addAtEnd(&head, 94);
	addAtEnd(&head, 3);
	addAtEnd(&head, 53);
	addAtEnd(&head, 93);
	addAtEnd(&head, 23);
	addAtEnd(&head, 86);
	addAtEnd(&head, 64);
	printList(head);
	// split(head, &head1, &head2);
	// cout<<endl<<"FIRST"<<endl;
	// printList(head1);
	// cout<<endl<<"SECOND"<<endl;
	// printList(head2);
	return 0;
}