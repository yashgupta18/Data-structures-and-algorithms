#include <iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std; 
  

struct Node{
  int data;
  struct Node *next, *random;
};

struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->next = NULL; 
    temp->random=NULL;
    return temp; 
} 

void traverse(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}

Node* clone(Node* head){
    Node* head_ref=head;
    if(head_ref==NULL) return head;

    //copy each node again like 1->1->2->2
    while(head_ref!=NULL){
        Node *temp= newNode(head_ref->data);
        temp->next=head_ref->next;
        head_ref->next=temp;
        head_ref=head_ref->next->next;
    }

    head_ref=head;
    // copy random
    while(head_ref!=NULL){
        head_ref->next->random=head_ref->random->next;
        head_ref=head_ref->next->next;
    }

    // make a new copy LL
    Node* original = head, *copy = head->next; 
    Node* temp=copy;
    while(original && head){
        if(original->next){
            original->next=original->next->next;
        }
       
       if(temp->next){
            temp->next=temp->next->next;
        }
       original=original->next;
       temp=temp->next;
    }

    //print cloned 
    traverse(copy);

    // return original
    return head;
}


int main(){
    // Clone a linked list with next and random pointer in O(1) space


    // https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/

	Node *head= newNode(1);
	head->next=newNode(2);
	head->next->next=newNode(3);
	head->next->next->next=newNode(4);
	head->next->next->next->next=newNode(5);

    // 1's random points to 3 
    head->random = head->next->next; 
  
    // 2's random points to 1 
    head->next->random = head; 
  
    // 3's and 4's random points to 5 
    head->next->next->random = head->next->next->next->next; 
    head->next->next->next->random = head->next->next->next->next; 
  
    // 5's random points to 2 
    head->next->next->next->next->random = head->next; 
	
    clone(head);
	// traverse(head);

}