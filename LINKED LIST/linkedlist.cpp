#include <iostream>
using namespace std;

// coders use node** for pointing head pointer and node* for iterating. 
class Node{
public:
	int data;
	Node* next;
};

void printList(Node* n){
	while(n!=NULL){
		cout<<n->data<<""<<endl;
		n=n->next;
	}
}

void insertAfter(Node* prev_node, int new_data){
	Node* newnode=new Node();
	newnode->data=new_data;
	newnode->next=prev_node->next;
	prev_node->next=newnode;
	// printList(head);
}

void addAtEnd(Node** head_ref, int new_data){
	Node* newnode=new Node();
	newnode->data=new_data;
	newnode->next=NULL;
	Node *last = *head_ref;

	if(*head_ref==NULL){
		*head_ref=newnode;
		return;
	}

	while(last->next!=NULL){
		last=last->next;
	}
	last->next=newnode;
	return;
	// printList(head);
}

void deleteNode(Node** head_ref,int key){
	Node *temp = *head_ref, *prev;

	if(temp!=NULL && temp->data==key){
		*head_ref=temp->next;
		free(temp);
		return;
	}

	while(temp!=NULL && temp->data!=key){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)return;

	prev->next=temp->next;
	free(temp);

}

void deletePosition(Node** head_ref, int position){
	Node* temp=*head_ref, *prev;

	if(*head_ref==NULL) return;

	if (position==0)
	{
		*head_ref=temp->next;
		free(temp);
		return;
	}

	for (int i = 0; temp!=NULL && i < position-1; ++i)
	{
		temp=temp->next;

		// If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    	// Node temp->next is the node to be deleted 
    	// Store pointer to the next of node to be deleted 
    	Node *next = temp->next->next; 
  
    	// Unlink the node from linked list 
    	free(temp->next);  // Free memory 
  
   	 	temp->next = next;  // Unlink the deleted node from list 
	}
}

void deleteLinkedList(Node** head_ref){
	Node* current=*head_ref;
	Node* next;

	while(current!=NULL){
		next=current->next;
		free(current);
		current=next;
	}

	*head_ref=NULL;
	cout<<"Linked List deleted";
}

int nodeLengthIterative(Node* head_ref){
    Node* temp=head_ref;
    int count =0;
    // temp->next=head_ref;
    while(temp!=NULL){
        temp=temp->next;
        // printList(temp);
        // int n=temp->data;
        // cout<<n;
        count++;

    }
    return count;
}

int nodeLengthRecursive(Node* head_ref){
    // int count=0;
    // Nodehead_ref;
    if(head_ref==NULL){
    	return 0;
    }
    else{
    	return 1 + nodeLengthRecursive(head_ref->next);
    }
   
}

int searchNode(Node* head_ref, int s){
	Node *current=head_ref;
	while(current!=NULL){
		if(current->data==s){
		cout<<"found";
		return true;
		}
		current=current->next;
	}
	cout<<"Not found";
	return false;
	
}

int searchNodeRecursive(Node* head_ref, int s){
	// Node *current=head_ref;
	if(head_ref==NULL){
		cout<<"Not found";
		return false;
	}
	if(head_ref->data==s){
		cout<<"Found";
		return 0;
	}
	return searchNodeRecursive(head_ref->next,s);
	cout<<"Not Found";
}

int findNthNode(Node* head_ref, int n){
	Node *temp=head_ref;
	int count=0;
	while(temp!=NULL){
		if(count==n)
			return temp->data;
		temp=temp->next;
		count++;
	}
	cout<<"Not found"<<'\n';
	assert(0);
	// return true;
}

void swap(Node** one, Node** two){

}

void pairWise(Node **head_ref){
	Node* current=*head_ref;
	// Node* second=current->next;
	while(current!=NULL){
		swap(current->data, current->next->data);
		current=current->next->next;
	}

}

// int intersectionNodes(Node *head_ref1, Node* head_ref2){
// 	if(head_ref1==NULL || head_ref2==NULL)
// 		return 0;

// 	if(head_ref1->data > head_ref2->data)
// 		return intersectionNodes(head_ref1, head_ref2->next);

// 	if(head_ref1->data < head_ref2->data)
// 		return intersectionNodes(head_ref1->next, head_ref2);

// 	Node *temp=NULL;
// 	temp->data=head_ref1->data;
// 	temp->next=intersectionNodes(head_ref1,head_ref2);
// 	return temp;
// }



int main()
{
	Node* head=NULL;
	Node* second=NULL;
	Node* third=NULL;
	Node* fourth=NULL;


	head=new Node();
	second=new Node();
	third=new Node();
	fourth=new Node();

	head->data=1;
	second->data=2;
	third->data=3;
	fourth->data=4;

	head->next=second;
	second->next=third;
	third->next=fourth;
	fourth->next=NULL;

	// addNode(head, 12);
	// cout<<nodeLengthIterative(head); 
	// cout<<nodeLengthRecursive(head);
	// searchNode(head,22);
	// searchNodeRecursive(head,5);
	// cout<<findNthNode(head, 3);
	// printList(head);
	addAtEnd(&head,5);
	addAtEnd(&head,6);
	addAtEnd(&head,7);
	addAtEnd(&head,8);
	// printList(head);
	// deleteNode(&head, 5);
	// deletePosition(&head,0);
	// deleteLinkedList(&head);
	// pairWise(&head);
	printList(head);

	// removeduplicate()
	return 0;
}