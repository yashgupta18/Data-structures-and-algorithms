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

Node* kSwap(Node *head, int k)  
{
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    if(count<k) return head;

    // temp=head;
    Node* x=head;
    Node* x_prevNode=NULL;
    for (int i = 1; i < k; ++i)
    {
        x_prevNode=x;
        x=x->next;
    }

    Node* y=head;
    Node* y_prevNode=NULL;
    for (int i = 1; i <count-k+1 ; ++i)
    {
        y_prevNode=y;
        y=y->next;
    }

    if(x_prevNode){
        x_prevNode->next=y;
    }

    if(y_prevNode){
        y_prevNode->next=x;
    }

    Node* tempTo = x->next; 
    x->next = y->next; 
    y->next = tempTo; 

    if (k == 1) 
        head = y; 
    if (k == count) 
        head = x; 

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

	// head=reverse(head);
	// traverse(head);
	int k=2;
	cout<<"Before Reverse"<<endl;
	traverse(head);
	cout<<endl;
	head=kSwap(head,k);
	cout<<"After Reverse"<<endl;
	traverse(head);

}