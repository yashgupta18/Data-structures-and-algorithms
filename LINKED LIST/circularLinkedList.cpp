#include <iostream>
using namespace std;
#define MAX 1000 

class Node { 
public:
	int data;
	Node *next;
};


void printList(Node* head_ref){
	Node* current=head_ref;
	do{
		cout<<current->data<<" ";
		current=current->next;
		
	}while(current!=head_ref);
}

void addAtEnd(Node** head_ref, int value){
	Node* current=*head_ref;
	Node* newnode=new Node();
	newnode->data=value;
	newnode->next=*head_ref;

	if(*head_ref==NULL){
		newnode->next=*head_ref;
		return;
	}
	while(current->next!=*head_ref){
		current=current->next;

	}

	current->next=newnode;
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
	Node* head1=NULL;
	Node* head2=NULL;
	head=new Node();
	head->data=33;
	head->next=head;
	addAtEnd(&head, 94);
	addAtEnd(&head, 3);
	addAtEnd(&head, 53);
	addAtEnd(&head, 93);
	addAtEnd(&head, 23);
	addAtEnd(&head, 86);
	addAtEnd(&head, 64);
	printList(head);
	split(head, &head1, &head2);
	cout<<endl<<"FIRST"<<endl;
	printList(head1);
	cout<<endl<<"SECOND"<<endl;
	printList(head2);
	return 0;
}